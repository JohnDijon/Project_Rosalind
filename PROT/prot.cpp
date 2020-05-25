//date: 5/22/2020

#include <fstream>
#include <iostream>
#include <string>
#include <map>


int main()
{
	const std::string in_path = "rosalind_prot.txt";
	const std::string out_path = "OUT_rosalind_prot.txt";
	const std::string condons_path = "Codons.txt";
	
	//loading codons
	std::ifstream in_codons(condons_path);
	std::map<std::string, std::string> codons;
	while(in_codons.good())
	{
		std::string buffer_RNA;
		std::string buffer_AA;
		in_codons >> buffer_RNA >> buffer_AA;
		codons[buffer_RNA] = buffer_AA;
	}
	//mRNA -> protein	
	std::ifstream in(in_path);
	std::string RNA_seq;
	std::string sub_RNA_seq;
	std::string Protein_seq;
	std::getline(in, RNA_seq);
	int counter = 0;
	for (int i = 0; i < RNA_seq.size(); i++)
	{
		if (counter == 3)
		{
			if (codons[sub_RNA_seq] == "Stop")
			{
				break;
			}
			else
			{
				Protein_seq += codons[sub_RNA_seq];
				sub_RNA_seq.clear();
				counter = 0;
			}
		} 
		sub_RNA_seq += RNA_seq[i];
		counter++;
	}
	
	std::ofstream out(out_path);
	out << Protein_seq;
}


