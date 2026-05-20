/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findThePrefixCommonArray(int* A, int ASize, int* B, int BSize, int* returnSize) {
    int n = fmax(ASize, BSize);
    int* trk = (int*)malloc(51 * sizeof(int));
    int* ans = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < 51; i++) trk[i] = 0;
    int i = 0, cnt = 0;
    while(i < n) {
        if(i < ASize) {
            trk[A[i]]++;
            if(trk[A[i]] == 0) cnt++;
        }
        if(i < BSize) {
            trk[B[i]]--;
            if(trk[B[i]] == 0) cnt++;
        }
        ans[i++] = cnt;
    }
    *returnSize = n;
    free(trk);
    return ans;
}