text_in = "Pepero is a cookie stick, dipped in compound chocolate, manufactured by ????? Confectionery in South Korea\nPepero Day is held annually on November 11"
text_out = "7/OkZQIau/jou/R1by9acyjjutd0cUdlWshecQhkZUn1cUH1by9g4/9qNAn1byGaby9pbQSjWshgbUmqZAF+JtOBZUn1b8e1YoMPYoM1ny95ZAO+J/jaNAOB2vhrNLhVNDO0cshWNDIjbnrnZQhj4AM1S/Fmu/jou/GjN/n1bUm5JUFpNte1NyH1VA9yZUqLZQu13VR="
regex = "?hs?RF/tuI?W3d?YnSvV7OUQbZcN4J2?1GL+ejA8?r?lpg5ak?Bo0qyDHm??M9?P"
dict = {}
dict["="]=0
for i in range(0, 64):
    if regex[i] == '?':
        continue
    dict[regex[i]] = i

flag = "S/jeutjaJvhlNA9Du/GaJBhLbQdjd+n1Jy9BcD3="
ans = ""
for i in range(0, len(flag), 4):
    chk = flag[i:i+4]
    s = ""
    for j in range(0,4):
        vuf=bin(dict[chk[j]]).replace("0b",'')
        while len(vuf) != 6:
            vuf = "0" + vuf
        s+=vuf
    
    for j in range(0, 3):
        a = int(s[j*8:j*8+8],2)
        if a == 0:
            break
        ans += chr(a)

print(ans)

"""
outbf = 0
for i in range(0, len(text_in), 3):
    if i + 3 > len(text_in):
        le = len(text_in) - i

        last = ""
        for j in range(0, le):
            vuf = bin(ord(text_in[i+j])).replace("0b", '')
            while len(vuf) != 8:
                vuf = "0" + vuf
            last += vuf
        print(last)
        if le == 1:
            dict[int(last[0:6], 2)] = text_out[outbf]
            dict[int(last[6:8], 2)] = text_out[outbf+1]
        else:
            dict[int(last[0:6], 2)] = text_out[outbf]
            dict[int(last[6:12], 2)] = text_out[outbf+1]
            dict[int(last[12:16], 2)] = text_out[outbf+2]
        break
    s = ""
    for j in range(0, 3):
        vuf = bin(ord(text_in[i+j])).replace("0b", '')
        while len(vuf) != 8:
            vuf = "0" + vuf
        s += vuf
    for j in range(0, 4):
        spl = s[j*6:j*6+6]
        k = int(spl, 2)
        dict[k] = text_out[j+outbf]
    outbf += 4

for i in range(0, 64):
    if dict.get(i) == None:
        print("?", end='')
        continue
    print(dict[i], end='')
"""