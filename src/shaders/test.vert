#version 410

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_colour;
layout(location = 2) in vec2 vertex_texture;

out vec3 colour;
out vec2 texture_coord;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;

void main() {
	colour = vertex_colour;
	texture_coord = vertex_texture;
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(vertex_position, 1.0);
}
