# Data analysis of 58Ni + 96Ru @RITU

## 1.Setup

## 2. Products
   img src="./fig/Products.png" width="80%" height="80%">
## 3.代码分析流程数据

  - 1. Decode
      - 利用[Grain](https://github.com/IMP-HHuang/Grain)将数据Decode成txt文件（由于文件较大，已被删除）
         - [Grain](https://github.com/IMP-HHuang/Grain)为RITU数据分析专用的，用JAVA语言写的数据处理软件，详细介绍见链接
         - 数据Decode采用各探测自触发模式输出
         - [code](./Decode/Grain/code)
         - [刻度及触发参数文件 conf](./Decode/Grain/conf)
      - 利用基于ROOT的C++代码将txt文件转成root文件
        - [code](./Decode/C++) 
        - 输出文件位于核结构服务器/home/share_data/58Ni96Ru/root/目录（注意请勿删除或修改此文件，另外此文件较大且服务器存储空间有限请勿将其拷贝到别的目录）
        - 输出文件结构
          - 探测器类型见Branch名
          - tof ：MWPC到DSSD的飞行时间
          - oe ：原始道址
          - e ：北航刻度结果
          - t ：时间戳，单位为10 ns
  - 2. 事件重构
     - [code](./event) 
     - par.h ： 参数文件
        - EventWindow ： 事件重构时间窗
     - parx.txt pary.txt 为DSSD刻度参数，目前存在问题，建议直接采用北航刻度结果或重新刻度
  - 3. 衰变分析
     - [Hao Huang](./ana/)
     - Xinghan Yu
     - Xiangyu Fu
