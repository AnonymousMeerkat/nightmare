/*
    Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
        * Redistributions of source code must retain the above copyright
          notice, this list of conditions and the following disclaimer.
        * Redistributions in binary form must reproduce the above copyright
          notice, this list of conditions and the following disclaimer in the
          documentation and/or other materials provided with the distribution.
        * Neither the name of the Nightmare Project nor the
          names of its contributors may be used to endorse or promote products
          derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "../NKTool.h"

#include <stdio.h>
#include <stdlib.h>

char vec_names[3][4] = {
    "xyzw",
    "rgba",
    "stpq"
};

char* types[2] = {
    "int",
    "float"
};

char mat_names[] = "0123";

char* func_def = "static __inline__";
char* fwd_def = "static";

int vecmathbuilder(int argc, char** argv) {
    FILE* output = stdout;

    // License
    // No, it didn't take me hours to do this. Thanks to Sublime Text's SHIFT+Right drag feature, I got it done in ~20 seconds.
    // Thank you so much sublime devs!
    // As a token of my thank you, here's me still using your evaluation version <3

    fprintf(output,
"/* Copyright (c) 2014,  Anonymous Meerkat<meerkatanonymous@gmail.com>\n"
"All rights reserved.\n"
"\n"
"Redistribution and use in source and binary forms, with or without\n"
"modification, are permitted provided that the following conditions are met:\n"
"    * Redistributions of source code must retain the above copyright\n"
"      notice, this list of conditions and the following disclaimer.\n"
"    * Redistributions in binary form must reproduce the above copyright\n"
"      notice, this list of conditions and the following disclaimer in the\n"
"      documentation and/or other materials provided with the distribution.\n"
"    * Neither the name of the Nightmare Project nor the\n"
"      names of its contributors may be used to endorse or promote products\n"
"      derived from this software without specific prior written permission.\n"
"\n"
"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\" AND\n"
"ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED\n"
"WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE\n"
"DISCLAIMED. IN NO EVENT SHALL ANONYMOUS MEERKAT BE LIABLE FOR ANY\n"
"DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES\n"
"(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;\n"
"LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND\n"
"ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
"(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS\n"
"SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */\n\n");

    // Headers

    fprintf(output, "#include <math.h>\n");

    fprintf(output, "\n");

    // Generate types

    for (int i = 2; i <= 4; i++) {
        for (int y = 0; y < 2; y++) {
            // Vectors

            fprintf(output, "union _NVec%i%c_t {\n", i, types[y][0]);
            for (int j = 0; j < 3; j++) {
                fprintf(output, "    struct {\n");
                for (int x = 0; x < i; x++) {
                    fprintf(output, "        %s %c;\n", types[y], vec_names[j][x]);
                }
                fprintf(output, "    };\n");
            }
            fprintf(output, "    %s v[%i];\n", types[y], i);
            fprintf(output, "};\n");
            fprintf(output, "typedef union _NVec%i%c_t NVec%i%c_t;\n\n", i, types[y][0], i, types[y][0]);

            // Matrices

            fprintf(output, "union _NMat%i%c_t {\n", i, types[y][0]);
            fprintf(output, "    struct {\n");
            for (int x = 0; x < i; x++) {
                for (int j = 0; j < i; j++) {
                    fprintf(output, "        %s m%c%c;\n", types[y], mat_names[x], mat_names[j]);
                }
            }
            fprintf(output, "    };\n");
            fprintf(output, "    %s m[%i];\n", types[y], i * i);
            fprintf(output, "    %s m%i[%i][%i];\n", types[y], i, i, i);
            fprintf(output, "};\n");
            fprintf(output, "typedef union _NMat%i%c_t NMat%i%c_t;\n\n", i, types[y][0], i, types[y][0]);
        }
    }

    // Forward declarations

    for (int i = 2; i <= 4; i++) {
        for (int y = 0; y < 2; y++) {
              //////////////////////////////////
             //// Initialization functions ////
            //////////////////////////////////

            // e.g. NVec2i(x, y)

            fprintf(output, "%s NVec%i%c_t NVec%i%c(", fwd_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ");\n");

            // e.g. NVec2i_3f(NVec2i(x, y))

            for (int i1 = 2; i1 <= 4; i1++) {
                for (int y1 = 0; y1 < 2; y1++) {
                    if (i == i1 && y == y1) {
                        continue;
                    }
                    fprintf(output, "%s NVec%i%c_t NVec%i%c_%i%c(NVec%i%c_t o);\n",
                        fwd_def, i1, types[y1][0], i, types[y][0], i1, types[y1][0], i, types[y][0]);
                }
            }

            // e.g. NMat2i(m00, m01, m10, m11)

            fprintf(output, "%s NMat%i%c_t NMat%i%c(", fwd_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, "%s m%c%c, ", types[y], mat_names[j], mat_names[x]);
                    } else {
                        fprintf(output, "%s m%c%c", types[y], mat_names[j], mat_names[x]);
                    }
                }
            }
            fprintf(output, ");\n");

            // e.g. NMat2i_identity()

            fprintf(output, "%s NMat%i%c_t NMat%i%c_identity();\n", fwd_def, i, types[y][0], i, types[y][0]);

            // e.g. NMat2i_rows(0, 1)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_rows(", fwd_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ");\n");

            // e.g. NMat2i_cols(0, 1)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_cols(", fwd_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ");\n");

            // e.g. NMat2i_3f(NMat2i(m00, m01, m10, m11))

            for (int i1 = 2; i1 <= 4; i1++) {
                for (int y1 = 0; y1 < 2; y1++) {
                    if (i == i1 && y == y1) {
                        continue;
                    }
                    fprintf(output, "%s NMat%i%c_t NMat%i%c_%i%c(NMat%i%c_t o);\n",
                        fwd_def, i1, types[y1][0], i, types[y][0], i1, types[y1][0], i, types[y][0]);
                }
            }

              ///////////////////
             //// Functions ////
            ///////////////////

            // e.g. NVec2i_neg(NVec2i(x, y)) -> NVec2i(-x, -y)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_neg(NVec%i%c_t v1);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_add(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_add(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_adds(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_adds(NVec%i%c_t v1, %s s);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);

            // e.g. NVec2i_sub(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_sub(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_subs(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_subs(NVec%i%c_t v1, %s s);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);

            // e.g. NVec2i_mul(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_mul(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_muls(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_muls(NVec%i%c_t v1, %s s);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);

            // e.g. NVec2i_div(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_div(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_divs(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_divs(NVec%i%c_t v1, %s s);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);

            // e.g. NVec2i_dot(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s %s NVec%i%c_dot(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, types[y], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_len(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s float NVec%i%c_len(NVec%i%c_t v1);\n",
                fwd_def, i, types[y][0], i, types[y][0]);

            // e.g. NVec2i_norm(NVec2i(x, y))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_norm(NVec%i%c_t v1);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NVec3i_cross(NVec3i(x, y, z), NVec3i(x1, y1, z1))

            if (i >= 3) {
                fprintf(output, "%s NVec%i%c_t NVec%i%c_cross(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                    fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            }

            // e.g. NVec2i_proj(NVec2i(x, y))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_proj(NVec%i%c_t v1, NVec%i%c_t v2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);


            // e.g. NMat2i_add(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_add(NMat%i%c_t m1, NMat%i%c_t m2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NMat2i_sub(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_sub(NMat%i%c_t m1, NMat%i%c_t m2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            // e.g. NMat2i_mul(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_mul(NMat%i%c_t m1, NMat%i%c_t m2);\n",
                fwd_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);

            if (i >= 3) {
                // e.g. NMat3f_scale_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_scale_%i%c(NMat%i%c_t m1, NVec%i%c_t v1);\n",
                            fwd_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i, types[y][0], i1, types[y1][0]);
                    }
                }

                // e.g. NMat3f_rotation_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_rotation_%i%c(float radians, NVec%i%c_t v1);\n",
                            fwd_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i1, types[y1][0]);
                    }
                }

                // e.g. NMat3f_rotate_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_rotate_%i%c(NMat%i%c_t m1, float radians, NVec%i%c_t v1);\n",
                            fwd_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i, types[y][0], i1, types[y1][0]);
                    }
                }
            }

            if (i == 4 && types[y][0] == 'f') {
                // e.g. NMat4f_translate()

                for (int y1 = 0; y1 < 2; y1++) {
                    fprintf(output, "%s NMat4f_t NMat4f_translate_3%c(NMat4f_t m1, NVec3%c_t v1);\n", fwd_def, types[y1][0], types[y1][0]);
                }

                // e.g. NMat4f_perspective()

                fprintf(output, "%s NMat4f_t NMat4f_perspective(float fov_rad, float aspect, float nearZ, float farZ);\n",
                    fwd_def);

                // e.g. NMat4f_frustum()

                fprintf(output, "%s NMat4f_t NMat4f_frustum(float left, float right, float bottom, float top, float nearZ, float farZ);\n",
                    fwd_def);

                // e.g. NMat4f_ortho()

                fprintf(output, "%s NMat4f_t NMat4f_ortho(float left, float right, float bottom, float top, float nearZ, float farZ);\n",
                    fwd_def);

                // TODO: Add LookAt function
            }
        }
    }

    fputs("\n", output);

    // Functions

    for (int i = 2; i <= 4; i++) {
        for (int y = 0; y < 2; y++) {
              //////////////////////////////////
             //// Initialization functions ////
            //////////////////////////////////

            // e.g. NVec2i(x, y)

            fprintf(output, "%s NVec%i%c_t NVec%i%c(", func_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ") {\n");
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%c, ", vec_names[0][j]);
                } else {
                    fputc(vec_names[0][j], output);
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_3f(NVec2i(x, y))

            for (int i1 = 2; i1 <= 4; i1++) {
                for (int y1 = 0; y1 < 2; y1++) {
                    if (i == i1 && y == y1) {
                        continue;
                    }
                    fprintf(output, "%s NVec%i%c_t NVec%i%c_%i%c(NVec%i%c_t o) {\n",
                        func_def, i1, types[y1][0], i, types[y][0], i1, types[y1][0], i, types[y][0]);
                    fprintf(output, "    NVec%i%c_t ret = {{", i1, types[y1][0]);
                    for (int j = 0; j < i1; j++) {
                        if (j >= i) {
                            fputc('0', output);
                        } else {
                            fprintf(output, "o.v[%i]", j);
                        }
                        if ((j + 1) < i1) {
                            fputs(", ", output);
                        }
                    }
                    fputs("}};\n", output);
                    fprintf(output, "    return ret;\n");
                    fprintf(output, "}\n\n");
                }
            }

            // e.g. NMat2i(m00, m01, m10, m11)

            fprintf(output, "%s NMat%i%c_t NMat%i%c(", func_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, "%s m%c%c, ", types[y], mat_names[j], mat_names[x]);
                    } else {
                        fprintf(output, "%s m%c%c", types[y], mat_names[j], mat_names[x]);
                    }
                }
            }
            fprintf(output, ") {\n");
            fprintf(output, "    NMat%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, "m%c%c, ", mat_names[j], mat_names[x]);
                    } else {
                        fprintf(output, "m%c%c", mat_names[j], mat_names[x]);
                    }
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_identity()

            fprintf(output, "%s NMat%i%c_t NMat%i%c_identity() {\n", func_def, i, types[y][0], i, types[y][0]);
            fprintf(output, "    NMat%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    if (x == j) {
                        fprintf(output, "1");
                    } else {
                        fprintf(output, "0");
                    }
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, ", ");
                    }
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_rows(0, 1)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_rows(", func_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ") {\n");
            fprintf(output, "    NMat%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    fprintf(output, "%c", vec_names[0][j]);
                    if ((x + 1) < i) {
                        fprintf(output, ", ");
                    }
                }
                if (((j + 1) * (j + 1)) < (i * i)) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_cols(0, 1)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_cols(", func_def, i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                if ((j + 1) < i) {
                    fprintf(output, "%s %c, ", types[y], vec_names[0][j]);
                } else {
                    fprintf(output, "%s %c", types[y], vec_names[0][j]);
                }
            }
            fprintf(output, ") {\n");
            fprintf(output, "    NMat%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    fprintf(output, "%c", vec_names[0][x]);
                    if ((x + 1) < i) {
                        fprintf(output, ", ");
                    }
                }
                if (((j + 1) * (j + 1)) < (i * i)) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_3f(NMat2i(m00, m01, m10, m11))

            for (int i1 = 2; i1 <= 4; i1++) {
                for (int y1 = 0; y1 < 2; y1++) {
                    if (i == i1 && y == y1) {
                        continue;
                    }
                    fprintf(output, "%s NMat%i%c_t NMat%i%c_%i%c(NMat%i%c_t o) {\n",
                        func_def, i1, types[y1][0], i, types[y][0], i1, types[y1][0], i, types[y][0]);
                    fprintf(output, "    NMat%i%c_t ret = {{", i1, types[y1][0]);
                    for (int j = 0; j < i1; j++) {
                        for (int x = 0; x < i1; x++) {
                            if (j >= i || x >= i) {
                                fputc('0', output);
                            } else {
                                fprintf(output, "o.m%c%c", mat_names[j], mat_names[x]);
                            }
                            if (((j + 1) * (x + 1)) < (i1 * i1)) {
                                fputs(", ", output);
                            }
                        }
                    }
                    fputs("}};\n", output);
                    fprintf(output, "    return ret;\n");
                    fprintf(output, "}\n\n");
                }
            }

              ///////////////////
             //// Functions ////
            ///////////////////

            // e.g. NVec2i_neg(NVec2i(x, y)) -> NVec2i(-x, -y)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_neg(NVec%i%c_t v1) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "-v1.%c", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_add(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_add(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c + v2.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_adds(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_adds(NVec%i%c_t v1, %s s) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c + s", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_sub(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_sub(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c - v2.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_subs(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_subs(NVec%i%c_t v1, %s s) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c - s", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_mul(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_mul(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * v2.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_muls(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_muls(NVec%i%c_t v1, %s s) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * s", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_div(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_div(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c / v2.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_divs(NVec2i(x, y), x)

            fprintf(output, "%s NVec%i%c_t NVec%i%c_divs(NVec%i%c_t v1, %s s) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], types[y]);
            fprintf(output, "    float f = 1. / s;\n");
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * f", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec2i_dot(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s %s NVec%i%c_dot(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, types[y], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    return ");
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * v2.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, " + ");
                }
            }
            fputs(";\n", output);
            fprintf(output, "}\n\n");

            // e.g. NVec2i_len(NVec2i(x, y), NVec2i(x1, y1))

            fprintf(output, "%s float NVec%i%c_len(NVec%i%c_t v1) {\n",
                func_def, i, types[y][0], i, types[y][0]);
            fprintf(output, "    return sqrt(");
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * v1.%c", vec_names[0][j], vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, " + ");
                }
            }
            fputs(");\n", output);
            fprintf(output, "}\n\n");

            // e.g. NVec2i_norm(NVec2i(x, y))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_norm(NVec%i%c_t v1) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    float scale = 1.f / NVec%i%c_len(v1);\n", i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = {{", i, types[y][0]);
            for (int j = 0; j < i; j++) {
                fprintf(output, "v1.%c * scale", vec_names[0][j]);
                if ((j + 1) < i) {
                    fprintf(output, ", ");
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NVec3i_cross(NVec3i(x, y, z), NVec3i(x1, y1, z1))

            if (i >= 3) {
                fprintf(output, "%s NVec%i%c_t NVec%i%c_cross(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                    func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
                fprintf(output, "    return (NVec%i%c_t) {{\n", i, types[y][0]);
                fprintf(output, "        v1.v[1] * v2.v[2] - v1.v[2] * v2.v[1],\n");
                fprintf(output, "        v1.v[2] * v2.v[0] - v1.v[0] * v2.v[2],\n");
                fprintf(output, "        v1.v[0] * v2.v[1] - v1.v[1] * v2.v[0]");
                if (i == 4) {
                    fprintf(output, ",\n        0\n");
                } else {
                    fputs("\n", output);
                }
                fputs("    }};\n", output);
                fprintf(output, "}\n\n");
            }

            // e.g. NVec2i_proj(NVec2i(x, y))

            fprintf(output, "%s NVec%i%c_t NVec%i%c_proj(NVec%i%c_t v1, NVec%i%c_t v2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    float scale = NVec%i%c_dot(v2, v1) / NVec%i%c_dot(v2, v2);\n", i, types[y][0], i, types[y][0]);
            fprintf(output, "    NVec%i%c_t ret = NVec%i%c_muls(v2, scale);\n", i, types[y][0], i, types[y][0]);
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");


            // e.g. NMat2i_add(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_add(NMat%i%c_t m1, NMat%i%c_t m2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NMat%i%c_t ret = (NMat%i%c_t) {{", i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    fprintf(output, "m1.m%c%c + m2.m%c%c", mat_names[j], mat_names[x], mat_names[j], mat_names[x]);
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, ", ");
                    }
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_sub(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_sub(NMat%i%c_t m1, NMat%i%c_t m2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NMat%i%c_t ret = (NMat%i%c_t) {{", i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    fprintf(output, "m1.m%c%c - m2.m%c%c", mat_names[j], mat_names[x], mat_names[j], mat_names[x]);
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, ", ");
                    }
                }
            }
            fprintf(output, "}};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            // e.g. NMat2i_mul(...)

            fprintf(output, "%s NMat%i%c_t NMat%i%c_mul(NMat%i%c_t m1, NMat%i%c_t m2) {\n",
                func_def, i, types[y][0], i, types[y][0], i, types[y][0], i, types[y][0]);
            fprintf(output, "    NMat%i%c_t ret = (NMat%i%c_t) {{\n", i, types[y][0], i, types[y][0]);
            for (int j = 0; j < i; j++) {
                for (int x = 0; x < i; x++) {
                    fprintf(output, "        ");
#define docalc(m00, m01, m10, m11) fprintf(output, "m1.m%c%c * m2.m%c%c", mat_names[m00], mat_names[m01], mat_names[m10], mat_names[m11])
                    for (int z = 0; z < i; z++) {
                        docalc(z, x, j, z);
                        if ((z + 1) < i) {
                            fprintf(output, " + ");
                        }
                    }
                    if (((j + 1) * (x + 1)) < (i * i)) {
                        fprintf(output, ",\n");
                    } else {
                        fprintf(output, "\n");
                    }
                }
            }
            fprintf(output, "    }};\n");
            fprintf(output, "    return ret;\n");
            fprintf(output, "}\n\n");

            if (i >= 3) {
                // e.g. NMat3f_scale_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_scale_%i%c(NMat%i%c_t m1, NVec%i%c_t v1) {\n",
                            func_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i, types[y][0], i1, types[y1][0]);
                        fprintf(output, "    return (NMat%i%c_t) {{\n", i, types[y][0]);
                        fprintf(output, "        ");
                        for (int j = 0; j < i; j++) {
                            fprintf(output, "m1.m0%i * v1.v[0], ", j);
                        }
                        fprintf(output, "\n");

                        fprintf(output, "        ");
                        for (int j = 0; j < i; j++) {
                            fprintf(output, "m1.m1%i * v1.v[1], ", j);
                        }
                        fprintf(output, "\n");

                        fprintf(output, "        ");
                        for (int j = 0; j < i; j++) {
                            fprintf(output, "m1.m2%i * v1.v[2]", j);
                            if (i != 3 || j != 2) {
                                fprintf(output, ", ");
                            }
                        }
                        fprintf(output, "\n");

                        if (i == 4) {
                            fprintf(output, "        m1.m30, m1.m31, m1.m32, m1.m33\n");
                        }

                        fprintf(output, "    }};\n");
                        fprintf(output, "}\n\n");
                    }
                }

                // e.g. NMat3f_rotation_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_rotation_%i%c(float radians, NVec%i%c_t v1) {\n",
                            func_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i1, types[y1][0]);
                        fprintf(output, "    NVec%i%c_t v1_norm = NVec%i%c_norm(v1);\n", i1, types[y1][0], i1, types[y1][0]);
                        fprintf(output, "    float radcos = cosf(radians);\n");
                        fprintf(output, "    float invradcos = 1.f / radcos;\n");
                        fprintf(output, "    float radsin = sinf(radians);\n");
                        fprintf(output, "    %s v01 = v1_norm.v[0] * v1_norm.v[1];\n", types[y1]);
                        fprintf(output, "    %s v02 = v1_norm.v[0] * v1_norm.v[2];\n", types[y1]);
                        fprintf(output, "    %s v12 = v1_norm.v[1] * v1_norm.v[2];\n", types[y1]);
                        fprintf(output, "    return (NMat%i%c_t) {{\n", i, types[y][0]);
                        fprintf(output, "        ");
                        fprintf(output, "radcos + invradcos * v1_norm.v[0] * v1_norm.v[0], ");
                        fprintf(output, "invradcos * v01 + v1_norm.v[2] * radsin, ");
                        fprintf(output, "invradcos * v02 - v1_norm.v[1] * radsin, ");
                        if (i == 4) fprintf(output, "0.f,\n"); else fprintf(output, "\n");

                        fprintf(output, "        ");
                        fprintf(output, "invradcos * v01 - v1_norm.v[2] * radsin, ");
                        fprintf(output, "radcos + invradcos * v1_norm.v[1] * v1_norm.v[1], ");
                        fprintf(output, "invradcos * v12 + v1_norm.v[0] * radsin, ");
                        if (i == 4) fprintf(output, "0.f,\n"); else fprintf(output, "\n");

                        fprintf(output, "        ");
                        fprintf(output, "invradcos * v02 + v1_norm.v[1] * radsin, ");
                        fprintf(output, "invradcos * v12 - v1_norm.v[0] * radsin, ");
                        fprintf(output, "radcos + invradcos * v1_norm.v[2] * v1_norm.v[2]");
                        if (i == 4) fprintf(output, ", 0.f,\n"); else fprintf(output, "\n");

                        if (i == 4) {
                            fprintf(output, "        0.f, 0.f, 0.f, 1.f\n");
                        }

                        fprintf(output, "    }};\n");
                        fprintf(output, "}\n\n");
                    }
                }

                // e.g. NMat3f_rotate_3f()

                for (int i1 = 3; i1 <= 4; i1++) {
                    for (int y1 = 0; y1 < 2; y1++) {
                        fprintf(output, "%s NMat%i%c_t NMat%i%c_rotate_%i%c(NMat%i%c_t m1, float radians, NVec%i%c_t v1) {\n",
                            func_def, i, types[y][0], i, types[y][0], i1, types[y1][0], i, types[y][0], i1, types[y1][0]);
                        fprintf(output, "    return NMat%i%c_mul(m1, NMat%i%c_rotation_%i%c(radians, v1));\n", i, types[y][0], i, types[y][0], i1, types[y1][0]);
                        fprintf(output, "}\n\n");
                    }
                }
            }

            if (i == 4 && types[y][0] == 'f') {
                // e.g. NMat4f_translate()

                for (int y1 = 0; y1 < 2; y1++) {
                    fprintf(output, "%s NMat4f_t NMat4f_translate_3%c(NMat4f_t m1, NVec3%c_t v1) {\n", func_def, types[y1][0], types[y1][0]);
                    fprintf(output, "    return (NMat4f_t) {{\n");
                    fprintf(output, "        m1.m00, m1.m01, m1.m02, m1.m03,\n");
                    fprintf(output, "        m1.m10, m1.m11, m1.m12, m1.m13,\n");
                    fprintf(output, "        m1.m20, m1.m21, m1.m22, m1.m23,\n");
                    fprintf(output, "        m1.m00 * v1.x + m1.m10 * v1.y + m1.m20 * v1.z + m1.m30,\n");
                    fprintf(output, "        m1.m01 * v1.x + m1.m11 * v1.y + m1.m21 * v1.z + m1.m31,\n");
                    fprintf(output, "        m1.m02 * v1.x + m1.m12 * v1.y + m1.m22 * v1.z + m1.m32,\n");
                    fprintf(output, "        m1.m33\n");
                    fprintf(output, "    }};\n");
                    fprintf(output, "}\n\n");
                }

                // e.g. NMat4f_perspective()

                fprintf(output, "%s NMat4f_t NMat4f_perspective(float fov_rad, float aspect, float nearZ, float farZ) {\n",
                    func_def);
                fprintf(output, "    float arctan = 1.f / tanf(fov_rad / 2.f);\n");
                fprintf(output, "    float invnf = 1.f / (nearZ - farZ);\n");
                fprintf(output, "    return (NMat4f_t) {{\n");
                fprintf(output, "        arctan / aspect, 0.f, 0.f, 0.f,\n");
                fprintf(output, "        0.f, arctan, 0.f, 0.f,\n");
                fprintf(output, "        0.f, 0.f, (farZ + nearZ) * invnf, -1.f,\n");
                fprintf(output, "        0.f, 0.f, (2.f * farZ * nearZ) * invnf, 0.f\n");
                fprintf(output, "    }};\n");
                fprintf(output, "}\n\n");

                // e.g. NMat4f_frustum()

                fprintf(output, "%s NMat4f_t NMat4f_frustum(float left, float right, float bottom, float top, float nearZ, float farZ) {\n",
                    func_def);
                fprintf(output, "    float invrl = 1.f / (right - left);\n");
                fprintf(output, "    float invtb = 1.f / (top - bottom);\n");
                fprintf(output, "    float invfn = 1.f / (farZ - nearZ);\n");
                fprintf(output, "    float _2n    = 2.f * nearZ;\n");
                fprintf(output, "    return (NMat4f_t) {{\n");
                fprintf(output, "        _2n * invrl, 0.f, 0.f, 0.f,\n");
                fprintf(output, "        0.f, _2n * invtb, 0.f, 0.f,\n");
                fprintf(output, "        (right + left) * invrl, (top + bottom) * invtb, -(farZ + nearZ) * invfn, -1.f,\n");
                fprintf(output, "        0.f, 0.f, (-_2n * farZ) * invfn, 0.f\n");
                fprintf(output, "    }};\n");
                fprintf(output, "}\n\n");

                // e.g. NMat4f_ortho()

                fprintf(output, "%s NMat4f_t NMat4f_ortho(float left, float right, float bottom, float top, float nearZ, float farZ) {\n",
                    func_def);
                fprintf(output, "    float invrl = 1.f / (right - left);\n");
                fprintf(output, "    float invtb = 1.f / (top - bottom);\n");
                fprintf(output, "    float invfn = 1.f / (farZ - nearZ);\n");

                fprintf(output, "    return (NMat4f_t) {{\n");
                fprintf(output, "        2.f * invrl, 0.f, 0.f, 0.f,\n");
                fprintf(output, "        0.f, 2.f * invtb, 0.f, 0.f,\n");
                fprintf(output, "        0.f, 0.f, -2.f * invfn, 0.f,\n");
                fprintf(output, "        -(right + left) * invrl, -(top + bottom) * invtb, -(farZ + nearZ) * invfn, 1.f\n");
                fprintf(output, "    }};\n");
                fprintf(output, "}\n\n");

                // TODO: Add LookAt function
            }
        }
    }

    return 0;
}

NKTool vecmathbuilder_tool = {
    .command = "vecmathbuilder",
    .description = "Generates the vector math library",
    .tool = vecmathbuilder
};
