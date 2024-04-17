#include <iostream>
using namespace std;
#define Total_Chars 256 

// Функция для создания таблицы "плохих символов"
void badCharHeuristic(string str, int size, int bad_characters[Total_Chars]) 
{
    int i;
    // Инициализация всех элементов массива "плохих символов" значением -1
    for(i = 0; i < Total_Chars; i++) 
    {
        bad_characters[i] = -1;
    }
    // Заполнение массива "плохих символов" индексами последних вхождений символов строки
    for(i = 0; i < size; i++) 
    {
        bad_characters[(int) str[i]] = i;
    }
}

// Основная функция алгоритма Бойера-Мура для поиска подстроки в строке
void boyermoore(string T, string P) 
{
    int m = P.size(); // Длина подстроки (образца)
    int n = T.size(); // Длина строки (текста)

    int bad_characters[Total_Chars]; // Массив для хранения "плохих символов"

    // Создание таблицы "плохих символов"
    badCharHeuristic(P, m, bad_characters);

    int idx = 0; // Индекс текущего сравнения в тексте
    // Пока возможно сравнивать подстроку с оставшейся частью текста
    while(idx <= (n - m)) 
    {
        int j = m -1; // Индекс для сравнения символов в обратном порядке в подстроке
        // Пока символы в подстроке и тексте совпадают
        while(j >= 0 && P[j] == T[idx + j]) 
        {
            j--;
        }
        // Если весь образец был совпавший, выводим позицию, в которой он встретился
        if(j < 0) 
        {
            cout << "Сдвиг, при котором возникает паттерн = " << idx << "\n";

            // Перемещаем индекс на количество символов в образце
            idx += (idx + m < n) ? m - bad_characters[T[idx + m]] : 1;
        }
        else 
        {
            // В случае несовпадения символов, вычисляем новый индекс с учетом "плохих символов" и сравниваем с образцом
            idx += max(1, j - bad_characters[T[idx + j]]);
        }
    }
}

int main() 
{
    string text = "hsrhghsdABCfgfghdfghdfgh"; // текст
    string pattern = "ABC"; // подстрока
    boyermoore(text, pattern); 
    return 0;
}

