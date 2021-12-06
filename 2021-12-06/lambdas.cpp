#include <functional>
#include <iostream>

void foo(std::function<void(int &)> modify) {
    static int x = 0;
    modify(x);
    std::cout << x << std::endl;
}

struct add_n {
    int n;

    add_n(int n) : n(n) {
    }

    void operator()(int &x) {
        x += n;
    }
};

struct set_n {
    int &n;

    set_n(int &n_orig) : n(n_orig) {
    }

    void operator()(int &x) const {
        x = n;
    }
};

int main() {
    add_n plus_one{1};
    add_n minus_two{-2};
    int x = 0;
    plus_one(x);
    foo(plus_one);
    foo(minus_two);
    foo([n = 0](int &x) mutable {
        n = 1;
        x = n;
    });

    return 0;
}
