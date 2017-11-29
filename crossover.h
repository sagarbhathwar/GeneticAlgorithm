#pragma once

#include <vector>

namespace geneticalgo
{
	class Crossover
	{
	public:
		virtual std::vector<std::vector<bool>> do_crossover(
			const std::vector<std::vector<bool>>& parent1_list,
			const std::vector<std::vector<bool>>& parent2_list) = 0;
	};

	class SinglePointCrossover : public Crossover
	{
	public:
		virtual std::vector<std::vector<bool>> do_crossover(
			const std::vector<std::vector<bool>>& parent1_list,
			const std::vector<std::vector<bool>>& parent2_list);
	};

	class DoublePointCrossover : public Crossover
	{
	public:
		virtual std::vector<std::vector<bool>> do_crossover(
			const std::vector<std::vector<bool>>& parent1_list,
			const std::vector<std::vector<bool>>& parent2_list);
	};

	class UniformCrossover : public Crossover
	{
	public:
		virtual std::vector<std::vector<bool>> do_crossover(
			const std::vector<std::vector<bool>>& parent1_list,
			const std::vector<std::vector<bool>>& parent2_list);
	};
}