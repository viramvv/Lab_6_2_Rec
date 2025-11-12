#pragma once

// Включаємо необхідні бібліотеки
#include <iostream>

// Прототипи допоміжних функцій (створення та виведення)
void Create(int* a, const int size, const int low, const int high);
void Print(const int* a, const int size, const int i);

// -----------------------------------------------------------
// Функції для Варіанту 14 (Рекурсивний підхід)
// -----------------------------------------------------------
int CalculateOddIndexSum_Recursive_Helper(const int* a, const int size, int i, int currentSum);

int CalculateOddIndexSum_Recursive(const int* a, const int size);