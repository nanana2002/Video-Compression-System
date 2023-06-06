void dct(double *src,double *dst,int N)
{
    int k,n;
    double res;
    for(k=0;k<N;k++){  
        res=0;
        for(n=0;n<N;n++)      
            res+=src[n]*cos((double)cosLUT[k][n]);
        dst[k]=res*cshift[k];
    }
}

void transposeMatrix(double *matSrc,double *matResult,int srcWidth,int srcHeight){
    int i,j;
    for(i=0;i<srcWidth;i++){
        for(j=0;j<srcHeight;j++){
            matResult[i*srcHeight+j]=matSrc[j*srcWidth+i];
        }
    }
}

// get sub-block ducerOne[8][8] from a matrix[startX:startY:startX+7:startY+7]
void getPelsFromPic(PIXEL_CY pixelCy,PicSize CySize,int startX,int startY,double **ducerOne){
    int i,j;
    for(i=0;i<8;i++){
        for(j=startX;j<=startX+7;j++){
            ducerOne[i][j-startX]=(double)pixelCy[startY+i][j];
        }
    }
}
