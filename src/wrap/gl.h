#ifndef _SP_WRAP_GL_H
#define _SP_WRAP_GL_H

#include <GL/gl.h>
#include <GL/glu.h>

// Float precision is double (d)
#define _gl(f) f##d

#define glTranslate _gl(glTranslate)
#define glTexCoord2 _gl(glTexCoord2)
#define glVertex2   _gl(glVertex2)

#endif
