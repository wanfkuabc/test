#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include<functional>
#include<ctime>
#include<numeric>
using namespace std;

//定义Player类，包含姓名、年龄、每场比赛的得分
class Player
{
    public:
    string name;
    int age;
    double score[3];//最多有三轮比赛
};

// 创建选手信息
void CreatePlayers(map<int, Player> &players, vector<int> &v1)
{
    string setName="ABCDEFGHIJKLMNOPQRSTUVWXYZ";  
    for(int i=0;i<24;i++)
    {
        Player p;
        p.name = "选手";
        p.name += setName[i];
        p.age = rand() % 20 + 18;
        for(int j=0;j<3;j++)
        {
            p.score[j] = 0;
        }
        //生成选手编号
        int ID = 100 + i;
        //保存选手编号
        v1.push_back(ID);
        //保存选手信息
        players.insert(pair<int, Player>(ID, p));
    }
}

// 抽签
void PlayerByRandom(vector<int> &v1)
{
    // 随机生成抽签顺序
    random_shuffle(v1.begin(), v1.end());
}

// 比赛
void StartMatch(int index, vector<int> &v1, map<int, Player> &players, vector<int> &v2)
{
    //定义multimap容器，键值是分数，值是选手编号，multimap会根据键值自动排序
    multimap<double, int,greater<double>> m;
    for(vector<int>::iterator it=v1.begin();it!=v1.end();it++)
    {
        deque<double> dScore;
        for(int i=0;i<10;i++)
        {
            double score = rand() % 100 + 1;
            dScore.push_back(score);
        }
        //排序
        sort(dScore.begin(), dScore.end(), greater<double>());
        //去掉最高分和最低分
        dScore.pop_front();
        dScore.pop_back();

        //求总分
        double totalScore = accumulate(dScore.begin(), dScore.end(), 0.0);
        //求平均分
        double avgScore = totalScore / dScore.size();
        //更新选手信息
        players[*it].score[index-1] = avgScore;
        //把选手放在multimap中
        m.insert(pair<double, int>(avgScore, *it));
        //评比
        if(m.size() ==6)
        {
            //取出前六名
            int count = 0;
            for(multimap<double, int,greater<double>>::iterator it2=m.begin();it2!=m.end()&&count<3;count++,it2++)
            {
                v2.push_back(it2->second);
            }
            // 清空容器
            m.clear();
        }

    }
}

// 显示晋级结果
void showPlayerScore(int index, vector<int> &v, map<int, Player> &players)
{
    cout << "第" << index << "轮比赛晋级选手：" << endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++)
    {
        cout<<"姓名："<<players[*it].name<<" 年龄："<<players[*it].age<<" 得分："<<players[*it].score[index-1]<<endl;
    }
}

void test()
{
    srand((unsigned int)time(NULL));
    vector<int> v1;//保存选手编号
    map<int, Player> players;//保存选手信息
    vector<int> v2;//保存第一轮晋级选手编号
    vector<int> v3; // 保存第二轮晋级选手编号
    vector<int> v4; // 保存第三轮晋级选手编号

    //创建选手信息
    CreatePlayers(players, v1);
    //第一轮比赛
    //抽签
    PlayerByRandom( v1);
    //比赛
    StartMatch(1, v1, players, v2);
    //显示晋级结果
    showPlayerScore(1,v2, players);
    // 第二轮比赛
    // 抽签
    PlayerByRandom(v2);
    // 比赛
    StartMatch(2, v2, players, v3);
    // 显示晋级结果
    showPlayerScore(2, v3, players);
    // 第三轮比赛
    // 抽签
    PlayerByRandom(v3);
    // 比赛
    StartMatch(3, v3, players, v4);
    // 显示晋级结果
    showPlayerScore(3, v4, players);
}

int main()
{
    test();
    return 0;
}