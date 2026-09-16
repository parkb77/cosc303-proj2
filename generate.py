#!/usr/bin/env python3

import random
import sys

if len(sys.argv) != 3:
    print("usage: python3 generate.py SIZE OUTPUT")
    sys.exit(1)

size = int(sys.argv[1])
filename = sys.argv[2]

random.seed(303)

with open(filename, "w") as f:
    for _ in range(size):
        number = random.randint(0, 2000000000)
        f.write(str(number) + "\n")
