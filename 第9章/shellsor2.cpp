#include <iostream.h>                  //希尔排序
const int N=8;
void output(int table[]);              //输出数组的N个元素,略
void swap(int table[],int i,int j)     //交换table[i]、table[j]的值
{                        
    int temp = table[i];
    table[i] = table[j];
    table[j] = temp;
}
void shellsort(int table[])            //对table数组元素进行希尔排序
{
    int jump = N / 2;
    while (jump>0)                     //控制增量，一趟排序
    {
        cout<<"jump="<<jump<<"  ";
        for (int i=jump;i<N;i++)       //一轮比较、交换
        {
            cout<<"i="<<i<<" ";
            int j = i-jump;
            while (j>=0)
            {
                cout<<table[j]<<"<"<<table[j+jump]<<"? ";
                if (table[j]>table[j+jump]) 
                {                      //与相隔jump的元素比较、交换
                    swap(table,j,j+jump); //反序时，交换
                    cout<<"swap ";
                    j = j - jump;      //继续与前面的元素比较
                } 
                else  j = -1;          //退出循环
            }
        }
        output(table);
        jump /= 2;                     //增量减半
    }
}
void main()
{
    int a[N]={8,3,2,7,9,1,6,5};
    cout<<"N="<<N;
    output(a);
    shellsort(a);
}
/*程序运行结果 ：
N=8 table:  8 3 2 7 9 1 6 5 
jump=4  i=4 8<9? i=5 3<1? swap i=6 2<6? i=7 7<5? swap  table:  8 1 2 5 9 3 6 7 
jump=2  i=2 8<2? swap i=3 1<5? i=4 8<9? i=5 5<3? swap 1<3? i=6 9<6? swap 8<6? swap 2<6? i=7 5<7?  table:  2 1 6 3 8 5 9 7 
jump=1  i=1 2<1? swap i=2 2<6? i=3 6<3? swap 2<3? i=4 6<8? i=5 8<5? swap 6<5? swap 3<5? i=6 8<9? i=7 9<7? swap 8<7? swap 6<7?  table:  1 2 3 5 6 7 8 9 
*/
void output(int table[])               //输出数组的N个元素
{
    cout<<" table:  ";
    for (int i=0;i<N;i++)
        cout<<table[i]<<" ";
    cout<<"\n";
}