a,b,c,d = map(int,input().split())
e,f,g,h = map(int,input().split())


def f1(x):
    if a==c:
        k = '직선'
        return k
    else:
      return ((b-d)/(a-c))*(x-a)+b
def f2(x):
   if e == g:
       k = '직선'
       return k
   return ((f-h)/(e-g))*(x-e)+f


if(f1(12312113)=='직선' and f2(12113123)=='직선'):
    if(a==e):
        if b<=h<=d or d<=h<=b or b<= f<=d or d<=f <= b or f<=b<=h or f<=d<=h or h<=b<=f or h<=d<=f:
            print(1)
        else:
            print(0)
    else:
        print(0)
elif(f2(12311123)=='직선'):
    if((f<=f1(e)<=h)or(h<=f1(e)<=f)) and ((a<=e<=c) or (c<=e<=a)):
        print(1)
    else:
        print(0)
elif(f1(12311123)=='직선'):
    if((b<=f2(a)<=d)or(d<=f2(a)<=b)) and (e<=a<=g) or (g<=a<= e):
        print(1)
    else:
        print(0)

elif((a<=e<=c)and(a<=g<=c))or((c<=e<=a)and(c<=g<=a)):

    if(f1(e)>= f2(e))and(f1(g)<=f2(g)):
        print(1)
    elif(f1(e)<= f2(e))and(f1(g)>=f2(g)):
        print(1)
    else:
        print(0)
elif(g<=a<=e<=c):
    if ((f2(a)>=f1(a)) and (f2(e)<=f1(e)))or((f2(a)<=f1(a)) and (f2(e)>=f1(e))):
        print(1)
    else:
        print(0)
elif(e<=c<=g<=a):
    if(f2(c)>=f1(c) and f1(g)<=f2(g))or(f2(c)<=f1(c) and f1(g)>=f2(g)):
        print(1)
    else:
        print(0)
elif(e<=a<=g<=c):
    if(f2(a)>=f1(a) and f2(g)<=f1(g)) or (f2(a)<=f1(a) and f2(g)>=f1(g)):
        print(1)
    else:
        print(0)
elif(a<=g<=c<=e):
    if(f2(g)>=f1(g) and f2(c)<= f1(c)) or (f2(g)<=f1(g) and f2(c)>= f1(c)):
        print(1)
    else:
        print(0)

elif(g<=c<=e<=a):
    if ((f2(c)>=f1(c)) and (f2(e)<=f1(e)))or((f2(c)<=f1(c)) and (f2(e)>=f1(e))):
        print(1)
    else:
        print(0)
elif(e<=a<=g<=c):
    if(f2(a)>=f1(a) and f1(g)<=f2(g))or(f2(a)<=f1(a) and f1(g)>=f2(g)):
        print(1)
    else:
        print(0)
elif(e<=c<=g<=a):
    if(f2(c)>=f1(c) and f2(g)<=f1(g)) or (f2(c)<=f1(c) and f2(g)>=f1(g)):
        print(1)
    else:
        print(0)
elif(c<=g<=a<=e):
    if(f2(g)>=f1(g) and f2(a)<= f1(a)) or (f2(g)<=f1(g) and f2(a)>= f1(a)):
        print(1)
    else:
        print(0)




elif(e>a and e>c and g>a and g>c)or(e<a and e<c and g<a and g<c):
    print(0)

else:
    if(f1(a)>= f2(a))and(f1(c)<=f2(c)):
        print(1)
    elif(f1(a)<= f2(a))and(f1(c)>=f2(c)):
        print(1)
    else:
        print(0)