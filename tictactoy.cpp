#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void drawBoard(char *arr)
{
    cout << "     |     |     " << "\n";
    cout << "  " << arr[0] << "  |  " << arr[1] << "  |  " << arr[2] << "  " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << arr[3] << "  |  " << arr[4] << "  |  " << arr[5] << "  " << "\n";
    cout << "_____|_____|_____" << "\n";
    cout << "     |     |     " << "\n";
    cout << "  " << arr[6] << "  |  " << arr[7] << "  |  " << arr[8] << "  " << "\n";
    cout << "     |     |     " << "\n\n";
}

void playerMove(char *arr, char player)
{
    int num;
    do
    {
        cout << "Enter the spot: ";
        cin >> num;
        num--;
        if (arr[num] == ' ')
        {
            arr[num] = player;
            break;
        }
    } while (!num > 0 || !num < 8);
}

void comMove(char *arr, char comp)
{
    int num;
    srand(time(0));
    while (true)
    {
        num = rand() % 10;
        if (arr[num] == ' ')
        {
            arr[num] = comp;
            break;
        }
    }
}

bool checkWin(char *arr, char player, char comp)
{
    if (arr[0] != ' ' && arr[0] == arr[1] && arr[1] == arr[2])
    {
        arr[0] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[3] != ' ' && arr[3] == arr[4] && arr[4] == arr[5])
    {
        arr[3] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[6] != ' ' && arr[6] == arr[7] && arr[7] == arr[8])
    {
        arr[6] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[0] != ' ' && arr[0] == arr[3] && arr[3] == arr[6])
    {
        arr[0] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[1] != ' ' && arr[1] == arr[4] && arr[4] == arr[7])
    {
        arr[1] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[2] != ' ' && arr[2] == arr[5] && arr[5] == arr[8])
    {
        arr[2] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[0] != ' ' && arr[0] == arr[4] && arr[4] == arr[8])
    {
        arr[0] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else if (arr[2] != ' ' && arr[2] == arr[4] && arr[4] == arr[6])
    {
        arr[2] == player ? cout << "You Win...😃👍" : cout << "Huh Loser!!!🤣🤣";
    }
    else
    {
        return false;
    }
    return true;
}

bool checkTie(char *arr)
{
    for (int i = 0; i < 9; i++)
    {
        if (arr[i] == ' ')
        {
            return false;
        }
    }
    cout << "It's a tie!!!🫢🫢🫢";
    return true;
}

int main()
{
    char board[9] = {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
    char player = 'X';
    char comp = 'O';
    bool running = true;
    drawBoard(board);

    while (running)
    {
        playerMove(board, player);
        drawBoard(board);
        if (checkWin(board, player, comp))
        {
            running = false;
            break;
        }
        else if (checkTie(board))
        {
            running = false;
            break;
        }
        comMove(board, comp);
        drawBoard(board);
    }
    cout << "\nThanks for playing...";
    return 0;
}