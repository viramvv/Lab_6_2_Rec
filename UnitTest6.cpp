#include "gtest/gtest.h"
#include "lab_6_2_rec.h" // Підключаємо наш файл заголовків

// -------------------------------------------------------------
// Тести для функції CalculateOddIndexSum_Recursive (Варіант 14)
// -------------------------------------------------------------

// Тестовий набір 1: Базові перевірки (позитивні та нульові значення)
TEST(OddIndexSumTest, BasicCases) {
    // Масив: [10, 1, 20, 2, 30, 3]
    // Індекси: 0,  1, 2,  3, 4,  5
    // Непарні індекси (1, 3, 5): 1, 2, 3
    // Очікувана сума: 1 + 2 + 3 = 6
    int a1[] = {10, 1, 20, 2, 30, 3};
    int n1 = sizeof(a1) / sizeof(a1[0]);
    EXPECT_EQ(6, CalculateOddIndexSum_Recursive(a1, n1));

    // Масив: [1, 5, 1, 5, 1, 5]
    // Непарні індекси (1, 3, 5): 5, 5, 5
    // Очікувана сума: 5 + 5 + 5 = 15
    int a2[] = {1, 5, 1, 5, 1, 5};
    int n2 = sizeof(a2) / sizeof(a2[0]);
    EXPECT_EQ(15, CalculateOddIndexSum_Recursive(a2, n2));
}

// Тестовий набір 2: Перевірка з негативними числами
TEST(OddIndexSumTest, NegativeNumbers) {
    // Масив: [10, -1, 20, -2, 30, -3]
    // Непарні індекси (1, 3, 5): -1, -2, -3
    // Очікувана сума: -1 + (-2) + (-3) = -6
    int a3[] = {10, -1, 20, -2, 30, -3};
    int n3 = sizeof(a3) / sizeof(a3[0]);
    EXPECT_EQ(-6, CalculateOddIndexSum_Recursive(a3, n3));

    // Масив: [1, -5, 1, -5]
    // Непарні індекси (1, 3): -5, -5
    // Очікувана сума: -5 + (-5) = -10
    int a4[] = {1, -5, 1, -5};
    int n4 = sizeof(a4) / sizeof(a4[0]);
    EXPECT_EQ(-10, CalculateOddIndexSum_Recursive(a4, n4));
}

// Тестовий набір 3: Крайові випадки (Edge Cases)
TEST(OddIndexSumTest, EdgeCases) {
    // Крайній випадок 1: Пустий масив
    int a5[] = {};
    int n5 = 0;
    EXPECT_EQ(0, CalculateOddIndexSum_Recursive(a5, n5)); // Сума має бути 0

    // Крайній випадок 2: Масив з одним елементом (немає непарних індексів)
    // Масив: [100]
    // Індекси: 0
    // Очікувана сума: 0
    int a6[] = {100};
    int n6 = 1;
    EXPECT_EQ(0, CalculateOddIndexSum_Recursive(a6, n6));

    // Крайній випадок 3: Масив з елементами, які не додаються (нулі на непарних індексах)
    // Масив: [10, 0, 20, 0, 30]
    // Непарні індекси (1, 3): 0, 0
    // Очікувана сума: 0 + 0 = 0
    int a7[] = {10, 0, 20, 0, 30};
    int n7 = 5;
    EXPECT_EQ(0, CalculateOddIndexSum_Recursive(a7, n7));
}