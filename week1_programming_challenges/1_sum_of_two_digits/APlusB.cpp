#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <utility>

using namespace std;

int sum_of_two_digits(int first_digit, int second_digit) {
    return first_digit + second_digit;
}

void solution(istream& in, ostream& out) {
    int a, b;
    in >> a >> b;
    out << sum_of_two_digits(a, b) << endl;
}

void test() {
    pair <string, string> testcases[] {
        {"sample.input.txt", "sample.output.txt"}
    };

    for (auto testcase : testcases) {
        ifstream input (testcase.first), output (testcase.second);
        stringstream result;
        string ref;

        if (input.is_open()) {
            getline(output, ref, '\0');
            solution(input, result);
            output.close();
            input.close();

            cout << "test case (" << testcase.first << ',' << testcase.second << "): ";
            if (result.str() == ref) {
                cout << "passed" << endl;
            } else {
                cout << "failed" << endl;
                cout << result.str() << "!=" << endl;
                cout << ref;
            };
        } else {
            cout << "Unable to open file" << endl;
        }
    }

    return;
}

int main(int argc, char* argv[]) {
    if (argc > 1) test();
    else solution(cin, cout);
    return 0;
}
