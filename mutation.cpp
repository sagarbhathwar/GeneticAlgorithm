#include "mutation.h"

geneticalgo::Mutation::Mutation(double mutation_rate) : mutation_rate(mutation_rate)
{

}

geneticalgo::SingleBitMutation::SingleBitMutation(double mutation_rate) : Mutation(mutation_rate)
{

}

void geneticalgo::SingleBitMutation::do_mutation(std::vector<bool>& hypothesis)
{
	int rand_index = generate_random_int(0, hypothesis.size() - 1);

	hypothesis[rand_index] = !hypothesis[rand_index];
}

geneticalgo::FlipBitMutation::FlipBitMutation(double mutation_rate) : Mutation(mutation_rate)
{

}


void geneticalgo::FlipBitMutation::do_mutation(std::vector<bool>& hypothesis)
{
	for (int i = 0; i < hypothesis.size(); ++i)
		hypothesis[i] = !hypothesis[i];
}

geneticalgo::UniformMutation::UniformMutation(double mutation_rate) : Mutation(mutation_rate)
{

}


void geneticalgo::UniformMutation::do_mutation(std::vector<bool>& hypothesis)
{
	for (int i = 0; i < hypothesis.size(); ++i) {
		if (generate_random_fraction() < this->mutation_rate)
			hypothesis[i] = !hypothesis[i];
	}
}
