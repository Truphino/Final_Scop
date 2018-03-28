#version 410

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_colour;
layout(location = 2) in vec2 vertex_texture;
layout(location = 3) in vec3 vertex_normal;
layout(location = 4) in vec3 explode_vector;

out vec3 colour;
out vec2 texture_coord;
out vec3 frag_position;
out vec3 frag_normal;

uniform mat4 model_matrix;
uniform mat4 view_matrix;
uniform mat4 projection_matrix;
uniform vec3 light_position;
uniform vec3 light_color;
uniform float explode_coef;

void main() {
	vec3 pos = vertex_position + (explode_coef * explode_vector);
	frag_position = pos;
	frag_normal = vertex_normal;
	colour = vertex_colour;
	texture_coord = vertex_texture;
	gl_Position = projection_matrix * view_matrix * model_matrix * vec4(pos, 1.0);
}
