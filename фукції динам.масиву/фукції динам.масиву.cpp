// Написати такі функції для роботи з динамічним масивом :
//Функція розподілу динамічної пам’яті;+
//Функція ініціалізації динамічного масиву;+
//Функція друку динамічного масиву;+
//Функція видалення динамічного масиву;+
//Функція додавання елемента в кінець масиву;+
//Функція вставки елемента за вказаним індексом;+
//Функція видалення елемента за вказаним індексом.+
#include <iostream>
#include<ctime>
using namespace std;
void divisionArr(int*& Array, int& size) {//ф-н розподілу динамічної пам'яті
       Array = new int[size];

}
void inputArr(int*Array,  int size) {//функція заповнення масиву рандомними числами
    for (int i = 0; i < size; i++)
    {
        Array[i] = rand() % 20;
    }      
}
void printArr(int*Array, int size) {//ф-н друку масиву
    for (int i = 0; i < size; i++)
    {  cout <<Array[i] << "\t";        
        
    }
    cout << endl;

}
void deleteArr(int*& Array) {//ф-н видалення дин.масиву
           
    delete[] Array;     
}
void push_back(int*& Array, int& size, const int value) {//функція додає в кінець масиву елемент
    int* newArray = new int[size + 1];//створюємо новий більший масив 
        for (int i = 0; i < size; i++)
        {
            newArray[i] = Array[i];//копіюємо елементи із старого в новий 
        }
        newArray[size] = value;//додаємо елемент
        size++;//збільшуємо розмір масиву оскільки додали один елемент
        delete[] Array;//видаляєм масив
        Array = newArray;//змінюємо указатель на новий масив
}
void pop_back(int*& Array, int& size) {//функція видаляє з кінця масиву елемент
    size--;
    int* newArray = new int[size];   
    for (int i = 0; i < size; i++)
    {
        newArray[i] = Array[i];
    }    
    delete[] Array;//видаляємо масив
    Array = newArray;//змінюємо указатель на новий масив
}
void insertNumber(int*& Array, int& size, int index, int value)//ф-н додавання елемента за вказаним індексом
{
    int* newArray = new int[++size]; //створюємо новий масив 
    for (int i = 0; i < index; ++i) { // перебираємо едементи масива до index
        newArray[i] = Array[i];
    }
    newArray[index] = value;
    for (int i = index; i < size - 1; ++i) { // перебираємо едементи масива після index
        newArray[i + 1] = Array[i];
    }
    
    delete[]Array; // видаляємо массив
    Array = newArray;//змінюємо указатель на новий масив
}
void insertDeleteNumber(int*& Array, int& size, int index)//ф-н видалення елемента за вказаним індексом
{
    for (int i = index; i < size - 1; i++) //здвигаємось зліва напрва із заданої позиції
    {
        Array[i] = Array[i + 1]; //здвигаємо елементи 
    }
    size--;//зменшуємо розмір масиву на 1 елемент щоб не було мусору
}
int main()
{
    srand(time(NULL));
    setlocale(0, "");
    int*Array = nullptr;
    int size = 1;
    int value ,index;
    cout << "Введіть розмір масиву m = ";
    cin >> size;
    divisionArr( Array,  size);//ф-н виділення динамічної пам'яті
    inputArr(Array,size);//функція заповнення масиву рандомними числами
    printArr(Array, size);//ф-н друку масиву

    cout << "\n\tВведіть елемент який хочете добавити : ";
    cin >> value;
    cout << endl;
    push_back(Array, size, value);//функція додає в кінець масиву елемент
    printArr(Array, size);//ф-н друку масиву

    pop_back(Array, size);//функція видаляє з кінця масиву елемент
    cout << "\n\t\tМасив після видалення останнього елемента масиву\n\n";
    printArr(Array, size);//ф-н друку масиву

    cout << "\nВведіть індекс за яким хочете вставити новий елемент в масив :";
    cin >> index;
    cout << "\nВведіть елемент який хочете добавити  по індексу : ";
    cin >> value;
    cout << endl;
    insertNumber(Array, size, index, value);//ф-н додавання елемента за вказаним індексом
    printArr(Array, size); // ф - н друку масиву

    cout << "\nВведіть індекс за яким хочете видалити елемент в масиві : ";
    cin >> index;
    cout << endl;
    insertDeleteNumber( Array, size,index);//ф-н видалення елемента за вказаним індексом
    printArr(Array, size); // ф - н друку масиву


    deleteArr(Array); //ф-н видалення дин.масиву
       
}


