# [Diamond V] 건물주 - 13342 

[문제 링크](https://www.acmicpc.net/problem/13342) 

### 성능 요약

메모리: 2176 KB, 시간: 0 ms

### 분류

최대 유량, 플로이드–워셜, 그래프 이론, 최소 비용 최대 유량, 최단 경로

### 제출 일자

2024년 7월 24일 01:04:46

### 문제 설명

<p>강호는 구역 N개로 나누어져 있는 도시의 건물주이다. 각각의 구역은 양방향 도로로 이루어져 연결되어져 있다. 각 구역은 0번부터 N-1번까지 번호가 매겨져 있다.</p>

<p>강호는 차를 C대 가지고 있고, 각각의 차는 구역 중 하나에 주차되어 있다. 한 구역에 여러 대의 차가 주차되어 있을 수도 있다. </p>

<p>오늘은 월세를 받는 날이다. 강호는 직접 자신의 건물을 돌아다니면서 월세를 받으려고 한다. 월세를 받아야 하는 건물은 총 M개가 있으며, 월세를 받는 순서는 A<sub>i</sub>로 미리 정해져 있다. 즉, 첫 번째로 A<sub>0</sub> 구역으로 가서 월세를 받고, 그 다음 A<sub>1</sub> 구역으로 가서 월세를 받고, ..., 마지막으로 A<sub>M-1</sub>구역으로 가서 월세를 받아야 한다. 강호는 처음에 0번 구역에 있다.</p>

<p>구역을 이동하는 방법은 걷기와 차 타기 두 가지가 있다. 걷는데 걸리는 시간은 W × 도로의 길이 이며, 차를 타고 이동하는데 걸리는 시간은 D × 도로의 길이이다.</p>

<p>강호가 자신의 차가 주차되어있는 구역에 도착했다면, 차 한 대에 탑승해서 원하는 곳으로 이동할 수 있다. 강호는 한 번 차에서 내린 다음에는 다시는 그 차를 타지 않는다. 또, 월세를 받을 때는 반드시 차에서 내려야 한다.</p>

<p>도로의 정보가 주어졌을 때, 월세를 모두 받는데 걸리는 시간의 최솟값을 구하는 프로그램을 작성하시오.</p>

### 입력 

 <p>첫째 줄에 도시의 개수 N과 주차되어 있는 차의 개수 C, 월세를 받아야 하는 건물의 개수 M, 걷는데 걸리는 시간 W, 차를 타고 이동하는데 걸리는 시간 D가 주어진다. (1 ≤ N, C, M ≤ 50, 1 ≤ D < W ≤ 100)</p>

<p>둘째 줄에는 차가 주차되어 있는 구역이 공백으로 구분해서 주어진다.</p>

<p>셋째 줄에는 월세를 받아야하는 순서 A<sub>i</sub>가 공백으로 구분해서 주어진다. (A<sub>0</sub> ≠ 0)</p>

<p>넷째 줄부터 N개의 줄에는 도시의 도로 정보가 인접 행렬 형식으로 주어진다. i번 줄의 j번째 수는 i번 구역과 j번 구역의 도로 정보를 나타내며, 0인 경우에는 도로가 없는 것, 자연수인 경우에는 그 도로의 길이이다. 도로의 길이는 62를 넘지 않는 자연수이다.</p>

<p>도로는 양방향 도로이기 때문에, i번째 줄의 j번째 수와 j번째 줄의 i번째 수는 항상 같으며, i번째 줄의 i번째 수는 항상 0이다. 또, 이동할 수 없는 구역은 없다.</p>

### 출력 

 <p>첫째 줄에 월세를 모두 받는데 걸리는 시간의 최솟값을 출력한다.</p>

