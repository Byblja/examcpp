#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;

int i,j;//line and column of matrix
int n;//size of matrix
float arr [10][10];//matrix

void random()//Псевдовипадкова генерація для першого завдання
{
    srand(time(NULL));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            arr[i] [j] = rand() % 21-10;
        }
    }
}

void output()//вивід матриці
{
    for (int i = 0; i < n; i++){//зовнішній  цикл по рядках
        for (int j = 0; j < n; j++){//внутрішній цикл по стовпцях
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

int search_max()//шукаємо максимальний елемент в строчці
{
    int max = arr [i][i];
    for (int j = 0; j < n; j++) {
        if (arr[i][j] > max)
            max = arr[i][j];
    }
    return max;
}

void negative()//перевіряємо діагональний елемент на від'ємність
{
    for (int i = 0; i < n; i++){
        if (arr[i][i] < 0) {
            search_max();
        }
    }
}

void task()
{
    cout<<"input size of matrix: ";
    cin>>n;
    random();
    output();
}


int main ()
{
    cout<<"Bezrukov Andrii. IPZ-14. number 4"<<endl;
    task();

}