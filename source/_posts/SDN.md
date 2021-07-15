---
title: SDN
date: 2021-07-15 20:06:26
tags: 
    - SDN 
    - Network
---
# SDN
## 1. Mininet 基本使用

### Mininet指令
#### net
查看拓扑链接情况
#### xterm 
`xterm [hosts]`
打开对应主机终端
#### pingall
测试所有设备联通性
#### 在对应主机执行指令
`[host] {command}`

### iperf指令
```bash
iperf 
    -c [ip] 客户端IP 与-s互斥
    -s 服务器 与-c互斥
    -t [seconds] 测量时间
    -i [seconds] 测量报告次数
    -p [port] 端口
    -u 使用UDP
```
