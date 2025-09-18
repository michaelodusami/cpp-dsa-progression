#include <iostream>


int main()
{

    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 1;
        std::cout << "arr i: " << arr[i] << std::endl;
        if (arr[i] >= 5)
            goto miko;
    }

miko:
    std::cout << "transported to miko" << std::endl;

    return 0;
}