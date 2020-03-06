#pragma once
#include <iostream>  
#include <cstdlib>  
#include <cmath>
#include <vector>
#include <typeinfo>
#include<iomanip>
template  <class T>
class Matrix
{
private:
	int m_cols;
	int m_rows;
	int m_size;
	T* m_pData;
	bool singular = false;//是否奇异
public:
	Matrix();													//默认构造函数
	Matrix(int rows, int cols, T val = static_cast<T>(1));		//按行列数构造矩阵,元素填充值val
	Matrix(int rows_cols, T val = static_cast<T>(1));			//构造对角方阵,对角元素值val
	Matrix(int rows, int cols, const std::vector<T>& array, bool isRowFirst = true);//用一维数组构造矩阵，默认先行后列存储  
	Matrix(int rows, int cols, T* array, bool isRowFirst = true);					//用一维数组构造矩阵，默认先行后列存储 
	Matrix(int rows, int cols, const std::vector<std::vector<T> >& array);			//用二维数组构造矩阵
	Matrix(int rows, int cols, T** array);			//用二维数组构造矩阵
	Matrix(const Matrix& matrix);					
	~Matrix();

	int getCols() const { return m_cols; };              //获取列数  
	int getRows() const { return m_rows; };              //获取行数  
	int getSize() const { return m_rows * m_cols; };     //获取数组大小
	bool isSingular() { inverse(); return singular; };//判断矩阵是否奇异

	T& operator()(int row, int col);					 //括号操作符重载，用于获取矩阵第row行第col列元素 

	bool LUP_Descomposition(Matrix<double>& A, Matrix<double>& L, Matrix<double>& U, Matrix<double>& P);//LUP分解
	Matrix<double> LUP_Solve(Matrix<double>& L, Matrix<double>& U, Matrix<double>& P, Matrix<double>& b);//LUP求解线性方程
	Matrix<T>  transpose();                                //矩阵转置
	Matrix<double>  inverse();                             //LU分解求逆矩阵 
	Matrix<T>& operator=(const Matrix& matrix);            //矩阵的赋值操作符重载
	Matrix<T>& operator=(T arr[]);
	Matrix<T>& operator+=(const Matrix& matrix);          //矩阵的加法操作符重载  
	Matrix<T>& operator+=(T val);                         //矩阵与数的加法操作符重载  
	Matrix<T>& operator-=(const Matrix& matrix);          //矩阵的减法操作符重载  
	Matrix<T>& operator-=(T val);                         //矩阵与数的减法操作符重载  
	Matrix<T>& operator*=(const Matrix& matrix);          //矩阵的乘法操作符重载  
	Matrix<T>& operator*=(T val);                         //矩阵与数的乘法操作符重载  
	Matrix<T>& operator/=(const Matrix& matrix);          //矩阵的逐元素除法操作符重载  
	Matrix<T>& operator/=(T val);                         //矩阵与数的除法操作符重载

public:
	template  <class ElemType>
	friend Matrix<ElemType>  operator+(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2);//矩阵与矩阵加法+操作符重载
	template  <class ElemType>
	friend Matrix<ElemType>  operator-(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2);//矩阵与矩阵减法-操作符重载
	template  <class ElemType>
	friend Matrix<ElemType>  operator*(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2);//矩阵与矩阵乘法*操作符重载
	template  <class ElemType>
	friend Matrix<ElemType>  operator/(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2);//矩阵与矩阵逐元素除法/操作符重载
	template  <class ElemType>
	friend Matrix<ElemType>  operator+(const Matrix<ElemType>& matrix, const ElemType val);      //矩阵与数加法+操作符重载（1）
	template  <class ElemType>
	friend Matrix<ElemType>  operator+(const ElemType val, const Matrix<ElemType>& matrix);      //矩阵与数加法+操作符重载（2）
	template  <class ElemType>
	friend Matrix<ElemType>  operator-(const Matrix<ElemType>& matrix, const ElemType val);      //矩阵与数减法-操作符重载（1）
	template  <class ElemType>
	friend Matrix<ElemType>  operator-(const ElemType val, const Matrix<ElemType>& matrix);      //矩阵与数减法-操作符重载（2）
	template  <class ElemType>
	friend Matrix<ElemType>  operator*(const Matrix<ElemType>& matrix, const ElemType val);      //矩阵与数乘法*操作符重载（1）
	template  <class ElemType>
	friend Matrix<ElemType>  operator*(const ElemType val, const Matrix<ElemType>& matrix);      //矩阵与数乘法*操作符重载（2）
	template  <class ElemType>
	friend Matrix<ElemType>  operator/(const Matrix<ElemType>& matrix, const ElemType val);      //矩阵与数除法/操作符重载（1）
	template  <class ElemType>
	friend Matrix<ElemType>  operator/(const ElemType val, const Matrix<ElemType>& matrix);      //矩阵与数除法/操作符重载（2）
	template  <class ElemType>
	friend std::ostream& operator<<(std::ostream& os, const Matrix<ElemType>& matrix); //向输出流输出矩阵
};

//默认构造函数
template  <class T>
Matrix<T>::Matrix()
{
	m_cols = 0;
	m_rows = 0;
	m_size = 0;
	m_pData = nullptr;
}

/*
*构造函数
*rows: 行数
*cols: 列数
*val:  初始值，默认为1
*/
template  <class T>
Matrix<T>::Matrix(int rows, int cols, T val)
{
	m_cols = cols;
	m_rows = rows;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	for (int i = 0; i < m_size; i++)
		m_pData[i] = val;
}

/*
*方阵
*row_col 行列数
*val:初始值，默认为1
*/
template  <class T>
Matrix<T>::Matrix(int rows_cols, T val)
{
	m_cols = m_rows = rows_cols;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	for (int i = 0; i < m_cols; i++)
	{
		for (int j = 0; j < m_rows; j++)
		{
			m_pData[i * m_rows + j] = (j == i ? val : 0);
		}
	}
}

/*
*构造函数
*rows: 行数
*cols: 列数
*array:一维列表
*isRowFirst:是否奇异
*/
template  <class T>
Matrix<T>::Matrix(int rows, int cols, const std::vector<T>& array, bool isRowFirst)
{
	m_cols = cols;
	m_rows = rows;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	if (m_size != array.size()) {
		std::cerr << "vector m_size is not equal with the matrix!" << std::endl;
		return;
	}
	if (isRowFirst == false) {
		for (int i = 0; i < m_size; i++) {
			m_pData[i] = array[i];
		}
	}
	else {
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_cols; j++) {
				m_pData[j * m_rows + i] = array[i * m_cols + j];
			}
	}
}

/*
*构造函数
*rows: 行数
*cols: 列数
*array:一维列表
*isRowFirst:是否奇异
*/
template<class T>
inline Matrix<T>::Matrix(int rows, int cols, T* array, bool isRowFirst)
{
	m_cols = cols;
	m_rows = rows;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	if (isRowFirst == false) {
		for (int i = 0; i < m_size; i++) {
			m_pData[i] = array[i];
		}
	}
	else {
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < m_cols; j++) {
				m_pData[j * m_rows + i] = array[i * m_cols + j];
			}
	}
}
/*
*构造函数
*rows: 行数
*cols: 列数
*array:二维列表
*isRowFirst:是否奇异
*/
template  <class T>
Matrix<T>::Matrix(int rows, int cols, const std::vector<std::vector<T>>& array)
{
	m_cols = cols;
	m_rows = rows;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	for (int i = 0; i < m_cols; i++)
		for (int j = 0; j < m_rows; j++)
			m_pData[i * m_rows + j] = array[j][i];
}
/*
*构造函数
*matrix 矩阵
*/
template  <class T>
Matrix<T>::Matrix(const Matrix& matrix)
{
	m_cols = matrix.m_cols;
	m_rows = matrix.m_rows;
	m_size = m_cols * m_rows;
	m_pData = new T[m_size];
	for (int i = 0; i < m_size; i++)
		m_pData[i] = matrix.m_pData[i];
}

template<class T>
inline Matrix<T>::~Matrix()
{
	if (m_pData)
		delete[] m_pData;
}


template  <class T>
T& Matrix<T>::operator()(int row, int col)
{
	return m_pData[(col-1) * (m_rows - 1) + row - 1];
}

//矩阵输出  
template  <class ElemType>
std::ostream& operator<<(std::ostream& os, const Matrix<ElemType>& matrix)
{
	for (int i = 0; i < matrix.m_rows; i++)
	{
		for (int j = 0; j < matrix.m_cols; j++)
		{
			os << std::setprecision(6)<<matrix.m_pData[j * matrix.m_rows + i];
			if (j != matrix.m_cols - 1)
				os << ",";
		}
		os << ";" << std::endl;
	}
	return os;
}

//矩阵转置
template  <class T>
Matrix<T> Matrix<T>::transpose()
{
	Matrix<T> res(m_cols, m_rows, 0);
	for (int i = 0; i < m_cols; i++)
		for (int j = 0; j < m_rows; j++)
			res(i, j) = m_pData[i * m_rows + j];
	return res;
}

//操作符 = 重载
template  <class T>
Matrix<T>& Matrix<T>::operator=(const Matrix& matrix)
{
	//一定要创建临时矩阵，防止同一矩阵赋值（重新分配内存的同时，已经将此矩阵改变！！！！！！）  
	if (this == &matrix)
	{
		return *this;
	}
	m_cols = matrix.m_cols;
	m_rows = matrix.m_rows;
	m_size = m_cols * m_rows;
	delete[] m_pData;
	m_pData = new T[m_size];
	for (int i = 0; i < m_size; i++)
		m_pData[i] = matrix.m_pData[i];
	return *this;
}

template<class T>
inline Matrix<T>& Matrix<T>::operator=(T arr[])
{
	for (int i = 0; i < m_size; i++)
		m_pData[i] = arr[i];
	return *this;
}

//操作符 += 重载(矩阵加)  
template  <class T>
Matrix<T>& Matrix<T>::operator+=(const Matrix& matrix)
{
	if (m_cols != matrix.m_cols || m_rows != matrix.m_rows)
	{
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator+=)" << std::endl;
		return *this;
	}
	else if (typeid(matrix.m_pData).name() != typeid(m_pData).name())
	{
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator+=)" << std::endl;
		return *this;
	}
	else
	{
		for (int i = 0; i < m_size; i++)
			m_pData[i] += matrix.m_pData[i];
		return *this;
	}
}

//操作符 +＝ 重载(数加)  
template  <class T>
Matrix<T>& Matrix<T>::operator+=(T val)
{
	for (int i = 0; i < this->m_size; i++)
		this->m_pData[i] += val;
	return *this;
}
 
//操作符 -= 重载(矩阵减) 
template  <class T>
Matrix<T>& Matrix<T>::operator-=(const Matrix& matrix)
{
	if (m_cols != matrix.m_cols || m_rows != matrix.m_rows)
	{
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator-=)" << std::endl;
		return *this;
	}
	else if (typeid(matrix.m_pData).name() != typeid(m_pData).name())
	{
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator-=)" << std::endl;
		return *this;
	}
	else
	{
		for (int i = 0; i < m_size; i++)
			m_pData[i] -= matrix.m_pData[i];
		return *this;
	}
}

//操作符 -= 重载(数减)  
template  <class T>
Matrix<T>& Matrix<T>::operator-=(T val)
{
	for (int i = 0; i < this->m_size; i++)
		this->m_pData[i] -= val;
	return *this;
}

//操作符 *= 重载(矩阵乘)  
template  <class T>
Matrix<T>& Matrix<T>::operator*=(const Matrix& matrix)
{
	if (m_cols != matrix.m_rows) {
		std::cerr << "Error:The m_cols of matrix1 is not equal to the m_rows of matrix2, and can not be multiplied.(matrix::operator*=)" << std::endl;
		return *this;
	}
	else if (typeid(matrix.m_pData).name() != typeid(m_pData).name()) {
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator*=)" << std::endl;
		return *this;
	}
	else{
		int res_size = m_rows * matrix.m_cols;
		T* res_data = new T[res_size];
		for (int i = 0; i < m_rows; i++)
			for (int j = 0; j < matrix.m_cols; j++)
			{
				T temp = 0.0;
				for (int k = 0; k < m_cols; k++)
				{
					temp += m_pData[k * m_rows + i] * matrix.m_pData[j * matrix.m_rows + k];
					res_data[j * m_rows + i] = temp;
				}
			}
		m_cols = matrix.m_cols;
		m_size = res_size;
		delete[] m_pData;
		m_pData = new T[m_size];
		for (int i = 0; i < m_size; i++)
			m_pData[i] = res_data[i];
		delete[] res_data;
		return *this;
	}
}

//操作符 *= 重载(数乘)  
template  <class T>
Matrix<T>& Matrix<T>::operator*=(T val)
{
	for (int i = 0; i < this->m_size; i++)
		this->m_pData[i] *= val;
	return *this;
}

//操作符 /= 重载(矩阵逐元素除)  
template  <class T>
Matrix<T>& Matrix<T>::operator/=(const Matrix& matrix)
{
	if (m_cols != matrix.m_cols || m_rows != matrix.m_rows){
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator/=)" << std::endl;
		return *this;
	}
	else if (typeid(matrix.m_pData).name() != typeid(m_pData).name()){
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator/=)" << std::endl;
		return *this;
	}
	else{
		for (int i = 0; i < m_size; i++)
			m_pData[i] /= matrix.m_pData[i];
		return *this;
	}
}

//操作符 /= 重载(数除)  
template  <class T>
Matrix<T>& Matrix<T>::operator/=(T val)
{
	for (int i = 0; i < this->m_size; i++)
		this->m_pData[i] /= val;
	return *this;
}

//操作符 + 重载(矩阵加)  
template  <class ElemType>
Matrix<ElemType>  operator+(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2)
{
	Matrix<ElemType> res(matrix1);
	if (matrix1.m_cols != matrix2.m_cols || matrix1.m_rows != matrix2.m_rows)
	{
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator+)" << std::endl;
	}
	else if (typeid(matrix1.m_pData).name() != typeid(matrix2.m_pData).name())
	{
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator+)" << std::endl;
	}
	else
	{
		for (int i = 0; i < matrix1.m_size; i++)
			res.m_pData[i] = matrix1.m_pData[i] + matrix2.m_pData[i];
	}
	return res;
}

//操作符 - 重载(矩阵减)  
template  <class ElemType>
Matrix<ElemType>  operator-(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2)
{
	Matrix<ElemType> res(matrix1);
	if (matrix1.m_cols != matrix2.m_cols || matrix1.m_rows != matrix2.m_rows)
	{
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator-)" << std::endl;
	}
	else if (typeid(matrix1.m_pData).name() != typeid(matrix2.m_pData).name())
	{
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator-)" << std::endl;
	}
	else
	{
		for (int i = 0; i < matrix1.m_size; i++)
			res.m_pData[i] = matrix1.m_pData[i] - matrix2.m_pData[i];
	}
	return res;
}

//操作符 * 重载(矩阵乘)  
template  <class ElemType>
Matrix<ElemType>  operator*(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2)
{
	Matrix<ElemType> res(matrix1.m_rows, matrix2.m_cols,1);
	if (matrix1.m_cols != matrix2.m_rows) {
		std::cerr << "Error:The m_cols of matrix1 is not equal to the m_rows of matrix2, and can not be multiplied.(matrix::operator*)" << std::endl;
		return res;
	}
	else if (typeid(matrix1.m_pData).name() != typeid(matrix2.m_pData).name()) {
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator*)" << std::endl;
		return res;
	}
	else
	{
		for (int i = 0; i < matrix1.m_rows; i++)
			for (int j = 0; j < matrix2.m_cols; j++)
			{
				ElemType temp = 0.0;
				for (int k = 0; k < matrix1.m_cols; k++)
				{
					temp += matrix1.m_pData[k * matrix1.m_rows + i] * matrix2.m_pData[j * matrix2.m_rows + k];
					res.m_pData[j * matrix1.m_rows + i] = temp;
				}
			}
		return res;
	}
}

//操作符 / 重载(矩阵逐元素除)  
template  <class ElemType>
Matrix<ElemType>  operator/(const Matrix<ElemType>& matrix1, const Matrix<ElemType>& matrix2)
{
	Matrix<ElemType> res(matrix1);
	if (matrix1.m_cols != matrix2.m_cols || matrix1.m_rows != matrix2.m_rows)
	{
		std::cerr << "Error:The number of m_rows or columns is not equal(matrix::operator/)" << std::endl;
	}
	else if (typeid(matrix1.m_pData).name() != typeid(matrix2.m_pData).name())
	{
		std::cerr << "Error:Different types of matrix m_pData(matrix::operator/)" << std::endl;
	}
	else
	{
		for (int i = 0; i < matrix1.m_size; i++)
			res.m_pData[i] = matrix1.m_pData[i] / matrix2.m_pData[i];
	}
	return res;
}

//操作符 + 重载(数加1)  
template  <class ElemType>
Matrix<ElemType>  operator+(const Matrix<ElemType>& matrix, const ElemType val)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] += val;
	return matrix;
}
//操作符 + 重载(数加2)
template  <class ElemType>
Matrix<ElemType>  operator+(const ElemType val, const  Matrix<ElemType>& matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] += val;
	return matrix;
}
//操作符 - 重载(数减1)  
template  <class ElemType>
Matrix<ElemType>  operator-(const Matrix<ElemType>& matrix, const ElemType val)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] -= val;
	return matrix;
}
//操作符 - 重载(数减2)
template  <class ElemType>
Matrix<ElemType>  operator-(const ElemType val, const  Matrix<ElemType>& matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] = val - matrix.m_pData[i];
	return matrix;
}
//操作符 * 重载(数乘1)  
template  <class ElemType>
Matrix<ElemType>  operator*(const Matrix<ElemType>& matrix, const ElemType val)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] *= val;
	return matrix;
}
//操作符 * 重载(数乘2)
template  <class ElemType>
Matrix<ElemType>  operator*(const ElemType val, const  Matrix<ElemType>& matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] *= val;
	return matrix;
}
//操作符 / 重载(数除1)  
template  <class ElemType>
Matrix<ElemType>  operator/(const Matrix<ElemType>& matrix, const ElemType val)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] /= val;
	return matrix;
}


//操作符 / 重载(数除2)
template  <class ElemType>
Matrix<ElemType>  operator/(const ElemType val, const  Matrix<ElemType>& matrix)
{
	for (int i = 0; i < matrix.m_size; i++)
		matrix.m_pData[i] = val / matrix.m_pData[i];
	return matrix;
}

//LUP分解
template  <class T>
bool Matrix<T>::LUP_Descomposition(Matrix<double>& A, Matrix<double>& L, Matrix<double>& U, Matrix<double>& P)
{
	int N = P.getSize();
	int row = 0;
	for (int i = 0; i < N; i++) {
		P(0, i) = i;
	}
	for (int i = 0; i < N - 1; i++) {
		double p = 0.0;
		for (int j = i; j < N; j++) {
			if (fabs(A(j, i)) > p) {
				p = fabs(A(j, i));
				row = j;
			}
		}
		if (0 == p) {
			std::cerr << "Error:Matrix singularity and the inverse matrix is incalculable" << std::endl;
			return false;
		}

		//交换P[i]和P[row]
		double tmp = P(0, i);
		P(0, i) = P(0, row);
		P(0, row) = tmp;

		double tmp2 = 0;
		for (int j = 0; j < N; j++) {
			//交换A[i][j]和 A[row][j]
			tmp2 = A(i, j);
			A(i, j) = A(row, j);
			A(row, j) = tmp2;
		}

		//以下同LU分解
		double u = A(i, i), l = 0;
		for (int j = i + 1; j < N; j++) {
			l = A(j, i) / u;
			A(j, i) = l;
			for (int k = i + 1; k < N; k++) {
				A(j, k) = A(j, k) - A(i, k) * l;
			}
		}
	}

	//构造L和U
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (i != j) {
				L(i, j) = A(i, j);
			}
			else { 
				L(i, j) = 1;
			}
		}
		for (int k = i; k < N; k++) {
			U(i, k) = A(i, k);
		}
	}
	return true;
}
//LUP求解线性方程
template  <class T>
Matrix<double> Matrix<T>::LUP_Solve(Matrix<double>& L, Matrix<double>& U, Matrix<double>& P, Matrix<double>& b)
{
	int N = P.getSize();
	Matrix<double> x(1, N, 0.0);
	Matrix<double> y(1, N, 0.0);
	//正向替换
	for (int i = 0; i < N; i++)
	{
		y(0, i) = b(0, P(0, i));
		for (int j = 0; j < i; j++)
		{
			y(0, i) = y(0, i) - L(i, j) * y(0, j);
		}
	}
	//反向替换
	for (int i = N - 1; i >= 0; i--)
	{
		x(0, i) = y(0, i);
		for (int j = N - 1; j > i; j--)
		{
			x(0, i) = x(0, i) - U(i, j) * x(0, j);
		}
		x(0, i) /= U(i, i);
	}
	return x;
}

//LU分解求逆矩阵
template  <class T>
Matrix<double> Matrix<T>::inverse()
{
	int N = m_rows;
	Matrix<double> A_mirror(N, N, 0.0);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			A_mirror(i, j) = m_pData[j * m_rows + i];
	Matrix<double> A_inv(N, N, 0.0);
	Matrix<double> A_inv_each(1, N, 0.0);
	Matrix<double> b(1, N, 0.0);
	Matrix<double> L(N, N, 0.0);
	Matrix<double> U(N, N, 0.0);
	Matrix<double> P(1, N, 0.0);
	if (LUP_Descomposition(A_mirror, L, U, P) == false) {
		A_inv.singular = true;
		return A_inv;
	}
	for (int i = 0; i < N; i++)
	{
		//构造单位阵的每一列
		for (int i = 0; i < N; i++)
		{
			b(0, i) = 0;
		}
		b(0, i) = 1;
		A_inv_each = LUP_Solve(L, U, P, b);
		for (int j = 0; j < N; j++)A_inv(j, i) = A_inv_each(0, j);
	}
	return A_inv;
}

#define Reflection(a,axis_x,axis_y,axis_z) {\
		std::vector<int> vec= {  	\
		axis_x, 0,      0,		0,	\
		0,      axis_y, 0,		0,	\
		0,      0,      axis_z, 0, \
		0,0,0,1						\
};									\
a = Matrix(4, 4, vec);				\
}

#define Translation(a,axis_x,axis_y,axis_z)\
std::vector<int> vec = {				\
1,0,0,axis_x		\
0,1,0,axis_y		\
0,0,1,axis_z		\
0,0,0,1				\
};					\
a = Matrix(4, 4, vec);		\
}