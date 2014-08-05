import matplotlib.pyplot as plt
import matplotlib.pylab as pyl
import math

def rand(x):
    x = (x<<13) ^ x;
    return ( 1.0 - ( (x * (x * x * 15731 + 789221) + 1376312589) & 0x7fffffff) / 1073741824.0);

octaves = []
total = 0
for i in range(1, 7):
    ourlist = []
    ourlist.append(.25**(i)) # amplitude
    ourlist.append((2**(i))) # frequency
    ourlist.append(128/ourlist[1]) # wavelength
    print(str(ourlist[0]) + " " + str(ourlist[1]) + " " + str(ourlist[2]))
    total = ourlist[1]
    for x in range(1, ourlist[1]):
        ourlist.append(rand(x) * ourlist[0])
    for x in range(2, ourlist[1]):
        this = ourlist[x]
        prev = ourlist[x]
        nex = ourlist[x]
        if x != 2:
            prev = ourlist[x-1]
        if x < ourlist[1]-1:
            nex = ourlist[x+1]
        ourlist[x] = this/2 + prev/4 + nex/4
    octaves.append(ourlist)

def inter(x, y, per):
    ft = per * 3.1415927
    f = (1 - math.cos(ft)) * .5
    return x * (1-f) + y*f

arr = []
for x in range(0, total):
    val = 0
    for i in range(len(octaves)):
        if (int(x / octaves[i][2]) + 3) >= len(octaves[i]):
            continue
        if int(x / octaves[i][2]) + 3 == 3:
            val += octaves[i][int(x / octaves[i][2]) + 3]
        else:
            #print((x - int(x / (octaves[i][2]*4))) / float(octaves[i][2] * 4.))
            #print("TEST " + str(1-((x % octaves[i][2]) / octaves[i][2])))
            val += inter(octaves[i][int(x / octaves[i][2]) + 2], octaves[i][int(x / octaves[i][2]) + 3], 1-((x % octaves[i][2]) / octaves[i][2]))
    arr.append(val)

#plt.fill(range(total), arr, "r")
pyl.plot(range(total), arr)
plt.grid(True)
plt.show()
