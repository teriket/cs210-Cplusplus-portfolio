//@author Tanner Hunt
//@date 12/7/2024

#include <iostream>
#include "Window.h"
#include <memory>

int main()
{
    unique_ptr<Window> window = std::make_unique<Window>();
    window->Display();
}

