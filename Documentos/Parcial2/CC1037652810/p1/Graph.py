import csv
import numpy as np
import matplotlib.pyplot as plt
xpos=[]
ypos=[]
zpos=[]

with open('spiral.dat', "r") as csv_file:
    csv_reader = csv.reader(csv_file,delimiter=",")
    filacontador=0
    for row in csv_reader:
        #row=np.array(row)
        #print(row)
        if (filacontador>0 and filacontador<120):
            #according to the text file, to get the values we need to
            splitted=row[0].split()
            print(splitted)

            xpos.append(float(splitted[1]))
            ypos.append(float(splitted[2]))
            zpos.append(float(splitted[3]))

        filacontador=filacontador+1


fig = plt.figure()
ax = plt.axes(projection='3d')
#ax = plt.axes(projection='3d')

# Data for a three-dimensional line
zline = np.linspace(0, 15, 1000)
xline = np.sin(zline)
yline = np.cos(zline)

ax.plot3D(xpos, ypos, zpos, 'gray')
plt.show()


