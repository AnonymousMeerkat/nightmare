import random
from PIL import Image

width = 256
height = 256
breadth = 8
values = [0] * (width * height * breadth)

def drange(start, stop, step):
    numelements = int((stop-start)/float(step))
    for i in range(numelements+1):
            yield start + i*step

def frand():
    return random.uniform(-1, 1)

def sample(x, y, z):
    return values[(x & (width - 1)) + (y & (height - 1)) * width + (z & (breadth - 1)) * width * height]

def set_sample(x, y, z, val):
    values[(x & (width - 1)) + (y & (height - 1)) * width + (z & (breadth - 1)) * width * height] = val

featuresize = 16

for z in drange(0, breadth, featuresize):
    for y in drange(0, height, featuresize):
        for x in drange(0, width, featuresize):
            set_sample(x, y, z, frand())

def sample_square(x, y, z, size, val):
    hs = size / 2

    a = sample(x - hs, y - hs, z - hs)
    b = sample(x + hs, y - hs, z - hs)
    c = sample(x - hs, y + hs, z - hs)
    d = sample(x + hs, y + hs, z - hs)
    e = sample(x - hs, y - hs, z + hs)
    f = sample(x + hs, y - hs, z + hs)
    g = sample(x - hs, y + hs, z + hs)
    h = sample(x + hs, y + hs, z + hs)

    set_sample(x, y, z, ((a + b + c + d + e + f + g + h) / 8.) + val)

def sample_diamond(x, y, z, size, val):
    hs = size / 2

    a = sample(x - hs, y, z)
    b = sample(x + hs, y, z)
    c = sample(x, y - hs, z)
    d = sample(x, y + hs, z)
    e = sample(x, y, z - hs)
    f = sample(x, y, z + hs)


    set_sample(x, y, z, ((a + b + c + d + e + f) / 6.) + val)


def diamond_square(stepsize, scale):
    halfstep = stepsize / 2

    for z in drange(halfstep, breadth + halfstep, stepsize):
        for y in drange(halfstep, height + halfstep, stepsize):
            for x in drange(halfstep, width + halfstep, stepsize):
                sample_square(x, y, z, stepsize, frand() * scale)

    for z in drange(0, breadth, stepsize):
        for y in drange(0, height, stepsize):
            for x in drange(0, width, stepsize):
                sample_diamond(x + halfstep, y, z, stepsize, frand() * scale)
                sample_diamond(x, y + halfstep, z, stepsize, frand() * scale)
                sample_diamond(x, y, z + halfstep, stepsize, frand() * scale)

samplesize = featuresize
scale = 1.

while samplesize > 1:
    diamond_square(samplesize, scale)
    print("Done samplesize " + str(samplesize))

    samplesize /= 2
    scale /= 2.

for z in range(breadth):
    im = Image.new("L", (width, height))
    im.putdata(values[width * height * z:width * height * (z + 1)], width, height)
    im.save("noise" + str(z) + ".png")
    print("Generated " + str(z))
