#include <stdio.h>

int main () {
    int age;
    printf("Masukan umur anda disini: ");
    scanf("%d", &age);
    //jika input tidak sesuai range dibawah atau sama dengan 0
    if(age <= 0){
        printf("Invalid input");
    }
    //jika lebih atau sama dengan 18 tahun
    else if(age >= 18){
        printf("Umur Anda memenuhi  untuk mengikuti pemilu");
    }
    //jika kurang dari 18 tahun
    else if(age < 18){
        printf("Maaf umur anda belum memenuhi untuk mengikuti pemilu");
    }
}
