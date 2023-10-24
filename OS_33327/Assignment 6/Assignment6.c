#include <stdio.h>

void fifo(int pro[], int q[], int n, int f)
{
	 int s = 0;
	 int hit = 0;
	 int miss = 0;
	 int ans1[f][n];
	 int col = 0;
	 for (int i = 0; i < f; i++){
	 	q[i] = -1;
	 }
	 for (int i = 0; i < n; i++){
		 int cnt = 0;
		 for (int j = 0; j < f; j++){
			 if (pro[i] == q[j]){
				 cnt++;
				 break;
			 }
		 }
		 if (cnt == 0){
			 q[s] = pro[i];
			 s = (s + 1) % f;
			 miss++;
		 }
		 else{
		 	hit++;
		 }
		 for (int row = 0; row < f; row++){
		 	ans1[row][col] = q[row];
		 }
		 col++;
	 }

	 for (int i = 0; i < f; i++){
		 printf("f%d ", i + 1);
		 for (int j = 0; j < n; j++){
			 if (ans1[i][j] == -1){
			 	printf("* ");
			 }
			 else{
			 	printf("%d ", ans1[i][j]);
			 }
		 }
		 printf("\n");
	 }
	 printf("\nTotal Hit:%d", hit);

	 printf("\nTotal miss:%d\n", miss);
	 printf("---------------------------------------------------------\n");
}
void OptimalAlgo(int pro[], int q[], int n, int f)
{
	 int hit = 0;
	 int miss = 0;
	 int ans2[f][n];
	 int col = 0;
	 for (int i = 0; i < f; i++){
	 	q[i] = -1;
	 }
	 for (int i = 0; i < n; i++){
		 int cnt = 0;
		 for (int j = 0; j < f; j++){
			 if (pro[i] == q[j]){
				 cnt++;
				 break;
			 }
		 }
		 if (cnt != 0){
		 	hit++;
		 }
		 else{
			 miss++;
			 int v = -1;
			 int ok = 0;
			 int s[f]; // Create an array to simulate a set
			 for (int k = 0; k < f; k++){
			 	s[k] = -1; // Initialize the set with -1 values
			 }
			 for (int j = i + 1; j < n; j++){
				 for (int k = 0; k < f; k++){
					 if (pro[j] == q[k]){
						 v = pro[j];
						 s[k] = v; // Add the element to the set
						 break;
					 }
		 	 	 }
				 int set_full = 1;
				 for (int k = 0; k < f; k++){
					 if (s[k] == -1){
						 set_full = 0; // The set is not full yet
						 break;
					 }
				 }
				 if (set_full){
					 ok = 1;
					 break;
				 }
		 	}
		 	if (ok){
				if (v != -1){
					 int x = -1;
					 for (int j = 0; j < f; j++){
						 if (q[j] == -1){
							 x = j;
							 break;
						 }
					 }
					 if (x != -1){
					 	q[x] = pro[i];
					 }
					 else{
						 for (int j = 0; j < f; j++){
							 if (q[j] == v){
								 q[j] = pro[i];
								 break;
							 }
						 }
					 }
				 }
				 else{
					 int x = -1;
					 for (int j = 0; j < f; j++){
						 if (q[j] == -1){
							 x = j;
							 break;
						 }
					 }
					 if (x != -1){
					 	q[x] = pro[i];
					 }
					 else{
					 	q[0] = pro[i];
					 }
				 }
		 	}
			else{
				 for (int j = 0; j < f; j++){
					 if (s[j] == -1){
						 q[j] = pro[i];
						 break;
					 }
				 }
			}
	 	}
		for (int row = 0; row < f; row++){
		 	ans2[row][col] = q[row];
		}
		col++;
	 }
	 for (int i = 0; i < f; i++){
		 printf("f%d ", i + 1);
		 for (int j = 0; j < n; j++){
		 	if (ans2[i][j] == -1){
		 		printf("* ");
		 	}
			else{
			 	printf("%d ", ans2[i][j]);
			}
	 	 }
	 	 printf("\n");
	 }
	 printf("\nTotal Hit:%d", hit);
	 printf("\nTotal miss:%d\n", miss);
	 printf("---------------------------------------------------------\n");
}

void LRU(int pro[], int q[], int n, int f)
{
	 int hit = 0;
	 int miss = 0;
	 int ans3[f][n];
	 for (int i = 0; i < f; i++){
	 	q[i] = -1;
	 }
	 int col = 0;
	 for (int i = 0; i < n; i++){
		 int cnt = 0;
		 for (int j = 0; j < f; j++){
			 if (pro[i] == q[j]){
				 cnt++;
				 break;
			 }
		 }
		 if (cnt != 0){
		 	hit++;
		 }
		 else{
			 miss++;
			 int v = -1;
			 int s[f]; // Create an array to simulate a set
			 for (int k = 0; k < f; k++){
			 	s[k] = -1; // Initialize the set with -1 values
			 }
			 for (int j = i - 1; j >= 0 && i != 0; j--){
				 for (int k = 0; k < f; k++){
					 if (pro[j] == q[k]){
						 v = pro[j];
						 s[k] = v; // Add the element to the set
						 break;
					 }
				 }
				 int set_full = 1;
				 for (int k = 0; k < f; k++){
					 if (s[k] == -1){
						 set_full = 0; // The set is not full yet
						 break;
					 }
				 }
				 if (set_full){
				 	break;
				 }
			 }
			 if (v != -1){
				 int x = -1;
				 for (int j = 0; j < f; j++){
					 if (q[j] == -1){
						 x = j;
						 break;
					 }
				 }
				 if (x != -1){
				 	q[x] = pro[i];
				 }
				 else{
					 for (int j = 0; j < f; j++){
						 if (q[j] == v){
							 q[j] = pro[i];
							 break;
						 }
					 }
				 }
			 }
			 else{
				 int x = -1;
				 for (int j = 0; j < f; j++){
					 if (q[j] == -1){
						 x = j;
						 break;
					 }
				 }
				 if (x != -1){
				 	q[x] = pro[i];
				 }
				 else{
				 	q[0] = pro[i];
				 }
			 }
		 }
		 for (int row = 0; row < f; row++){
		 	ans3[row][col] = q[row];
		 }
		 col++;
	 }
	 for (int i = 0; i < f; i++){
		 printf("f%d ", i + 1);
		 for (int j = 0; j < n; j++){
			 if (ans3[i][j] == -1){
			 	printf("* ");
			 }
			 else{
			 	printf("%d ", ans3[i][j]);
			 }
		 }
		 printf("\n");
	 }
	 printf("\nTotal Hit:%d", hit);
	 printf("\nTotal miss:%d\n", miss);
	 printf("---------------------------------------------------------\n");
}
int main()
{
	 printf("Enter the String Length:");
	 int n;
	 scanf("%d", &n);
	 int pro[n];
	 for (int i = 0; i < n; i++){
	 	scanf("%d", &pro[i]);
	 }
	 printf("Enter the number of Frames\n");
	 int f;
	 scanf("%d", &f);
	 int q[f];
	 for (int i = 0; i < f; i++){
		 q[i] = -1;
	 }

	 while (1){
		 printf("Enter Your Choice\n1.FIFO\n2.Optimal Solution\n3.LRU\n4.Exit\n");
		 int var;
		 scanf("%d", &var);
		 if (var == 4){
		 	break;
		 }

		 switch (var){
			 case 1:
			 fifo(pro, q, n, f);
			 break;
			 case 2:
			 OptimalAlgo(pro, q, n, f);
			 break;
			 case 3:
			 LRU(pro, q, n, f);
			 break;
			 default:
			 printf("Wrong Response");
			 break;
		 }
	 }
	 return 0;
}
