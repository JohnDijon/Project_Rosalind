#include <fstream>
#include <string>
#include <iostream>
#include <cassert>
#include <utility>	//for pair

bool isPalindrom(std::string str)
{
        int length = str.size();
        assert(length % 2 == 0);
        for (int i = 0; i < length; i++)
        {
                if (str[i] != str[length - i - 1])
                {
                        return false;
                }
        }
        return true;
}

int main()
{
        //file handlings
        std::string path_in = "D:\\2020year\\Code\\Project_Rosalind\\REVP\\rosalind_revp.txt";
        std::string path_out = "D:\\2020year\\Code\\Project_Rosalind\\REVP\\revp_answer.txt";
        std::string dna_seq = "";

        std::ifstream input(path_in);
        for (std::string line; std::getline(input, line);)
        {
                if (line != ">Rosalind_24")
                {
                        dna_seq.append(line);
                }
        }
        std::ofstream output(path_out);
        if (!output.is_open())
        {
                std::cerr << "open error\n";
        }


        //palindrome search
        int gap[] = {12, 10, 8, 6, 4};
        int pos_len = dna_seq.size();

        for (int cur_pos = 0; cur_pos < pos_len; cur_pos++)
        {
                for (auto i : gap)
                {
                        if (cur_pos + i <= pos_len)
                        {
                                if (isPalindrom(dna_seq.substr(cur_pos, i)))
                                {
                                        std::pair<int, int> answer = std::make_pair (cur_pos, i);
                                        output << answer.first << " " << answer.second << "\n";
                                }
                        }
                }
        }

        return 0;
}
