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


std::string separateCommand(std::string command) {
	std::string repCommand = "";
	for (int i = 0; i < command.size(); ++i) {
		if (command[i] == ' ') {
			for (int k = 0; k < i; ++k) {
				repCommand += command[k];
			}
		}
	}
	return repCommand;
}

void menu() {
	system("cls");
	std::cout << "--- VIRTUAL CONSOLE AYOUB NABIL 2023 ---\n";
	std::cout << "|_                 C++                _|\n";
}

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
	
	if (!isInRepo) {std::cout << "| File not found !" << std::endl;}

	else if (isInRepo) {
		std::cout << "|" << std::endl;
		std::cout << "-------> READING FILE : " << fileName << std::endl << "|" << std::endl << "|__[READ][CONTENT] -> " << fileContent << std::endl;
	}

}

std::map<std::string, std::string> modifyFile(std::map<std::string, std::string> repositoryMap, std::string fileName) {
	std::string newContent;
	if (findFile(repositoryMap, fileName) == true) {
		std::cout << std::endl <<"-------> WRITING FILE : " << fileName << std::endl;
		std::cout << "|\n";
		std::cout << "|_[WRITE][FILE] -> ";
		getline(std::cin, newContent);
		repositoryMap[fileName] = newContent;
		std::cout << "|- [UPDATED] -| " << std::endl;
	}
	return repositoryMap;
}

std::map<std::string, std::string> deleteFile(std::map<std::string, std::string> repositoryMap, std::string fileName) {
	if (findFile(repositoryMap, fileName)) {
		repositoryMap.erase(fileName);
		std::cout << "\n-------> ERASE FILE\n";
		std::cout << "|" << std::endl << "| {" << fileName << "} It's successfully erased.\n|";
		std::cout << ">----<\n" << std::endl;
		return repositoryMap;
	}
	else {
		std::cout << "\n-------> ERROR \n|\n|_ [File Not Found] >-< \n";
		return repositoryMap;
	}
}

void consoleMain() {
	menu();
	std::string command;
	std::cout << "-> ";getline(std::cin, command);
}




int main(void)
{
	std::string command = separateCommand("cls test");
	std::cout << command.size();
}
