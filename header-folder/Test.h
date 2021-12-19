#include "Solution.h"
#include <vector>
#include <string>

namespace test 
{
	typedef unsigned long long test_int;

	class TestBase 
	{
	public:
		std::string create_error_message(const std::string& message, int left, int middle, int right) const;
		std::string create_error_message(const std::string& message, unsigned int test_number) const;
		void assert(const std::vector<int>& actual) const;
 	};	

	class SolutionTest: protected TestBase
	{
	private:
		test_int elapsed_time(const solution::solution_base& solution, std::vector<int>& input) const;
		test_int test1(const solution::solution_base& solution) const;
		test_int test2(const solution::solution_base& solution) const;
		test_int test3(const solution::solution_base& solution) const;
		test_int test4(const solution::solution_base& solution) const;
	public:
		test_int run_test(const solution::solution_base& solution) const;
	};

	class TestException : public std::runtime_error
	{
	private:
		using _Mybase = runtime_error;
	public:
		TestException(const std::string& message) : _Mybase(message) { }
	};
};

