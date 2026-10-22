# Data Structures & Algorithms — Week 2 Assignment

**Topics:** Linked List, Stack, Queue, and Dynamic Memory Allocation in C++  
**Language:** C++  
**Assignment source:** Week 2 PDF supplied with the task.

## Contents

1. `src/01_singly_linked_list.cpp` — insert, delete, display, and search in a singly linked list.
2. `src/02_stack_using_linked_list.cpp` — stack with push, pop, peek, and display.
3. `src/03_queue_using_array.cpp` — linear queue using an array, with enqueue, dequeue, front, and display.
4. `src/04_reverse_linked_list_using_stack.cpp` — reverses a linked list using stack logic.
5. `src/05_undo_redo_text_editor.cpp` — mini-project implementing undo/redo with stacks.

## Requirements

- A C++ compiler such as GCC, Clang, or Microsoft Visual C++.
- Basic knowledge of pointers, classes/structures, arrays, and dynamic memory allocation.

## Compile and run

From the repository root, compile each program separately:

```bash
g++ -std=c++17 src/01_singly_linked_list.cpp -o linked_list
./linked_list
```

Repeat with the matching source filename and output name for the other programs. On Windows, run the generated `.exe` file, for example `linked_list.exe`.

## Assignment 1: Singly Linked List

**Aim:** Implement insertion and deletion in a singly linked list.

**Concept:** Each node stores data and a pointer to the next node. The `head` pointer refers to the first node. Nodes are allocated dynamically with `new` and released with `delete`.

**Operations:** Insert at the end, delete the first matching value, search, and display.

**Algorithm — insert at end**
1. Create a node containing the new value.
2. If the list is empty, make the new node the head.
3. Otherwise traverse to the final node and link it to the new node.

**Algorithm — delete by value**
1. If the list is empty, report that the value was not found.
2. If the head contains the value, move head to the next node and delete the old head.
3. Otherwise find the node whose next node contains the value.
4. Bypass that node and release its memory.

**Complexity:** Insertion at end is O(n) without a tail pointer. Deletion/search is O(n). Display is O(n).

## Assignment 2: Stack Using Linked List

**Aim:** Implement Last-In, First-Out (LIFO) behavior using a linked list.

**Operations:** `push`, `pop`, `peek`, and `display`.

- `push`: insert a new node at the head.
- `pop`: remove the head node.
- `peek`: read the top value without removing it.
- Underflow occurs when pop/peek is attempted on an empty stack.

**Complexity:** Push, pop, and peek are O(1); display is O(n).

## Assignment 3: Queue Using Array

**Aim:** Implement First-In, First-Out (FIFO) behavior using an array.

**Operations:** `enqueue`, `dequeue`, `front`, and `display`.

This implementation is a **linear queue**. It reports overflow when the array is full and underflow when it is empty. Once the rear reaches the final array index, freed positions at the front are not reused; a circular queue would solve that limitation.

**Complexity:** Enqueue and dequeue are O(1); display is O(n).

## Assignment 4: Reverse a Linked List Using Stack Logic

**Aim:** Reverse the order of the list by pushing node values onto a stack and assigning them back while traversing the list.

**Algorithm**
1. Traverse the list and push each node's data onto a stack.
2. Traverse the list again.
3. Replace each node's data with the top stack value, then pop.
4. The list now displays in reverse order.

**Complexity:** O(n) time and O(n) extra space.

## Mini Project: Undo-Redo Text Editor Simulation

**Aim:** Simulate text editing with undo and redo operations.

**Design:** Two stacks are used:
- **Undo stack:** stores previous text states.
- **Redo stack:** stores states that can be restored by redo.

When new text is entered, the current state is pushed onto the undo stack and the redo stack is cleared. Undo saves the current state to redo and restores the most recent undo state. Redo saves the current state to undo and restores the most recent redo state.

**Complexity:** Stack operations are O(1), excluding the cost of copying text strings.

## Sample test plan

| Program | Test | Expected behavior |
|---|---|---|
| Singly linked list | Insert 10, 20, 30 | Displays `10 -> 20 -> 30 -> NULL` |
| Singly linked list | Delete 20 | Displays `10 -> 30 -> NULL` |
| Stack | Push 10, then 20; pop | Pops 20; top becomes 10 |
| Queue | Enqueue 10, then 20; dequeue | Removes 10; front becomes 20 |
| Reverse list | Input 1, 2, 3 | Displays 3, 2, 1 |
| Text editor | Type `Hello`, then ` World`; undo | Text becomes `Hello`; redo restores `Hello World` |

## Conclusion

This assignment demonstrates linked-list operations, LIFO stacks, FIFO queues, stack-based list reversal, and state history for undo/redo. The code is split into separate files so each task can be compiled and tested independently.

## GitHub upload steps

1. Create a new repository on GitHub.
2. Extract this ZIP file on your computer.
3. Upload `README.md`, `.gitignore`, and the complete `src` folder while preserving the folder structure.
4. Enter a commit message such as `Add Week 2 DSA assignment solutions`.
5. Click **Commit changes**.
