﻿#include <iostream>
#include <windows.h>
#include <vector>
#include <stdlib.h>
#include <string>
#include "Buckshot_Roulette.h"

using namespace std;

/*vector <int> bullets;
vector <int> hp_p1;
vector <int> hp_p2;
vector <int> inventory_p1;
vector <int> inventory_p2;

int WhichMove = 0;
int pila = 0;
bool naruchniky_p1 = false;
bool naruchniky_p2 = false;
int PreviousItem = 0;
void bullet_chance() // разпределение патронів у пушкі самий початок
{
    int chance;
    srand(time(NULL));
    do
    {
        chance = rand() % 8 + 1;
    } while (chance < 2);
    while (bullets.size() != chance)
        bullets.push_back(rand() % 2);
    /*int sum;
    for (int i = 0; i < bullets.size(); i++)
    {
        sum += bullets[i];
    }
    if (sum <= )                   // Додуматься як зробить шоб воно вибирало майже порівну бойових і холостих
    
}

void hp_chance() // разпределение здоров'я гравів самий початок
{
    int chance;
    srand(time(NULL));
    do
    {
        chance = rand() % 5 + 1;
    } while (chance < 2);
    hp_p1.resize(chance);
    hp_p2.resize(chance);

}

void hp_lose()
{
    if (!WhichMove)
        hp_p1.resize(hp_p1.size() - 1 - pila);
    else hp_p2.resize(hp_p2.size() - 1 - pila);
    pila = 0;
}

void hp_add()
{
    if (!WhichMove && (hp_p1.size() != 6))
        hp_p1.resize(hp_p1.size() + 1);
    else if(hp_p2.size() != 6) hp_p2.resize(hp_p2.size() + 1);
}

void shot_opponent()
{
    if (bullets[bullets.size() - 1]) //бойовий
    {
        if (!WhichMove)
            hp_lose(WhichMove + 1);
        if (WhichMove)
            hp_lose(WhichMove - 1);
        cout << "Постріл бойовим патроном" << endl;
    }
    else cout << "Постріл холостим патроном" << endl; // холостий
    bullets.pop_back();
    if (!WhichMove)
        WhichMove = 1;
    else WhichMove = 0;
}

void shot_himself()
{
    if (bullets[bullets.size() - 1])   // бойовий
    {
        if (!WhichMove)
            hp_lose();
        if (WhichMove)
            hp_lose();
        bullets.pop_back();
        if (!WhichMove)
            WhichMove++;
        else WhichMove--;
        cout << "Постріл бойовим патроном" << endl;
    }
    else
    {
        bullets.pop_back();
        cout << "Постріл холостим патроном" << endl; // холостий
    }
}

bool Game_over()
{
    if (!hp_p1.size())
        return true;
    if (!hp_p2.size())        
        return true;
    return false;
}

void prev_item()
{
    inventory_p1.resize(8);
    inventory_p2.resize(8);
    for (int i = 0; i < 8; i++)
    {
        if (inventory_p1[0] == 0)
        {
            PreviousItem = 0;
            break;
        }
        else if (inventory_p1[i] == 0)
        {
            PreviousItem = i;
            break;
        }
    }
}

void item_naruchniky()
{
    if (WhichMove)
        naruchniky_p1 = true;
    else naruchniky_p2 = true;
}

void item_chance()
{
    prev_item();

    int chance;
    int rand_item;
    srand(time(NULL));
    do
    {
        chance = rand() % 4 + 1;
    } while (chance < 1);
    for (int i = 0; i < chance && !inventory_p1[7]; i++)
    {
        rand_item = rand() % 5;
        switch (rand_item)
        {
            case 0:
                inventory_p1[i + PreviousItem] = 1; // Пила
                break;
            case 1:
                inventory_p1[i + PreviousItem] = 2; // Пиво
                break;
            case 2:
                inventory_p1[i + PreviousItem] = 3; // Лупа
                break;
            case 3:
                inventory_p1[i + PreviousItem] = 4; // Сіги
                break;
            case 4:
                inventory_p1[i + PreviousItem] = 5; // Н-ки
                break;
        }   
    }
    for (int i = 0; i < chance && !inventory_p2[7]; i++)
    {
        srand(time(NULL));
        rand_item = rand() % 5;
        switch (rand_item)
        {
        case 0:
            inventory_p2[i + PreviousItem] = 1; // Пила
            break;
        case 1:
            inventory_p2[i + PreviousItem] = 2; // Пиво
            break;
        case 2:
            inventory_p2[i + PreviousItem] = 3; // Лупа
            break;
        case 3:
            inventory_p2[i + PreviousItem] = 4; // Сіги
            break;
        case 4:
            inventory_p2[i + PreviousItem] = 5; // Н-ки
            break;
        }
    }

}

void item_interaction(int number)
{
    if (!WhichMove)
    {
        switch (inventory_p1[number])
        {
        case 1:
            pila = 1;
            break;
        case 2:
            bullets.pop_back();
            if (bullets[bullets.size() - 1] == 1)
                cout << "Вилетіла бойова" << endl;
            else cout << "Вилетіла холоста" << endl;
            break;
        case 3:
            if (bullets[bullets.size() - 1] == 1)
                cout << "Бойова" << endl;
            else cout << "Холоста" << endl;
            break;
        case 4:
            hp_add(WhichMove);
            break;
        case 5:
            item_naruchniky(WhichMove);
            break;
        }
    }
    else 
        switch (inventory_p2[number])
        {
        case 1:
            pila = 1;
            break;
        case 2:
            bullets.pop_back();
            if (bullets[bullets.size() - 1] == 1)
                cout << "Вилетіла бойова" << endl;
            else cout << "Вилетіла холоста" << endl;
            break;
        case 3:
            if (bullets[bullets.size() - 1] == 1)
                cout << "Бойова" << endl;
            else cout << "Холоста" << endl;
            break;
        case 4:
            hp_add(WhichMove);
            break;
        case 5:
            item_naruchniky(WhichMove);
            break;
        }
}

string item_name(int number)
{
    switch (number)
    {
    case 0:
        return " ";
        break;
    case 1:
        return "Пила";
        break;
    case 2:
        return "Пиво";
        break;
    case 3:
        return "Лупа";
        break;
    case 4:
        return "Сигарета";
        break;
    case 5:
        return "Наручніки";
        break;
    }
}

void Start_Game()
{

    hp_chance();
    int round_count = -1;
    int chose;
    int hp_do_vistrela = 0;
    int bull_da = 0;
    int bull_ni = 0;
    while (!Game_over())
    {
        item_chance();
        bull_da = 0;
        bull_ni = 0;
        bullet_chance();
        round_count++;
        WhichMove = 0;
        cout << "У гвинтівки " << bullets.size() << " патронів" << endl;
        for (int i = 0; i < bullets.size(); i++)
        {
            if (bullets[i] == 1)
                bull_da++;
            else bull_ni++;
        }
        cout << bull_da << " бойових, " << bull_ni << " холостих" << endl;
        do  // Шоб оптімізірувать можна зробить отдєльно функцію для цього куска,
            //яка буде перегружена, а передавать значення буде в залежності від WhichMove так само і хп, і інвентарь
        {
            if (Game_over())
                break;
            while (!WhichMove)
            {
                if (naruchniky_p1)
                {
                    WhichMove++;
                    cout << "Гравець пропускає хід" << endl; 
                    naruchniky_p1 = false;
                    break;
                }
                if (Game_over())
                    break;
                if (!bullets.size())
                    break;
                cout << "Гравець 1" << endl;
                cout << "У нього " << hp_p1.size() << " здоров'я" << endl;
                cout << "У нього такі предмети:" << endl;
                cout << "==== 0 - " << item_name(inventory_p1[0]) << endl << "==== 1 - " << item_name(inventory_p1[1]) << endl << "==== 2 - " << item_name(inventory_p1[2]) << endl << "==== 3 - " << item_name(inventory_p1[3]) << endl
                    << "==== 4 - " << item_name(inventory_p1[4]) << endl << "==== 5 - " << item_name(inventory_p1[5]) << endl << "==== 6 - " << item_name(inventory_p1[6]) << endl
                    << "==== 7 - " << item_name(inventory_p1[7]) << endl;
                cout << "Він вибирає що робити " << endl << "0 - 7 - використати предмет " << endl << "8 - постріл в себе" << endl << "9 - постріл в опонента" << endl;
                cin >> chose;
                hp_do_vistrela = hp_p1.size();
                switch (chose)
                {
                case 0:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 1:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 2:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 3:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 4:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 5:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 6:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 7:
                    item_interaction(chose);
                    inventory_p1[chose] = 0;
                    break;
                case 8:
                    shot_himself(WhichMove);
                    if (hp_do_vistrela != hp_p1.size())
                        cout << "Його хп " << hp_p1.size() << endl;
                    break;
                case 9:
                    shot_opponent();
                    break;
                }
            }
            while (WhichMove)
            {
                if (naruchniky_p2)
                {
                    WhichMove--;
                    cout << "Гравець пропускає хід" << endl;
                    naruchniky_p2 = false;
                    break;
                }
                if (Game_over())
                    break;
                if (!bullets.size())
                    break;
                cout << "Гравець 2" << endl;
                cout << "У нього " << hp_p2.size() << " здоров'я" << endl;
                cout << "У нього такі предмети:" << endl;
                cout << "==== 0 - " << item_name(inventory_p2[0]) << endl << "==== 1 - " << item_name(inventory_p2[1]) << endl << "==== 2 - " << item_name(inventory_p2[2]) << endl << "==== 3 - " << item_name(inventory_p2[3]) << endl
                    << "==== 4 - " << item_name(inventory_p2[4]) << endl << "==== 5 - " << item_name(inventory_p2[5]) << endl << "==== 6 - " << item_name(inventory_p2[6]) << endl
                    << "==== 7 - " << item_name(inventory_p2[7]) << endl;
                cout << "Він вибирає що робити " << endl << "0 - 7 - використати предмет " << endl << "8 - постріл в себе" << endl << "9 - постріл в опонента" << endl;
                cin >> chose;
                hp_do_vistrela = hp_p1.size();
                switch (chose)
                {
                case 0:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 1:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 2:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 3:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 4:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 5:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 6:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 7:
                    item_interaction(chose);
                    inventory_p2[chose] = 0;
                    break;
                case 8:
                    shot_himself(WhichMove);
                    if (hp_do_vistrela != hp_p2.size())
                        cout << "Його хп " << hp_p2.size() << endl;
                    break;
                case 9:
                    shot_opponent();
                    break;
                }
            }

        } while (bullets.size());
    }
    system("cls");
    if (!hp_p1.size())
        cout << "Програв гравець #1 " << endl;
    if (!hp_p2.size())
        cout << "Програв гравець #2 " << endl;
    for (int i = 0; i < inventory_p1.size(); i++)
    {
        inventory_p1[i] = 0;
        inventory_p2[i] = 0;
    }

}
*/
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Buckshot_Roulette Game;
    int start;
    do
    {
        cout << "--------------------Меню---------------------" << endl;
        cout << "1 - Старт " << endl << "2 - Інфо " << endl;
        cin >> start;
        if (start == 2)
        {
            /*cout << "Ця гра копія гри Buckshot roulette, але для двох гравців, для тих  хто не грав ось інформація про правила та предмети:  " << endl
                << "-------------------Правила-------------------" << endl
                << "Кожен раунд у гвинтівку заряджається до 8 патронів, деякі з них є холостими, деякі - бойовими" << endl
                << "У гравців є запас здоров'я, максимум може бути 5 очків здоров'я на гравця" << endl
                << "Програє той гравець, у якого не залишається очків здоров'я " << endl
                << "Основною ціллю гри є вбити опонента, для цього можна зробити постріл або в себе, або в опонента " << endl
                << "Коли робиш постріл в опонента, неважливо чи патрон холостий, чи бойовий, ваш хід закінчується" << endl
                << "Коли робиш постріл в себе, і постріл бойовий, то ваш хід закінчується" << endl
                << "Також коли робиш постріл в себе, а постріл холостий, то ваш хід не закінчується" << endl
                << "Під час вашого хода можна використовувати різні предмети, які не закінчують ваш ход, зі свого інвентаря" << endl
                << "-------------------Предмети------------------" << endl
                << "1. Пиво - пропускає одну пулю з гвинтівки " << endl
                << "2. Лупа - дозволяє перевірити яка пуля зараз заряджена" << endl
                << "3. Пила - збільшує урон пулі на 1, можна використовувати раз за ход" << endl
                << "4. Наручніки - заставляє вашого опонента пропустити хід, можна використовувати один раз, до наступного хода опонента" << endl
                << "5. Сигарети - додає одне очко здоров'я " << endl << "----------------------------------------------" << endl << "developed by \"GamesB(c)\", sponsored by \"Eugene's vine(c)\"" << endl;*/
            Game.Game_info();
        }
    } while (start != 1);
    //cout << "-------------------Перший раунд-------------------" << endl;
    cout << "---------------------------------------------------" << endl;
    Game.Game_start();
    /*cout << "-------------------Другий раунд-------------------" << endl;
    Start_Game();
    cout << "-------------------Третій раунд-------------------" << endl;
    Start_Game();*/
    system("pause");
}
 

