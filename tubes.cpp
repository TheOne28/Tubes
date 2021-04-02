#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

struct chara {
    int x = 0;
    int y = 0;
    float health = 0;
    float damage;
};

chara robot;
chara cockroach;
//Fungsi gerak
void move() {
    bool moved = false;
    string direction;
    do {
        // W A S D
        cout << "Masukkan arah gerak (W) atas, (A) kiri, (S) bawah, (D) kanan : "; // kayak ga pernah main game aja
        cin >> direction;

        if (direction == "W" || direction == "w"){ //Gerak ke atas
            if ((robot.y + 1 == cockroach.y) && (robot.x == cockroach.x)) {
                cout << "Menabrak kecoak\n";
            }
            else if (robot.y == 100) {
                cout << "Keluar bidang\n";
            }
            else {
                robot.y++;
                moved = true;
            }
        }
        else if (direction == "S" || direction == "s") { //Gerak ke bawah
            if ((robot.y - 1 == cockroach.y) && (robot.x == cockroach.x)) {
                cout << "Menabrak kecoak\n";
            }
            else if (robot.y == 0) {
                cout << "Keluar bidang\n";
            }
            else {
                robot.y--;
                moved = true;
            }
        }
        else if (direction == "A" || direction == "a") { //Gerak ke kiri
            if ((robot.x - 1 == cockroach.x) && (robot.y == cockroach.y)) {
                cout << "Menabrak kecoak\n";
            }
            else if (robot.x == 0) {
                cout << "Keluar bidang\n";
            }
            else {
                robot.x--;
                moved = true;
            }
        }
        else if (direction == "D" || direction == "d") { //Gerak ke kanan
            if ((robot.x + 1 == cockroach.x) && (robot.y == cockroach.y)) {
                cout << "Menabrak kecoak\n";
            }
            else if (robot.x == 100) {
                cout << "Keluar bidang\n";
            }
            else {
                robot.x++;
                moved = true;
            }
        }
        else {
            cout << "Masukan tidak valid\n";
        }
    } while (!moved);
}
//Fungsi menembak
void shoot(int range, int distance) {
    if (distance <= range) {
        cockroach.health -= robot.damage;
    }
    else {
        cout << "Out of range\n";
    }
}


int main() {
    srand((unsigned)time(0));
    int count = 0;
    // Asumsi health 10, damage = 2
    robot.health = 10;
    robot.damage = 2;
    bool finish = false;
    while (robot.health > 0) {
        // Asumsi maksimal papan 100
        if (cockroach.health <= 0) {
            do {
                cockroach.x = rand() % 10;
                cockroach.y = rand() % 10;
            } while (cockroach.x == robot.x && cockroach.y == robot.y);
            cockroach.health = (rand() % 6) + 1;
        }
        cout << "Posisi Kecoak (X,Y) : " << cockroach.x << "," << cockroach.y << endl;
        cout << "Posisi Robot (X,Y) : " << robot.x << "," << robot.y << endl;
        float distance = sqrt(pow((cockroach.x - robot.x), 2) + pow((cockroach.y - robot.y), 2));
        cockroach.damage = 1;
        // Jarak diasumsikan berupa jarak terdekat yang dapat berupa diagonal

        int range = 2;

        if (distance <= range) {
            robot.health -= cockroach.damage;
        }
        cout << "Health Kecoak : " << cockroach.health << "             Health Robot : " << robot.health << "\n"<< endl;
        //Input pertama
        string command;
        bool valid = false;
        //Gerak = M or m, tembak = K or k
        do {
            float distance = sqrt(pow((cockroach.x - robot.x), 2) + pow((cockroach.y - robot.y), 2));
            if (distance <= range) {
                cout << "Kecoak dalam jarak tembak \n";
            }
            cout << "Silahkan masukkan komando (M)ove (K)ill : ";
            cin >> command;
            if (command == "M" || command == "m") { //Perintah bergerak
                move();
                valid = true;
            }
            else if (command == "K" || command == "k") { //Perintah menembak
                shoot(range, distance);
                if (cockroach.health <= 0) {
                    count++;
                }
                valid = true;
            }
            else if (command == "Q" || command == "q") {
                finish = true;
                valid = true;
            }
            else if (command == "H" || command == "h"){  //
                if (robot.health < 10){
                    robot.health = 10;
                    robot.x = 0;
                    robot.y = 0;
                }
                else if (robot.health == 10){
                    cout << "Nyawa robot penuh" << endl;
                }
                valid = true;
            }
            else {
                cout << "Perintah tidak terdefinisi \n";
            }
        } while (!valid);

        if (finish) {
            break;
        }
    }
    cout << "Jumlah kecoak dibunuh: " << count << endl;
}
