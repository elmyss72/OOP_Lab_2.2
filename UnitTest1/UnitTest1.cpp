
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.2/Stack.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTests
{
    TEST_CLASS(StackTests)
    {
    public:

        // 1. Перевірка конструктора за замовчуванням
        TEST_METHOD(DefaultConstructor_CreatesEmptyStack)
        {
            Stack s;

            Assert::IsTrue(s.IsEmpty());
            Assert::AreEqual(0, s.GetCount());
        }

        // 2. Перевірка конструктора з одним елементом
        TEST_METHOD(ConstructorWithValue_CreatesStack)
        {
            Stack s(10);

            Assert::IsFalse(s.IsEmpty());
            Assert::AreEqual(1, s.GetCount());
            Assert::AreEqual(10, s.Top());
        }

        // 3. Перевірка Push
        TEST_METHOD(Push_AddsElementToTop)
        {
            Stack s;

            s.Push(10);
            s.Push(20);

            Assert::AreEqual(2, s.GetCount());
            Assert::AreEqual(20, s.Top());
        }

        // 4. Перевірка Pop
        TEST_METHOD(Pop_RemovesTopElement)
        {
            Stack s;

            s.Push(10);
            s.Push(20);

            int removed = s.Pop();

            Assert::AreEqual(20, removed);
            Assert::AreEqual(1, s.GetCount());
            Assert::AreEqual(10, s.Top());
        }

        // 5. Перевірка Pop для порожнього стеку
        TEST_METHOD(Pop_EmptyStackReturnsZero)
        {
            Stack s;

            int result = s.Pop();

            Assert::AreEqual(0, result);
            Assert::IsTrue(s.IsEmpty());
            Assert::AreEqual(0, s.GetCount());
        }

        // 6. Перевірка Top
        TEST_METHOD(Top_ReturnsTopElementWithoutRemovingIt)
        {
            Stack s;
            s.Push(15);
            s.Push(25);

            Assert::AreEqual(25, s.Top());
            Assert::AreEqual(2, s.GetCount());
        }

        // 7. Перевірка Top для порожнього стеку
        TEST_METHOD(Top_EmptyStackReturnsZero)
        {
            Stack s;

            Assert::AreEqual(0, s.Top());
            Assert::IsTrue(s.IsEmpty());
        }

        // 8. Перевірка конструктора копіювання
        TEST_METHOD(CopyConstructor_CopiesElements)
        {
            Stack original;
            original.Push(10);
            original.Push(20);
            original.Push(30);

            Stack copy(original);

            Assert::IsTrue(copy == original);
            Assert::AreEqual(3, copy.GetCount());
            Assert::AreEqual(30, copy.Top());
        }

        // 9. Перевірка незалежності копії
        TEST_METHOD(CopyConstructor_CreatesIndependentStack)
        {
            Stack original;
            original.Push(10);
            original.Push(20);

            Stack copy(original);
            copy.Pop();
            copy.Push(99);

            Assert::AreEqual(20, original.Top());
            Assert::AreEqual(99, copy.Top());
            Assert::AreEqual(2, original.GetCount());
        }

        // 10. Перевірка оператора присвоєння
        TEST_METHOD(AssignmentOperator_CopiesStack)
        {
            Stack first;
            first.Push(10);
            first.Push(20);

            Stack second;
            second.Push(100);

            second = first;

            Assert::IsTrue(first == second);
            Assert::AreEqual(2, second.GetCount());
            Assert::AreEqual(20, second.Top());
        }

        // 11. Перевірка присвоєння самому собі
        TEST_METHOD(AssignmentOperator_SelfAssignment)
        {
            Stack s;
            s.Push(10);
            s.Push(20);

            s = s;

            Assert::AreEqual(2, s.GetCount());
            Assert::AreEqual(20, s.Top());
        }

        // 12. Перевірка оператора +
        TEST_METHOD(OperatorPlus_AddsElementToCopiedStack)
        {
            Stack s1;
            s1.Push(10);
            s1.Push(20);

            Stack s2 = s1 + 30;

            Assert::AreEqual(3, s2.GetCount());
            Assert::AreEqual(30, s2.Top());

            // Оригінал не змінюється
            Assert::AreEqual(2, s1.GetCount());
            Assert::AreEqual(20, s1.Top());
        }

        // 13. Перевірка оператора +=
        TEST_METHOD(OperatorPlusAssign_AddsElementToCurrentStack)
        {
            Stack s;
            s.Push(10);

            Stack& result = (s += 20);

            Assert::AreEqual(2, s.GetCount());
            Assert::AreEqual(20, s.Top());
            Assert::IsTrue(&result == &s);
        }

        // 14. Перевірка оператора *
        TEST_METHOD(OperatorMultiply_MultipliesTopElement)
        {
            Stack s1;
            s1.Push(10);
            s1.Push(5);

            Stack s2 = s1 * 3;

            Assert::AreEqual(15, s2.Top());
            Assert::AreEqual(2, s2.GetCount());

            // Початковий стек не змінюється
            Assert::AreEqual(5, s1.Top());
        }

        // 15. Множення порожнього стеку
        TEST_METHOD(OperatorMultiply_EmptyStack)
        {
            Stack s1;

            Stack s2 = s1 * 5;

            Assert::IsTrue(s2.IsEmpty());
            Assert::AreEqual(0, s2.GetCount());
        }

        // 16. Перевірка оператора ==
        TEST_METHOD(OperatorEqual_IdenticalStacks)
        {
            Stack s1;
            Stack s2;

            s1.Push(10);
            s1.Push(20);

            s2.Push(10);
            s2.Push(20);

            Assert::IsTrue(s1 == s2);
        }

        // 17. Перевірка оператора !=
        TEST_METHOD(OperatorNotEqual_DifferentStacks)
        {
            Stack s1;
            Stack s2;

            s1.Push(10);
            s2.Push(20);

            Assert::IsTrue(s1 != s2);
        }

        // 18. Стек однакової довжини, але різний порядок
        TEST_METHOD(OperatorEqual_DifferentOrder)
        {
            Stack s1;
            Stack s2;

            s1.Push(10);
            s1.Push(20);

            s2.Push(20);
            s2.Push(10);

            Assert::IsFalse(s1 == s2);
            Assert::IsTrue(s1 != s2);
        }

        // 19. Перевірка перетворення на string
        TEST_METHOD(StringConversion_ReturnsStackContents)
        {
            Stack s;
            s.Push(10);
            s.Push(20);

            std::string result = static_cast<std::string>(s);

            Assert::AreEqual(
                std::string("[ВЕРШИНА] -> 20 10 "),
                result
            );
        }

        // 20. Перевірка виведення порожнього стеку
        TEST_METHOD(StringConversion_EmptyStack)
        {
            Stack s;

            std::string result = static_cast<std::string>(s);

            Assert::AreEqual(
                std::string("[Порожній стек]"),
                result
            );
        }

        // 21. Перевірка оператора <<
        TEST_METHOD(OutputOperator_PrintsStack)
        {
            Stack s;
            s.Push(10);
            s.Push(20);

            std::ostringstream out;
            out << s;

            Assert::AreEqual(
                std::string("[ВЕРШИНА] -> 20 10 "),
                out.str()
            );
        }
    };
}
