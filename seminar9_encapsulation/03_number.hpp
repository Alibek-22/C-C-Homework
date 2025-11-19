#pragma once

#include <iostream>
#include <iomanip>
#include <string>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

    void resize(std::size_t new_capacity) {
        char* new_data = new char[new_capacity];
        for (std::size_t i = 0; i < size; ++i) {
            new_data[i] = data[i];
        }
        for (std::size_t i = size; i < new_capacity; ++i) {
            new_data[i] = 0;
        }
        delete[] data;
        data = new_data;
        capacity = new_capacity;
    }

public:
    // 1. Конструктор по умолчанию (число 0)
    Number() : data(new char[1]), size(1), capacity(1) {
        data[0] = 0;
    }

    // 2. Конструктор копирования
    Number(const Number& n) : data(new char[n.capacity]), size(n.size), capacity(n.capacity) {
        for (std::size_t i = 0; i < size; ++i) {
            data[i] = n.data[i];
        }
    }

    // 3. Конструктор из строки
    Number(const std::string& str) {
        if (str.empty()) {
            data = new char[1];
            data[0] = 0;
            size = capacity = 1;
            return;
        }

        // Вычисляем необходимый размер
        std::size_t str_size = str.size();
        capacity = (str_size + 1) / 2;
        if (capacity == 0) capacity = 1;
        data = new char[capacity];
        
        // Инициализируем нулями
        for (std::size_t i = 0; i < capacity; ++i) {
            data[i] = 0;
        }
        size = 0;

        // Преобразуем строку в число
        for (std::size_t i = 0; i < str_size; ++i) {
            char digit = str[str_size - 1 - i] - '0';
            
            // Умножаем текущее число на 10 и добавляем цифру
            int carry = digit;
            for (std::size_t j = 0; j < size || carry; ++j) {
                if (j == capacity) {
                    resize(capacity * 2);
                }
                if (j >= size) {
                    data[size++] = 0;
                }
                int product = data[j] * 10 + carry;
                data[j] = product % base;
                carry = product / base;
            }
        }
        
        // Убираем ведущие нули
        while (size > 1 && data[size - 1] == 0) {
            size--;
        }
    }

    // 4. Оператор присваивания
    Number& operator=(const Number& n) {
        if (this != &n) {
            delete[] data;
            capacity = n.capacity;
            size = n.size;
            data = new char[capacity];
            for (std::size_t i = 0; i < size; ++i) {
                data[i] = n.data[i];
            }
        }
        return *this;
    }

    // 5. Операторы сложения
    Number& operator+=(const Number& n) {
        std::size_t max_size = (size > n.size) ? size : n.size;
        if (max_size >= capacity) {
            resize(max_size + 1);
        }

        int carry = 0;
        for (std::size_t i = 0; i < max_size || carry; ++i) {
            if (i >= size) {
                data[size++] = 0;
            }

            int sum = data[i] + carry;
            if (i < n.size) {
                sum += n.data[i];
            }

            data[i] = sum % base;
            carry = sum / base;
        }

        return *this;
    }

    Number operator+(const Number& n) const {
        Number result(*this);
        result += n;
        return result;
    }

    // 7. Проверка на четность
    bool isEven() const {
        return (data[0] % 2) == 0;
    }

    // 8. Оператор умножения
    Number operator*(const Number& n) const {
        Number result;
        result.resize(size + n.size + 1);
        result.size = size + n.size;
        
        for (std::size_t i = 0; i < result.size; ++i) {
            result.data[i] = 0;
        }

        for (std::size_t i = 0; i < size; ++i) {
            int carry = 0;
            for (std::size_t j = 0; j < n.size || carry; ++j) {
                long long product = static_cast<long long>(data[i]) * 
                                  (j < n.size ? n.data[j] : 0) + 
                                  carry + result.data[i + j];
                result.data[i + j] = product % base;
                carry = product / base;
            }
        }
        
        // Убираем ведущие нули
        while (result.size > 1 && result.data[result.size - 1] == 0) {
            result.size--;
        }
        
        return result;
    }

    ~Number() {
        delete[] data;
    }

    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

// Функция для вычисления n-го числа Фибоначчи
Number fibonacci(int n) 
{
    if (n == 0) 
    {
        return Number("0");
    }
    
    if (n == 1) 
    {
        return Number("1");
    }
    
    Number a("0");
    Number b("1");
    Number c;
    
    for (int i = 2; i <= n; ++i) 
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    return b;
}

// Функция для вычисления факториала
Number factorial(int n) 
{
    Number res("1");
    
    for (int i = 2; i <= n; ++i) 
    {
        Number item(std::to_string(i));
        res = res * item;
    }
    return res;
}

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}
