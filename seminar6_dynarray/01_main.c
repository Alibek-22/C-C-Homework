#include <stdio.h>
#include "dynarray.h"

int main() 
{
    Dynarray a;
    init(&a, 0);
    for (size_t i = 0; i < 10; ++i)
    {
        push_back(&a, i);
    }
    printf("Initial dynarray: ");
    print(&a);

#if defined(TEST_POP_BACK) || defined(TEST_ALL)

    printf("==================== TEST_POP_BACK ====================\n");
    for (size_t i = 0; i < 3; ++i)
    {
        int result = pop_back(&a);
        printf("Extracted %i\n", result);
    }
    printf("Dynarray after pop_back test: ");
    print(&a);

    // Тестирование граничного случая - pop_back до пустого массива
    printf("--- Testing pop_back until empty ---\n");
    while (a.size > 0) {
        int result = pop_back(&a);
        printf("Extracted %i, size: %zu\n", result, a.size);
    }
    printf("Dynarray after emptying: ");
    print(&a);

    for (size_t i = 0; i < 5; ++i) {
        push_back(&a, i * 10);
    }
    printf("Restored dynarray: ");
    print(&a);

#endif

#if defined(TEST_RESIZE) || defined(TEST_ALL)

    printf("==================== TEST_RESIZE ====================\n");
    printf("Size and capacity before resize: %zu %zu\n", a.size, a.capacity);
    
    // Уменьшение размера
    resize(&a, 3);
    printf("After resize to 3: ");
    print(&a);
    printf("Size and capacity: %zu %zu\n", a.size, a.capacity);
    
    // Увеличение размера
    resize(&a, 8);
    printf("After resize to 8: ");
    print(&a);
    printf("Size and capacity: %zu %zu\n", a.size, a.capacity);
    
    // Увеличение до очень большого размера
    resize(&a, 20);
    printf("After resize to 20: ");
    print(&a);
    printf("Size and capacity: %zu %zu\n", a.size, a.capacity);

#endif

#if defined(TEST_SHRINK_TO_FIT) || defined(TEST_ALL)

    printf("==================== TEST_SHRINK_TO_FIT ====================\n");
    printf("Size and capacity before shrink_to_fit: %zu %zu\n", a.size, a.capacity);
    shrink_to_fit(&a);
    printf("Size and capacity after shrink_to_fit:  %zu %zu\n", a.size, a.capacity);
    printf("Dynarray after shrink_to_fit test: ");
    print(&a);

    // Тестирование shrink_to_fit на пустом массиве
    printf("--- Testing shrink_to_fit on empty array ---\n");
    Dynarray empty;
    init(&empty, 10);
    for (size_t i = 0; i < 3; ++i) {
        push_back(&empty, i);
    }
    printf("Before emptying: size=%zu, capacity=%zu\n", empty.size, empty.capacity);
    
    // Опустошаем массив
    while (empty.size > 0) {
        pop_back(&empty);
    }
    printf("After emptying: size=%zu, capacity=%zu\n", empty.size, empty.capacity);
    
    shrink_to_fit(&empty);
    printf("After shrink_to_fit: size=%zu, capacity=%zu\n", empty.size, empty.capacity);
    
    destroy(&empty);

#endif

#if defined(TEST_SHALLOW_COPY) || defined(TEST_ALL)

    printf("==================== TEST_SHALLOW_COPY ====================\n");
    Dynarray b = shallow_copy(&a);
    printf("Original dynarray a: ");
    print(&a);
    printf("Shallow copy b: ");
    print(&b);

    printf("Modifying original array a (adding 100 to all elements):\n");
    for (size_t i = 0; i < a.size; ++i)
        set(&a, i, get(&a, i) + 100);

    printf("After modification:\n");
    printf("Dynarray a: ");
    print(&a);
    printf("Dynarray b (shallow copy): ");
    print(&b);
    printf("Note: b changed because it shares data with a!\n");

    // Демонстрация проблемы с уничтожением
    printf("--- Warning: cannot destroy both a and b (double free) ---\n");
    printf("--- Only destroy one when using shallow copy ---\n");

#endif

#if defined(TEST_DEEP_COPY) || defined(TEST_ALL)

    printf("==================== TEST_DEEP_COPY ====================\n");
    Dynarray c = deep_copy(&a);
    printf("Original dynarray a: ");
    print(&a);
    printf("Deep copy c: ");
    print(&c);

    printf("Modifying original array a (adding 50 to all elements):\n");
    for (size_t i = 0; i < a.size; ++i)
        set(&a, i, get(&a, i) + 50);
    
    printf("After modification:\n");
    printf("Dynarray a: ");
    print(&a);
    printf("Dynarray c (deep copy): ");
    print(&c);
    printf("Note: c did NOT change because it has its own data!\n");

    // Тестирование глубокого копирования пустого массива
    printf("--- Testing deep copy of empty array ---\n");
    Dynarray empty2;
    init(&empty2, 0);
    Dynarray empty_copy = deep_copy(&empty2);
    printf("Empty original: size=%zu, capacity=%zu\n", empty2.size, empty2.capacity);
    printf("Empty deep copy: size=%zu, capacity=%zu\n", empty_copy.size, empty_copy.capacity);
    
    destroy(&empty2);
    destroy(&empty_copy);
    destroy(&c);

#endif

    // Очистка
    destroy(&a);
    
    // Внимание: не уничтожаем b, так как это shallow copy от a
    printf("Done\n");
    return 0;
}
