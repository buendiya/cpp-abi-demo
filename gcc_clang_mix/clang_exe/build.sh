mkdir -p build
cd build

export CC=/usr/bin/clang-6.0
export CXX=/usr/bin/clang++-6.0
cmake ..
make -j8
