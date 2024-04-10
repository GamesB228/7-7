#include "Buckshot_Roulette.h"

void Buckshot_Roulette::bullet_chance()
{
    // ������������� ������� � ���� ����� �������
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
        if (sum <= )*/                   // ���������� �� ������� ��� ���� �������� ����� ������ ������� � ��������

    }
}

void Buckshot_Roulette::hp_chance()
{
    // ������������� ������'� ����� ����� �������
    {
        int chance;
        srand(time(NULL));
        do
        {
            chance = rand() % 5 + 1;
        } while (chance < 2);
        hp_p1 = chance;
        hp_p2 = chance;

    }
}

void Buckshot_Roulette::hp_lose(int x)
{

    {
        if (!x)
            hp_p1 = hp_p1 - 1 - pila;
        else hp_p2 = hp_p2 - 1 - pila;
        pila = 0;
    }
}

void Buckshot_Roulette::hp_add()
{

    {
        if (!WhichMove && (hp_p1 != 6))
            hp_p1++;
        else if (hp_p2 != 6) hp_p2++;
    }
}

void Buckshot_Roulette::shot_opponent()
{

    {
        if (bullets[bullets.size() - 1]) //�������
        {
            if (!WhichMove)
                hp_lose(WhichMove + 1);
            if (WhichMove)
                hp_lose(WhichMove - 1);
            cout << "������ ������� ��������" << endl;
        }
        else cout << "������ �������� ��������" << endl; // ��������
        bullets.pop_back();
        if (!WhichMove)
            WhichMove = 1;
        else WhichMove = 0;
    }
}

void Buckshot_Roulette::shot_himself()
{

    {
        if (bullets[bullets.size() - 1])   // �������
        {
            if (!WhichMove)
                hp_lose(WhichMove);
            if (WhichMove)
                hp_lose(WhichMove);
            bullets.pop_back();
            if (!WhichMove)
                WhichMove++;
            else WhichMove--;
            cout << "������ ������� ��������" << endl;
        }
        else
        {
            bullets.pop_back();
            cout << "������ �������� ��������" << endl; // ��������
        }
    }
}

void Buckshot_Roulette::prev_item()
{

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
}

bool Buckshot_Roulette::Game_over()
{

    {
        if (!hp_p1)
            return true;
        if (!hp_p2)
            return true;
        return false;
    }
}

void Buckshot_Roulette::item_naruchniky()
{

    {
        if (WhichMove)
            naruchniky_p1 = true;
        else naruchniky_p2 = true;
    }
}

void Buckshot_Roulette::item_chance()
{

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
                inventory_p1[i + PreviousItem] = 1; // ����
                break;
            case 1:
                inventory_p1[i + PreviousItem] = 2; // ����
                break;
            case 2:
                inventory_p1[i + PreviousItem] = 3; // ����
                break;
            case 3:
                inventory_p1[i + PreviousItem] = 4; // ѳ��
                break;
            case 4:
                inventory_p1[i + PreviousItem] = 5; // �-��
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
                inventory_p2[i + PreviousItem] = 1; // ����
                break;
            case 1:
                inventory_p2[i + PreviousItem] = 2; // ����
                break;
            case 2:
                inventory_p2[i + PreviousItem] = 3; // ����
                break;
            case 3:
                inventory_p2[i + PreviousItem] = 4; // ѳ��
                break;
            case 4:
                inventory_p2[i + PreviousItem] = 5; // �-��
                break;
            }
        }

    }
}

void Buckshot_Roulette::item_interaction(int number)
{

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
                    cout << "������� ������" << endl;
                else cout << "������� �������" << endl;
                break;
            case 3:
                if (bullets[bullets.size() - 1] == 1)
                    cout << "������" << endl;
                else cout << "�������" << endl;
                break;
            case 4:
                hp_add();
                break;
            case 5:
                item_naruchniky();
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
                    cout << "������� ������" << endl;
                else cout << "������� �������" << endl;
                break;
            case 3:
                if (bullets[bullets.size() - 1] == 1)
                    cout << "������" << endl;
                else cout << "�������" << endl;
                break;
            case 4:
                hp_add();
                break;
            case 5:
                item_naruchniky();
                break;
            }
    }
}

string Buckshot_Roulette::item_name(int number)
{

    {
        switch (number)
        {
        case 0:
            return " ";
            break;
        case 1:
            return "����";
            break;
        case 2:
            return "���";
            break;
        case 3:
            return "����";
            break;
        case 4:
            return "ճ���";
            break;
        case 5:
            return "��������";
            break;
        }
    }
}

void Buckshot_Roulette::Game_start()
{

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
            cout << "� �������� " << bullets.size() << " �������" << endl;
            for (int i = 0; i < bullets.size(); i++)
            {
                if (bullets[i] == 1)
                    bull_da++;
                else bull_ni++;
            }
            cout << bull_da << " �������, " << bull_ni << " ��������" << endl;
            do  // ��� ����������� ����� ������� ������� ������� ��� ����� �����,
                //��� ���� �����������, � ���������� �������� ���� � ��������� �� WhichMove ��� ���� � ��, � ���������
            {
                if (Game_over())
                    break;
                while (!WhichMove)
                {
                    if (naruchniky_p1)
                    {
                        WhichMove++;
                        cout << "������� �������� ���" << endl;
                        naruchniky_p1 = false;
                        break;
                    }
                    if (Game_over())
                        break;
                    if (!bullets.size())
                        break;
                    cout << "������� 1" << endl;
                    cout << "� ����� " << hp_p1 << " ������'�" << endl;
                    cout << "� ����� ��� ��������:" << endl;
                    cout << "==== 0 - " << item_name(inventory_p1[0]) << endl << "==== 1 - " << item_name(inventory_p1[1]) << endl << "==== 2 - " << item_name(inventory_p1[2]) << endl << "==== 3 - " << item_name(inventory_p1[3]) << endl
                        << "==== 4 - " << item_name(inventory_p1[4]) << endl << "==== 5 - " << item_name(inventory_p1[5]) << endl << "==== 6 - " << item_name(inventory_p1[6]) << endl
                        << "==== 7 - " << item_name(inventory_p1[7]) << endl;
                    cout << "³� ������ �� ������ " << endl << "0 - 7 - ����������� ������� " << endl << "8 - ������ � ����" << endl << "9 - ������ � ��������" << endl;
                    cin >> chose;
                    hp_do_vistrela = hp_p1;
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
                        shot_himself();
                        if (hp_do_vistrela != hp_p1)
                            cout << "���� �� " << hp_p1 << endl;
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
                        cout << "������� �������� ���" << endl;
                        naruchniky_p2 = false;
                        break;
                    }
                    if (Game_over())
                        break;
                    if (!bullets.size())
                        break;
                    cout << "������� 2" << endl;
                    cout << "� ����� " << hp_p2 << " ������'�" << endl;
                    cout << "� ����� ��� ��������:" << endl;
                    cout << "==== 0 - " << item_name(inventory_p2[0]) << endl << "==== 1 - " << item_name(inventory_p2[1]) << endl << "==== 2 - " << item_name(inventory_p2[2]) << endl << "==== 3 - " << item_name(inventory_p2[3]) << endl
                        << "==== 4 - " << item_name(inventory_p2[4]) << endl << "==== 5 - " << item_name(inventory_p2[5]) << endl << "==== 6 - " << item_name(inventory_p2[6]) << endl
                        << "==== 7 - " << item_name(inventory_p2[7]) << endl;
                    cout << "³� ������ �� ������ " << endl << "0 - 7 - ����������� ������� " << endl << "8 - ������ � ����" << endl << "9 - ������ � ��������" << endl;
                    cin >> chose;
                    hp_do_vistrela = hp_p2;
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
                        shot_himself();
                        if (hp_do_vistrela != hp_p2)
                            cout << "���� �� " << hp_p2 << endl;
                        break;
                    case 9:
                        shot_opponent();
                        break;
                    }
                }

            } while (bullets.size());
        }
        system("cls");
        if (!hp_p1)
            cout << "������� ������� #1 " << endl;
        if (!hp_p2)
            cout << "������� ������� #2 " << endl;
        for (int i = 0; i < inventory_p1.size(); i++)
        {
            inventory_p1[i] = 0;
            inventory_p2[i] = 0;
        }

    }
}

void Buckshot_Roulette::Game_info()
{
    cout << "�� ��� ���� ��� Buckshot roulette, ��� ��� ���� �������, ��� ���  ��� �� ���� ��� ���������� ��� ������� �� ��������:  " << endl
        << "-------------------�������-------------------" << endl
        << "����� ����� � �������� ����������� �� 8 �������, ���� � ��� � ���������, ���� - ��������" << endl
        << "� ������� � ����� ������'�, �������� ���� ���� 5 ���� ������'� �� ������" << endl
        << "������ ��� �������, � ����� �� ���������� ���� ������'� " << endl
        << "�������� ����� ��� � ����� ��������, ��� ����� ����� ������� ������ ��� � ����, ��� � �������� " << endl
        << "���� ����� ������ � ��������, ��������� �� ������ ��������, �� �������, ��� ��� ����������" << endl
        << "���� ����� ������ � ����, � ������ �������, �� ��� ��� ����������" << endl
        << "����� ���� ����� ������ � ����, � ������ ��������, �� ��� ��� �� ����������" << endl
        << "ϳ� ��� ������ ���� ����� ��������������� ��� ��������, �� �� ��������� ��� ���, � ����� ���������" << endl
        << "-------------------��������------------------" << endl
        << "1. ��� - �������� ���� ���� � �������� " << endl
        << "2. ���� - �������� ��������� ��� ���� ����� ���������" << endl
        << "3. ���� - ������ ���� ��� �� 1, ����� ��������������� ��� �� ���" << endl
        << "4. �������� - ��������� ������ �������� ���������� ���, ����� ��������������� ���� ���, �� ���������� ���� ��������" << endl
        << "5. ճ��� - ���� ���� ���� ������'� " << endl << "----------------------------------------------" << endl
        << "developed by \"GamesB(c)\", sponsored by \"Eugene's vine(c)\"" << endl;
}
