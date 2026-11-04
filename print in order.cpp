#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>
using namespace std;

class Foo {
    mutex m;
    condition_variable cv;
    int step = 1;

public:
    Foo() {}

    void first(function<void()> printFirst) {
        unique_lock<mutex> lock(m);
        printFirst();
        step = 2;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return step == 2; });
        printSecond();
        step = 3;
        cv.notify_all();
    }

    void third(function<void()> printThird) {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [this] { return step == 3; });
        printThird();
    }
};