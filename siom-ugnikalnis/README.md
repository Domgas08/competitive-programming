## SIOM – Ugnikalnis (C++)

Solution for the SIOM task ["Ugnikalnis"](https://siom.lmio.lt/task/ugnikalnis.html)

Idea:
- Each lava hole is a circle. Intersecting/touching circles form one connected lava region.
- Build a graph where circles are connected if they intersect or touch
  (touching also blocks passage).
- Find connected components of circles.
- A connected component that touches both the left and right borders creates a full barrier.
  Any path from bottom to top must cross each such barrier once.
- Answer = number of components touching both left and right borders.

Techniques:
- Geometry (circle intersection / touching)
- Graph connected components (DFS)
