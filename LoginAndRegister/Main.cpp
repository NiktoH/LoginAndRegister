#include <iostream>
#include <fstream>
#include <string>

class Templates {
public:
	std::string username, password, age, us, pw, ag;
};

bool LoggedIn() {
	Templates templates;
	std::cout << "Enter ur username: ";
	std::cin >> templates.username;
	std::cout << "Enter password: ";
	std::cin >> templates.password;
	

	std::ifstream read("D:\\" + templates.username + ".txt");

	std::getline(read, templates.us);
	std::getline(read, templates.pw);
	std::getline(read, templates.age);

	if (templates.us == templates.username && templates.pw == templates.password) {
		return true;
		
	}
	else {
		return false;
	}

}


int main() {
	
	int n;

	std::cout << "1: Register" << std::endl << "2: Login" << std::endl;
	std::cin >> n;
	if (n == 1) {
		std::string username, password, age;

		std::cout << "select a username: ";
		std::cin >> username;
		std::cout << "Select a password: ";
		std::cin >> password;
		std::cout << "Select age: ";
		std::cin >> age;

		std::ofstream file;
		file.open("D:\\" + username + ".txt");
		file << username << std::endl << password << std::endl << age;
		file.close();
		

		main();

	}
	else if (n == 2) {
		bool status = LoggedIn();

		if (!status) {
			std::cout << "Login Fail!" << std::endl;
			system("PAUSE");
			return 0;
		}
		else {
			std::string age;
			std::cout << "U was logged!" <<std::endl <<  age << std::endl;
			system("PAUSE");
			return 1;
		}

	}
}