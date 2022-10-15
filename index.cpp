#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

long long int vectorToInt(std::vector<int> &numbers) {
	std::string result = "";

	for (int i = 0; i < numbers.size(); ++i) {
		result += std::to_string(numbers[i]);
	}

	return std::stoi(result);
}
