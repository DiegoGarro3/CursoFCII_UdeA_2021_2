
import numpy as np
import matplotlib.pyplot as plt

datos = []

with open("DatosXposYpos.txt") as fname:
	for lineas in fname:
		datos.append(lineas.split())

Datos=np.array(datos[1:])

Xpos=Datos[:,1].astype(float)
Ypos=Datos[:,2].astype(float)

plt.figure(figsize=(6,6))
plt.plot(Xpos,Ypos,label="Radio = 1.5 \ndt = 0.1 \nT final = 3.2 \nOmega = 2 \nFase = Pi/4")
plt.title("X(t) vs Y(t)")
plt.xlabel("Xpos(t)")
plt.ylabel("Ypos(t)")
plt.legend()
plt.savefig("Circulo.jpg")
plt.show()

datos = []

with open("DatosXposYposZpos.txt") as fname:
	for lineas in fname:
		datos.append(lineas.split())

Datos=np.array(datos[1:])

Xpos=Datos[:,1].astype(float)
Ypos=Datos[:,2].astype(float)
Zpos=Datos[:,3].astype(float)

#plt.figure(figsize=(6,6))
fig = plt.figure(figsize=(10,8))
ax = plt.axes(projection ='3d')
ax.plot(Xpos, Ypos, Zpos,"b", label="Radio = 1.5 \ndt = 0.1 \nT final = 3.2 \nOmega = 2 \nFase = Pi/4 \nZ_o = 0.5 \nV_z = 2.1") 
ax.set_title("X(t) vs Y(t) vs Z(t)")
ax.set_xlabel("Xpos(t)")
ax.set_ylabel("Ypos(t)")
ax.set_zlabel("Zpos(t)")
plt.legend()
plt.savefig("Espiral.jpg")
plt.show()

