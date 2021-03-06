
#include <iostream>
#include <algorithm>
using namespace std ;
struct params {
    int* arr;
    int n;
};
inline void print (int a) {
    char s[10];
    int n=0;
    while (a>0 || n==0) {
        s[n]='0'+a%10;
        a/=10;
        n++;
    }
    for (int i=n-1;i>=0;--i) {
        putchar(s[i]);
    }
    putchar(' ');
}

struct stack {
    int end=0;
    params buffer [50];
    inline void push(params param) {
        buffer[end]=param;
        end+=1;
    }
    inline params pop () {
        end-=1;
        return buffer[end];
    }
};
stack stack;
inline void vstavochki (int* arr,int n) {
    if (n==2) {
        if (arr[0]>arr[1]) {
            swap (arr[0],arr[1]);
        }
    }
    for (int i(1);i<n;++i) {
        int tmp=arr[i];
        int j=i-1;
        while (tmp<arr[j]  && (j>=0)) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=tmp;
    }
}
inline int Partition (int* arr,int n) {
    int a(arr[0]), b(arr[n / 2]), c(arr[n - 1]), base;
    if ((a <= b && b <= c) || (c <= b && b <= a)) base = n / 2;
    else if ((a <= c && c <= b) || (b <= c && c <= a)) base = n - 1;
    else base = 0;
    swap(arr[n-1], arr[base]);
    base=arr[n-1];
    int i(0),j(0);
    while (j<n-1) {
        if (arr[j]>base) {
            j+=1;
        } else {
            swap (arr[i],arr[j]);
            i+=1;
            j+=1;
        }
    }
    swap (arr[i],arr[n-1]);
    return i;
}
void quicksort (int*arr,int n) {
    int i=Partition(arr,n);
    params param1;
    param1.arr=arr+i;
    param1.n=n-i;
    stack.push(param1);
    param1.arr-=i;
    param1.n=i;
    stack.push(param1);
    while (stack.end>0) {
        param1=stack.pop();
        if (param1.n<=1) {
            continue;
        } else if (param1.n<=16) {
            vstavochki(param1.arr, param1.n);
        } else {
            i=Partition(param1.arr, param1.n);
            param1.arr+=i;
            param1.n-=i;
            stack.push(param1);
            param1.arr-=i;
            param1.n=i;
            stack.push(param1);
        }
    }
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int arr[25000000];
    int count=-1;
    char k = '1';
    int num;
    while (k!=EOF) {
        k=getchar();
        num=0;
        while (k>='0' && k<='9') {
            num=num*10+k-'0';
            k=getchar();
        }
        count+=1;
        arr[count]=num;
    }
    quicksort(arr, count);
    for (int i(9);i<count;i+=10) {
        print(arr[i]);
    }
    return 0;
}





















