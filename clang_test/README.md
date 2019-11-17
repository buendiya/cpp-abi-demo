## clang test

### llvm, clang, libc++, libc++ ABI 简介 

https://llvm.org

http://clang.llvm.org/

### test

使用  libc++ 时，需要安装下面这两个pkg
```bash
sudo apt-get install libc++-dev libc++abi-dev
```

- 不指定 "-stdlib=" 和 时， ldd 可以看到链接的是：libstdc++.so.6; 说明 clang 默认使用的 stdlib 和 gcc 一样， 都是 libstdc++

- 指定 "-stdlib=libstdc++", ldd 可以看到链接的是：libstdc++.so.6

- 指定 "-stdlib=libc++", 链接的是: libc++.so.1 和 libc++abi.so.1
