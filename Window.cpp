#include "Window.h"

/// <summary>
/// The environment other objects live in
/// </summary>
Window::Window() {
	menu = make_unique<Menu>();
	records = make_unique<Record>();
}

/// <summary>
/// The main loop for the environment.  Repeatedly prints the menu, gets the user input, then parses user input
/// </summary>
void Window::Display() {
	string input = "";

	while (input != "quit") {
		menu->PrintMenu();
		getline(cin, input);
		this->ParseInput(input);
	}
}

/// <summary>
/// Calls the appropriate function based on user input
/// </summary>
/// <param name="input"></param>
void Window::ParseInput(string& input) {
	//Print the frequency items were bought
	if (input == "amounts") {
		records->PrintFrequencies();
	}

	//print the histogram of frequencies items were bought
	else if (input == "histogram") {
		records->PrintHistogram();
	}

	//exit the program
	else if (input == "quit") {
		return;
	}

	//Print the frequency a single item was bought if it exists in the list of bought items
	else {
		try {
			cout << input << ": " << records->Get(input) << endl;
		}
		catch (exception exc) {
			cout << exc.what() << endl;
		}
	}
}