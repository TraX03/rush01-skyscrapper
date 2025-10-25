# Project Overview<br> 
A logic-based solver for the Skyscraper Puzzle, a game played on an N×N grid (supporting grid sizes from 2×2 up to 9×9).
Each cell contains a number from 1 to N, representing building heights.
The goal is to fill the grid so that all logic and visibility clues are satisfied.

### Puzzle Rules<br>
- Each row and column must contain all numbers from 1 to N without repetition<br>
- Numbers placed around the grid (called constraints or clues) indicate how many buildings are visible from that direction — taller buildings block shorter ones behind them<br>
- Visibility counts must match the clues given on all four sides (top, bottom, left, right)<br>

## How It Works<br>
#### 1. Input Parsing (`parse_input()`)<br>
- Dynamically validates and stores exactly N × 4 clues.
- Rejects malformed input (multi-digit numbers, invalid characters, or incorrect counts).

#### 2. Dynamic Grid Allocation (`malloc_grid()`/`free_grid()`)<br>
- Allocates a 2D grid dynamically using `malloc()`.
- Ensures all allocated memory is freed on failure or program exit.

#### 3. Recursive Backtracking Solver (`rush01()`)<br>
- Uses recursive backtracking to fill the grid cell by cell.
- Checks:
  - `no_duplicate()` → ensures row/column uniqueness
  - `check_line()` → ensures visibility constraints are satisfied
  - `count_visible()` → counts visible buildings from a side
- Recursively explores possibilities until a valid grid is found.

#### 4. Output<br>
- If a valid grid is found → prints the solution.
- If input is invalid or no solution exists → prints an error message.

## Usage<br>
#### Compilation<br>
```

cc -Wall -Wextra -Werror *c -o rush01

```

#### Input Format<br>
```

./rush01 [grid size 2–9] "[constraints]"

```

#### Constraints Format<br>
```

"col1top col2top ... colNtop col1bottom ... colNbottom row1left ... rowNleft row1right ... rowNright"

```

#### Example (4 x 4)<br> 
```

./rush01 4 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

```

## Input Rules Summary
✅ Accepted:
- Exactly `N x 4` integers separated by spaces
- Extra spaces are ignored
- Each integer is between `1` and `N`
- If more than `N x 4` numbers are provided, only the first `N x 4` are used

❌ Rejected:
- Multi-digit numbers (e.g., 12)
- Non-digit characters
- Too few clues

## Performance Notes
This solver uses pure backtracking, which has factorial time complexity — roughly O(N!) per row or column.
While this is manageable for smaller grids, performance decreases rapidly as N increases.
- 🟢 2×2 to 5×5: Solves almost instantly
- 🟡 6×6: Noticeable increase in computation time
- 🔴 8×8 and 9×9: May take a very long time or appear to “hang” (timeout) because of the huge search space
