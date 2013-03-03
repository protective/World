import Image, ImageDraw, os

effects =["Icons/Armor","Icons/Mechanical"]

f = open("../../../Server/database/itemtexname.txt", 'w')

i = 0
for j in effects:
	if(not i):
		f.write("if (str.find(\"" + j + "\")!= string::npos)\n")
		f.write("return " + str(i+1) + ";\n")
	else:
		f.write("else if (str.find(\"" + j + "\")!= string::npos)\n")
		f.write("return " + str(i+1) + ";\n")
	i += 1


im = Image.open("0001.png")

im = im.resize((1024,1024))
hight = 0

i = -1
k = 0
idc = 0




im = Image.open("0001.png")

im = im.resize((1024,1024))
hight = 0

f = open("iconcords.txt", 'w')

i = -1
k = 0
idc = 0
for j in effects:
	i += 1
	idc += 1
	s = "" + j + "/itempic0001.png"
	pasteim = Image.open(s)
	size = pasteim.size
	if (i == 20):
		i = 0
		k += 1

	im.paste(pasteim,(40*(i), (40*k)))


	f.write("case " + str(idc) + ":{\n")
	f.write("\tglBindTexture( GL_TEXTURE_2D, textures[Textures::Icons1]);\n")
	f.write("\tuvx1 = "+ str(40 * (i)) + ";\n")
	f.write("\tuvy1 = "+ str(40 * k) + ";\n")
	f.write("\tbreak;\n")
	f.write("}\n")



hight += size[1]

# write to stdout
im.save("iconsheet.png", "PNG")










