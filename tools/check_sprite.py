import os

def compare_bin_files(file1, file2):
    with open(file1, 'rb') as f1, open(file2, 'rb') as f2:
        data1 = f1.read()
        data2 = f2.read()

        if data1 == data2:
            return None  # No differences

        # Find differences
        differences = []
        min_len = min(len(data1), len(data2))
        for i in range(min_len):
            if data1[i] != data2[i]:
                differences.append((i, data1[i], data2[i]))

        # If lengths are different, capture the extra bytes
        if len(data1) != len(data2):
            longer_data = data1 if len(data1) > len(data2) else data2
            differences.extend(
                (i, longer_data[i], None if len(data1) > len(data2) else longer_data[i])
                for i in range(min_len, len(longer_data))
            )

        return differences

def find_and_compare():

    script_dir = os.path.dirname(os.path.realpath(__file__))
    root_dir = os.path.join(script_dir, "..")

    dir1 = os.path.join(root_dir, 'ver', 'us', 'expected', 'ver', 'us', 'build', 'assets', 'us', 'sprite', 'npc')
    dir2 = os.path.join(root_dir, 'ver', 'us', 'build', 'assets', 'us', 'sprite', 'npc')

    # Create sets of file names in each directory
    files1 = {f for f in os.listdir(dir1) if f.endswith('.bin')}
    files2 = {f for f in os.listdir(dir2) if f.endswith('.bin')}

    # Find matching file names
    common_files = files1 & files2

    for file_name in common_files:
        file1 = os.path.join(dir1, file_name)
        file2 = os.path.join(dir2, file_name)

        print(f"Comparing: {file_name}")
        differences = compare_bin_files(file1, file2)
        if differences:
            print(f"Differences found in {file_name}:")
            for offset, byte1, byte2 in differences[:10]:  # Limit to first 10 differences
                print(f"  Offset {offset}: {byte1:#04x} -> {byte2:#04x}")
            if len(differences) > 10:
                print(f"  ...and {len(differences) - 10} more differences.")
        else:
            print(f"No differences in {file_name}")

if __name__ == "__main__":
    find_and_compare()
