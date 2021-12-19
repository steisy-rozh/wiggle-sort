#include <vector>
#include <stdexcept>
#include <string>
#include <iostream>
#include <sstream>
#include <chrono>
#include "..\header-folder\Test.h"
#include "..\header-folder\Utility.h"

std::string test::TestBase::create_error_message(const std::string& message, int left, int medium, int right) const
{
	std::stringstream in;
	in << message << " : " << "[" << left << " < " << medium << " > " << right << "]";
	return in.str();
}

std::string test::TestBase::create_error_message(const std::string& message, unsigned int test_number) const
{
	std::stringstream in;
	in << message << " in test " << test_number;
	return in.str();
}

void test::TestBase::assert(const std::vector<int>& actual) const
{
	const std::string message("Invalid value in array");

	std::cout << actual[0];

	for (test::test_int index = 1; index < actual.size() - 1; ++index)
	{
		std::cout << " - " << actual[index];

		if (!utility::is_even(index))
		{
			if (actual[index - 1] < actual[index] && actual[index] > actual[index + 1])
			{
				
			}
			else 
			{
				std::string error_message = this->create_error_message(message, actual[index - 1], actual[index], actual[index + 1]);
				throw std::invalid_argument(error_message);
			}
		}
	}

	std::cout << std::endl;
}

test::test_int test::SolutionTest::elapsed_time(const solution::solution_base& solution, std::vector<int>& input) const
{
	auto start = std::chrono::steady_clock::now();
	solution.wiggle_sort(input);
	auto end = std::chrono::steady_clock::now();

	auto elapsed_microseconds = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
	test_int ms = elapsed_microseconds;
	return ms;
}

test::test_int test::SolutionTest::test1(const solution::solution_base& solution) const
{
	test::test_int ms = 0;
	std::vector<int> v_input({ 1, 5, 1, 1, 6, 4 });
	try
	{
		ms += this->elapsed_time(solution, v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 1);
		throw test::TestException(error_message);
	}
	
	std::cout << "test" << 1 << std::endl;

	try 
	{
		this->assert(v_input);
	}
	catch (std::invalid_argument &e) 
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 1);
		throw test::TestException(error_message);
	}

	return ms;
}

test::test_int test::SolutionTest::test2(const solution::solution_base& solution) const
{
	test::test_int ms = 0;
	std::vector<int> v_input({ 1, 3, 2, 2, 3, 1 });
	try
	{
		ms += this->elapsed_time(solution, v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 2);
		throw test::TestException(error_message);
	}

	std::cout << "test" << 2 << std::endl;

	try
	{
		this->assert(v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 2);
		throw test::TestException(error_message);
	}

	return ms;
}

test::test_int test::SolutionTest::test3(const solution::solution_base& solution) const
{
	test::test_int ms = 0;
	std::vector<int> v_input({ 13, 6, 5, 5, 4, 2 });
	try
	{
		ms += this->elapsed_time(solution, v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 3);
		throw test::TestException(error_message);
	}

	std::cout << "test" << 3 << std::endl;

	try
	{
		this->assert(v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 2);
		throw test::TestException(error_message);
	}

	return ms;
}

test::test_int test::SolutionTest::test4(const solution::solution_base& solution) const
{
	test::test_int ms = 0;
	std::vector<int> v_input({ 1, 1, 2, 1, 2, 2, 1 });
	try
	{
		ms += this->elapsed_time(solution, v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 4);
		throw test::TestException(error_message);
	}

	std::cout << "test" << 4 << std::endl;

	try
	{
		this->assert(v_input);
	}
	catch (std::invalid_argument& e)
	{
		std::string message(e.what());
		std::string error_message = this->create_error_message(message, 4);
		throw test::TestException(error_message);
	}

	return ms;
}

test::test_int test::SolutionTest::run_test(const solution::solution_base& solution) const
{
	test::test_int ms = 0ULL;

	ms += this->test1(solution);
	ms += this->test2(solution);
	ms += this->test3(solution);
	ms += this->test4(solution);

	return ms;
}
