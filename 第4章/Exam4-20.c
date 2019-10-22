#include <stdio.h>
#include <string.h>

int Replace(char *S, int start, char *T, char *V) 
{
	int i, j, k, l, n, m, s, count = 0, signal = 0;
	
	n = strlen(T);
	m = strlen(V);
	s = strlen(S);
	
	for(i = start - 1; S[i] != '\0'; i++) 
	{
		k = i;
		j = 0;
		
		while(S[k] == T[j])
		{
			k++;
			j++;
		}
		
		if(T[j] == '\0') 
		{
			if(m - n > 0) 
			{
				for(l = s + (m - n) * (count + 1) - 1; l >= k; l--)
				{
					S[l] = S[l - m + n];
				}
				for(l = k - n, j = 0; j < m; l++, j++)
				{
					S[l] = V[j];
				}
				
				count++;
			} 
			else if(m - n < 0)
			{
				for(l = k - n, j = 0; j < m; l++, j++)
				{
					S[l] = V[j];
				}
				for(; l < s + (m - n) * (count + 1); l++)
				{
					S[l] = S[l+n-m];
				}
				count++;
			} 
			else 
			{
				for(l = k - 1; l >= k - n; l--, j--)
				{
					S[l] = V[j - 1];
				}
			}
			
			signal = 1;
		}
	}
	
	S[s + (m - n) * count] = '\0';
	
	return signal;
}

int main() 
{
	char a[100], b[100], c[100];
	int n;
	
	printf("请输入字符串S: ");
	gets(a);
	printf("请输入查找的子串T: ");
	gets(b);
	printf("请输入替换的子串V: ");
	gets(c);
	printf("请输入开始查找的位置start: ");
	scanf("%d",&n);
	
	if(Replace(a, n, b, c))
		printf("替换后的结果是: %s\n",a);
	else
		printf("S中不存在子串T!\n");
		
	return 0;
}
