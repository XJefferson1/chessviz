#include "source.h"

using namespace std;

void Chessplace(char pole[][9])
{
    cout << endl;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (j == 0) {
                cout << " ";
            }
            cout << pole[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void move_all(char pole[][9], int* team)
{
    int x1 = 9, x2 = 9, y1 = 0, y2 = 0;
    string step;
    cout << endl << "Your move: ";
    cin >> step;
    if (step == "exit") {
        cout << "Exit the programm";
        exit(0);
    }
    if (step.length() != 5) {
        cout << "\nERROR\n";
        return;
    }
    switch (step[0]) {
    case 'a':
        y1 = 1;
        break;
    case 'b':
        y1 = 2;
        break;
    case 'c':
        y1 = 3;
        break;
    case 'd':
        y1 = 4;
        break;
    case 'e':
        y1 = 5;
        break;
    case 'f':
        y1 = 6;
        break;
    case 'g':
        y1 = 7;
        break;
    case 'h':
        y1 = 8;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }
    switch (step[1]) {
    case '1':
        x1 = 7;
        break;
    case '2':
        x1 = 6;
        break;
    case '3':
        x1 = 5;
        break;
    case '4':
        x1 = 4;
        break;
    case '5':
        x1 = 3;
        break;
    case '6':
        x1 = 2;
        break;
    case '7':
        x1 = 1;
        break;
    case '8':
        x1 = 0;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }
    if (step[2] != '-') {
        cout << "\nERROR\n";
        return;
    }
    switch (step[3]) {
    case 'a':
        y2 = 1;
        break;
    case 'b':
        y2 = 2;
        break;
    case 'c':
        y2 = 3;
        break;
    case 'd':
        y2 = 4;
        break;
    case 'e':
        y2 = 5;
        break;
    case 'f':
        y2 = 6;
        break;
    case 'g':
        y2 = 7;
        break;
    case 'h':
        y2 = 8;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }
    switch (step[4]) {
    case '1':
        x2 = 7;
        break;
    case '2':
        x2 = 6;
        break;
    case '3':
        x2 = 5;
        break;
    case '4':
        x2 = 4;
        break;
    case '5':
        x2 = 3;
        break;
    case '6':
        x2 = 2;
        break;
    case '7':
        x2 = 1;
        break;
    case '8':
        x2 = 0;
        break;
    default:
        cout << "\nERROR\n";
        return;
    }

    int flag = move_check(*team, x1, x2, y1, y2, pole);
    if (flag == 1) {
        if ((pole[x2][y2] == 'k') || (pole[x2][y2] == 'K')) {
            cout << "\n You win!";
            exit(0);
        }
        pole[x2][y2] = pole[x1][y1];
        pole[x1][y1] = ' ';
        switch (*team) {
        case 0:
            if ((pole[x2][y2] == 'P') && (x2 == 0)) {
                char transform = ' ';
                while (transform == ' ') {
                    cout << endl << "Transform your pawn: ";
                    cin >> transform;
                    if ((transform != 'R') && (transform != 'N')
                        && (transform != 'B') && (transform != 'Q')) {
                        transform = ' ';
                    }
                }
                pole[x2][y2] = transform;
            }
            break;
        case 1:
            if ((pole[x2][y2] == 'p') && (x2 == 7)) {
                char transform = ' ';
                while (transform == ' ') {
                    cout << endl << "Transform your pawn: ";
                    cin >> transform;
                    if ((transform != 'r') && (transform != 'n')
                        && (transform != 'b') && (transform != 'q')) {
                        transform = ' ';
                    }
                }
                pole[x2][y2] = transform;
            }
            break;
        }
        *team = 1 - *team;
    } else {
        cout << "\nERROR\n";
    }
    cout << endl;
    cout << endl;
}

int move_check(int team, int x1, int x2, int y1, int y2, char pole[][9])
{
    int flag = 0;
    if ((x1 == x2) && (y1 == y2)) {
        cout << "\nERROR\n";
        return 0;
    }
    switch (team) {
    case 0:
        switch (pole[x1][y1]) {
        case ' ':
            cout << "\nERROR\n";
            return 0;
        case 'P':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y1 == y2) && (x1 - x2 == 1) && (pole[x2][y2] == ' '))
                    flag = 1;
                if ((y1 == y2) && (x1 - x2 == 2) && (x1 == 6)
                    && (pole[x2][y2] == ' ')) {
                    if (pole[x2 + 1][y2] == ' ') {
                        flag = 1;
                    } else {
                        cout << "\nERROR\n";
                        return 0;
                    }
                }
                if ((x1 - x2 == 1) && (pole[x2][y2] != ' ')
                    && ((y1 - y2 == 1) || (y2 - y1 == 1)))
                    flag = 1;
            }
            break;
        case 'R':
            if (friendly(team, x2, x2, pole) == 1) {
                if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;
        case 'N':
            if (friendly(team, x2, y2, pole) == 1) {
                if (((x2 == x1 - 2) && (y2 == y1 + 1))
                    || ((x2 == x1 - 2) && (y2 == y1 - 1))
                    || ((x2 == x1 + 2) && (y2 == y1 + 1))
                    || ((x2 == x1 + 2) && (y2 == y1 - 1))
                    || ((x2 == x1 - 1) && (y2 == y1 + 2))
                    || ((x2 == x1 - 1) && (y2 == y1 - 2))
                    || ((x2 == x1 + 1) && (y2 == y1 + 2))
                    || ((x2 == x1 + 1) && (y2 == y1 - 2))) {
                    flag = 1;
                }
            }
            break;
        case 'B':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;
        case 'Q':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }

                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;

        case 'K':
            if (friendly(team, x2, y2, pole) == 1) {
                flag = 1;
            }
            break;
        default:
            cout << "\nERROR\n";
            break;
        }
        break;
    case 1:
        switch (pole[x1][y1]) {
        case ' ':
            cout << "\nERROR\n";
            return 0;
        case 'p':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y1 == y2) && (x2 - x1 == 1) && (pole[x2][y2] == ' '))
                    flag = 1;
                if ((y1 == y2) && (x2 - x1 == 2) && (x1 == 1)
                    && (pole[x2][y2] == ' ')) {
                    if (pole[x2 - 1][y2] == ' ') {
                        flag = 1;
                    } else {
                        cout << "\nERROR\n";
                        return 0;
                    }
                }
                if ((x2 - x1 == 1) && (pole[x2][y2] != ' ')
                    && ((y2 - y1 == 1) || (y1 - y2 == 1)))
                    flag = 1;
            }
            break;
        case 'r':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;
        case 'n':
            if (friendly(team, x2, y2, pole) == 1) {
                if (((x2 == x1 - 2) && (y2 == y1 + 1))
                    || ((x2 == x1 - 2) && (y2 == y1 - 1))
                    || ((x2 == x1 + 2) && (y2 == y1 + 1))
                    || ((x2 == x1 + 2) && (y2 == y1 - 1))
                    || ((x2 == x1 - 1) && (y2 == y1 + 2))
                    || ((x2 == x1 - 1) && (y2 == y1 - 2))
                    || ((x2 == x1 + 1) && (y2 == y1 + 2))
                    || ((x2 == x1 + 1) && (y2 == y1 - 2))) {
                    flag = 1;
                }
            }
            break;
        case 'b':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;
        case 'q':
            if (friendly(team, x2, y2, pole) == 1) {
                if ((y1 == y2) && (x1 != x2)) {
                    if (x1 > x2) {
                        for (int i = x1 - 1; i > x2; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (x1 < x2) {
                        for (int i = x2 - 1; i > x1; i--) {
                            if (pole[i][y1] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((x1 == x2) && (y1 != y2)) {
                    if (y1 > y2) {
                        for (int i = y1 - 1; i > y2; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                    if (y1 < y2) {
                        for (int i = y2 - 1; i > y1; i--) {
                            if (pole[x1][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 < x1)) {
                    if (y1 - y2 == x1 - x2) {
                        for (int i = y1 - 1, v = x1 - 1; i > y2 && v > x2;
                             i--, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\n ERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 < y1) && (x2 > x1)) {
                    if (y1 - y2 == x2 - x1) {
                        for (int i = y1 - 1, v = x1 + 1; i > y2 && v < x2;
                             i--, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\ERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 < x1)) {
                    if (y2 - y1 == x1 - x2) {
                        for (int i = y1 + 1, v = x1 - 1; i < y2 && v > x2;
                             i++, v--) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
                if ((y2 > y1) && (x2 > x1)) {
                    if (y2 - y1 == x2 - x1) {
                        for (int i = y1 + 1, v = x1 + 1; i < y2 && v < x2;
                             i++, v++) {
                            if (pole[v][i] != ' ') {
                                cout << "\nERROR\n";
                                return 0;
                            }
                        }
                        flag = 1;
                    }
                }
            }
            break;
        case 'k':
            if (friendly(team, x2, y2, pole) == 1) {
                flag = 1;
            }
            break;
        default:
            cout << "\nERROR\n";
            break;
        }
        break;
    }
    return flag;
}

int friendly(int side, int x2, int y2, char pole[][9])
{
    int flag = 1;
    switch (side) {
    case 0:
        if ((pole[x2][y2] == 'P') || (pole[x2][y2] == 'R')
            || (pole[x2][y2] == 'N') || (pole[x2][y2] == 'B')
            || (pole[x2][y2] == 'Q') || (pole[x2][y2] == 'K')) {
            cout << "\n ERROR\n";

            flag = 0;
        }
        break;
    case 1:
        if ((pole[x2][y2] == 'p') || (pole[x2][y2] == 'r')
            || (pole[x2][y2] == 'n') || (pole[x2][y2] == 'b')
            || (pole[x2][y2] == 'q') || (pole[x2][y2] == 'k')) {
            cout << "\ERROR\n";
            ;
            flag = 0;
        }
        break;
    }
    return flag;
}
