#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Функция для вычисления префикс-функции строки
vector<int> prefix_function(const string& s) {
    vector<int> pi(s.length(), 0); // Создание вектора для хранения значений префикс-функции

    for (int i = 1; i < s.length(); i++) {
        int j = pi[i - 1]; // Индекс предыдущего совпадения префикса и суффикса

        // Пока не достигнуто начало строки или не найдено совпадение символов
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1]; // Перемещаемся к предыдущему совпадению префикса и суффикса
        }

        // Если найдено совпадение символов, увеличиваем значение префикс-функции
        if (s[i] == s[j]) {
            pi[i] = j + 1;
        } else {
            pi[i] = j; // Иначе сохраняем значение предыдущего совпадения
        }
    }

    return pi; // Возвращаем вектор значений префикс-функции
}

int main() {
    string s, t;
    cin >> s >> t; 

    vector<int> pi = prefix_function(t + '#' + s); // Вычисление префикс-функции для строки t + '#' + s

    int t_len = t.length(); 

    // Перебор всех символов строки s
    for (int i = 0; i < s.length(); i++) {
        // Если значение префикс-функции равно длине строки t, выводим позицию вхождения
        if (pi[t_len + 1 + i] == t_len) {
            cout << "s[" << i - t_len + 1 << ".." << i << "] = t" << endl;
        }
    }
    return 0;
}
