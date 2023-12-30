#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <ncurses.h>

#include <termios.h>
#include <unistd.h>

void enableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag &= ~(ICANON | ECHO); // Turn off canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void disableRawMode() {
    termios term;
    tcgetattr(STDIN_FILENO, &term);
    term.c_lflag |= ICANON | ECHO; // Turn on canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &term);
}




void getKeyboard(std::promise<char>&& promiseObj) {
    
    char ch = getch();
    //std::cin.get(ch);
    promiseObj.set_value(ch);
}


int main() {
    //setting a timeout
    std::chrono::seconds timeout(3);
    // Create a std::promise object
    std::promise<char> promiseObj;

    // Fetch the std::future object associated with promise
    std::future<char> futureObj = promiseObj.get_future();

    // Starting a thread to run the lengthy operation
    std::thread th(lengthyOperation, std::move(promiseObj));

    std::cout << "Waiting for the result from the thread..." << std::endl;

    char result;
    // Fetching the result from std::future object. It will wait till the thread is finished.
    if(futureObj.wait_for(timeout) == std::future_status::ready)
      result = futureObj.get();

    std::cout << "The result is: " << result << std::endl;

    // Join the thread with the main thread
    th.join();

    return 0;
}
