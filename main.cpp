#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
int current_thread = 1; // 現在のスレッド番号

void PrintThread(int id, const std::string& message)
{
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return current_thread == id; }); // 現在のスレッドが実行可能になるまで待機
    std::cout << message << std::endl;
    current_thread = (current_thread % 3) + 1; // 次のスレッドに進む (1, 2, 3の循環)
    cv.notify_all();  // ほかのスレッドを通知
}

int main()
{
    std::thread t1(PrintThread, 1, "Thread1");
    std::thread t2(PrintThread, 2, "Thread2");
    std::thread t3(PrintThread, 3, "Thread3");
   
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
