#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define MAX_N 30000

// Функция для проверки конфликтности масок
int is_conflicting(uint64_t a, uint64_t b) {
    return (a & b) != 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    scanf("%d", &n);
    uint64_t masks[MAX_N];
    
    // Чтение масок
    for (int i = 0; i < n; i++) {
        scanf("%llx", &masks[i]);
    }

    long long non_conflicting_pairs = 0;
    
    // Подсчет неконфликтующих пар
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (!is_conflicting(masks[i], masks[j])) {
                non_conflicting_pairs++;
            }
        }
    }

    printf("%lld\n", non_conflicting_pairs);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
