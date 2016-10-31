Algorithms that attempt solving Hidato puzzles.

Features:

* Three different algorithms:
	- Two backtrackers that guarantee solutions to each valid Hidato puzzle.
	- One hill-climber that comes rather close in most cases.
  
* Flexible file input

Usage:

Hidato_Solver.exe [-algorithm] [“path/filename”]

The input format for each algorithm:
* Regular Backtracker: -b
* Smart Backtracker: -sb
* Hill-climber: -h

Example: To run the regular backtracker on puzzle Beginner 9, type in:
Hidato_Solver.exe -b “beginner_9.txt”

Access to a full-screen command-line application is advised as some outputs are rather large.


Adding your own puzzles:

The valid inputs in-file are:
* ? - for empty nodes
* X - for blocked nodes
* Numbers

Further rules:
* Number 1 must be present
* Each item must be separated by any non-valid character
* Each row must be entered in its own row in-file, i.e. contain a new-line character

Aside from these rules, the input is flexible:
* Suggested characters for separating items are [ and ]. However, spaces or other non-valid characters will work as well.
* Numbers, such as 9, can be entered as 09 or 009 to improve the layout for larger puzzles in-file. 
* The same applies to ? and X which can be entered as ?? or XXX
* If some rows are shorter than other rows, the remainder of these rows will be filled up with blocked nodes automatically.


