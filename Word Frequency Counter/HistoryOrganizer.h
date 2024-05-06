#pragma once
#ifndef HISTORYORGANIZER_H
#define HISTORYORGANIZER_H
#include "Reader.h"
#include <stack>
#include <vector>
#include"Trie.h"
#include <string>
#include <chrono>
#include <ctime>
#include<iostream>
using namespace std;
#pragma warning(disable : 4996)
class HistoryOrganizer
{
	
	static vector<Trie> DataOfParagraph;
	//Trie DataOfParagraph[50];
	std::stack<std::string> history;
	const std::string directoryPath = "word_freq/Word Frequency Counter/Files";
	std::string fileName;
	std::time_t now;
	std::tm* localtm;
	//std::fstream newFile;

	/*
		
	*/
public:
	static int counter;
	static map<string, int> general;
	HistoryOrganizer();
	static void setmap(string s);
	void settervec(string title, string paragraph,map<string,int> freq);
	bool CheckFile();
	void CreateFile();
	void SaveFile();
	void print();



};
#endif
