#include <stdio.h>

int gcd(int num1, int num2) {
    if (num2 != 0)
    {
      int rem=num1%num2;
      return gcd(num2, rem);
    }
    else
    {
        return num1;
    }
}

int main() {
    int a, b;
    printf("Enter two positive Numbers: ");
    scanf("%d %d", &a, &b);
    printf("G.C.D is: %d", gcd(a, b));
    return 0;
}
