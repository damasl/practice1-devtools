#include "filters.hpp"

class FiltersMaslova : public Filters{
	virtual void boxFilter(const Matrix &src, Matrix &dst, const int kSize = 3) {};
	virtual void filter2d(const Matrix &src, Matrix &dst, const Matrix &kernel){
		const int R=src.rows(), C=src.cols(), RF=kernel.rows()%2, CF=kernel.cols()%2;
		
		//filter
		dst = Matrix(R,C);
		dst.Zeros();
		for (int x=0; x<R; x++)
			for (int y=0; y<C; y++)
				for (int i=-RF; i<=RF;i++)
				if(((x+i)>=0)&&((x+i)<R))
					for (int j=-CF; j<=CF;j++)
					if (((y+j)>=0)&&((y+j)<C)){
						std::cout<<"I'm here "<<x<<" "<<i<<" "<<y<<" "<<j<<std::endl;
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