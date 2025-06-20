<div align="center">
  <a href="https://github.com/mpeyre-s/push_swap">
    <img src="https://github.com/mpeyre-s/42_project_badges/raw/main/badges/push_swap_bonus.svg" alt="push_swap badge" />
  </a>
</div>

---
# push_swap

![Test de l'algorithme](assets/screenshot.png)



## Overview

**push_swap** is an algorithmic project from 42 that involves sorting a stack of integers using a very limited set of operations and a second auxiliary stack.  
The challenge is to implement the most efficient sorting algorithm (in terms of number of operations) possible.

This implementation is based on the **Radix Sort** algorithm, which guarantees optimal performance for large data sets while respecting all project constraints.

---

## Goals

- Implement sorting with **restricted stack operations**
- Optimize the total number of operations
- Practice algorithm design and optimization techniques
- Handle input parsing, error management, and edge cases robustly

---

## Stack Operations Allowed

Only these operations are permitted:

- **sa** / **sb** : swap the first two elements of stack A or B  
- **ss** : `sa` and `sb` at the same time  
- **pa** / **pb** : push the top element from one stack to another  
- **ra** / **rb** : rotate stack A or B upwards  
- **rr** : `ra` and `rb` at the same time  
- **rra** / **rrb** : reverse rotate stack A or B  
- **rrr** : `rra` and `rrb` at the same time

---

## Algorithm: Radix Sort

This project uses **Radix Sort in base 2** to sort the stack efficiently:

1. **Indexing**: All input values are replaced by their index in the sorted array (e.g., the smallest becomes 0).
2. **Bitwise sorting**: For each bit (from LSB to MSB), elements are pushed to stack B if the current bit is 0, otherwise rotated in stack A.
3. After each pass, elements are pushed back from B to A.
4. Repeat until all bits have been processed.

This method ensures a time complexity of **O(n log n)** and passes all 42 performance requirements for large inputs.

---

## Compilation

Clone and compile the project with:

```bash
git clone https://github.com/mpeyre-s/push_swap.git
cd push_swap
make
```
This will generate the `push_swap` executable.

---

## Usage

```bash
./push_swap [list of integers]
```

## Error Handling

- 🚫 Duplicate numbers are not allowed  
- 🔢 Only valid integers are accepted  
- 📉 Inputs outside of `INT_MIN` and `INT_MAX` are rejected  
- ❌ Proper error message is printed: `Error\n`

