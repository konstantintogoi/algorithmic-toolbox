# Uses python3
import random
import sys
from collections import defaultdict


def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    # write your code here

    stag, ptag, etag = 1, 2, 3

    point2index = defaultdict(set)

    pairs = []
    for s in starts:
        pairs.append((s, stag))
    for e in ends:
        pairs.append((e, etag))
    for i, point in enumerate(points):
        pairs.append((point, ptag))
        point2index[point].add(i)

    sorted_pairs = sorted(pairs, key=lambda p: (p[0], p[1]))

    coverage = 0
    for point, tag in sorted_pairs:
        if tag == stag:
            coverage += 1
        if tag == etag:
            coverage -= 1
        if tag == ptag:
            ixs = point2index[point]
            for i in ixs:
                cnt[i] = coverage

    return cnt


def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt


def test():
    while True:
        n = random.randint(1, 5)
        m = random.randint(3, 5)
        print(n, m)

        starts, ends = [], []
        for i in range(n):
            a = random.randint(1, 10) - 5
            b = random.randint(1, 10) - 5
            if b < a:
                a, b = b, a
            elif a == b:
                b += 1
            starts.append(a)
            ends.append(b)
            print(a, b)

        points = []
        for i in range(m):
            point = random.randint(1, 10) - 5
            points.append(point)
            print(point, end=' ')
        print()

        naive = naive_count_segments(starts, ends, points)
        fast = fast_count_segments(starts, ends, points)

        if naive == fast:
            print('OK')
            print()
        else:
            print('Wrong answer')
            print(naive)
            print(fast)
            break


if __name__ == '__main__':
    # test()
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = fast_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')
    print()
