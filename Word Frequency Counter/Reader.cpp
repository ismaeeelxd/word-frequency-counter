#include "Reader.h"
#include <iostream>
#include <string>
#include "Trie.h"
#include "HistoryOrganizer.h"
#include "TextProcessor.h"
using namespace std;

Reader::Reader() {
	//this->paragraphPath = "default.txt";
}
Reader::Reader(std::string& paragraphPath){
	paragraphPath += ".txt";
	this->paragraphPath = paragraphPath;
}

void Reader::uplaod() {
	char in = 'c';
	HistoryOrganizer history;
	TextProcessor txt;
	do {
		in = 'c';
		string path; cin >> path;
		//path += ".txt";
		Reader file(path);
		string paragraph = file.read();
		txt.WordSplitter(paragraph);
		history.settervec(path,paragraph,txt.words);
		cout << "do you want to read file\n";
		cin >> in;
		history.counter++;

	} while (in == 'y');
}

std::string Reader::read() {
	paragraphFile.open(paragraphPath, std::ios::in);
	try {
		if (paragraphFile.is_open()) {
			while (std::getline(paragraphFile, line))
				paragraph += line + "\n";
		}	
		else 
			throw std::runtime_error("Error: File is not open");
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
//	cout << paragraph;
	return paragraph;
}

void Reader::write(std::string& paragraph) {
	paragraphFile.open(paragraphPath, std::ios::out);
	try {
		for (int i = 0; !paragraph.empty(); ++i)
			paragraphFile << paragraph[i];
	}
	catch (const std::exception& e) {
		std::cout << e.what();
	}
	paragraphFile.close();
}
Reader::~Reader() {
	if (paragraphFile.is_open())
		paragraphFile.close();
}

