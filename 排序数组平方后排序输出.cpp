#include <stdio.h>
#include <stdlib.h>
void convert(int *a, int n){
	int i = -1, j = 0, top = 0, *stack = (int *)calloc(n, sizeof(int));

	while (a[++i] < 0 && i < n){
		stack[++top] = a[i] * a[i]; //栈赋值，将为负数的a[i]依次平方后压入栈区
		
	}

	while ((i!=n)&&(top!=0)){
		if ((a[i] * a[i]) < stack[top])    {              //此时a[i]为非负数
			a[j++] = a[i] * a[i], i++;
			
		}
		else a[j++] = stack[top--];
		
	}
	while(1)
		if (top != 0) a[j++] = stack[top--];
		else if (i != n) {a[j++] = a[i] * a[i];
		i++; }
		else break;
	for (j = 0; j < n; j++) printf("%10d", a[j]);
}


int main(){
	int n = 7;
	int a[7] = { -5, -4, -2, 0, 1,4, 7 };
	convert(a, n);

	getchar();
	getchar();
}
