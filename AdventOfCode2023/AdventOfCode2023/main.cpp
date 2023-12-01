#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int ChallengePart1();
int ChallengePart2();
char GetFirstNum(std::string input);
char GetFirstNumSubStringMethod(std::string input);
char GetLastNum(std::string input);
char GetLastNumSubStringMethod(std::string input);
std::string FindSubstring(std::string input, int n);
std::string FindReversedSubstring(std::string input, int n);

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
	int total = 0;
	std::fstream adventInputFile;

	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::string extracted = { GetFirstNum(textLine) , GetLastNum(textLine) };
			total += std::stoi(extracted);
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return total;
}

int ChallengePart2()
{
	int total = 0;
	std::vector<std::string> nums{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			std::string extracted = { GetFirstNumSubStringMethod(textLine) , GetLastNumSubStringMethod(textLine) };
			total += std::stoi(extracted);
		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return total;
}

char GetFirstNum(std::string input)
{
	for (char& c : input)
	{
		if (std::isdigit(c))
			return int(c);
	}

	return '0';
}

char GetLastNum(std::string input)
{
	std::reverse(input.begin(), input.end());
	return GetFirstNum(input);
}

char GetFirstNumSubStringMethod(std::string input)
{
	std::vector<std::string> nums { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i]))
			return input[i];

		std::string substr = FindSubstring(input, i + 1);
		for (int j = 0; j < nums.size(); j++)
			if (substr.find(nums[j]) != std::string::npos)
				return (j + 1) + '0';
	}
}

char GetLastNumSubStringMethod(std::string input)
{
	std::vector<std::string> nums{ "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

	for (int i = input.length() - 1; i >= 0; i--)
	{
		if (std::isdigit(input[i]))
			return input[i];

		std::string substr = FindReversedSubstring(input, (input.length() - i) + 1);
		for (int j = 0; j < nums.size(); j++)
			if (substr.find(nums[j]) != std::string::npos)
				return (j + 1) + '0';
	}
}

std::string FindSubstring(std::string input, int n)
{
	if (input.length() < n)
		return input;

	return input.substr(0, n);
}

std::string FindReversedSubstring(std::string input, int n)
{
	if (input.size() < n)
		return input;

	return input.substr(input.size() - n);
}