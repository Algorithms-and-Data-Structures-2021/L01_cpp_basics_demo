#include <iostream>  // cout
#include <cstdio>    // printf
#include <array>
#include <cmath>     // pow

using namespace std;

int main() {

    int a = 3;  // переменная типа int со значением 3

    int a_copy = a;  // копия переменной типа int
    // переменная 'a_copy' не имеет ничего общего с переменной 'a' кроме значения

    int *a_pointer = &a;   // указатель на переменную типа int
    // указатель (переменная, которая хранит в себе адрес на переменную 'a')
    // мы можем получить доступ к переменной 'a' (изменить и прочесть ее значение)

    int &a_reference = a;  // ссылка на переменную типа int (int & - ссылка на int)

    // ссылка - это почти тоже самое, что и указатель
    // различия с указателем:
    // 1. не нужно использовать оператор разыменования * для получения доступа к данным по ссылке
    // 2. ссылка является неизменяемым типом данных, ее сразу необходимо инициализировать

    // после инициализации ссылка не может изменить своего значения
    // произойдет копирование значения 'b' в 'a'
    int b = 11;
    a_reference = b;

    // у ссылки так же, как и у самой переменной можно взять указатель,
    // указатель на переменную и на ссылку будет один и тот же,
    // т.е. по сути ссылка - это псевдоним (alias) для переменной
    printf("Address of 'a': %d\n", &a);
    printf("Address of 'a_copy': %d\n", &a_copy);
    printf("Address of 'a_reference': %d\n", &a_reference);

    cout << endl;

    // значение переменной по указателю и ссылке
    cout << "Value of 'a' by pointer: " << *a_pointer << endl;
    cout << "Value of 'a' by reference: " << a_reference << endl;  // просто и без лишних операторов

    cout << endl;

    // изменяем значения переменных по указателю и ссылке
    cout << "Changing the value of 'a':" << endl;

    *a_pointer = 2;   // через оператор разыменования

    cout << "Value of 'a': " << a << endl;

    a_reference = 1;  // по ссылке, никаких дополнительных операторов

    cout << "Value of 'a': " << a << endl;

    // примеры со ссылками
    array<int, 5> arr = {0, 1, 2, 3, 4};  // [0, 1, 2, 3, 4]

    array<int, 5> &arr_reference = arr;  // ссылка на массив

    // это просто копия, значения элемента массива не изменишь
    int arr_elem_copy = arr[3];

    // ссылка на элемент массива
    int &arr_elem_reference = arr[3];

    arr_elem_reference = -1;  // можем изменить значение элемента массива [0, 1, 2, -1, 4]
    // экивалентно записи: arr[3] = -1

    // пример с указателями
    int *a_pointer_copy = a_pointer;  // копия указателя на 'a'

    cout << endl;

    printf("Address of 'a_pointer': %X\n", &a_pointer);
    printf("Address of 'a_pointer_copy': %X\n", &a_pointer_copy);

    printf("Value at 'a_pointer': %d\n", *a_pointer);
    printf("Value at 'a_pointer_copy': %d\n", *a_pointer_copy);

    // если мы поменяем то, куда ссылается указатель 'a_pointer_copy', то с 'a_pointer' ничего не произойдет

    int *&a_pointer_ref = a_pointer;  // ссылка на указатель

    a_pointer_ref = &b;  // можем изменить то, на что ссылается указатель
    // эквивалентно записи: a_pointer = &b;

    a_pointer_ref = nullptr;  // теперь указатель 'a_pointer' нулевой

    cout << "a_pointer_ref = " << a_pointer << endl;  // выведится 0

    cout << endl;

    // for-each с использованиемм ссылок
    for (int &element_ref: arr) {
        element_ref = pow(element_ref, 2);  // возведение в степень 2

        cout << element_ref << '\t';
    }

    // arr = [0, 1, 4, 1, 16]

    cout << endl;

    return 0;
}