# PrivateAccessor

## 前言
这是一个非侵入式访问 c++ 私有成员变量的一个实现

## 我该如何使用
复制 `PrivateAccessor.hpp` 文件到你的工程

## 使用示例
```cpp
DECLARE_ACCESS(CLASS_TYPE, PROPERTY_TYPE, PROPERTY_NAME)

// 给类 X 的 int a 字段生成了一个访问接口
DECLARE_ACCESS(X, int, a)

// 注意！同类型的字段不可同时生成一个访问接口，例如：
DECLARE_ACCESS(X, int, a)
DECLARE_ACCESS(X, int, b)
// 以上代码是不行的

// 声明了之后如何访问？
// 得到了类 X 的私有字段 int a 的值
auto a = PrivateAccess::access(x, PrivateAccess::PlaceHolder<int>);
// [type a = int&]
// 对于不同的类型，请使用符合其类型的占位符
```

## 什么编译器可以使用？
msvc gcc clang 都可以