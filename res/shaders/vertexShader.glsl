#version 420 core

layout(location = 0) in vec3 pos;
layout(location = 1) in int id;

layout(location = 0) out vec3 outColor;

void main() {
    outColor = pos * id;
    gl_Position = vec4(pos, 1.0f);
}