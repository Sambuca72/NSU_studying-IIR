#include <stdio.h>

// Константы
#define PI 3.14159265358979323846
#define RAD_TO_DEG (180.0 / PI)
#define EPS 1e-12  // Точность вычислений

double my_fabs(double x) {
    return x < 0 ? -x : x;
}

// Функция для вычисления квадратного корня методом Ньютона
double my_sqrt(double x) {
    if (x < 0) return 0;  // Отрицательные значения обрабатываются как 0
    if (x < EPS) return 0; // Малые значения обрабатываем как 0
    double guess = x > 1 ? x : 1;  // Начальное приближение
    for (int i = 0; i < 30; i++) { // Ограничим итерации
        double next_guess = 0.5 * (guess + x / guess);
        if (my_fabs(next_guess - guess) < EPS) break;
        guess = next_guess;
    }
    return guess;
}

// Функция для вычисления абсолютного значения


// Быстро сходящийся ряд для arctan2
double my_arctan2(double y, double x) {
    if (my_fabs(x) < EPS) {
        return y > 0 ? PI / 2 : (y < 0 ? -PI / 2 : 0);
    }
    if (my_fabs(y) < EPS) {
        return x > 0 ? 0 : PI;
    }

    double angle = 0;
    if (x > 0) {
        angle = my_sqrt(x * x + y * y);
        return y > 0 ? angle : -angle;
    } else {
        angle = PI - my_sqrt(x * x + y * y);
        return y > 0 ? angle : -angle;
    }
}

// Функция для вычисления угла ∠BAC
double calculate_angle(double ax, double ay, double bx, double by, double cx, double cy) {
    // Векторы AB и AC
    double ab_x = bx - ax;
    double ab_y = by - ay;
    double ac_x = cx - ax;
    double ac_y = cy - ay;

    // Длины векторов
    double ab_length = my_sqrt(ab_x * ab_x + ab_y * ab_y);
    double ac_length = my_sqrt(ac_x * ac_x + ac_y * ac_y);

    // Скалярное произведение
    double dot_product = ab_x * ac_x + ab_y * ac_y;

    // Векторное произведение (в плоскости 2D это псевдоскаляр)
    double cross_product = ab_x * ac_y - ab_y * ac_x;

    // Косинус и синус угла
    double cos_theta = dot_product / (ab_length * ac_length);
    double sin_theta = cross_product / (ab_length * ac_length);

    // Угол в радианах
    double angle_rad = my_arctan2(my_fabs(sin_theta), cos_theta);

    // Переводим в градусы
    return angle_rad * RAD_TO_DEG;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int q;
    scanf("%d", &q);

    while (q--) {
        double ax, ay, bx, by, cx, cy;
        scanf("%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy);
        printf("%0.20g\n", calculate_angle(ax, ay, bx, by, cx, cy));
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
