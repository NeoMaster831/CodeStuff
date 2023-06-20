data = []
with open("secretMessage.enc", "rb") as file:
	data = file.read()

with open("ans.bin", "wb") as file:
    last_chr = -1
    flagged = False
    for i in range(0, len(data)):
        now = data[i].to_bytes(1, "big")
        #print(now)
        if data[i] == last_chr:
            nxt = data[i+1]
            print(nxt)
            for j in range(0, nxt+1):
                file.write(now)
            last_chr=-1
            flagged = True
        elif not flagged:
            file.write(now)
            last_chr = data[i]
        else:
            flagged = False 

print("Done!")
