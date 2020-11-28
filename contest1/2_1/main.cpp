#include <iostream>
#include <algorithm>

int* GetArray(int n){
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> arr[i];
    return arr;
}
int* GetSuffixMax(const int* arr, int n){
    int* arr_suffix = new int[n];
    arr_suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i){
        arr_suffix[i] = std::max(arr_suffix[i + 1], arr[i]);
    }
    return arr_suffix;

}
void GetIndex(const int* arr_a, const int* arr_b, int* answer, int n){
    int max = 0;
    int index = 0;
    int* arr_b_s = GetSuffixMax(arr_b, n);
    for(int i = 0; i < n; i++)
        if((arr_a[i] + arr_b_s[i]) > max){
            index = i;
            max = (arr_a[i] + arr_b_s[i]);
        }
    answer[0] = index;
    while(arr_b[index] != arr_b_s[index])
        ++index;
    answer[1] = index;
    delete[] arr_b_s;
}
int main() {
    int n;
    int* arr_a, *arr_b;
    int answer[2];
    std::cin >> n;
    arr_a = GetArray(n);
    arr_b = GetArray(n);
    GetIndex(arr_a, arr_b, answer, n);
    std::cout << answer[0] << " " << answer[1];
    delete[] arr_a;
    delete[] arr_b;
    return 0;
}