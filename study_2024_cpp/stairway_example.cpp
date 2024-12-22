#include <iostream>
#include<list>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<ctime>
using namespace std;

class Person
{
    public:
        string name;
};

//打印人员
void printVector(vector<Person> &vec)
{
    for(vector<Person>::iterator it = vec.begin();it!=vec.end();it++)
    {
        cout << it->name << endl;
    }
    cout<<endl;
}

//创建人员
void CreatePerson(queue<Person> &que,int num)
{
    string SetName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int sum = rand() % 10;
    for(int i=0;i<num;i++)
    {
        Person p;
        char buf[64] = {0};
        sprintf(buf, "%d", num);
        string s(buf);
        p.name = "第";
        p.name += s;
        p.name += "层";
        p.name += SetName[i];
        que.push(p);
    }
}

int PopList(list<Person> &personList, int num, vector<Person> &downQueue)
{
    int tmpPop = 0;//临时变量记录出电梯人数
    if(num==17)//到达17层，所有人出电梯
    {
        while(!personList.empty())
        {
            Person p = personList.front();
            //把出电梯的人拷贝到vector
            downQueue.push_back(p);
            personList.pop_front();//移除电梯的人
            tmpPop++;
        }
    }
    int n=rand()%5;
    if(n==0)
    {
        //随机出电梯
        return tmpPop;
    }
    if(personList.size()>=1&&personList.size()>=n)
    {
        //随机出电梯
        for(int i=0;i<n;i++)
        {
            Person p = personList.front();
            //把出电梯的人拷贝到vector
            downQueue.push_back(p);
            personList.pop_front();//移除电梯的人
            tmpPop++;
        }
    }
    return tmpPop;
}

int PushList(list<Person> &personList, queue<Person> &que, vector<Person> &upQueue)
{
    int tmppush = 0;//临时变量记录出电梯人数
    while(!que.empty() && personList.size()<16)
    {
        if(personList.size()>=15)//电梯满员
        {
            break;
        }

        Person p = que.front();

        //拷贝到vector
        upQueue.push_back(p);
        //拷贝到list
        personList.push_back(p);
        //出队
        que.pop();
        tmppush++;
    }
    return tmppush;
}

void test()
{
    srand((unsigned)time(NULL));
    list<Person> personList;
    int Pushnum = 0;//进电梯人数
    int Popnum = 0;//出电梯人数
    vector<Person> upQueue;//进电梯人员
    vector<Person> downQueue;//出电梯人员
    for (int i = 1;i<18;i++)
    {
        //创建人员
        queue<Person> que;
        //创建人员函数
        CreatePerson(que,i);
        //判断是否能进电梯
        if(personList.size()<=15)
        {
            if(i<17)
            {
                Pushnum += PushList(personList, que, upQueue);
            }
        }
        //判断是否能出电梯
        if(personList.size()>=1)
        {
            if(i>1)
            {
                Popnum += PopList(personList, i, downQueue);
            }
        }
    }
    //打印进出电梯人数
    printVector(upQueue);
    cout<<"进电梯人数："<<Pushnum<<endl;
  
    //打印出电梯人数
    printVector(downQueue);
    cout<<"出电梯人数："<<Popnum<<endl;
}
int main()
{
    test();
    return 0;
}