# Project Overview<br> 
Rush01 is a logic-based solver for the Skyscraper Puzzle, a game played on an N×N grid (currently supporting 4×4, with plans for up to 9×9).
Each cell contains a number from 1 to N, representing building heights.
The objective is to fill the grid according to logic rules and visibility clues.

### Puzzle Rules<br>
- Each row and column must contain all numbers from 1 to N without repetition.<br>
- The numbers placed around the grid indicate how many buildings are visible from that direction — taller buildings block shorter ones behind them.

## How It Works<br>
#### 1. Input Parsing (`parse_input()`)<br>
- Reads and validates exactly 16 digits (1–4) separated by spaces.
- Rejects malformed input, multi-digit numbers, or non-digit characters.
- If more than 16 numbers are provided, only the first 16 are used.

#### 2. Recursive Backtracking Solver (`rush01()`)<br>
Fills the 4×4 grid cell-by-cell using backtracking:
- Ensures no duplicates in rows or columns via `no_duplicate()`.
- Checks visibility rules using `check_line()` and `count_visible()`.
- Recursively explores valid placements until a complete solution is found.

#### 3. Output<br>
- If a valid grid is found → prints the solution.
- If input is invalid or no solution exists → prints `Error`.

## Usage<br>
#### Compilation<br>
```

cc -Wall -Wextra -Werror *c -o rush01

```

#### Input Format<br>
```

./rush01 "col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right"

```

#### Example<br> 
```

./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

```

## Input Rules Summary
✅ Accepted:
- Exactly 16 numbers between 1 and 4
- Spaces between numbers are ignored
- If more than 16 numbers are given, only the first 16 are used

❌ Rejected:
- Multi-digit numbers (e.g., 12)
- Non-digit characters
- Fewer than 16 numbers
