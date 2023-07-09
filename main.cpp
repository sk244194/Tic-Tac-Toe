#include <iostream>
using namespace std;

char box[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int check() {
    if (box[1] == box[2] && box[2] == box[3])
        return 1;
    else if (box[4] == box[5] && box[5] == box[6])
        return 1;
    else if (box[7] == box[8] && box[8] == box[9])
        return 1;
    else if (box[1] == box[5] && box[5] == box[9])
        return 1;
    else if (box[3] == box[5] && box[5] == box[7])
        return 1;
    else if (box[1] == box[4] && box[4] == box[7])
        return 1;
    else if (box[2] == box[5] && box[5] == box[8])
        return 1;
    else if (box[3] == box[6] && box[6] == box[9])
        return 1;
    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' &&
             box[6] != '6' && box[5] != '5' && box[4] != '4' &&
             box[7] != '7' && box[8] != '8' && box[9] != '9')
        return 0;
    else
        return -1;
}

void board() {
    cout << "\n\n\t Tic Tac Toe\n\n\n";
    cout << "Player 1[X]" << endl;
    cout << "Player 2[O]" << endl;

    cout << "     |     |     \n";
    cout << "  " << box[1] << "  |  " << box[2] << "  |  " << box[3] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << box[4] << "  |  " << box[5] << "  |  " << box[6] << " \n";
    cout << "_____|_____|_____\n";
    cout << "     |     |     \n";
    cout << "  " << box[7] << "  |  " << box[8] << "  |  " << box[9] << " \n";
    cout << "     |     |     \n";
}

int main() {
    int player = 1, i, choice;
    char mark;

    do {
        board();
        player = (player % 2) ? 1 : 2;

        cout << "Player " << player << " -- Choice: ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        if (box[choice] != 'X' && box[choice] != 'O') {
            box[choice] = mark;
        } else {
            cout << "Invalid Move";
            player--;
            cin.ignore();
            cin.get();
        }
        i = check();
        player++;
    } while (i == -1);

    board();
    if (i == 1) {
        cout << "\aCongratulation! Player " << --player << " won" << endl;
    } else {
        cout << "\aGame draw" << endl;
    }

    cin.ignore();
    cin.get();
    return 0;
}
