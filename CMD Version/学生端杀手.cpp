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
    cout<<"请选择功能号："<<endl;
    cout<<"1.解除控制"<<endl;
    cout<<"2.恢复控制软件"<<endl;
    cout<<"3.查看帮助"<<endl;
    cout<<"4.退出"<<endl;
    cout<<"请输入功能号：";
}
int main()
{
    ios::sync_with_stdio(false);
    cout<<"正在读入路径......"<<endl;
    Fin.open("command.cta",ios::in);
    Help.open("Readme.cta",ios::in);
    opened=Help.is_open();
    if (Fin.is_open()==false)
    {
        cout<<"文件损坏！请重新下载！"<<endl;
        goto end;
    }
    getline(Fin,cmd);
    c1="del "+cmd+"SduEdu.exe /q";
    c2="copy SduEdu.exe "+cmd;
    c3="start "+cmd+"SduEdu.exe";
    cout<<"路径读入成功！"<<endl;
    cout<<"正在重新设置窗口颜色"<<endl;
    system("color f0");
    cout<<"设置完成！"<<endl;
    system("cls");
    for ( ; ; )
    {
        system("cls");
        Title();
        cin>>n;
        switch (n)
        {
            case 1:
              cout<<"正在终止进程......"<<endl;
              system("taskkill /f /im SduEdu.exe /t");
              cout<<"进程已终止！"<<endl;
              cout<<"正在删除文件......"<<endl;
              Sleep(114);
              system(c1.c_str());
              cout<<"文件已删除！"<<endl;
              cout<<"2秒后将返回主菜单"<<endl;
              Sleep(2000);
              break;
            case 2:
              cout<<"正在还原......"<<endl;
              system(c2.c_str());
              system(c3.c_str());
              cout<<"还原成功！"<<endl;
              cout<<"2秒后将返回主菜单"<<endl;
              Sleep(2000);
              break;
            case 3:
              system("cls");
              if (opened==false)
                cout<<"你正在遭受盗版软件的侵害！请立即删除本软件！"<<endl;
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
              cout<<"操作数有误！"<<endl;
              cout<<"2秒后将返回主菜单"<<endl;
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
