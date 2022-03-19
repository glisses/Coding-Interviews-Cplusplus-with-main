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