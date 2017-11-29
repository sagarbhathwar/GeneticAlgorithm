#include <algorithm>
#include <set>

#include <iostream>

#include "selection.h"
#include "util.h"

std::vector<int> geneticalgo::RouletteWheel::select(const std::vector<int>& fitness_values)
{
	int fitness_sum = 0;
	for (int i = 0; i < fitness_values.size(); ++i)
		fitness_sum += fitness_values[0];

	std::cout << "Average Fitness :" << fitness_sum / fitness_values.size() << std::endl;

	std::vector<int> cumulative_fitness(fitness_values.size());

	cumulative_fitness[0] = fitness_values[0];

	for (int i = 1; i < fitness_values.size(); ++i)
		cumulative_fitness[i] = cumulative_fitness[i - 1] + fitness_values[i];

	std::set<int> selection;

	for (int i = 0; selection.size() < fitness_values.size() / 2 && i < fitness_values.size(); ++i)
	{
		int random_fintess = generate_random_int(0, fitness_sum);
		int partial_fitness = 0;
		auto it = std::lower_bound(cumulative_fitness.begin(), cumulative_fitness.end(), random_fintess);
		int index = std::distance(cumulative_fitness.begin(), it);
		selection.insert(index);
	}

	return std::vector<int>(selection.begin(), selection.end());

}

std::vector<int> geneticalgo::Rank::select(const std::vector<int>& fitness_values)
{

	struct Comp
	{
		Comp(const std::vector<int>& v) : v(v) {}
		bool operator ()(int a, int b) { return v[a] > v[b]; }
		const std::vector<int>& v;
	};

	std::vector<int> all_indices(fitness_values.size());
	for (int i = 0; i < fitness_values.size(); ++i) all_indices[i] = i;

	std::partial_sort(
		all_indices.begin(), all_indices.begin() + fitness_values.size() / 2, 
		all_indices.end(), Comp(fitness_values));

	return std::vector<int>(all_indices.begin(), all_indices.begin() + fitness_values.size() / 2);
}
