// minimalistic code to draw a single triangle, this is not part of the API.
// Simple Vertex Shader
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/transform.hpp>
#include "Level_Data.h"
#define PLIGHT_COUNT 5

const char* vertexShaderSource = R"(
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
)";
// Simple Fragment Shader
const char* fragmentShaderSource = R"(
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

in vec3 norm;
in vec3 light;
in vec3 frag;

out vec4 outColor;

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
)";
// Used to print debug infomation from OpenGL, pulled straight from the official OpenGL wiki.
#ifndef NDEBUG
void MessageCallback(GLenum source, GLenum type, GLuint id,
	GLenum severity, GLsizei length,
	const GLchar* message, const void* userParam) {
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
		(type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}
#endif
/*
struct UBO_DATA
{
	glm::vec4 sunDirection, sunColor;
	glm::mat4 PVM;
	MyAttrib material;
	glm::vec3 viewPos;
};
*/
struct UBO_DATA
{
	glm::vec4 sunDirection, sunColor;
	glm::mat4 model;
	glm::mat4 view;
	glm::mat4 pers;
	MyAttrib material;
	glm::vec4 viewPos;
};

// Creation, Rendering & Cleanup
class Renderer
{

	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GOpenGLSurface ogl;
	// what we need at a minimum to draw a triangle
	GLuint vertexArray = 0;
	GLuint vertexBufferObject = 0;
	GLuint indexBufferObject = 0;

	GLuint vertexShader = 0;
	GLuint fragmentShader = 0;
	GLuint shaderExecutable = 0;
	GLuint lightUniform = 0;
	glm::mat4 world[2], view, proj;
	glm::vec3 eye, orient, up, right;
	float pitch = 0.0f;
	float yaw = 0.0f;
	std::chrono::steady_clock::time_point startRend;	// for world mat rotation
	std::chrono::steady_clock::time_point start;
	GW::INPUT::GInput input;
	GW::INPUT::GController controller;
	bool enableMouse[2];

	UBO_DATA data{};
	unsigned int blockIndex;
	GLuint UBO;
	GLint blockSize;

	Level_Data LevelData;

public:
	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GOpenGLSurface _ogl)
	{
		/*
		box test
		RoomTest
		GameLevel
		FloorTest
		AssetTest
		Collapse
		*/
		LevelData.loadLevel("Collapse");

		win = _win;
		ogl = _ogl;

		controller.Create();
		input.Create(_win);

		eye = { 1.15f, 2.0f, 1.5f };
		orient = { -0.65f, 0.15f, -0.75f };
		up = { 0.0f, 1.0f, 0.0f };
		view = glm::lookAt(eye, orient, up);

		float ar;
		ogl.GetAspectRatio(ar);
		proj = glm::perspective(glm::radians(65.0f), ar, 0.1f, 100.0f);

		glm::mat4 identity(1.0f);
		world[0] = identity;
		world[1] = identity;

		startRend = std::chrono::steady_clock::now();
		// Link Needed OpenGL API functions
		LoadExtensions();
		// In debug mode we link openGL errors to the console
#ifndef NDEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glDebugMessageCallback(MessageCallback, 0);
#endif

		// Create Vertex Buffer
		glm::vec3 verts[11000][3] = {}; // 0 = pos 1 = uvw 2 = nrm
		//std::vector<glm::vec3> verts[3];
		for (int i = 0; i < LevelData.vertexCount; i++)
		{
			verts[i][0] = LevelData.vertices[i].pos;
			verts[i][1] = LevelData.vertices[i].uvw;
			verts[i][2] = LevelData.vertices[i].nrm;
		}
		glGenVertexArrays(1, &vertexArray);
		glGenBuffers(1, &vertexBufferObject);
		glBindVertexArray(vertexArray);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObject);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)0);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(3 * sizeof(float)));
		glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 9 * sizeof(float), (void*)(6 * sizeof(float)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
		glEnableVertexAttribArray(2);



		std::vector<unsigned int> index;
		for (int i = 0; i < LevelData.indexCount; i++)
		{
			index.push_back(LevelData.indices[i]);
		}

		glGenBuffers(1, &indexBufferObject);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBufferObject);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, index.size() * sizeof(unsigned int), &index[0], GL_STATIC_DRAW);
		// unbind
		glBindVertexArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

		// Create Vertex Shader
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
		glCompileShader(vertexShader);
		char errors[1024]; GLint result;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(vertexShader, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}
		// Create Fragment Shader
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
		glCompileShader(fragmentShader);
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &result);
		if (result == false)
		{
			glGetShaderInfoLog(fragmentShader, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}
		// Create Executable Shader Program
		shaderExecutable = glCreateProgram();
		glAttachShader(shaderExecutable, vertexShader);
		glAttachShader(shaderExecutable, fragmentShader);
		glLinkProgram(shaderExecutable);
		glGetProgramiv(shaderExecutable, GL_LINK_STATUS, &result);
		if (result == false)
		{
			glGetProgramInfoLog(shaderExecutable, 1024, NULL, errors);
			std::cout << errors << std::endl;
		}

		glUseProgram(shaderExecutable);

		// get the index of UBO_DATA
		blockIndex = glGetUniformBlockIndex(shaderExecutable, "UBO_DATA");
		// get the size of the memory for UBO_DATA
		glGetActiveUniformBlockiv(shaderExecutable, blockIndex, GL_UNIFORM_BLOCK_DATA_SIZE, &blockSize);

		glGenBuffers(1, &UBO);
		glBindBuffer(GL_UNIFORM_BUFFER, UBO);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(UBO_DATA), &data, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, UBO);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
	}
	void Render()
	{
		// setup the pipeline

		glUseProgram(shaderExecutable);
		glBindVertexArray(vertexArray);

		// now we can draw

		GLuint uboLoc = glGetUniformBlockIndex(shaderExecutable, "UBO_DATA");
		glUniformBlockBinding(shaderExecutable, uboLoc, blockIndex);

		// draw text
		data.sunDirection = { 2.0f, -5.0f, 2.0f, 0.0f };
		data.sunColor = { 0.50f, 0.50f, 0.70f, 1.0f };
		data.viewPos = { eye.x, eye.y, eye.z, 0.0f };
		
		for (int i = 0; i < LevelData.modelCount; i++)
		{
			unsigned int modelIndex = LevelData.getModelIndex(LevelData.model[i]);
			data.model = LevelData.worldMatrix[i];
			data.pers = proj;
			data.view = view;

			for (int j = 0; j < LevelData.batches.size(); j++)
			{
				if (LevelData.model[i] == LevelData.batches[j].modelName)
				{
					data.material = LevelData.materials[LevelData.getMaterialIndex(j)];

					glBindBuffer(GL_UNIFORM_BUFFER, UBO);
					glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(data), (void*)&data);

					glDrawElements(GL_TRIANGLES, LevelData.batches[j].indexCount, GL_UNSIGNED_INT, (void*)((LevelData.batches[j].indexOffset) * sizeof(unsigned int)));
					
				}
			}

		}

		// some video cards(cough Intel) need this set back to zero or they won't display
		glBindVertexArray(0);
	}
	
	void UpdateCamera()
	{
		// takes time interval since this function was last called
		std::chrono::steady_clock::time_point tick = std::chrono::steady_clock::now();
		std::chrono::duration<float, std::milli> duration = (tick - start);
		start = std::chrono::steady_clock::now();

		// checks if a controller is connected
		bool conConnected = false;
		controller.IsConnected(0, conConnected);

		// a modifier for movement speed, multipled by the amount of time since the last frame update
		const float moveSpeed = 0.015f;
		float curSpeed = moveSpeed * duration.count();

		// using arrays to store movement inputs, final input will be the last index of each array
		float deltaY[5] = { 0 };
		float deltaX[4] = { 0 };
		float deltaZ[4] = { 0 };

		input.GetState(G_KEY_SPACE, deltaY[0]);
		input.GetState(G_KEY_LEFTSHIFT, deltaY[1]);
		if (conConnected)
		{
			controller.GetState(0, G_RIGHT_TRIGGER_AXIS, deltaY[2]);
			controller.GetState(0, G_LEFT_TRIGGER_AXIS, deltaY[3]);
		}

		deltaY[4] = (deltaY[0] - deltaY[1] + deltaY[2] - deltaY[3]) * curSpeed;

		input.GetState(G_KEY_D, deltaX[0]);
		input.GetState(G_KEY_A, deltaX[1]);
		if (conConnected)
		{
			controller.GetState(0, G_LX_AXIS, deltaX[2]);
		}

		deltaX[3] = (deltaX[0] - deltaX[1] + deltaX[2]) * curSpeed;

		input.GetState(G_KEY_W, deltaZ[0]);
		input.GetState(G_KEY_S, deltaZ[1]);
		if (conConnected)
		{
			controller.GetState(0, G_LY_AXIS, deltaZ[2]);
		}

		deltaZ[3] = (deltaZ[0] - deltaZ[1] + deltaZ[2]) * curSpeed;

		// modifier for analog stick input 
		float thumbSpeed = 0.25f * duration.count();
		// overall sensitivity modifier
		float lookSpeed = 0.03f;
		// Right stick X & Y axies
		float RSY = 0.0f;
		float RSX = 0.0f;
		// mouse X & Y axies
		float mouseX = 0.0f;
		float mouseY = 0.0f;
		// aspect ratio, height and width of window
		float ar;
		unsigned int height;
		unsigned int width;
		ogl.GOpenGLSurface::GetAspectRatio(ar);
		win.GetHeight(height);
		win.GetWidth(width);

		// rudimentary toggle to enable/disable mouse control 
		float checkMouse = 0.0f;
		input.GetState(G_KEY_LEFTCONTROL, checkMouse);
		if (checkMouse > 0 && !enableMouse[1])
		{
			enableMouse[0] = !enableMouse[0];
			enableMouse[1] = true;
			if (enableMouse[0])
			{
				std::cout << "Mouse enabled" << std::endl;
			}
			else
			{
				std::cout << "Mouse disabled" << std::endl;
			}
		}

		if (checkMouse == 0)
		{
			enableMouse[1] = false;
		}

		if (enableMouse[0])
		{
			POINT point;
			GetCursorPos(&point);
			mouseX = point.x - ((float)width / 2);	// yaw
			mouseY = point.y - ((float)height / 2);	// pitch
			// offset for rounding errors
			if (height % 2 == 1)
			{
				mouseY += 0.5;
			}
			if (width % 2 == 1)
			{
				mouseX += 0.5f;
			}

			SetCursorPos(width / 2, height / 2);
		}

		if (conConnected)
		{
			controller.GetState(0, G_RY_AXIS, RSY);
			controller.GetState(0, G_RX_AXIS, RSX);
		}

		float deltaPitch = (65.0f * mouseY / height + RSY * (-thumbSpeed)) * lookSpeed;	// yrot
		float deltaYaw = (65.0f * ar * mouseX / width + RSX * thumbSpeed) * lookSpeed;	// xrot

		// inverts delta yaw if the "camera" is upside down, still gets weird at the Y poles
		if (up.y < 0.0f)
		{
			deltaYaw *= -1.0f;
		}

		if (deltaPitch != 0 || deltaYaw != 0)
		{
			if (deltaPitch != 0)
			{
				pitch -= deltaPitch;
			}
			if (deltaYaw != 0)
			{
				yaw -= deltaYaw;
			}

			orient = { cosf(pitch) * sinf(yaw), sin(pitch), cos(pitch) * cos(yaw) };
			right = { sinf(yaw - M_PI / 2.0f), 0.0f, cosf(yaw - M_PI / 2.0f) };
			up = glm::cross(right, orient);

			std::cout << "Orient: X = " << orient.x << ", Y = " << orient.y << ", Z = " << orient.z << std::endl;
			std::cout << "pitch: " << pitch << "\nyaw: " << yaw << std::endl;
		}

		if (deltaZ[3] != 0 || deltaX[3] != 0 || deltaY[4] != 0)
		{
			// "moves" the eye/position of the camera along the orient, right and up vectors by a factor of deltaZ, deltaX and deltaY respectively
			if (deltaZ[3] != 0)
			{
				std::cout << "move Z: " << deltaZ[3] << std::endl;
				eye += orient * deltaZ[3];
			}
			if (deltaX[3] != 0)
			{
				std::cout << "move X: " << deltaX[3] << std::endl;
				eye += right * deltaX[3];
			}
			if (deltaY[4] != 0)
			{
				std::cout << "move Y: " << deltaY[4] << std::endl;
				eye += up * deltaY[4];
			}
			std::cout << "Position: X = " << eye.x << " Y = " << eye.y << " Z = " << eye.z << std::endl;
		}

		view = glm::lookAt(eye, (eye + orient), up);
	}

	~Renderer()
	{
		// free resources
		glDeleteVertexArrays(1, &vertexArray);
		glDeleteBuffers(1, &vertexBufferObject);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
		glDeleteProgram(shaderExecutable);
	}
private:
	// Modern OpenGL API Functions must be queried before use
	PFNGLCREATESHADERPROC				glCreateShader = nullptr;
	PFNGLSHADERSOURCEPROC				glShaderSource = nullptr;
	PFNGLCOMPILESHADERPROC				glCompileShader = nullptr;
	PFNGLGETSHADERIVPROC				glGetShaderiv = nullptr;
	PFNGLGETSHADERINFOLOGPROC			glGetShaderInfoLog = nullptr;
	PFNGLATTACHSHADERPROC				glAttachShader = nullptr;
	PFNGLDETACHSHADERPROC				glDetachShader = nullptr;
	PFNGLDELETESHADERPROC				glDeleteShader = nullptr;
	PFNGLCREATEPROGRAMPROC				glCreateProgram = nullptr;
	PFNGLLINKPROGRAMPROC				glLinkProgram = nullptr;
	PFNGLUSEPROGRAMPROC					glUseProgram = nullptr;
	PFNGLGETPROGRAMIVPROC				glGetProgramiv = nullptr;
	PFNGLGETPROGRAMINFOLOGPROC			glGetProgramInfoLog = nullptr;
	PFNGLGENVERTEXARRAYSPROC			glGenVertexArrays = nullptr;
	PFNGLBINDVERTEXARRAYPROC			glBindVertexArray = nullptr;
	PFNGLGENBUFFERSPROC					glGenBuffers = nullptr;
	PFNGLBINDBUFFERPROC					glBindBuffer = nullptr;
	PFNGLBUFFERDATAPROC					glBufferData = nullptr;
	PFNGLENABLEVERTEXATTRIBARRAYPROC	glEnableVertexAttribArray = nullptr;
	PFNGLDISABLEVERTEXATTRIBARRAYPROC	glDisableVertexAttribArray = nullptr;
	PFNGLVERTEXATTRIBPOINTERPROC		glVertexAttribPointer = nullptr;
	PFNGLGETUNIFORMLOCATIONPROC			glGetUniformLocation = nullptr;
	PFNGLUNIFORMMATRIX4FVPROC			glUniformMatrix4fv = nullptr;
	PFNGLDELETEBUFFERSPROC				glDeleteBuffers = nullptr;
	PFNGLDELETEPROGRAMPROC				glDeleteProgram = nullptr;
	PFNGLDELETEVERTEXARRAYSPROC			glDeleteVertexArrays = nullptr;
	PFNGLDEBUGMESSAGECALLBACKPROC		glDebugMessageCallback = nullptr;

	PFNGLGETUNIFORMBLOCKINDEXPROC		glGetUniformBlockIndex = nullptr;
	PFNGLGETACTIVEUNIFORMBLOCKIVPROC	glGetActiveUniformBlockiv = nullptr;
	PFNGLGETUNIFORMINDICESPROC			glGetUniformIndices = nullptr;
	PFNGLCREATEBUFFERSPROC				glCreateBuffers = nullptr;
	PFNGLNAMEDBUFFERSTORAGEPROC			glNamedBufferStorage = nullptr;
	PFNGLGETACTIVEUNIFORMSIVPROC		glGetActiveUniformsiv = nullptr;
	PFNGLBINDBUFFERRANGEPROC			glBindBufferRange = nullptr;
	PFNGLBINDBUFFERBASEPROC				glBindBufferBase = nullptr;
	PFNGLMAPBUFFERPROC					glMapBuffer = nullptr;
	PFNGLUNMAPBUFFERPROC				glUnmapBuffer = nullptr;
	PFNGLUNIFORMBLOCKBINDINGPROC		glUniformBlockBinding = nullptr;
	PFNGLUNIFORM4FVPROC					glUniform4fv = nullptr;
	PFNGLBUFFERSUBDATAPROC				glBufferSubData = nullptr;

	// Modern OpenGL API functions need to be queried
	void LoadExtensions()
	{
		ogl.QueryExtensionFunction(nullptr, "glCreateShader", (void**)&glCreateShader);
		ogl.QueryExtensionFunction(nullptr, "glShaderSource", (void**)&glShaderSource);
		ogl.QueryExtensionFunction(nullptr, "glCompileShader", (void**)&glCompileShader);
		ogl.QueryExtensionFunction(nullptr, "glGetShaderiv", (void**)&glGetShaderiv);
		ogl.QueryExtensionFunction(nullptr, "glGetShaderInfoLog", (void**)&glGetShaderInfoLog);
		ogl.QueryExtensionFunction(nullptr, "glAttachShader", (void**)&glAttachShader);
		ogl.QueryExtensionFunction(nullptr, "glDetachShader", (void**)&glDetachShader);
		ogl.QueryExtensionFunction(nullptr, "glDeleteShader", (void**)&glDeleteShader);
		ogl.QueryExtensionFunction(nullptr, "glCreateProgram", (void**)&glCreateProgram);
		ogl.QueryExtensionFunction(nullptr, "glLinkProgram", (void**)&glLinkProgram);
		ogl.QueryExtensionFunction(nullptr, "glUseProgram", (void**)&glUseProgram);
		ogl.QueryExtensionFunction(nullptr, "glGetProgramiv", (void**)&glGetProgramiv);
		ogl.QueryExtensionFunction(nullptr, "glGetProgramInfoLog", (void**)&glGetProgramInfoLog);
		ogl.QueryExtensionFunction(nullptr, "glGenVertexArrays", (void**)&glGenVertexArrays);
		ogl.QueryExtensionFunction(nullptr, "glBindVertexArray", (void**)&glBindVertexArray);
		ogl.QueryExtensionFunction(nullptr, "glGenBuffers", (void**)&glGenBuffers);
		ogl.QueryExtensionFunction(nullptr, "glBindBuffer", (void**)&glBindBuffer);
		ogl.QueryExtensionFunction(nullptr, "glBufferData", (void**)&glBufferData);
		ogl.QueryExtensionFunction(nullptr, "glEnableVertexAttribArray", (void**)&glEnableVertexAttribArray);
		ogl.QueryExtensionFunction(nullptr, "glDisableVertexAttribArray", (void**)&glDisableVertexAttribArray);
		ogl.QueryExtensionFunction(nullptr, "glVertexAttribPointer", (void**)&glVertexAttribPointer);
		ogl.QueryExtensionFunction(nullptr, "glGetUniformLocation", (void**)&glGetUniformLocation);
		ogl.QueryExtensionFunction(nullptr, "glUniformMatrix4fv", (void**)&glUniformMatrix4fv);
		ogl.QueryExtensionFunction(nullptr, "glDeleteBuffers", (void**)&glDeleteBuffers);
		ogl.QueryExtensionFunction(nullptr, "glDeleteProgram", (void**)&glDeleteProgram);
		ogl.QueryExtensionFunction(nullptr, "glDeleteVertexArrays", (void**)&glDeleteVertexArrays);
		ogl.QueryExtensionFunction(nullptr, "glDebugMessageCallback", (void**)&glDebugMessageCallback);

		ogl.QueryExtensionFunction(nullptr, "glGetUniformBlockIndex", (void**)&glGetUniformBlockIndex);
		ogl.QueryExtensionFunction(nullptr, "glGetActiveUniformBlockiv", (void**)&glGetActiveUniformBlockiv);
		ogl.QueryExtensionFunction(nullptr, "glGetUniformIndices", (void**)&glGetUniformIndices);
		ogl.QueryExtensionFunction(nullptr, "glCreateBuffers", (void**)&glCreateBuffers);
		ogl.QueryExtensionFunction(nullptr, "glNamedBufferStorage", (void**)&glNamedBufferStorage);
		ogl.QueryExtensionFunction(nullptr, "glGetActiveUniformsiv", (void**)&glGetActiveUniformsiv);
		ogl.QueryExtensionFunction(nullptr, "glBindBufferRange", (void**)&glBindBufferRange);
		ogl.QueryExtensionFunction(nullptr, "glBindBufferBase", (void**)&glBindBufferBase);
		ogl.QueryExtensionFunction(nullptr, "glMapBuffer", (void**)&glMapBuffer);
		ogl.QueryExtensionFunction(nullptr, "glUnmapBuffer", (void**)&glUnmapBuffer);
		ogl.QueryExtensionFunction(nullptr, "glUniformBlockBinding", (void**)&glUniformBlockBinding);
		ogl.QueryExtensionFunction(nullptr, "glUniform4fv", (void**)&glUniform4fv);
		ogl.QueryExtensionFunction(nullptr, "glBufferSubData", (void**)&glBufferSubData);
	}
};