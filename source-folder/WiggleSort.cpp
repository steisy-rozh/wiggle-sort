// WiggleSort.cpp : Defines the entry point for the application.
//

#include "../header-folder/WiggleSort.h"

using namespace std;

int main()
{
	std::vector<unique_ptr<solution::solution_base>> solutions;
	solutions.emplace_back(new solution::solution_py());
	solutions.emplace_back(new solution::solution_cpp());

	test::SolutionTest test;

	for (auto& solution: solutions)
	{
		try
		{
			test::test_int ms = test.run_test(*solution);
			cout << "All tests for the " << solution->name() << " completed successfully for " << ms << " microseconds." << endl;
		}
		catch (test::TestException& e)
		{
			cout << e.what() << endl;
		}
	}

	return 0;
}


