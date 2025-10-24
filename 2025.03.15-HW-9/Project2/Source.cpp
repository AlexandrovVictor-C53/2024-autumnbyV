#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>

class Student {
public:
    std::string name;
    
    int resilence;
    int intellect;
    int luck;
    int defense;
    int health;
    int strength;

    Student(std::string name, int str, int res, int intel, int luck, int def)
        : name(name), health(100), strength(str), resilence(res), intellect(intel), luck(luck), defense(def) {}
    
    bool isAlive() 
    {
        return health > 0;
    }

    void attack(Student& opponent) 
    {
        if (!isAlive()) return; 

        int baseDamage = strength / 2 + (rand() % (resilence / 2 + 1)); 
        int critChance = rand() % 100;

        if (critChance < luck) {
            baseDamage *= 2; 
            std::cout << name << " ulta " << opponent.name << " damage= " << baseDamage << "\n";
        }
        else {
            std::cout << name  << opponent.name <<  baseDamage << " - damage \n";
        }

        opponent.takeDamage(baseDamage);
    }

    void takeDamage(int damage) 
    {
        int reducedDamage = std::max(1, damage - defense / 2);
        health -= reducedDamage;
        std::cout << name << " got " << reducedDamage << " damage. HP: " << health << "\n";
    }


};

void shuffleOrder(Student* students[], int size) 
{
    for (int i = size - 1; i > 0; i--) 
    {
        int j = rand() % (i + 1);
        std::swap(*students[i], *students[j]);
    }
}

int main() {
    srand(time(0));

    Student students[10] = {
        {"Beg", 10, 8, 6, 20, 5},
        {"Gotfried", 7, 9, 10, 15, 6},
        {"Mo", 12, 6, 5, 10, 8},
        {"Matis", 8, 10, 7, 18, 4},
        {"John", 9, 7, 9, 12, 7},
        {"Faust", 11, 5, 8, 14, 6},
        {"Wilson", 6, 12, 6, 16, 5},
        {"Ray", 7, 8, 11, 13, 6},
        {"Sasha", 9, 6, 10, 17, 5},
        {"Dzhed", 8, 9, 7, 19, 4}
    };

    Student* activeStudents[10];
    for (int i = 0; i < 10; ++i) {
        activeStudents[i] = &students[i];
    }

    int aliveCount = 10;
    int round = 1;

    while (aliveCount > 1) {
        std::cout << "\n===== raund " << round << " =====\n";
        shuffleOrder(activeStudents, aliveCount);

        for (int i = 0; i < aliveCount; ++i) {
            if (!activeStudents[i]->isAlive()) continue;

            Student* opponent = nullptr;
            while (opponent == nullptr || opponent == activeStudents[i] || !opponent->isAlive()) {
                opponent = activeStudents[rand() % aliveCount];
            }

                 


            activeStudents[i]->attack(*opponent);
        }

        aliveCount = 0;
        for (int i = 0; i < 10; ++i) {
            if (students[i].isAlive()) {
                activeStudents[aliveCount++] = &students[i];
            }
        }

        round++;
    }

    for (int i = 0; i < 10; ++i) {
        if (students[i].isAlive()) {
            std::cout << "\n_/\ Winner: " << students[i].name << "_/\ \n";
            break;
        }
    }

    return 0;
}
