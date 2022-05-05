#!/usr/bin/python3
"""
Pascal Triangle Model
"""


def CofBinom(n, k):
    """
    Binomial coefficient
    C(line, i)   = line! / ( (line-i)! * i! )
    line par line
    """
    res = 1
    if (k > n - k):
        k = n - k
    for i in range(0, k):
        res = res * (n - i)
        res = res // (i + 1)

    return res


def pascal_triangle(n):
    """
     returns a list of lists of integers
     representing the Pascal triangle of n
    """
    triangle = []
    if n <= 0:
        return (triangle)
    for i in range(n):
        row = []
        for j in range(i+1):
            row.append(CofBinom(i, j))
        triangle.append(row)
    return triangle
