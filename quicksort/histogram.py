import matplotlib.pyplot as plt
#import numpy as np

intData=[]

with open("filename.txt") as file:
    for i in range(1, 10001):
        data = file.readline()
        intData.append(data)



 
# Generate random data for the histogram


# print("running")



# for i in data:
#     intData.append(float(i))
    

# Plotting a basic histogram
plt.hist(intData, bins=40,  color='skyblue', edgecolor='black')
 
# Adding labels and title
plt.xlabel('Values')
plt.ylabel('Frequency')
plt.title('Probability Distribution')

plt.savefig("histo.png")  