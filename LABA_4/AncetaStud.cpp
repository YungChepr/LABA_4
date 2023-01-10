#define _CRT_SECURE_NO_WARNINGS
#include "AncetaStud.h"

AncetaStud::AncetaStud() //����������� ��� ����������
{
    strcpy(fio, "");
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = typchik::DVO;
    uch.dvo = *(new dvoechnik);
    //setkolstud(getkolstud() + 1);

    //this->nomerGrup=0;
};

AncetaStud::AncetaStud(typchik t) //����������� � ����� ����������
{
    strcpy(fio, "");
    nomerGrup = 0;
    nomerStud = 0;
    reiting = 0;
    type = t;
    uch.dvo = *(new dvoechnik);
    //kolstud = kolstud + 1;

};

AncetaStud::AncetaStud(char f[N], int nomerG, int nomerS, int r, typchik t) //����������� �� ����� �����������
{
    strcpy(fio, f);
    nomerGrup = nomerG;
    nomerStud = nomerS;
    reiting = r;
    type = t;
    uch.dvo = *(new dvoechnik);
    //kolstud = kolstud + 1;

};

AncetaStud::~AncetaStud() //���������� ��� ���������� �������� ������������ ���� kolstud
{
    //kolstud = kolstud - 1;
}

void AncetaStud::setfio(char fio[N]) //��������� �������� ���������� fio
{
    strcpy(this->fio, fio);
};

char* AncetaStud::getfio() //��������� �������� ���������� fio 1
{
    return fio;
};

void AncetaStud::getfio(char fio[N]) //��������� �������� ���������� fio 2
//������������ �������� �������� ��������� ������� ������ ��� ���� ���������
{
    strcpy(fio, this->fio);
    //��������� ��� ��������
    //char fio[30] ������ ��������� ����������
};

void AncetaStud::setnomerGrup(int nomerGrup) //��������� �������� ���������� nomerGrup
{
    this->nomerGrup = nomerGrup;
};

int AncetaStud::getnomerGrup() //��������� �������� ���������� nomerGrup
{
    return nomerGrup;
};

void AncetaStud::setnomerStud(int nomerStud) //��������� �������� ���������� nomerStud
{
    this->nomerStud = nomerStud;
};

int AncetaStud::getnomerStud() //��������� �������� ���������� nomerGrup
{
    return nomerStud;
};

void AncetaStud::setreiting(int reiting) //��������� �������� ���������� reiting
{
    this->reiting = reiting;
};

int AncetaStud::getreiting() //��������� �������� ���������� nomerGrup
{
    return reiting;
};

void AncetaStud::settype(typchik type) //��������� �������� ���������� type
{
    this->type = type;
};

typchik AncetaStud::gettype() //��������� �������� ���������� nomerGrup
{
    return type;
};

void AncetaStud::inputuch(AncetaStud uch) //��������� �������� ���������� uch
{
    //strcpy(this->fio, fio);
    if (reiting >= 75)
    {
        type = typchik::OTL;
        strcpy(this->uch.otl.dopstependia, "������� �������� ��������� ");
        printf("������� ������ �������������� ���������\n");
        scanf("%d", &this->uch.otl.razmer);
    }
    else
    {
        if (reiting >= 50)
        {
            type = typchik::HOR;
            strcpy(this->uch.hor.stependia, "�������  �������� ��������� ");
            printf("������� ������ ������� ���������\n");
            scanf("%d", &this->uch.hor.razmer);
        }
        else
        {
            if (reiting >= 25)
            {
                type = typchik::TRO;
                strcpy(this->uch.hor.stependia, "������� �� �������� ���������");
            }
            else
            {
                type = typchik::DVO;
                while (getchar() != '\n');
                printf("������� �������� ����� ��������\n");
                gets_s(this->uch.dvo.adres);
                printf("������� Enter\n");
                while (getchar() != '\n');
                printf("������� ������� ��������\n");
                gets_s(this->uch.dvo.telephone);
                printf("������� Enter\n");
            };
        };
    }
};
void AncetaStud::setuch1(AncetaStud uch, int razmer, char dopstependia[N]) //��������� �������� ���������� kolstud
{
    strcpy(this->uch.otl.dopstependia,dopstependia);
    this->uch.otl.razmer = razmer;
};

int AncetaStud::getuch1(char dopstependia[N]) //��������� �������� ���������� uch
//������������ �������� �������� ��������� ������� ������ ��� ���� ���������
{
    strcpy(dopstependia, this->uch.otl.dopstependia);
    return uch.otl.razmer;
};

void AncetaStud::setuch2(AncetaStud uch, int razmer, char stependia[N]) //��������� �������� ���������� kolstud
{
    strcpy(this->uch.hor.stependia, stependia);
    this->uch.hor.razmer = razmer;
};

int AncetaStud::getuch2(char stependia[N]) //��������� �������� ���������� uch
//������������ �������� �������� ��������� ������� ������ ��� ���� ���������
{
    strcpy(stependia, this->uch.hor.stependia);
    return uch.hor.razmer;
};

void AncetaStud::setuch3(AncetaStud uch, char stependia[N]) //��������� �������� ���������� kolstud
{
    strcpy(this->uch.tro.stependia, stependia);
};

void AncetaStud::getuch3(char stependia[N]) //��������� �������� ���������� uch
//������������ �������� �������� ��������� ������� ������ ��� ���� ���������
{
    strcpy(stependia, this->uch.tro.stependia);

};

void AncetaStud::setuch4(AncetaStud uch, char adres[N], char telephone[N]) //��������� �������� ���������� kolstud
{
    strcpy(this->uch.dvo.adres, adres);
    strcpy(this->uch.dvo.telephone, telephone);
};

void AncetaStud::getuch4(char adres[N], char telephone[N]) //��������� �������� ���������� uch
//������������ �������� �������� ��������� ������� ������ ��� ���� ���������
{
    strcpy(adres, this->uch.dvo.adres);
    strcpy(telephone, this->uch.dvo.telephone);
};

void AncetaStud::setkolstud(int kolst) //��������� �������� ���������� kolstud
{
    kolstud = kolst;
}; 

int AncetaStud::getkolstud() //��������� �������� ���������� kolstud
{
    return kolstud;
}; 

int AncetaStud::kolstud = 0; //������������� ������������ ���� kolstud ���������� ��������� ������ ���� ����� 0

void AncetaStud::inputstud() //���� - ���� ������ � ���������
{   //gets_s(a//��� this ��� �����������//->fio);
    printf(" ���: ");
    char fio[N];
    gets_s(fio);
    setfio(fio);

    int nomerGrup;
    do {
        printf(" ����� ������:(������� � ������� 5 ���� '22091')\n");
        while (scanf("%d", &nomerGrup) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� �� ��� �������� � ������� : ");
        }
    } while (nomerGrup < 10000 || nomerGrup >99999);
    setnomerGrup(nomerGrup);

    int nomerStud;
    do {
        printf(" ����� �������������(������� � ������� 7 ���� '2111851')\n");
        while (scanf("%d", &nomerStud) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while (nomerStud < 1000000 || nomerStud >9999999);
    setnomerStud(nomerStud);

    int reiting;
    do {
        printf(" ������� ��������:(�� 0 �� 100) ");
        while (scanf("%d", &reiting) != 1) //�������� ����� ���� ������������  ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while ((reiting < 0) || (reiting > 100));
    setreiting(reiting);

    AncetaStud uch;
    inputuch(uch);
    setkolstud(getkolstud() + 1); //����������� ������� ��������� �� 1
    printf("\n");
    while (getchar() != '\n');
}

void AncetaStud::outputstud() //���� - ����� ������ � ���������
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

void AncetaStud::deletestud(AncetaStud* spisokstud[N])//���� - �������� ������ � ��������
{
    int f1 = 0;
    int i;

    char fio[N];
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;
    AncetaStud uch;

    int nomer,
        nomerstudaka;
    char imya[N];
    char dopstependia[N];
    int razmer1;
    char stependia[N];
    int razmer2;
    char adres[N];
    char telephone[N];
    while (getchar() != '\n');
    printf("������� ��� �������� �������� ������ �������\n");
    gets_s(imya);

    for (i = 0; i < N; i++)  //���� �������� ��������
    {
        if (spisokstud[i] != NULL)
        {
            (*spisokstud[i]).getfio(fio);
            if (strcmp(imya, fio) == 0)
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
                nomer = i;
                printf("\n");
            }
        }
    }
    if (f1 == 0)
    {
        printf("\n �� ������ ������� ������ �� �������\n ");
    }
    if (f1 == 1)
    {
        //���������� ��������� �� ���� ����� ������
        for (i = nomer; i < AncetaStud::getkolstud(); i++)  //���������� �������� ���������� �������
        {
            (*spisokstud[i + 1]).getfio(fio);
            nomerGrup = (*spisokstud[i + 1]).getnomerGrup();
            nomerStud = (*spisokstud[i + 1]).getnomerStud();
            reiting = (*spisokstud[i + 1]).getreiting();
            type = (*spisokstud[i + 1]).gettype();
            if (type == OTL)
            {


                razmer1 = (*spisokstud[i + 1]).getuch1(dopstependia);
            }
            if (type == HOR)
            {


                razmer2 = (*spisokstud[i + 1]).getuch2(stependia);
            }
            if (type == TRO)
            {


                (*spisokstud[i + 1]).getuch3(stependia);

            }
            if (type == DVO)
            {


                (*spisokstud[i + 1]).getuch4(adres, telephone);
            }
            //��������� � i ������ �������� i+1 �������
            (*spisokstud[i]).setfio(fio);
            (*spisokstud[i]).setnomerGrup(nomerGrup);
            (*spisokstud[i]).setnomerStud(nomerStud);
            (*spisokstud[i]).setreiting(reiting);
            if (reiting >= 75)
            {
                (*spisokstud[i]).settype(OTL);
                (*spisokstud[i]).setuch1(uch,razmer1, dopstependia);
            }
            else
            {
                if (reiting >= 50)
                {
                    (*spisokstud[i]).settype(HOR);
                    (*spisokstud[i]).setuch2(uch, razmer2, stependia);
                }
                else
                {
                    if (reiting >= 25)
                    {
                        (*spisokstud[i]).settype(TRO);
                        (*spisokstud[i]).setuch3(uch, stependia);
                    }
                    else
                    {
                        (*spisokstud[i]).settype(DVO);
                        (*spisokstud[i]).setuch4(uch, adres, telephone);
                    };
                };
            }
        }
        // ������������� ��������� ������
        strcpy(fio, "");
        nomerGrup = 0;
        nomerStud = 0;
        reiting = 0;
        type = typchik::DVO;
        strcpy(adres, "");
        strcpy(telephone, "");
        (*spisokstud[AncetaStud::getkolstud()]).setfio(fio);
        (*spisokstud[AncetaStud::getkolstud()]).setnomerGrup(nomerGrup);
        (*spisokstud[AncetaStud::getkolstud()]).setnomerStud(nomerStud);
        (*spisokstud[AncetaStud::getkolstud()]).setreiting(reiting);
        (*spisokstud[AncetaStud::getkolstud()]).settype(type);
        (*spisokstud[AncetaStud::getkolstud()]).setuch4(uch, adres, telephone);
        setkolstud(getkolstud() - 1); //��������� ������� ��������� �� 1
    }
    if (f1 > 1)
    {
        printf("�� ������ ������� ������� ������ ������ ��������\n");
        printf("������� ����� ������������� �������� �������� ������ �������\n");
        do {
            printf(" ����� �������������(������� � ������� 7 ���� '2111851')\n");
            while (scanf("%d", &nomerstudaka) != 1) //�������� ����� ���� ������������ ������ �� �����
            {
                while (getchar() != '\n');
                printf("������. ������� ����� ��� �������� � �������: ");
            }
        } while (nomerstudaka < 1000000 || nomerstudaka >9999999);
        for (i = 0; i < N; i++)  //���� �������� ��������
        {
            if (spisokstud[i] != NULL)
            {
                if (nomerstudaka == nomerStud)
                {
                    (*spisokstud[i]).getfio(fio);
                    nomerGrup = (*spisokstud[i]).getnomerGrup();
                    nomerStud = (*spisokstud[i]).getnomerStud();
                    type = (*spisokstud[i]).gettype();
                    if (type == OTL)
                    {
                        char dopstependia[N];
                        int razmer1;

                        razmer1 = (*spisokstud[i]).getuch1(dopstependia);
                    }
                    if (type == HOR)
                    {
                        char stependia[N];
                        int razmer2;

                        razmer2 = (*spisokstud[i]).getuch2(stependia);
                    }
                    if (type == TRO)
                    {
                        char stependia[N];

                        (*spisokstud[i]).getuch3(stependia);

                    }
                    if (type == DVO)
                    {
                        char adres[N];
                        char telephone[N];

                        (*spisokstud[i]).getuch4(adres, telephone);
                    }
                    nomer = i;
                }
            }
        }
        //���������� ��������� �� ���� ����� ������
        for (i = nomer; i < AncetaStud::getkolstud(); i++)  //���������� �������� ���������� �������
        {
            (*spisokstud[i+1]).getfio(fio); 
            nomerGrup = (*spisokstud[i+1]).getnomerGrup();
            nomerStud = (*spisokstud[i+1]).getnomerStud();
            type = (*spisokstud[i+1]).gettype();
            if (type == OTL)
            {
                

                razmer1 = (*spisokstud[i+1]).getuch1(dopstependia);
            }
            if (type == HOR)
            {
                

                razmer2 = (*spisokstud[i+1]).getuch2(stependia);
            }
            if (type == TRO)
            {
                

                (*spisokstud[i+1]).getuch3(stependia);

            }
            if (type == DVO)
            {
                

                (*spisokstud[i+1]).getuch4(adres, telephone);
            }
            //��������� � i ������ �������� i+1 �������
            (*spisokstud[i]).setfio(fio); 
            (*spisokstud[i]).setnomerGrup(nomerGrup);
            (*spisokstud[i]).setnomerStud(nomerStud);
            (*spisokstud[i]).setreiting(reiting);
            if (reiting >= 75)
            {
                settype(OTL);
                setuch1(uch, razmer1, dopstependia);
            }
            else
            {
                if (reiting >= 50)
                {
                    settype(HOR);
                    setuch2(uch, razmer2, stependia);
                }
                else
                {
                    if (reiting >= 25)
                    {
                        settype(TRO);
                        setuch3(uch, stependia);
                    }
                    else
                    {
                        settype(DVO);
                        setuch4(uch, adres, telephone);
                    };
                };
            }
        }
        // ������������� ��������� ������
        strcpy(fio, "");
        nomerGrup = 0;
        nomerStud = 0;
        reiting = 0;
        type = typchik::DVO;
        strcpy(adres, "");
        strcpy(telephone, "");
        (*spisokstud[AncetaStud::getkolstud()]).setfio(fio);
        (*spisokstud[AncetaStud::getkolstud()]).setnomerGrup(nomerGrup);
        (*spisokstud[AncetaStud::getkolstud()]).setnomerStud(nomerStud);
        (*spisokstud[AncetaStud::getkolstud()]).setreiting(reiting);
        (*spisokstud[AncetaStud::getkolstud()]).settype(type);
        (*spisokstud[AncetaStud::getkolstud()]).setuch4(uch, adres, telephone);
        setkolstud(getkolstud() - 1); //��������� ������� ��������� �� 1
    }
    
}


int searchbynamestud(AncetaStud* spisokstud[N], char  c[N]) //���� - ����� �� ����� ����� ���������
{   // ������� ��������� ���������� ��������� ����������
    int f1 = 0;
    int i;

    char fio[N];
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;

    for (i = 0; i < N; i++)  //���� �������� ��������
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
        printf("\n �� ������ ������� ������ �� �������\n ");
    }

    return f1;
}

int searchbyreiting(AncetaStud* spisokstud[N], int d) //���� - ����� �� �������� ����� ���������
{   // ������� ��������� ���������� ��������� ����������
    int f2 = 0;
    int i;
    char fio[N];
    int nomerGrup;
    int nomerStud;
    int reiting;
    typchik type;
    for (i = 0; i < N; i++)  //���� �������� ��������
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
        printf("\n �� ������ ������� ������ �� �������\n ");
    }

    return f2;
}
