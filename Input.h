#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string_view>
#include <vector>

int getUserInput(std::string_view message = "");
int getUserDataSize(std::string_view message = "");
int getUserMaxElementsRange(std::string_view message = "");
bool askUser(const std::string_view& message = "");

#endif


