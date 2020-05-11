#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();

    int max1 = -1, max2 = -2;
    for (int i = 0; i < n; ++i) {
        if (numbers[i] > max1) {
          max2 = max1;
          max1 = numbers[i];
        } else if (numbers[i] > max2) {
          max2 = numbers[i];
        }
    }

    return (long)max1 * (long)max2;
}

int MaxPairwiseProduct(const std::vector<int>& numbers) {
    int max_product = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = std::max(max_product,
                numbers[first] * numbers[second]);
        }
    }

    return max_product;
}

int test() {
    while (true) {
        int n = rand() % 1000 + 2;
        std::cout << n << "\n";
        std::vector<int> a;
        for (int i = 0; i < n; ++i) {
            a.push_back(rand() % 100000);
        }
        for (int i = 0; i < n; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            std::cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        }
        else {
            std::cout << "OK\n";
        }
    }
    return 0;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }

    std::cout << MaxPairwiseProductFast(numbers) << "\n";
    return 0;
}
