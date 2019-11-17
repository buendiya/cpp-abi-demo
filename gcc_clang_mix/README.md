## 简介

- clang_exe 链接 gcc_lib, 可以正常运行. 用 ldd 可以看到: gcc_lib 和 clang_exe 都链接的是gcc的标准库: libstdc++.so.6

- 如果编译 clang_exe 时添加 "-stdlib=libstdc++", 可以正常编译；

- 如果编译 clang_exe 时添加 "-stdlib=libc++", 会报如下错误：
    ```txt
        main.cpp:(.text+0xac): undefined reference to `Hello::print(std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char> >)'
        clang: error: linker command failed with exit code 1 (use -v to see invocation)
    ```

    说明: 不能同时链接 libstdc++ 和 libc++

- 如果编译 gcc_lib 时添加 "-stdlib=libc++", 会报如下错误：
    ```txt
    c++: error: unrecognized command line option ‘-stdlib=libc++’
    ```
    说明: gcc 和 libc++ 是不能同时使用的
