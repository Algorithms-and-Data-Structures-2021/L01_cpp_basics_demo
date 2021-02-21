#include <iostream>  // cout
#include <cstdio>    // printf
#include <algorithm>

using namespace std;

int main() {

    // В отличие от фиксированного массива, где его размер должен быть известен во время компиляции,
    // динамическое выделение массива в языке C++ позволяет нам устанавливать его длину во время выполнения программы.

    int arr_size = 3;

    int *p = &arr_size;

    // возвращается указатель на начало массива
    int *arr = new int[arr_size];

    // доступ к элементам массива
    arr[0] = 0;
    arr[1] = -1;
    arr[2] = -7;

    // высвобождение памяти при помощи оператора delete[]
    delete[] arr;

    arr = nullptr;  // обнуляем указатель после освобождения памяти

    // еще раз выделим память большего размера под динмический массив с инициализацией
    arr = new int[2 * arr_size]{1, 2, 3, 4, 5, 6};

    delete[] arr;
    arr = nullptr;

    // Use-case: увеличение размера массива с копированием старых данных
    {
        arr = new int[3]{0, 1, 2};  // [0, 1, 2]

        // нам понадобилось добавить еще один элемент в массив, придется его расширить
        int *resized_arr = new int[5]{0, 0, 0, -1, -1};  // [0, 0, 0, -1, -1]

        copy(arr, arr + 3, resized_arr);  // [0, 1, 2, -1, -1]

        delete[] arr;       // высвобождаем память старого массива
        arr = resized_arr;  // меняем значение указателя на новое (бОльшего массива)

        // теперь arr ссылается на новый массив большего размера

        for (int index = 0; index < 5; index++) {
            cout << arr[index] << '\t';
        }

        cout << endl;

        delete[] arr;
        resized_arr = nullptr;
    }

    cout << endl;

    // динамические многомерные массивы
    {
        int num_rows = 3;

        // выделяем память под массив указателей int* [] (читаем слева направо)
        // теперь у нас есть одномерный массив из указателей
        // указатели пока что никуда не указывают
        // [указатель 0, указатель 1, указатель 2]
        int **array_2d = new int *[num_rows];

        int num_cols = 2;

        // для каждой строки массива выделяем память под столбцы
        // указатель 0 -> [. . .]  указаетель ссылается на первый элемент строки
        // указатель 1 -> [. . .]
        // указатель 2 -> [. . .]
        for (int row_index = 0; row_index < num_rows; ++row_index) {
            array_2d[row_index] = new int[num_cols]{row_index, row_index};  // с инициализацией
        }

        for (int row_index = 0; row_index < num_rows; row_index++) {
            for (int column_index = 0; column_index < num_cols; column_index++) {
                cout << array_2d[row_index][column_index] << '\t';
            }
            cout << endl;
        }
    }


    return 0;
}