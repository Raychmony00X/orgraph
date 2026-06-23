#include <Windows.h>

#include <iostream>
#include <fstream>
#include <sstream>

void TopologicalDFS(int** orgraph,int size, int vertex, bool* visited, int* order,
	int& order_index)  {
	visited[vertex] = true;
	
	for (int i = 0; i < size; ++i)  {
		if (orgraph[vertex][i] == 1 && !visited[i])  { 
			TopologicalDFS(orgraph, size, i, visited, order, order_index);
		}

	}

	order[order_index++] = vertex;
}

void TopologicalSort(int** orgraph, int size, std::ostringstream& result)  {
	bool* visited = new bool[size]();
	
	int* order = new int[size];
	int order_index = 0;

	for (int i = 0; i < size; ++i)  {
		if (!visited[i]) {
			TopologicalDFS(orgraph, size, i, visited, order, order_index);
		}

	}

	for (int i = size - 1; i >= 0; --i)  {
		result << order[i] + 1 << " ";
	}

	delete[] visited;
	delete[] order;
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
	TopologicalSort(orgraph, size, result);
	std::cout << "Топологический порядок вершин: " << result.str() << std::endl;

	for (int i = 0; i < size; ++i) {
		delete[] orgraph[i];
	}
	delete[] orgraph;

	return 0;
}