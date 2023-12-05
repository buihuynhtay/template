struct Matrix{
    int col, row;
    vector<vector<ll>> matrix;

    Matrix(int _row = 0, int _col = 0){
        row = _row;
        col = _col;
        matrix = vector<vector<ll>>(row, vector<ll>(col, 0));
    }

    Matrix identity(int n){
        Matrix res(n, n);
        while(n--){
            res.matrix[n][n] = 1;
        }
        return res;
    }

    Matrix operator * (const Matrix b){
        Matrix a = (*this);
        Matrix res(a.row, b.col);
        for(int i = 0; i < a.row; i++){
            for(int j = 0; j < b.col; j++){
                for(int k = 0; k < a.col; k++){
                    add(res.matrix[i][j], a.matrix[i][k] * b.matrix[k][j] % mod);
                }
            }
        }
        return res;
    }

    Matrix operator ^ (const long long &exp){
        if(!exp) return identity(col);
        Matrix t = (*this) ^ (exp/2);
        return (exp&1 ? t * t * (*this) : t * t);
    }

};
