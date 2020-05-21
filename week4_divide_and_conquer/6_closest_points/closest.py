#Uses python3
import sys
import math


def minimum_distance(x, y):
    #write your code here
    assert len(x) == len(y)
    if len(x) == 2:
        x1, x2 = x
        y1, y2 = y
        return math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
    if len(x) == 3:
        x1, x2, x3 = x
        y1, y2, y3 = y
        return min(
            math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2),
            math.sqrt((x2 - x3) ** 2 + (y2 - y3) ** 2),
            math.sqrt((x3 - x1) ** 2 + (y3 - y1) ** 2),
        )

    mid = len(x) // 2
    pairs = sorted(zip(x, y), key=lambda p: p[0])
    x, y = list(zip(*pairs))
    xmid = (x[mid - 1] + x[mid]) / 2

    d1 = minimum_distance(x[:mid], y[:mid])
    d2 = minimum_distance(x[mid:], y[mid:])
    d = min(d1, d2)

    pairs = sorted(
        (p for p in pairs if abs(xmid - p[0]) <= d),
        key=lambda p: p[1]
    )
    for i in range(len(pairs)):
        x1, y1 = pairs[i]
        for j in range(i + 1, min(len(pairs), i + 8)):
            x2, y2 = pairs[j]
            tmp = math.sqrt((x1 - x2) ** 2 + (y1 - y2) ** 2)
            if tmp < d:
                d = tmp

    return d


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    x = data[1::2]
    y = data[2::2]
    print("{0:.9f}".format(minimum_distance(x, y)))

