#pragma once
// Math.h
// Created by Haony 2023/4/2

#include <DirectXMath.h>

namespace XRender
{
	const float EPSILON = 1.192092896e-07f;

// Vector2
	template<class T>
	struct Vector2
	{
		T x;
		T y;

		Vector2() = default;
		Vector2(const Vector2& rhs) = default;
		Vector2& operator=(const Vector2& rhs) = default;

		Vector2(const T& value) : x(value), y(value) { }
		Vector2(const T& _x, const T& _y) : x(_x), y(_y) { }

		void Set(const T& value)
		{
			x = value;
			y = value;
		}

		void Set(const T& _x, const T& _y)
		{
			x = _x;
			y = _y;
		}

		bool operator==(const Vector2& rhs) const
		{
			T diffx = x - rhs.x;
			T diffy = y - rhs.y;

			if (diffx > EPSILON || diffx < -EPSILON || diffy > EPSILON || diffy < -EPSILON)
			{
				return false;
			}
			return true;
		}

		bool operator!=(const Vector2& rhs) const
		{
			return !this->operator==(rhs);
		}

		Vector2 operator-() const
		{
			return Vector2(-x, -y);
		}

		Vector2 operator+(const Vector2& rhs) const
		{
			return Vector2(x + rhs.x, y + rhs.y);
		}

		Vector2& operator+=(const Vector2& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			return *this;
		}

		Vector2 operator-(const Vector2& rhs) const
		{
			return Vector2(x - rhs.x, y - rhs.y);
		}

		Vector2& operator-=(const Vector2& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			return *this;
		}

		Vector2 operator*(const T& value) const
		{
			return Vector2(x * value, y * value);
		}

		Vector2& operator*=(const Vector2& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			return *this;
		}

		Vector2 operator/(const T& value) const
		{
			return Vector2(x / value, y / value);
		}

		Vector2& operator/=(const Vector2& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			return *this;
		}

		T Dot(const Vector2& rhs)
		{
			return x * rhs.x + y * rhs.y;
		}

		T LengthSqr()
		{
			return x * x + y * y;
		}

		T Length()
		{
			return sqrt(LengthSqr());
		}

		Vector2& Normalize()
		{
			T length = Length();
			if (length > EPSILON)
			{
				this->operator/=(length);
			}
			else
			{
				this->Set(0);
			}
			return *this;
		}

		T Distance(const Vector2& rhs)
		{
			Vector2 distVec = *this - rhs;
			return distVec.Length();
		}

		T DistanceSqr(const Vector2& rhs)
		{
			Vector2 distVec = *this - rhs;
			return distVec.LengthSqr();
		}
	};

	using Vector2f = Vector2<float>;

// Vector3
	template<class T>
	struct Vector3
	{
		T x;
		T y;
		T z;

		Vector3() = default;
		Vector3(const Vector3& rhs) = default;
		Vector3& operator=(const Vector3& rhs) = default;
		
		Vector3(const T& value) : x(value), y(value), z(value) { }
		Vector3(const T& _x,const T& _y,const T& _z) : x(_x), y(_y), z(_z){ }

		void Set(const T& value)
		{
			x = value;
			y = value;
			z = value;
		}

		void Set(const T& _x, const T& _y, const T& _z)
		{
			x = _x;
			y = _y;
			z = _z;
		}
				
		bool operator==(const Vector3& rhs) const
		{
			T diffx = x - rhs.x;
			T diffy = y - rhs.y;
			T diffz = z - rhs.z;

			if (diffx > EPSILON || diffx < -EPSILON || diffy > EPSILON || diffy < -EPSILON || diffz > EPSILON || diffz < -EPSILON)
			{
				return false;
			}
			return true;
		}

		bool operator!=(const Vector3& rhs) const
		{
			return !this->operator==(rhs);
		}

		Vector3 operator-() const
		{
			return Vector3(-x, -y, -z);
		}

		Vector3 operator+(const Vector3& rhs) const
		{
			return Vector3(x + rhs.x, y + rhs.y, z + rhs.z);
		}

		Vector3& operator+=(const Vector3& rhs)
		{
			x += rhs.x;
			y += rhs.y;
			z += rhs.z;
			return *this;
		}

		Vector3 operator-(const Vector3& rhs) const
		{
			return Vector3(x - rhs.x, y - rhs.y, z - rhs.z);
		}

		Vector3& operator-=(const Vector3& rhs)
		{
			x -= rhs.x;
			y -= rhs.y;
			z -= rhs.z;
			return *this;
		}

		Vector3 operator*(const T& value) const
		{
			return Vector3(x * value, y * value, z * value);
		}

		Vector3& operator*=(const Vector3& rhs)
		{
			x *= rhs.x;
			y *= rhs.y;
			z *= rhs.z;
			return *this;
		}

		Vector3 operator/(const T& value) const
		{
			return Vector3(x / value, y / value, z / value);
		}

		Vector3& operator/=(const Vector3& rhs)
		{
			x /= rhs.x;
			y /= rhs.y;
			z /= rhs.z;
			return *this;
		}

		T Dot(const Vector3& rhs)
		{
			return x * rhs.x + y * rhs.y + z * rhs.z;
		}

		Vector3 Cross(const Vector3& rhs)
		{
			return Vector3(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z, x * rhs.y - y * rhs.x);
		}

		T LengthSqr()
		{
			return x * x + y * y + z * z;
		}

		T Length()
		{
			return sqrt(LengthSqr());
		}

		Vector3& Normalize()
		{
			T length = Length();
			if (length > EPSILON)
			{
				this->operator/=(length);
			}
			else
			{
				this->Set(0);
			}
			return *this;
		}

		T Distance(const Vector3& rhs)
		{
			Vector3 distVec = *this - rhs;
			return distVec.Length();
		}

		T DistanceSqr(const Vector3& rhs)
		{
			Vector3 distVec = *this - rhs;
			return distVec.LengthSqr();
		}
	};

	using Vector3f = Vector3<float>;


	inline DirectX::XMFLOAT3 ToDXFloat3(const Vector3f& vec3)
	{
		return DirectX::XMFLOAT3(vec3.x, vec3.y, vec3.z);
	}

	inline DirectX::XMVECTOR ToDXVector3(const Vector3f& vec3)
	{
		DirectX::XMFLOAT3 flt3 = ToDXFloat3(vec3);
		return DirectX::XMLoadFloat3(&flt3);
	}

	inline Vector3f ToVector3(const DirectX::XMFLOAT3& dxvec3)
	{
		return Vector3f(dxvec3.x, dxvec3.y, dxvec3.z);
	}

	inline Vector3f ToVector3(const DirectX::XMVECTOR& dxvec3)
	{
		DirectX::XMFLOAT3 flt3;
		DirectX::XMStoreFloat3(&flt3, dxvec3);
		return ToVector3(flt3);
	}

}