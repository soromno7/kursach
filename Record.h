#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <windows.h>
#include <regex>

class Record
{
	std::string pName;
	std::string kbook;
	std::string date;
	std::string time;
	std::string nameOfBook;
	std::string author;
public:
	Record(std::string pName,std::string kbook, std::string date, std::string time, std::string nameOfBook,
		std::string author);
	Record();
	void print();
	void create();
	void setpName(std::string pName);
	void setkbook(std::string kbook);
	void setdate(std::string date);
	void settime(std::string time);
	void setnameOfBook(std::string nameOfBook);
	void setauthor(std::string author);
	std::string getpName();
	std::string getkbook();
	std::string getdate();
	std::string gettime();
	std::string getnameOfBook();
	std::string getauthor();
	friend std::ostream& operator<< (std::ostream& out, const Record& record);
	friend std::istream& operator>> (std::istream& in, Record& record);
};

