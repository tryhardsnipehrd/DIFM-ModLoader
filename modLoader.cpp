#include <urlmon.h>
#include <iostream>
#include <string>
#include <cstring>

bool isNewest = true;
HRESULT fileDone;

int main(int argc, char * argv[])
{
	// Define the strings needed to grab the file by version
	std::string version;
	std::string version1 = "https://github.com/LukeSaward1/DiFM-Speedrun-Mod/releases/download/v";
	std::string version3 = "/Assembly-CSharp.dll";

	// Grab the filepath, and check if it equals newest or latest
	std::cout << "Please enter the version you want. e.g. 1.0.1\n";
	std::getline(std::cin, version);
	if (version != "newest" && version != "latest") {isNewest = false;}
	
	// Slap those fuckers together
	version1.append(version);
	version1.append(version3);
	std::string versionB = version1;
	// Weird things idk how they work, but it does
	char * versionC = const_cast<char*>(versionB.c_str());
	
	// If the newest file is wanted, grab from the branch instead of the repository
	if (isNewest) {
		std::cout << "Getting newest version from the repository\n";
		fileDone = URLDownloadToFile(
			NULL,
			"https://raw.githubusercontent.com/LukeSaward1/DiFM-Speedrun-Mod/main/Assembly-CSharp.dll",
			"./Do It For Me V1.0.1_Data/Managed/Assembly-Csharp.dll",
			0,
			NULL
		);
	} else {
		// If they want a version instead, get it then
		std::cout << "Getting version " << version << " from the repository\n";
		fileDone = URLDownloadToFile(
			NULL,
			versionC,
			"./Do It For Me V1.0.1_Data/Managed/Assembly-Csharp.dll",
			0,
			NULL
		);
	}
	
	
	
	if (fileDone == S_OK){
		return 0;
	} else {
		std::cout << "Something went wrong\n";
		return 0;
	}
}