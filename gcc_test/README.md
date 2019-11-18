## gcc test

- D_GLIBCXX_USE_CXX11_ABI

    编译 gcc_lib 时, 不添加 "-D_GLIBCXX_USE_CXX11_ABI=0", nm 看到的 Hello::print 如下：
    ```txt
    Hello::print(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)
    ```

    添加 "-D_GLIBCXX_USE_CXX11_ABI=0", nm 看到的 Hello::print 如下：
    ```txt
    Hello::print(std::string)
    ```

    编译 gcc_lib 时添加，编译 gcc_exe 时不添加，会导致编译 gcc_exe 报如下错误：
    ```txt
    undefined reference to `Hello::print(std::__cxx11::basic_string<char, std::char_traits<char>, std::allocator<char> >)'
    ```
    编译 gcc_exe 也添加时，可以正常编译