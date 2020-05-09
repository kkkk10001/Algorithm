#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1010101
int arr[MAX_SIZE], n;
void my_qsort(int a[], int s, int e) {
	if (s >= e) return;
	int m = (s + e) / 2;
	int pivot = a[m]; // 중간 값을 pivot으로 잡기.
	swap(a[e], a[m]); // 구현을 깔끔하게 하기 위해 미리 pivot을 맨 뒤로 옮긴다.
	int L = s, R = e - 1;
	while (L <= R) {
		while(a[L] < pivot) L++; // pivot 이상 수 나올때까지 L++
		while(a[R] > pivot) R--; // pivot 미만 나올때까지 R--
		if(L<=R)swap(a[L], a[R]); // a[L]과 a[R] 스왑
	} 
	swap(a[e], a[L]); // 현재 L 위치는 pivot 이상이면서 최초의 위치 이므로 pivot을 이 자리로 옮겨준다.

	my_qsort(a, s, L - 1);
	my_qsort(a, L + 1, e);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];
	my_qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
