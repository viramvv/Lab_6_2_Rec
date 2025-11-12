# Мінімальна необхідна версія CMake
cmake_minimum_required(VERSION 3.16)
project(Lab_6_2_Rec) # Змініть назву проекту, якщо вона інша

set(CMAKE_CXX_STANDARD 17) # Використовуйте сучасний стандарт C++

# Знайдемо та підключимо Google Test
# Цей модуль входить до стандартної поставки CLion
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
# Переконайтеся, що ви викликаєте FetchContent_MakeAvailable(googletest)
# один раз у вашому головному CMakeLists.txt (якщо він ще не викликаний)
FetchContent_MakeAvailable(googletest)


# --- 1. Створення бібліотеки для функцій (lab_6_2_rec) ---

# Створюємо статичну бібліотеку з вашого файлу .cpp. Це зручно,
# оскільки цю бібліотеку можна буде підключити і до main, і до тестів.
add_library(lab_6_2_rec STATIC
        lab_6_2_rec.cpp
        lab_6_2_rec.h # Файли заголовків додавати не обов'язково, але це для зручності
)


# --- 2. Створення основного виконуваного файлу (main.cpp) ---

add_executable(lab_6_2_rec_app main.cpp)

# Прив'язуємо бібліотеку до основного виконуваного файлу
target_link_libraries(lab_6_2_rec_app
        lab_6_2_rec
)


# --- 3. Створення виконуваного файлу для тестів (UnitTest6) ---

add_executable(UnitTest6 UnitTest6.cpp)

# Прив'язуємо бібліотеки:
# - lab_6_2_rec: наша бібліотека з функціями, які ми тестуємо
# - gtest_main: бібліотека Google Test, яка містить функцію main для тестів
target_link_libraries(UnitTest6
        lab_6_2_rec
        gtest_main
        pthread # Може знадобитись для Linux/macOS
)
# Додаємо директорії для підключення заголовків gtest
target_include_directories(UnitTest6 PRIVATE ${gtest_SOURCE_DIR}/include)