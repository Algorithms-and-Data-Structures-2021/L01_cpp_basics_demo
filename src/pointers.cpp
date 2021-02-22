#include <iostream>  // cout
#include <cstdio>    // printf

using namespace std;

int main() {

    // При инициализации переменной под нее автоматически выделяется
    // свободный участок памяти, размер которого зависит от типа переменной.
    // Например, под тип int выделится sizeof(int) байт (4 байта)
    int a = 7;
    int b = 11;

    cout << "Value of 'a' = " << a << endl;
    cout << "Value of 'b' = " << b << endl;

    cout << endl;

    cout << "Pointers to variables 'a' and 'b':" << endl;

    // в C++ мы можем получить адрес на участок памяти, в которой хранится переменная.
    // Для этого используется оператор & (амперсанд).
    // Адрес переменной хранится в новой переменной под названием "указатель".
    int *pointer_to_a = &a;  // получаем адрес в памяти, т.е. указатель на переменную типа int
    int *pointer_to_b = &b;

    // int * - читаем справа налево: указатель на переменную типа int (* на int);
    // & - унарный оператор взятия адреса, ставится перед переменной;
    // указатель - переменная, которая хранит в себе адрес на определенный участок памяти;
    // в зависимости от разрядности системы (32 или 64) под указатель выделяется 4 или 8 байт памяти.

    cout << "Size of a pointer: " << sizeof(int *) << " bytes" << endl;

    // Еще раз.
    // Под переменную выделяется участок памяти, у которой есть адрес (адрес это просто число).
    // Адрес переменной мы можем получить, используя оператор взятия адреса &.
    // Указатель - это переменная со значением адреса другой переменной.
    // Тип указателя должен соответствовать типу переменной, на которую он указывает!

    cout << endl;

    // выведем адрес переменной в стандартный поток вывода
    printf("Address of 'a': %d (HEX: %X)\n", pointer_to_a, pointer_to_a);
    printf("Address of 'b': %d (HEX: %X)\n", pointer_to_b, pointer_to_b);

    cout << endl;

    cout << "Copying data from 'a' to 'c':" << endl;

    // Теперь у нас есть указатель на определенный участок памяти.
    // Чтобы получить доступ к данным по указателю используется оператор разыменования * (звездочка).

    // чтение данных по указателю
    int c = *pointer_to_a;  // копируем в 'c' значение переменной, на которую ссылается указатель (т.е. значение 'a')

    printf("Address of 'a': %d\n", &a);
    printf("Address of 'c': %d\n", &c);

    printf("Value of 'a': %d\n", a);
    printf("Value of 'c': %d\n", c);

    cout << endl;

    // Заметьте, что адреса переменных 'a' и 'c' различаются, несмотря на то, что значения переменных одинаковые

    cout << "Changing value of 'a':" << endl;

    // изменение данных по указателю
    // обращаемся к элементу через оператор разыменования * и устанавливаем новое значение
    *pointer_to_a = 100;

    printf("Address of 'a': %d\n", &a);
    printf("Value of 'a': %d\n", a);

    // В С++ есть ключевое слово, которое обозначает, что указатель никуда не ссылается
    int *null_pointer = nullptr;  // Python: None, Java: null

    // проверка указателя на то, что он куда-то ссылается
    if (null_pointer) {
        printf("Pointer is not nullptr\n");
    }

    if (!null_pointer) {
        printf("\nPointer is nullptr\n");
    }

    /*
     * Так обычно не пишут, но тоже вариант:
     * if (null_pointer == nullptr) {}
     * if (null_pointer != nullptr) {}
     */

    cout << endl;

    // сравнение указателей (ссылаются ли они на один и тот же участок памяти)
    if (pointer_to_a == pointer_to_b) {
        cout << "pointer_to_a == pointer_to_b" << endl;
    } else {
        cout << "pointer_to_a != pointer_to_b" << endl;
    }

    // указатель на указатель

    int var = 1;

    // указатель на 'var'
    int *pointer_to_var = &var;  // переменная, значением которой является адрес 'var'

    // указатель на указатель на 'var'
    // переменная, значением которой является адрес указателя 'pointer_to_var'
    int **pointer_to_pointer_to_var = &pointer_to_var;

    // можно продолжать бесконечно ...
    int ***pointer_to_pointer_to_pointer_to_var = &pointer_to_pointer_to_var;

    // схема указателя на указатель концептуально выглядит следующим образом:
    // - указатель указывает на 'var'
    // - далее есть указатель на указатель, который ссылается на указатель на 'var' и т.д.
    // [pointer_to_pointer_to_pointer_to_var] -> [pointer_to_pointer_to_var] -> [pointer_to_var] -> [var]

    cout << endl;

    cout << "Pointer to pointer:" << endl;

    printf("Address of 'var': %X\n", &var);
    printf("Address of 'pointer_to_var': %X\n", &pointer_to_var);
    printf("Address of 'pointer_to_pointer_to_pointer_to_var': %X\n", &pointer_to_pointer_to_var);

    cout << "Value of 'var': " << *pointer_to_var << endl;

    // разыменовали указатель и получили указатель на 'var';
    // чтобы получить значение 'var' необходимо еше раз разыменовать указатель
    cout << "Value of 'var': " << *(*pointer_to_pointer_to_var) << endl;

    return 0;
}