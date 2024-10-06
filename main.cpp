#include <stdio.h>
#include <functional>

int main(int argc, const char* argv[])
{
	std::function<int(int)> fx = [](int i) {return i + 1; };
	auto fx2 = [](int i) {return i + 1; };



	return 0;
}
