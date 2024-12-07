#ifndef GROCERY_APP_RECORD_H
#define GROCERY_APP_RECORD_H

#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
class Record
{
public:
	Record();
	int Get(string &item);
	void PrintHistogram();
	void PrintFrequencies();

private:
	void Add(string& key);
	void Read();
	void Backup();
	bool KeyExists(string& key);
	bool OpenInputFile();
	void AddAllBoughtItemsToDict();
	void PrintBar(int length);

	unordered_map<string, int> itemsBought;
	int longestItemBoughtNameLength;
	const string INPUT_FILE_PATH = "input.dat";
	const string OUTPUT_FILE_PATH = "frequency.dat";
	ifstream inputFile;
	ofstream outputFile;
};
#endif

