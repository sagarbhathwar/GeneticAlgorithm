#pragma once
#include <vector>
#include "util.h"

namespace geneticalgo
{
	class Mutation
	{
	public:
		double mutation_rate;
		Mutation(double mutation_rate);
		virtual void do_mutation(std::vector<bool>& hypothesis) = 0;
	};

	class SingleBitMutation : public Mutation
	{
	public:
		SingleBitMutation(double mutation_rate);
		virtual void do_mutation(std::vector<bool>& hypothesis);
	};

	class FlipBitMutation : public Mutation {
	public:
		FlipBitMutation(double mutation_rate);
		virtual void do_mutation(std::vector<bool>& hypothesis);
	};

	class UniformMutation : public Mutation {
	public:
		UniformMutation(double mutation_rate);
		virtual void do_mutation(std::vector<bool>& hypothesis);
	};
}