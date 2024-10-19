# PrivateAccessor

## 前言
这是一个非侵入式访问 c++ 私有成员变量的一个实现

## 我该如何使用
复制 `PrivateAccessor.hpp` 文件到你的工程

## 使用示例
```cpp
// 访问私有成员变量
DECLARE_PROPERTY_ACCESSOR(CLASS_TYPE, PROPERTY_TYPE, PROPERTY_NAME)

// 给类 X 的 int a 字段生成了一个访问接口
DECLARE_PROPERTY_ACCESSOR(X, int, a)

// 注意！同类型的字段不可同时生成一个访问接口，例如：
DECLARE_PROPERTY_ACCESSOR(X, int, a)
DECLARE_PROPERTY_ACCESSOR(X, int, b)
// 以上代码是不行的，因为会生成两个函数签名一样的函数，无法匹配

// 声明了之后如何访问？
// 得到了类 X 的私有字段 int a 的值
int a = PrivateAccess::access(x, PrivateAccess::Flag<int>);
// 对于不同的类型，请使用符合其类型的占位符
```

```cpp
// 访问私有成员方法
// 无参
DECLARE_FUNCTION_ACCESSOR_With_0_ARGS(CLASS_TYPE, RETURN_TYPE, FUNCTION_NAME)
// 带有一个参数
DECLARE_FUNCTION_ACCESSOR_With_1_ARGS(CLASS_TYPE, RETURN_TYPE, PARAMETER_TYPE, FUNCTION_NAME)

// 如 main.cpp 当中样例的
class X
{
private:
    int a = 1;

    int func(int& para)
    {
        std::cout << a + para << "\n";
        para = 2;
        return a + para;
    }
};

DECLARE_FUNCTION_ACCESSOR_With_1_ARGS(X, int, int&, func)

int main()
{
    int b = 1;
    int res = PrivateAccess::call(x, b, PrivateAccess::Flag<int>);
    std::cout << "res: " << res << ", b: " << b << "\n";
}
// 同样的，无法声明两个形参一样的 accessor
```

## 什么编译器可以使用？
msvc gcc clang 均可

## 更新日志
+ 2024-10-18：初版，支持访问私有成员变量
+ 2024-10-19：新增支持访问私有成员函数，支持 0 和 1 个参数