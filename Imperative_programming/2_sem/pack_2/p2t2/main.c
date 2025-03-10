#include "modular.h"
#include <assert.h>
#include <stdio.h>

int main() {
    // Тест 1: Модуль 13
    MOD = 13;
    assert(pnorm(45) == 6);
    assert(pnorm(-1) == 12);
    assert(padd(7, 8) == 2);
    assert(psub(2, 3) == 12);
    assert(pmul(5, 3) == 2);
    int x = pmul(padd(7, psub(2, 3)), 5);
    assert(x == 4);
    int y = pdiv(7, x);
    assert(pmul(x, y) == 7);

    // Тест 2: Модуль 2
    MOD = 2;
    assert(pnorm(5) == 1);
    assert(padd(1, 1) == 0);
    assert(psub(1, 1) == 0);
    assert(pmul(1, 1) == 1);
    assert(pdiv(1, 1) == 1);

    // Тест 3: Большой модуль (999999937 — простое число < 10^9)
    MOD = 999999937;
    assert(pnorm(1000000000) == 63); // 10^9 % 999999937 = 63
    assert(padd(500000000, 500000000) == 63); // 10^9 % 999999937 = 63
    assert(pmul(500000000, 2) == 63); // 10^9 % 999999937 = 63
    assert(pdiv(63, 500000000) == 2); // 63 / 500000000 = 2 (проверка обратного)

}