#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <future>

void print(int i);
void assignment1();
void assignment2();
void assignment3();
void assignment4(int i);
void assignment6();
void keep_promise_too(std::promise<int>&& promise_obj);

std::mutex mutex;
std::condition_variable conditionVariable;
bool ready = false;
int input = 0;

int main() {
    assignment6();
    //std::cout << "input a number:" << std::endl;
    //std::cin >> input;
    //assignment4(input);
    return 0;
}


int printInt(int i){
    if(i == 115){
        return 42;
    }
    else
        return i;
}

//1ste question in homework
void assignment1(){
    std::thread thread_object(print, 115);
    thread_object.join();
}

//2nd question in homework
void assignment2(){
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(std::thread(print, i));
    }
    for (auto& stonks : threads) {
        stonks.join();
    }
}

void assignment3(){
    ready = true;
    conditionVariable.notify_all();
}

void assignment4(int i){
    std::future<int> getInt = std::async (printInt, i);
    int x = getInt.get();
    std::cout << x << " your number";
}

//Op6
void assignment6(){
    std::promise<int> promise_obj;

    std::future<int> result = promise_obj.get_future();
    std::thread t(keep_promise_too, std::move(promise_obj));

    result.wait();
    printf("%d\n", result.get());
    t.join();
}

void keep_promise_too(std::promise<int>&& promise_obj){
    promise_obj.set_value(rand());
}

void print(int i) {
    std::scoped_lock<std::mutex> scopedLock(mutex);
    std::cout << "stonks = " << i << std::endl;
}
