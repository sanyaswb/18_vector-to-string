#include "test.h"
#include "../index.h"
#include "termcolor.hpp"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string boolString(bool value) {
	return value ? "true" : "false";
}

struct Option {
		long long int toBe;
		std::vector<int> numbers;
};

Option options[] = {
		{
				12345,
				{1, 2, 3, 4, 5}
		},
		{
				6162512,
				{6, 1, 6, 2, 5, 1, 2}
		},
		{
				5639129,
				{5, 6, 3, 9, 1, 2, 9}
		},
		{
				8215453,
				{8, 2, 1, 5, 4, 5, 3}
		},
		{
				752,
				{7, 5, 2}
		},
		{
				247812,
				{2, 4, 7, 8, 1, 2}
		}
};

void printGreen(const string& test, const string& result) {
	cout << termcolor::green << "TEST " << test << " PASSED! RESULT: " << result << "" << endl;
}

void printRed(const string& test, const string& expected, const string& result) {
	cout << termcolor::red << "TEST " << test << " FAILED! EXPECTED: " << expected << " INSTEAD OF " << result << "!" << endl;
}

void test() {
	cout << endl;

	int optionsLength = sizeof(options) / sizeof(options[0]);

	for (int i = 0; i < optionsLength; i++) {
		Option option = options[i];

		long long result = vectorToInt(option.numbers);

		string testStr = "{";

		for (int j = 0; j < option.numbers.size(); j++) {
			if (j < option.numbers.size() - 1) {
				testStr += to_string(option.numbers[j]) + ", ";
			} else {
				testStr += to_string(option.numbers[j]) += '}';
			}
		}

		if (result == option.toBe) {
			printGreen(testStr, to_string(result));
		} else {
			printRed(testStr, to_string(option.toBe), to_string(result));
		}

		cout << endl;
	}
}