#include <iostream>
#include <dlfcn.h>
#include <unistd.h>

// Предполагаемый тип функции из библиотеки (например, сложение)
typedef int (*add_func)(int, int);

int main() {
    std::cout << "Программа запущена, ждем 2 секунды..." << std::endl;
    sleep(2); // ждем 2 секунды

    // Загружаем динамическую библиотеку
    void* handle = dlopen("./libmiptlib.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Ошибка загрузки библиотеки: " << dlerror() << std::endl;
        return 1;
    }

    // Получаем указатель на функцию (например, add)
    add_func add = (add_func) dlsym(handle, "add");
    const char* dlsym_error = dlerror();
    if (dlsym_error) {
        std::cerr << "Ошибка поиска символа: " << dlsym_error << std::endl;
        dlclose(handle);
        return 1;
    }

    // Используем функцию
    int result = add(5, 3);
    std::cout << "Результат вызова функции add(5,3): " << result << std::endl;

    dlclose(handle);
    return 0;
}
