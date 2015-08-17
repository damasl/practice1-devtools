#include "filters.hpp"

class FiltersMaslova : public Filters{
	virtual void boxFilter(const Matrix &src, Matrix &dst, const int kSize = 3) {};
	virtual void filter2d(const Matrix &src, Matrix &dst, const Matrix &kernel){
		const int R=src.rows(), C=src.cols(), RF=kernel.rows(), CF=kernel.cols();
		Matrix matr(R+RF, C+CF);
		matr.Zeros();
		//copy
		for (int x=0; x<R; x++)
			for (int y=0; y<C; y++){
				matr[x][y]=src[x][y];
			};
		
		//filter
		dst = Matrix(R,C);
		dst.Zeros();
		for (int x=0; x<R; x++)
			for (int y=0; y<C; y++)
				for (int i=0; (i<RF)&&(i<(R-x));i++)
					for (int j=0; (j<CF)&&(j<(C-y));j++){
						dst[x][y]+=kernel[i][j]*matr[x+i][y+j];
					}

	};
	virtual void median(const Matrix &src, Matrix &dst, const int kSize = 3) {};
	virtual void SobelOx(const Matrix &src, Matrix &dst) {};
};

Filters* createFiltersMaslova(){
	Filters* filters = new FiltersMaslova();
	return filters;
}