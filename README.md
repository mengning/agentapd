agentapd
========

Agent of WiFi hardware

Next Sprint:已经能编译运行，接下来需要分析初始化过程，通过手工代码设定具体参数，最终使能AP，也就是station能扫描到AP但不一定能建立连接.

Milestone:编写main.c仿照hostapd使用driver的方法调用driver初始化无线网卡，需要用到到hostapd函数可以单独写一个hostapd.h声明函数和简单的测试用实现。（已完成，能够编译通过，执行时能初始化NL80211，但不确定是否成功初始化。）

Sprint:理解并修改编译通过代码(已基本完成)


编译方法：

$ source build.env
$ make clean
$ make