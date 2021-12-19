#include "../header-folder/Utility.h"

bool utility::is_even(unsigned long long index)
{
	return (index ^ 1) == (index + 1);
}