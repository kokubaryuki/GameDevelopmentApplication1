#pragma once

//��Βl�����߂�
template<typename T>
T Abs(T value)
{
	T result;
	
	if (value > 0)
	{
		result = value;
	}
	else
	{
		result = -value;
	}
	return result;
}

//�������m���m�F���āA�傫���l�����߂�
template <typename T>
T MAX(T a, T b)
{
	T result;

	if (a < b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}


//�������m���m�F���āA�������l�����߂�
template<typename T>
T Min(T a, T b)
{
	T result;
	if (a > b)
	{
		result = b;
	}
	else
	{
		result = a;
	}
	return result;
}





