agentapd
========

Agent of WiFi hardware

调整方案，改为直接基于linux系统接口编写，如netlink系统接口等

### Next Sprint:

编写main函数实现通过netlink与内核通信发送和接收消息,优先使用linux_80211_wrapper.h的接口



## 编译方法：

* $ source build.env
* $ make clean
* $ make