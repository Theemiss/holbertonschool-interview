#!/usr/bin/python3
"""
Prime Game
"""


def Prime(num):
    '''
    if a number is prime Return True Otherwise False
    '''
    if num > 1:
        for i in range(2, int(num/2)+1):
            if (num % i) == 0:
                return False
        return True
    else:
        return False


def isWinner(x, nums):
    """
    Prime Game
    """
    rounds = {
        "Maria": 0,
        "Ben": 0
    }
    t = 0
    for i in range(x):
        choices = [i for i in range(1, nums[i] + 1)]
        for j in choices:
            if (Prime(j)):
                for k in choices:
                    if k % j == 0:
                        choices.remove(k)
                    t = t + 1 % 2
        if t == 0:
            rounds["Maria"] += 1
            t = 1
        else:
            rounds["Ben"] += 1
            t = 0

    if rounds["Maria"] > rounds["Ben"]:
        return "Ben"
    elif rounds["Maria"] < rounds["Ben"]:
        return "Maria"
    else:
        return None
