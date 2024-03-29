#version 410 core

in vec3 g_Normal;

out vec4 color;

uniform vec3 u_Ambient;
uniform vec3 u_LightDir;
uniform float u_Bias;
uniform float u_Shininess;
uniform vec3 u_Color;

void main()
{
    float diffuse = max(0.0, dot(g_Normal, normalize(u_LightDir)) + u_Bias);
    diffuse = pow(diffuse, u_Shininess);

    color = vec4(u_Color, 1.0) * vec4(vec3(diffuse), 1.0) + vec4(u_Ambient, 1.0);
}