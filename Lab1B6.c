#include <stdio.h>

void main() {
    int seconds = 0, hours = 0, minutes = 0;

    printf("Enter seconds: ");
    scanf("%d", &seconds);

    while (seconds >= 60) {
        if (seconds >= 3600) {
            seconds = seconds - 3600;
            hours++;
        } else if (seconds >= 60) {
            seconds = seconds - 60;
            minutes++;
        }
    }

    printf("%d:%d:%d\n", hours, minutes, seconds);
}
