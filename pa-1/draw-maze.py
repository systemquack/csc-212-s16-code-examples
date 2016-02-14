import Tkinter as tk
import sys

# draw all vertical walls, line by line
def draw_v_walls(canvas, dx, data, l, t):
    y = t
    for bin_str in data["v_walls"]:
        x = l + dx
        for j in range(data["n"]-1):
            if bin_str[j] == '1':
                canvas.create_line(x, y, x, y+dx)
            x += dx
        y += dx

# draw all horizontal walls, line by line
def draw_h_walls(canvas, dx, data, l, t):
    y = t + dx
    for bin_str in data["h_walls"]:
        x = l
        for j in range(data["n"]):
            if bin_str[j] == '1':
                canvas.create_line(x, y, x+dx, y)
            x += dx
        y += dx

def read_data():
    temp = []
    # read the first number from standard input
    data = {"n" : int(sys.stdin.readline())}
    # read all other lines from standard input (and transform to binary)
    for line in sys.stdin:
        temp.append([format(int(w),'08b') for w in line.split()])
    # join consecutive binary strings
    temp = ["".join(l) for l in temp]
    # extract vertical and horizontal walls
    data["v_walls"] = temp[0::2]
    data["h_walls"] = temp[1::2]
    return data

def draw_maze(canvas, data, length):
    top, left = 5, 5
    # dx is the length of each wall
    dx = (length - 5) / data["n"]
    # draw the outer square
    # (5,5) is the upper left corner
    # (length,length) is the bottom right corner
    canvas.create_rectangle(left, top, length, length)
    # draw all verticall walls
    draw_v_walls(canvas, dx, data, left, top)
    # draw all horizontal walls
    draw_h_walls(canvas, dx, data, left, top)

if __name__ == "__main__":
    root = tk.Tk()
    # capture screen dimensions (use only 85% of height)
    length = root.winfo_screenheight() * 0.85;
    # create canvas
    canvas = tk.Canvas(root, width=length, height=length)
    canvas.pack()
    # read data from standard input
    data = read_data()
    # call the drawing function
    draw_maze(canvas, data, length)
    # loops until the window is closed
    root.mainloop()
