//date: 5/20/2020

#include <fstream>
#include <iostream>
#include <string>
#include <vector>


int fib(int n, int k)
{
	if (n == 1 || n == 2)
		return 1;
	else
		return fib(n - 1, k) + fib(n - 2, k) * k;
}

int main()
{
	const std::string in_path = "rosalind_fib.txt";
	const std::string out_path = "OUT_rosalind_fib.txt";
	
	std::ifstream in(in_path);
	int months, pairs;
	in >> months >> pairs;

	std::ofstream out(out_path);
	out << fib(months, pairs);
}


