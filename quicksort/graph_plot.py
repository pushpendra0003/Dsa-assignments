import matplotlib.pyplot as plt
from math import log
 
# x axis values
x = [10, 50, 100, 200, 500, 1000, 2000, 5000, 10000]
# corresponding y axis values
y = [ 9.891e-07, 5.2169e-06, 9.8151e-06, 1.88398e-05,  5.34538e-05, 0.000113714, 0.000240499, 0.000651913, 0.00152855]



z = []
for i in x:
    temp=0.00152855*i*log(i)/92103.403719761
    z.append(temp)
 
# plotting the points 
plt.plot(x,y)

plt.plot(x,z)
 
# naming the x axis
plt.xlabel('x - axis')
# naming the y axis
plt.ylabel('y - axis')
 
# giving a title to my graph
plt.title('r+Running time analysis!')
 
# function to show the plot
plt.savefig("output.png")
