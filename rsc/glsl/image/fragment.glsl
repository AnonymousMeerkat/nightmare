#version 330 core

in vec2 UV;
out vec4 color;
uniform sampler2D texsampler;

void main(){
    color = texture(texsampler, UV).rgba;
}
