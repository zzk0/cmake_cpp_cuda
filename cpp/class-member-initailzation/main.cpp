//
// Created by zzk on 2021/11/25.
//

#include "iostream"
#include "array"

class Apple {
 public:
  Apple() {
    std::cout << "Apple Default Constructor" << std::endl;
  }
  explicit Apple(int i) {
    std::cout << "Apple Parameter Constructor: " << i << std::endl;
    this->data = i;
  }
  ~Apple() {
    std::cout << "Apple Default Destructor" << std::endl;
  }
  Apple(const Apple &apple) {
    std::cout << "Apple Copy Constructor" << std::endl;
  }
  Apple &operator=(const Apple &apple) {
    std::cout << "Apple Copy Assign Constructor" << std::endl;
    return *this;
  }
  Apple(Apple &&apple) noexcept {
    std::cout << "Apple Move Constructor" << std::endl;
  }
  Apple &operator=(Apple &&apple) noexcept {
    std::cout << "Apple Move Assign Constructor" << std::endl;
    return *this;
  }
 private:
  int data = 0;
};

class AppleTree {
 public:
  AppleTree() : apple_(Apple(10)) {
  }
 private:
  // 加入这个类有很多成员, 很多构造器, 那么就需要对这些成员逐一使用列表初始化
  // 所以用下面的方式可以节省一些代码, 如果某个构造器不想要默认值, 用列表初始化覆盖
  // 所以这里执行的结果是输出上面的 10, 而不会输出下面的 20
  Apple apple_ = Apple(20);
};

// 第一, 要分清楚初始化和赋值的区别
// 初始化发生在进入构造函数体之前, 赋值发生在构造函数体内
// 第二, 初始化有两种方式, 一种是使用初始化列表, 一种是直接赋初值

int main() {
  AppleTree tree;
  return 0;
}

// https://zhuanlan.zhihu.com/p/113179482
// C++11 之前只能使用初始化列表
// C++11 开始, 可以使用非静态数据成员初始化, 直接赋值给成员(默认值初始化) NSDMI
// C++17 开始, 可以使用赋值给静态成员
// 启发: 在复制/移动构造函数里面使用初始化列表
