import random
from PIL import Image
import math

width = 256
height = 256
frequency = 16
values = [0] * (width * height)
output = [0] * (width * height)

#random.seed(0)

def frand():
    return random.uniform(-1, 1)

def calcpos(x, y, c):
    return (x & ((width/c) - 1)) + (y & ((height/c) - 1)) * width

def sample(x, y, c):
    return values[calcpos(x, y, c)]

def ssample(x, y, c):
    corners = (sample(x-1, y-1, c) + sample(x+1, y-1, c) +
               sample(x-1, y+1, c) + sample(x+1, y+1, c)) / 16
    sides = (sample(x-1, y, c) + sample(x+1, y, c) +
             sample(x, y-1, c) + sample(x, y+1, c)) / 8
    center = sample(x, y, c) / 3

    return corners + sides + center

def set_sample(x, y, val):
    values[calcpos(x, y, 1)] = val

def set_pixel(x, y, val):
    output[calcpos(x, y, 1)] = val

def linter(n, n1, t):
    return n * (1. - t) + n1 * t

def cosinter(n, n1, t):
    ft = t * 3.1415927
    f = (1 - math.cos(ft)) * .5

    return n * (1. - f) + n1 * t

def inter(n, n1, t):
    return linter(n, n1, t)

def biinter(n00, n10, n01, n11, tx, ty):
    a = inter(n00, n10, tx)
    b = inter(n01, n11, tx)
    return inter(a, b, ty)

def init():
    for y in range(height):
        for x in range(width):
            set_sample(x, y, frand())

init()

def noise(x, y):
    pixel = 0
    curr = frequency
    scale = 1.
    while curr > 1:
        x_fract = float(x) / float(curr)
        x_int = int(x_fract)
        x_diff = x_fract - x_int

        y_fract = float(y) / float(curr)
        y_int = int(y_fract)
        y_diff = y_fract - y_int

        pixel = pixel + biinter(ssample(x_int, y_int, curr), ssample(x_int + 1, y_int, curr),
                                ssample(x_int, y_int + 1, curr), ssample(x_int + 1, y_int + 1, curr),
                                    x_diff, y_diff) * scale

        curr = curr >> 1
        scale = scale / 2.
    return int((pixel + 1) * 128)

im = Image.new("L", (width, height))

for y in range(height):
    for x in range(width):
        calc = noise(x, y)
        im.putpixel((x, y), calc)

im.save("noise_thingy.png")
