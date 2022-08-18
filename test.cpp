#include <iostream>

int main() {
    int i= 1,s = 1;
    while(s<100)
        s+=++i;
    printf("%d",i);
}

