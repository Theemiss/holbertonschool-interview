#!/usr/bin/python3
"""
Minumum operation Model
"""


def minOperations(n):
    """
    In a text file, there is a single character H. Your text editor
    can execute only two operations in this file: Copy All
    and Paste. Given a number n, write a method that calculates
    the fewest number of operations needed to result
    in exactly n H characters in the file.
    Returns an integer
    If n is impossible to achieve, return 0
    Example:
    n = 9
    H => Copy All => Paste => HH => Paste =>HHH =>
    Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
    Number of operations: 6
    """
    if type(n) is not int or n < 2:
        return 0
    result = 0
    iteration = 2
    while n > 1:
        if n % iteration == 0:
            result += iteration
            n /= iteration
        else:
            iteration += 1
    return result
