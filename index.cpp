#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

long long int vectorToInt(std::vector<int> &numbers) {
	long long res = 0;

	int vectorSize = numbers.size();

	int reversedIndex = vectorSize - 1;

	for (int i = 0; i < vectorSize; i++) {
		if (i == 0) {
			res += numbers[reversedIndex];
		} else {
			int n = numbers[reversedIndex];

			for (int j = 0; j < vectorSize - reversedIndex - 1; j++) {
				n *= 10;
			}

			res += n;
		}

		reversedIndex--;
	}

	// --

	std::string str;

	for (int n: numbers) {
		str += std::to_string(n);
	}

	return std::stoi(str);
}
