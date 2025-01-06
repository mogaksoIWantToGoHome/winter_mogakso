# 4161 풀이

## 1. 문제 
[백준](https://boj.kr/4616)
### - 문제 설명
#### 이 문제는 체스의 나이트가 움직여 갈 수 있는 위치가 주어지면 그 위치로 가는 최소 횟수를 각 줄에 표시하는 문제이다. 이는 x y 형태로 주어지며 나이트가 갈 수 있는 방향은 
 - (2,1)
 - (2, -1)
 - (1, 2)
 - (1,-2)
 - (-2, 1)
 - (-2, -1)
 - (-1, 2)
 - (-1, -2)
##### 이다. 

## 문제 풀이
### 1. 기본 발상
#### 문제에서 (2, 1)과 (-2, -1)는 +와 -관계로 표현할 수 있기 때문에 이처럼 나타낼 수 있는 방향을 중복을 없애 나타내면 다음과 같다.
 - (2,1)
 - (1,2)
 - (2, -1)
 - (1, -2)

### 2. 표현
#### 위의 좌표를 통해 미지수 4개만을 사용해 나이트의 이동을 표현할 수 있으며 이를 행렬로 표현하면 다음과 같다.
$$
\begin{bmatrix}
2 & 1 &  2 &  1 \\
-1 & -2 & 1 & 2
\end{bmatrix} \times \begin{bmatrix}
a\\
b\\
c\\
d\\
\end{bmatrix} = \begin{bmatrix}
x\\
y
\end{bmatrix}
$$

### 3. a, b, c, d에 대한 식 찾기
$$
\begin{bmatrix}
2 & 1 &  2 &  1 \\
-1 & -2 & 1 & 2
\end{bmatrix} \times \begin{bmatrix}
a\\
b\\
c\\
d
\end{bmatrix} = \begin{bmatrix}
x\\
y
\end{bmatrix}
$$

$$
C = \begin{bmatrix}
2 & 1 &  2 &  1 \\
-1 & -2 & 1 & 2 
\end{bmatrix}, 
v = \begin{bmatrix}
a\\
b\\
c\\
d
\end{bmatrix}, 
B = \begin{bmatrix}
x\\
y\\
\end{bmatrix}
$$
$$
C \times v = B
$$
#### c와 d에 0을 대입해 특정한 x행렬을 얻을 수 있다.
$$
v_{specity} = \begin{bmatrix}
a\\
b\\
0\\
0
\end{bmatrix}
$$
$$
2a + b = x
$$
$$
-a - 2b = y
$$
$$
v_{specity} = \begin{bmatrix}
\frac{2x+y}{3} \\
-\frac{2y+x}{3}\\
0\\
0
\end{bmatrix}
$$

#### 이때, C $\times$ $v_{specity}$ = B이다. 
#### 만약 C $\times$ $v_{temp}$ = 0이라면 C $\times$ $(v_{specify} + v_{temp})$ = B이므로 $v_{temp}$를 찾아야한다.
#### C의 3번째 열과 4번째 열은 C의 첫번째 열과 두번째열의 요소로 표현이 가능하기 때문에 
$$
v_{temp1} = \begin{bmatrix}
\frac{5}{3} \\
-\frac{4}{3}\\
-1\\
0\\
\end{bmatrix} \\
v_{temp2} = \begin{bmatrix} 
\frac{4}{3} \\
-\frac{5}{3}\\
0\\
-1\\
\end{bmatrix}
$$
#### 로 
$$
v 
= v_{specify} + \lambda_1 \times v_{temp1} + \lambda_2 \times v_{temp2}\\
= \begin{bmatrix}
\frac{2x+y}{3} \\
-\frac{2y-x}{3}\\
0\\
0\\
\end{bmatrix} + \lambda_1 \begin{bmatrix}
\frac{5}{3} \\
-\frac{4}{3}\\
-1\\
0\\
\end{bmatrix} + \lambda_2 \begin{bmatrix}
\frac{4}{3} \\
-\frac{5}{3}\\
0\\
-1\\
\end{bmatrix}
$$
#### 이다. 
#### 즉
$$
R = |\frac{2x+y}{3} + \frac{5}{3} \lambda_1 + \frac{4}{3} \lambda_2 | + 
|-\frac{2y+x}{3} - \frac{4}{3} \lambda_1 - \frac{5}{3} \lambda_2 | + 
|\lambda_1| + 
|\lambda_2| 
$$
$$
= |\frac{2x+y}{3} + \frac{5}{3} \lambda_1 + \frac{4}{3} \lambda_2 | + 
|\frac{2y+x}{3} + \frac{4}{3} \lambda_1 + \frac{5}{3} \lambda_2 | + 
|\lambda_1| + 
|\lambda_2|
$$
#### 이며, R의 최솟값이 나이트 이동의 최소가 된다.
#### 이때, $\frac{5}{3}$과 $\frac{4}{3}$에 대해 정수 $\lambda_1$, $\lambda_2$가 주어진다면, 이때, 최솟값을 가지는 $\lambda_1$과 $\lambda_2$는 유일할 수 밖에 없기 때문에 공간에서 이분탐색을 진행하여 최솟값을 찾을 수 있다.
