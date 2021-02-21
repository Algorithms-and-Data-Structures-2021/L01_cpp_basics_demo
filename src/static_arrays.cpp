#include <iostream>   // cout
#include <array>      // array
#include <algorithm>  // fill, copy

using namespace std;

int main() {

    // массив - это тип данных, который хранит
    // набор последовательных элементов одного типа
    // [5, 2, 7, 1, 9] - набор последовательно расположенных в памяти чисел одного типа

    // объявление статического массива (т.е. массива фиксированного размера)
    // компилятор не должен выдавать ошибку того, что массив не инициализирован (хотя, может и выдасть)
    // неинициализарованный массив может быть заполнен "мусором", т.е. случайными данными

    /* тип элементов */ int /* название массива */ int_arr[/* размер */ 5];

    // поэлементаная инициализация массива
    // доступ к элементу массива осуществляется при помощи оператора [] (квадратные скобки)

    int_arr[/* индекс элемента*/ 0] = /* новое значение */ -1;  // индексация начинается с 0
    int_arr[1] = 9;
    int_arr[2] = 1;
    int_arr[3] = 5;
    int_arr[4] = 3;

    // инициализация массива в момент его объявления
    int int_arr2[] = {1, 4, 2};         // вариант 1: без указания размера (размер вычисляется автоматически)
    int int_arr3[5] = {1, 4, 2, 5, 7};  // вариант 2: с указанием размера
    int int_arr4[5] = {};               // вариант 3: с указанием размера, инициализировать все нулями

    int arr_element = int_arr[/* индекс элемента */0];  // копируем значение нулевого элемента в переменную

    cout << "Accessing array elements:" << endl;

    cout << "arr_element[0]: " << arr_element << endl;

    // обращение к элементу за пределами массива не вызывает ошибку
    // возвращается "мусор" - данные где-то там в памяти (будьте внимательны!)
    cout << "arr_element[100]: " << int_arr[100] << endl;

    // работа с массивами в цикле
    cout << "\nFor loop with conditions:" << endl;

    for (int index = 0; index < 5; index++) {  // цикл по индексам от 0 до 4
        if (int_arr[index] <= 0) {
            continue;  // пропускаем неположительные элементы
        }

        if (index == 3) {
            // блок кода при индексе равным 3
            cout << "Processing the 3rd element of the array ..." << endl;
        }

        int_arr[index] *= -1;  // умножаем элемент массива на 2 и сохраняем новое значение обратно в массив
    }

    // for-each цикл без использования индекса для обращения к элементам массива
    cout << "\nFor-each loop int_arr:" << endl;

    for (int element : int_arr) {  // каждую итерацию в переменную element копируется следуюшее значение элемента массива
        // в этом случае нет необходимости знать размер массива
        cout << element << '\t';
    }

    cout << endl;

    // проблема с такими массивами (массивами в стиле Си) в том, что мы не можем узнать их размер;
    // обычно, чтобы с этим как-то работать, вместе с массивами создают переменные, указывающие на размер массива,
    // что весьма неудобно и вызывает кучу ошибок в коде
    /**
     * Пример кода с переменной, обозначающей размер массива
     * const int N = 10;  // про const будет позже
     * int arr [N];
     */

    // поэтому в современном C++ используется std::array - класс-оболочка массивов в стиле Си;
    // array хранит в себе размер массива, который можно получить при промощи вызова метода size()

    array</* тип элементов */int, /* размер */ 5> cpp_int_arr = {};  // инициализация нулями

    // доступ к элементам осуществляется через оператор [] или методом at(index)
    cpp_int_arr[0] = 1;
    cpp_int_arr[2] = 2;

    cpp_int_arr.at(3) = 3;

    // обращение к элементу через оператор [] за пределами массива не вызывает ошибку
    // возвращается "мусор" - данные где-то там в памяти (будьте внимательны!)
    cout << "\ncpp_int_arr[100]: " << cpp_int_arr[100] << endl;

    // вывод значения за пределами массива вызывает ошибку при использовании метода at(index)
    // метод at(index) проверяет индекс на выход за пределы массива и может выбросить ошибку
//    cpp_int_arr.at(100);  // <-- попробуйте раскомментировать и запустить

    // получение размера C++ массива осуществляется при помощи метода size()
    // вызов метода осуществляется через оператор . (точка)
    int cpp_arr_length = cpp_int_arr.size();

    cout << "\ncpp_int_arr.size() = " << cpp_arr_length << endl;

    // работа с C++ массивом в цикле (ничем не отличается от массива в стиле Си)
    for (int index = 0; index < /* никаких магических значений размера массива */ cpp_arr_length; index++) {

        if (cpp_int_arr[index] <= 0) {
            continue;  // пропускаем неположительные элементы
        }

        cpp_int_arr[index] *= -1;
    }

    // for-each цикл
    cout << "\nFor-each loop cpp_int_arr:" << endl;

    for (int element : cpp_int_arr) {
        cout << element << '\t';
    }

    cout << endl;

    // массивы и указатели (может не понадобиться, если вы используете класс array)
    int int_arr5[3] = {3, 2, 5};  // массив int-ов размера 3

    // элементы массива в памяти находятся последовательно
    // [0] [1] [2]  <--- ячейки памяти, каждая ячейка размером sizeof(int) = 4 байта
    //  3   2   5

    // выведем элементы массива
    cout << "\nFor-each loop int_arr5:" << endl;

    for (int element : int_arr5) {
        cout << element << '\t';
    }

    cout << endl;

    int *arr_begin_pointer = int_arr5;  // указатель на нулевой элемент массива (начало массива)
    arr_begin_pointer = &int_arr5[0];   // идентично, берем адрес нулевого элемента массива

    cout << "Pointer address int_arr5 = " << int_arr5 << endl;
    cout << "Pointer address &int_arr5[0] = " << &int_arr5[0] << endl;
    cout << "*arr_begin_pointer (or int_arr5[0]) = " << *arr_begin_pointer << endl;

    int *next_arr_pointer = arr_begin_pointer + 1;  // передвигаем указатель на следующий элемент массива
    // свдиг указателя происходит на количество байт, равное размеру типа указателя, т.е. на sizeof(int) = 4 байта
    // это возможно по причине того, что элементы массива гарантированно находятся последовательно в памяти

    cout << "Pointer address int_arr5[1] = " << next_arr_pointer << endl;

    int *end_arr_pointer = arr_begin_pointer + 2;  // передвигаем указатель на последний элемент массива (3ий элемент)

    cout << "Pointer address int_arr5[2] = " << end_arr_pointer << endl;

    // заполнить массив элементами также можно при помощи функции fill
    // begin и end - итераторы, эту тему мы пока не затрагиваем,
    // можно думать о них, как об указателях на начало и конец массива
    fill(cpp_int_arr.begin(), cpp_int_arr.end(), /* значения элементов */0);

    // или при помощи метода класса array
    cpp_int_arr.fill(0);

    // устанавливаем последние два элемента массива в значение 1
    fill(cpp_int_arr.end() - 2, cpp_int_arr.end(), 1);

    cout << "\nFor-each loop cpp_int_arr (fill):" << endl;

    for (int element : cpp_int_arr) {
        cout << element << '\t';
    }

    // массив в стиле Си можно тоже заполнить каким-либо значением при помощи функции fill
    int int_arr6[3] = {};
    fill(/* указатель на начало массива */ int_arr6,
            /* указатель на элемент за концом массива */int_arr6 + 3,
            /* значение */ 6);

    // копирование массивов может осуществляться по-разному
    // если мы работаем с массивом в стиле Си, то придется использовать функцию копирования copy
    int copy_int_arr[5];

    copy(/* указатель на начало массива */ int_arr,
            /* указатель на элемент за концом массива */int_arr + 5,
            /* куда положить результат, другой массив */ copy_int_arr);

    cout << "\nFor-each loop copy_int_arr (copy):" << endl;

    for (int element : copy_int_arr) {
        cout << element << '\t';
    }

    cout << endl;

    cout << "\nFor-each loop int_arr (source):" << endl;

    for (int element : int_arr) {
        cout << element << '\t';
    }

    cout << endl;

    // копирование C++ массивов
    array<int, 5> copy_cpp_int_arr = cpp_int_arr;  // массив автоматически скопируется (склонируется)
    // здесь используется поведение оператора копирования = (равно)

    cout << "\nFor-each loop copy_cpp_int_arr (operator =):" << endl;

    for (int element : copy_cpp_int_arr) {
        cout << element << '\t';
    }

    cout << endl;

    cout << "\nFor-each loop cpp_int_arr (source):" << endl;

    for (int element : cpp_int_arr) {
        cout << element << '\t';
    }

    cout << endl;

    // многомерные статические массивы (матрицы)
    int array_2d[/* кол-во строк */3][/* кол-во столбцов */2] = {{1, 3},
                                                                 {5, 7},
                                                                 {9, 11}};

    // можно инициализировать массив следующим эквивалентным образом
    // int array_2d[3][2] = {1, 3, 5, 7, 9, 11}

    // указатели на начало строк массива (на первые элементы строк)
    int *array_2d_0th_row = array_2d[0];
    int *array_2d_1st_row = array_2d[1];
    int *array_2d_2nd_row = array_2d[2];

    cout << "\nAddresses and values of 0th elements in rows:" << endl;

    printf("array_2d[0] at %d: %d\n", array_2d_0th_row, *array_2d_0th_row);
    printf("array_2d[1] at %d: %d\n", array_2d_1st_row, *array_2d_1st_row);
    printf("array_2d[2] at %d: %d\n\n", array_2d_2nd_row, *array_2d_2nd_row);

    // несмотря на то, что данные теперь разделены условными номерами строк,
    // они все еще находятся последовательно в памяти
    // [1, 3, 5, 7, 9, 11]

    // проверим это при помощи указателей
    int *array_2d_begin = &array_2d[0][0];  // указатель на начало массива (0 строка, 0 столбец)
    int *array_2d_end = &array_2d[2][1];  // указатель на конец массива (2 строка, 1 столбец)

    // цикл, в котором мы передвигаем указатель от начала массива к его концу
    // pointer++ означает что мы передвигаемся от условного адреса ADDR к ADDR + sizeof(int)
    for (int *pointer = array_2d_begin; pointer <= array_2d_end; pointer++) {
        printf("array_2d at %d: %d\n", pointer, *pointer);
    }

    cout << endl;

    // доступ к элементам массива можно получить оператором [] (квадратные скобки)
    // пройдемся по элементам двумерного массива в цикле
    for (int row_index = 0; row_index < 3; row_index++) {

        cout << "Iterating over a row #" << row_index << endl;

        for (int column_index = 0; column_index < 2; column_index++) {

            // получение элемента массива на определенной строке и столбце
            int element = array_2d[row_index][column_index];

            printf("\tarray_2d[%d][%d] = %d\n", row_index, column_index, element);
        }

        cout << endl;
    }

    // многомерные массивы в стиле C++

    // массив array<..., 3> из массивов array<int, 2>
    // 3 строки и 2 столбца
    array<array<int, 2>, 3> cpp_array_2d = {};  // инициализируем нулями

    // получение кол-ва строк массива
    int cpp_array_2d_num_rows = cpp_array_2d.size();
    int cpp_array_2d_num_cols = cpp_array_2d[0].size();

    printf("\ncpp_array_2d dimensions: %d x %d\n", cpp_array_2d_num_rows, cpp_array_2d_num_cols);

    // доступ к элементам через оператор []
    cpp_array_2d[0][0] = 1;

    int cpp_array_2d_element = cpp_array_2d[0][1];

    // for-each итерация массива
    // можно заменить тип на кючевое слово auto
    for (/* array<int, 2> */ auto cpp_array_row: cpp_array_2d) {
        for (int element : cpp_array_row) {
            // блок кода
        }
    }

    // передача массива в функцию

    return 0;
}
