#include "Stack.h"

// --- Приватні допоміжні методи ---
void Stack::CopyFrom(const Stack& other) {
    if (!other.head) {
        head = nullptr;
        count = 0;
        return;
    }
    head = new Elem(other.head->data);
    Elem* curr = head;
    Elem* otherCurr = other.head->next;

    while (otherCurr) {
        curr->next = new Elem(otherCurr->data);
        curr = curr->next;
        otherCurr = otherCurr->next;
    }
    count = other.count;
}

void Stack::Free() {
    while (!IsEmpty()) {
        Pop();
    }
}

// --- Конструктори та деструктор ---
Stack::Stack() : head(nullptr), count(0) {}

Stack::Stack(int first_value) : head(nullptr), count(0) {
    Push(first_value);
}

Stack::Stack(const Stack& other) {
    CopyFrom(other);
}

Stack::~Stack() {
    Free();
}

// --- Методи доступу ---
void Stack::Push(int value) {
    head = new Elem(value, head);
    count++;
}

int Stack::Pop() {
    if (IsEmpty()) {
        cerr << "Помилка: стек порожній!" << endl;
        return 0;
    }
    Elem* temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;
    count--;
    return value;
}

int Stack::Top() const {
    if (IsEmpty()) {
        cerr << "Помилка: стек порожній!" << endl;
        return 0;
    }
    return head->data;
}

int Stack::GetCount() const {
    return count;
}

bool Stack::IsEmpty() const {
    return head == nullptr;
}

// --- Перевантаження операцій (методи класу) ---
Stack& Stack::operator=(const Stack& other) {
    if (this != &other) {
        Free();
        CopyFrom(other);
    }
    return *this;
}

Stack Stack::operator+(int value) const {
    Stack result(*this);
    result.Push(value);
    return result;
}

Stack& Stack::operator+=(int value) {
    Push(value);
    return *this;
}

bool Stack::operator==(const Stack& other) const {
    if (count != other.count) return false;

    Elem* curr1 = head;
    Elem* curr2 = other.head;

    while (curr1 && curr2) {
        if (curr1->data != curr2->data) return false;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return true;
}

bool Stack::operator!=(const Stack& other) const {
    return !(*this == other);
}

Stack::operator string() const {
    stringstream ss;
    if (IsEmpty()) {
        return "[Порожній стек]";
    }
    Elem* curr = head;
    ss << "[ВЕРШИНА] -> ";
    while (curr) {
        ss << curr->data << " ";
        curr = curr->next;
    }
    return ss.str();
}

// --- Перевантаження операцій (дружні функції) ---
Stack operator*(Stack& s, int value) {
    Stack result(s);
    if (!result.IsEmpty()) {
        result.head->data *= value;
    }
    return result;
}

ostream& operator<<(ostream& out, const Stack& s) {
    out << string(s);
    return out;
}

istream& operator>>(istream& in, Stack& s) {
    int n, val;
    cout << "Скільки елементів хочете додати у стек? ";
    in >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << (i + 1) << ": ";
        in >> val;
        s.Push(val);
    }
    return in;
}