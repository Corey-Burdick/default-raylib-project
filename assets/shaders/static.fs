#version 300 core

in vec2 fragTexCoord;

out vec4 finalColor;

uniform float uTime;

float random(vec2 st) {
  return fract(sin(dot(st.xy, vec2(12.9898, 78.233)) + uTime) * 43758.5453123);
}

void main() {
  float r = random(fragTexCoord + vec2(0.1, 0.2));
  float g = random(fragTexCoord + vec2(0.3, 0.4));
  float b = random(fragTexCoord + vec2(0.5, 0.6));

  finalColor = vec4(r, g, b, 1.0);
}
