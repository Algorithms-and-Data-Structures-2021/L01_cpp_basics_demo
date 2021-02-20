#include <iostream>  // cout
#include <cstdio>    // printf

using namespace std;

int main() {

    // при инициализации переменной для нее автоматически выделяется
    // свободный участок памяти, объяем которого зависит от типа переменной
    int a = 7;  // выделяется участок памяти в 4 байта
    int b = 11;

    cout << "Variable a = " << a << endl;
    cout << "Variable b = " << b << endl;

    cout << "\nGetting pointers to variables a and b:" << endl;

    // в C++ мы можем получить адрес на участок памяти, где хранится переменная
    // для этого используется оператор &
    int *a_pointer = &a;  // получаем адрес в памяти, указатель на переменную типа int
    int *b_pointer = &b;  // переменная-указатель

    // int * - читаем справа налево: указатель на переменную типа int (* на int)
    // & - унарный оператор взятия адреса, ставится перед переменной
    // указатель - переменная, которая хранит значение адреса на участок памяти

    // Еще раз.
    // Под переменную выделяется участок памяти, у которой есть адрес (адрес это просто число).
    // Адрес переменной мы можем получить, используя оператор взятия адреса &.
    // Указатель - это переменная со значением адреса другой переменной.
    // Тип указателя должен соответствовать типу переменной, на которую он указывает!

    // выводим адрес переменной в стандартный поток вывода
    printf("Address of a: %d (HEX: %X)\n", a_pointer, a_pointer);
    printf("Address of b: %d (HEX: %X)\n", b_pointer, b_pointer);

    cout << "\nCopying data from a to c:" << endl;

    // так как теперь у нас есть указатель на участок памяти
    // мы можем захотеть получить данные, которые там хранятся (т.е. получить данные по указателю)
    // для этого используется оператор разыменования *
    int c = *a_pointer;  // создаем переменную и копируем в нее значение переменной на которую указывает указатель

    // оператор * возвращает значение переменной, хранящейся по данному адресу (указателю)
    // под переменную c выделяется новый участок памяти с другим адресом
    // в участок памяти c записывается (копируется) значение переменной a

    printf("Address of a: %d\n", &a);
    printf("Address of c: %d\n", &c);

    printf("Value of a: %d\n", a);
    printf("Value of c: %d\n", c);

    // заметьте, что адреса переменных a и c разные,
    // несмотря на то, что значения переменных одинаковые

    // изменение значения переменной, на которую указывает указатель;
    // обращаемся к элементу через оператор разыменования * и устанавливаем новое значение
    // через опретор = (равно)
    cout << "\nChanging value of a using a pointer:" << endl;

    *a_pointer = 100;

    printf("Address of a: %d\n", &a);
    printf("Value of a: %d\n", a);

    // есть ключевое слово, которое говорит, что указатель ни на что не указывает
    int * null_ptr = nullptr;  // Python: None, Java: null

    // проверка указателя
    if (null_ptr) {
        printf("Pointer is OK\n");
    } else {
        printf("\nPointer is nullptr\n");  // выполнится этот код
    }

    // или вот так
    if (!null_ptr) {
        printf("Pointer is nullptr (1)\n");  // выполнится этот код
    } else {
        printf("Pointer is OK\n");
    }

    // указатель на указатель
    // арифметика указателей

    return 0;
}