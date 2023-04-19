# Data analysis of 58Ni + 96Ru @RITU


## 1.代码分析流程数据

  - 1. Decode
      - 利用[Grain](https://github.com/IMP-HHuang/Grain)将数据Decode成txt文件（由于文件较大，已被删除）
         - [Grain](https://github.com/IMP-HHuang/Grain)为RITU数据分析专用的，用JAVA语言写的数据处理软件，详细介绍见链接
         - 数据Decode采用各探测自触发模式输出
         - [code](./Decode/Grain/code)
         - [刻度及触发参数文件 conf](./Decode/Grain/conf)
      - 利用基于ROOT的C++代码将txt文件转成root文件
