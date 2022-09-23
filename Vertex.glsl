#version 420 // GLSL 3.30
// an ultra simple glsl vertex shader
struct OBJ_ATTRIBUTES
{
	vec3		Kd;			// diffuse reflectivity
	float		d;			// dissolve (transparency) 
	vec3		Ks;			// specular reflectivity
	float		Ns;			// specular exponent
	vec3		Ka;			// ambient reflectivity
	float		sharpness;	// local reflection map sharpness
	vec3		Tf;			// transmission filter
	float		Ni;			// optical density (index of refraction)
	vec3		Ke;			// emissive reflectivity
	uint		illum;		// illumination model
};
layout(std140, binding = 0) uniform UBO_DATA
{
	vec4 sunDirection;
	vec4 sunColor;
	mat4 model;
	mat4 view;
	mat4 pers;
	OBJ_ATTRIBUTES material;
	vec4 viewPos;
};

layout(location = 0) in vec3 local_pos;
layout(location = 1) in vec3 local_uvw;
layout(location = 2) in vec3 local_nrm;

out vec3 norm;	// output normal
out vec3 light;	// output of light, redundant?
out vec3 frag;	// vec from camera to fragment

void main()
{

	gl_Position = (pers * view * model) * vec4(local_pos, 1.0f);

	vec4 worldPos = model * vec4(local_pos, 1.0f);
	norm = mat3(model) * local_nrm;
	light = vec3(sunDirection);
	frag = worldPos.xyz;
}