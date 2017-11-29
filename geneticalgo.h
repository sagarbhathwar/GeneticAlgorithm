#pragma once

#include "fitness.h"
#include "selection.h"
#include "crossover.h"
#include "mutation.h"

namespace geneticalgo
{
	
	class GeneticAlgo
	{
	private:
		Fitness* fitness;
		Selection* selection;
		Crossover* crossover;
		Mutation* mutation;

		std::vector<std::vector<bool>> population;

		std::vector<int> _fitness_vals;
		std::vector<int> _selection_indices;
		std::vector<std::vector<bool>> _crossover_result;
		std::vector<std::vector<bool>> _mutation_result;
		std::vector<std::vector<bool>> _parent_list1, _parent_list2;

		void calc_fitness();
		void select();
		void do_crossover();
		void refill_population();
		void do_mutation();

	public:

		GeneticAlgo(const std::vector<std::vector<bool>>&, Fitness*, Selection*, Crossover*, Mutation*);

		void run(int max_iter);

	private:
		
	};
}