#include <iostream>
#include <ctime>
#include <cstdlib>

int getRandomNumber(int max);
int displayDice(int);
int rollDice(int);
int holdDice(int);

int sixD(int);
int pair(int);

struct Dice
{
    char num = ' ';
    bool hold = 0;
    char display = ' ';
};

Dice d[5];



int main()
{
    srand(time(nullptr));

    bool done = 0;

    do
    {
        

        displayDice(0);

        char menu = ' ';
        std::cout << "\n \nWhat do you want to do?" << std::endl;
        std::cout << "f: Roll dice \ng: Hold dice \nh: Stop holding \n\nv: Look for six \nb: Look for pairs" << std::endl;
        std::cin >> menu;

        system("CLS");

        if (menu == 'f')
        {
            rollDice(0);
            
        }
        else if (menu == 'g')
        {
            holdDice(0);
        }
        else if (menu == 'h')
        {
            for (int i = 0; i < 6; i++)
            {
                d[i].hold = 0;
            }
            std::cout << "Holding stopped" << std::endl;
        }
        else if (menu == 'v')
        {
            sixD(0);
        }
        else if (menu == 'b')
        {
            pair(0);
        }
        else
        {
            std::cout << "Please select valid option" << std::endl;
            system("PAUSE");
        }

        
    } while (done == 0);
    


}

int displayDice(int)
{
    for (int i = 0; i < 5; i++)
    {
        if (d[i].hold == 1)
        {
            d[i].display = 'h';
        }
        else
        {
            d[i].display = '0' + i + 1;
        }
    }

    std::cout << "\n" << "Dice:\t    " << d[0].display << "\t   " << d[1].display << " \t  " << d[2].display << " \t  " << d[3].display << " \t  " << d[4].display << std::endl;
    std::cout << "\n" << "\t   --- \t  --- \t --- \t --- \t ---";
    std::cout << "\n" << "Dice roll:" << "| " << d[0].num << " | " << " | " << d[1].num << " | " << " | " << d[2].num << " | " << "  | " << d[3].num << " | " << "  | " << d[4].num << " | ";
    std::cout << "\n" << "\t   --- \t  --- \t --- \t --- \t ---";
    return 0;
}

int rollDice(int)
{
    for (int i = 0; i < 5; i++)
    {
        if (d[i].hold == 0)
        {
            d[i].num = '0' + getRandomNumber(6);
        }
    }
   
    return 0;
}

int holdDice(int)
{
    system("CLS");

    bool done = 0;
    do
    {
        displayDice(0);

        int dice = 0;
        std::cout << "\nSelect dice to hold, or 0 to stop" << std::endl;
        std::cin >> dice;

        if (dice > 0 && dice < 7)
        {
            d[dice - 1].hold = 1;
        }
        else if (dice == 0)
        {
            done = 1;
        }
        
        system("CLS");
    } while (done == 0);

    return 0;
    
}

int sixD(int)
{
    int six = 0;
    for (int i = 0; i < 5; i++)
    {
        if (d[i].num == '6')
        {
            six++;
        }
    }

    std::cout << "You now have " << six << " die with the number 6" << std::endl;


    return 0;
}

int pair(int)
{
    char pair = ' ';
    

    for (int i = 0; i < 5; i++)
    {
        int numofnum = 1;

        for (int j = 0; j < 5; j++)
            if (i == j)
            {
                break;
            }
            else if (d[i].num == d[j].num)
            {
                pair = d[i].num;
                numofnum++;
            }

        switch (numofnum)
        {
        case 5:
            std::cout << "WOW! All the dices are " << pair << "!" << std::endl;
            break;
        case 4:
            std::cout << "There are " << numofnum << " of " << pair << std::endl;
            break;
        case 3:
            std::cout << "There are " << numofnum << " of " << pair << std::endl;
            break;
        case 2:
            std::cout << "There is a pair of " << pair << std::endl;
            break;
        }
        
    }

    return 0;
}

int getRandomNumber(int max)
{
    int randomNumber = rand() % max + 1;
    return randomNumber;
}