#include "User.h"

const char* User::baseOfUsersFile = "Librarians.txt";

using namespace std;


vector<Record> User::readVectorOfRecords() {
	Admin admin;
	return admin.readVectorOfRecords();
}

void User::viewRecords() {
	Admin admin;
	admin.viewRecords();
}

void User::addRecord() {
	Admin admin;
	admin.addRecord();
}

void User::redactRecord() {
	cout << endl << "Нет доступа к данной операции в режиме библиотекаря";
}
void User::deleteRecord() {
	cout << endl << "Нет доступа к данной операции в режиме библиотекаря";
}
void User::searchRecord() {
	Admin admin;
	admin.searchRecord();
}
void User::sortRecords() {
	cout << endl << "Нет доступа к данной операции в режиме библиотекаря";
}
void User::filterRecords() {
	Admin admin;
	admin.filterRecords();
}