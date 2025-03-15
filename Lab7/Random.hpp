#pragma once

#include <ctime>
#include <cstdlib>

namespace SfmlLab1
{
	class Random
	{
	private:
		static int map(int x, int in_min, int in_max, int out_min, int out_max) {
			return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
		}

	public:
		static void init()
		{
			std::srand(std::time({}));
		}

		static float fRandom()
		{
			return static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
		}

		static unsigned char ubRandom()
		{
			return static_cast<unsigned char>(map(rand(), 0, RAND_MAX, 0, 255));
		}
	};
}