//date: 5/22/2020

#include <fstream>
#include <iostream>
#include <string>
#include <map>


float main()
{
	const std::string in_path = "rosalind_iprb.txt";
	const std::string out_path = "OUT_rosalind_iprb.txt";
	
	std::ifstream in(in_path);
	int k, m, n;
	in >> k >> m >> n;
	
	float total = k + m + n;
	float prob = 1 - ((n / total * (n - 1) / (total - 1)) * 1.0f
		+ 2 * (n / total * m / (total - 1)) * 1.0f / 2.0f		//2* since m*n and n*m - two cases of the same prob
		+ (m / total * (m -1) / (total - 1)) * 1.0f / 4.0f);


	std::ofstream out(out_path);
	out << prob;
}


