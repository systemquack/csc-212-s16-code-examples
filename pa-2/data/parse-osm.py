import re
import sys

def printInfo(node):
    info = {"name":"", "amenity":""}
    keys = ["lat", "lon", "k"]
    if len(node) > 1:
        for line in node:
            for w in keys:
                match = re.search(w+"=\".*?\"", line)
                if match:
                    val = re.sub(w+"=|\"", "", match.group())
                    if w == "k":
                        info[val] = re.sub("v=|\"","",re.search("v=\".*?\"", line).group())
                    else:
                        info[w] = val
        # print values
        print info["lat"], info["lon"], info["name"].lower().replace('"',' '), "-", info["amenity"].lower().replace('"',' ')

with open(sys.argv[1], "rt") as fid:
    node = []
    for line in fid:
        line = line.strip()
        # found start node
        if line.startswith("<node"):
            if not line.endswith("/>"):
                line = line.replace(" ", "")
                node = [line]
        # found end node
        elif line.startswith("</node"):
            printInfo(node)
            node = []
        # found a tag
        elif node:
            if line.startswith("<tag"):
                line = line.replace(" ", "")
                if 'k="name"' in line or 'k="amenity"' in line:
                    node.append(line)
