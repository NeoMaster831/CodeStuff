a,b,c,d = map(int,input().split())
e,f,g,h = map(int,input().split())


def f1(x):
    if a==c:
        return False
    else:
      return ((b-d)/(a-c))*(x-a)+b
def f2(x):
   if e == g:
       return False
   return ((f-h)/(e-g))*(x-e)+f


if(f1(123123)==False and f2(123123)==False):
    if(a==e):
        print(1)
    else:
        print(0)

elif((a<=e<=c)and(a<=g<=c))or((c<=e<=a)and(c<=g<=a)and f2(123123)==True and f1(123123) == True):

    if(f1(e)>= f2(e))and(f1(g)<=f2(g)):
        print(1)
    elif(f1(e)<= f2(e))and(f1(g)>=f2(g)):
        print(1)
    else:
        print(0)
elif(f2(123123)==False):
    if(f<=f1(e)<=h)or(h<=f1(e)<=f) and ((a<=e<=c or c<=e<=a)):
        print(1)
    else:
        print(0)
elif(f1(123123)==False):
    if(b<=f2(a)<=d)or(d<=f2(a)<=b) and(e<=a<=g or g<=a <= e):
        print(1)
    else:
        print(0)
elif(a>e and a>g and c>e and c>g)or(a<e and a<g and c<e and c<g):
    print(0)







else:
    if(f1(a)>= f2(a))and(f1(b)<=f2(b)):
        print(1)
    elif(f1(a)<= f2(a))and(f1(b)>=f2(b)):
        print(1)
    else:
        print(0)