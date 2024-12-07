#ifndef GROCERY_APP_MENU_H
#define GROCERY_APP_MENU_H

#include <string>
#include <iostream>

using namespace std;
class Menu
{
public:
	void PrintMenu();
private:
	const string MENU_OPTION_1 = "Type the name of a food to find its frequency";
	const string MENU_OPTION_2 = "Type \'amounts\' to show the amount of each foods purchased";
	const string MENU_OPTION_3 = "Type \'histogram\' to display a histogram of the foods purchased";
	const string MENU_OPTION_4 = "Type \'quit\' to exit the program";
	const int TABLE_WIDTH = MENU_OPTION_3.length() + 1;

	void PrintHeader();
	void PrintOptions();
	void PrintDivider(int numberOfChars, char character = '-');
	
};
#endif