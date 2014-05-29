#ifndef _NME_GLSL_H
#define _NME_GLSL_H

// Vertex
#define Nreal_vertex_pos() NMVP * vec4(Nvertex_pos, 1)
#define Ncheck_UV_flip(UV) {\
    if (NUV_flip) {\
        UV.x = 1 - UV.x;\
    }\
}

#endif
