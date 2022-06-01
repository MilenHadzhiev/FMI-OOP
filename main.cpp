#include <iostream>

int calc(int a[5])
{
    int sum = 8;
    for (int i = 0; a[i]; ++i)
        sum += i;
    return sum;
}

int main() {
    int a[7] = {1, 2, 3};
    std::cout << calc(a);
    return 0;
}
