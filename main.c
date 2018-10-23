#include <conio.h>
#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char maSV[6];
    char hoVaTen[30];
    char soDienThoai[15];
}sinhVien;

sinhVien SV[10];

int dem=0;
void removeStdchar(char *array)
{
    if (!strchr(array, '\n'))
    {
        while (getc(stdin) != '\n');
    }
}
void menu();

void Insert()
{
    char n;
    sinhVien sv2;
    printf(" -------------------New Member--------------\n\n ");
    if(dem>9)
    {
        printf("Full");
        menu();
    }
    else
    {
        printf("ID student :");
        scanf("%s",&sv2.maSV);
        while(strlen(sv2.maSV) !=5)
        {   removeStdchar(sv2.maSV);
            printf("Nhap loi!");
            scanf("%s",&sv2.maSV);
        }
        removeStdchar(sv2.hoVaTen);
        printf("Ho va ten :");
        gets(sv2.hoVaTen);
        printf("So dien thoai:");
        scanf("%s",&sv2.soDienThoai);
        SV[dem]=sv2;
        dem++;
    }
    printf("Nhap 1 neu muon them sinh vien: \n");
    n = getch();
    switch(n)
    {
        case '1':
        {
            Insert();
            break;
        }
        default:
        {
            menu();
            break;
        }
    };

}
void ShowList(){

    printf("- Ma sinh vien |      Ten         | So dien thoai  \n");
    for(int i = 0; i < dem; i++)
    {
        printf("- %5s        | %-16s | %s\n", SV[i].maSV, SV[i].hoVaTen,
               SV[i].soDienThoai);
    }
    getch();
    menu();
}
void SaveFile()
{
    printf("Da luu danh sach hoc sinh vao file.\n");
    FILE *file;
    file = fopen("../danhsachsinhvien.txt","a+");
    fprintf(file,"- Ma sinh vien |        Ten      | So dien thoai  \n");
    for(int i = 0; i < dem; i++)
    {
        fprintf(file,"- %5s          | %-16s | %s\n",SV[i].maSV,SV[i].hoVaTen,SV[i].soDienThoai);
    }
    fclose(file);
    getch();
    menu();
}
void menu()
{
    char n;
    do
    {
        printf("\t\t\t |=====================Menu===================|\n");
        printf("\t\t\t |1. Them moi sinh vien                       |\n");
        printf("\t\t\t |2. Hien  thi danh sach sinh vien            |\n");
        printf("\t\t\t |3. Luu danh sach sinh vien ra file          |\n");
        printf("\t\t\t |4. Doc danh sach sinh vien tu file          |\n");
        printf("\t\t\t |5. Thoat chuong trinh                       |\n");
        printf("\t\t\t |============================================|\n");
        printf("\nChon chuc nang (1| 2| 3 |4 |5):\n");
        n = getch();
    }
    while(n > '5' || n < '1');
    switch(n)
    {
        case '1':
            Insert();
            break;
        case '2':

            ShowList();
            break;
        case '3':

            SaveFile();
            break;
        case '4':

//            ReadFile();
            break;
        case '5':
            exit(5);
            break;
    }
}
int main()
{
    menu();
    getch();

}
