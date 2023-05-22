#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <unordered_map>
#include <string>
#include "raylib.h"
#include "resourcemanager.h"

// Singleton ResourceManager
class ResourceManager
{
private:
	std::unordered_map<std::string, Texture2D> textures;
	static ResourceManager instance;

	// Private constructor to prevent instantiation
	ResourceManager() {}

public:
	static ResourceManager& Instance()
	{
		return instance;
	}

	Texture2D GetTexture(const std::string& path)
	{
		if (textures.contains(path))
		{
			// Texture already loaded
			return textures[path];
		}

		// Load the texture from disk
		Texture2D texture = LoadTexture(path.c_str());
		textures[path] = texture;
		return texture;
	}
};

// Define the static member outside the class definition
ResourceManager ResourceManager::instance;

#endif // RESOURCEMANAGER_H
