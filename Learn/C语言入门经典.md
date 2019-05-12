# C语言入门经典

[TOC]



## 第一章

- C程序创建的4个步骤：
  - 编辑  
  - 编译 
  - 链接
  - 执行 
- GCC的常用命令：
  - gcc -E                       Preprocess only; do not compile, assemble or link.
  - gcc  -S                       Compile only; do not assemble or link.
  - gcc  -c                       Compile and assemble, but do not link.
  - gcc -o <file>         Place the output into <file>.
- 重定向：
  - `>` 为输出重定向，箭头指的是方向流向
  - `<`为输入重定向，箭头指的方向是流入

- 头文件的两种写法：
  - `#include<stdio.h>`表示引用的是标准头文件，编译器会从系统配置的库中寻找
  - `#include"stdio.h"`表示用户自己定义在工程目录下的头文件，编译器默认会从工程目录文件下寻找，找不见再从系统库中寻找
- 标准C语言的主函数的写法：
  
- `int main(int argc, char **argv)`
  
- 转义字符的实例输出:
  
- 使用 `\\` `\x`
  
- 三字母序列（不常用，可忽略）

- 预处理指令：

  - 所有以`#`开头的语句，**#include< >也为预处理指令**
  - 在`gcc -E`时，将所有的预处理语句进行处理，头文件也要进行处理

  

##　第二章

- 计算机的内存：
  - 可执行程序存放在计算机的存储器中
  - 计算机在执行程序的过程中，组成程序的语句和变量将会读取到计算机内存（ＲＡＭ）中。
  - 所以需要把程序处理完成的数据使用文件系统或者数据库存放起来。
  - 内存的最小单位为`bit`,内存操作的基本单位为字节`byte`
  
- 变量的命名：
  - 由数字，字母，下划线组成
  - 不能以数字开头，一般不以下划线开头，系统变量比较喜欢以下划线开头
  - 名称不能与关键字重复
  - 编译器最多只能识别前３１个字符，后面的字符会被截段
  
- 函数的声明和定义：

  - 编译器是从上到下进行编译的
  - 在同一个文件中，一般的被调函数放在主函数之后，就应该有声明，不然Ｃ语言编译器从上到下编译的话，系统将会无法识别
  - 类似于变量的先声明在使用，函数也应该先声明在使用。
  - 函数的的声明和定义可以分开，函数的实体(定义)只有一次，声明可以多次。
  - 声明不开辟空间，定义才开辟空间。

- printf()函数的多行处理方法：使用`""` 进行多行的连接

  ```c
  printf("Hello World!"
  		"\t You are Welcome");
  ```

- 算数运算符之除法和取模运算符：
  - 除法运算符：
    - 当除数或者被除数异号，则结果为负
    - 当除数或者被除数同号，则结果为正
    - 想要变成小数除法，可以进行数据的强制转化
  - 取模运算符：
    - 其结果总是与**左**操作数的符号相同
- 变量和内存的关系：
  - 变量要放在内存当中，变量需要占用内存的多少空间是由变量的定义的函数类型确定的
  - 各种数据类型的极限值在`limits.h`里面可以查询到，Ｃ头文件的存储位置为`/usr/include`
  - 可以在声明的变量后面写上后缀，`L/U/LL/ULL`,`unsigned short a = 10U;  `
  - 整数类型：
    - `char(singned char) `   			占用１个字节
    - `short(signed short int)`　占用２个字节
    - `int (signed int)`　　　　　占用４个字节
    - `long(singed long int)`　　占用４个字节
    - `long long (singned long long  int)`　占用８个字节
    - `float`              占用４个字节
    - `double`　　　占用８个字节
  - 浮点数的问题：
    - 31:符号位，　30 --- 23(8位,无符号)：指数位，　22-- 0: 尾数位
    - `7655.001`在C语言中的表示为`0.7655001E4`
    - 浮点数错误问题：
      - 正数除以0 为+无穷
      - 负数除以0为-无穷
      - 0除以0为`NaN(Not a Number)`
    - `float `精确到6~7位，`double`精确到15位，`long double`精确到18位
    - 浮点数在进行变量的定义或者是宏定义时，加上后缀为好`#define PI 3.14159f`
    - C语言中有一个通用的约定：`#define`语句的标识符都是大写
- 针对与常量定义的两种方法：
  - `#define PI 3.14159f`,这条语句将其定义为指定的类型的常量值，PI只是一个字符序列，在预编译时进行符号替换
  - `const float Pi = 3.14159f`，会使得比编译器检查代码是否试图改变他的值，无法直接改变，但可以间接改变。
- 控制输出的字段宽度：默认是右对其，加`-`左对齐
- `sizeof()`关键字和`strlen（）`函数的区别：
  
  - `sizeof（）`是运算符，返回值为`unsigned int`,参数可以任意类型变量，
  
    - 功能：获得字节大小，最大的
  
    - `sizeof()`是在编译时计算，无法返回动态分配的内存大小
  
      - >数组 --- 编译时分配的数组大小
        >
        >指针 --- 存储该指针的空间大小，因机器的系统位数和编译器而异，一般为4 or 8
        >
        >类型 --- 该类型所占的空间大小
        >
        >对象 --- 该对象所占用的实际空间大小
        >
        >函数 --- 函数的返回值所占的空间大小，函数的返回值不为`void`
  
  - `strlen()`是一个函数，需要在运行时计算，传入的参数是一个`char *`类型，返回值为`size_t`
  
  - `strlen()`得到字符串可见字符的大小

```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char **argv)
{
    int a = 1;
    char st[100] = "1234567890";
    char st1[]   = "1234567890";
    char * st2 = "1234567890";
    char * p  = NULL;

    p = st;

    printf("sizeof(a)  = %ld\t\n ", sizeof(a)); //4
    printf("sizeof(st) = %ld\t strlen(st) = %ld\t\n ",sizeof(st),strlen(st));//100 10
    printf("sizeof(st1) = %ld\t strlen(st1) = %ld\t\n ",sizeof(st1),strlen(st1));//11 10
    printf("sizeof(st2) = %ld\t strlen(st2) = %ld\t\n ",sizeof(st2),strlen(st2));//8 10
    printf("sizeof(p)  = %ld\t  strlen(p) = %ld\t\n",sizeof(p),strlen(p));//8 10

    return 0;
}
//静态数组和指针的不同

```

- 数据的溢出：

  ```c
  #include <stdio.h>
    
  int main()
  {
      char a = 127;
      char b = 128;
      char c = 129;
  
      printf("char a = 127 and a = %d\n",a); //128
      printf("char b = 128 and b = %d\n",b); //-128
      printf("char c = 129 and c = %d\n",c); //-127
  
      return 0;
  }
  //类似于汽油表，超出最高的极限值，变回到最低值
  ```

- 强制数据类型转化：

  - 自动的类型转换：

    - 将值域较小的操作数类型转换为值域较大的操作数类型。

    - >1.`long double ` ,另一个转换为`long double`
      >
      >2.`double`,另一个转换为`double`
      >
      >3.`float`，另一个转换为`float`
      >
      >4.同为有符号或者无符号整数：按照顺序转化：
      >
      >`char` `short` `int` `long` `long long`
      >
      >5.**如果带符号的操作数级别低于无符号的操作数级别，将其转换为无符号数**
      >
      >6.如果带符号数的值域包含无符号数的值域，就把无符号数转换为带符号数
      >
      >7.两个数都转换为带符号数相对应的无符号数的类型

    - 赋值语句中的隐式的类型转换：

      - 将`float`或者`double`的数据转换为`int`型，会将小数截止
      - 最好使用显式类型转化

- 关于字符类型`char`

  - `char`只需要一个字节空间
  - 需要注意的是`char`因为编译器的不同代表的含义也不同，有可能代表`unsigned char`也有可能代表`signed char`
  - 所以在接受字符数据的时候，一般是这样的定义的`int st = 0;//获取键盘的按键值`
  - 使用`%c`或者`%d`来进行字符和数字的切换
  - 常见的ASCII码：`a:65`,`A:97`,`0:48`

- 枚举：

  - 枚举声明和定义形式：
    - `enum Weekday{Monday,Tuseday,Wednesday,Thursday,Friday,Saturday,Sunday};`
    - `enum Weekday today = Monday;`
    - 枚举默认从0开始，当然也可以自己定义，每一个值。
  - 用法：限定希望变量可能出现的取值。

- `_Bool` 类型

  - `BOOL`类型是最近才引入C的，所以使用`_Bool`可以最大限度的减少与已有代码的冲突的可能性

  - 需要添加头文件`#include<stdbool.h>`

    ```c
    #include <stdio.h>
    #include <stdbool.h>
    
    int main()
    {
        _Bool vaild = true;
        printf("vaild = %d\n",vaild);
        return 0;
    }
    
    ```

- 常用的数学函数：

  - `fabs`
  - `pow(x)`
  - `floor()` and `ceil()`
  - `exp(x)`


## 条件判断

- 算术运算符`> < >= <= == !=`
- `if`语句：
  - `if...else`
  - `if...else if...else`
- `switch...case...default...`
  - 判断条件为整数和字符，**需要注意的是C中的switch判断没有字符串的判断，更不能为浮点数**
- 逻辑判断运算符：`&& & || ！`
- 三目运算符：`式子 ? 值1:值2`
- `'1':48` `'A':65` `'a':97`
- 关于运算符的优先级问题：`（）[] . ->`依次递减

## 循环

## 数组和指针

### 1. 数组

- 数组的定义形式

#### 1.1 数组初始化

```C
int a[] = {1,2,3,4,,5,6,7,8,9,0};
int a[100] = {0};
char str[] = "Hello World!\n";
```

- 只读数组：

  ```C
  const int a[] = {1,2,3,4,5,6,7,8,9,0};
  //只读数组必须在变量定义的时候赋初值
  ```

- 未经初始化的数组里面是垃圾值

  ```C
  #include <stdio.h>
  #include <stdlib.h>
  
  int main(int argc, char **argv)
  {
  	int a[10];
  	int i = 0;
  	
  	for(i = 0; i < 10; i++) 
  	{
  		printf("%d\t",a[i]);
  	}
  	putchar('\n');
      return 0;
  }
  //1       0       4203641 0       48      0       48      0       0       0
  ```

- 计算数组元素的个数：

  ```C
  int length = sizeof(a) / sizeof(a[0]);
  ```

#### 1.2 初始化指定项目

C99规定了一种新的语法：

```
int a[6] = {[5] = 100};
//未经过初始化的元素为0
```

#### 1.3 为数组赋值

数组名称之间不能使用赋值号

```C
int a[10];
int b[10];
a = b; //error
```

#### 1.4数组的边界

- 编译器不会检查数组的边界问题

#### 1.5 指定数组大小

- 声明数组可以使用宏定义和正整数
- 声明数组还可以使用`sizeof()`关键字，在程序中`sizeof()`被认为是一个整数常量，是因为`sizeof()`在编译时被处理
- C99新定义：`int a[n];`称之为变长数组VAL

### 2.多维数组

- 其实数组里面的元素是顺序存储的，而二维数组是将线性存储转换为了二维
- `int a[2][3];`或者`int a[][3] = {};`,第一个表示行，第二个表示列

#### 2.1 初始化二维数组

- 两种初始化格式：

  - 加中括号
  - 不加中括号

  ```C
  int a[][3] = {{1,2,3},{4,5,6}};
  int b[][3] = {1,2,3,4,5,6};
  //必须指定列，可以不指定行
  ```

### 3. 指针和数组



