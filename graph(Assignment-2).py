import matplotlib.pyplot as plt

n = [10000, 20000, 50000, 100000, 200000, 500000]

time_taken = [0.000, 0.003, 0.005, 0.010, 0.019, 0.053]

plt.plot(n, time_taken, marker='o')

plt.xlabel("Number of elements (n)")
plt.ylabel("Time taken (seconds)")
plt.title("Quick Sort: Time vs Number of Elements")

plt.grid(True)
plt.show()