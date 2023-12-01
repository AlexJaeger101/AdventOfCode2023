#include <iostream>
#include <fstream>
#include <string>

int ChallengePart1();
int ChallengePart2();

int main()
{
	int solution1 = ChallengePart1();
	std::cout << "Answer 1: " << solution1 << std::endl;

	int solution2 = ChallengePart2();
	std::cout << "Answer 2: " << solution2 << std::endl;
	return 0;
}

int ChallengePart1()
{
	std::fstream adventInputFile;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{

		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return -1;
}

int ChallengePart2()
{
	std::fstream adventInputFile;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{

		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return -1;
}