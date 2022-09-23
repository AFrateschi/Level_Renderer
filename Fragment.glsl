#version 420 // GLSL 3.30
// an ultra simple glsl fragment shader

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
struct PointLight
{
	vec3 pos;
	float cons;
	vec3 ambient;
	float line;
	vec3 diffuse;
	float quad;
	vec3 specular;
};

#define PLIGHT_COUNT 5

layout(std140, binding = 0) uniform UBO_DATA
{
	mat4 model;
	mat4 view;
	mat4 pers;
	OBJ_ATTRIBUTES material;
	vec4 viewPos;
	PointLight pointLights[PLIGHT_COUNT];
};


in vec3 norm;
in vec3 light;
in vec3 frag;

out vec4 outColor;

vec3 CalcPointLight(PointLight light, vec3 norm, vec3 fragPos, vec3 viewDir)
{
	vec3 lightDir = normalize(light.pos - fragPos);

	float diff = max(dot(norm, lightDir), 0.0f);

	vec3 halfvec = normalize(-light.pos + viewDir);

	vec3 reflectDir = reflect(-lightDir, norm);
	float spec = pow(max(dot(norm, halfvec), 0.0f), material.Ns);

	float dist = length(light.pos - fragPos);
	float attenuation = 1.0f / (light.cons + light.line * dist + light.quad * (dist * dist));

	vec3 ambient = light.ambient * material.Kd;
	vec3 diffuse = light.diffuse * diff * material.Kd;
	vec3 specular = light.specular * spec * material.Ks;
	ambient *= attenuation;
	diffuse *= attenuation;
	specular *= attenuation;

	return (ambient + diffuse + specular);
}

void main() 
{	
	// normalize in vectors
	vec3 fNorm = normalize(norm);
	vec3 viewDir = normalize(vec3(viewPos) - frag);

	

	vec3 result = {0.15f, 0.15f, 0.15f};

	for (int i = 0; i < PLIGHT_COUNT; i++)
	{
		result += CalcPointLight(pointLights[i], norm, frag, viewDir);
	}

	outColor = clamp(vec4(result, 1.0f), 0.0f, 1.0f);
}
/*	ORGINAL SHADER single directional light source
void main() 
{	
	// normalize in vectors
	vec3 fNorm = normalize(norm);
	vec3 fLight = normalize(light);
	// inverse becomes vector from fragment to camera
	//vec3 fFrag = normalize(frag);

	vec4 color = vec4(material.Kd, 1.0f);
	float ratio = max(dot(fNorm, -fLight), 0.0);
	// add ambient light to brighten overall image slightly
	//ratio = ratio + 0.25;
	vec4 diffuse = ratio * sunColor;
	vec4 ambient = vec4(0.25f, 0.25f, 0.35f, 0.0f);
	
	vec3 viewDir = normalize(vec3(viewPos) - frag);
	vec3 halfVec = normalize(-fLight + viewDir);
	float intensity = pow(max(dot(fNorm, halfVec), 0.0), material.Ns);
	vec4 specular = intensity * vec4(material.Ks, 1);


	outColor = clamp(diffuse + ambient, 0.0f, 1.0f) * color + specular;	
}
*/