import sys, random

from time import *

N = 2048

A = [[random.random()
      for row in xrange (N)]
     for col in xrange (N)]

B = [[random.random()
      for row in xrange (N)]
     for col in xrange (N)]

C = [[0 for row in xrange (N)]
     for col in xrange(N)]

start = time()
for i in xrange(N):
    for j in xrange(N):
        for k in xrange(N):
            C[i][j]+=A[i][k] * B[k][j]
end = time()

print "%0.6f" % (end - start)

