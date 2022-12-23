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

int search_max(int i, int n)//шукаємо максимальний елемент в строчці
{
    int max = arr [i][0];
    for (int j = 0; j < n; j++) {
        if (arr[i][j] > max)
            max = arr[i][j];
    }
    return max;
}

void negative(int *b, int n, int& k)//перевіряємо діагональний елемент на від'ємність
{
    for (int i = 0; i < n; i++){
        if (arr[i][i] < 0) {
            int t = search_max(i, n);
               cout<<"Max element of "<< i+1 <<" row is: "<< t <<endl;
            b[k] = t;
            k++;
        }
    }
}

int min(int* b, int k) {
    int min = b[0];
    for (int i = 0; i < k; i++) {
        if (b[i] < min)
            min = b[i];
    }
    return min;
}


void task()
{
    int k = 0;
    int* b = new int[100];

    cout<<"input size of matrix: ";
    cin>>n;
    random();
    output();
    negative(b,n,k);

    cout << endl << "Minimal element is = " << min(b, k) << endl;
}


int main ()
{
    cout<<"Bezrukov Andrii. IPZ-14. number 4. Task 1"<<endl;
    task();

}