#include "lab_6_2_rec.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned int>(time(NULL)));

    const int n = 15; // Приклад розміру масиву
    int a[n];
    const int Low = -10;
    const int High = 30;

    // Створення та заповнення масиву
    Create(a, n, Low, High);

    // Виведення масиву (Використовуємо рекурсивне виведення, щоб показати роботу)
    std::cout << "Сформований масив:" << std::endl;
    Print(a, n, 0); // Рекурсивне виведення масиву
    std::cout << std::endl;

    // Обчислення суми за допомогою рекурсивної функції
    int sum = CalculateOddIndexSum_Recursive(a, n);

    // Виведення результату
    std::cout << "Сума елементів з непарними індексами (1, 3, 5, ...): " << sum << std::endl;

    return 0;
}