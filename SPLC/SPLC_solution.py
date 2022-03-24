def trim_string(main_string, substrings):
    for substr in substrings:
        main_string = re.sub(substr, '', main_string)
    return main_string


def protein_expression(dna_string):
    from Bio.Seq import Seq
    coding_dna = Seq(dna_string)
    return str(coding_dna.translate()).strip('*')


def splc(in_file):
    with open(in_file) as f:
        split_pattern = r'>Rosalind_\d+'
        file_str = f.read().strip(r'\n')
        strings = [i.replace('\n', '') for i in re.split(split_pattern, file_str)]
        print(strings)

    with open(r'SPLC/out_file.txt', 'w') as f:
        f.write(protein_expression(trim_string(strings[1], strings[2:])))


if __name__ == '__main__':
    import re
    file_path = r'./SPLC/rosalind_splc.txt'
    splc(file_path)
