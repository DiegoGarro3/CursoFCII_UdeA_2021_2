import csv
import numpy as np
import matplotlib.pyplot as plt
xpos=[]
ypos=[]
zpos=[]

with open('SolutionDifEq.dat', "r") as csv_file:
    csv_reader = csv.reader(csv_file,delimiter=",")
    filacontador=0
    for row in csv_reader:
        #row=np.array(row)
        #print(row)
        if (filacontador>0 and filacontador<120):
            #according to the text file, to get the values we need to
            splitted=row[0].split()
            print(splitted)

            xpos.append(float(splitted[0]))
            ypos.append(float(splitted[1]))
            #zpos.append(float(splitted[3]))

        filacontador=filacontador+1

def f(x):
  return np.exp(2)*(np.exp(4)-1)**-1*(np.exp(2*x)-np.exp(-2*x))+x
xx=np.arange(0,1,0.001)
fig = plt.figure()
#ax = plt.axes(projection='3d')
#ax = plt.axes(projection='3d')
"""
# Data for a three-dimensional line
zline = np.linspace(0, 15, 1000)
xline = np.sin(zline)
#yline = np.cos(zline)
"""
plt.plot(xpos, ypos, 'r-.', label="Finite Difference Aprox")
plt.plot(xx, f(xx), 'gray', label = "Analytical Solution" )
plt.xlabel("x")
plt.ylabel("y(x)")
plt.legend()
plt.grid()
plt.show()
"""
# Data for three-dimensional scattered points
zdata = 15 * np.random.random(100)
xdata = np.sin(zdata) + 0.1 * np.random.randn(100)
ydata = np.cos(zdata) + 0.1 * np.random.randn(100)
ax.scatter3D(xdata, ydata, zdata, c=zdata, cmap='Greens');
"""

