import numpy as np
import matplotlib.pyplot as plt
from matplotlib import animation
import matplotlib.animation as anm

datoscuerda = np.genfromtxt("cuerda.txt")
figure = plt.figure()
frames, puntos = np.shape(datoscuerda)
size = np.size(datoscuerda,1)
fr = np.size(datoscuerda,0)
fr2 = fr/2

def animacion(u):
    plt.cla()
    da = datoscuerda[u,:]
    plt.ylim([-1,1])
    plt.plot(da)
    
animaci = animation.FuncAnimation(figure, animacion, frames = fr)
animaci.save( "cuerda.gif", writer = "imagemagick", fps = fr2)

    
#http://www.jamesphoughton.com/2013/08/23/making-gif-animations-with-matplotlib.html
