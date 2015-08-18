#include "filters.hpp"

int chooseBoxIndex(int xi, int max)
{
	while(true)
	{
		if (xi>max) xi = max+max-xi;
		else if (xi<0) xi *=-1;
		else break;
	}
	return xi;
}


class FiltersMaslova : public Filters{
	virtual void boxFilter(const Matrix &src, Matrix &dst, const int kSize = 3) {
		const int R=src.rows(), C=src.cols(), k2=kSize*kSize, k = kSize/2;
		//filter
		dst = Matrix(R,C);
		dst.Zeros();
		for (int x=0; x<R; x++)
			for (int y=0; y<C; y++){
				for (int i = -k; i<=k; i++)
					for (int j =-k; j<=k; j++)
						dst[x][y]+=src[chooseBoxIndex(x+i, R-1)][chooseBoxIndex(y+j, C-1)];
				dst[x][y]/=k2;
			}
	};
	virtual void filter2d(const Matrix &src, Matrix &dst, const Matrix &kernel){
		const int R=src.rows(), C=src.cols(), RF=kernel.rows()/2, CF=kernel.cols()/2;
		//filter
		dst = Matrix(R,C);
		dst.Zeros();
		for (int x=0; x<R; x++)
			for (int y=0; y<C; y++)
				for (int i=-RF; i<=RF;i++)
				if(((x+i)>=0)&&((x+i)<R))
					for (int j=-CF; j<=CF;j++)
					if (((y+j)>=0)&&((y+j)<C)){
						dst[x][y]+=kernel[i+RF][j+CF]*src[x+i][y+j];	
					}
	};
	virtual void median(const Matrix &src, Matrix &dst, const int kSize = 3) {};
	virtual void SobelOx(const Matrix &src, Matrix &dst) {};
};

Filters* createFiltersMaslova(){
	Filters* filters = new FiltersMaslova();
	return filters;
}