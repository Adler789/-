#include <stdio.h>
#include <stdlib.h>
void convert(int *a, int n){
	int i = -1, j = 0, top = 0, *stack = (int *)calloc(n, sizeof(int));

	while (a[++i] < 0 && i < n){
		stack[++top] = a[i] * a[i]; //ջ��ֵ����Ϊ������a[i]����ƽ����ѹ��ջ��
		
	}

	while ((i!=n)&&(top!=0)){
		if ((a[i] * a[i]) < stack[top])    {              //��ʱa[i]Ϊ�Ǹ���
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
