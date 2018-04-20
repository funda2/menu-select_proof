#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <conio.h>

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

class interfacex {
    public:
        void gotoxy_select(int x, int y);
        void gotoxy(int x, int y);
        void menu();
        void pause();
        void refresh();
        void supercomplete() {
            system("cls");
            std::cout<<"\n COMPLETADO";
        }
    private:
};

void interfacex::gotoxy_select(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
    std::cout<<"-";
}

void interfacex::gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void interfacex::menu() {
    std::cout<<"\n\n   Inicio";
    std::cout<<"\n   Ajustes";
    std::cout<<"\n   Creditos";
    std::cout<<"\n   Salir\n";
}

void interfacex::pause() {
    std::cin.ignore();
}

void interfacex::refresh() {
    system("cls");
}

void loop_refresh() {
    interfacex ui;
    bool enter = 0;
    int option_selected = 0;
    int selectpos = 2;
    char key;
    int c = 0;
    while(enter == 0) {
        ui.refresh();
        ui.menu();
        ui.gotoxy_select(2, selectpos);
        ui.gotoxy(9,9);
        switch ((c=getch())) {
            case '\r':
                if (selectpos == 2) {
                    ui.supercomplete();
                    ui.pause();
                }
                if (selectpos == 3) {
                    system("cls");
                    std::cout<<"ajustes";
                    ui.pause();
                }
                if (selectpos == 4) {
                    system("cls");
                    std::cout<<"creditos";
                    ui.pause();
                }
                if (selectpos == 5) {
                    system("cls");
                    enter = 1;
                }
                else {
                    std::cout<<"ERROR";
                }
                break;
            case KEY_UP:
                if (selectpos == 2) {
                    //nada
                }
                else {
                selectpos = selectpos - 1;
                }
                break;
            case KEY_DOWN:
                if (selectpos == 5) {
                    //nada
                }
                else {
                selectpos = selectpos + 1;
                }
                break;
        }
    }
}

int main(int argc, char *argv) {
    loop_refresh();
    return 0;
}
