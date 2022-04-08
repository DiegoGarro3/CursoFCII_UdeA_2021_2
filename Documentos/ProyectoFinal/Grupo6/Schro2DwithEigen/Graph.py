import csv
import numpy as np
import matplotlib.pyplot as plt
from matplotlib.animation import FuncAnimation
from matplotlib.patches import Rectangle

allpsi=[]
x3pos=[]
x4pos=[]
x5pos=[]
rowpos=[]
psimatrix=[]

with open('Solution1.dat', "r") as csv_file:
    csv_reader = csv.reader(csv_file,delimiter=",")
    filacontador=0
    for row in csv_reader:
        #row=np.array(row)
        #print(row)
        if (filacontador>=0 and filacontador<30000):
            #according to the text file, to get the values we need to
            splitted=row[0].split()
            #print(np.array(splitted))
            #print(splitted[0])
            if (str(splitted[0])=="nextt"):
                allpsi.append(psimatrix)
                print(psimatrix)
                psimatrix=[]

            else:
                xpos=[]
                for sp in splitted:          
                    xpos.append(float(sp))

                #xpos.append(float(splitted[4]))
                #print(xpos)
                psimatrix.append(xpos)
                #zpos.append(float(splitted[3]))



        filacontador=filacontador+1


"""
def f(x):
  return np.exp(2)*(np.exp(4)-1)**-1*(np.exp(2*x)-np.exp(-2*x))+x
xx=np.arange(0,1,0.001)
fig = plt.figure()
#ax = plt.axes(projection='3d')
#ax = plt.axes(projection='3d')
"""
"""
# Data for a three-dimensional line
zline = np.linspace(0, 15, 1000)
xline = np.sin(zline)
#yline = np.cos(zline)
"""
"""
plt.plot(xpos, ypos, 'r-.', label="Finite Difference Aprox")
plt.plot(xx, f(xx), 'gray', label = "Analytical Solution" )
plt.xlabel("x")
plt.ylabel("y(x)")
plt.legend()
plt.grid()
plt.show()
"""
"""
# Data for three-dimensional scattered points
zdata = 15 * np.random.random(100)
xdata = np.sin(zdata) + 0.1 * np.random.randn(100)
ydata = np.cos(zdata) + 0.1 * np.random.randn(100)
ax.scatter3D(xdata, ydata, zdata, c=zdata, cmap='Greens');
"""
L = 8. # Well of width L. Shafts from 0 to +L.
Dy =0.1 # Spatial step size.
Dt = Dy**2/4. # Temporal step size.
Nx = int(L/Dy) + 1 # Number of points on the x axis.
Ny = int(L/Dy) + 1 # Number of points on the y axis.
Nt = 200 # Number of time steps.
rx = -Dt/(2j*Dy**2) # Constant to simplify expressions.
ry = -Dt/(2j*Dy**2) # Constant to simplify expressions.

# Initial position of the center of the Gaussian wave function.
x0 = L/5.
y0 = L/2.

# Parameters of the double slit.
w = 0.2 # Width of the walls of the double slit.
s = 0.6 # Separation between the edges of the slits.
a = 0.3 # Aperture of the slits.

# Indices that parameterize the double slit in the space of points.
# Horizontal axis.
j0 = int(1/(2*Dy)*(L-w)) # Left edge.
j1 = int(1/(2*Dy)*(L+w)) # Right edge.
# Eje vertical.
i0 = int(1/(2*Dy)*(L+s) + a/Dy) # Lower edge of the lower slit.
i1 = int(1/(2*Dy)*(L+s))        # Upper edge of the lower slit.
i2 = int(1/(2*Dy)*(L-s))        # Lower edge of the upper slit.
i3 = int(1/(2*Dy)*(L-s) - a/Dy) # Upper edge of the upper slit.


v = np.zeros((Ny,Ny), complex) # Potential.

Ni = (Nx-2)*(Ny-2)  # Number of unknown factors v[i,j], i = 1,...,Nx-2, j = 1,...,Ny-2


# =============================================================================
# Third step: We make the animation.
# =============================================================================
#L=6.
fig = plt.figure() # We create the figure.
ax = fig.add_subplot(111, xlim=(0,L), ylim=(0,L)) # We add the subplot to the figure.

img = ax.imshow(allpsi[0], extent=[0,L,0,L], cmap=plt.get_cmap("hot"), vmin=0, vmax=np.max(allpsi), zorder=1, interpolation="none") # Here the modulus of the 2D wave function shall be represented.

# We paint the walls of the double slit with rectangles.
wall_bottom = Rectangle((j0*Dy,0),     w, i3*Dy,      color="w", zorder=50) # (x0, y0), width, height
wall_middle = Rectangle((j0*Dy,i2*Dy), w, (i1-i2)*Dy, color="w", zorder=50)
wall_top    = Rectangle((j0*Dy,i0*Dy), w, i3*Dy,      color="w", zorder=50)

# We add the rectangular patches to the plot.
ax.add_patch(wall_bottom)
ax.add_patch(wall_middle)
ax.add_patch(wall_top)

# We define the animation function for FuncAnimation.

def animate(i):
    
    """
    Animation function. Paints each frame. Function for Matplotlib's 
    FuncAnimation.
    """
    print(i)
    img.set_data(allpsi[i]) # Fill img with the modulus data of the wave function.
    img.set_zorder(1)
    
    return img, # We return the result ready to use with blit=True.


anim = FuncAnimation(fig, animate, interval=100, frames=np.arange(0,Nt,2), repeat=True, blit=0) # We generate the animation.

cbar = fig.colorbar(img)
plt.show() # We show the animation finally.

## Save the animation (Ubuntu).
anim.save('./SchrodingerSlitdiag.gif', writer='imagemagick')
