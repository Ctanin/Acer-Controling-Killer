#ifndef ONLINE_JUDGE
#pragma GCC optimize(3)
#include<windows.h>
#endif
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
typedef unsigned long long int UL;
typedef long long int LL;
typedef unsigned short US;
typedef double DB;
fstream Fin,Help;
UL n;
string cmd,c1,c2,c3,temp;
char quote='"';
bool opened;
void Title(void)
{
    cout<<"��ѡ���ܺţ�"<<endl;
    cout<<"1.�������"<<endl;
    cout<<"2.�ָ��������"<<endl;
    cout<<"3.�鿴����"<<endl;
    cout<<"4.�˳�"<<endl;
    cout<<"�����빦�ܺţ�";
}
int main()
{
    ios::sync_with_stdio(false);
    cout<<"���ڶ���·��......"<<endl;
    Fin.open("command.cta",ios::in);
    Help.open("Readme.cta",ios::in);
    opened=Help.is_open();
    if (Fin.is_open()==false)
    {
        cout<<"�ļ��𻵣����������أ�"<<endl;
        goto end;
    }
    getline(Fin,cmd);
    c1="del "+cmd+"SduEdu.exe /q";
    c2="copy SduEdu.exe "+cmd;
    c3="start "+cmd+"SduEdu.exe";
    cout<<"·������ɹ���"<<endl;
    cout<<"�����������ô�����ɫ"<<endl;
    system("color f0");
    cout<<"������ɣ�"<<endl;
    system("cls");
    for ( ; ; )
    {
        system("cls");
        Title();
        cin>>n;
        switch (n)
        {
            case 1:
              cout<<"������ֹ����......"<<endl;
              system("taskkill /f /im SduEdu.exe /t");
              cout<<"��������ֹ��"<<endl;
              cout<<"����ɾ���ļ�......"<<endl;
              Sleep(114);
              system(c1.c_str());
              cout<<"�ļ���ɾ����"<<endl;
              cout<<"2��󽫷������˵�"<<endl;
              Sleep(2000);
              break;
            case 2:
              cout<<"���ڻ�ԭ......"<<endl;
              system(c2.c_str());
              system(c3.c_str());
              cout<<"��ԭ�ɹ���"<<endl;
              cout<<"2��󽫷������˵�"<<endl;
              Sleep(2000);
              break;
            case 3:
              system("cls");
              if (opened==false)
                cout<<"���������ܵ���������ֺ���������ɾ���������"<<endl;
              else
              {
                  while (Help>>temp)
                  {
                      cout<<temp<<endl;
                  }
              }
              system("pause");
              break;
            case 4:
              goto end;
              break;
            default:
              cout<<"����������"<<endl;
              cout<<"2��󽫷������˵�"<<endl;
              Sleep(2000);
              break;
        }
    }
    end:cout<<"";
    #ifndef ONLINE_JUDGE
    system("pause");
    #endif
    return 0;
}
