#include "Menu.h"

/// <summary>
/// Displays the menu in its entirety
/// </summary>
void Menu::PrintMenu() {
	PrintHeader();
	PrintOptions();

	//footer
	PrintDivider(TABLE_WIDTH);
	cout << "\n\n";
	
}

/// <summary>
/// Print a sequence of repeated characters
/// </summary>
/// <param name="numberOfCharacters">The number of characters to be printed out</param>
/// <param name="character">The character to print out. Default is '-' </param>
void Menu::PrintDivider(int numberOfCharacters, char character) {
	if (numberOfCharacters <= 0) {
		return;
	}

	for (int i = 0; i < numberOfCharacters; i++) {
		cout << character;
	}
}

/// <summary>
/// Output the header of the menu table
/// </summary>
void Menu::PrintHeader() {
	string menuHeader = "Main Menu";
	int BufferSize = (TABLE_WIDTH - menuHeader.length()) / 2;
	
	//top margin
	PrintDivider(TABLE_WIDTH, '=');
	cout << endl;

	//table title
	PrintDivider(BufferSize, '-');
	cout << menuHeader;
	PrintDivider(BufferSize, '-');
	cout << endl;
}

/// <summary>
/// Prints out each option for user input from the user i.e. type "quit" to quit.
/// </summary>
void Menu::PrintOptions() {
	cout << MENU_OPTION_1 << endl;
	cout << MENU_OPTION_2 << endl;
	cout << MENU_OPTION_3 << endl;
	cout << MENU_OPTION_4 << endl;
}