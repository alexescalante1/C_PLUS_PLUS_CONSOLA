#include <iostream>
#include <winbgim.h>
using namespace std;

int main()
{
    initwindow(700,600);
    while(!kbhit()){
        settextstyle(0,0,2);
        outtext("Simple cubo");
        setcolor(1);
        delay(10);
        rectangle(100,100,300,300);
        setcolor(3);
        delay(10);
        rectangle(200,200,400,400);
        setcolor(5);
        delay(10);
        line(100,100,200,200);
        line(100,300,200,400);
        setcolor(7);
        delay(10);
        line(300,100,400,200);
        line(300,300,400,400);
        delay(10);
        cleardevice();
    }
    getch();
    closegraph();
    return 0;
}
