## ŠIOM - Aštuonių valdovių uždavinys
Solution for ŠIOM task ["Aštuonių valdovių uždavinys"](https://siom.lmio.lt/task/valdoves.html).

Idea:
- Place queens row by row using backtracking.
- Keep track of which columns and diagonals are already occupied.
- If a position is safe, place a queen and continue to the next row.
- Count all complete placements; store the first one to print.

Techniques:
- Backtracking / recursion
- Pruning using column + diagonal occupancy
