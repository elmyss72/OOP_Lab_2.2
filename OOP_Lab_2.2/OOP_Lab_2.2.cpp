#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    cout << "=== Демонстрація розміру об'єкта (вирівнювання) ===" << endl;
    cout << "Розмір Stack (без #pragma pack): " << sizeof(Stack) << " байт" << endl;
    cout << "Розмір StackPacked (з #pragma pack(1)): " << sizeof(StackPacked) << " байт" << endl;
    cout << "---------------------------------------------------" << endl << endl;

    Stack s1;
    cout << "=== Ініціалізація першого стеку ===" << endl;
    cin >> s1;
    cout << "Стек s1: " << s1 << endl << endl;

    int valToAdd;
    cout << "Введіть число, яке хочете додати до s1 через операцію (+): ";
    cin >> valToAdd;
    Stack s2 = s1 + valToAdd; // Виклик конструктора копіювання та operator+
    cout << "Стек s2 (результат s1 + " << valToAdd << "): " << s2 << endl;
    cout << "Оригінальний s1: " << s1 << endl << endl;

    int valToMult;
    cout << "Введіть число, на яке хочете помножити вершину s2 (операція *): ";
    cin >> valToMult;
    Stack s3 = s2 * valToMult;
    cout << "Стек s3 (результат s2 * " << valToMult << "): " << s3 << endl << endl;

    int valToAddAssign;
    cout << "Введіть число, яке хочете додати до s1 через операцію (+=): ";
    cin >> valToAddAssign;
    s1 += valToAddAssign;
    cout << "Оновлений s1: " << s1 << endl << endl;

    cout << "=== Перевірка порівняння (== та !=) ===" << endl;
    cout << "Чи s1 == s2 ? " << (s1 == s2 ? "Так" : "Ні") << endl;

    cout << "\nПрисвоєння s2 = s1..." << endl;
    s2 = s1;
    cout << "Стек s1: " << s1 << endl;
    cout << "Стек s2: " << s2 << endl;
    cout << "Чи s1 == s2 ? " << (s1 == s2 ? "Так" : "Ні") << endl;

    cout << "\n=== Тестування вилучення (Pop) ===" << endl;
    if (!s1.IsEmpty()) {
        cout << "Вилучено зі стеку s1: " << s1.Pop() << endl;
        cout << "Стек s1 після вилучення: " << s1 << endl;
    }

    system("pause");
    return 0;
}