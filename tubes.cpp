#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

struct chara{
    int x = 0;
    int y = 0;
    float health, damage
};

chara robot;
chara cockroach;

void move(){
    bool moved = false;
    string direction;
    do{
        // U D L R
        cout << "Masukkan arah gerak:  ";
        cin >> direction;

        if(direction == 85 || direction == 117){
            if((robot.y + 1 != cockroach.y) && (robot.y != 99)){
                robot.y ++;
                moved = true;
            }
            else{
                if(robot.y + 1 == cockroach.y){
                    cout << "Menabrak kecoak";
                }
                else{
                    cout << "Keluar bidang";
                }
            }
        }
        else if(direction == 68 || direction == 100){
            if((robot.y - 1 != cockroach.y) && (robot.y != 0)){
                robot.y --;
                moved = true;
            }
            else{
                if(robot.y - 1 == cockroach.y){
                    cout << "Menabrak kecoak";
                }
                else{
                    cout << "Keluar bidang";
                }
            }
        }
        else if(direction == 76 || direction == 108){
            if((robot.x - 1 != cockroach.x) && (robot.x != 0)){
                robot.x --;
                moved = true;
            }
            else{
                if(robot.x - 1 == cockroach.x){
                    cout << "Menabrak kecoak";
                }
                else{
                    cout << "Keluar bidang";
                }
            }
        }
        else if(direction == 82 || direction == 114){
            if((robot.x + 1 != cockroach.x) && (robot.x != 99)){
                robot.x ++;
                moved = true;
            }
            else{
                if(robot.x + 1 == cockroach.x){
                    cout << "Menabrak kecoak";
                }
                else{
                    cout << "Keluar bidang";
                }
            }
        }
        else{
            cout << "Masukan tidak valid";
        }
    }
}

bool shoot(int range, int distance){
    if(distance <= range){
        cockroach.health -= robot.damage;
        return true;
    }
    else{
        cout << "Out of range" ;
        return false;
    }
}

int main(){
   
    int count = 0;
    // Asumsi health 10, damage = 2
    robot.health = 10;
    robot.damage = 2;

    while(robot.health != 0){
        // Asumsi maksimal papan 100
        while(cockroach.x == 0 && cockroach.y == 0){        
            cockroach.x = rand() % 101;
            cockroach.y = rand() % 101;
        }
        cockroach.damage = 1;
        cockroach.health = rand() % 2 6;
        // Jarak diasumsikan berupa jarak terdekat yang dapat berupa diagonal


        int range = 2;

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
            if(command == 77 || command == 109){
                move();
                valid = true;
            } 
            else if(command == 83 || command == 115){
                shoot(range, distance);
                valid = true;
            }
            else{
                cout << "Perintah tidak terdefinisi";
            }
        while(!valid);
        
    }

}