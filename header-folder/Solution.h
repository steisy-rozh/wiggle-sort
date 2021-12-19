#include <vector>
#include <string>

namespace solution
{
	class solution_base
	{
	public:
		std::string virtual name() const = 0;
		void virtual wiggle_sort(std::vector<int>& nums) const = 0;
	};


	class solution_py: public solution_base
	{
	private:
		size_t map_index(size_t index, size_t size) const;

	public:
		std::string name() const override;
		void wiggle_sort(std::vector<int>& nums) const override;
	};

	class solution_cpp: public solution_base
	{
	public:
		std::string name() const override;
		void wiggle_sort(std::vector<int>& nums) const override;
	};
};

