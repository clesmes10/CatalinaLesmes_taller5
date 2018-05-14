import numpy as np
import matplotlib.pyplot as plt
from matplotlib.pyplot import *

 
datose= np.genfromtxt("placas.txt")
v = datose[0,:]
ex = datose[1,:]
ey = datose[2,:]
lenn= len(v)
n = int(lenn**0.5)
r = np.arange(n)
R0,R1 = np.meshgrid(r,r)
V = np.reshape(v,(n,n))
Ex = np.reshape(ex,(n,n))
Ey = np.reshape(ey,(n,n))
imshow(V)
colorbar()
streamplot(R0,R1,Ex,Ey)
savefig('placas.pdf')
 

 
