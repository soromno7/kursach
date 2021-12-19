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

void Record::print() { //Функция для вывода на экран информации об объекте
	std::cout << "Название компании-поставщика : " <<pName << std::endl;
	std::cout << "  Количество поставленных книг : "<<kbook << std::endl;
	std::cout << "  Дата поставки : "<<date << std::endl;
	std::cout << "  Время поставки : " <<time<< std::endl;
	std::cout << "  Название книги : "<<nameOfBook << std::endl;
	std::cout << "  Автор книги : "<<author << std::endl;
	return;
}

void Record::create() { //функция заполнения полей объекта, пользователь вводит все данные с клавиатуры
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}");//с помощью регулярного выражения осуществляется проверка, чтобы пользователь ввел данные в правильном формате
	std::regex timeRegex("\\d{2}-\\d{2}");
	char data[150];
	std::cout << "Введите полное название компании-поставщика " << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);  ///перекодировка необходима, т.к. работаем с киррилицей.
	pName = data;
	std::cout << "Введите колличество поставленных книг" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data); ///перекодировка необходима, т.к. работаем с киррилицей.
	kbook = data;
	do {
		std::cout << "Введите дату поставки (20ГГ-ММ-ДД)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, dataRegex));
	date = data;
	do {
		std::cout << "Введите время (ЧЧ-ММ)" << std::endl;
		std::cin.getline(data, 150);
		OemToCharA(data, data);
	} while (!std::regex_match(data, timeRegex));
	time = data;
	std::cout << "Введите название книги" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	nameOfBook = data;
	std::cout << "Введите автора книги" << std::endl;
	std::cin.getline(data, 150);
	OemToCharA(data, data);
	author = data;
}

void Record::setpName(std::string pName) {
	this->pName=pName;
}

void Record::setkbook(std::string date) { //Чтобы при перезаписи поля выдерживался нужный формат, проводится проверка 
	std::regex dataRegex("\\d{4}-\\d{2}-\\d{2}"); //с помощью регулярного выражения
	if (!std::regex_match(date, dataRegex)) {
		do {
			std::cout << "Введите дату поставки (20ГГ-ММ-ДД)" << std::endl;
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
			std::cout << "Введите время поставки (ЧЧ-ММ)" << std::endl;
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


std::ostream& operator<< (std::ostream& out, const Record& record) ////используется для работы с файлами, возвращает поток, который выводится в файл
{
	out << record.pName << std::endl;
	out << record.kbook << std::endl;
	out << record.date << std::endl;
	out << record.time << std::endl;
	out << record.nameOfBook << std::endl;
	out << record.author << std::endl;
	return out;
}

std::istream& operator>> (std::istream& in, Record& record)  //используется для работы с файлами, читает из потока in информацию в объект
{
	getline(in, record.pName);
	getline(in, record.kbook);
	getline(in, record.date);
	getline(in, record.time);
	getline(in, record.nameOfBook);
	getline(in, record.author);
	return in;
}
