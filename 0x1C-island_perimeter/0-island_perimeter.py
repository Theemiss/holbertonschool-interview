#!/usr/bin/python3
"""
island_perimeter
"""


def island_perimeter(grid):
    """
    calculate the perimeter of a grid island
    """
    island_surface = 0
    for i in range(0, len(grid), 1):
        for j in range(0, len(grid), 1):
            if grid[i][j] == 1:
                island_surface += 1

    al = island_surface - 2

    sur = al * 2 + (island_surface - al) * 3
    return sur
