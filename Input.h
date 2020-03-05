#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string_view>
#include <vector>

int getUserInput(std::string_view message);
int getUserVectorSize(std::string_view message);
std::vector<int> createUserPromptedVector(int vector_size);

#endif // !INPUT_H


