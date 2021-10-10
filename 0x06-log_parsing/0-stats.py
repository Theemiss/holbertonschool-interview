#!/usr/bin/python3
"""
Write a script that reads stdin line by line and computes metrics:
Input format: <IP Address> - [<date>] "GET /projects/260 HTTP/1.1"
<status code> <file size> (if the format is not this one,
the line must be skipped)
After every 10 lines and/or a keyboard interruption (CTRL + C),
 print these statistics from the beginning:
Total file size: File size: <total size>
where <total size> is the sum of all previous
<file size> (see input format above)
Number of lines by status code:
possible status code: 200, 301, 400, 401, 403, 404, 405 and 500
if a status code doesn’t appear or is not an integer,
don’t print anything for this status code
format: <status code>: <number>
status codes should be printed in ascending order
"""

import sys

STATUS = {'200': 0,
          '301': 0,
          '400': 0,
          '401': 0,
          '403': 0,
          '404': 0,
          '405': 0,
          '500': 0}

total_size = 0
n = 0
try:
    for argument in sys.stdin:
        arguments = argument.split(" ")
        if len(arguments) > 2:
            status = arguments[-2]
            file_size = int(arguments[-1])
            if status in STATUS:
                STATUS[status] += 1
            total_size += file_size
            n += 1
            if n == 10:
                print("File size: {:d}".format(total_size))
                for key, value in sorted(STATUS.items()):
                    if value != 0:
                        print("{}: {:d}".format(key, value))
                n = 0
except KeyboardInterrupt:
    pass
finally:
    print("File size: {:d}".format(total_size))
    for key, value in sorted(STATUS.items()):
        if value != 0:
            print("{}: {:d}".format(key, value))
