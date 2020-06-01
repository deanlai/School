# ENGR221 Lab 6
# Sean Lai

# Note: The os module has been imported to manage file opening on my computer's
#       file system. ltdata.raw and this python script (lab6.py) should be in 
#       the same directory for this to function properly.
# Note: For these calculations in LTSpice, Rth = 1296.654. This rounding to 3
#       decimal places accounts for power difference between P1 and P2 being
#       about orders of magnitude smaller than P1 and P2, i.e. (P1-P2) ~ P1e-4

import numpy as np
import matplotlib.pyplot as plt
import ltspice
import os

# clearing the screen
from subprocess import call 
call('clear')

l = ltspice.Ltspice(os.path.dirname(__file__)+'ltdata.raw')
l.parse() # Data loading sequence.
RL = l.getTime()  # 500 RL values
Va = l.getData('V(a)')  # voltage at A
Vb = l.getData('V(b)')  # voltage at B
Vth = l.getData('V(c)')  # voltage at C, or thevenin voltage
IRL = l.getData('I(Rl)')  # current through RL
IRLth = l.getData('I(Rlth)')  # current through Rlth

Vab = Va - Vb # calculate voltage difference between a and b

# calculate power and convert to uW
P1 = (Vab * IRL) * 1e6 
P2 = (Vth * IRLth) * 1e6
P1_minus_P2 = P1 - P2

# Plot of circuit using Vab and P1
plt.plot(RL, P1)
plt.xlabel('Load resistance (ohms)')
plt.ylabel('Power dissapated (uW)')
plt.title('Power dissapation vs. Load resistance, Circuit 1')
plt.grid(axis='x')
plt.grid(axis='y')
plt.savefig(os.path.dirname(__file__)+'plot1.png', dpi=300, bbox_inches='tight')
plt.clf()

# Plot of circuit using Vth(Vc) and P2
plt.plot(RL, P2)
plt.xlabel('Load resistance (ohms)')
plt.ylabel('Power dissapated (uW)')
plt.title('Power dissapation vs. Load resistance, Circuit 2 (Thevenin)')
plt.grid(axis='x')
plt.grid(axis='y')
plt.savefig(os.path.dirname(__file__)+'plot2.png', dpi=300, bbox_inches='tight')
plt.clf()

# Plot of difference between plots 1 and 2
plt.plot(RL, P1_minus_P2)
plt.xlabel('Load resistance (ohms)')
plt.ylabel('Power dissapated (uW)')
plt.title('Power dissapation difference (P1-P2) vs. Load resistance')
plt.grid(axis='x')
plt.grid(axis='y')
plt.savefig(os.path.dirname(__file__)+'plot3.png', dpi=300, bbox_inches='tight')
plt.clf()

