#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

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
	bool temp = false;
	std::string repCommand = "";
	for (int i = 0; i < command.size(); ++i) {
		if (command[i] == ' ') {
			for (int k = 0; k < i; ++k) {
				repCommand += command[k];
				temp = true;
			}
		}
		if (i == command.size() - 1 && temp == false) {
			return command;
		}
	}
	return repCommand;
}

std::string separateParam(std::string command) {
	std::string repCommand = "";
	for (int i = 0; i < command.size(); ++i) {
		if (command[i] == ' ') {
			for (int k = i + 1; k < command.size(); ++k) {
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

bool p_findFile(std::map<std::string, std::string> repository, std::string fileName, std::string* ptr_fileContent) {
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

	if (!isInRepo) { std::cout << "| File not found !" << std::endl; }

	else if (isInRepo) {
		std::cout << "|" << std::endl;
		std::cout << "-------> READING FILE : " << fileName << std::endl << "|" << std::endl << "|__[READ][CONTENT] -> " << fileContent << std::endl;
	}

}

std::map<std::string, std::string> modifyFile(std::map<std::string, std::string> repositoryMap, std::string fileName) {
	std::string newContent;
	if (findFile(repositoryMap, fileName) == true) {
		std::cout << std::endl << "-------> WRITING FILE : " << fileName << std::endl;
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

std::map<int, std::vector<std::string>> createRepository(std::string repoName, std::map<std::string, std::string> content) {
	std::map<int, std::vector<std::string>> repoFile;
	int index = 1;
	for (const auto& pairs : content) {
		repoFile[index] = { pairs.first , pairs.second };
		index += 1;
	}
	return repoFile;
}

void coutRepositoryFile(std::map<int, std::vector<std::string>> repoFile, std::string repoName) {
	std::cout << "| [REPO FILE]\n|\n";
	std::cout << repoName << " -  |\n";
	for (const auto& pairs : repoFile) {
		std::cout << "|_[NAME] -> " << pairs.second[0] << std::endl;
		std::cout << "|          ^^^^^^^^^^^^^^^" << std::endl;
		std::cout << "|          |   READING   |" << std::endl;
		std::cout << "|_________>|_____________| CONTENT -> " << pairs.second[1] << std::endl;
	}
}


void consoleMain(std::string UserName, std::string Role) {
	std::map<std::string, std::string> repositoryT = createDefaultFile({ "System" }, "atror");
	std::map<int, std::vector<std::string>> repoFileP = createRepository("System", repositoryT);
	menu();

	while (true) {
		//commandes basiques
		std::map<int, std::vector<std::string>> repoFileP = createRepository("System", repositoryT);
		std::string command;
		std::cout << "-> ";getline(std::cin, command);
		std::string argv1 = separateCommand(command);
		std::string argv = separateParam(command);
		if (argv1 == "cls") { system("cls"); }
		if (argv1 == "menu") { menu(); }
		if (argv1 == "repo") {
			std::map<int, std::vector<std::string>> repoFileP = createRepository("System", repositoryT);
			coutRepositoryFile(repoFileP, "System");
		}
		if (argv1 == "crepo") {
			std::map<int, std::vector<std::string>> repoFileP = createRepository(argv, repositoryT);
		}
		if (argv1 == "cdf") {
			std::string extention;
			std::cout << "| Extention -> ";getline(std::cin, extention);
			repositoryT = createDefaultFile({ argv , argv }, extention);
		}
		if (argv1 == "ls") { coutRepository(repositoryT); };
		if (argv1 == "create") {
			std::string extention;
			std::string content;
			std::cout << "| Extention -> ";getline(std::cin, extention);
			std::cout << "| Content -> ";getline(std::cin, content);std::cout << std::endl;
			repositoryT = createFile(repositoryT, argv, extention, content);
		};


		//commandes admin
		if (argv1 == "read") {
			if (verifyRole(Role)) { readFile(repositoryT, argv); }
			else { std::cout << "\n| you don't have the roles of reading, writing and erasing\n"; }
		}
		if (argv1 == "del") {
			if (verifyRole(Role)) { repositoryT = deleteFile(repositoryT, argv); }
			else { std::cout << "\n| you don't have the roles of reading, writing and erasing\n"; }
		}
		if (argv1 == "modify") {
			if (verifyRole(Role)) { repositoryT = modifyFile(repositoryT, argv); }
			else { std::cout << "\n| you don't have the roles of reading, writing and erasing\n"; }
		}

	}


}




int main(void)
{
	consoleMain("Ayoub", "Admin");
}
