#include <iostream>
#include <clocale>
#include "IUser.h"
#include "Admin.h"
#include "Viewer.h"
#include "User.h"
#include "sha256.h" 
#include "Authorization.h";

using namespace std;

int menu(void);


int main() {
	system("color F0");
	setlocale(LC_CTYPE, "rus");
	IUser* user=NULL;  
	bool stillWork;
	int choice = 0, choiceUser=0;
	string choosenFile;
	if (!Authorization::isUserExist(Admin::baseOfUsersFile)) { 
		cout << "Необходимо создать администратора" << endl;
		if (Authorization::createAccount(Admin::baseOfUsersFile) == false) {
			cout << endl << "Не удалось создать администратора";
			return 0;
		}
	}
	while (1) {
		while (1) {  
			stillWork = true;
			cout <<endl<< "Выберите режим работы: " << endl
				<< "1 - администратор" << endl
				<< "2 - библиотекарь" << endl
				<< "3 - создать нового библиотекаря" << endl
				<< "0 - выход" << endl;
			cin >> choice;
			if (std::cin.fail())
			{
				std::cin.clear(); 
				std::cin.ignore(32767, '\n'); 
				std::cout << "Неправильно введены данные.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); }
			if (choice > 3 || choice < 0) cout << "Неправильно введен номер команды" << endl;
			else break;
		}
		switch (choice) {
		case 1: 
			if (Authorization::singIn(Admin::baseOfUsersFile)) {
				user = new Admin;
			}
			else continue;
			break;
		case 2: 
			if (!Authorization::isUserExist(User::baseOfUsersFile)) {
				cout << "Пользователей с доступом не существует" << endl;
				continue;
			}
			if (Authorization::singIn(User::baseOfUsersFile)) {
				user = new User;
			}
			else continue;
			break;
		case 3:
			cout <<endl<< "Для добавления пользователя необходимо авторизоваться как администратор";
			if (!Authorization::singIn(Admin::baseOfUsersFile)) {
				cout << endl << "Не удалось авторизоваться" << endl;
				continue;
			}
			cout << endl << "1 - Добавить администратора "
				<< endl << "2 - Добавить библиотекаря "<<endl;
			cin >> choiceUser;
			if (std::cin.fail()) 
			{
				std::cin.clear();  
				std::cin.ignore(32767, '\n'); 
				std::cout << "Неправильно введены данные.\n";
				continue;
			}
			else { std::cin.ignore(32767, '\n'); }
			if (choiceUser > 2 || choiceUser < 1) {
				std::cout << std::endl << "Данный библиотекарь отсутствует";
				continue;
			}
			if (choiceUser == 1) {
				choosenFile = Admin::baseOfUsersFile;
			}
			if (choiceUser == 2) {
				choosenFile = User::baseOfUsersFile;
			}
			if (Authorization::createAccount(choosenFile.c_str()) == false) {
				cout << endl << "Не удалось создать библиотекаря";
				continue;
			}
			continue;
			break;
		case 0: if (user != NULL) {
			delete user;
			user = NULL;
		}
			exit(0);
			return 0;
			break;
		}  
		while (stillWork) {
			switch (menu()) {
			case 1: user->viewRecords();
				break;
			case 2:	user->addRecord();
				break;
			case 3:user->redactRecord();
				break;
			case 4:	user->deleteRecord();
				break;
			case 5:user->searchRecord();
				break;
			case 6: user->sortRecords();
				break;
			case 7:	user->filterRecords();
				break;
			case 8: stillWork = false;
				if (user != NULL) {
					delete user;
					user = NULL;
				}
				break;
			default: cout << endl << "Выбран неправильный номер действия";
				break;
			}
		}
	}
	return 0;
}

int menu(void) {
	int choice = 0;
	cout <<endl<< "Выберите действие: " << endl
		<< "1. Просмотр" << endl
		<< "2. Добавление" << endl
		<< "3. Редактирование" << endl
		<< "4. Удаление" << endl
		<< "5. Поиск" << endl
		<< "6. Сортировка" << endl
		<< "7. Фильтр" << endl
		<< "8. Выход" << endl;
	cin >> choice;
	if (std::cin.fail()) 
	{
		std::cin.clear();
		std::cin.ignore(32767, '\n'); 
		return 0;
	}
	else { std::cin.ignore(32767, '\n'); } 
	return choice;
}