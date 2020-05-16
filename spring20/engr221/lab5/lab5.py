# ENGR 221 Lab5, Sean Lai
# Due: 5/20/20

import math
import numpy as np

# Declare constants
VS = 10
R1 = 1500
R2 = 2200
R3 = 1000
R4 = 680

# Load resistor values
RL = [390, 680, 1200, 2200, 3900, 10e7]

# Lists to store calculated VAB and PL values for each RL value
VAB = []
PL = []

# **************** Part A ******************
# loop through values of RL
for i in range(len(RL)):
    # Solve for VA, VB
    # matrices found using NVA for points A and B
    A = np.array([[1/R2 + 1/R1 + 1/RL[i], -1/RL[i]],
                  [-1/RL[i], 1/R4 + 1/R3 + 1/RL[i]]])
    B = np.array([VS/R1, VS/R3])
    result = np.linalg.solve(A, B)
    VAB.append(result[0] - result[1]) # VA - VB from resultant vector
    PL.append(VAB[i]**2/RL[i]*1e6) # Note: *1e6 to convert to microwatts

# Print results
print("**************** Part A Results ******************")
for i in range(len(RL)):
    print(f"For RL = {RL[i]},  VAB = {VAB[i]}, PL = {PL[i]}")


# **************** Part B ******************
# Calculate Rth and Vth using Thevenin equivalents
Rth = ((1/R1 + 1/R2)**-1 + (1/R3 + 1/R4)**-1)
# Calculate VA, VB using voltage dividers at A, B
VA = VS*(R2/(R1 + R2))
VB = VS*(R4/(R3 + R4))
Vth = VA-VB

# Print results
print("\n**************** Part B Results ******************")
print(f"Rth = {Rth}, Vth = {Vth}")


# **************** Part C ******************
# Lists to store calculated VAB and PL values for each RL value
VABth = []
PLth = []

for i in range(len(RL)):
    # Solve for VABth using voltage divider in Thevenin equivalent circuit
    VABth.append(Vth*(RL[i]/(RL[i]+Rth)))
    PLth.append(VABth[i]**2/RL[i]*1e6)

# Print results
print("\n**************** Part C Results ******************")
for i in range(len(RL)):
    print(f"For RL = {RL[i]},  VABth = {VAB[i]}, PLth = {PL[i]}")

print("\nCheck to see if power at RL = Rth is larger than other values")
print(f"For RL = Rth = {Rth}, VAB = {Vth/2}, Pth = {(Vth/2)**2/Rth*1e6}")
