#include <fstream>
#include <string>


int main()
{
	const std::string in_path = "rosalind_dna.txt";
	const std::string out_path = "rosalind_dna_OUT.txt";
	std::ifstream in(in_path);
	
	int A{ 0 }, C{ 0 }, G{ 0 }, T{ 0 };
	for (char ch = in.get(); in.good(); ch = in.get())
	{
		if (ch == 'A')
			A++;
		else if (ch == 'C')
			C++;
		else if (ch == 'G')
			G++;
		else if (ch == 'T')
			T++;
	}

	std::ofstream out(out_path);
	out << A << " " << C << " " << G << " " << T;
}


