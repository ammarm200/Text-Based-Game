#include<iostream>
using namespace std;

int mainScreen()
{
    Jump:
    system("CLS");
    cout<<"___________________"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|                     WELCOME                       |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|       1. Start New Game                           |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|       2. Credential                               |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|       3. Attack List                              |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|       4. Quit                                     |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|_________________|"<<endl;
    int n = 0;
    cout<<"Select One: ";
    cin>>n;
    if(n > 4 || n <= 0)
    {
        goto Jump;
    }
    return n;

}

int game_type()
{
    Jump:
    system("CLS");
    cout<<"___________________"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|        1. Easy                                    |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|        2. Medium                                  |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|        3. Hard                                    |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|        4. Very Hard                               |"<<endl;
    cout<<"|                                                   |"<<endl;
    cout<<"|_________________|"<<endl;
    int n = 0;
    cout<<"Select One: ";
    cin>>n;
    if(n > 4 || n <= 0)
    {
        goto Jump;
    }
    return n;

}

void display_fight(string player_name, int player_health,string enemy_name, int enemy_health, int enemy_power)
{
    system("CLS");
    cout<<"___________________"<<endl<<endl;
    cout<<"        Name: "<<player_name<<endl<<endl;
    cout<<"        Health: "<<player_health<<endl<<endl;
    cout<<"        Player Power: 10"<<endl<<endl;
    cout<<"___________________"<<endl<<endl;
    cout<<"        Enemy Name: "<<enemy_name<<endl<<endl;
    cout<<"        Health: "<<enemy_health<<endl<<endl;
    cout<<"        Enemy Power: "<<enemy_power<<endl<<endl;
    cout<<"___________________"<<endl<<endl;

}

void status(bool check)
{
    system("CLS");
    if(check == true)
    {
        cout<<"___________________"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|                     YOU WIN                       |"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|_________________|"<<endl;
    }
    else
    {
        cout<<"___________________"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|                     YOU LOSE                      |"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|_________________|"<<endl;
    }
}

bool start_game_ranadom(int type)
{
    system("CLS");
    string player_name;
    cout<<"Enter Your Name: ";
    cin>>player_name;
    int player_health = 100;
    string enemy_name_list[6] = {"Howerang",  "Paul", "Heihachi", "Kazuya", "Jin", "Azazel"};
    string enemy_name;
    int enemy_health = 100;
    int count = 1 ;
    bool attack = false;
    int attack_power = 5 * type;
    string command;
    for(int round = 1; round <= 6 ; round++){
        attack_power = 5 * type + round;
        player_health = 100;
        enemy_name = enemy_name_list[round-1];
        
        if(round == 6){
            enemy_health = 20 * type + 200;
            attack_power = 5 * type * round;
        }
        else
        {
            enemy_health = 100;
        }
        while(enemy_health > 0 && player_health > 0)
        {
            display_fight(player_name, player_health, enemy_name, enemy_health, attack_power);
            cout<<"A : Attack"<<endl;
            cout<<"D : Dodge"<<endl;
            if(count % 2 == 0)
            {
                cout<<"|  Enemy is Attacking  |"<<endl<<endl;
                attack = true;
            }
            cin>>command;
            if(command == "WASD")
            {
                enemy_health -= 40;
            }
            else if(command == "DSA")
            {
                enemy_health -= 20;
            }
            else if(command == "OIU")
            {
                enemy_health -= 25;
            }
            else if(command == "AA")
            {
                enemy_health -= 15;
            }
            else if(command == "XYZ")
            {
                enemy_health -= 35;
            }
            else if(command == "QWE")
            {
                enemy_health -= 10;
                attack = false;
            }
            else if(command == "A")
            {
                enemy_health -= 10;
            }
            else if(command == "D")
            {
                cout<<"Dodge Successfully"<<endl;
                attack = false;
            }
            if(attack == true)
            {
                player_health -= attack_power;
                attack = false;
            }
            count++;
        
        }
        if(enemy_health >= 0)
        {
            return false;
        }
        else
        {
            status(true);
            system("pause");
        }
    }
    if(enemy_health <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}

void Credential()
{
        cout<<"___________________"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|             Made By: Ammar Amir                   |"<<endl;
        cout<<"|                                                   |"<<endl;
        cout<<"|_________________|"<<endl;
}

void ComboCode()
{
        system("CLS");
        cout<<"___________________"<<endl<<endl;
        cout<<"   Attack Name          |  Damage  |       Command   "<<endl<<endl;
        cout<<"___________________"<<endl<<endl;
        cout<<"   Heavy Attack         |  40      |        WASD    "<<endl<<endl;
        cout<<"   Sparkal Fist         |  20      |        DSA     "<<endl<<endl;
        cout<<"   Tornado Punch        |  25      |        OIU     "<<endl<<endl;
        cout<<"   Medium Attack        |  15      |        AA      "<<endl<<endl;
        cout<<"   Finish Him           |  35      |        XYZ     "<<endl<<endl;
        cout<<"   Counter              |  10      |        QWE     "<<endl<<endl;
}

int main()
{
    int n = 0;
    START:
    int menu = mainScreen();
    
    if(menu == 1)
    {
        n = game_type();    
        if(start_game_ranadom(n))
        {
            status(true);
        }
        else
        {
            status(false);
        }
        system("pause");
        goto START;   
    }
    else if(menu == 2)
    {
        Credential();
        system("pause");
        goto START; 

    }
    else if(menu == 3)
    {
        ComboCode();
        system("pause");
        goto START; 

    }
    else if(menu == 4)
    {
        return 0;
    }
    else
    {
        goto START;
    }
    return 0;
}
