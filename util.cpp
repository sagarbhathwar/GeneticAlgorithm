#include "util.h"

std::vector<int> generate_uinque_random_number_list(double lower, double higher, int num)
{

	std::random_device rnd_device;
	std::mt19937 mersenne_engine(rnd_device());
	std::uniform_real_distribution<double> dist(lower, higher);

	auto gen = std::bind(dist, mersenne_engine);
	std::vector<int> vec(num);
	std::generate(vec.begin(), vec.end(), gen);

	return vec;
}

std::vector<std::vector<double>> generate_population_double(
	double min, double max,
	int num_population, int num_chromosome_per_population)
{
	std::vector<std::vector<double>> result(num_population, std::vector<double>(num_chromosome_per_population));

	std::random_device generator;
	std::uniform_real_distribution<double> distribution(min, max);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			result[i][j] = distribution(generator);
		}
	}

	return result;
}

std::vector<std::vector<int>> generate_population_int(
	int min, int max,
	int num_population, int num_chromosome_per_population)
{
	std::vector<std::vector<int>> result(num_population, std::vector<int>(num_chromosome_per_population));

	std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);

	for (int i = 0; i < result.size(); ++i)
	{
		for (int j = 0; j < result[i].size(); ++j)
		{
			result[i][j] = distribution(generator);
		}
	}

	return result;
}

int generate_random_int(
	int min, int max)
{
	std::random_device generator;
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(generator);
}


int flip_int(
	int min, int max,
	int value)
{
	return max - value + min;
}

double generate_random_fraction()
{
	return ((double)std::rand() / (RAND_MAX));
}

std::vector<bool> generate_random_bool_vec(size_t size)
{
	std::mt19937 gen;
	std::bernoulli_distribution  dist;

	std::vector<bool> bv;
	bv.reserve(size);

	for (int i = 0; i < size; ++i)
		bv.push_back(dist(gen));

	return bv;
}


bool cmpfun(const std::pair<int, double> &r1, const std::pair<int, double> &r2) { return r1.second > r2.second; }

void initpopg(std::vector<std::vector<bool>>& c, const std::vector<int> &w, const std::vector<int> &v, const int dimw, const int limit, const int pop) {
	std::vector<std::pair<int, double> > rvals(dimw);
	std::vector<int> index(dimw, 0);
	for (int i = 0; i<dimw; i++) {
		rvals.push_back(std::pair<int, double>(std::make_pair(i, (double)v[i] / (double)w[i])));
	}
	std::sort(rvals.begin(), rvals.end(), cmpfun);
	int currentw = 0, k;
	for (int i = 0; i<dimw; i++) {
		k = rvals[i].first;
		if (currentw + w[k] <= limit) { // greedy fill
			currentw += w[k];
			index[k] = 1;
		}
	}
	for (int i = 0; i<pop; i++) {
		for (int j = 0; j<dimw; j++) {
			c[i][j] = index[j];
		}
	}
}