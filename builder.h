#pragma once

#include "geneticalgo.h"
#include "knapsack.h"

using namespace std;
using namespace geneticalgo;
using namespace knapsack;

class KnapsackGABuilder
{
private:
	vector<vector<bool>> population;
	vector<int> weights;
	vector<int> values;
public:
	KnapsackGA build_knapsack_simple()
	{
		return KnapsackGA(population, new Rank(), new SinglePointCrossover(), new SingleBitMutation(0.05),weights, values, 50, 7);
	}

	KnapsackGABuilder(vector<vector<bool>>& population, vector<int> weights, vector<int> values) :population(population), weights(weights), values(values) {}
};