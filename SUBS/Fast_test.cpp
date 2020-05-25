//date: 5/20/2020

#include <fstream>
#include <iostream>
#include <string>
#include <vector>



int main()
{
	const std::string in_path = "rosalind_subs.txt";
	const std::string out_path = "OUT_rosalind_subs.txt";
	
	std::ifstream in(in_path);
	std::string main_str; //"GATATATGCATATACTT";
	std::getline(in, main_str);
	std::string sub_str; // = "ATAT";
	std::getline(in, sub_str);



	std::vector<int> indexes;

	for (int i = 0; i < main_str.size(); i++)
	{
		if (main_str[i] == sub_str[0])
		{
			int count = 0;
			for (int j = 0; j < sub_str.size(); j++)
			{
				if (main_str[i + j] == sub_str[j])
					count++;
				else
					break;
			}
			if (count == sub_str.size())
				indexes.push_back(i + 1);
		}
	}
	std::ofstream out(out_path);
	for (auto& index : indexes)
		out << index << " ";
}


