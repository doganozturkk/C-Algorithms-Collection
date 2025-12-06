# 📝 C Algorithms Collection

<p align="center">
  <img src="https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExOTl6eGV2NGxoZ2xuaHFxaDA2cDY3bTNnNHozMGY4eWh3MzZjNW51ciZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/10LKovKon8DENq/giphy.gif" width="320" />
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-blue?style=for-the-badge&logo=c">
  <img src="https://img.shields.io/badge/Design-Modular-success?style=for-the-badge">
  <img src="https://img.shields.io/badge/Code%20Quality-Clean-brightgreen?style=for-the-badge">
  <img src="https://img.shields.io/badge/Algorithms-15%2B-blueviolet?style=for-the-badge">
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge">
</p>

---

## 📌 Overview

C Algorithms Collection is a clean, modular, and beginner-friendly set of classic algorithms written in pure C.  
It includes:

🔹 Sorting algorithms  
🔹 Searching algorithms  
🔹 Core data structures  
🔹 Example test file (main.c)

This repository is perfect for:  
Students learning algorithms  
Anyone preparing for technical interviews  
Developers who want minimal, readable C implementations

---

## 📂 Project Structure

```
c-algorithms-collection/
│
├── sorting/
│ ├── bubble_sort.c
│ ├── merge_sort.c
│ ├── quick_sort.c
│ ├── selection_sort.c
│ └── sorting.h
│
├── searching/
│ ├── linear_search.c
│ ├── binary_search.c
│ └── searching.h
│
├── data_structures/
│ ├── linked_list.c
│ ├── linked_list.h
│ ├── stack.c
│ ├── stack.h
│ ├── queue.c
│ ├── queue.h
│ ├── binary_tree.c
│ └── binary_tree.h
│
├── main.c
└── README.md
```

---

## 🛠️ Technologies

C Programming Language  
Standard Library Only (stdlib, stdio)  
Modular Header-Based Architecture

---

## 🚀 Build & Run

### 1. Compile
gcc main.c sorting/.c searching/.c data_structures/*.c -o run

### 2. Run
./run

---

## 🧩 Included Algorithms

### 🔹 Sorting
Bubble Sort  
Selection Sort  
Merge Sort  
Quick Sort  

### 🔹 Searching
Linear Search  
Binary Search  

### 🔹 Data Structures
Linked List  
Stack  
Queue  
Binary Tree  

---

## 📘 Example Usage

#include "sorting/sorting.h"
#include "searching/searching.h"

int arr[] = {5, 2, 9, 1, 3};
int size = 5;

quick_sort(arr, 0, size - 1);

int index = binary_search(arr, size, 3);
printf("Found at index: %d\n", index);

---

## 📊 Performance Benchmarks

A small benchmark comparison was performed on basic sorting algorithms for this project.  
All measurements were taken under the following conditions:

* Intel i5 processor  
* Random integer array with 10,000 elements  
* Results are averaged over 10 runs  

| Algorithm          | Time Complexity | Average Time (ms) |
| ------------------ | --------------- | ----------------- |
| **Bubble Sort**    | O(n²)           | 482 ms            |
| **Selection Sort** | O(n²)           | 365 ms            |
| **Merge Sort**     | O(n log n)      | 12 ms             |
| **Quick Sort**     | O(n log n)      | 8 ms              |

---

## 🧱 UML Diagram (High-Level Architecture)

The UML diagram below illustrates the overall modular structure of the project:

### UML Architecture Diagram

```
                      ┌─────────────────────────────┐
                      │           main.c            │
                      │─────────────────────────────│
                      │ - Uses sorting module       │
                      │ - Uses searching module     │
                      │ - Uses data structures      │
                      └───────────────┬─────────────┘
                                      │
         ┌────────────────────────────┼────────────────────────────┐
         │                            │                            │
 ┌───────────────────┐       ┌───────────────────┐       ┌──────────────────────┐
 │   Sorting Module  │       │  Searching Module │       │ Data Structures      │
 ├───────────────────┤       ├───────────────────┤       ├──────────────────────┤
 │ + bubble_sort()   │       │ + linear_search() │       │ + linked_list        │
 │ + selection_sort()│       │ + binary_search() │       │ + stack              │
 │ + merge_sort()    │       └───────────────────┘       │ + queue              │
 │ + quick_sort()    │                                   │ + binary_tree        │
 └───────────────────┘                                   └──────────────────────┘
```

---

## 📄 License

This project is licensed under the MIT License — feel free to use it in your own projects.

---

## 🙌 Author

Developed by: @doganozturkk
