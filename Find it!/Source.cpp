//Xhoi Caveli
#include <iostream>
#include <map>
#include <fstream>
#include <string>
#include <list>

int main()
{

	//open file to read
	std::fstream file;
	file.open("shuffled_words.txt", std::ios::in);
	if (!file) 
	{
		std::cerr << "ERROR! Cannot open file!" << std::endl;
		exit(-2);
	}

	std::map<std::string, std::string> wordsChain;
	std::string str1, str2;

	//read words into map
	while (!file.eof())
	{
		std::getline(file, str1, ' ');
		std::getline(file, str2, ' ');
		wordsChain.insert(std::pair<std::string, std::string>(str1, str2));
		
	}

	std::list<std::list<std::string>> sentences;
	std::map<std::string, std::string>::iterator iter1 = wordsChain.begin();
	std::map<std::string, std::string>::iterator iter2;
	std::map<std::string, std::string>::iterator iter3;
	
	//loop through map to find values that are also keys 
	while (iter1 != wordsChain.end())
	{
		//create list to hold chains 
		std::list<std::string> s;

		iter2 = wordsChain.begin();
		iter3 = iter1;
		
		iter2 = wordsChain.(iter1->second);
		if (iter2 == wordsChain.end())
		{
			iter2 = wordsChain.begin();
		}

		if (iter2->first == iter3->second)
		{
			s.push_back(iter3->first);
			s.push_back(iter3->second);
		}

		//keep looping to add chains
		//until you find a value that is not a key (dead end)
		while (iter2->first == iter3->second)
		{
			iter3 = iter2;
			iter2 = wordsChain.find(iter3->second);
			if (iter2 == wordsChain.end())
			{
				iter2 = wordsChain.begin();
			}

			s.push_back(iter3->second);
		}

		//add chains to list that holds all the chains
		if (!s.empty())
		{
			sentences.push_back(s);
		}

		iter1++;
	}
	
	//create list to hold longest list
	std::list<std::string> longestSentence = sentences.front();

	//find longest list
	for (std::list<std::string> x : sentences)
	{
		if (x.size() > longestSentence.size())
		{
			longestSentence = x;
		}
	}

	//display longest chain
	for (std::string snt : longestSentence)
	{
		std::cout << snt << " ";
	}
	std::cout << std::endl;
	std::cout << std::endl;

	//close file
	file.close();

	system("PAUSE");
	return 0;
}