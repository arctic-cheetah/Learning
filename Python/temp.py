from itertools import permutations, combinations
import random
import numpy as np
a = np.array([1,2,3])
for p in permutations(a):
    print(p)

pool = []
for comb in combinations(a, 2):
    pool.append(comb)
random.sample(pool, 3)