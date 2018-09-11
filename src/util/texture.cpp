#include <GL/gl3w.h>

#include "util.hpp"

/**
 * \brief creates a 3D texture filled with the given values
 *
 * \param buf array containing the volume data in linear order
 * \param internalFormat OGL Define that determines the number of color
 *        componenents and their type
 * \param res_x Number of values in the first dimension
 * \param res_y Number of values in the second dimension
 * \param res_z Number of values in the third dimension
 *
 * \return OpenGL ID of the texture object
 */
GLuint util::create3dTexFromScalar(
    const GLvoid *buf,
    GLenum type,
    GLsizei res_x,
    GLsizei res_y,
    GLsizei res_z)
{
    GLuint volumeTex;

    glGenTextures(1, &volumeTex);
    glBindTexture(GL_TEXTURE_3D, volumeTex);
    glTexImage3D(
        GL_TEXTURE_3D,
        0,
        GL_RED,
        res_x,
        res_y,
        res_z,
        0,
        GL_RED,
        type,
        buf);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
    float borderColor[] = {0.f, 0.f, 0.f, 1.f};
    glTexParameterfv(GL_TEXTURE_3D, GL_TEXTURE_BORDER_COLOR, borderColor);

    return volumeTex;
}
/**
 * \brief Creates a 2D texture object which can be used as render target
 * \param internalFormat   internal format of the texture
 * \param format           format of the data: GL_RGB,...
 * \param type             data type: GL_UNSIGNED_BYTE, GL_FLOAT,...
 * \param filter           texture filter: GL_LINEAR or GL_NEAREST
 * \param width            texture width
 * \param height           texture height
 *
 * \return OpenGL ID of the texture Object
 */
GLuint util::create2dTextureObject(
    const GLenum internalFormat,
    const GLenum format,
    const GLenum type,
    GLint filter,
    int width,
    int height)
{
    GLuint texID = 0;

    glGenTextures(1, &texID);

    glBindTexture(GL_TEXTURE_2D, texID);

    glTexImage2D(
        GL_TEXTURE_2D,
        0,
        internalFormat,
        width,
        height,
        0,
        format,
        type,
        NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
    float borderColor[] = { 0.f, 0.f, 0.f, 1.f };
    glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);

    return texID;
}