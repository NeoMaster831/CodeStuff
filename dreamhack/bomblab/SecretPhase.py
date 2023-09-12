l = [91, 82, 48, 80, 95, 77, 52, 68, 78, 51, 83, 83, 33, 33, 93, 0]

def find_chr(what):
    for i in range(ord('A'), ord('Z')):
        for j in range(ord('A'), ord('Z')):
            if ((i - ord('A')) << 4) + (j - ord('A')) == what:
                return ''.join([chr(i), chr(j)])
                

for i in l:
    print(find_chr(i), end='')

# B~DpC~BuBAuC|AbAbAAAtCqAqCtCsCt -> fuck
# ENFPFNDUEOCUFLBRBRAACTEQCQETESET -> fuck
# FLESCQEQFPENCUDUEOCTETETBRBRFNAA -> good gg