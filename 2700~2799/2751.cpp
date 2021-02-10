#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int i, n;
    int *arr;

    // 할당
    scanf("%d", &n);
    arr = new int[n];

    // 입력
    for (i = 0; i < n; ++i)
        scanf("%d", arr + i);

    // 정렬
    sort(arr, arr + n);

    // 출력
    for (i = 0; i < n; ++i)
        printf("%d\n", arr[i]);

    delete[] arr;
    return 0;
}