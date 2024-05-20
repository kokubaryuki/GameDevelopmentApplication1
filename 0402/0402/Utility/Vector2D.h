#pragma once

class Vector2D
{
public:
	float x;//x座標
	float y;//Y座標

public:
	//コンストラクタ
	Vector2D();
	Vector2D(float scalar);
	Vector2D(float mx, float my);

	//デストラクタ
	~Vector2D();


public:

	//代入演算子
	Vector2D& operator=(const Vector2D& location);

	//加算
	const Vector2D operator+(const Vector2D& location) const;
	Vector2D& operator+=(const Vector2D& location);

	//減算
	const Vector2D operator-(const Vector2D& location) const;
	Vector2D& operator-=(const Vector2D& location);

	//乗算
	const Vector2D operator*(const float& scalar)const;
	const Vector2D operator*(const Vector2D& location)const;
	Vector2D& operator*=(const float& scalar);
	Vector2D& operator*=(const Vector2D& location);

	//除算
	const Vector2D operator/(const float& scalar)const;
	const Vector2D operator/(const Vector2D& location)const;
	Vector2D& operator/=(const float& scalar);
	Vector2D& operator/=(const Vector2D& location);

	//文字列を整数値に変換
	void ToInt(int* x, int* y)const;

};


