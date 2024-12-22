#include"listNode2.c"

void test01()
{
    //初始化链表
    struct ListNode *header = init_ListNode();

    //遍历链表
    printf("遍历链表为： \n");
    foreach_ListNode(header);

    //测试插入数据
    insert_ListNode(header, 20, 100);
    insert_ListNode(header, 21, 1000);

    printf("插入数据后遍历链表为： \n");
    foreach_ListNode(header);

    //测试删除
    delete_ListNode(header, 100);
    delete_ListNode(header, 201);
    printf("删除数据后遍历链表为： \n");
    foreach_ListNode(header);

    //清空链表
    clear_ListNode(header);
    printf("清空链表后遍历链表为： \n");
    insert_ListNode(header, 111, 111);
    insert_ListNode(header, 222, 222);
    insert_ListNode(header, 333, 333);
    foreach_ListNode(header);

    //销毁链表
    destroy_ListNode(header);
    printf("销毁链表后遍历链表为： \n");
}


void test02()
{
    //初始化链表
    struct ListNode *header = init_ListNode();

    //遍历链表
    printf("反转前遍历链表为： \n");
    foreach_ListNode(header);

    //反转链表
    reverse_ListNode(header);
    printf("反转后遍历链表为： \n");
    foreach_ListNode(header);

    int count = count_ListNode(header);
    printf("链表个数为： %d\n", count);
}
int main()
{
   //test01();
   test02();
   return 0;
}