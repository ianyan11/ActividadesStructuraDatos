//Ian De La Garza González a01283525

#include "priority_queue.h"

int main(int argc, char const *argv[])
{
    priority_queue miPF;
    miPF.push(100);
    miPF.push(200);
    miPF.push(150);
    miPF.push(250);
    miPF.push(410);
    miPF.push(50);
    miPF.push(660);
    miPF.push(900);
    miPF.push(800);
    miPF.push(1200);
    miPF.push(155);
    miPF.push(22);
    miPF.push(300);

    while (!miPF.empty())
    {
        //cout << miPF.top() << endl;
        miPF.pop();
        miPF.print();
    }
    return 0;
}
