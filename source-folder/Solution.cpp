#include "../header-folder/Solution.h"
#include <vector>
#include <algorithm>
#include "../header-folder/Utility.h"
#include <stdexcept>

using namespace solution;

/// <summary>
/// Find median and put everything below it on the left and everything above it on the right (This is a well-known O(n) problem) 
/// </summary>
/// <param name="index"></param>
/// <param name="size"></param>
/// <returns></returns>
size_t solution::solution_py::map_index(size_t index, size_t size) const
{
	size_t median_index = (size + 1) / 2;
	return index < median_index
		? (median_index - index - 1) * 2
		: (size - index - 1) * 2 + 1;
}

std::string solution::solution_py::name() const
{
	return std::string("Python base solution");
}

void solution_py::wiggle_sort(std::vector<int>& nums) const
{	
	size_t size = nums.size();

	if (size <= 1)
	{
		return;
	}

	size_t index_left = 0, index_right = size, index_median = (size + 1) / 2;

	while (index_left < index_right)
	{
		auto p_median = nums.begin() + this->map_index(index_median, size);
		const int median = *p_median;

		size_t lcnt = 0, ecnt = 0, hcnt = 0;

		for (size_t index = index_left; index < index_right; ++index)
		{
			auto val = nums.begin() + this->map_index(index, size);
			if (*val < median)
			{
				++lcnt;
			}
			else if (*val == median)
			{
				++ecnt;
			}
			else
			{
				++hcnt;
			}
		}

		size_t lc = 0;
		for (size_t index = index_left; index < index_right; ++index)
		{
			auto val = nums.begin() + this->map_index(index, size);
			if (*val < median)
			{
				std::iter_swap(nums.begin() + this->map_index(index, size), 
					nums.begin() + this->map_index(lc++ + index_left, size));
			}
		}

		if (lc != lcnt)
		{
			throw std::invalid_argument("the total left shift must be equal the total number of values, those are below median.");
		}

		size_t ec = 0;
		for (size_t index = index_left + lcnt; index < index_right; ++index)
		{
			auto val = nums.begin() + this->map_index(index, size);
			if (*val == median)
			{
				std::iter_swap(nums.begin() + this->map_index(index, size), 
					nums.begin() + this->map_index(ec++ + lcnt + index_left, size));
			}
		}

		if (ec != ecnt)
		{
			throw std::invalid_argument("the median shift must be equal the total number of values, those are equal median.");
		}

		if (index_left > index_median || index_median >= index_right)
		{
			throw std::invalid_argument("the median has to be located between left and right borders of array");
		}

		if (index_median < index_left + lcnt)
		{
			index_right = index_left + lcnt;
		}
		else if (index_median < index_left + lcnt + ecnt)
		{
			break; // solution found
		}
		else
		{
			index_left += lcnt + ecnt;
		}
	}
	
	
}

std::string solution::solution_cpp::name() const
{
	return std::string("Pure cpp solution");
}

void solution::solution_cpp::wiggle_sort(std::vector<int>& nums) const
{
	size_t n = nums.size();
	auto mid_it = nums.begin() + n / 2;
	nth_element(nums.begin(), mid_it, nums.end());
	int middle = *mid_it;

	#define map_index(i) nums[(1 + (i) * 2) % (n | 1)]

	size_t i = 0, j = 0, k = n - 1;
	while (j <= k && k > 0) {
		if (map_index(j) > middle)
		{
			std::swap(map_index(i++), map_index(j++));
		}
		else if (map_index(j) < middle)
		{
			 std::swap(map_index(j), map_index(k--));
		}
		else ++j;
	}
}
