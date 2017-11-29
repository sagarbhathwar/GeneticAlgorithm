#include "geneticalgo.h"

geneticalgo::GeneticAlgo::GeneticAlgo(
	const std::vector<std::vector<bool>>& population,
	geneticalgo::Fitness* fitness,
	geneticalgo::Selection* selection,
	geneticalgo::Crossover* crossover,
	geneticalgo::Mutation* mutation) :
	population(population),
	fitness(fitness),
	selection(selection),
	crossover(crossover),
	mutation(mutation)
{

}

void geneticalgo::GeneticAlgo::calc_fitness()
{
	_fitness_vals = fitness->calculate_fitness();
}

void geneticalgo::GeneticAlgo::select()
{
	_selection_indices = selection->select(_fitness_vals);
}

void geneticalgo::GeneticAlgo::do_crossover()
{
	_parent_list1 = std::vector<std::vector<bool>>(_parent_list1.size());
	_parent_list2 = std::vector<std::vector<bool>>(_parent_list2.size());
	for (int i = 0; i < _selection_indices.size(); i+= 2) _parent_list1.push_back(population[i]);

	for (int i = 1; i < _selection_indices.size(); i += 2) _parent_list2.push_back(population[i]);


	_crossover_result = crossover->do_crossover(_parent_list1, _parent_list2);
}

void geneticalgo::GeneticAlgo::refill_population()
{
	population = std::vector<std::vector<bool>>();
	for (auto vec : _parent_list1) population.push_back(vec);
	for (auto vec : _parent_list2) population.push_back(vec);
	for (auto vec : _crossover_result) population.push_back(vec);
}

void geneticalgo::GeneticAlgo::do_mutation()
{
	for(int i = 0; i < population.size(); ++i)
		mutation->do_mutation(population[i]);
}

//Facade?
void geneticalgo::GeneticAlgo::run(int max_iter)
{
	for (int i = 0; i < max_iter; ++i)
	{
		calc_fitness();
		select();
		do_crossover();
		refill_population();
		do_mutation();
	}
}

