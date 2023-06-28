#version 410

in VertexData {
    vec4 vertexPos;
    float lineBrightness;
} VertexInput;

out vec4 Color;

//uniform vec3 u_Color;
uniform vec3 u_CamPos;

float fogMin = 100.0;
float fogMax = 250.0;

vec4 fogColor = vec4(0.15, 0.15, 0.15, 1.0);

void main() {
    float distance = distance(VertexInput.vertexPos, vec4(u_CamPos, 1.0));
    float fogFactor = 1 - (fogMax - distance) / (fogMax - fogMin);
    vec4 color = vec4(VertexInput.lineBrightness, VertexInput.lineBrightness, VertexInput.lineBrightness, 1.0);
    Color = mix(color, fogColor, clamp(fogFactor, 0.0, 1.0));
}