#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <ctime>
#include <list>
using namespace std;
#define SALE_DEPARTMENT 1     // 销售部门
#define DEVELOP_DEPARTMENT 2  // 开发部门
#define FINANCIAL_DEPARTMENT 3 // 财务部门
class Worker
{
public:
    string name;
    int age;
    double salary;
};

// 创建员工
void CreateWorker(vector<Worker> &v_workers)
{
    srand((unsigned int)time(NULL));
    string SetName = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i < 5; i++)
    {
        Worker worker;
        worker.name = "员工";
        worker.name += SetName[i];
        worker.age = rand() % 30 + 10;
        worker.salary = rand() % 10000 + 20000;
        v_workers.push_back(worker);
    }
}

// 分组，把分好组的员工放到m_workers中
void WorkerByGroup(vector<Worker> &v_workers, multimap<int, Worker> &m_workers)
{
    for(vector<Worker>::iterator it = v_workers.begin(); it!= v_workers.end(); it++)
    {
        int id=rand()%3+1;
        //员工保存到m_workers中
        m_workers.insert(pair<int, Worker>(id, *it));
    }
    // 按部门分组
    // for(multimap<int, Worker>::iterator it = m_workers.begin(); it!= m_workers.end(); it++)
    // {
    //     if(it->first==SALE_DEPARTMENT)
    //     {
    //         cout<<"销售部门："<<it->second.name<<" "<<it->second.age<<" "<<it->second.salary<<endl;
    //     }
    //     else if(it->first==DEVELOP_DEPARTMENT)
    //     {
    //         cout<<"开发部门："<<it->second.name<<" "<<it->second.age<<" "<<it->second.salary<<endl;
    //     }
    //     else if(it->first==FINANCIAL_DEPARTMENT)
    //     {
    //         cout<<"财务部门："<<it->second.name<<" "<<it->second.age<<" "<<it->second.salary<<endl;
    //     }
    // }
}

void MyGroup(multimap<int, Worker> &m_workers, int id)
{
    //查询id部门的员工
    multimap<int, Worker>::iterator it = m_workers.find(id);
    //查询部门人数
    int count = m_workers.count(id);
    //零时变量
    int index = 0;
    // for (; it != m_workers.end() && it->first == id; it++)
    // {
    //     cout<<"员工姓名："<<it->second.name<<" 员工年龄："<<it->second.age<<" 员工薪资："<<it->second.salary<<endl;
    // }
    for (;it != m_workers.end() && index < count; it++,index++)
    {
        cout<<"员工姓名："<<it->second.name<<" 员工年龄："<<it->second.age<<" 员工薪资："<<it->second.salary<<endl;
    }
}

// 打印员工信息
void PrintWorker(multimap<int, Worker> &m_workers)
{
    cout<<"财务部员工信息如下： "<<endl;
    MyGroup(m_workers, FINANCIAL_DEPARTMENT);
    cout<<"研发部员工信息如下： "<<endl;
    MyGroup(m_workers, DEVELOP_DEPARTMENT);
    cout<<"销售部员工信息如下： "<<endl;
    MyGroup(m_workers, SALE_DEPARTMENT);
    
    // for(multimap<int, Worker>::iterator it = m_workers.begin(); it!= m_workers.end(); it++)
    // {
    //     cout<<"员工姓名："<<it->second.name<<" 员工年龄："<<it->second.age<<" 员工薪资："<<it->second.salary<<" 员工部门："<<it->first<<endl;
    // }
}

void test()
{
    // 保存未分组的员工信息
    vector<Worker> v_workers;

    // 保存分组后员工信息
    multimap<int, Worker> m_workers;

    // 创建员工
    CreateWorker(v_workers);

    // 分组，把分好组的员工放到m_workers中
    WorkerByGroup(v_workers, m_workers);

    // 打印员工信息
    PrintWorker(m_workers);
}

int main()
{
    test();
    return 0;
}