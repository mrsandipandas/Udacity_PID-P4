from numpy import *
import math
import matplotlib.pyplot as plt
import numpy as np

steer_p = []
steer_pd = []
steer_pid = []
with open("p.txt", "r") as ins:
	for line in ins.read().splitlines():
		msg = line.split(",")
		steer_p.append(float(msg[1]))

with open("pd.txt", "r") as ins:
	for line in ins.read().splitlines():
		msg = line.split(",")
		steer_pd.append(float(msg[1]))
		
with open("pid.txt", "r") as ins:
	for line in ins.read().splitlines():
		msg = line.split(",")
		steer_pid.append(float(msg[1]))
		
n = len(steer_p)
x = np.array(steer_p)
y = np.array(steer_pd)
z = np.array(steer_pid)
plt.xlim(0,950)
plt.ylim(-1.5,1.5)
plt.plot(x, 'r', label='P controller')
plt.plot(y, 'g', label='PD controller')
plt.plot(z, 'b', label='PID controller')

plt.title('Steering angle for different types of controller', fontsize=20)
plt.gca().legend(('P controller','PD controller', 'PID controller'))

plt.show()
