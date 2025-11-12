#include "lab_6_2_rec.h"
#include <iomanip>
#include <cstdlib>

// --- Реалізація допоміжних функцій ---

void Create(int* a, const int size, const int low, const int high) {
    for (int i = 0; i < size; ++i) {
        a[i] = low + rand() % (high - low + 1);
    }
}

void Print(const int* a, const int size, const int i) {
    if (i == size) {
        // Замість std::cout << std::endl; в .cpp-файлі краще не виводити нічого,
        // якщо ця функція викликається у тестах. В main вона може виводити.
        // Для чистоти тестування, можна її взагалі не використовувати у тестах.
        return;
    }

    std::cout << std::setw(4) << a[i];
    Print(a, size, i + 1);
}

// --- Реалізація функцій Варіанту 14 ---

int CalculateOddIndexSum_Recursive_Helper(const int* a, const int size, int i, int currentSum) {
    // Базовий випадок: дійшли до кінця масиву
    if (i == size) {
        return currentSum;
    }

    // Перевірка умови: чи є поточний індекс непарним?
    if (i % 2 != 0) {
        currentSum += a[i];
    }

    // Рекурсивний крок
    return CalculateOddIndexSum_Recursive_Helper(a, size, i + 1, currentSum);
}

int CalculateOddIndexSum_Recursive(const int* a, const int size) {
    // Запускаємо рекурсивний процес, починаючи з індексу 0 та початковою сумою 0
    return CalculateOddIndexSum_Recursive_Helper(a, size, 0, 0);
}