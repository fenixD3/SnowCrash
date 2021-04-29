#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <numeric>

int main(int ac, char **av)
{
	std::ifstream token(av[1]);
	std::string hashed;
	token >> hashed;
	std::vector<char> indexes(hashed.size());
	std::iota(indexes.begin(), indexes.end(), 0);
	std::transform(hashed.begin(), hashed.end(), indexes.cbegin(), hashed.begin(), std::minus<>{});
	std::cout << hashed << std::endl;
	return 0;
}
