#version 330 core
//#extension GL_ARB_separate_shader_objects : enable

in vec3 vertex_position;
in vec2 vertex_UV;

uniform mat4 MVP;
uniform bool flip;

out vec2 UV;

void main(){
    gl_Position = MVP * vec4(vertex_position, 1);
    //gl_Position = sign(gl_Position);
    UV = vertex_UV;
    if (flip) {
        if (UV.x == 0) {
            UV.x = 1;
        } else {
            UV.x = 0;
        }
    }
}
