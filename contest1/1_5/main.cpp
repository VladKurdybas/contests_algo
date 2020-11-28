#include <iostream>

class Squares {
public:
    uint64_t GetNext();
private:
    uint64_t sqr{0};
    uint64_t count{1};
};

uint64_t Squares::GetNext() {
    sqr += count;
    count += 2;
    return sqr;
}

int main() {
    int input;
    Squares s;
    std::cin >> input;
    for (int i = 0; i < input; ++i) {
        std::cout << s.GetNext() << " ";
    }
    return 0;
}