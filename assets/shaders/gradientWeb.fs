#version 100
precision mediump float;

vec2 fragTexCoord;

vec4 finalColor;

uniform vec2 resolution;

void main() {

  float r = gl_FragCoord.x / resolution.x;
  float g = gl_FragCoord.y / resolution.y;

  finalColor = vec4(r, g, .0, 1.0);
  gl_FragColor = finalColor;
}
