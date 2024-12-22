#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include<deque>
#include<vector>
#include<algorithm>
#include<ctime>
using namespace std;

class Student
{
    public:
        string name;
        int score;
        Student()
        {
            this->name = "";
            this->score = 0;
        }
        Student(string name, int score)
        {
            this->name = name;
            this->score = score;
        }
};

// 创建学生对象并添加到容器中
void CreatStudent(vector<Student>& students)
{
    string setName="ABCDE";
    for(int i=0;i<5;i++)
    {
        Student stu;
        stu.name="学生";
        stu.name+=setName[i];
        stu.score=0;
        students.push_back(stu);
    }
}
// 评委给学生打分
void Setscore(vector<Student>& students)
{
    srand((unsigned)time(NULL));
    for(vector<Student>::iterator it=students.begin();it!=students.end();it++)
    {
        
        deque<double> score;
        for(int i=0;i<10;i++)
        {
            double s=rand()%70+30;
            score.push_back(s);
            cout<<s<<" ";
        }
        cout<<endl;
        sort(score.begin(),score.end());
        score.pop_front();
        score.pop_back();
        //求总分
        double sum=0;
        for(deque<double>::iterator it=score.begin();it!=score.end();it++)
        {
            sum+=*it;
        }
        //平均分
        double avg=sum/score.size();
        //平均分储存到对象中
        it->score=avg;
    }
}
void PrintShow(vector<int>& score)
{
    for(vector<int>::iterator it=score.begin();it!=score.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
}
bool Compare(Student &a,Student &b)
{
    return a.score>b.score;
}
// 排名并打印
void PrintRank(vector<Student>& students)
{ 
    sort(students.begin(), students.end(), Compare);
    for(vector<Student>::iterator it=students.begin();it!=students.end();it++)
    {
        cout<<"姓名："<<it->name<<" 分数："<<it->score<<endl;
    }
}
void test()
{
    //储存学生的容器
    vector<Student> students;
    //创建学生对象并添加到容器中
    CreatStudent(students); 
    //评委给学生打分
    Setscore(students);
    //排名并打印
    PrintRank(students);
}
int main()
{
    test();
    return 0;
}