# Project Overview<br> 
Rush01 is a logic-based puzzle solver for the Skyscraper Puzzle — a game played on an N×N grid.
Currently, it supports 4×4 grids, with plans to expand up to 9×9.
Each cell contains a number from 1 to N, representing the height of a building.
The goal is to fill the grid following the puzzle’s logic rules and visibility clues.

### Rules<br>
- Each row and column must contain all numbers from 1 to N without repetition.<br>
- Numbers placed around the grid indicate how many buildings are visible from that direction. Taller buildings hide shorter ones behind them.

### Usage<br>
#### Compile<br>
```

cc -Wall -Wextra -Werror *c -o rush01

```

#### Run Command Format<br>
```

./rush01 "col1top col2top col3top col4top col1bottom col2bottom col3bottom col4bottom row1left row2left row3left row4left row1right row2right row3right row4right"

```

#### Example<br> 
```

./rush01 "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2"

```

### Input Rules 
✅ Accepts exactly 16 numbers between 1 and 4.<br>
✅ Ignores spaces between numbers.<br>
✅ If more than 16 numbers are given, only the first 16 are taken.<br>

❌ Rejects input if:<br>
- Pattern is malformed (extra digits, invalid spacing, etc.)
- Multi-digit numbers are given (e.g., 12)
- Non-digit characters are included
- Fewer than 16 numbers are given

### Error Handling 
If there is no valid solution or the input is invalid, the program prints:<br>
```

Error

```
