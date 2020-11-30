# 3D-display
 3D to Gcode的附属程序
 详细生成原理再onenote

 write_triangle_obj.cpp:生成三角形网格模型
 write_ours_obj、 write_ours_obj_2.0、 write_ours_obj_3.0_batch:都是生成我们结构的obj模型，2.0更高效，3.0是批量生成。
 主要使用2.0，后续发现现有的生成方式已经很完美，没法改动。
 
 animation_ours_structure.cpp：填充线的动态展示
 animation_gradual_change.cpp：变化线的动态展示，细分了两次
 这两个展示都是用细线，所有有点锯齿。
 
 write_gradual_change_obj
 1.0：上下都不是完美的三角形网格
 2.0：为了是完美网格，结果边的粗细不一
 3.0：大三角形容易是完美网格，但是小三角形有点困难，所以结合了1.0和2.0
 
 