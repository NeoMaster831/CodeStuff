N = int(input())
names = []
for i in range(N):
    names.append(input())

cnt = 0
for i in range(N):
    for j in range(i + 1, N):
        #print("씨발",j)
        for k in range(len(names[i])):
            sliced = names[i][0:k + 1]
            #print(names[j].find(sliced), i, j, k)
            if names[j].find(sliced) + k == len(names[j]):
                cnt += 1
                #print(1)
                break
            sliced = names[i][k:len(names[i])]
            if names[j].find(sliced) == 0:
                cnt += 1
                #print(1)
                break

print(cnt)