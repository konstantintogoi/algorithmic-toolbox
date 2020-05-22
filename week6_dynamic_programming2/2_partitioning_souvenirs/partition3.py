# Uses python3
import sys
import itertools


table = {}  # lookup table


def optimal_weight(W, w):
    # write your code here
    if len(w) == 1:
        return w[0] if W >= w[0] else 0

    if (W, len(w)) in table:
        return table[(W, len(w))]

    *weights, lw = w
    w1 = optimal_weight(W - lw, weights) + lw if W >= lw else float('-inf')
    w2 = optimal_weight(W, weights)

    ret = max(w1, w2)
    table[(W, len(w))] = ret

    return ret


def fast_partition3(A):
    sA = sum(A)
    if sA % 3 != 0:
        return 0
    else:
        psum = sA // 3

    global table
    for i in range(1, len(A) - 1):
        table = {}
        for c in itertools.combinations(A, i):
            if sum(c) == psum:
                tmp = list(A)
                for n in c:
                    tmp.remove(n)
                if optimal_weight(psum, tmp) == psum:
                    return 1

    return 0


def partition3(A):
    for c in itertools.product(range(3), repeat=len(A)):
        sums = [None] * 3
        for i in range(3):
            sums[i] = sum(A[k] for k in range(len(A)) if c[k] == i)

        if sums[0] == sums[1] and sums[1] == sums[2]:
            return 1

    return 0

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *A = list(map(int, input.split()))
    print(fast_partition3(A))

