# Uses python3


def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False


table = {}  # lookup table


def minmax(ds, i, j, ops):
    if (i, j) in table:
        return table[(i, j)]

    mn = float('inf') if ops[i:j] else int(ds[2 * i])
    mx = float('-inf') if ops[i:j] else int(ds[2 * i])

    for k in range(i, j):
        op = ops[k]
        mn1, mx1 = minmax(ds, i, k, ops)
        mn2, mx2 = minmax(ds, k + 1, j, ops)

        a = evalt(mx1, mx2, ops[k])
        b = evalt(mx1, mn2, ops[k])
        c = evalt(mn1, mx2, ops[k])
        d = evalt(mn1, mn2, ops[k])

        mn = min(mn, a, b, c, d)
        mx = max(mx, a, b, c, d)

    table[(i, j)] = mn, mx
    return mn, mx


def get_maximum_value(ds):
    #write your code here
    n = len(ds) // 2 + 1
    ops = [ds[i] for i in range(1, len(ds), 2)]
    mns = [[0 for _ in range(n)] for _ in range(n)]
    mxs = [[0 for _ in range(n)] for _ in range(n)]

    for i in range(n):
        mns[i][i] = int(ds[2 * i])
        mxs[i][i] = int(ds[2 * i])

    for s in range(1, n):
        for i in range(n - s):
            j = i + s
            mns[i][j], mxs[i][j] = minmax(ds, i, j, ops)

    return mxs[0][-1]


if __name__ == "__main__":
    print(get_maximum_value(input()))

