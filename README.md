# Push-Swap
As part of the 42 School curriculum i wrote this highly efficient sorting algorithm project in C coding language.

The goal is to sort a stack of integers using a limited set of operations and the minimum number of moves.

---

## Visual Representation

Visualizing the "dancing stacks" is the best way to understand how the algorithm works. 

Here the video of the sorting: [Push_swap Sorting Video](https://www.youtube.com/watch?v=n-B5SbzzJtQ)

## What the Programme Does

The `push_swap` program calculates and displays the smallest sequence of instructions to sort a list of integers. It uses two stacks, **Stack A** and **Stack B**, and a specific set of operations:

- `sa`, `sb`, `ss`: Swap the first two elements of a stack.
- `pa`, `pb`: Push an element from one stack to another.
- `ra`, `rb`, `rr`: Rotate the stack (first element becomes last).
- `rra`, `rrb`, `rrr`: Reverse rotate (last element becomes first).

### Algorithm
In the implementation I used a **Greedy Cost-Based Algorithm** (often referred to as "Turk Algorithm"):
1. It handles small cases (n <= 5) with optimized hardcoded logic.
2. For larger sets, it pushes elements to Stack B, leaving only 3 in Stack A.
3. It then calculates the "cost" for each element in B to be moved back to A in the correct position.
4. It executes the move with the lowest combined cost (rotations in A + rotations in B).
5. Finally, it performs a final adjustment to ensure the smallest number is at the top.

## How to Run It

### 1. Compilation
Open a terminal in the project directory and run:
```bash
make
```
This will generate the `push_swap` executable.

### 2. Execution
Run the program by passing a list of integers:
```bash
./push_swap 4 67 3 87 23
```
It will output the sequence of commands.

### 3. Verification
It is possible to use the provided `checker_Mac` or `checker_linux` to verify if the output correctly sorts the numbers:
```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_Mac $ARG
```
If it displays **OK**, the sort was successful.

## Testing & Benchmarking

The `Makefile` includes scripts to stress-test the algorithm and ensure it meets the 42 School efficiency requirements.

### 1. Performance Testing (Efficiency)
These commands will run the program multiple times with different random sets and report the **worst-case** scenario (the maximum number of moves it took).

- **For 100 numbers**: (Target: < 700 moves for maximum score in the evaluation)
  ```bash
  make 100
  ```
- **For 500 numbers**: (Target: < 5500 moves for maximum score in the evaluation)
  ```bash
  make 500
  ```

### 2. Consistency Testing (Correctness)
These commands run the program through the `checker_Mac` or `checker_linux` 10 times with random inputs to verify that the sorting is always correct.

- **Check 100 numbers**: `make 100check`
- **Check 500 numbers**: `make 500check`

---

### Online / Web Visualizers
Here I am listing one of the many web-based visualizers that helps to visualise the algorithm in action, by simply copying the output of the program and the initial numbers.
(Following a sample of 300 numbers and operations ready to be pasted)
 - [Push_swap Visualizer (Web)](https://push.eliotlucas.ch/)


[Link to Sample 300 Operations](./sample_300.txt)
