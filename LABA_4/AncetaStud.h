#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <string.h>
#include <locale.h>
//Константа хранит количество элементов массива преподователей
const int N = 30;
class otlichnik    //Структура хранит данные для студента отличника
{
public:
    char dopstependia[N];
    int razmer;
    static int kolstud;
};
class horoshist    //Структура хранит данные для студента хорошиста 
{
public:
    char stependia[N];
    int razmer;
    static int kolstud;
};
class troechnik    //Структура хранит данные для студента троечника 
{
public:
    char stependia[N];
    static int kolstud;
};
class dvoechnik    //Структура хранит данные для студента двоечника
{
public:
    char adres[N];
    char telephone[N];
    static int kolstud;
};
enum typchik
{
    OTL,
    HOR,
    TRO,
    DVO
};
class AncetaStud
{
private:
    char fio[30];  //Переменная хранит имя студнта
    int nomerGrup; //Переменная хранит номер группы студнта
    int nomerStud; //Переменная хранит номер студенческого студнта
    int reiting;   //Переменная хранит рейтинг студнта
    typchik type;      //Переменная хранит метку активного компонента
    union          //Объединение хранит переменные компонент который различается в зависимости от рейтинга студента
    {
        otlichnik otl;
        horoshist hor;
        troechnik tro;
        dvoechnik dvo;
    }uch;
    static int kolstud; //Статическое поле хранит количество студентов
public:
    AncetaStud(); //Конструктор без параметров
    AncetaStud(typchik type); //Конструктор с одним параметром
    AncetaStud(char fio[N], int nomerGrup, int nomerStud, int reiting, typchik type); //Конструктор со всеми параметрами
    ~AncetaStud(); //Деструктор для уменьшения значения статического поля kolstud

    void setfio(char fio[N]); //Установка значений переменной fio
    void setnomerGrup(int nomerGrup); //Установка значений переменной nomerGrup
    void setnomerStud(int nomerStud); //Установка значений переменной nomerStud
    void setreiting(int reiting); //Установка значений переменной reiting
    void settype(typchik type); //Установка значений переменной type
    void setuch(AncetaStud uch); //Установка значений переменной uch */
    static void setkolstud(int kolstud); //Установка значений переменной kolstud

    char* getfio(); //Получение значений переменной fio
    void getfio(char fio[N]); //Получение значений переменной fio
    int getnomerGrup(); //Получение значений переменной nomerGrup
    int getnomerStud(); //Получение значений переменной nomerStud
    int getreiting(); //Получение значений переменной reiting
    typchik gettype(); //Получение значений переменной type
    int getuch1(char dopstependia[N]); //Получение значений переменной uch */
    int getuch2(char stependia[N]); //Получение значений переменной uch */
    void getuch3(char stependia[N]); //Получение значений переменной uch */
    void getuch4(char adres[N], char telephone[N]); //Получение значений переменной uch */
    static int getkolstud(); //Получение значений переменной kolstud

    void inputstud();  //Блок - ввод данных о студентах
    void outputstud(); //Блок - вывод данных о студентах
    void deletestud(AncetaStud* spisokstud[N]); //Блок - удаления данных о студенте

};
int searchbynamestud(AncetaStud* spisokstud[N], char с[N]);
int searchbyreiting(AncetaStud* spisokstud[N], int d);

