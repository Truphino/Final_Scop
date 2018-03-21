#version 410

in vec3 colour;
in vec2 texture_coord;

out vec4 frag_colour;

uniform sampler2D tex;

void main() {
	frag_colour = texture(tex, texture_coord);
}
