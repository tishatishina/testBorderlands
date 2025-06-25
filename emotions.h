
using namespace std;


enum Worlds { SADNESS, CALM, POWER, RAGE, JOY, FEAR };

Worlds currentWorld = Worlds::SADNESS;

string worlds[] = { "Мир Грусти", "Мир Радости", "Мир Страха", "Мир Спокойствия", "Мир Гнева", "Мир Силы" };

struct player_ {

    int current_loc = 0;
};

struct portal_ {

    string name;
    int target;
    bool activ;
};

struct location_ {
    string name;
    vector<portal_> portal;


};

location_ room[6];
player_ user;



struct Character {
    string name;
    int effect[3][6]; // 3 реплики, 6 эмоций
};

 string emotionNames[6] = { "Грусть", "Радость", "Страх", "Спокойствие", "Гнев", "Сила" };

    int emotions[6]{ 50,50,50,50,50,50 };

    void emotionScales()
    {
        emotions[JOY] = 100 - emotions[SADNESS];
        emotions[CALM] = 100 - emotions[RAGE];
        emotions[POWER] = 100 - emotions[FEAR];


    };



void sadness() 
{
    Character characters[3]= {
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
            emotionScales();

            bool extreme = true;
            for (int i : {SADNESS, FEAR, RAGE}) {
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
                        currentWorld = Worlds::CALM;
                        cout << ">> Ты проиграл\n";
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

        return;
    }

void calm()
{
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

        emotionScales();

        bool extreme = true;
        for (int i : {SADNESS, FEAR, RAGE}) {
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
                    currentWorld = Worlds::POWER;
                    cout << ">> Ты проиграл\n";
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

    return;
}

void power()
{
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

        emotionScales();

        bool extreme = true;
        for (int i : {SADNESS, FEAR, RAGE}) {
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
                    currentWorld = Worlds::RAGE;
                    cout << ">> Ты проиграл\n";
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

    return;
}

void rage()
{

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

        emotionScales();

        bool extreme = true;
        for (int i : {SADNESS, FEAR, RAGE}) {
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
                    currentWorld = Worlds::JOY;
                    cout << ">> Ты проиграл\n";
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

    return;
}

void joy()
{
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

        emotionScales();

        bool extreme = true;
        for (int i : {SADNESS, FEAR, RAGE}) {
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
                    currentWorld = Worlds::FEAR;
                    cout << ">> Ты проиграл\n";
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

    return;
}

void fear()
{
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

        emotionScales();

        bool extreme = true;
        for (int i : {SADNESS, FEAR, RAGE}) {
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
                    currentWorld = Worlds::SADNESS;
                    cout << ">> Ты проиграл\n";
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

    return;
}