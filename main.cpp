#include <iostream>
#include <climits>

#include "fitness.h"
#include "selection.h"
#include "crossover.h"
#include "mutation.h"
#include "geneticalgo.h"
#include "knapsack.h"
#include "util.h"

using namespace std;
using namespace geneticalgo;
using namespace knapsack;

int main()
{
	vector<int> weights, values; // items weights and values
	int info = 0;
	FILE *f = fopen("1000_weights.txt", "r");
	FILE *f2 = fopen("1000_values.txt", "r");
	while (!feof(f) || !feof(f2)) 
	{
		fscanf(f, " %d ", &info);
		weights.push_back(info);

		info = 0;
		fscanf(f2, " %d ", &info);
		values.push_back(info);
	}

	const int limit = 50; // knapsack weight limit
	const int pop = 250; // chromosome population size
	const int gens = INT_MAX; // maximum number of generations
	const int penalty = 7;
	const double mutation_rate = 0.5;

	std::vector<std::vector<bool>> population;
	for (int i = 0; i < pop; ++i)
		population.push_back(vector<bool>(weights.size()));

	initpopg(population, weights, values, weights.size(), limit, pop);

	KnapsackGA ksga(
		population, new RouletteWheel(), new SinglePointCrossover(), new SingleBitMutation(mutation_rate),
		weights, values, limit, penalty);
	ksga.run(20000);
	cin.get();
}