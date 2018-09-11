#version 410

in vec3 colour;
in vec3 frag_position;
in vec3 frag_normal;

out vec4 frag_colour;

uniform sampler2D tex;
uniform mat4 model_matrix;
uniform vec3 light_position;
uniform vec3 light_color;

void main() {
	vec3 normal = normalize(frag_normal * transpose(inverse(mat3(model_matrix))));
	vec3 surface_pos = vec3(model_matrix * vec4(frag_position, 1));
	vec3 surface_to_light = normalize(light_position - surface_pos);
	float brightness = max(0.0, dot(normal, surface_to_light));
	vec4 surface_color = vec4(colour, 1);

//	frag_colour = vec4(brightness * light_color * surface_color.rgb,
//			surface_color.a);
	frag_colour = surface_color;
}
/**/
