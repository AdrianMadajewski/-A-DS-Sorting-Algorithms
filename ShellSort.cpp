#include "ShellSort.h"
#include <iostream>

void shell_sort(std::vector<int>& data, int& comparisons, int& swaps, std::vector<int>& knuths)
{
	if (!data.size())
		return;

	auto gap = 1;
	while (gap <= data.size())
		gap = gap * 3 + 1;
	gap /= 9;
	std::cout << gap << '\n';

	while (gap > 0) {
		knuths.emplace_back(gap);
		for (auto i = gap; i < data.size(); ++i) {
			auto temp = data.at(i);
			comparisons++;
			while (i >= gap && data.at(i - gap) > temp) {
				comparisons++;
				data.at(i) = data.at(i - gap);
				swaps++;
				i -= gap;
			}
			data.at(i) = temp;
			swaps++;
		}
		gap /= 3;
	}
}