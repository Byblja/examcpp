#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int i, j;//line and column of matrix
int n;//size of matrix
int arr[10][10];//matrix

void random()//Псевдовипадкова генерація для першого завдання
{
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = rand() % 21 - 10;
        }
    }
}

void output()//вивід матриці
{
    for (int i = 0; i < n; i++) {//зовнішній  цикл по рядках
        for (int j = 0; j < n; j++) {//внутрішній цикл по стовпцях
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int search_max(int i, int n)//шукаємо максимальний елемент в строчці
{
    int max = arr[i][0];
    for (int j = 0; j < n; j++) {
        if (arr[i][j] > max)
            max = arr[i][j];
    }
    return max;
}

void negative()//перевіряємо діагональний елемент на від'ємність
{
    int count = 0, max = 0, max2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i][i] < 0)
        {
            cout << "Line number " << i + 1 << " ,element " << arr[i][i] << endl;
            max = 0;
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] > arr[i][max])
                    max = j;
                if (arr[i][max] > arr[i][max2])
                    max2 = j;
            }
            cout << " max of row " << i + 1 << " = " << arr[i][max] << endl;
            cout << " max of row max " << i + 1 << " = " << arr[i][max2] << endl;
        }
    }
}

void task()
{
    cout << "input size of matrix: ";
    cin >> n;
    random();
    output();
    negative();
}


int main()
{
    cout << "Bezrukov Andrii. IPZ-14. number 4. Task 1" << endl;
    task();

}