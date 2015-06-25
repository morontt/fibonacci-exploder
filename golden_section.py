#!/usr/bin/env python

import math

fi = (math.sqrt(5.0) + 1.0)/2

print 'epsilon: ',
eps = input()

print 'a: ',
a = input()

print 'b: ',
b = input()

x1 = b - (b - a)/fi
x2 = a + (b - a)/fi

print ''
print 'f[{}]: '.format(x1),
f1 = input()

print 'f[{}]: '.format(x2),
f2 = input()

while (b - a) > eps:
    if f1 >= f2:
        a = x1
        x1 = x2
        x2 = a + (b - a)/fi
        f1 = f2
        print 'f[{}]: '.format(x2),
        f2 = input()
    else:
        b = x2
        x2 = x1
        x1 = b - (b - a)/fi
        f2 = f1
        print 'f[{}]: '.format(x1),
        f1 = input()

print ''
print 'result: ', (a + b)/2
