#include<bits/stdc++.h>
using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
const double eps=3e-8;
const int maxn=100005;
//1 3 5 7 8 10 12   上半年单数，下半年双数
//Date结构体！！！
int mon_day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
struct Date{
    int year,month,day;
    Date(int y,int m,int d):year(y),month(m),day(d){}
    Date(){}
    bool isLeap(){
        return (year%400==0)||(year%4==0&&year%100!=0);
    }
    bool vaild(){
        if(year<1960||year>2059)return false;
        if(month<1||month>12)return false;
        if(day<1)return false;
        if(isLeap()){
            if(month==2)return day<=mon_day[month]+1;
            return day<=mon_day[month];
        }
        else  return day<=mon_day[month];
    }
    bool operator <(const Date b)const{
        if(year==b.year){
            if(month==b.month){
                return day<b.day;
            }
            return month<b.month;
        }
        return year<b.year;
    }
    void printDate(){
        printf("%d-%02d-%02d\n",year,month,day);
    }
};
set<Date>que;
void insertDa(int y,int m,int d){
    Date dd(y,m,d);
    if(dd.vaild()){
        que.insert(dd);
    }
}
void solve(){
    int y,m,d;
    scanf("%d/%d/%d",&y,&m,&d);
    int y1=1900;
    int y2=2000;
    //年y月m日d
    insertDa(y+y1,m,d);
    insertDa(y+y2,m,d);
    //月y日m年d
    insertDa(d+y1,y,m);
    insertDa(d+y2,y,m);
    //日y月m年d
    insertDa(d+y1,m,y);
    insertDa(d+y2,m,y);

    for(auto it:que){
        it.printDate();
    }
}
int main(){
    solve();
    return 0;
}
