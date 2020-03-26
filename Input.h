#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <string_view>
#include <vector>

inline constexpr auto USER_DATA_SIZE_MAX = 10;

/**
 * Returns user prompted number with std::cin extractions and clearance
 * if prompted with invalid data asks for another try
 *
 * @param message - if NaN - prints nothing, if given - a user greeting with expected values to be given
 * @returns some user generated number
 */
int getUserInput(const std::string_view &message = "");

/**
 * Returns user prompted number = data size for data generator
 * prompted number must be >= 1
 * if prompted with invalid data asks for another try
 * 
 * @param message - if NaN - prints nothing, if given - a user greeting with expected values to be given
 * @returns user given size for the data to be generated
 */
int getUserDataSize(const std::string_view &message = "");

/**
 * Gets user elements range for testing the algorithms
 * input must be greater than MIN_ELEMENTS defined in Test.h
 * if prompted with invalid data asks for another try
 *
 * @param message - if NaN - prints nothing, if given - a user greeting with expected values to be given
 * @returns - max element generation range for generating the data
 */
int getUserMaxElementsRange(const std::string_view &message = "");

/**
 * Expect user boolean expression 0 or 1 for acceptance or dissagreement
 * input must be either 1 for true or 0 for false
 * if prompted with invalid data asks for another try
 *
 * @param message - if NaN - prints nothing, if given - a user greeting with expected values to be given
 * @returns true if user prompted 1, 0 otherwise
 */
bool askUser(const std::string_view& message = "");

#endif


