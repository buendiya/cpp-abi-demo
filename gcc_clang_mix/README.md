
## 简介

    gcc_lib:   gcc 编译, print 函数有 std::string 参数, 默认不指定 -stdlib
    gcc_lib_2: gcc 编译, print 函数没有参数, 默认不指定 -stdlib

    clang_lib:   gcc 编译, print 函数有 std::string 参数, 默认指定: -stdlib=libc++
    clang_lib_2: gcc 编译, print 函数没有参数, 默认指定: -stdlib=libc++

    clang_exe: gcc 编译, 默认不指定 -stdlib

- 不调用 clang_lib 的 print 函数的话，可以正常编译； ldd 可以看到同时链接了: libstdc++.so.6 和 libc++.so.1

- 调用 clang_lib 的 print 函数的话，会报如下错误：

    ```txt
    undefined reference to `clang_lib::Hello::print(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)'
    ```

- 说明编译时可以同时链接 libstdc++.so.6 和 libc++.so.1 这两个标准库

- 编译 clang_exe 时，不指定 -stdlib, 因此默认用的是 libstdc++.so; clang_lib 的 头文件被编译成: "clang_lib::Hello::print(std::__cxx11::basic_string", 但 libclang_library.so 里对应的symbol 是: clang_lib5Hello5printENSt3__112basic_string; 因此编译失败.
  
    对应 libgcc_library.so 里的symbol 是： gcc_lib5Hello5printENSt7__cxx1112basic_string

- 如果编译 clang_exe 时添加 "-stdlib=libc++", 则会因为 gcc_lib 的 print 函数的 std::string 参数编译失败

    ```txt
    undefined reference to `gcc_lib::Hello::print(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >)'
    ```

## Reference

### https://answers.unrealengine.com/questions/674473/compiling-libraries-in-linux.html

    In general, if you are not passing STL types between your code and any Unreal module, you may be fine using libstdc++
