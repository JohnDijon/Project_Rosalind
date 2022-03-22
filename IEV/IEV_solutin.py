def calculate_average(data):
    probability_mask = {1: 1, 2: 1, 3: 1, 4: 0.75, 5: 0.5, 6: 0}  # probability of a dominant offspring
    offsprings = 0
    for i, num in enumerate(data):
        offsprings += 2 * int(num) * probability_mask[i+1]
    return offsprings


def IEV(in_file):
    with open(in_file) as f:
        dataset = f.readline().strip().split()

    with open(r'out_file.txt', 'w') as f:
        f.write(str(calculate_average(dataset)))


if __name__ == '__main__':
    file_path = r'./rosalind_iev.txt'
    IEV(file_path)
