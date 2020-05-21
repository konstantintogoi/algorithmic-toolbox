# Uses python3
import sys


table = {}
denoms = [1, 3, 4]


def get_change(m):
    #write your code here
    if m < 0:
        return float('inf')
    if m in table:
        return table[m]
    if m in denoms:
        return 1

    ret = min(
        get_change(m - 1) + 1,
        get_change(m - 3) + 1,
        get_change(m - 4) + 1,
    )
    table[m] = ret
    return table[m]


if __name__ == '__main__':
    m = int(sys.stdin.read())
    print(get_change(m))

