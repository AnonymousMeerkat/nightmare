from PIL import Image
import sys

im = Image.new("L", (256, 256))
c = 0

with open(sys.argv[1], "rb") as f:
    f.read(8)
    byte = f.read(1)
    while c < 65536:
        #print(c)
        im.putpixel((c % 256, int(c / 256)), ord(byte))
        byte = f.read(1)
        c = c + 1

im.save("fog.png")
