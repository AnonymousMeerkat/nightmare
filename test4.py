import random
from PIL import Image

width = 256
height = 256
values = [0] * (width * height)
output = [0] * (width * height)

def frand():
    return random.uniform(-1, 1)

def calcpos(x, y):
    return (x & (width - 1)) + (y & (height - 1)) * width

def sample(x, y):
    return values[calcpos(x, y)]

def set_pixel(x, y, val):
    output[calcpos(x, y)] = val

def smooth_noise(x, y):
    corners = (sample(x - 1, y - 1) + sample(x + 1, y - 1) +
               sample(x - 1, y + 1) + sample(x + 1, y + 1)) / 16
    sides =   (sample(x - 1, y)     + sample(x + 1, y)
               sample(x, y - 1)     + sample(x, y + 1)) / 8
    center = sample(x, y) / 4
    return corners + sides + center

def inter_noise(x, y):
    x_int = int(x)
    x_fract = x - x_int

    y_int = int(y)
    y_fract = y - y_int
