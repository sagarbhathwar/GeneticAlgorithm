#include "crossover.h"

#include <iostream>

using namespace std;

std::vector<std::vector<bool>> geneticalgo::SinglePointCrossover::do_crossover(
	const std::vector<std::vector<bool>>& parent1_list, 
	const std::vector<std::vector<bool>>& parent2_list)
{
	std::vector<vector<bool> > result;
	std::vector<vector<bool> > parent1_pt(parent1_list.begin(), parent1_list.end());
	std::vector<vector<bool> > parent2_pt(parent2_list.begin(), parent2_list.end());

	auto row = parent1_pt.begin();
	auto row1 = parent2_pt.begin();

	for (; row != parent1_pt.end() && row1 != parent2_pt.end(); ++row, ++row1) 
	{
		bool temp = *row->begin();
		*row->begin() = *row1->begin();
		*row1->begin() = temp;
	}

	for (int i = 0; i< parent1_list.size(); ++i) {
		result.push_back(parent1_list[i]);
	}

	for (int i = 0; i< parent2_list.size(); ++i) {
		result.push_back(parent2_list[i]);
	}


	for (int i = 0; i< parent1_pt.size(); ++i) {
		result.push_back(parent1_pt[i]);
	}

	for (int i = 0; i< parent2_pt.size(); ++i) {
		result.push_back(parent2_pt[i]);
	}

	//return std::vector<std::vector<bool>>();
	return result;
}

std::vector<std::vector<bool>> geneticalgo::DoublePointCrossover::do_crossover(const std::vector<std::vector<bool>>& parent1_list, const std::vector<std::vector<bool>>& parent2_list)
{
	std::vector<vector<bool> > result;
	std::vector<vector<bool> > parent1_pt;
	parent1_pt.assign(parent1_list.begin(), parent1_list.end());
	std::vector<vector<bool> > parent2_pt;
	parent2_pt.assign(parent2_list.begin(), parent2_list.end());

	std::vector< vector<bool> >::iterator row = parent1_pt.begin();
	std::vector< vector<bool> >::iterator row1 = parent2_pt.begin();

	for (; row != parent1_pt.end(); ++row, ++row1) {
		swap(*row->begin(), *row1->begin());
		swap(*(row->end() - 1), *(row1->end() - 1));
	}

	for (int i = 0; i< parent1_list.size(); ++i) {
		result.push_back(parent1_list[i]);
	}

	for (int i = 0; i< parent2_list.size(); ++i) {
		result.push_back(parent2_list[i]);
	}


	for (int i = 0; i< parent1_pt.size(); ++i) {
		result.push_back(parent1_pt[i]);
	}

	for (int i = 0; i< parent2_pt.size(); ++i) {
		result.push_back(parent2_pt[i]);
	}

	//return std::vector<std::vector<bool>>();
	return result;
}

std::vector<std::vector<bool>> geneticalgo::UniformCrossover::do_crossover(const std::vector<std::vector<bool>>& parent1_list, const std::vector<std::vector<bool>>& parent2_list)
{
	std::vector<vector<bool> > result;
	std::vector<vector<bool> > parent1_pt;
	parent1_pt.assign(parent1_list.begin(), parent1_list.end());
	std::vector<vector<bool> > parent2_pt;
	parent2_pt.assign(parent2_list.begin(), parent2_list.end());

	std::vector< vector<bool> >::iterator row = parent1_pt.begin();
	std::vector< vector<bool> >::iterator row1 = parent2_pt.begin();

	std::vector<bool>::iterator col;
	std::vector<bool>::iterator col1;

	for (; row != parent1_pt.end(); ++row, ++row1) {
		for (col = row->begin(), col1 = row1->begin(); col <= row->end(); ) {
			std::swap(*col, *col1);
			col = col + 2;
			col1 = col1 + 2;
		}

	}



	for (int i = 0; i< parent1_list.size(); ++i) {
		result.push_back(parent1_list[i]);
	}

	for (int i = 0; i< parent2_list.size(); ++i) {
		result.push_back(parent2_list[i]);
	}


	for (int i = 0; i< parent1_pt.size(); ++i) {
		result.push_back(parent1_pt[i]);
	}

	for (int i = 0; i< parent2_pt.size(); ++i) {
		result.push_back(parent2_pt[i]);
	}

	//return std::vector<std::vector<bool>>();
	return result;
}
