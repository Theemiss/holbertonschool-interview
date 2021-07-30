#!/usr/bin/python3
""" Module that containes "canUnlockAll" function"""


def canUnlockAll(boxes):
    """
        You have n number of locked boxes in front of you. Each box is
        numbered sequentially from 0 to n
         - 1 and each box may contain keys to the other boxes.

        Write a method that determines if all the boxes can be opened.

        Prototype: def canUnlockAll(boxes)
        boxes is a list of lists
        A key with the same number as a box opens that box
        You can assume all keys will be positive integers
        There can be keys that do not have boxes
        The first box boxes[0] is unlocked
        Return True if all boxes can be opened, else return False
    """
    if (type(boxes) is not list):
        return False

    if (len(boxes) == 0):
        return False
    keysbox = [0]
    for key in keysbox:
        for j in boxes[key]:
            if j not in keysbox and j < len(boxes):
                keysbox.append(j)
    for i in range(len(boxes)):
        if i not in keysbox:
            return False
    return True
