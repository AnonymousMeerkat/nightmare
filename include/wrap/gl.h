#ifndef _NME_WRAP_GL_H
#define _NME_WRAP_GL_H

#define GLEW_STATIC
#include <gl_compat.h>
#include <GL/gl.h>
#include <GL/glu.h>

// Float precision is float (f)
#define _gl(func) func##f

#define _glTranslate _gl(glTranslate)
#define glTexCoord2  _gl(glTexCoord2)
#define glVertex2    _gl(glVertex2)
#define _glScale     _gl(glScale)

#define glTranslate(x, y) _glTranslate(x, y, 0)
#define glScale(x, y) _glScale(x, y, 0)

#undef _gl

#endif
