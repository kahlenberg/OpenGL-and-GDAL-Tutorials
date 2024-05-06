#include <AssetManager.h>
#include <filesystem>
#include <iostream>

string AssetManager::APP_PATH;

// Set the app path for the asset manager
void AssetManager::SetAppPath(string path)
{
	std::filesystem::path p = std::filesystem::current_path();
	std::cout << "path set: " << p << std::endl;
	APP_PATH = p.string();
};

// Get the main app path
string AssetManager::GetAppPath()
{
	return APP_PATH + "/";
}