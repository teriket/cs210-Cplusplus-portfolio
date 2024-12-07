#ifndef GROCERY_APP_WINDOW_
#define GROCERY_APP_WINDOW_

#include <string>
#include <iostream>
#include <memory>
#include "Menu.h"
#include "Record.h"

using namespace std;
class Window
{
public:
	Window();
	void Display();

private:
	void ParseInput(string& input);

	unique_ptr<Menu> menu;
	unique_ptr<Record> records;
};

#endif // !GROCERY_APP_WINDOW_
