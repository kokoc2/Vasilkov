#include <iostream>
#include <iomanip>
#include <vector>

double Summa(std::vector<double> Array)
{
    double Sum = 0;
    for (int i = 0; i < Array.size(); i++)
    {
        Sum += Array[i];
    }
    return Sum;
}

double ChangeLast(std::vector<double> Array)
{
    double Last;
    double Sum = Summa(Array);
    double Size = Array.size();
    Last = (Sum / Size);
    return Last;
}

void Show(std::vector<double> Array) // вывод вектора
{
    for (int i = 0; i < Array.size(); i++)
    {
        std::cout << std::fixed << std::setprecision(3) << Array[i] << " ";
    }
    std::cout << std::endl;
}

void Change(std::vector<double> Array)
{
    double Sum = Summa(Array);
    double Last = ChangeLast(Array);
    Array.push_back(Sum);
    Array.push_back(Last);
    double SumLast = Summa(Array);
    Show(Array);
    double Del;
    double Mnoj;
    for (int i = 0; i < Array.size(); i++)
    {
        Array[i] -= SumLast;
    }
    Show(Array);
    int operation = 10;
    double element;
    while (operation)
    {
        std::cin >> operation;
        if (operation == 0)
            break;
        if (operation == 1)
        {
            std::cin >> element;
            std::cout << "+: " << Array.size() + 1 << std::endl;
            Array.push_back(element);
            Show(Array);
            double Sum = Summa(Array);
            double Last = ChangeLast(Array);
            Array.push_back(Sum);
            Array.push_back(Last);
            Show(Array);

            double SumLast = Summa(Array);

            for (int i = 0; i < Array.size(); i++)
            {
                Array[i] -= SumLast;
            }
            Show(Array);
        }

        if (operation == 2)
        {
            std::cout << "-: " << Array.size() - 1 << std::endl;
            Array.pop_back();
            Show(Array);
            double Sum = Summa(Array);
            double Last = ChangeLast(Array);
            Array.push_back(Sum);
            Array.push_back(Last);
            Show(Array);

            double SumLast = Summa(Array);

            for (int i = 0; i < Array.size(); i++)
            {
                Array[i] -= SumLast;
            }
            Show(Array);
        }
    }
}

int main()
{
    int n;
    std::vector<double> Array;
    std::cin >> n; // длина массива
    double* array = new double[n];
    for (int i = 0; i < n; i++) // заполнение массива
    {
        std::cin >> array[i];
    }
    for (int i = 0; i < n; i++)
    {
        Array.push_back(array[i]);
    }
    std::cout << n << std::endl;
    Show(Array); // вывод
    Change(Array);
    delete[] array;
    return 0;
}