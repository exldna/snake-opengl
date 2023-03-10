#version 460 core

layout (points) in;
layout (triangle_strip, max_vertices = 6) out;

uniform mat4 projection;

void main() {
    vec4 v1 = projection * (gl_in[0].gl_Position + vec4(1, 1, 0, 0));
    vec4 v2 = projection * (gl_in[0].gl_Position + vec4(1, 0, 0, 0));
    vec4 v3 = projection * (gl_in[0].gl_Position + vec4(0, 0, 0, 0));
    vec4 v4 = projection * (gl_in[0].gl_Position + vec4(0, 1, 0, 0));

    gl_Position = v1;
    EmitVertex();
    gl_Position = v2;
    EmitVertex();
    gl_Position = v3;
    EmitVertex();
    EndPrimitive();

    gl_Position = v1;
    EmitVertex();
    gl_Position = v3;
    EmitVertex();
    gl_Position = v4;
    EmitVertex();
    EndPrimitive();
}