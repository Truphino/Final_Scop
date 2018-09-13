#version 410

layout(location = 0) in vec3 vertex_position;
layout(location = 1) in vec3 vertex_normal;
layout(location = 2) in vec3 explode_vector;
layout(location = 3) in vec2 vertex_texture;
layout(location = 4) in vec3 vertex_colour;

out vec3 colour;
out vec2 texture_coord;
out vec3 frag_position;
out vec3 frag_normal;

uniform int texture_enabled;
uniform mat4 model_matrix;
uniform mat4 fps_view_matrix;
uniform mat4 projection_matrix;
uniform vec3 light_position;
uniform vec3 light_color;
uniform float explode_coef;
uniform int transition_enabled;
uniform double transition_time;

void main() {
	vec3 pos = vertex_position + (explode_coef * explode_vector);
	colour = vertex_colour;
	frag_position = pos;
	frag_normal = vertex_normal;
	texture_coord = vertex_texture;
	gl_Position = projection_matrix * fps_view_matrix * model_matrix * vec4(pos, 1.0);
}
