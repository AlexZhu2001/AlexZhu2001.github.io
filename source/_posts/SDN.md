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


## 2. 链路性能参数设置及iperf数据绘图
### 链路性能设置
`mn --link=tc,loss=[loss_rate],bw=[band_width],delay='[delay]'`

loss -> 每条链路的丢包率
bw -> 链路带宽
delay -> 每条链路的延迟

### iperf结果绘图

在服务器端使用 `iperf -s -i 1 | tee tcp.txt`
将结果通过管道存放到文件

效果如下
```txt
------------------------------------------------------------
Server listening on TCP port 5001
TCP window size: 85.3 KByte (default)
------------------------------------------------------------
[ 14] local 10.0.0.2 port 5001 connected with 10.0.0.1 port 60150
[ ID] Interval       Transfer     Bandwidth
[ 14]  0.0- 1.0 sec  1.08 MBytes  9.09 Mbits/sec
[ 14]  1.0- 2.0 sec  1.14 MBytes  9.56 Mbits/sec
[ 14]  2.0- 3.0 sec  1.14 MBytes  9.57 Mbits/sec
[ 14]  3.0- 4.0 sec  1.14 MBytes  9.56 Mbits/sec
[ 14]  4.0- 5.0 sec  1.14 MBytes  9.57 Mbits/sec
[ 14]  5.0- 6.0 sec  1.14 MBytes  9.57 Mbits/sec
[ 14]  6.0- 7.0 sec  1.14 MBytes  9.56 Mbits/sec
[ 14]  7.0- 8.0 sec  1.14 MBytes  9.57 Mbits/sec
[ 14]  8.0- 9.0 sec  1.14 MBytes  9.55 Mbits/sec
[ 14]  9.0-10.0 sec  1.14 MBytes  9.58 Mbits/sec
[ 14] 10.0-11.0 sec  1.14 MBytes  9.57 Mbits/sec
[ 14] 11.0-12.0 sec  1.14 MBytes  9.55 Mbits/sec
[ 14] 12.0-13.0 sec  1.14 MBytes  9.58 Mbits/sec
[ 14]  0.0-13.1 sec  14.9 MBytes  9.53 Mbits/sec
```

然后 使用

```bash
cat tcp.txt | grep sec | head -n 10 | tr "-" " " | awk '{print $4,$8} > a'
```

其中 
* `cat tcp.txt`读取文件并显示 
* `grep sec` 会标记出含有sec的列
* `head -n 10` 取出前十行
* `tr "-" " "` 会将`-`替换为空格
* `awk '{print $4,$8}'` 会取出第四列和第八列

效果如下
```txt
1.0 9.09
2.0 9.56
3.0 9.57
4.0 9.56
5.0 9.57
6.0 9.57
7.0 9.56
8.0 9.57
9.0 9.55
10.0 9.58
```
然后我们使用`gnuplot`绘图
* 输入`gnuplot` 回车 进入gnuplot
* 输入`plot "a" title "tcp" with linespoints` 绘图,`"a"` 为文件名,`title "tcp"`设置标题,`with linespoints`设置为带点直线
* `set xrange[0:10]`和`set yrange[0:10]`设置x、y轴范围 0 ~ 10
* `set xtics 0,1,10`和`set ytics 0,1,10`设置x、y轴刻度 0开始 10结束 1步进
* `set xlabel "time(sec)"`和`set ylabel "Throughput(Mbps)"`设置x、y轴标记文字
* `set title "Tcp"` 设置图标标题为Tcp
* `set terminal gif` 设置保存格式为gif
* `set output "a.gif"` 设置保存的文件名为`a.gif`
* `replot` 修改设置后重绘或者可以保存文件

{% asset_img a.gif 绘图效果 %}