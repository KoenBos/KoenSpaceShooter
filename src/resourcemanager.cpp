#include <iostream>
#include <fstream>
#include <sstream>
#include "resourcemanager.h"

ResourceManager* ResourceManager::_instance = nullptr;

ResourceManager::ResourceManager() {

}

ResourceManager::~ResourceManager(){

}

ResourceManager* ResourceManager::Instance()
{
	if (ResourceManager::_instance == nullptr)
	{
		_instance = new ResourceManager();
	}
	return _instance;
}

Texture2D ResourceManager::GetTexture(std::string path)
{
	if (textures.contains(path))
	{
		return textures[path];
	}
	Texture2D texture;
	try
	{
		texture = LoadTexture(path.c_str());
		if (texture.id <= 0)
		{
			throw texture;
		}
	}
	catch (...)
	{
		texture = LoadTexture("assets/noimage.png");
	}
	textures[path] = texture;
	return texture;
}

void ResourceManager::Cleanup()
{
	std::map<std::string, Texture2D>::iterator text_it;
	for (text_it = textures.begin(); text_it != textures.end(); ++text_it) {
		UnloadTexture(text_it->second);
	}
	UnloadFont(_font);
}

