// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
using namespace std;
int bubbleSortAndCountSwaps(std::vector<int>& arr) {
    int n = arr.size();
    int swapCount = 0;
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapCount++;
                swapped = true;
          
            }
        }
        if (!swapped) {
            break; // массив уже отсортирован
        }  
    }
    
    std::cout << "Количество обменов:" <<  swapCount<< setw(7);
    return swapCount;
}
int main()
{
    setlocale(LC_ALL, "Russian");
    std::ifstream inputFile("input.txt"); // Открываем файл для чтения
    if (!inputFile) {
        std::cerr << "Ошибка открытия файла." << std::endl;
        return 1;
    }

    const int TEST_CASES = 10;
    for (int test = 1; test <= TEST_CASES; ++test) {
        int n;
        inputFile >> n; // Читаем количество элементов массива

        std::vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            inputFile >> arr[i]; // Читаем элементы массива
        }

        int swapCount = bubbleSortAndCountSwaps(arr);

        // Формируем результат: "да" если обменов больше 0, иначе "нет"
        std::string result = (swapCount > 0) ? "да" : "нет";

        // Выводим результат
        std::cout << "Тест " << test << " Результат " << result << std::endl;
    }

    inputFile.close(); // Закрываем файл
    return 0;
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
