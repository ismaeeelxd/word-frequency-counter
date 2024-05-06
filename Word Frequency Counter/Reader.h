#pragma once
#ifndef READER_H
#define READER_H

#include"HistoryOrganizer.h";
#include <fstream>
#include <string>
#include <iostream>
class Reader
{
	std::string filename;
	std::fstream paragraphFile;
	std::string paragraphPath;
	std::string line;
	std::string paragraph;
	//HistoryOrganizer history;

public:
	Reader();
	Reader(std::string&);
	std::string read();
	void write(std::string&);
	void uplaod();
	~Reader();

};
#endif

