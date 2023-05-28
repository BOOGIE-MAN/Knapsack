# Knapsack

## About the project
Program written to solve a knapsack problem via brute-force method.
### What is Knapsack problem
Solving the knapsack problem tell us what items that have a value(the higher the better) and weight(the lower the better) can be inserted into the backpack of given capacity whilst having the highest possible sum of values.
In this project number of items = 32, which yields 2^32 possible item subsets to be evaluated.
### Brute-force solution
This project utilizes brute-force meaning that all possible solutions are tested(which in this case is quite slow, around 4 minutes), however the best solution to the problem is guaranteed.
### How it works?
Since there are 2^32 possible item combinations, an uint32_t to store all possible item combinations, where if i-th bit is set it means that during this iteration i-th item is considered.
Program goes through all values of uint32_t in order to determin the best set of items i.e. items that can be placed inside the backpack while simultaneously having the highest possible sum of values. 
## How to run it
It can be run directly from the .exe file or through Visual Studio 2022 in any configuraion.
## Idea
The project originally was written as a university project.
