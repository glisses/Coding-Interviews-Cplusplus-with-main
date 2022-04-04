# commonly used grammar in C++



## string

``` c++
string s;
int len = s.length();
```



## vector

```c++
vector <int> a(10);		//注意是()，不是[]
a.push_back(1);
a.push_back(2);
a.push_back(3);
for (auto i:a) cout<<i<<endl;
cout<<a[0]<<endl;
reverse(a.begin(), a.end());
```

``` c++
//使用vector一次性完成二维数组的定义（注意：此种方法适用于每一行的列数相等的二维数组）
vector<vector<int>> matrix(m, vector<int>(n, -1));

//以下是拆分理解
//创建一维数组matirx，这个数组里有m个元素，元素是int型vector。
vector<vector<int>> matrix(m);
//除了定义数组类型及数组大小外，同时给数组中的元素赋值：将元素赋值为大小为n的int型vector。
vector<vector<int>> matrix(m, vector<int>(n));
//除了定义数组类型、数组大小、列的大小，同时给数组列中的元素（或者说，数组中的所有元素）赋值为-1。
vector<vector<int>> matrix(m, vector<int>(n, -1));
```



## STL

|          |      |      |      |      |      |
| -------- | ---- | ---- | ---- | ---- | ---- |
| vector   |      |      |      |      |      |
| queue    |      |      |      |      |      |
| stack    |      |      |      |      |      |
| list     |      |      |      |      |      |
| set      |      |      |      |      |      |
| multiset |      |      |      |      |      |
| map      |      |      |      |      |      |

常用的通用方法：sort，reverse倒序，rotate部分倒序，lower_bound/upper_bound二分查找，copy，swap

详见：https://blog.csdn.net/u010183728/article/details/81913729



## stack

``` c++
stack<int> s;
stack< int, vector<int> > stk;  //覆盖基础容器类型，使用vector实现stk
s.empty();  //判断stack是否为空，为空返回true，否则返回false
s.size();   //返回stack中元素的个数
s.pop();    //删除栈顶元素，但不返回其值
s.top();    //返回栈顶元素的值，但不删除此元素
s.push(item);   //在栈顶压入新元素item
```



## queue & priority_queue

 ```c++
 queue<int> q; //priority_queue<int> q;
 q.empty();  //判断队列是否为空
 q.size();   //返回队列长度
 q.push(item);   //对于queue，在队尾压入一个新元素
                //对于priority_queue，在基于优先级的适当位置插入新元素
  
 //queue only:
 q.front();  //返回队首元素的值，但不删除该元素
 q.back();   //返回队尾元素的值，但不删除该元素
  
 //priority_queue only:
 q.top();    //返回具有最高优先级的元素值，但不删除该元素
 ```



## vector

1.**push_back** 在数组的最后添加一个数据

2.**pop_back** 去掉数组的最后一个数据

3.at 得到编号位置的数据

4.**begin** 得到数组头的指针

5.**end** 得到数组的最后一个单元+1的指针

6．**front** 得到数组头的引用

7.**back** 得到数组的最后一个单元的引用

8.max_size 得到vector最大可以是多大

9.capacity 当前vector分配的大小

10.**size** 当前使用数据的大小

11.resize 改变当前使用数据的大小，如果它比当前使用的大，者填充默认值

12.reserve 改变当前vecotr所分配空间的大小

13.**erase** 删除指针指向的数据项

14.**clear** 清空当前的vector

15.rbegin 将vector反转后的开始指针返回(其实就是原来的end-1)

16.rend 将vector反转构的结束指针返回(其实就是原来的begin-1)

17.**empty** 判断vector是否为空

18.swap 与另一个vector交换数据



## map/multimap

map和multimap都需要#include<map>，唯一的不同是，map的键值key不可重复，而multimap可以，也正是由于这种区别，map支持[ ]运算符，multimap不支持[ ]运算符。在用法上没什么区别。

1.    **begin**()     返回指向map头部的迭代器
2.    **clear**(）    删除所有元素
3.    **count**()     返回指定元素出现的次数
4.    **empty**()     如果map为空则返回true
5.    **end**()      返回指向map末尾的迭代器
6.    equal_range()  返回特殊条目的迭代器对
7.    **erase**()     删除一个元素
8.    **find**()     查找一个元素
9.    get_allocator() 返回map的配置器
10.    **insert**()    插入元素
11.    key_comp()   返回比较元素key的函数
12.    **lower_bound**()  返回键值>=给定元素的第一个位置
13.    max_size()   返回可以容纳的最大元素个数
14.    rbegin()    返回一个指向map尾部的逆向迭代器
15.    rend()     返回一个指向map头部的逆向迭代器
16.    **size**()     返回map中元素的个数
17.    **swap**()      交换两个map
18.    **upper_bound**()  返回键值>给定元素的第一个位置
19.    value_comp()   返回比较元素value的函数



## 二维数组传参

## 1 将给定第二维长度的二维数组作为形参传递

```cpp
#include<iostream>
using namespace std;

void outputArray1(int ia[][4])
{
    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 4; ++j)
        {
            cout << ia[i][j] << endl;
        }
    }
}

int main()
{
    int ia[3][4] = {
    {1, 2, 8, 9 },
    {2, 4, 9, 12},
    {4, 7, 10, 13}
    };
    //输出数组中所有元素
    outputArray1(ia);
    return 0;
}
```

## 2 使用给定第二维长度的指针作为形参传递

```cpp
#include<iostream>
using namespace std;

void outputArray2(int (*pia)[4])
{
    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 4; ++j)
        {
            cout << pia[i][j] << endl;
        }
    }
}

int main()
{
    int ia[3][4] = {
    {1, 2, 8, 9 },
    {2, 4, 9, 12},
    {4, 7, 10, 13}
    };
    //输出数组中所有元素
    outputArray2(ia);
    return 0;
}
```

## 3 将二维数组指针转换成一维数组指针作为形参传递

将`int (*ia)[4]`转换为 `int* ia`

```cpp
#include<iostream>
using namespace std;

void outputArray3(int *pia2)
{
    for (int i = 0; i != 12; ++i)
    {        
        cout << pia2[i] << endl;
        //等价于cout<< *(pia2 + i) << endl;       
    }
   /* 另一种写法
   for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 4; ++j)
        {         
            cout << *(pia2 + i * 4 + j) << endl;
            //等价于cout << pia2[ i * 4 + j] << endl;
        }
    }*/
}

int main()
{
    int ia[3][4] = {
    {1, 2, 8, 9 },
    {2, 4, 9, 12},
    {4, 7, 10, 13}
    };
    //输出数组中所有元素
    outputArray3((int*)ia);
    return 0;
}
```

## 4 使用二级指针作为形参传递

```cpp
#include<iostream>
using namespace std;

void outputArray4(int **pia3)
{

    for (int i = 0; i != 3; ++i)
    {
        for (int j = 0; j != 4; ++j)
        {
            cout << *((int*)pia3 + i * 4 + j) << endl;//解引用指针
        }
    }
}

int main()
{
    int ia[3][4] = {
    {1, 2, 8, 9 },
    {2, 4, 9, 12},
    {4, 7, 10, 13}
    };

    //输出数组中所有元素
    outputArray4((int **)ia);//强制转换为int**
    return 0;
}
```

*Tips：对于2维数组ia来说，`ia[1]`指向第二行的第一个位置，`\*ia[1]`等于2，一级指针指向每行（子数组）的第一个元素，用二级指针才能定位到任意单个元素。在实际使用中尽量避免使用强制转换和多级指针。*



## 最短路板子

``` C++
#define Max 0x3f3f3f3f
#define maxn 10010
int n,m;
int Map[maxn][maxn];
int dist[maxn];
int vist[maxn];
```

## Floyd

``` C++
void floyd()
{
    int i,j,k;
    for (k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for (j=1; j<=n; j++)
            {
                Map[i][j]=min( Map[i][j],Map[i][k]+Map[k][j] );
            }
        }
    }
}

```

## Dijkstra

``` C++
void Dijkstra(int s)
{
    int i,j;
    int u;
    int Min;
    for (i=1; i<=n; i++)
    {
        vist[i]=0;
        dist[i] = Map[s][i];
    }
    vist[s] = 1;
    for (i=1; i<=n; i++)
    {
        Min=Max;
        u = -1;
        for (j=1; j<=n; j++)
        {
            if (vist[j]==0&&dist[j]<Min)
            {
                u = j;
                Min = dist[j];
            }
        }
        if (u==-1)
            break;
        vist[u] = 1;
        for (j=1; j<=n; j++)
        {
            if(vist[j]==0)
            {
                if(dist[u]+Map[u][j]<dist[j])
                    dist[j] = dist[u]+Map[u][j];
            }
        }
    }
}
```

## SPFA

``` C++
void spfa(int s)
{
    int i,now;
    for( i=1;i<=n;i++ )
    {
        dist[i]=Max;
        vist[i] = 0;
    }
    dist[s] = 0;
    queue<int>q;
    q.push(s);
    vist[s] = 1;
    while (!q.empty())
    {
        now = q.front();
        q.pop();
        vist[now] = 0;
        for( i=1;i<=n;i++)
        {
            if (dist[i]>dist[now]+Map[now][i])
            {
                dist[i] = dist[now]+Map[now][i];
                if (vist[i] == 0)
                {
                    q.push(i);
                    vist[i] = 1;
                }
            }
        }
    }
}
```

