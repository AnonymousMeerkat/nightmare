import random
import math
from PIL import Image

perm = range(256)
random.shuffle(perm)
perm += perm
perm += perm
dirs = [(math.cos(a * 2.0 * math.pi / 256),
         math.sin(a * 2.0 * math.pi / 256),
         math.tan(a * 2.0 * math.pi / 256))
         for a in range(256)]

def noise(x, y, z, per):
    def surflet(gridX, gridY, gridZ):
        distX, distY, distZ = abs(x-gridX), abs(y-gridY), abs(z-gridZ)
        polyX = 1 - 6*distX**5 + 15*distX**4 - 10*distX**3
        polyY = 1 - 6*distY**5 + 15*distY**4 - 10*distY**3
        polyZ = 1 - 6*distZ**5 + 15*distZ**4 - 10*distZ**3
        hashed = perm[perm[int(gridX)%per] + perm[int(gridY)%per] + perm[int(gridZ)%per]]
        grad = (x-gridX)*dirs[hashed][0] + (y-gridY)*dirs[hashed][1] + (z-gridZ)*dirs[hashed][2]
        return polyX * polyY * polyZ * grad
    intX, intY, intZ = int(x), int(y), int(z)
    return (surflet(intX+0, intY+0, intZ+0) + surflet(intX+1, intY+0, intZ+0) +
            surflet(intX+0, intY+1, intZ+0) + surflet(intX+1, intY+1, intZ+0) +
            surflet(intX+0, intY+0, intZ+1) + surflet(intX+1, intY+0, intZ+1) +
            surflet(intX+0, intY+1, intZ+1) + surflet(intX+1, intY+1, intZ+1))

def fBm(x, y, z, per, octs):
    val = 0
    for o in range(octs):
        val += 0.5**o * noise(x*2**o, y*2**o, z*2**o, per*2**o)
    if val > 0.9:
        print val
    return val

size, freq, octs, data = 128, 1/32.0, 5, []
for z in range(size):
    data = []
    for y in range(size):
        for x in range(size):
            data.append(fBm(x*freq, y*freq, z*freq, int(size*freq), octs))
    im = Image.new("L", (size, size))
    im.putdata(data, 128, 128)
    im.save("noise" + str(z) + ".png")
    print("Generated " + str(z))
