#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>
#include <sstream>

int ChallengePart1();
int ChallengePart2();
bool CheckColorValue(std::regex regColor, std::string game, int maxNum);
std::vector<std::string> splitString(const std::string& str, char splitter);
int FindMinNumOfCubes(std::regex regColor, std::string game);

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
	int maxBlue = 14;
	int maxGreen = 13;
	int maxRed = 12;
	int counter = 0;

	//regexs
	std::regex regBlue("[0-9]+ blue");
	std::regex regGreen("[0-9]+ green");
	std::regex regRed("[0-9]+ red");


	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			counter++;

			if (!CheckColorValue(regBlue, textLine, maxBlue))
				continue;

			if (!CheckColorValue(regGreen, textLine, maxGreen))
				continue;

			if (!CheckColorValue(regRed, textLine, maxRed))
				continue;

			total += counter;
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

	//regexs
	std::regex regBlue("[0-9]+ blue");
	std::regex regGreen("[0-9]+ green");
	std::regex regRed("[0-9]+ red");

	std::fstream adventInputFile;
	adventInputFile.open("AdventInput.txt");
	if (adventInputFile.is_open())
	{
		std::string textLine;
		while (std::getline(adventInputFile, textLine))
		{
			int blueUsed = FindMinNumOfCubes(regBlue, textLine);
			int greenUsed = FindMinNumOfCubes(regGreen, textLine);
			int redUsed = FindMinNumOfCubes(regRed, textLine);

			total += (blueUsed * greenUsed * redUsed);

		}

		adventInputFile.close();
	}
	else
	{
		std::cout << "ERROR: File failed to open\n";
	}

	return total;
}

bool CheckColorValue(std::regex regColor, std::string game, int maxNum)
{
	std::regex numExtractor("[0-9]+");
	std::vector<std::string> gameVec = splitString(game, ';');
	for (std::string round : gameVec)
	{
		int counter = 0;

		for (std::sregex_iterator i = std::sregex_iterator(round.begin(), round.end(), regColor); i != std::sregex_iterator(); i++)
		{
			std::smatch match = *i;
			std::string matchStr = match.str();
			counter += std::stoi(matchStr.substr(0, matchStr.find(' ')));

			if (counter > maxNum)
				return false;
		}
	}

	return true;
}

int FindMinNumOfCubes(std::regex regColor, std::string game)
{
	int minNumOfCubes = 0;
	std::regex numExtractor("[0-9]+");
	std::vector<std::string> gameVec = splitString(game, ';');
	for (std::string round : gameVec)
	{
		for (std::sregex_iterator i = std::sregex_iterator(round.begin(), round.end(), regColor); i != std::sregex_iterator(); i++)
		{
			std::smatch match = *i;
			std::string matchStr = match.str();
			int cubesUsed = std::stoi(matchStr.substr(0, matchStr.find(' ')));

			if (cubesUsed > minNumOfCubes)
				minNumOfCubes = cubesUsed;
		}
	}

	return minNumOfCubes;
}

std::vector<std::string> splitString(const std::string& str, char splitter)
{
	std::vector<std::string> splitVec;
	std::stringstream ss(str);

	std::string splitStr;
	while (std::getline(ss, splitStr, splitter))
		splitVec.push_back(splitStr);
	
	return splitVec;
}