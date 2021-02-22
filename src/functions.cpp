#include <iostream>  // cout
#include <vector>
#include <array>

using namespace std;

// передача скалярного аргумента по значению
void pass_by_value(int value) {
    // значение аргумента (т.е. 'var') копируется в новую переменную 'value'
    cout << "[Pass by value] Variable 'value' at " << &value << " = " << value << endl;

    value = 10;  // значение переменной 'var' не изменится
}

// передача скалярного аргумента по указателю
void pass_by_pointer(int *pointer) {
    // значение аргумента-указателя копируется в новую переменную-указатель 'pointer'
    // теперь 'pointer' и 'pointer_to_var' оба указывают на 'var'
    cout << "[Pass by pointer] Pointer refers to " << pointer << " with value = " << *pointer << endl;

    *pointer = 20;  // значение переменной 'var' изменится
}

// передача скалярного аргумента по ссылке
void pass_by_reference(int &reference) {
    // ссылка 'reference' напрямую представляет переменную 'var'
    cout << "[Pass by reference] Reference at " << &reference << " with value = " << reference << endl;

    reference = 30;  // значение переменной 'var' изменится
}

// передача любого массива в стиле Си по указателю на нулевой элемент с указанием размера массива
void array_pass_by_pointer(int *arr, int size) {
    cout << "[Pass array by pointer] arr[0] at " << arr << endl;
    cout << "[Pass array by pointer] Iterating over array elements:" << endl;

    // идем по адресам элементов массива [arr, arr + sizeof(int), arr + 2 * sizeof(int)]
    for (int *curr = arr; curr < arr + size; curr++) {
        cout << *curr << '\t';
    }

    cout << endl;

    // доступ к значениям элементов массива при помощи оператора []
    arr[size - 1] = -1;

    for (int index = 0; index < size; index++) {
        cout << arr[index] << '\t';
    }

    cout << endl;
}

// передача статического C++ массива по значению
void cpp_array_pass_by_value(array<int, 3> cpp_arr) {
    // происходит копирование аргумента функции в локальную переменную 'cpp_arr'
    cout << "[Cpp array pass by value] copy of 'cpp_arr' at " << &cpp_arr << endl;

    // for-each цикл
    for (int element : cpp_arr) {
        cout << element << '\t';
    }

    cout << endl;

    // изменяем значение последнего элемента массива
    cpp_arr[cpp_arr.size() - 1] = -1;

    for (int index = 0; index < cpp_arr.size(); index++) {
        cout << cpp_arr[index] << '\t';
    }

    cout << endl;
}

// передача статического C++ массива по ссылке
void cpp_array_pass_by_reference(array<int, 3> &cpp_arr) {
    // ссылка напрямую представляет аргумент функции (т.е. переданный массив)
    cout << "[Cpp array pass by reference] of 'cpp_arr' at " << &cpp_arr << endl;

    // for-each цикл
    for (int element : cpp_arr) {
        cout << element << '\t';
    }

    cout << endl;

    // изменяем значение последнего элемента массива
    cpp_arr[cpp_arr.size() - 1] = -1;

    for (int index = 0; index < cpp_arr.size(); index++) {
        cout << cpp_arr[index] << '\t';
    }

    cout << endl;
}

int *create_array(int size) {
    int *arr = new int[size]{};
    return arr;  // вернет указатель на выделенную под массив память

    // можно было бы написать так: return new int[size]{};

    // придется помнить о том, что память выделялась под массив и освобождать ее
    // соответствующим образом, т.е. при помощи оператора delete[]
}

vector<int> create_cpp_array(int size) {
    vector<int> arr(size, 0);  // создаем динамический массив с изначальным размером size
    return arr;  // возвращаем по значению (все ОК)

    // можно было бы написать так: return vector<int>(size, 0);
}

int main() {

    {  // передача скалярных переменных по значение, указателю и ссылке в функцию
        int var = 0;
        int *pointer_to_var = &var;
        int &reference_to_var = var;

        cout << "Variable 'var' at " << &var << " = " << var << endl;

        pass_by_value(var);

        cout << "[Pass by value] 'var' = " << var << endl;

        pass_by_pointer(pointer_to_var);

        cout << "[Pass by pointer] 'var' = " << var << endl;

        pass_by_reference(reference_to_var);

        cout << "[Pass by reference] 'var' = " << var << endl;

        cout << endl;
    }

    {  // передача массивов в стиле Си в функцию

        int static_arr[3] = {1, 2, 3};  // [1, 2, 3]

        cout << "[Pass array by pointer] static_arr[0] at " << &static_arr[0] << endl;

        array_pass_by_pointer(static_arr, 3);

        cout << endl;

        int *dynamic_arr = new int[3]{10, 20, 30};  // [10, 20, 30]

        cout << "[Pass array by pointer] dynamic_arr[0] at " << dynamic_arr << endl;

        array_pass_by_pointer(dynamic_arr, 3);  // идентично статическому массиву

        delete[] dynamic_arr;  // не забываем освобождать память

        cout << endl;
    }

    {  // передача C++ массива

        array<int, 3> cpp_arr = {3, 2, 1};  // [3, 2, 1]

        cout << "[Cpp array pass by value] 'cpp_arr' at " << &cpp_arr << endl;

        cpp_array_pass_by_value(cpp_arr);

        cout << "[Cpp array pass by value] 'cpp_arr' values:" << endl;

        for (int element: cpp_arr) {
            cout << element << '\t';
        }

        cout << endl;

        cpp_array_pass_by_reference(cpp_arr);

        cout << "[Cpp array pass by reference] 'cpp_arr' values:" << endl;

        for (int element: cpp_arr) {
            cout << element << '\t';
        }

        cout << endl << endl;
    }

    {  // создание массивов через функции

        cout << "[Create array] Creating a dynamic array via function:" << endl;

        int size = 2;
        int *arr = create_array(size);  // [0, 0]

        for (int index = 0; index < size; index++) {
            cout << arr[index] << '\t';
        }

        cout << endl;

        delete[] arr;  // не забываем удалить массив

        cout << endl;

        cout << "[Create array] Creating a dynamic cpp array via function:" << endl;

        vector<int> cpp_arr = create_cpp_array(3);  // [0, 0, 0]

        for (int element: cpp_arr) {
            cout << element << '\t';
        }

        cout << endl << endl;
    }

    return 0;
}