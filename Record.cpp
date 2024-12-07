#include "Record.h"

/// <summary>
/// Read a file of bought items and write a backup every time this object is created.
/// </summary>
Record::Record() {
	this->longestItemBoughtNameLength = 0;
	this->Read();
	this->Backup();
}

/// <summary>
/// Searches the record of bought items for a specific item
/// </summary>
/// <param name="item">The item to search for</param>
/// <returns> The frequency a specific item was bought</returns>
int Record::Get(string &item) {
	if (KeyExists(item)) {
		return itemsBought[item];
	}
	else {
		throw runtime_error("Could not find this item in the list of bought items.");
	}
}

/// <summary>
/// Prints out a list of items bought and a bar graph of the number of times they were bought
/// </summary>
void Record::PrintHistogram() {
	for (const auto& boughtItem : itemsBought) {
		int barLength = boughtItem.second;
		//Print  the food name, justified to the right
		cout << setw(longestItemBoughtNameLength) << right << boughtItem.first << " ";
		PrintBar(barLength);
	}
}

/// <summary>
/// Prints out a list of bought items and the number of times they were bought
/// </summary>
void Record::PrintFrequencies() {
	for (const auto& boughtItem : itemsBought) {
		//print the foods justified to the right
		cout << setw(longestItemBoughtNameLength) << right << boughtItem.first << " : " << boughtItem.second << endl;
	}
}

/// <summary>
/// Adds an item bought to the itemsBought dictionary, or increments the number of times that item was bought by 1.
/// Also updates the size of the longestItemBoughtNameLength.
/// </summary>
/// <param name="key"></param>
void Record::Add(string& key) {
	//Add the food to the frequency map
	if (KeyExists(key)) {
		itemsBought[key] = itemsBought[key] + 1;
	}
	else {
		itemsBought.insert({ key, 1 });
	}

	//Update the length of the longest food name
	if (key.length() > longestItemBoughtNameLength) {
		this->longestItemBoughtNameLength = key.length();
	}
}

/// <summary>
/// Tries to open a file of groceries bought, then add the frequency items are bought to the itemsBought unordered_map.
/// </summary>
void Record::Read() {
	if (OpenInputFile()) {
		AddAllBoughtItemsToDict();
		inputFile.close();
	}
}

/// <summary>
/// Writes the frequencies from the input file to a backup file
/// </summary>
void Record::Backup() {
	outputFile.open(OUTPUT_FILE_PATH);

	//Abort this method if the file fails to open
	if (!outputFile.is_open()) {
		cout << "error in opening the output file";
		return;
	}

	//Write the frequencies of all bought items to the backup file
	for (const auto& boughtItem : itemsBought) {
		outputFile << boughtItem.first << " " << boughtItem.second << endl;
	}

	outputFile.close();
}

/// <summary>
/// Checks to see if an item is in the list of purchased items
/// </summary>
/// <param name="key">The name of the food item to look for</param>
/// <returns>true if the food item is in the list of purchased items.</returns>
bool Record::KeyExists(string& key) {
	if (itemsBought.find(key) != itemsBought.end()) {
		return true;
	}
	else return false;
}

/// <summary>
/// Tries to open a file of groceries bought.
/// </summary>
/// <returns>True if the file was opened successfully, false otherwise</returns>
bool Record::OpenInputFile() {
	inputFile.open(INPUT_FILE_PATH);

	if (!inputFile.is_open()) {
		cout << "Error in opening the input file" << endl;
		return false;
	}
	return true;
}

/// <summary>
/// Load groceries from a file to memory in the unordered_map boughtItems
/// </summary>
void Record::AddAllBoughtItemsToDict() {
	string boughtItem;
	while (!inputFile.eof())
	{
		inputFile >> boughtItem;
		Add(boughtItem);
	}
}

/// <summary>
/// Prints a repeated sequence of characters for a histogram bar
/// </summary>
/// <param name="length"></param>
void Record::PrintBar(int length) {
	for (int i = 0; i < length; i++) {
		cout << '#';
	}
	cout << endl;
}
