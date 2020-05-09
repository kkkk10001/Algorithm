#include <iostream>
#include <cmath>
using namespace std;
int n, arr[1010];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		int iminval = i;
		int minval = arr[i];
		for (int j = i; j < n; j++) { // [0,i-1]까지는 이미 정렬 됐으므로, i부터 보자.
			if (minval > arr[j]) { // arr[j]가 현재 저장 된 최소값보다 작은 경우
				iminval = j;
				minval = arr[j];
			}
		}
		swap(arr[i], arr[iminval]);
		//i번째 위치 원소와 최소값을 갖는 위치의 원소를 swap하자.
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\n";
	}
}
