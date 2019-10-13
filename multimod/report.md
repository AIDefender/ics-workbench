# 1. 解析神秘代码
## 1.1. 表达式分析

若记 $x=$ (int64_t)((double)a $*$ b / m)$*$m, 则 
$$t\equiv a\times b-x \equiv a\times b\ (\operatorname{mod} m) \text{ iff } x\equiv0(\operatorname{mod}m)\ \ (*)
$$
即数学上,只要$x$被$m$整除,表达式结果就是正确的.条件$(*)$容易验证.但若考虑溢出, $x$必须足够大,使$a\times b-x\leq2^{63}-1$. 

**Theorm 1**:若 $A=\{x|x\leq a\times b\ \wedge\ m|x  \},\ x=\sup A(**)$,则$a\times b-x\leq2^{63}-1$.

证明: 假设$a\times b-x>2^{63}-1$,由 $m<2^{63}-1$, 有$a\times b-x>m$. 则存在 $x'=x+m$, s.t. $m|x'$ 且 $a\times b-x'=a\times b-x-m>0,\ x'<a\times b$. 故 $x'\in A, x'>x$, 与 $x=\sup A$矛盾! 证毕.

而事实上,如果`(double)a * b / m)`计算精确, 条件$(**)$可由强制类型转换`(int64_t)`保证; 如果不精确且数值偏大, 可能导致 $x>a\times b$, 可由`t < 0 ? t + m : t`的判断弥补;但如果不精确且数值偏小,可能导致 $a\times b-x>2^{63}-1$,使结果溢出.

## 1.2. 实验
### 1.2.1. double保证精度
根据`IEEE754`浮点数标准,`double`类型的尾数为52位,加上标准形式的1共计53位,所以当 $a\times b\leq2^{53}-1$时,`double`能保证乘法的精度.根据理论推导,代码能产生正确结果.测试代码为`test_3.py`中的`test1()`.经实验验证,代码确实能产生正确结果.

### 1.2.2. double损失精度
测试代码为`test_3.py`中的`test2()`.其中为判断`double(a*b)`与 $a\times b$ 的大小关系, 调用了`get_double`程序,其返回`(double)input`.下表为实验结果:

|`double(a*b)`与$a\times b$的关系|大于|小于|等于|
|-----------|:----------:|:-----------:|---------
|总数量|5004|4996|0|
|结果正确的数量|135|124|0|

其中`double(a*b)`$>a\times b$ 的情形正确率较低,与理论预测相符. 但是在`double(a*b)`$<a\times b$ 的情形中,`t < 0 ? t + m : t`的弥补措施并未提高准确率.进一步调试后发现: `double(a*b)//m`与`(a*b)//m`差距较大,基本维持在 $10^2$ 的数量级,再乘$m$同样会有很大概率溢出.

启示:浮点数表示范围大,可一定程度上缓解乘法溢出的问题; 但损失精度后,其所能表示的大数过于稀疏,不能准确计算.
