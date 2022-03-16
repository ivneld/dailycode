#include <stdio.h>
#include <string.h>

int max(int x, int y) {
	return x > y ? x : y;
}

int DP[1010][1010] ;
char ch1[1010] , ch2[1010] ;

int main() {
	
	int len1, len2;

	scanf("%s", &ch1[1]);
	scanf("%s", &ch2[1]);

	len1 = strlen(&ch1[1]);
	len2 = strlen(&ch2[1]);

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (ch1[i] == ch2[j])
				DP[i][j] = DP[i - 1][j - 1] + 1;
			else
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			
		}
	}
	printf("%d", DP[len1][len2]);

	return 0;
}