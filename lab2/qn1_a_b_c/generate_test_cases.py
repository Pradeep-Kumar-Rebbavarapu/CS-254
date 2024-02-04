import random

def generate_large_test_case(arr1_size, arr2_size, filename):
    with open(filename, 'w') as file:
        file.write(f"{arr1_size} {arr2_size}\n")

      
        row_data = sorted([str(random.randint(1, 1000000)) for _ in range(arr1_size)])
        file.write(' '.join(row_data) + '\n')

        
        row_data = sorted([str(random.randint(1, 1000000)) for _ in range(arr2_size)])
        file.write(' '.join(row_data) + '\n')

    print(f'Test case generated and saved to {filename}.')

arr1_size = 10000000
arr2_size = 10000000
filename = './input.txt'

generate_large_test_case(arr1_size, arr2_size, filename)
