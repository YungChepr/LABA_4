#define _CRT_SECURE_NO_WARNINGS
#include "AncetaStud.h"


AncetaStud::AncetaStud() //Конструктор без параметров
{
    fio = "";
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = typchik::DVO;
    uch.dvo = *(new dvoechnik);
    strcpy(uch.dvo.adres, "");
    strcpy(uch.dvo.telephone, "");
    //setkolstud(getkolstud() + 1);

    //this->nomerGrup=0;
};

AncetaStud::AncetaStud(typchik t) //Конструктор с одним параметром
{
    fio = "";
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = t;
    uch.dvo = *(new dvoechnik);
    strcpy(uch.dvo.adres, "");
    strcpy(uch.dvo.telephone, "");
    //kolstud = kolstud + 1;

};

AncetaStud::AncetaStud(string f, int nomerG, int nomerS, int r, typchik t) //Конструктор со всеми параметрами
{
    fio = f;
    nomerGrup = nomerG;
    nomerStud = nomerS;
    reiting = r;
    type = t;
    uch.dvo = *(new dvoechnik);
    strcpy(uch.dvo.adres, "");
    strcpy(uch.dvo.telephone, "");
    //kolstud = kolstud + 1;

};

AncetaStud::~AncetaStud() //Деструктор 
{
  /*if (type == OTL) //Проверка какой тип объекта был создан и удаление старого объекта
    {
        delete &AncetaStud::uch.otl;
    }
    if (type == HOR)
    {
        delete &AncetaStud::uch.hor;
    }
    if (type == TRO)
    {
        delete &AncetaStud::uch.tro;
    }
    if (type == DVO)
    {
        delete &AncetaStud::uch.dvo;
    }*/ 
 }

void AncetaStud::setfio(string fio) //Установка значений переменной fio
{
    //strcpy(this->fio, fio);
    this->fio = fio;
};

/*char* AncetaStud::getfio() //Получение значений переменной fio 1
{
    return fio;
}; */

string AncetaStud::getfio() //Получение значений переменной fio 2
//Обязательным условием является выделение области памяти под этот указатель
{
    //strcpy(fio, this->fio);
    return this->fio;
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

void AncetaStud::inputuch() //Установка значений переменной uch
{
   /* if (type == OTL) //Проверка какой тип объекта был создан и удаление старого объекта
    {
        delete &(uch.otl);
    }
    if (type == HOR)
    {
        delete &(uch.hor);
    }
    if (type == TRO)
    {
        delete &(uch.tro);
    }
    if (type == DVO)
    {
        delete &(uch.dvo);
    } */

    if (reiting >= 75) //Создание нового объекта
    {
        type = typchik::OTL;
        //uch.otl = *(new otlichnik);

        strcpy(this->uch.otl.dopstependia, "Студент получает степендию ");
        printf("Введите размер Дополнительной степендии\n");
        scanf("%d", &this->uch.otl.razmer);
    }
    else
    {
        if (reiting >= 50)
        {
            type = typchik::HOR;
            //uch.hor = *(new horoshist);

            strcpy(this->uch.hor.stependia, "Студент  получает степендию ");
            printf("Введите размер обычной степендии\n");
            scanf("%d", &this->uch.hor.razmer);
        }
        else
        {
            if (reiting >= 25)
            {
                type = typchik::TRO;
                //uch.tro = *(new troechnik);

                strcpy(this->uch.tro.stependia, "Студент НЕ получает степендию");
            }
            else
            {
                type = typchik::DVO;
                //uch.dvo = *(new dvoechnik);

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
void AncetaStud::setuch1(int razmer, char dopstependia[N]) //Установка значений переменной kolstud
{
    strcpy(this->uch.otl.dopstependia,dopstependia);
    this->uch.otl.razmer = razmer;
};

int AncetaStud::getuch1(char dopstependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(dopstependia, this->uch.otl.dopstependia);
    return uch.otl.razmer;
};

void AncetaStud::setuch2(int razmer, char stependia[N]) //Установка значений переменной kolstud
{
    strcpy(this->uch.hor.stependia, stependia);
    this->uch.hor.razmer = razmer;
};

int AncetaStud::getuch2(char stependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(stependia, this->uch.hor.stependia);
    return uch.hor.razmer;
};

void AncetaStud::setuch3(char stependia[N]) //Установка значений переменной kolstud
{
    strcpy(this->uch.tro.stependia, stependia);
};

void AncetaStud::getuch3(char stependia[N]) //Получение значений переменной uch
//Обязательным условием является выделение области памяти под этот указатель
{
    strcpy(stependia, this->uch.tro.stependia);

};

void AncetaStud::setuch4(char adres[N], char telephone[N]) //Установка значений переменной kolstud
{
    strcpy(this->uch.dvo.adres, adres);
    strcpy(this->uch.dvo.telephone, telephone);
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
    string fio;
    std::cin >> fio;
    //gets_s(fio);
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

    inputuch();
    setkolstud(getkolstud() + 1); //Увеличиваем счетчик студентов на 1
    printf("\n");
    while (getchar() != '\n');
}

void AncetaStud::outputstud() //Блок - вывод данных о студентах
{
    string fio;
    fio = getfio();
    std::cout << fio ;
    //printf(" %s ", fio);

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

void AncetaStud::deletestud(AncetaStud* spisokstud[N])//Блок - удаления данных о студенте
{
    int f1 = 0;
    int i;

    string fio;
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;

    int nomer = -1,
        nomerstudaka;
    string imya;

    char dopstependia[N];
    int razmer;
    char stependia[N];
    char adres[N];
    char telephone[N];
    while (getchar() != '\n');
    printf("Введите имя студента которого хотите удалить\n");
    std::cin >> imya;
    //gets_s(imya);

    for (i = 0; i < AncetaStud::getkolstud(); i++)  //блок проверки запросов
    {
        if (spisokstud[i] != NULL)
        {
            fio = (*spisokstud[i]).getfio();
            if (imya == fio)
            {
                
                nomerStud = (*spisokstud[i]).getnomerStud();
                std::cout << fio ;
                //printf(" %s ", fio);
                printf(" %d ", nomerStud);
                f1 = f1 + 1;
                nomer = i;
                printf("\n");
            }
        }
    }

    if (f1 == 0)
    {
        printf("\n По вашему запросу ничего не найдено\n ");
        nomer = -1;
    }

    if (f1 > 1)
    {
        f1 = 0;
        printf("По вашему запросу нашлось больше одного студента\n");
        printf("Введите номер студенческого студента которого хотите удалить\n");
        do {
            printf(" Номер студенческого(Введите в формате 7 цифр '2111851')\n");
            while (scanf("%d", &nomerstudaka) != 1) //Проверка ввода если пользователь введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число как показано в примере: ");
            }
        } while (nomerstudaka < 1000000 || nomerstudaka >9999999);
        for (i = 0; i < AncetaStud::getkolstud(); i++)  //блок проверки запросов
        {
            if (spisokstud[i] != NULL)
            {
                if (nomerstudaka == (*spisokstud[i]).getnomerStud())
                {
                    printf(" Вы удаляете такого студента: ");
                    fio = (*spisokstud[i]).getfio();
                    std::cout << fio;
                    //printf(" %s ", fio);
                    nomerStud = (*spisokstud[i]).getnomerStud();
                    printf(" %d ", nomerStud);
                    nomer = i;
                    f1 = 1;
                    i = AncetaStud::getkolstud();
                    printf("\n");
                }
            }
        }
    }
    if (f1 == 1) 
    {
        //Перезапись студентов на один номер меньше
        //Установка в i объект значений i+1 объекта
        for (i = nomer; i < (AncetaStud::getkolstud()-1); i++)  //Сохранение значений следующего объекта
        {
            fio = (*spisokstud[i + 1]).getfio();
            (*spisokstud[i]).setfio(fio);

            (*spisokstud[i]).setnomerGrup((*spisokstud[i + 1]).getnomerGrup());

            (*spisokstud[i]).setnomerStud((*spisokstud[i + 1]).getnomerStud());

            (*spisokstud[i]).setreiting((*spisokstud[i + 1]).getreiting());

            (*spisokstud[i]).settype((*spisokstud[i + 1]).gettype());

            type = (*spisokstud[i + 1]).gettype();
            if (type == OTL)
            {
                razmer = (*spisokstud[i + 1]).getuch1(dopstependia);
                (*spisokstud[i]).setuch1(razmer, dopstependia);
            }
            if (type == HOR)
            {
                razmer = (*spisokstud[i + 1]).getuch2(stependia);
                (*spisokstud[i]).setuch2(razmer, stependia);
            }
            if (type == TRO)
            {
                (*spisokstud[i + 1]).getuch3(stependia);
                (*spisokstud[i]).setuch3(stependia);

            }
            if (type == DVO)
            {
                (*spisokstud[i + 1]).getuch4(adres, telephone);
                (*spisokstud[i]).setuch4(adres, telephone);
            }
            
        }
        // Инициализирую последний объект
        (*spisokstud[AncetaStud::getkolstud()-1]).AncetaStud::~AncetaStud();
        (*spisokstud[AncetaStud::getkolstud()-1]).AncetaStud::AncetaStud();
        setkolstud(getkolstud() - 1); //Уменьшаем счетчик студентов на 1
    }
    else
    {
        printf("\n По вашему новому запросу ничего не найдено\n ");
        nomer = -1;
    }
    
}


int searchbynamestud(AncetaStud* spisokstud[N], string  c) //Блок - поиск по имени среди студентов
{   // функция возращает количество найденных совпадений
    int f1 = 0;
    int i;

    string fio;
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;

    for (i = 0; i < AncetaStud::kolstud; i++)  //блок проверки запросов
    {
        if (spisokstud[i] != NULL)
        {
            fio = (*spisokstud[i]).getfio();
            if (c == fio)
            {
                nomerGrup = (*spisokstud[i]).getnomerGrup();
                nomerStud = (*spisokstud[i]).getnomerStud();
                reiting = (*spisokstud[i]).getreiting();
                type = (*spisokstud[i]).gettype();
                std::cout << fio;
                //printf(" %s ", fio);
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
    string fio;
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;
    for (i = 0; i < AncetaStud::kolstud; i++)  //блок проверки запросов
    {
        if (spisokstud[i] != NULL)
        {
            reiting = (*spisokstud[i]).getreiting();
            if (d == reiting)
            {
                fio = (*spisokstud[i]).getfio();
                nomerGrup = (*spisokstud[i]).getnomerGrup();
                nomerStud = (*spisokstud[i]).getnomerStud();
                type = (*spisokstud[i]).gettype();
                std::cout << fio;
                //printf(" %s ", fio);
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

AncetaStud operator++(AncetaStud& x, int unused) //Этот оператор прибавляет один объект
{
    printf(" ФИО: ");
    string fio;
    std::cin >> fio;
    //gets_s(fio);
    x.setfio(fio);

    int nomerGrup;
    do {
        printf(" Номер группы:(Введите в формате 5 цифр '22091')\n");
        while (scanf("%d", &nomerGrup) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
    } while (nomerGrup < 10000 || nomerGrup >99999);
    x.setnomerGrup(nomerGrup);

    int nomerStud;
    do {
        printf(" Номер студенческого(Введите в формате 7 цифр '2111851')\n");
        while (scanf("%d", &nomerStud) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while (nomerStud < 1000000 || nomerStud >9999999);
    x.setnomerStud(nomerStud);

    int reiting;
    do {
        printf(" Рейтинг студента:(от 0 до 100) ");
        while (scanf("%d", &reiting) != 1) //Проверка ввода если пользователь  введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while ((reiting < 0) || (reiting > 100));
    x.setreiting(reiting);

    x.inputuch();
    x.setkolstud(x.getkolstud() + 1); //Увеличиваем счетчик студентов на 1
    printf("\n");
    while (getchar() != '\n');
    return x;
}

AncetaStud operator+(AncetaStud& x) //Этот оператор прибавляет несколько объектов
{
    printf("Ввод данных о студентах(оператор)\n");
    int n,i;
    do {
        printf("\n Введите количество студентов n (n<%d): ", N);
        while (scanf("%d", &n) != 1) //Проверка ввода если пользователь введет введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
        while (getchar() != '\n');
    } while (n < 1 || n > N);

    for (i = 0; i < n; i++)
    {
        if (AncetaStud::getkolstud() < N) {
            printf("Студент %d \n", (AncetaStud::getkolstud() + 1));
            spisokstud[AncetaStud::getkolstud()]++;
        }
        else
        {
            printf("Количество студентов не может быть больше %d\n", N);
            i = n;
        }
    }
    return x;
}

AncetaStud operator++(AncetaStud& x) //Этот оператор прибавляет один объект
{
    AncetaStud* spisokstud1[N]; //Указатель на массив в котором будут хранится указатели на объекты студентов
    int i;
    for (i = 0; i < N; i++)
    {
        spisokstud1[i] = &(spisokstud[i]);
    }

   x.deletestud(spisokstud1);

   return x;
}
AncetaStud* spisokstud = NULL;