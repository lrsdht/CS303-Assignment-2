#include <iostream>
#include <vector>
#include <numeric>
#include <iomanip>

using namespace std;

class Stack {
private:
    vector<int> data;

public:
    bool isEmpty() const {
        return data.empty();
    }

    void push(int value) {
        data.push_back(value);
    }

    void pop() {
        if (!isEmpty()) {
            data.pop_back();
        }
    }

    int top() const {
        if (!isEmpty()) {
            return data.back();
        }
        throw runtime_error("Stack is empty");
    }

    double average() const {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        double sum = std::accumulate(data.begin(), data.end(), 0.0);
        return sum / data.size();
    }
};
