#include "Record.h"

Record::Record(std::string pName, std::string kbook, std::string date, std::string time, std::string nameOfBook,
	std::string author)
{
	this->pName = pName;
	this->kbook = kbook;
	this->date = date;
	this->time = time;
	this->nameOfBook = nameOfBook;
	this->author = author;
}

Record::Record() {
	this->pName ="unknown";
	this->kbook ="unknown";
	this->date ="unknown";
	this->time ="unknown";
	this->nameOfBook ="unknown";
	this->author ="unknown";
}

void Record::print() { //������� ��� ������ �� ����� ���������� �� �������
	std::cout << "�������� ��������-���������� : " <<pName << std::endl;
	std::cout << "  ���������� ������������ ���� : "<<kbook << std::endl;
	std::cout << "  ���� �������� : "<<date << std::endl;
	std::cout << "  ����� �������� : " <<time<< std::endl;
	std::cout << "  �������� ����� : "<<nameOfBook << std::endl;
	std::cout << "  ����� ����� : "<<author << std::endl;
	return;
}

void Record::create() { //������� ���������� ����� �������, ������������ ������ ��� ������ � ����������
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}");//� ������� ����������� ��������� �������������� ��������, ����� ������������ ���� ������ � ���������� �������
	std::regex timeRegex("\\d{2}-\\d{2}");
	char data[150];
	std::cout << "������� ������ �������� ��������-���������� " << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);  ///������������� ����������, �.�. �������� � ����������.
	pName = data;
	std::cout << "������� ����������� ������������ ����" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data); ///������������� ����������, �.�. �������� � ����������.
	kbook = data;
	do {
		std::cout << "������� ���� �������� (20��-��-��)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, dataRegex));
	date = data;
	do {
		std::cout << "������� ����� (��-��)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, timeRegex));
	time = data;
	std::cout << "������� �������� �����" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	nameOfBook = data;
	std::cout << "������� ������ �����" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	author = data;
}

void Record::setpName(std::string pName) {
	this->pName=pName;
}

void Record::setkbook(std::string date) { //����� ��� ���������� ���� ������������ ������ ������, ���������� �������� 
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}"); //� ������� ����������� ���������
	if (!std::regex_match(date, dataRegex)) {
		do {
			std::cout << "������� ���� �������� (20��-��-��)" << std::endl;
			std::getline(std::cin, date);
		} while (!std::regex_match(date, dataRegex));
	}
	this->date=date;
}

void Record::setdate(std::string kbook) {
	this->kbook = kbook;
}

void Record::settime(std::string time){
	std::regex timeRegex("\\d{2}-\\d{2}");
	if (!std::regex_match(time, timeRegex)) {
		do {
			std::cout << "������� ����� �������� (��-��)" << std::endl;
			std::getline(std::cin, time);
		} while (!std::regex_match(time, timeRegex));
	}
	this->time = time;
}

void Record::setnameOfBook(std::string nameOfBook){
	this->nameOfBook = nameOfBook;
}

void Record::setauthor(std::string author){
	this->author = author;
}


std::string Record::getpName() {
	std::string pName;
	pName = this->pName;
	return pName;
}

std::string Record::getkbook(){
	std::string kbook; 
	kbook = this->kbook;
	return kbook;
	}

std::string Record::getdate() {
	std::string date;
	date = this->date;
	return date;
}

std::string Record::gettime(){
	std::string time; 
	time = this->time;
	return time;
}

std::string Record::getnameOfBook(){
	std::string nameOfBook; 
	nameOfBook = this->nameOfBook;
	return nameOfBook;
}

std::string Record::getauthor(){
	std::string author; 
	author = this->author;
	return author;
}


std::ostream& operator<< (std::ostream& out, const Record& record) ////������������ ��� ������ � �������, ���������� �����, ������� ��������� � ����
{
	out << record.pName << std::endl;
	out << record.kbook << std::endl;
	out << record.date << std::endl;
	out << record.time << std::endl;
	out << record.nameOfBook << std::endl;
	out << record.author << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)  //������������ ��� ������ � �������, ������ �� ������ in ���������� � ������
{
	getline(in, record.pName);
	getline(in, record.kbook);
	getline(in, record.date);
	getline(in, record.time);
	getline(in, record.nameOfBook);
	getline(in, record.author);
	return in;
}
