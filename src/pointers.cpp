#include <iostream>  // cout
#include <cstdio>    // printf

using namespace std;

int main() {

    int a = 7;
    int b = 11;

    cout << "Variable a = " << a << endl;
    cout << "Variable b = " << b << endl;

    // переменные на стеке с каким-то значением
    // у переменной есть адрес в памяти, который мы можем получить и использовать

    cout << "\nGetting pointers to variables a and b:" << endl;

    int *a_pointer = &a;  // получаем адрес в памяти, указатель
    int *b_pointer = &b;

    // int * - читаем справа налево: указатель (*) на переменную типа int
    // & - оператор взятия адреса, ставится перед переменной
    // указатель - указывает на участок памяти определенного размера (зависит от типа)

    // выводим адрес переменной в стандартный поток вывода
    printf("Address of a: %d (HEX: %X)\n", a_pointer, a_pointer);
    printf("Address of b: %d (HEX: %X)\n", b_pointer, b_pointer);

    cout << "\nCopying data from a to c:" << endl;

    int c = *a_pointer;  // создаем переменную со значением, которое хранится по адресу указателя

    // здесь используется оператор разыменовывания (*)
    // оператор * возвращает значение переменной, хранящейся по данному адресу (указателю)
    // под переменную c выделяется новый участок памяти с другим адресом
    // в участок памяти c записывается (копируется) значение переменной a

    printf("Address of a: %d\n", &a);
    printf("Address of c: %d\n", &c);

    printf("Value of a: %d\n", a);
    printf("Value of c: %d\n", c);

    // заметьте, что адреса переменных a и c разные,
    // несмотря на то, что значения одинаковы

    return 0;
}