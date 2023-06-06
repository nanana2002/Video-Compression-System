int nomQntMtx[8][8] = {
    {8, 16, 19, 22, 26, 27, 29, 34},
    {16, 16, 22, 24, 27, 29, 34, 37},
    {19, 22, 26, 27, 29, 34, 34, 38},
    {22, 22, 26, 27, 29, 34, 37, 40},
    {22, 26, 27, 29, 32, 35, 40, 48},
    {26, 27, 29, 32, 35, 40, 48, 58},
    {26, 27, 29, 34, 38, 46, 56, 69},
    {27, 29, 35, 38, 46, 56, 69, 83}
};

void blockquantization(double **data, int dataSize, int *quantMtx){
  
    int r, c;
  
    for (r = 0; r < dataSize; r++){
        for (c = 0; c < dataSize; c++){
            int tmp = round(data[r][c]/quantMtx[r][c]);
            data[r][c] = (double)tmp*quantMtx[r][c];
        }
    }
}
