#pragma once

#include <vector>
#include <random>
#include <functional>
#include <cstdlib>


std::vector<int> generate_uinque_random_number_list(double lower, double higher, int num);

std::vector<std::vector<double>> generate_population_double(
	double min, double max,
	int num_chromosomes, int num_genes_per_chromosome);

std::vector<std::vector<int>> generate_population_int(
	int min, int max,
	int num_population, int num_chromosome_per_population);

int generate_random_int(
	int min, int max);

int flip_int(
	int min, int max,
	int value);

double generate_random_fraction();

std::vector<bool> generate_random_bool_vec(size_t size);

bool cmpfun(const std::pair<int, double> &r1, const std::pair<int, double> &r2);

void initpopg(std::vector<std::vector<bool>>& c, const std::vector<int> &w, const std::vector<int> &v, const int dimw, const int limit, const int pop);