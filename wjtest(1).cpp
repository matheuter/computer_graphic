// +-----------------------------------------------------
//【摘要】:练习与测试
//【目录】:搜索test加编号即可跳转到目标区域
//   [test1]: function与map的基本用法,多态实现
//   [test2]: 控制台绘图
//   [test3]: ASCII码的转义字符用法
//   [test4]: 变长参数与变长参数模板，仿printf为例
//   [test5]: 计时工具
//   [test6]: 智能指针的实现unique_ptr与shared_ptr
//   [test7]: 随机数生成
//   [test8]: c++中cout与cin的状态刷新与C语言中的flush操作
//   [test9]: 使用宏时应当注意的事项，c++新标准内联函数(inline function)
//   [test10]: 底层const与顶层const的区别
//   [test11]: 深复制与浅复制的警惕
//   [test12]: delete莫名出现的异常
//   [test13]: auto使用的注意事项
//   [test14]: typeid()与头文件<typeinfo>
//   [图论]: 求解一个节点到另一节点某长度的通路的数目(权值都为1)
// +----------------------------------------------------x

#include<iostream>
#include<functional>
#include<map>
#include<conio.h>
#include<typeinfo>

using std::cout;
using std::endl;

// -----------------------------------------------------
//[测试1]:function与map的基本功能
// -----------------------------------------------------
namespace test1
{
	int add(int a, int b){return a + b;}
	int del(int a, int b){return a - b;}
	int mult(int a, int b){return a * b;}

	void map_function_test()
	{
		char a;
		int b[2];
		std::cin >> b[0] >> a >> b[1];
		std::map < char, std::function < int (int, int) > >op = \
		{
			{'+', add},
			{'-', del},
			{'*', mult}
		};
		std::cout << op[a] (b[0], b[1]) << std::endl;
	}
	void function_test()
	{
	        
	}
	void map_test()
	{
	
	}
}
// -----------------------------------------------------
//[测试2]:字符绘图
//    1.基本线段
//    2.常见图形
//    3.基本框架
//    4.Tcc下gotoxy()函数的实现
// -----------------------------------------------------

#define default_size 50
#define SIGN int

namespace test2{
	inline int max_(int x, int y) {return ((x) > (y) ? (x) : (y));}
	inline int min_(int x, int y) {return ((x) < (y) ? (x) : (y));}
	class Widget{
	public:
		Widget(int Widget_weight = default_size, int Widget_high = default_size);
		Widget(Widget* parent);
	private:
	      static SIGN sign;
	      size_t Widget_high;
	      size_t Widget_weight;
	      void commend(char* formal, ...);
	      void SetLine(int x1,int y1, int x2, int y2);
	      void SetPoint(int pos, int rect);
	      void SetText(int x, int y, char* string);
	};// defination of Widget class
	
	void Widget::SetLine(int x1, int y1, int x2, int y2)
	{
		int x, y;
		int weidge = x1 - x2;
		float k = ((double)x1 - x2)/(y1 -y2);
		for (int i = max_(x1,x2); i <= x2; ++i){
			x = i;
			y = y1 + (int)((x - x1)*k);
			gotoxy(x, y);
			std::cout<< "";
		}
	}
}
// ------------------------------------------------------------------------
//[测试3]:ASCII码的用法
// from wiki
// ANSI escape sequences are a standard for in-band signaling to control the cursor location, color,
// and other options on video text terminals and terminal emulators.
// Certain sequences of bytes,most starting with Esc and '[', are embedded into the text,
// which the terminal looks for and interprets as commands, not as character codes.
//    1.\x1B为ASCII码esc，其后加[可以执行一些系统命令，仅部分平台支持，与语言无关
// ------------------------------------------------------------------------
#include<cstdio>

namespace test3{
      void printf_clear_test()
      {
      	printf("\x1B[2J\x1B[0;0f");
      }
      void printf_gotoxy_test(int x, int y)
      {
      	printf("\x1B[%d;%df", y, x);
      	printf("这里输出字符");
      }
}
// -----------------------------------------------------
//[测试4]:变长参数与变长参数模板
//    1.c语言:...与一系列宏va_list等
//     typedef char* va_list
//     #define _INTSIZEOF(n)  ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))
//     #define _ADDRESSOF(v)  (&const_cast<char&>(reinterpret_cast<const volatile char&>(v)))
//     #define __crt_va_start_a(ap, v) ((void)(ap = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v)))
//     #define __crt_va_arg(ap, t)     (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))
//     #define __crt_va_end(ap)        ((void)(ap = (va_list)0))
//     #define __crt_va_start(ap, x)   ((void)(__vcrt_va_start_verify_argument_type<decltype(x)>(), __crt_va_start_a(ap, x)))
//     #define va_start __crt_va_start
//     #define va_arg   __crt_va_arg
//     #define va_end   __crt_va_end
//    2.c++: initlist_list模板类与变长参数模板
// -----------------------------------------------------
namespace test4{
	void c_variable_parameter_test(char* formal, ...)
	{
		
	}
}

// ------------------------------------------------------------------------
//[测试5]:计时工具
//    1.std:chrono
//    2.time.h
//    3.系统级计时工具
// ------------------------------------------------------------------------

#include<chrono>

//c++11标准
#define TIME_INIT;  std::chrono::time_point<std::chrono::system_clock> start, end;
#define TIME_START; start = std::chrono::system_clock::now();
#define TIME_FINISH;end = std::chrono::system_clock::now();
#define TIME_SHOW;  std::cout << "调用耗时:\t" << std::chrono::duration<double> (end - start).count() << "秒" << std::endl;


#define TIME_BEGIN; auto start = std::chrono::system_clock::now();
#define TIME_END;   auto end = std::chrono::system_clock::now();\
                    std::cout << "调用耗时:  " << std::chrono::duration<double> (end - start).count() << "秒" << std::endl;

namespace test5{
	void chrono_time_test_cpp()
	{
		
	}
	
	
}

int main()
{
	//test1::map_function_test();
	//test3::printf_gotoxy_test(34,45);
	//test2::SetLine(42,10,25,25);
	//test2::SetLine(40,1,1,40);
	return 0;
}