#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// Допоміжна структура для демонстрації #pragma pack(1)
#pragma pack(push, 1)
struct StackPacked {
    void* head;
    int count;
};
#pragma pack(pop)

class Stack {
private:
    struct Elem {
        int data;
        Elem* next;
        Elem(int d, Elem* n = nullptr) : data(d), next(n) {}
    };

    Elem* head;
    int count;

    void CopyFrom(const Stack& other);
    void Free();

public:
    // Конструктори та деструктор
    Stack();
    Stack(int first_value);
    Stack(const Stack& other);
    ~Stack();

    // Методи доступу
    void Push(int value);
    int Pop();
    int Top() const;
    int GetCount() const;
    bool IsEmpty() const;

    // Перевантаження операцій (методи класу)
    Stack& operator=(const Stack& other);
    Stack operator+(int value) const;
    Stack& operator+=(int value);
    bool operator==(const Stack& other) const;
    bool operator!=(const Stack& other) const;
    operator string() const;

    // Перевантаження операцій (дружні функції)
    friend Stack operator*(Stack& s, int value);
    friend ostream& operator<<(ostream& out, const Stack& s);
    friend istream& operator>>(istream& in, Stack& s);
};