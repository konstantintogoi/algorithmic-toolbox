# Uses python3
import sys


table = [
    (),
    (1, ),  # recursion base
    (1, 2),  # multiply by 3
    (1, 3), # multiply by 3
]


def fast_optimal_sequence(n):
    for i in range(4, n + 1):
        s1 = table[i // 3] if i % 3 == 0 else ()
        s2 = table[i // 2] if i % 2 == 0 else ()
        s3 = table[i - 1]

        k = min(len(s1) or float('inf'), len(s2) or float('inf'), len(s3))

        if k == len(s1):
            table.append(s1 + (s1[-1] * 3, ))
        elif k == len(s2):
            table.append(s2 + (s2[-1] * 2, ))
        else:
            table.append(s3 + (s3[-1] + 1, ))

    return table[n]


def optimal_sequence(n):
    sequence = []
    while n >= 1:
        sequence.append(n)
        if n % 3 == 0:
            n = n // 3
        elif n % 2 == 0:
            n = n // 2
        else:
            n = n - 1
    return reversed(sequence)


input = sys.stdin.read()
n = int(input)
sequence = list(fast_optimal_sequence(n))
print(len(sequence) - 1)
for x in sequence:
    print(x, end=' ')
print()

