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
struct Student *creat(void)//������������
{
    printf("������ѧ����ɼ��м��Զ��Ÿ�����0,0�������룺\n");
    struct Student *head;
    struct Student *p1,*p2;
    n=0;
    p1=p2=(struct Student *)malloc(LEN);
    scanf ("%ld,%f",&p1->num,&p1->score);
    head = NULL;//���� head��next= NULL???
    while (p1->num!=0)
    {
        n=n+1;
        if(n==1)
        {
            head=p1;//�����ͷ
        }
        else
        {
            p2->next=p1; //�ڶ���ѭ��ʱ����ʱ��p2��head��ָ��ͬһ�ڵ㣬Ҳ����˵head��p2�ȼۡ���һ��ѭ��ʱp2�������µĽڵ��ǵȼ۵ġ�
        };
        p2=p1;//ʹÿ��ѭ����p2�����µĽڵ�ȼ�
        p1=(struct Student *)malloc(LEN);//�½��ڵ�
        scanf ("%ld,%f",&p1->num,&p1->score);//��¼�½��ڵ�����
    }
    p2->next=NULL;//���һ���ڵ�ָ���ָ��
    return (head);//���ؽڵ��ͷ
}
struct Student *insertlianbiao(struct Student *L,int i,long n1,float s1)//�ڵ�Ĳ���
{
    struct Student *pre;//preΪǰ�����
    pre = L;
    int tempi;
    for (tempi = 1; tempi < i-1; tempi++)
        pre = pre->next;                 //���ҵ�i��λ�õ�ǰ�����
    struct Student *p;                                //����Ľ��Ϊp
    p = (struct Student *)malloc(sizeof(struct Student));
    p->num = n1;
    p->score = s1;
    p->next = pre->next;
    pre->next = p;//�˴���p->next �в�����
    return (L);
}
struct Student *delete1(struct Student *L,float x)//�������ɾ������������ɾ��ֵΪx��Ԫ��
{
    struct Student *p,*pre;                   //preΪǰ����㣬pΪ���ҵĽ�㡣
    p = L;            //p=L->next           //ʲô��˼����p=L���Բ�������һ��û�м��
    while(p->score != x)              //����ֵΪx��Ԫ��
    {
        pre = p;
        p = p->next;
    }
    pre->next = p->next;          //ɾ������������ǰ��nextָ�����̡�
    free(p);
    return L;
}
struct Student *delete2(struct Student *L,int i)//ѡ������λ��ɾ���ڵ�
{
    struct Student *pre,*P;//Ϊʲô*p ��p�е�p�᲻һ��������
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
struct Student *findlianbiao(struct Student *L,float x)//����Ĳ��ң��Ƿ���x
{
    int count=1;
    struct Student *p;                   //preΪǰ����㣬pΪ���ҵĽ�㡣
    p = L;            //p=L->next           //ʲô��˼����p=L���Բ�������һ��û�м��
    while(p->score != x)              //����ֵΪx��Ԫ��
    {
        count++;
        p = p->next;
    }
    printf("���ҳɹ���������һ�γ������������е�%dλ�ô���\n",count);
}
struct Student printflianbiao(struct Student *ptf)//�ڵ�����
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
    pt=creat();//�ڵ�Ľ���
    printf("���������\n");
    printflianbiao(pt);
    printf("��������ϣ���ڵڼ��в������ݣ�\n");
    scanf("%d",&i);
    printf("�����������ѧ����ѧ����ɼ��Զ��Ÿ�����\n");
    scanf("%d,%d",&a,&b);
    insertlianbiao(pt,i,a,b);//�ڵ�Ĳ���
    printf("����������\n");
    printflianbiao(pt);
    printf("��������Ҫɾ���ڼ���ѧ�����ݣ�\n");
    scanf("%d",&c);
    delete2(pt,c);//�ڵ��ɾ��
    printf("ɾ����%d�нڵ��\n",c);
    printflianbiao(pt);
    printf("��������Ҫ���ҵ�ѧ���ɼ���\n");
    scanf("%d",&d);
    findlianbiao(pt,d);//����Ĳ��ң��Ƿ���x
    printf("��������Ҫɾ����ѧ���ĳɼ���\n");
    scanf("%d",&e);
    delete1(pt,e);//�������ɾ������������ɾ��ֵΪx��Ԫ��
    printf("ɾ����score=%d�Ľڵ�\n",e);
    printflianbiao(pt);
    return 0;
}
