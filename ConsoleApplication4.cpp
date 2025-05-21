#include <iostream>
#include <string>
#include <windows.h>

    using namespace std;

    enum { SADNESS, JOY, FEAR, CALM, ANGER, POWER };

    struct Character {
        string name;
        int effect[3][6]; // 3 реплики, 6 эмоций
    };

    // Названия эмоций и миров
    string emotionNames[6] = { "Грусть", "Радость", "Страх", "Спокойствие", "Гнев", "Сила" };
    string worlds[6] = { "Мир Грусти", "Мир Радости", "Мир Страха", "Мир Спокойствия", "Мир Гнева", "Мир Силы" };

    int main() {
        std::setlocale(LC_ALL, "Russian");
        SetConsoleCP(1251);
        SetConsoleOutputCP(1251);
        int emotions[6] = { 50, 50, 50, 50, 50, 50 };
        int currentWorld = SADNESS;

        Character characters[3] = {
            {"Эла", {
                {10, -5, 0, 0, 0, 0},   // Реплика 1: сильное влияние
                {-15, 5, 0, 0, 0, 0},   // Реплика 2: ещё сильнее
                {5, 0, 5, -5, 0, 0}     // Реплика 3: смесь
            }},
            {"Лоран", {
                {5, -2, 0, 0, 0, 0},    // Реплика 1: слабо
                {-5, 2, 0, 0, 0, 0},
                {0, 0, 5, -5, 0, 0}
            }},
            {"Ними", {
                {0, 0, 0, 0, 5, -5},    // Гнев/Сила
                {0, 0, 5, -5, 0, 0},    // Страх/Спокойствие
                {0, 0, -5, 5, 0, 0}
            }}
        };

        int round = 0;
        while (true) {
            Character& c = characters[round % 3];
            cout << "\nТы находишься в " << worlds[currentWorld] << ". Тебе встречается " << c.name << ".\n";
            cout << "Выбери реплику:\n";
            cout << "1) «Ты ведь всё ещё помнишь?»\n";
            cout << "2) «Я пытался забыть»\n";
            cout << "3) «Ты была права»\n";
            int choice;
            cin >> choice;

            if (choice < 1 || choice > 3) {
                cout << "Некорректный выбор. Повторите.\n";
                continue;
            }

            // Применение эффекта
            int idx = choice - 1;
            for (int i = 0; i < 6; i++) {
                emotions[i] += c.effect[idx][i];
                if (emotions[i] > 100) emotions[i] = 100;
                if (emotions[i] < 0) emotions[i] = 0;
            }

            // Эмоции как переливающиеся сосуды:
            emotions[JOY] = 100 - emotions[SADNESS];
            emotions[CALM] = 100 - emotions[ANGER];
            emotions[POWER] = 100 - emotions[FEAR];

            bool extreme = true;
            for (int i : {SADNESS, FEAR, ANGER}) {
                if (emotions[i] != 0 && emotions[i] != 100) {
                    extreme = false;
                    break;
                }
            }
            if (extreme) {
                cout << "\nВсе эмоции достигли крайних пределов. Ты теряешь себя...\nИгра окончена.\n";
                break;
            }

            // Перенос в другой мир, если текущая эмоция вышла за пределы
            if (emotions[currentWorld] <= 0 || emotions[currentWorld] >= 100) {
                for (int i = 0; i < 6; i++) {
                    if (i != currentWorld && emotions[i] > 0 && emotions[i] < 100) {
                        currentWorld = i;
                        cout << ">> Ты переместился в " << worlds[currentWorld] << " из-за нестабильности.\n";
                        break;
                    }
                }
            }

            // Вывод эмоций
            cout << "\nТекущие эмоции:\n";
            for (int i = 0; i < 6; i++) {
                cout << emotionNames[i] << ": " << emotions[i] << "\n";
            }

            round++;
        }

        return 0;
    }