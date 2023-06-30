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

Sound ResourceManager::GetSound(std::string path)
{
	std::cout << "GetSound called" << std::endl;
	if (sounds.contains(path))
	{
		std::cout << "existing sound sent" << std::endl;
		return sounds[path];
	}
	std::cout << "Loading new sound" << std::endl;
	Sound sound;
	sound = LoadSound(path.c_str());
	sounds[path] = sound;
	return sound;
}

void ResourceManager::Cleanup()
{
	std::map<std::string, Texture2D>::iterator text_it;
	for (text_it = textures.begin(); text_it != textures.end(); ++text_it) {
		std::cout << "unloading " << text_it->first << std::endl;
		UnloadTexture(text_it->second);
	}
	std::cout << "unloading font\n";
	UnloadFont(_font);
}

