#pragma once

#include <vector>
#include <algorithm>

#include "util.h"

namespace geneticalgo
{
	class Selection
	{
	public:
		virtual std::vector<int> select(const std::vector<int>& fitness_values) = 0;
	};

	class RouletteWheel : public Selection
	{
	public:
		virtual std::vector<int> select(const std::vector<int>& fitness_values);
	};

	class Rank : public Selection
	{
	public:
		virtual std::vector<int> select(const std::vector<int>& fitness_values);
	};
}