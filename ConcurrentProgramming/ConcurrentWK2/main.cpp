#include <iostream>
#include <thread>
#include <mutex>
#include <cmath>
#include <string>
#include "ThreadPool.h"

std::mutex mtxLock;


/* B E M P U S
 * b = Low Border of the range
 * e = High border of the range
 * m = the modulus for the m_check
 * p = amount of threads
 * u = Program mode
 * s = only used for search
 */
int b, e, m, p, u, s;

void execute(ThreadPool &pool);

int main() {

    std::cout << "Input Data: " << std::endl;
    scanf("%*d %d %d %d %d %d %d", &b, &e, &m, &p, &u, &s);

    ThreadPool pool(p);

    execute(pool);
}

bool m_Check(int iBan, const int &mRef) {
    int checkSum = 0;
    for (int i = 1; i <= log10(iBan) + 1; ++i) {
        checkSum += (iBan % 10) * i;
        iBan /= 10;
    }
    return checkSum % mRef == 0;
}

void execute(ThreadPool &pool) {
    int count = 0;
    bool found = false;
    for (int i = b; i < e; ++i) {
        pool.enqueue([i, &count, &found] {
            if (found) return;
            if (u == 2 && s == i) {
                found = true;
                std::cout << "Your number found: " << i << std::endl;
            }
            if (m_Check(i, m)) {
                std::scoped_lock lock(mtxLock);
                count++;
                if (u == 1)
                    std::cout << count << ' ' << i << std::endl;
            }
        });
    }
    std::this_thread::sleep_for(std::chrono::seconds(2));
    if (u == 0)
        std::cout << "count: " << count << std::endl;
    if (!found && u == 2)
        std::cout << "outside of given range" << std::endl;
}