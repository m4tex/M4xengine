#version 410 core

uniform vec3 u_Color;
out vec4 color;

float fade_farDistance = 4.0;
float fade_nearDistance = 0.1;

vec4 fadeColor = vec4(0.15, 0.15, 0.15, 1.0);

void main() {
    float distance = gl_FragCoord.z * gl_FragCoord.w;
    float fade = (fade_farDistance - distance) / (fade_farDistance - fade_nearDistance);

    color = mix(fadeColor, vec4(u_Color, 1.0), clamp(fade, 0.0, 1.0));
}