# icpc2018_a
题目里关键的句子：  
Your goal is to plan your journey in such a way as to maximize the probability of catching your plane.  
You also have a complete schedule of when each bus leaves its start station and arrives at its destination station.   
Additionally, for each bus you know the probability that it is actually going to run as scheduled, as opposed to its driver going on strike and taking the bus out of service.  
If you arrive before the departure time of a bus, you can transfer to that bus.  
If two or more buses leave a station at the same time, you can try to get on only one of them.  

设计算法  
使用动态规划的方法，依时间倒序，计算每个有巴士出发或到达的站台和时间点的概率。因为计算前面的时间点的概率需要依据后面时间点的概率，因此根据自底向上的方法，最终可以得出0时刻从0站台出发赶上飞机的概率，即题目要求求出的最优路径的概率。  
