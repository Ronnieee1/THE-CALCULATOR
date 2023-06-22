#include<iostream>
#include<string>
using namespace std;

struct number {
    double num1;
    double num2;
    double answer;
    char operation;
} a[10];

void add();
void subs();
void mult();
void divi();
void historydisp();

char back, history, respo1;
string ptr;
int main() {
    do {
        system ("cls");
        cout << "---The Calculator" << endl << endl;
        cout << "Please input the numbers you want to solve:" << endl;
        cin >> a[0].num1;
        cin >> a[0].operation;
        cin >> a[0].num2;

        if (a[0].operation == '+') {
            add();
            cout << a[0].num1 << "+" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '-') {
            subs();
            cout << a[0].num1 << "-" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '*') {
            mult();
            cout << a[0].num1 << "*" << a[0].num2 << "=" << a[0].answer << endl;
        }
        else if (a[0].operation == '/') {
            if (a[0].num2 == 0) {
                cout << "UNDEFINED" << endl;
            }
            else {
                divi();
                cout << a[0].num1 << "/" << a[0].num2 << "=" << a[0].answer << endl;
            }
        }
        else {
            cout << "Invalid operator" << endl;
            continue;
        }

        for (int i = 9; i > 0; i--) {
            a[i].num1 = a[i - 1].num1;
            a[i].operation = a[i - 1].operation;
            a[i].num2 = a[i - 1].num2;
            a[i].answer = a[i - 1].answer;
        }

        cout << "Do you want to show the history? [Y/N]:";
        cin >> respo1;
        cout << endl << endl;
        if (respo1 == 'y' || respo1 == 'Y') {
            historydisp();
        }

     cout << "Continue? [Y/N]:";
        cin >> back;
        cout << endl << endl;
    } while (back == 'y' || back == 'Y');

    return 0;
}

void add() {
    a[0].answer = a[0].num1 + a[0].num2;
}

void subs() {
    a[0].answer = a[0].num1 - a[0].num2;
}

void mult() {
    a[0].answer = a[0].num1 * a[0].num2;
}

void divi() {
    a[0].answer = a[0].num1 / a[0].num2;
}

void historydisp() {
    string *pointer = &ptr;

    for (int i = 0; i < 9; i++) {
        cout << (a[i].num1) << (a[i].operation) << (a[i].num2) << "=" << (a[i].answer) << pointer + i << endl << endl;
    }
}
