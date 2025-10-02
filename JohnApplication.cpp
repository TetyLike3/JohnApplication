#include <iostream>
#include <thread>

void spawnWindow()
{
    system("start cmd /k echo :(");
}

void onCrash()
{
    using std::thread;
    for (int i = 0; i < 10; i++) {
        thread windowThread(spawnWindow);
    }
}

int main()
{
    using std::cout;
    cout << "It's me John Application\n";
    cout << "Please don't crash me or anything that would be mean\n";

    try {
        float input;
        cout << "Can you give me a number: ";
        auto& result = std::cin >> input;
        if (!result.good()) throw 1;
    }
    catch (...) {
        onCrash();
        return 1;
    }

    cout << ":) \n";
    return 0;
}
