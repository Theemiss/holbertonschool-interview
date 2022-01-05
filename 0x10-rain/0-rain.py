#!/usr/bin/python3
"""
rain module
"""


def rain(walls):
    """
    Given a list of non-negative integers representing
    the heights of walls with unit width 1,
    as if viewing the cross-section of a relief map,
    calculate how many square units of water will be
    retained after it rains.
    """
    if not walls:
        return 0
    walls_length = len(walls)
    water = 0
    for i in range(walls_length):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])
        water += min(left, right) - walls[i]
    return water
