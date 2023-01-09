#define _CRT_SECURE_NO_WARNINGS
#include "AncetaStud.h"

AncetaStud::AncetaStud() //Конструктор без параметров
{
    strcpy(fio, "");
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = typchik::DVO;
    uch.dvo = *(new dvoechnik);
    kolstud = kolstud + 1;

    //this->nomerGrup=0;
};

AncetaStud::AncetaStud(typchik t) //Конструктор с одним параметром
{
    strcpy(fio, "");
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = t;
    uch.dvo = *(new dvoechnik);
    kolstud = kolstud + 1;

};

AncetaStud::AncetaStud(char f[N], int nomerG, int nomerS, int r, typchik t) //Конструктор со всеми параметрами
{
    strcpy(fio, f);
    nomerGrup = nomerG;
    nomerStud = nomerS;
    reiting = r;
    type = t;
    uch.dvo = *(new dvoechnik);
    kolstud = kolstud + 1;

};

AncetaStud::~AncetaStud() //Деструктор для уменьшения значения статического поля kolstud
{
    kolstud = kolstud - 1;
}

void AncetaStud::setfio(char fio[N]) //Установка значений переменной fio
{
    strcpy(this->fio, fio);
};

char* AncetaStud::getfio() //Получение значений переменной fio 1
{
    return fio;
};

void AncetaStud::getfio(char fio[N]) //Получение значений переменной fio 2
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(fio, this->fio);
    //непонятно что передали
    //char fio[30] только константу подставить
};

void AncetaStud::setnomerGrup(int nomerGrup) //Установка значений переменной nomerGrup
{
    this->nomerGrup = nomerGrup;
};

int AncetaStud::getnomerGrup() //Получение значений переменной nomerGrup
{
    return nomerGrup;
};

void AncetaStud::setnomerStud(int nomerStud) //Установка значений переменной nomerStud
{
    this->nomerStud = nomerStud;
};

int AncetaStud::getnomerStud() //Получение значений переменной nomerGrup
{
    return nomerStud;
};

void AncetaStud::setreiting(int reiting) //Установка значений переменной reiting
{
    this->reiting = reiting;
};

int AncetaStud::getreiting() //Получение значений переменной nomerGrup
{
    return reiting;
};

void AncetaStud::settype(typchik type) //Установка значений переменной type
{
    this->type = type;
};

typchik AncetaStud::gettype() //Получение значений переменной nomerGrup
{
    return type;
};

void AncetaStud::setuch(AncetaStud uch) //Установка значений переменной uch
{
    //strcpy(this->fio, fio);
    if (reiting >= 75)
    {
        type = typchik::OTL;
        strcpy(this->uch.otl.dopstependia, "Студент получает степендию ");
        printf("Введите размер Дополнительной степендии\n");
        scanf("%d", &this->uch.otl.razmer);
    }
    else
    {
        if (reiting >= 50)
        {
            type = typchik::HOR;
            strcpy(this->uch.hor.stependia, "Студент  получает степендию ");
            printf("Введите размер обычной степендии\n");
            scanf("%d", &this->uch.hor.razmer);
        }
        else
        {
            if (reiting >= 25)
            {
                type = typchik::TRO;
                strcpy(this->uch.hor.stependia, "Студент НЕ получает степендию");
            }
            else
            {
                type = typchik::DVO;
                while (getchar() != '\n');
                printf("Введите домашний адрес студента\n");
                gets_s(this->uch.dvo.adres);
                printf("Нажмите Enter\n");
                while (getchar() != '\n');
                printf("Введите телефон студента\n");
                gets_s(this->uch.dvo.telephone);
                printf("Нажмите Enter\n");
            };
        };
    }
};

int AncetaStud::getuch1(char dopstependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(dopstependia, this->uch.otl.dopstependia);
    return uch.otl.razmer;
};

int AncetaStud::getuch2(char stependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(stependia, this->uch.hor.stependia);
    return uch.hor.razmer;
};

void AncetaStud::getuch3(char stependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(stependia, this->uch.tro.stependia);

};

void AncetaStud::getuch4(char adres[N], char telephone[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(adres, this->uch.dvo.adres);
    strcpy(telephone, this->uch.dvo.telephone);
};

void AncetaStud::setkolstud(int kolst) //Установка значений переменной kolstud
{
    kolstud = kolst;
}; 

int AncetaStud::getkolstud() //Получение значений переменной kolstud
{
    return kolstud;
}; 

int AncetaStud::kolstud = 0; //Инициализация статического поля kolstud количество студентов должно быть равно 0

void AncetaStud::inputstud() //Блок - ввод данных о студентах
{   //gets_s(a//Тут this уже определенен//->fio);
    printf(" ФИО: ");
    char fio[N];
    gets_s(fio);
    setfio(fio);

    int nomerGrup;
    do {
        printf(" Номер группы:(Введите в формате 5 цифр '22091')\n");
        while (scanf("%d", &nomerGrup) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
    } while (nomerGrup < 10000 || nomerGrup >99999);
    setnomerGrup(nomerGrup);

    int nomerStud;
    do {
        printf(" Номер студенческого(Введите в формате 7 цифр '2111851')\n");
        while (scanf("%d", &nomerStud) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while (nomerStud < 1000000 || nomerStud >9999999);
    setnomerStud(nomerStud);

    int reiting;
    do {
        printf(" Рейтинг студента:(от 0 до 100) ");
        while (scanf("%d", &reiting) != 1) //Проверка ввода если пользователь  введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while ((reiting < 0) || (reiting > 100));
    setreiting(reiting);

    AncetaStud uch;
    setuch(uch);
    printf("\n");
    while (getchar() != '\n');
}

void AncetaStud::outputstud() //Блок - вывод данных о студентах
{
    char fio[N];
    getfio(fio);
    printf(" %s ", fio);

    int nomerGrup;
    nomerGrup = getnomerGrup();
    printf(" %d ", nomerGrup);

    int nomerStud;
    nomerStud = getnomerStud();
    printf(" %d ", nomerStud);

    int reiting;
    reiting = getreiting();
    printf(" %d ", reiting);

    typchik type;
    type = gettype();
    if (type == OTL)
    {
        char dopstependia[N];
        int razmer1;

        razmer1 = getuch1(dopstependia);
        printf(" %s ", dopstependia);
        printf(" %d ", razmer1);
    }
    if (type == HOR)
    {
        char stependia1[N];
        int razmer2;

        razmer2 = getuch2(stependia1);
        printf(" %s ", stependia1);
        printf(" %d ", razmer2);
    }
    if (type == TRO)
    {
        char stependia2[N];

        getuch3(stependia2);
        printf(" %s ", stependia2);

    }
    if (type == DVO)
    {
        char adres[N];
        char telephone[N];

        getuch4(adres, telephone);
        printf(" %s ", adres);
        printf(" %s ", telephone);

    }
    printf("\n");
}

int searchbynamestud(AncetaStud* spisokstud[N], char  c[N]) //Блок - поиск по имени среди студентов
{   // функция возращает количество найденных совпадений
    int f1 = 0;
    int i;

    char fio[N];
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;

    for (i = 0; i < N; i++)  //блок проверки запросов
    {
        if (spisokstud[i] != NULL)
        {
            (*spisokstud[i]).getfio(fio);
            if (strcmp(c, fio) == 0)
            {
                nomerGrup = (*spisokstud[i]).getnomerGrup();
                nomerStud = (*spisokstud[i]).getnomerStud();
                reiting = (*spisokstud[i]).getreiting();
                type = (*spisokstud[i]).gettype();
                printf(" %s ", fio);
                printf(" %d ", nomerGrup);
                printf(" %d ", nomerStud);
                printf(" %d ", reiting);
                if (type == OTL)
                {
                    char dopstependia[N];
                    int razmer1;

                    razmer1 = (*spisokstud[i]).getuch1(dopstependia);
                    printf(" %s ", dopstependia);
                    printf(" %d ", razmer1);
                }
                if (type == HOR)
                {
                    char stependia[N];
                    int razmer2;

                    razmer2 = (*spisokstud[i]).getuch2(stependia);
                    printf(" %s ", stependia);
                    printf(" %d ", razmer2);
                }
                if (type == TRO)
                {
                    char stependia[N];

                    (*spisokstud[i]).getuch3(stependia);
                    printf(" %s ", stependia);

                }
                if (type == DVO)
                {
                    char adres[N];
                    char telephone[N];

                    (*spisokstud[i]).getuch4(adres, telephone);
                    printf(" %s ", adres);
                    printf(" %s ", telephone);

                }
                f1 = f1 + 1;
                printf("\n");
            }
        }
    }
    if (f1 == 0)
    {
        printf("\n По вашему запросу ничего не найдено\n ");
    }

    return f1;
}

int searchbyreiting(AncetaStud* spisokstud[N], int d) //Блок - поиск по рейтингу среди студентов
{   // функция возращает количество найденных совпадений
    int f2 = 0;
    int i;
    char fio[N];
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;
    for (i = 0; i < N; i++)  //блок проверки запросов
    {
        if (spisokstud[i] != NULL)
        {
            reiting = (*spisokstud[i]).getreiting();
            if (d == reiting)
            {
                (*spisokstud[i]).getfio(fio);
                nomerGrup = (*spisokstud[i]).getnomerGrup();
                nomerStud = (*spisokstud[i]).getnomerStud();
                type = (*spisokstud[i]).gettype();
                printf(" %s ", fio);
                printf(" %d ", nomerGrup);
                printf(" %d ", nomerStud);
                printf(" %d ", reiting);
                if (type == OTL)
                {
                    char dopstependia[N];
                    int razmer1;

                    razmer1 = (*spisokstud[i]).getuch1(dopstependia);
                    printf(" %s ", dopstependia);
                    printf(" %d ", razmer1);
                }
                if (type == HOR)
                {
                    char stependia[N];
                    int razmer2;

                    razmer2 = (*spisokstud[i]).getuch2(stependia);
                    printf(" %s ", stependia);
                    printf(" %d ", razmer2);
                }
                if (type == TRO)
                {
                    char stependia[N];

                    (*spisokstud[i]).getuch3(stependia);
                    printf(" %s ", stependia);

                }
                if (type == DVO)
                {
                    char adres[N];
                    char telephone[N];

                    (*spisokstud[i]).getuch4(adres, telephone);
                    printf(" %s ", adres);
                    printf(" %s ", telephone);

                }
                f2 = f2 + 1;
            }
        }

    }
    printf("\n");
    if (f2 == 0)
    {
        printf("\n По вашему запросу ничего не найдено\n ");
    }

    return f2;
}
