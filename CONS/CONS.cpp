//date: 5/22/2020

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


char max_of_four(int a, int b, int c, int d)
{
	if ((a >= b) && (a >= c) && (a >= d))
		return 'A'; //max = a;
	if ((b >= a) && (b > c) && (b >= d))
		return 'C'; // max = b;
	if ((c >= a) && (c >= b) && (c >= d))
		return 'G'; //max = c;
	if ((d >= a) && (d >= b) && (d >= c))
		return 'T'; //max = d;
}


int main()
{
	const std::string in_path = "rosalind_cons.txt";
	const std::string out_path = "OUT_rosalind_cons.txt";
	
	std::ifstream in(in_path);
	std::vector<char> DNA_seq;

	//parsing
	int rows = 0;
	int columns = 0;
	for (std::string buffer; std::getline(in, buffer); )
	{
		if (buffer[0] == '>')
		{
			rows++;
		}
		else
		{
			for (auto& ch : buffer)
				DNA_seq.push_back(ch);
		}
	}
	columns = DNA_seq.size() / rows;
	//Profile matrix
	std::vector<int> DNA_profile(4*columns);
	std::string Consensus = "";
	for (int j = 0; j < columns; j++)
	{
		int A{ 0 }, C{ 0 }, G{ 0 }, T{ 0 };
		for (int i = 0; i < rows; i++)
		{
			int index = i * columns + j;
			if (DNA_seq[index] == 'A')
				A++;
			else if (DNA_seq[index] == 'C')
				C++;
			else if (DNA_seq[index] == 'G')
				G++;
			else if (DNA_seq[index] == 'T')
				T++;
		}
		DNA_profile[0 * columns + j] = A; //4*columns
		DNA_profile[1 * columns + j] = C;
		DNA_profile[2 * columns + j] = G;
		DNA_profile[3 * columns + j] = T;

		Consensus += max_of_four(A, C, G, T);
	}
	//output
	std::ofstream out(out_path);

	out << Consensus << '\n';
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case (0):
			out << "A: ";
			break;
		case (1):
			out << "C: ";
			break;
		case (2):
			out << "G: ";
			break;
		case(3):
			out << "T: ";
			break;
		default:
			break;
		}
		for (int j = 0; j < columns; j++)
		{
			out << DNA_profile[i * columns + j] << ' ';
		}
		out << '\n';
	}
}


