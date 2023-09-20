#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <Windows.h>

class Admin {
public:
	std::string userName = "ADMIN";
private:
	std::string role = "admin";
};
class User {
public:
	std::string userName = "DEFAULT-USER";
private:
	std::string role = "User";
};

bool verifyRole(std::string role) {
	if (role == "Admin" || role == "admin" || role == "ADMIN") { return true; }
	else { return false; }
}

std::map<std::string, std::string> createDefaultFile(std::vector<std::string> repositoryName, std::string extention) {
	std::map<std::string, std::string> repositoryMap;
	for (int i = 0; i < repositoryName.size(); ++i) {
		repositoryMap[repositoryName[i] + '.' + extention] = "Default Content :-)";
	}
	return repositoryMap;
}

void coutRepository(std::map<std::string, std::string> repositoryMap) {
	std::cout << "-------> Repository" << std::endl << "|" << std::endl;
	for (const auto& pairs : repositoryMap) {
		std::cout << "|__[FILE] -> " << pairs.first << std::endl;
	}
}

std::map<std::string, std::string> createFile(std::map<std::string, std::string> repository, std::string fileName, std::string extention, std::string content) {
	repository[fileName + '.' + extention] = content;
	return repository;
}

bool p_findFile(std::map<std::string, std::string> repository, std::string fileName , std::string* ptr_fileContent) {
	for (const auto& pairs : repository) {
		if (pairs.first == fileName) {
			*ptr_fileContent = pairs.second;
			return true;
		}
	}
	return false;
}

bool findFile(std::map<std::string, std::string> repository, std::string fileName) {
	for (const auto& pairs : repository) {
		if (pairs.first == fileName) {
			return true;
		}
	}
	return false;
}

void readFile(std::map<std::string, std::string> repositoryMap, std::string fileName) {
	bool isInRepo = false;

	//cree un pointeur vers la valeur de fileContent
	std::string fileContent = "Empty";
	std::string* ptr_fileContent = &fileContent;

	isInRepo = p_findFile(repositoryMap, fileName, ptr_fileContent);
	
	if (!findFile) {std::cout << "File not found !" << std::endl;}

	else if (findFile) { 
		std::cout << "|" << std::endl;
		std::cout << "-------> READING FILE : " << fileName << std::endl << "|" << std::endl << "|__[READ][CONTENT] -> " << fileContent << std::endl;
	}

}

std::map<std::string, std::string> modifyFile(std::map<std::string, std::string> repositoryMap, std::string fileName) {
	std::string newContent;
	if (findFile(repositoryMap, fileName) == true) {
		std::cout << std::endl <<"-------> WRITING FILE : " << fileName << std::endl;
		std::cout << "|";
		std::cout << "|_[WRITE][FILE] -> ";
		getline(std::cin, newContent);
		repositoryMap[fileName] = newContent;
		std::cout << "|- [UPDATED] -| " << std::endl;
	}
	return repositoryMap;
}


int main(void)
{
	std::map<std::string, std::string> Dir = createDefaultFile({ "Premier Fichier" , "Deuxieme Fichier" , "Troisieme Fichier" }, "txt");
	Dir = createFile(Dir, "test Nouveau fichier", "exe", "Salut Je suis le contenue !");
	coutRepository(Dir);
	readFile(Dir, "test Nouveau fichier.exe");
	Dir = modifyFile(Dir, "test Nouveau fichier.exe");
	readFile(Dir, "test Nouveau fichier.exe");
}
