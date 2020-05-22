# Uses python3
from pprint import pprint


def edit_distance(s, t):
    #write your code here
    d = [[i] + [0] * len(t) for i in range(len(s) + 1)]
    d[0] = [i for i in range(len(t) + 1)]

    for i in range(1, len(s) + 1):
        for j in range(1, len(t) + 1):
            if s[i - 1] == t[j - 1]:
                d[i][j] = d[i - 1][j - 1]
            else:
                d[i][j] = min(d[i][j - 1], d[i - 1][j], d[i - 1][j - 1]) + 1

    return d[-1][-1]


if __name__ == "__main__":
    print(edit_distance(input(), input()))

