#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

struct chara{
    int x = 0;
    int y = 0;
    float health = 0; 
    float damage;
};

chara robot;
chara cockroach;

void move(){
    bool moved = false;
    string direction;
    do{
        // U D L R
        cout << "Masukkan arah gerak: ";
        cin >> direction;

        if(direction == "U" || direction == "u"){
            if((robot.y + 1 == cockroach.y ) && (robot.x == cockroach.x)){
                cout << "Menabrak kecoak\n";
            }
            else if(robot.y == 100){
                cout << "Keluar bidang\n";
            }
            else{
                robot.y ++;
                moved = true;
            }
        }
        else if(direction == "D" || direction == "d"){
            if((robot.y - 1 == cockroach.y ) && (robot.x == cockroach.x)){
                cout << "Menabrak kecoak\n";
            }
            else if(robot.y == 0){
                cout << "Keluar bidang\n";
            }
            else{
                robot.y --;
                moved = true;
            }
        }
        else if(direction == "L" || direction == "l"){
            if((robot.x - 1 == cockroach.x ) && (robot.y == cockroach.y)){
                cout << "Menabrak kecoak\n";
            }
            else if(robot.x == 0){
                cout << "Keluar bidang\n";
            }
            else{
                robot.x --;
                moved = true;
            }
        }
        else if(direction == "R" || direction == "r"){
            if((robot.x + 1 == cockroach.x ) && (robot.y == cockroach.y)){
                cout << "Menabrak kecoak\n";
            }
            else if(robot.x == 100){
                cout << "Keluar bidang\n";
            }
            else{
                robot.x ++;
                moved = true;
            }
        }
        else{
            cout << "Masukan tidak valid\n";
        }
    }
    while(!moved);
    cout << robot.x << " " << robot.y << endl;
}

void shoot(int range, int distance){
    if(distance <= range){
        cockroach.health -= robot.damage;
    }
    else{
        cout << "Out of range\n" ;
    }
}


int main(){
    srand((unsigned) time(0));
    int count = 0;
    // Asumsi health 10, damage = 2
    robot.health = 10;
    robot.damage = 2;
    bool finish = false;
    while(robot.health > 0){
        // Asumsi maksimal papan 100
        if(cockroach.health <= 0){
            while(cockroach.x == robot.x && cockroach.y == robot.y ){        
                cockroach.x = rand() % 10;
                cockroach.y = rand() % 10;
            }
            cockroach.health = (rand() %  6) + 1;
        }
        cout << cockroach.x << " " << cockroach.y << endl;
        float distance = sqrt(pow((cockroach.x - robot.x), 2) + pow((cockroach.y - robot.y), 2));
        cockroach.damage = 1;
        // Jarak diasumsikan berupa jarak terdekat yang dapat berupa diagonal

        int range = 2;

        if(distance <= range){
            robot.health -= cockroach.damage;
        }
        cout << cockroach.health << " " << robot.health <<  endl;
        //Input pertama
        string command;
        bool valid = false;
        //Gerak = M or m, tembak = S or s
        do{
            float distance = sqrt(pow((cockroach.x - robot.x), 2) + pow((cockroach.y - robot.y), 2));
            if(distance <= range){
                cout << "Kecoak dalam jarak tembak \n";
            }
            cout << "Silahkan masukkan komando: ";
            cin >> command;
            if(command == "M" || command == "m"){
                move();
                valid = true;
            } 
            else if(command == "S" || command == "s"){
                shoot(range, distance);
                cout << cockroach.health << endl;
                if(cockroach.health == 0){
                    count ++;
                }
                valid = true;
            }
            else if (command == "END"){
                finish = true;
                valid = true;
            }
            else{
                cout << "Perintah tidak terdefinisi \n";
            }
        }
        while(!valid);

        if(finish){
            break;
        }
    }
    cout << "Jumlah kecoak dibunuh: " << count << endl;
}