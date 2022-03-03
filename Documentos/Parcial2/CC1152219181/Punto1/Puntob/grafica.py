import matplotlib.pyplot as plt
import numpy as np


datos = np.loadtxt("Motion3d.dat", skiprows=1)


x=[x[0] for x in datos]
y=[x[1] for x in datos]
z=[x[2] for x in datos]


fig = plt.figure()
ax = fig.gca(projection='3d')


ax.set_title('Spiral')
ax.set_xlabel('x')
ax.set_ylabel('y')
ax.set_zlabel('z')
ax.plot(x, y, z)

plt.savefig("spiral_image.png")




