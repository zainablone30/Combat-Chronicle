#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include<Windows.h>
#pragma comment(lib, "winmm.lib")
#include<iomanip>

using namespace std;

struct Player
{
    string name;
    string playerClass;
    string inventory[5];
    string weapon;
    int health;
    int level = 1;
    int levelMax;
    int experiencePoints;
    int attack;
};

struct Enemy
{
    string enemyName;
    int enemyHealth;
    int difficultyLevel;
};

string lowerString(string str) //This function converts Uppercase letter into lower case
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + 32; //adding 32 in will change ASCII code and convert it into lower case
        }
    }
    return str;
}

string upperString(string str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32; // Subtracting 32 converts lowercase to uppercase
        }
    }
    return str;
}
bool validateAlphaString(string name) //user defined function declaration
{

    for (const char c : name)
    {
        if (!isalpha(c) && !isspace(c))
            return false;
    }

    return true;
}
string getValidName(string name)
{
    while (!validateAlphaString(name))
    {
        cout << "Wrong Input!please Use only alphabets for name" << endl;
        cout << "Enter Name:  ";
        getline(cin, name);
    }
    return name;
}

string input(string x)
{
    while (true)
    {
        if (cin.eof() && cin.fail())
        {
            cin.clear();
        }
        else if (!cin.eof() && !cin.fail())
        {
            return x;
        }
    }
}
int Quit()
{
    cout << setw(50) << "GOODBYE" << endl;
    return 0;
}
void initializePlayer(Player& player)
{
    cout << "\n\n" << setw(60) << "CREATING PLAYER" << endl << endl << endl;
    cout << "Player Name: ";
    while (true)
    {
        getline(cin, player.name);
        player.name = input(player.name);
        player.name = upperString(player.name);
        getValidName(player.name);
        if (player.name.length() > !3 && player.name.length() < !8)
        {
            cout << "Length must between 3 to 8 characters.\nEnter name: ";
        }
        else
        {
            break;
        }
    }
    while (true)
    {
        cout << endl << setw(55) << "CLASSES";
        cout << "\n\n*Warrior\n\n*Mage\n\n*Rogue" << endl;
        cout << "\nChoose your class: ";
        getline(cin, player.playerClass);
        player.playerClass = input(player.playerClass);
        player.playerClass = lowerString(player.playerClass);
        if (player.playerClass == "warrior" || player.playerClass == "mage" || player.playerClass == "rogue")
        {
            break;
        }
        else
        {
            cout << "Invalid class" << endl;
        }
    }
    player.experiencePoints = 0;
    player.level = 1;
    player.health = 100;
    player.levelMax = 5;
}

void EnemyInfo(Player& player, Enemy& enemy)
{
    cout << "Press ( 1 to 9 ) for body shoot" << endl;
    cout << "Press ( 0 ) for headshot" << endl;

    if (player.level == 1)
    {
        cout << setw(50) << "LEVEL 1 " << endl << endl;
        enemy.enemyName = "DOCTOR";
        enemy.enemyHealth = 50;
        enemy.difficultyLevel = 1;
        cout << "Enemy: " << enemy.enemyName << endl;
        cout << "Enemy Health: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
    }
    else if (player.level == 2)
    {
        cout << setw(50) << "LEVEL 2 " << endl << endl;
        enemy.enemyName = "SARA";
        enemy.enemyHealth = 100;
        enemy.difficultyLevel = 2;
        cout << "Enemy: " << enemy.enemyName << endl;
        cout << "Enemy Health: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;

    }
    else if (player.level == 3)
    {
        cout << setw(50) << "LEVEL 3 " << endl << endl;
        enemy.enemyName = "ANNA";
        enemy.enemyHealth = 130;
        enemy.difficultyLevel = 3;
        cout << "Enemy: " << enemy.enemyName << endl;
        cout << "Enemy Health: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
    }
    else if (player.level == 4)
    {
        cout << setw(50) << "LEVEL 4 " << endl << endl;
        enemy.enemyName = "CARLO";
        enemy.enemyHealth = 150;
        enemy.difficultyLevel = 4;
        cout << "Enemy: " << enemy.enemyName << endl;
        cout << "Enemy Health: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
    }
    else if (player.level = player.levelMax)
    {
        cout << setw(50) << "FINAL LEVEL  " << endl << endl;
        enemy.enemyName = "ANDY";
        enemy.enemyHealth = 200;
        enemy.difficultyLevel = 5;
        cout << "Enemy: " << enemy.enemyName << endl;
        cout << "Enemy Health: " << enemy.enemyHealth << endl;
        cout << "Difficulty Level: " << enemy.difficultyLevel << endl;
    }
}

void displayPlayerInfo(Player& player)
{
    cout << setw(65) << "Character Information\n\n";
    cout << "Name: " << player.name << endl;
    cout << "Class: " << player.playerClass << endl;
    cout << "Health: " << player.health << endl;
    cout << "Experience Points: " << player.experiencePoints << endl;
    if (player.level > player.levelMax)
    {
        player.level = 5;
    }
    cout << "Level: " << player.level << "\n\n";
}

string Weapon(Player& player)
{
    if (player.level == 1)
    {
        player.weapon = "UMP-45";
        player.inventory[0] = player.weapon;
        return player.weapon;
    }
    if (player.level == 2)
    {
        player.weapon = "M416";
        player.inventory[1] = player.weapon;
        return player.weapon;
    }
    if (player.level == 3)
    {
        player.weapon = "AKM";
        player.inventory[2] = player.weapon;
        return player.weapon = "AKM";
    }
    if (player.level == 4)
    {
        player.weapon = "AWM";
        player.inventory[3] = player.weapon;
        return player.weapon = "AWM";
    }
    if (player.level == 5)
    {
        player.weapon = "LMG";
        player.inventory[4] = player.weapon;
        return player.weapon = "LMG";
    }
}


void inventory(Player& player)
{
    player.inventory[0] = "UMP-45";
    player.inventory[1] = "M416";
    player.inventory[2] = "AKM";
    player.inventory[3] = "AWM";
    player.inventory[4] = "LMG";
    cout << "1. UMP-45" << setw(30) << "at Level 1" << endl;
    cout << "2. M416" << setw(30) << "  at Level 2" << endl;
    cout << "3. AKM" << setw(30) << "   at Level 3" << endl;
    cout << "4. AWM" << setw(30) << "   at Level 4" << endl;
    cout << "5. LMG" << setw(30) << "   at Final Level" << endl;
}


int levelUp(Player& player)
{
    if (player.experiencePoints >= 100)
    {
        player.level++;
        if (player.level == 5)
        {
            player.level = player.levelMax;
        }
        player.health = 100; // Reset health on level up
        player.experiencePoints = 0; // Reset experience points

        cout << "\nCongratulations! You've leveled up to Level " << player.level << "!" << endl;
        return player.level;

    }
}


int PlayerAttack(Player& player)
{
    string ch;
    cin >> ch;
    ch = input(ch);
    ch = lowerString(ch);
    while (true)
    {
        if (!cin.eof() && !cin.fail())
        {
            if (ch == "1")
            {
                player.attack = 3;
                return player.attack;
                true;
            }
            else if (ch == "2")
            {
                player.attack = 6;
                return player.attack;
                true;
            }
            else if (ch == "3")
            {
                player.attack = 9;
                return player.attack;
                true;
            }
            else if (ch == "4")
            {
                player.attack = 12;
                return player.attack;
                true;
            }
            else if (ch == "5")
            {
                player.attack = 15;
                return player.attack;
                true;
            }
            else if (ch == "6")
            {
                player.attack = 18;
                return player.attack;
                true;
            }
            else if (ch == "7")
            {
                player.attack = 21;
                return player.attack;
                true;
            }
            else if (ch == "8")
            {
                player.attack = 24;
                return player.attack;
                true;
            }
            else if (ch == "9")
            {
                player.attack = 27;
                return player.attack;
                true;
            }
            else if (ch == "0")
            {
                player.attack = 50;
                return player.attack;
                true;
            }
            else
            {
                player.attack = 0;
                break;
            }
        }
        else if (cin.eof() && cin.fail())
        {
            cin.clear();
            player.attack = 0;
            break;
        }
    };
}



void battle(Player& player, Enemy& enemy)
{
    cout << "\nPlayer weapon: " << Weapon(player) << endl << endl;
    cout << setw(40) << player.name << setw(20) << "V/S" << setw(20) << enemy.enemyName << endl;
    while (true)
    {
        int enemyAttack = rand() % 30 + 5; // Simulate enemy attack
        if (player.health > 0)
        {
            PlayerAttack(player);
            cout << "You attack the " << enemy.enemyName << " for " << "'" << player.attack << "'" << " damage." << endl;
            enemy.enemyHealth = enemy.enemyHealth - player.attack;
            if (enemy.enemyHealth > 0)
            {
                cout << enemy.enemyName << " attacks you for " << enemyAttack << " damage." << endl;
                player.health = player.health - enemyAttack;
                if (player.health <= 0)
                {
                    player.health = 0;
                    cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                    while (true)
                    {

                        cout << "You were defeated.\n\n";
                    up:
                        cout << "Do you want to play again(Y / N)...";
                        string choice;
                        choice = input(choice);
                        choice = lowerString(choice);
                        cin >> choice;
                        if (choice == "y" || choice == "Y")
                        {
                            system("cls");
                            cout << setw(50) << "LEVEL " << player.level << endl;
                            battle(player, enemy);
                        }
                        else if (choice == "n" || choice == "N")
                        {
                            cout << "Do you want to quit the game (Y/N).";
                        jump:
                            cin >> choice;
                            choice = input(choice);
                            choice = lowerString(choice);
                            if (choice == "Y" || choice == "y")
                            {
                                Quit();
                            }
                            else if (choice == "n" || choice == "N")
                            {
                                cout << endl;
                                goto up;
                            }
                            else
                            {
                                cout << "Invalid Input.";
                                goto jump;
                            }
                        }
                    };
                }

                else
                {
                    cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                    true;
                }
                true;
            }
            else if (enemy.enemyHealth <= 0)
            {
                enemy.enemyHealth = 0;
                cout << "\nYour Health: " << player.health << setw(25) << enemy.enemyName << " Health: " << enemy.enemyHealth << endl;
                cout << "You defeated " << enemy.enemyName << ". You gained 100 experience points." << endl;
                player.experiencePoints = player.experiencePoints + 100;
                levelUp(player);

                break;
            }
        }
        else if (player.health <= 0)
        {
            player.health = 100;
            true;
        }
    }
}


void gameLoop(Player& player, Enemy& enemy)
{
    levelUp(player);
    EnemyInfo(player, enemy);
    battle(player, enemy);
}
void Controlls()
{
    cout << "press 1 for giving damage of health 3" << endl;
    cout << "press 2 for giving damage of health 6" << endl;
    cout << "press 3 for giving damage of health 9" << endl;
    cout << "press 4 for giving damage of health 12" << endl;
    cout << "press 5 for giving damage of health 15" << endl;
    cout << "press 6 for giving damage of health 18" << endl;
    cout << "press 7 for giving damage of health 21" << endl;
    cout << "press 8 for giving damage of health 24" << endl;
    cout << "press 9 for giving damage of health 27" << endl;
    cout << "press 0 for giving damage of health 30" << endl;
}

void StoryLine(Player& player)
{
    cout << setw(50) << "LEVEL 1" << endl << endl;
    cout << setw(30) << "Player" << setw(18) << "V/S" << setw(30) << "DOCTOR" << endl;
    cout << "\nPlayer Weapon: UMP-45 " << endl;
    cout << "\n" << setw(50) << "LEVEL 2" << endl << endl;
    cout << setw(30) << "PLayer" << setw(18) << "V/S" << setw(30) << "SARA" << endl;
    cout << "\nPlayer Weapon: M416" << endl;
    cout << "\n" << setw(50) << "LEVEL 3" << endl << endl;
    cout << setw(30) << "Player" << setw(18) << "V/S" << setw(30) << "ANNA" << endl;
    cout << "\nPlayer Weapon: AKM" << endl;
    cout << "\n" << setw(50) << "LEVEL 4" << endl << endl;
    cout << setw(30) << "Player" << setw(18) << "V/S" << setw(30) << "CARLO" << endl;
    cout << "\nPlayer Weapon: AWM" << endl;
    cout << "\n" << setw(50) << "LEVEL 5" << endl << endl;
    cout << setw(30) << "player" << setw(18) << "V/S" << setw(30) << "ANDY" << endl;
    cout << "\nPlayer Weapon: LMG " << endl;
}
void End(Player& player, Enemy& enemy)
{
    displayPlayerInfo(player);
    cout << endl;
    cout << player.name << " has defeated: " << endl << endl;
    cout << "*DOCTOR\n*SARA\n*ANNA\n*CARLO\n*ANDY" << endl;

}

int main()
{
    PlaySound(TEXT("back.wav"), NULL, SND_ASYNC);
    Player player;
    Enemy enemy;
    string ch;
    system("cls");
    cout << "\n\n\n\n";
    cout << setw(65) << "COMBAT CHRONICLES\n" << endl << endl;
    cout << "1.StoryLine." << endl << endl;;
    cout << "2.Start Playing." << endl << endl;
    cout << "3.View Inventory." << endl << endl;
    cout << "4.Controll Settings." << endl << endl;
    cout << "5.Quit Game." << endl << endl;
jump:
    cin >> ch;
    ch = input(ch);
    ch = lowerString(ch);
    while (true)
    {
        if (ch == "1")
        {
            system("cls");
            StoryLine(player);
            string choice;
            do
            {
                cout << "Press y to continue......";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);
            } while (choice != "y");
            true;
            main();
            break;
        }
        else if (ch == "2")
        {
            system("cls");
            cin.ignore();
            initializePlayer(player);
            cout << endl << endl;
            displayPlayerInfo(player);
        play:
            cout << "Ready to play game (Y/N): ";
            string choice;
            cin >> choice;
            choice = input(choice);
            choice = lowerString(choice);
            while (true)
            {
                if (choice == "y" || choice == "Y")
                {
                    system("cls");
                    string c;

                    do
                    {
                        gameLoop(player, enemy);
                    up:
                        if (player.level > player.levelMax)
                        {
                            string choice;
                            do
                            {
                            again:
                                cout << "\nPress y to continue.....";
                                cin >> choice;
                                choice = input(choice);
                                choice = lowerString(choice);
                                if (choice == "y")
                                {
                                    system("cls");
                                    End(player, enemy);
                                    do
                                    {
                                    y:
                                        cout << "Press y to continue...";
                                        string x;
                                        cin >> x;
                                        x = input(x);
                                        x = lowerString(x);
                                        if (x == "y")
                                        {
                                            system("cls");
                                            main();
                                        }
                                        else if (x != "y")
                                        {
                                            goto y;
                                        }

                                    } while (c != "y");
                                }
                                else if (choice != "y")
                                {
                                    goto again;
                                }
                            } while (c != "y");

                        }
                        else if (player.level <= player.levelMax)
                        {
                            cout << "Ready for next level (Y/N): ";
                            cin >> c;
                            c = input(c);
                            c = lowerString(c);
                            if (c == "n" || c == "N")
                            {
                                cout << "Do you want to quit...(y/n)";
                            choice:
                                string ch;
                                cin >> ch;
                                ch = input(ch);
                                ch = lowerString(ch);
                                if (ch == "Y" || ch == "y")
                                {
                                    system("cls");
                                    cout << displayPlayerInfo << endl;
                                    return 0;
                                }
                                else if (ch == "n" || ch == "N")
                                {
                                    goto up;
                                }
                                else
                                {
                                    cout << "Invalid Input." << endl;
                                    goto choice;
                                }

                            }
                            else if (c == "y" || c == "Y")
                            {
                                system("cls");
                                if (player.level > player.levelMax)
                                {

                                    string choice;
                                    do
                                    {
                                        cout << "\nPress y to continue......";
                                        cin >> choice;
                                        choice = input(choice);
                                        choice = lowerString(choice);
                                        if (choice == "y")
                                        {
                                            End(player, enemy);
                                        }
                                    } while (choice == "y");
                                    main();
                                    break;
                                }

                            }
                            else
                            {
                                cout << "Invalid Input." << endl;
                                goto up;
                            }
                        }
                    } while (c == "y" || c == "Y");
                    true;
                }
                else if (choice == "n" || choice == "N")
                {
                    string choice;
                    cout << "\nDo you want to quit the game (Y/N): ";
                    do
                    {
                    ch:
                        cin >> choice;
                        choice = input(choice);
                        choice = lowerString(choice);
                        if (choice == "y" || choice == "Y")
                        {
                            Quit();
                            return 0;
                        }
                        else if (choice == "n" || choice == "N")
                        {
                            goto play;
                        }
                        else
                        {
                            cout << "Invalid Input." << endl;
                            goto ch;
                        }
                    } while (choice == "Y" || choice == "y" || choice == "n" || choice == "N");
                    true;
                }
                else
                {
                    cout << "Invalid Input." << endl;
                    goto play;
                }

            };
            break;
        }
        else if (ch == "3")
        {
            system("cls");
            inventory(player);
            string choice;
            do
            {
                cout << "Press y to continue......";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);
                choice = lowerString(choice);
            } while (choice != "y");
            true;
            main();
            break;
        }
        else if (ch == "4")
        {
            system("cls");
            Controlls();
            string choice;
            do
            {
                cout << "Press y to continue......";
                cin >> choice;
                choice = input(choice);
                choice = lowerString(choice);
            } while (choice != "y");
            true;
            main();
            break;

        }

        else if (ch == "5")
        {
            system("cls");
            cout << "\n\n\n\n\n\n";
            Quit();
            break;
        }
        else
        {
            cout << "Invalid Input" << endl;
            goto jump;
        }
    };
}


