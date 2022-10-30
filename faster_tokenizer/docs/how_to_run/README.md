# 如何在 M1 Mac 上运行

## CMakeLists.txt 中新增生成 executable 可执行文件
```cmake
add_executable(demo demo.cpp)

target_link_libraries(
        demo
        PUBLIC
        core_tokenizers
)
```


## cmake 配置
![](imgs/Screen Shot 2022-10-30 at 09.49.01.png)
![](imgs/Screen Shot 2022-10-30 at 09.49.24.png)

## make build and run demo executable
![](imgs/Screen Shot 2022-10-30 at 09.51.39.png)

