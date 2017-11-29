#pragma once
#include <cmath>
#include <vector>

namespace geneticalgo
{
	class Fitness
	{
	public:
		virtual std::vector<int> calculate_fitness() = 0;
	};
}