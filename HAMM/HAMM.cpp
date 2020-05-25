#include <fstream>
#include <string>



int main()
{
	const std::string in_path = "rosalind_hamm.txt";
	const std::string out_path = "rosalind_hamm_OUT.txt";
	
	std::ifstream in(in_path);
	std::string seq1;
	std::string seq2;
	int count = 0;

	std::getline(in, seq1);
	std::getline(in, seq2);
	int size = seq1.size();
	for (int i = 0; i < seq1.size(); i++)
	{
		if (seq1[i] != seq2[i])
			count++;
	}

	std::ofstream out(out_path);
	out << count;
}