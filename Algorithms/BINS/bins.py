def bin_search(arr, k):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right)//2
        if arr[mid] == k:
            return mid + 1  # the indexes in the task start with 1
        elif arr[mid] < k:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == '__main__':
    in_path = r'./rosalind_bins.txt'
    out_path = r'./bins_out.txt'
    with open(in_path) as f:
        n = int(f.readline())   # array size
        m = int(f.readline())   # search array size
        in_arr = [int(i) for i in f.readline().split()]     # sorted array
        k_arr = [int(i) for i in f.readline().split()]  # array to search

    with open(out_path, 'w') as f:
        for k in k_arr:
            f.write(str(bin_search(in_arr, k)) + ' ')