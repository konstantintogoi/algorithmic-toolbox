# Uses python3
import sys


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


if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))

