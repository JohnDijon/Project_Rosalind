#include <fstream>
#include <string>


int main()
{
	const std::string in_path = "rosalind_revc.txt";
	const std::string out_path = "rosalind_revc_OUT.txt";
	std::ifstream in(in_path);
	
	std::string buffer = "";

	for (char ch = in.get(); in.good(); ch = in.get())
	{
		if (ch == 'A')
			buffer += 'T';
		else if (ch == 'T')
			buffer += 'A';
		else if (ch == 'C')
			buffer += 'G';
		else if (ch == 'G')
			buffer += 'C';
	}
	//revese part
	std::ofstream out(out_path);
	for (int i = buffer.size() - 1; i >= 0; i--)
	{
		out.put(buffer[i]);
	}
}