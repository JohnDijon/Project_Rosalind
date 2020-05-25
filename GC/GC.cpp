//date: 5/20/2020

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


struct SeqPair 
{
	float gc;
	std::string name = "";
	std::string sequence = "";

	SeqPair(std::string& fasta_name) : gc(0)
	{	//excude ">"
		for (int i = 1; i < fasta_name.size(); i++)
		{
			name += fasta_name[i];
		}
	}
	void gc_content()
	{
		if (sequence.size() != 0)
		{
			int gc_counter = 0;
			for (auto& ch : sequence)
			{
				if (ch == 'G' || ch == 'C')
					gc_counter++;
			}
			gc = (float)gc_counter * 100.0f / sequence.size();
		}
	}

	bool operator>(const SeqPair& rhs)
	{
		return gc > rhs.gc;
	}
	bool operator>=(const SeqPair& rhs)
	{
		return gc >= rhs.gc;
	}
	bool operator<(const SeqPair& rhs)
	{
		return gc < rhs.gc;
	}
	bool operator<=(const SeqPair& rhs)
	{
		return gc <= rhs.gc;
	}
	bool operator==(const SeqPair& rhs)
	{
		return gc == rhs.gc;
	}
};

int main()
{
	const std::string in_path = "rosalind_gc.txt";
	const std::string out_path = "OUT_rosalind_gc.txt";
	
	std::ifstream in(in_path);

	std::vector<SeqPair> DNA_sequences;
	int seq_number = 0;
	//parsing the txt file
	for (std::string buffer; std::getline(in, buffer);)
	{
		if (buffer[0] == '>')
		{
			DNA_sequences.emplace_back(buffer);
			seq_number++;
		}
		else
		{
			DNA_sequences[seq_number - 1].sequence += buffer;
		}
	}
	//GC content calc
	for (auto& seq : DNA_sequences)
	{
		seq.gc_content();
	}
	//sort by GC content
	std::sort(DNA_sequences.begin(), DNA_sequences.end());// , std::greater<SeqPair>());

	std::ofstream out(out_path);
	out << DNA_sequences[seq_number -1].name << "\n" << DNA_sequences[seq_number-1].gc;
}


