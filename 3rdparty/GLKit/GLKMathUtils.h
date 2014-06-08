//
//  GLKMathUtils.h
//  GLKit
//
//  Copyright (c) 2011, Apple Inc. All rights reserved.
//

#ifndef __GLK_MATH_UTILS_H
#define __GLK_MATH_UTILS_H

#include <math.h>
#include <stdbool.h>

#include <GLKit/GLKMathTypes.h>

#ifdef __cplusplus
extern "C" {
#endif

static __inline__ float GLKMathDegreesToRadians(float degrees) { return degrees * (M_PI / 180); };
static __inline__ float GLKMathRadiansToDegrees(float radians) { return radians * (180 / M_PI); };

GLKVector3 GLKMathProject(GLKVector3 object, GLKMatrix4 model, GLKMatrix4 projection, int *viewport);
GLKVector3 GLKMathUnproject(GLKVector3 window, GLKMatrix4 model, GLKMatrix4 projection, int *viewport, bool *success);

#ifdef __cplusplus
}
#endif

#endif /* __GLK_MATH_UTILS_H */
