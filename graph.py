import matplotlib.pyplot as plt

# Values obtained from C program
n = [100, 500, 1000, 5000, 10000, 50000, 100000]

time = [0.003666, 0.004745, 0.004683,
        0.003592, 0.003165, 0.003725, 0.002934]

# Plot graph
plt.plot(n, time, marker='o')

plt.xlabel("Number of elements (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Recursive Binary Search - Time vs n")

plt.grid(True)
plt.show()