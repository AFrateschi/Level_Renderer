#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/transform.hpp>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "h2bParser.h"

struct MyAttrib
{
	// attributes
	glm::vec3 Kd;
	float d;
	glm::vec3 Ks;
	float Ns;
	glm::vec3 Ka; 
	float sharpness;
	glm::vec3 Tf;
	float Ni;
	glm::vec3 Ke;
	unsigned int illum;
};
struct MyVertex
{
	// vertex
	glm::vec3 pos, uvw, nrm;
};
struct MyBatch
{
	/*
		TODO:

		make my own batch that handles index count, index offset, material index, model name
			-index count comes directly from parse.batch.indexcount
			-index offset will be current index count before adding incoming index count
			-once complete meshes and batches will no longer be needed

		figure out what is going on with world matrix
			-I think it's a matter of columns and rows being different between opengl and blender
			-answer might be to transpose incoming matrix before adding it to the vector

	*/
	unsigned int indexCount;
	unsigned int indexOffset;
	unsigned int materialIndex;
	std::string modelName;
};
struct MODELDATA
{
	// vector data
	unsigned int indexOffset;			// remove covered in batch
	unsigned int vertexCount;			// move to level data
	unsigned int indexCount;			// move to level data, covered for models in batch
	unsigned int materialCount;			// copy to data for total count keep count for individual models as well?
	unsigned int meshCount;

	std::vector<MyVertex> vertices;		// move to level data, 1 vector for all vertex data
	std::vector<unsigned int> indices;	// move to level data, 1 vector for all index data
	std::vector<MyAttrib> materials;	// move to level data, 1 vector for all material data
	std::vector<MyBatch> batches;
	std::vector<H2B::MESH> meshes;

	std::string modelName;
};
struct PointLight
{
	glm::vec3 pos;
	float cons;
	glm::vec3 ambient;
	float line;
	glm::vec3 diffuse;
	float quad;
	glm::vec3 specular;
	float padding;
};
struct WorldMatrix
{
	float data[16] = {0.0f};
};
class Level_Data
{

public:
	Level_Data();
	~Level_Data();
	void loadLevel(std::string _in);
	MyVertex vertexConvert(H2B::VERTEX _in);
	glm::vec3 vectorConvert(H2B::VECTOR _in);
	WorldMatrix ExtractMatrix(std::fstream &_file, std::string _line);
	float ExtractLightFloat(std::fstream& _file, std::string _line);
	glm::vec3 ExtractLightVec(std::fstream& _file, std::string _line);
	unsigned int getModelIndex(std::string _in);
	unsigned int getMaterialIndex(unsigned int _batchIndex);
	unsigned int getBatch(std::string _in);

	std::vector<glm::mat4> worldMatrix;
	std::vector<std::string> model;
	std::vector<std::string> uniqueModel;
	//std::vector<MODELDATA> modelData;
	unsigned int uniqueModelCount;				// count of unique models
	unsigned int modelCount = 0;					// total number of models

	unsigned int vertexCount = 0;			// move to level data
	unsigned int indexCount = 0;			// move to level data, covered for models in batch
	unsigned int materialCount = 0;			// copy to data for total count keep count for individual models as well?
	unsigned int meshCount = 0;

	std::vector<MyVertex> vertices;		// move to level data, 1 vector for all vertex data
	std::vector<unsigned int> indices;	// move to level data, 1 vector for all index data
	std::vector<MyAttrib> materials;	// move to level data, 1 vector for all material data
	std::vector<MyBatch> batches;
	std::vector<PointLight> lights;

private:

};

Level_Data::Level_Data()
{
}

Level_Data::~Level_Data()
{
}

void Level_Data::loadLevel(std::string _in)
{
	std::string line;
	std::fstream file;

	file.open("../Levels/" + _in + ".txt", std::ios::in);
	if (file.is_open())
	{
		while (std::getline(file, line))
		{
			if (line == "MESH")
			{
				int index = 0;									// declare locals
				WorldMatrix worldData{};
				std::string modelName;

				std::cout << line << std::endl;
				std::getline(file, line);						// write out block type and go to next line

				modelName = line.substr(0, line.find('.'));		// trim .xyz from model name
				model.push_back(modelName);						// add model to vector

				if (!(std::count(uniqueModel.begin(), uniqueModel.end(), modelName)))
				{
					uniqueModel.push_back(modelName);			// makes a vector of all the unique models to get vertices for
				}

				std::cout << line << std::endl;
				std::getline(file, line);						// get first line of matrix

				worldData = ExtractMatrix(file, line);

				glm::mat4 worldIn =								// makes a temp matrix of our data input
				{
					worldData.data[0], worldData.data[1], worldData.data[2], worldData.data[3],
					worldData.data[4], worldData.data[5], worldData.data[6], worldData.data[7],
					worldData.data[8], worldData.data[9], worldData.data[10], worldData.data[11],
					worldData.data[12], worldData.data[13], worldData.data[14], worldData.data[15],
				};

				worldMatrix.push_back(worldIn);					// push matrix to our vector
				modelCount++;
			}
			else if (line == "LIGHT")
			{
				WorldMatrix worldData{};
				PointLight light{};

				std::cout << line << std::endl;
				std::getline(file, line);
				std::cout << line << std::endl;
				std::getline(file, line);						// get first line of matrix

				worldData = ExtractMatrix(file, line);

				light.pos = glm::vec3{ worldData.data[12], worldData.data[13], worldData.data[14] };
	
				light.cons = ExtractLightFloat(file, line);

				light.line = ExtractLightFloat(file, line);

				light.quad = ExtractLightFloat(file, line);

				light.ambient = ExtractLightVec(file, line);

				light.diffuse = ExtractLightVec(file, line);

				light.specular = ExtractLightVec(file, line);

				lights.push_back(light);
			}
			std::cout << line << std::endl;

		}
		file.close();

		uniqueModelCount = uniqueModel.size();

		H2B::Parser parse;
		unsigned int tempOffset = 0;
		for (int i = 0; i < uniqueModelCount; i++)
		{
			parse.Parse(("../Models/" + uniqueModel[i] + ".h2b").c_str());

			if (vertexCount != 0)
			{
				tempOffset = vertexCount;
			}
			
			vertexCount += parse.vertexCount;
			indexCount += parse.indexCount;
			materialCount += parse.materialCount;
			meshCount += parse.meshCount;

			for (int j = 0; j < parse.vertexCount; j++)
			{
				vertices.push_back(vertexConvert(parse.vertices[j]));
			}

			for (int j = 0; j < parse.materialCount; j++)
			{
				MyAttrib attribute;

				attribute.Kd = vectorConvert(parse.materials[j].attrib.Kd);
				attribute.Ks = vectorConvert(parse.materials[j].attrib.Ks);
				attribute.Ka = vectorConvert(parse.materials[j].attrib.Ka);
				attribute.Tf = vectorConvert(parse.materials[j].attrib.Tf);
				attribute.Ke = vectorConvert(parse.materials[j].attrib.Ke);

				attribute.d = parse.materials[j].attrib.d;
				attribute.Ns = parse.materials[j].attrib.Ns;
				attribute.sharpness = parse.materials[j].attrib.sharpness;
				attribute.Ni = parse.materials[j].attrib.Ni;
				attribute.illum = parse.materials[j].attrib.illum;

				materials.push_back(attribute);
				//modelData.materials.push_back(attribute);
			}

			for (int j = 0; j < parse.indexCount; j++)
			{
				indices.push_back(parse.indices[j] + tempOffset);
			}

			for (int j = 0; j < parse.meshCount; j++)
			{
				MyBatch temp;
				if (!batches.empty())
				{
					// case 1: batches has 1 or more batches in it
					temp.indexCount = parse.batches[j].indexCount;
					temp.indexOffset = batches.back().indexOffset + batches.back().indexCount;
					temp.materialIndex = batches.back().materialIndex + 1;
					temp.modelName = uniqueModel[i];
				}
				else
				{
					// case 2: batches is empty
					temp.indexCount = parse.batches[j].indexCount;
					temp.indexOffset = 0;
					temp.materialIndex = 0;
					temp.modelName = uniqueModel[i];
				}
				batches.push_back(temp);
			}

		}

	}

	else
	{
		std::cout << "unable to open file" << std::endl;
	}

}

MyVertex Level_Data::vertexConvert(H2B::VERTEX _in)
{
	MyVertex temp;

	temp.pos.x = _in.pos.x;
	temp.pos.y = _in.pos.y;
	temp.pos.z = _in.pos.z;

	temp.uvw.x = _in.uvw.x;
	temp.uvw.y = _in.uvw.y;
	temp.uvw.z = _in.uvw.z;

	temp.nrm.x = _in.nrm.x;
	temp.nrm.y = _in.nrm.y;
	temp.nrm.z = _in.nrm.z;

	return temp;
}

glm::vec3 Level_Data::vectorConvert(H2B::VECTOR _in)
{
	glm::vec3 temp;

	temp.x = _in.x;
	temp.y = _in.y;
	temp.z = _in.z;

	return temp;
}

WorldMatrix Level_Data::ExtractMatrix(std::fstream &_file, std::string _line)
{
	WorldMatrix worldIn{};

	int index = 0;

	for (int i = 0; i < 4; i++)
	{
		_line.erase(0, 13);								// trim matrix to fit

		size_t check = _line.find_first_not_of(' ');

		if (check != 0)
			_line.erase(0, check);

		check = _line.find_last_of(')');
		_line.erase(check, _line.size() - 1);

		//if (i != 3)
		//	line.erase(31, 1);
		//else
		//	line.erase(31, 2);

		std::stringstream temp(_line);					// create a string stream to go through current line
		while (temp.good())
		{
			std::string result;
			getline(temp, result, ',');					// gets each number deliminated by comma
			check = result.find_first_not_of(' ');
			if (check != 0)
				result.erase(0, check);					// trims off excess whitesspace from number

			worldIn.data[index] = std::stof(result);	// set the number to out local temp
			index++;									// increment index
		}
		std::cout << _line << std::endl;
		if (i != 3)										// goes to the next line, not needed for last row of matrix
			std::getline(_file, _line);
	}

	return worldIn;
}

float Level_Data::ExtractLightFloat(std::fstream& _file, std::string _line)
{
	std::getline(_file, _line);
	std::cout << _line << std::endl;
	std::getline(_file, _line);
	std::cout << _line << std::endl;
	return std::stof(_line);
}

glm::vec3 Level_Data::ExtractLightVec(std::fstream &_file, std::string _line)
{
	float temp[3] = { 0.0f, 0.0f, 0.0f };

	std::getline(_file, _line);					// get and print context
	std::cout << _line << std::endl;

	for (int i = 0; i < 3; i++)
	{
		std::getline(_file, _line);
		std::cout << _line << std::endl;
		temp[i] = std::stof(_line);
	}

	return glm::vec3(temp[0], temp[1], temp[3]);
}

unsigned int Level_Data::getModelIndex(std::string _in)
{
	for (unsigned int i = 0; i < uniqueModelCount; i++)
	{
		if (_in == uniqueModel[i])
		{
			return i;
		}
	}
	return UINT32_MAX;
}

unsigned int Level_Data::getMaterialIndex(unsigned int _meshIndex)
{
	return batches[_meshIndex].materialIndex;
}

unsigned int Level_Data::getBatch(std::string _in)
{
	
	return 0;
}