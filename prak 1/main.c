#include <stdio.h>

int main() {
    int detik, jam, menit, detik2;
    scanf("%d", &detik);
    jam = detik / 3600;
    menit = (detik / 60) - jam * 60;
    detik2 = detik % 60;
    printf("%d detik = %d jam %d menit %d detik\n", detik, jam, menit, detik2);
    return 0;
}