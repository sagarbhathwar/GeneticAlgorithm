#pragma once

#include "geneticalgo.h"

namespace knapsack
{
	class KnapsackFitness : public geneticalgo::Fitness
	{
	private:
		std::vector<std::vector<bool>> population;
		std::vector<int> weights;
		std::vector<int> values;
		int limit;
		int penalty;

	public:

		KnapsackFitness(
			const std::vector<std::vector<bool>>& population,
			const std::vector<int>& weights,
			const std::vector<int>& values, int limit, int penalty)
			:
			population(population),
			weights(weights),
			values(values),
			limit(limit),
			penalty(penalty){ }

		std::vector<int> calculate_fitness()
		{
			std::vector<int> fitness;

			for (int i = 0; i < population.size(); ++i)
			{
				int fit = 0;
				int wsum = 0;
				for (int j = 0; j < weights.size(); ++j)
				{
					fit += population[i][j] * values[i];
					wsum += population[i][j] * weights[i];
				}

				std::cout << fit << std::endl;
				if (wsum > limit) fit -= (wsum - limit);
				fitness.push_back(fit);
			}

			return fitness;
		}
	};
}

namespace knapsack
{
	class KnapsackGA : public geneticalgo::GeneticAlgo
	{
	private:

		std::vector<int> weights;
		std::vector<int> values;

	public:
		KnapsackGA(
			const std::vector<std::vector<bool>>& population,
			geneticalgo::Selection* selection,
			geneticalgo::Crossover* crossover,
			geneticalgo::Mutation* mutation,
			const std::vector<int>& weights, 
			const std::vector<int>& values,
			int limit, int penalty)
			:
			weights(weights),
			values(values),
			GeneticAlgo(population,
				new KnapsackFitness(population, weights, values, limit, penalty), 
				selection, crossover, mutation)
		{

		}

	};
}