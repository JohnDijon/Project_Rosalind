#include <fstream>
#include <string>


int main()
{
	const std::string in_path = "rosalind_rna.txt";
	const std::string out_path = "rosalind_rna_OUT.txt";
	std::ifstream in(in_path);
	std::ofstream out(out_path);

	for (char ch = in.get(); in.good(); ch = in.get())
	{
		if (ch == 'T')
			out << 'U';
		else
			out << ch;

	}
}


