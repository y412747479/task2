#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)
struct Student
{
    long num;
    float score;
    struct Student *next;
};
int n;
struct Student *creat(void)//建立单向链表
{
    printf("请输入学号与成绩中间以逗号隔开以0,0结束输入：\n");
    struct Student *head;
    struct Student *p1,*p2;
    n=0;
    p1=p2=(struct Student *)malloc(LEN);
    scanf ("%ld,%f",&p1->num,&p1->score);
    head = NULL;//能用 head。next= NULL???
    while (p1->num!=0)
    {
        n=n+1;
        if(n==1)
        {
            head=p1;//链表的头
        }
        else
        {
            p2->next=p1; //第二次循环时，此时的p2与head是指向同一节点，也就是说head和p2等价。下一次循环时p2又与最新的节点是等价的。
        };
        p2=p1;//使每次循环后p2与最新的节点等价
        p1=(struct Student *)malloc(LEN);//新建节点
        scanf ("%ld,%f",&p1->num,&p1->score);//记录新建节点数据
    }
    p2->next=NULL;//最后一个节点指向空指针
    return (head);//返回节点的头
}
struct Student *insertlianbiao(struct Student *L,int i,long n1,float s1)//节点的插入
{
    struct Student *pre;//pre为前驱结点
    pre = L;
    int tempi;
    for (tempi = 1; tempi < i-1; tempi++)
        pre = pre->next;                 //查找第i个位置的前驱结点
    struct Student *p;                                //插入的结点为p
    p = (struct Student *)malloc(sizeof(struct Student));
    p->num = n1;
    p->score = s1;
    p->next = pre->next;
    pre->next = p;//此处用p->next 行不？？
    return (L);
}
struct Student *delete1(struct Student *L,float x)//单链表的删除，在链表中删除值为x的元素
{
    struct Student *p,*pre;                   //pre为前驱结点，p为查找的结点。
    p = L;            //p=L->next           //什么意思？？p=L可以不？？第一个没有检查
    while(p->score != x)              //查找值为x的元素
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //删除操作，将其前驱next指向其后继。
    free(p);
    return L;
}
struct Student *delete2(struct Student *L,int i)//选择任意位置删除节点
{
    struct Student *pre,*P;//为什么*p 与p中的p会不一样？？？
    P = L;
    int tempi;
    for (tempi = 1; tempi < i; tempi++)
        {
            pre = P;
            P = P->next;
        }
    pre->next = P->next;
    free (P);
    return L;
}
struct Student *findlianbiao(struct Student *L,float x)//链表的查找，是否有x
{
    int count=1;
    struct Student *p;                   //pre为前驱结点，p为查找的结点。
    p = L;            //p=L->next           //什么意思？？p=L可以不？？第一个没有检查
    while(p->score != x)              //查找值为x的元素
    {
        count++;
        p = p->next;
    }
    printf("查找成功，该数第一次出现是在链表中第%d位置处。\n",count);
}
struct Student printflianbiao(struct Student *ptf)//节点的输出
{
    do
    {
        printf ("%2ld %5.1f\n",ptf->num,ptf->score);
        ptf=ptf->next;
    }while (ptf!=NULL);
}
int main()
{
    int i,a,b,c,d,e;
    struct Student *pt;
    pt=creat();//节点的建立
    printf("最初的链表\n");
    printflianbiao(pt);
    printf("请输入你希望在第几行插入数据：\n");
    scanf("%d",&i);
    printf("请输入你插入学生的学号与成绩以逗号隔开：\n");
    scanf("%d,%d",&a,&b);
    insertlianbiao(pt,i,a,b);//节点的插入
    printf("插入后的链表\n");
    printflianbiao(pt);
    printf("请输入你要删除第几个学生数据：\n");
    scanf("%d",&c);
    delete2(pt,c);//节点的删除
    printf("删除第%d行节点后：\n",c);
    printflianbiao(pt);
    printf("请输入你要查找的学生成绩：\n");
    scanf("%d",&d);
    findlianbiao(pt,d);//链表的查找，是否有x
    printf("请输入你要删除的学生的成绩：\n");
    scanf("%d",&e);
    delete1(pt,e);//单链表的删除，在链表中删除值为x的元素
    printf("删除含score=%d的节点\n",e);
    printflianbiao(pt);
    return 0;
}
