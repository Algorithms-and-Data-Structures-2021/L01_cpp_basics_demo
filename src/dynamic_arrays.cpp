#include <iostream>   // cout
#include <algorithm>  // copy
#include <vector>

using namespace std;

int main() {

    // В отличие от статического массива, динамическое выделение массива в языке C++
    // позволяет нам устанавливать его длину во время выполнения программы.

    {
        int arr_size = 3;  // размер массива может быть получен из файла, сети и т.д.

        // возвращается указатель на начало массива
        int *arr = new int[arr_size]{};  // [0, 0, 0]

        // доступ к элементам массива
        arr[0] = 0;
        arr[1] = -1;
        arr[2] = -7;

        // arr = [0, -1, -7]

        // высвобождение памяти при помощи оператора delete[]
        delete[] arr;

        // динамический массив с инициализацией (запросили новый участок памяти)
        arr = new int[2 * arr_size]{1, 2, 3, 4, 5, 6};  // [1, 2, 3, 4, 5, 6]

        delete[] arr;
    }

    // Use-case: увеличение размера массива с копированием старых данных
    {
        int *arr = new int[3]{0, 1, 2};  // [0, 1, 2]

        // нам понадобилось добавить еще элементы в массив, расширим массив
        int *resized_arr = new int[5]{0, 0, 0, -1, -1};  // [0, 0, 0, -1, -1]

        // копируем данные старого массива
        copy(arr, arr + 3, resized_arr);  // [0, 1, 2, -1, -1]

        delete[] arr;       // высвобождаем память, выделенную под старый массив
        arr = resized_arr;  // меняем значение указателя, теперь указатель ссылается на новый массив

        // причем указатели arr и resized_arr ссылаются на один и тот же участок памяти

        for (int index = 0; index < 5; index++) {
            cout << arr[index] << '\t';
        }

        cout << endl;

        delete[] arr;
    }

    cout << endl;

    // динамические многомерные массивы
    {
        int num_rows = 3;

        // выделяем память под массив указателей int* [] (читаем слева направо)
        // теперь у нас есть одномерный массив из указателей
        // [указатель 0, указатель 1, указатель 2]
        int **array_2d = new int *[num_rows];

        int num_cols = 2;

        // для каждой строки массива выделяем память под столбцы
        // указатель 0 -> [. . .]  указатель ссылается на первый элемент строки
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

        // высвобождение памяти: необходимо освободить память, выделенную под каждую строку массива
        for (int row_index = 0; row_index < num_rows; row_index++) {
            delete[] array_2d[row_index];
        }

        delete[] array_2d;  // высвобождение памяти, выделенную под массив указателей
    }

    {
        // дополнительный материал (класс vector)

        // В стандартной библиотеке C++ есть альтернатива динамическим массивам (как и статическим с классом array).
        // Для создания динамического массива используется класс vector.
        // Реализация vector позволяет не заботиться о ручном управлении памятью.

        cout << endl;

        vector<int> cpp_array;  // инициализация по-умолчанию (пустой массив)

        cout << "Vector size: " << cpp_array.size() << endl;

        // добавление элементов в конец массива
        cpp_array.push_back(0);   // [0]
        cpp_array.push_back(2);   // [0 2]
        cpp_array.push_back(-1);  // [0 2 -1]

        cout << "Vector size: " << cpp_array.size() << endl;

        vector<vector<int>> cpp_array_2d;  // пустой двумерный массив

        cpp_array_2d.push_back({1, 2, 3});     // [[1, 2, 3]]
        cpp_array_2d.push_back({1, 2});        // [[1, 2, 3], [1, 2]]
        cpp_array_2d.push_back({1, 2, 3, 5});  // [[1, 2, 3], [1, 2], [1, 2, 3, 5]]

        // получение доступа к элементам через оператор [] и метод at(index)
        cpp_array_2d[0][0] = -1;

        int element = cpp_array_2d[0][2];

        for (/* vector<int> */ auto &rows: cpp_array_2d) {  // ссылка на строку (чтобы не копировать ее)
            for (int e: rows) {
                cout << e << '\t';
            }

            cout << endl;
        }
    }

    return 0;
}