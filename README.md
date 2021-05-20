# cpp_example
1) 记录了平时做业务工程时，遇到不确定的东西，做的小实验等

## 试验记录
### example1: 数组中的1[a]表达居然也可以？ 
### example2: 类的继承小实验？ 
### example3: 如何遍历文件夹下的文件（windows下的api）？ 
### example4: 使用智能指针申请一段内存？ 
### example5: 使用std::find()判断子串？
### example6: 初步使用静态强制转换和动态强制转换。
### example7: 操作符重载
### example8: 宏定义尽量用const替换define
### example9: 类成员的方法的const修饰
### example10: pair的作用
### example11: c++构造函数中的=default和=delete
### example12: c++中的%d %ld(%Id) %lld(%I32d)
### example13: for循环中的j++和++j其实是一样的
### example14: map的使用：赋值 
### example15: sort中自定义比较函数
### example16: min, max函数的输入参数必须一致，编译器不会做自动转换  
### example17: map的insert和find
### example18: 文件的按行读取和行分割
### example19: map的遍历，map通过key取value  
### example20: 如何合并两个vector?
### example21: 字符串长度：str.size()或者str.lenth()
### example22: 变长数组的使用
### example23: vector可以用来封装pair,并进行key和value的索引
### example24: c++11不能用变量来定义数组
### example25: 如何清除字符数组中的字符？Memset
### example26: map的value可以用来存放指针
### example27: sort，map时中相同值时的顺序(按原来的顺序存储)
### example28: map如果索引不到，会返回nullptr 
### example29: 前置声明
### example30：文件的读写
### example31：string的compare?
### example32：c++中判断文件存在并删除它？
### example33：char可以直接赋值给string.
### example34: 类中的属性是定义成public还是private，取决于类外是否会使用该属性
### example35: class的赋值(直接赋值)以及vector的赋值容易踩的坑
### example36: 震惊！二维array的初始化：{(),()}
### example37: error: undefined reference to 'vtable for DetectionProcess' 接口实现注意事项
### example38: for 循环，改变值？ 关于for(auto e : v) 是否需要用引用的问题
### example39: 智能指针申请一段内存的方法
### example40: 构造函数参数错误（或者类中属性的类构造函数实现有问题），会出现implicitly-deleted default constructor
### example41: 类中的属性，声明的类指针只是一个空指针，需要在构造函数中new出实体,且最好不要使用指针，这样避免在构造和析构中大量的new, malloc
### example42: 增加日志打印模块，分等级打印
### example43: 类属性的初始化
### example44: 二维数组的初始化,声明和赋值不能分开
### example45: 避免头文件重复包含的情况！！
### example46: 字符串，任意长度的空格字符分隔计算
### example47: 形参为const时，传入的实参必须是const吗？其作用是什么？
### example48: 有元函数和有元类其实是告诉函数或者告诉有元类中的函数，可以访问本类中的私有成员
### example49: public的数据可以用于类外的访问
### example50: 类名和命名空间名 不能并行起相同的名字，否则会被认为重定义
### example51: 用基类的指针实例化继承类的对象时，只能调用基类定义的函数
### example52: cpp 能否用默认形参？？？ 当然可以
### example53: 类作为base类的属性时，用指针和直接对象化的用法和注意事项
### example54: 判断元素是否在set内部
### example55: memcpy和memccpy的区别及使用注意事项
### example56: free()失败，出现segment fault.
### example57: 类中实例话的对象会在类析构时析构
### example58: malloc后delete和free的后果
### example59: 如何将浮点数只保留后5位？
### example60: 单例模式
### example61: 函数模版是可以多参数的
### example62: 类中的静态变量和静态函数
### example63: split 分割字符串
### example64: 要十分注意的是: 在实现模版时，定义和实现不要分开，否则会出现链接问题
### example65: 函数执行或者初始化一定不要放置在头文件中
### example67: 函数默认参数
### example68: Eigen矩阵库的基本操作
### example69: 遍历文件夹下的所有文件
### example70: 容易错误理解的循环
### example71: accumulate的类型取决于初始值的类型,要注意
### example72: for需要改值记得用引用
### example73: Eigen的基本操作实验
### example75: c++中的可替代关键词
### example76: map中key如果不存在,通过key检索值时会返回默认值
### example77: python默认深拷贝
### example78: *& 指针引用的性质
### example79: 拷贝构造函数的深拷贝和浅拷贝
### example80: vector 容器 emplace_back 和push_back区别
### example88: 判断key是否在map中, 用count比轮询更有效率
### example89: 内存对齐
### example90: call_once()
### example91: lambda函数及闭包
### example92: lambda函数及静态变量的构造是在main函数之前
### example93: constexpr的应用
### example94: sprintf 会覆盖
