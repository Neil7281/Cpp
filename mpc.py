import matplotlib.pyplot as plt
import numpy as np

# Parameters
k = 0           # Current time step
Nu = 5          # Control horizon
Np = 10         # Prediction horizon
time_steps = np.arange(k, k + Np + 1)

# Control input (u) trajectory: Optimized for Nu steps, then held constant
u = np.zeros(len(time_steps))
u[:Nu] = np.linspace(1, 1, Nu)  # Constant control for illustration
u[Nu:] = u[Nu-1]                # Hold last value

# Predicted output (y) trajectory (example: decaying response)
y = np.exp(-0.2 * (time_steps - k)) * (1 - 0.1 * np.random.rand(len(time_steps)))

# Plotting
plt.figure(figsize=(10, 6))

# Control input (u) plot
plt.step(time_steps, u, where='post', label='Control Input (u)', linewidth=2, color='blue')
plt.axvline(x=k + Nu - 0.5, linestyle='--', color='red', label=f'Control Horizon (Nu={Nu})')

# Predicted output (y) plot
plt.plot(time_steps, y, 'o-', label='Predicted Output (y)', linewidth=2, color='green')
plt.axvline(x=k + Np - 0.5, linestyle=':', color='purple', label=f'Prediction Horizon (Np={Np})')

# Current time marker
plt.axvline(x=k, linestyle='-', color='black', alpha=0.5, label='Current Time (k)')

# Annotations
plt.text(k + Nu/2, 0.2, 'Optimized Control', ha='center', bbox=dict(facecolor='white', alpha=0.8))
plt.text(k + Nu + (Np-Nu)/2, 0.2, 'Held Constant', ha='center', bbox=dict(facecolor='white', alpha=0.8))
plt.title('MPC Horizons: Control (Nu) vs. Prediction (Np)', fontweight='bold')
plt.xlabel('Time Steps', fontweight='bold')
plt.ylabel('Signal Value', fontweight='bold')
plt.legend(loc='upper right')
plt.grid(True, alpha=0.3)
plt.ylim(0, 1.2)
plt.xlim(k, k + Np)
plt.show()