import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit


datos=np.loadtxt("Paramagnetismo3.000000.dat")
x=[x[0] for x in datos ]
y=[x[1] for x in datos ]

datos1=np.loadtxt("Paramagnetismo20.000000.dat")
y1=[x[1] for x in datos1 ]

datos2=np.loadtxt("Paramagnetismo80.000000.dat")
y2=[x[1] for x in datos2 ]

x=np.array(x)
y1=np.array(y1)
y2=np.array(y2)


#funcion de ajuste
def func(H,a,b):
  return a*np.tanh(b*H) 

popt, _ = curve_fit(func,x,y ) #ajuste para T=3
popt2, _ = curve_fit(func,x,y1 ) #ajuste para T=20
popt3, _ = curve_fit(func,x,y2 ) #ajuste para T=80

#Graficas
fig, axs = plt.subplots(2, 2, figsize=(10,8))

#H vs M/N para diferentes T
axs[0, 0].plot(x,y,"o",label ="T=3")
axs[0, 0].plot(x,y1,"o",label ="T=20")
axs[0, 0].plot(x,y2,"o",label ="T=80")
axs[0, 0].set_title('Curvas magnetización')
axs[0, 0].set_xlabel("H")
axs[0, 0].set_ylabel("M / N")
axs[0, 0].legend()
axs[0, 0].grid()

#H vs M/N Y  ajuste para T=3
axs[0, 1].plot(x,y, "o", label="Montecarlo")
axs[0, 1].plot(x,func(x,*popt),"r",label="Ajuste")
axs[0, 1].set_title('Ajuste para T=3')
axs[0, 1].plot(0,0, "w",label ="a={} y b ={}".format(np.round(popt[0],3),np.round(popt[1],3)))
axs[0, 1].set_xlabel("H")
axs[0, 1].set_ylabel("M / N")
axs[0, 1].legend()
axs[0, 1].grid()

#H vs M/N Y  ajuste para T=15
axs[1, 0].plot(x,y1,"o", label="Montecarlo")
axs[1, 0].plot(x,func(x,*popt2),"r",label="Ajuste")
axs[1, 0].set_title('Ajuste para T=20')
axs[1, 0].plot(0,0, "w",label ="a={} y b ={}".format(np.round(popt2[0],3),np.round(popt2[1],3)))
axs[1, 0].set_xlabel("H")
axs[1, 0].set_ylabel("M / N")
axs[1, 0].legend()
axs[1, 0].grid()

#H vs M/N Y  ajuste para T=80
axs[1, 1].plot(x,y2,"o", label="Montecarlo")
axs[1, 1].plot(x,func(x,*popt3),"r",label="Ajuste")
axs[1, 1].set_title('Ajuste para T=80')
axs[1, 1].plot(0,0, "w",label ="a={} y b ={}".format(np.round(popt3[0],3),np.round(popt3[1],3)))
axs[1, 1].set_xlabel("H")
axs[1, 1].set_ylabel("M / N")
axs[1, 1].legend()
axs[1, 1].grid()

plt.tight_layout()
plt.legend()
plt.savefig("Figure_1.png")
plt.show()
