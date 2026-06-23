#include <Windows.h>

#include <iostream>
#include <sstream>
#include <fstream>

void OutputOrgraph(int** orgraph, int size, std::ostringstream& result)  {
	for (int i = 0; i < size; ++i)  {
		result << i + 1 << ": ";
		bool edges = false;
		for (int j = 0; j < size; ++j)  {
			if (orgraph[i][j] == 1)  { 
				result << j + 1 << " ";
				edges = true;
			}

		}

		if (!edges)  {
			result << "нет";
		}
		result << std::endl;
	 }

}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::ifstream orgraph_txt("orgraph.txt");
	if (!orgraph_txt.is_open()) return 1;

	int size;
	orgraph_txt >> size;

	int** orgraph = new int* [size];
	for (int i = 0; i < size; ++i) {
		orgraph[i] = new int[size];
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			orgraph_txt >> orgraph[i][j];
		}

	}
	orgraph_txt.close();

	if (size <= 0) return 0;
	std::cout << size << std::endl;
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			std::cout << orgraph[i][j] << " ";
		}
		std::cout << std::endl;
	}

	std::ostringstream result;
	OutputOrgraph(orgraph, size, result);
	std::cout << "Текстовый вид орграфа:" << std::endl;
	std::cout << result.str();

	for (int i = 0; i < size; ++i) {
		delete[] orgraph[i];
	}
	delete[] orgraph;



	return 0;
}