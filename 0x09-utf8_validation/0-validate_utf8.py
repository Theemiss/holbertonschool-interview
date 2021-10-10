#!/usr/bin/python3
"""
determines if a given data set represents a valid UTF-8 encoding.
"""


def validUTF8(data):
    """
    determines if a given data set represents a valid UTF-8 encoding.
    """
    n = 0
    for d in data:
        r = format(d, '#010b')[-8:]
        if n == 0:
            for bit in r:
                if bit == '0':
                    break
                n += 1
            if n == 0:
                continue
            if n == 1 or n > 4:
                return False
        else:
            if not (r[0] == '1' and r[1] == '0'):
                return False
        n = n - 1
    if not n:
        return True
    else:
        return False
