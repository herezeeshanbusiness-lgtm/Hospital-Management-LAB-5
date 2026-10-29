Hospital Management System — Lab 05 Part B
=============================================

Project problem
---------------
A hospital needs to maintain a list of waiting patients and process urgent
patients before regular and low-priority patients.

Why a linked list fits
----------------------
A singly linked list can grow or shrink while the program runs. Insertion
and removal do not require shifting an array's elements. Each patient node
stores the patient's data and a pointer to the next patient.

Files
-----
- main.cpp: menu, input validation, and calls to the LinkedList class.
- LinkedList.h: PatientNode structure and LinkedList class declarations.
- LinkedList.cpp: implementation of linked-list operations.

Lab Part B operations included
------------------------------
Insert at head, Remove from head, IsEmpty, IsNotEmpty, InsertAt, RemoveAt,
Swap, Sort, Reverse, and Print. The project also has AddByPriority to preserve
the hospital waiting-queue idea. Priority 1 is urgent, 2 is regular, and 3 is low.

Indexing
--------
Indexes are zero-based: the first node is index 0. InsertAt allows indexes
from 0 through the current list size. RemoveAt and Swap require an existing index.

Compile and run in VS Code terminal
-----------------------------------
Make sure a C++ compiler such as g++ is installed. Open the folder containing
all three .cpp/.h files in VS Code, then run:

    g++ -std=c++17 main.cpp LinkedList.cpp -o hospital

On Windows PowerShell, run:

    .\hospital.exe

On Linux/macOS, run:

    ./hospital

Note
----
Option 2 inserts directly at the head, as required by the lab. Option 1 adds
the patient in priority order. Since manual linked-list operations can change
the order, option 3 sorts the list by priority before removing the head.
