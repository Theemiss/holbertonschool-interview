#!/usr/bin/python3
"""
island_perimeter
"""


def island_perimeter(grid):
    """
    calculate the perimeter of a grid island
    """
    row, col = len(grid), len(grid[0])
    directions = [(1, 0), (-1, 0), (0, 1), (0, -1)]
    perimeter = 0
    for r in range(row):
        for c in range(col):
            adjacent_land = 0
            if grid[r][c] == 1:
                for d in directions:
                    ro = r + d[0]
                    co = c + d[1]
                    if 0 <= ro < row and 0 <= co < col and grid[ro][co] == 1:
                        adjacent_land += 1
    perimeter += (4 - adjacent_land)
    return perimeter
