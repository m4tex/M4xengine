#version 410

layout(location = 0) in vec3 position;
layout(location = 1) in float brightness;

uniform mat4 u_MVP;

out VertexData {
    vec4 vertexPos;
    float lineBrightness;
} Output;

void main()
{
    Output.vertexPos = vec4(position, 1.0);
    Output.lineBrightness = brightness;
    gl_Position = u_MVP * vec4(position, 1.0);
}