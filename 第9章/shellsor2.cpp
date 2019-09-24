#include <iostream.h>                  //ϣ������
const int N=8;
void output(int table[]);              //��������N��Ԫ��,��
void swap(int table[],int i,int j)     //����table[i]��table[j]��ֵ
{                        
    int temp = table[i];
    table[i] = table[j];
    table[j] = temp;
}
void shellsort(int table[])            //��table����Ԫ�ؽ���ϣ������
{
    int jump = N / 2;
    while (jump>0)                     //����������һ������
    {
        cout<<"jump="<<jump<<"  ";
        for (int i=jump;i<N;i++)       //һ�ֱȽϡ�����
        {
            cout<<"i="<<i<<" ";
            int j = i-jump;
            while (j>=0)
            {
                cout<<table[j]<<"<"<<table[j+jump]<<"? ";
                if (table[j]>table[j+jump]) 
                {                      //�����jump��Ԫ�رȽϡ�����
                    swap(table,j,j+jump); //����ʱ������
                    cout<<"swap ";
                    j = j - jump;      //������ǰ���Ԫ�رȽ�
                } 
                else  j = -1;          //�˳�ѭ��
            }
        }
        output(table);
        jump /= 2;                     //��������
    }
}
void main()
{
    int a[N]={8,3,2,7,9,1,6,5};
    cout<<"N="<<N;
    output(a);
    shellsort(a);
}
/*�������н�� ��
N=8 table:  8 3 2 7 9 1 6 5 
jump=4  i=4 8<9? i=5 3<1? swap i=6 2<6? i=7 7<5? swap  table:  8 1 2 5 9 3 6 7 
jump=2  i=2 8<2? swap i=3 1<5? i=4 8<9? i=5 5<3? swap 1<3? i=6 9<6? swap 8<6? swap 2<6? i=7 5<7?  table:  2 1 6 3 8 5 9 7 
jump=1  i=1 2<1? swap i=2 2<6? i=3 6<3? swap 2<3? i=4 6<8? i=5 8<5? swap 6<5? swap 3<5? i=6 8<9? i=7 9<7? swap 8<7? swap 6<7?  table:  1 2 3 5 6 7 8 9 
*/
void output(int table[])               //��������N��Ԫ��
{
    cout<<" table:  ";
    for (int i=0;i<N;i++)
        cout<<table[i]<<" ";
    cout<<"\n";
}