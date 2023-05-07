#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>

#define Log(x) std::cout<< x <<std::endl








int main() {
	//works for 9119 // 765
	int num = 9119;
	std::vector<int> vec;
	std::vector<int> digit_vector;
	std::vector<int> digit_vector2;
	//std::string str;
	int digits = log10(num);
	int aux{};
	int zero_count{};

	for (int i = pow(10, digits); digits >= 0; i = i / 10) {
		vec.push_back(num / i);
		num = num % i;
		digits--;
	}

	for (int i = 0; i < vec.size(); i++) {
		vec.at(i) = pow(vec.at(i), 2);
	}

	if (vec.size() == 1) {
		num = vec.at(0);
		Log(num);
	}
	else {

		for (int i = 0; i < vec.size() - 1; i++) {
			digit_vector.push_back(log10(vec.at(i)));
			digit_vector2.push_back(log10(vec.at(i)));
		}

		int j = digit_vector.size() - 1;


		//first digit
		if (j == digit_vector.size() - 1) {
			if (log10(vec.at(vec.size() - 1)) == 0) {
				digit_vector2.at(j) = 10;
				zero_count = 1;
			}
			else {
				digit_vector2.at(j) = 100;
				zero_count = 2;
			}
			j--;
		}
		if (j == 0) {
			zero_count++;
			digit_vector2.at(j) = pow(10, zero_count);
		}
		else {
			//rest digits
			do {

				if (digit_vector.at(j) == 0) {
					zero_count++;
					digit_vector2.at(j) = pow(10, zero_count);
				}

				if (digit_vector.at(j) == 1) {
					zero_count += 2;
					digit_vector2.at(j) = pow(10, zero_count);
				}

				j--;
			} while (j != 0);
		}
		//last digit
		zero_count++;
		digit_vector2.at(j) = pow(10, zero_count);

		num = vec.at(vec.size() - 1);
		int i = vec.size() - 2;
		do {
			digit_vector2.at(i) = digit_vector2.at(i) * vec.at(i);
			num += digit_vector2.at(i);
			i--;
		} while (i != -1);


		Log(num);
	}


	return 0;
}