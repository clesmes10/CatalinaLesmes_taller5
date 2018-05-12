import numpy as np
import matplotlib.pyplot as plt

runge = np.genfromtxt("caos.txt")
q2 = runge[:,0]
p2 = runge[:,1]

plt.plot(p2, q2, "m")
plt.ylabel("q2")
plt.xlabel("p2")
plt.title("q2 vs p2")
plt.savefig("caos.pdf")
