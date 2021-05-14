int adjMat[N][N];

REP(k, 0, N){
    REP(i, 0, N){
        REP(j, 0, N){
            if (adjMat[i][k] == -1 || adjMat[k][j] == -1) continue;
            if (adjMat[i][j] == -1 || adjMat[i][j] > adjMat[i][k] + adjMat[k][j]) adjMat[i][j] = adjMat[i][k] + adjMat[k][j];
        }
    }
}
