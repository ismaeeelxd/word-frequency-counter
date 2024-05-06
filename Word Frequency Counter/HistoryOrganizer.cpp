#include "HistoryOrganizer.h"


map<string,int> HistoryOrganizer::general;
vector<Trie>HistoryOrganizer::DataOfParagraph;

HistoryOrganizer::HistoryOrganizer() {
	this->now = time(0);
	this->localtm = localtime(&now);

}

int HistoryOrganizer::counter = 0;

bool HistoryOrganizer::CheckFile() {
	std::ifstream file(this->directoryPath + "/" + asctime(this->localtm));
	return file.good();
}

void HistoryOrganizer::CreateFile() {
	std::ifstream file(this->directoryPath);
	file.open("test.txt");
}

 void HistoryOrganizer::setmap(string s) {
	general[s]++;
}

 void HistoryOrganizer::settervec(string title, string paragraph, map<string, int>freq) {
	/* DataOfParagraph[counter].title = title;
	 DataOfParagraph[counter].title = paragraph;
	 DataOfParagraph[counter].freq = freq;*/
	 DataOfParagraph.push_back({title, paragraph, freq});
	

}

void HistoryOrganizer::print() {
	
	for (auto it : DataOfParagraph) {
		cout << it.title << endl << endl;
		cout << it.paragraph << endl;
		for (auto x : it.freq) {
			cout << x.first << " " << x.second << endl;

		}
		cout <<"\n---------------------------------------------------\n";
	}
	cout << "------------------------general--------------------\n";
	for (auto it : general) {
		cout << it.first << " " << it.second << endl;
	}
}


