from PIL import Image, ImageDraw
import random

# Create a new image with the specified dimensions
width, height = 1920, 1080
img = Image.new('RGB', (width, height), color = 'black')
draw = ImageDraw.Draw(img)
# Draw random neon lines
for _ in range(100):
    x1, y1 = random.randint(0, width), random.randint(0, height)
    x2, y2 = random.randint(0, width), random.randint(0, height)
    color = random.choice([(255, 0, 255), (0, 255, 255), (0, 255, 0)])
    draw.line([(x1, y1), (x2, y2)], fill=color, width=2)

for _ in range(500):
    x, y = random.randint(0, width), random.randint(0, height)
    color = random.choice([(255, 0, 255), (0, 255, 255), (0, 255, 0)])
    draw.ellipse([(x-1, y-1), (x+1, y+1)], fill=color)

# Save the image
img.save('cyberpunk_wallpaper.png')
