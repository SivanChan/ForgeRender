/********************************************************************
	created:	2014/05/10
	created:	2014/5/10   17:47
	filename: 	Math.hpp
	author:		Sivan
	purpose:	��ѧ��
*********************************************************************/

#ifndef Forge_Math_hpp__
#define Forge_Math_hpp__

#pragma once

#include <PreDeclare.h>

namespace Forge
{
	// ��ѧ����
	float const FORGE_PI      = 3.14159265f;              // ��    //float(4.0f * std::atan(1.0));
	float const FORGE_2PI     = float(FORGE_PI * 2.0);    // 2��
	float const FORGE_PIdiv2  = float(FORGE_PI * 0.5);    // ��/2
	float const FORGE_1divPI  = float(1.0f / FORGE_PI);   // 1/��
	float const FORGE_1div2PI = float(1.0f / FORGE_2PI);  // 1/2��

	float const DEG2RAD	= 0.01745329f;			          // �ǶȻ���������
	float const RAD2DEG	= 57.29577f;			          // ���Ȼ��Ƕ�����

	enum BoundIntersection
	{
		BI_Outside,
		BI_Inside,
		BI_Intersecting
	};

	// ��ѧ����
	namespace Math
	{
		// �������
		template<typename T>
		inline T const & max3(T const & x, T const & y, T const & z)
		{
			return (std::max)((std::max)(x, y), z);
		}

		// ������С
		template<typename T>
		inline T const & min3(T const & x, T const & y, T const & z)
		{
			return (std::min)((std::min)(x, y), z);
		}

		// С�ڵ���x���������
		template<typename T>
		inline T floor(T const & x)
		{
			return static_cast<T>(static_cast<int>(x > 0 ? x : (x - 1)));
		}

		// �ж�value�Ƿ���low��high֮��
		template<typename T>
		inline bool in_bound(T const & value, T const & low, T const & high)
		{
			return ((value >= low) && (value <= high));
		}

		// ���� val �� low �� high ֮��
		template <typename T>
		inline T const & clamp(T const & val, T const & low, T const & high)
		{
			return (std::max)(low, (std::min)(high, val));
		}

		// ƽ��
		template<typename T>
		inline T sqr(T const & x)
		{
			return x * x;
		}

		// ����ת�Ƕ�
		template<typename T>
		inline T degree_to_radian(T const & x)
		{
			return static_cast<T>(x * DEG2RAD);
		}

		// �Ƕ�ת����
		template<typename T>
		inline T radian_to_degree(T const & x)
		{
			return static_cast<T>(x * RAD2DEG);
		}

		// ����
		template<typename T>
		inline T cube(T const & x)
		{
			return x * x * x;
		}

		// �󳤶�
		template<typename T>
		inline T length(Vector2_T<T> const & rhs)
		{
			return (T)std::sqrt(rhs.x() * rhs.x() + rhs.y() * rhs.y());
		}

		template<typename T>
		inline T length(Vector3_T<T> const & rhs)
		{
			return (T)std::sqrt(rhs.x() * rhs.x() + rhs.y() * rhs.y() + rhs.z() * rhs.z());
		}

		// ���ȵ�ƽ��
		template<typename T>
		inline T squared_length(Vector2_T<T> const & rhs)
		{
			return (T)(rhs.x() * rhs.x() + rhs.y() * rhs.y());
		}

		template<typename T>
		inline T squared_length(Vector3_T<T> const & rhs)
		{
			return (T)(rhs.x() * rhs.x() + rhs.y() * rhs.y() + rhs.z() * rhs.z());
		}

		template<typename T>
		inline T squared_length(Vector4_T<T> const & rhs)
		{
			return (T)(rhs.x() * rhs.x() + rhs.y() * rhs.y() + rhs.z() * rhs.z() + rhs.w() * rhs.w());
		}

		template<typename T>
		inline T squared_length(Plane_T<T> const & rhs)
		{
			return (T)(rhs.a() * rhs.a() + rhs.b() + rhs.b() + rhs.c() * rhs.c());
		}

		template<typename T>
		inline T squared_length(Quaternion_T<T> const & rhs)
		{
			return (T)(rhs.x() * rhs.x() + rhs.y() * rhs.y() + rhs.z() * rhs.z() + rhs.w() * rhs.w());
		}

		// ����
		template<typename T, typename U>
		inline void swap(T & lhs, U & rhs)
		{
			T val(lhs);
			lhs = rhs;
			rhs = val;
		}

		template<typename T>
		inline void swap(Vector2_T<T> & lhs, Vector2_T<T> & rhs)
		{
			lhs.Swap(rhs);
		}

		template<typename T>
		inline void swap(Vector3_T<T> & lhs, Vector3_T<T> & rhs)
		{
			lhs.Swap(rhs);
		}

		template<typename T>
		inline void swap(Vector4_T<T> & lhs, Vector4_T<T> & rhs)
		{
			lhs.Swap(rhs);
		}

		// 
		template<typename T>
		T recip_sqrt(T const & rhs)
		{
			if ( rhs < std::numeric_limits<T>::epsilon() )
				return (T)0;
			return 1.0f / std::sqrt(rhs);
		}

		// ��һ��
		template<typename T>
		T normalize(T const & rhs)
		{
			return rhs * recip_sqrt(Math::squared_length(rhs));
		}

		// ���
		template<typename T>
		inline Vector3_T<T> cross_product(Vector3_T<T> const & lhs, Vector3_T<T> const & rhs)
		{
			return Vector3_T<T>( lhs.y() * rhs.z() - lhs.z() * rhs.y(),
				lhs.z() * rhs.x() - lhs.x() * rhs.z(),
				lhs.x() * rhs.y() - lhs.y() * rhs.x() );
		}

		template<typename T>
		Quaternion_T<T> cross_product(Quaternion_T<T> const & lhs, Quaternion_T<T> const & rhs)
		{
			return Quaternion_T<T>(
				lhs.w() * rhs.w() - lhs.x() * rhs.x() - lhs.y() * rhs.y() - lhs.z() * rhs.z(),
				lhs.w() * rhs.x() + lhs.x() * rhs.w() + lhs.z() * rhs.y() - lhs.y() * rhs.z(),
				lhs.w() * rhs.y() + lhs.y() * rhs.w() + lhs.x() * rhs.z() - lhs.z() * rhs.x(),
				lhs.w() * rhs.z() + lhs.z() * rhs.w() + lhs.y() * rhs.x() - lhs.x() * rhs.y() );
		}
		template Quaternion cross_product(Quaternion const & lhs, Quaternion const & rhs);

		// ���
		template<typename T>
		inline T dot_product(Vector3_T<T> const & lhs, Vector3_T<T> const & rhs)
		{
			return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
		}

		// vector matrix ���
		template<typename T>
		Vector4_T<T> mul(Vector4_T<T> const & v, Matrix4x4_T<T> const & m)
		{
			return Vector4_T<T>( 
				v.x() * m(0, 0) + v.y() * m(1, 0) + v.z() * m(2, 0) + v.w() * m(3, 0),
				v.x() * m(0, 1) + v.y() * m(1, 1) + v.z() * m(2, 1) + v.w() * m(3, 1),
				v.x() * m(0, 2) + v.y() * m(1, 2) + v.z() * m(2, 2) + v.w() * m(3, 2), 
				v.x() * m(0, 3) + v.y() * m(1, 3) + v.z() * m(2, 3) + v.w() * m(3, 3) );
		}

		/** �ཻ���� */

		// �� - ��
		template<typename T>
		bool intersect(Sphere_T<T> const & lhs, Sphere_T<T> const & rhs);

		// �� - ��
		template<typename T>
		bool intersect(Sphere_T<T> const & s, Plane_T<T> const & p);

		// �� - ��Χ��
		template<typename T>
		bool intersect(Sphere_T<T> const & s, AABBox_T<T> const & b);

		// �� - ��
		template<typename T>
		bool intersect(Sphere_T<T> const & s, Vector3_T<T> const & p);

		// ��Χ�� - ��Χ��
		template<typename T>
		bool intersect(AABBox_T<T> const & lhs, AABBox_T<T> const & rhs);

		// ��Χ�� - ��
		template<typename T>
		bool intersect(AABBox_T<T> const & b, Vector3_T<T> const & p);

		// ���� - ��
		template<typename T>
		std::pair<bool,T> intersect(Ray_T<T> const & r, Plane_T<T> const & p);

		// ���� - �� From OGRE
		template<typename T>
		std::pair<bool,T> intersect(Ray_T<T> const & r, Sphere_T<T> const & s);

		// ���� - ��Χ�� From Gameplay
		template<typename T>
		std::pair<bool,T> intersect(Ray_T<T> const & r, AABBox_T<T> const & b);

		// �� - ��Χ��
		template<typename T>
		BoundIntersection intersect(Plane_T<T> const & p, AABBox_T<T> const & b);

		// ƽ��ͷ�� - ��Χ��
		template<typename T>
		BoundIntersection intersect(Frustum_T<T> const & f, AABBox_T<T> const & b);

		// ƽ��ͷ�� - ��
		template<typename T>
		BoundIntersection intersect(Frustum_T<T> const & f, Sphere_T<T> const & s);

		// ƽ��ͷ�� - ��
		template<typename T>
		bool intersect(Frustum_T<T> const & f, Vector3_T<T> const & p);


		//////////////////////////////////////////////////////////////////////////
		/// ��ά����
		template<typename T>
		Vector3_T<T> transform_quaternion(Vector3_T<T> const & v, Quaternion_T<T> const & q);
	
		//////////////////////////////////////////////////////////////////////////
		/// ��Ԫ��

		// ��Ԫ���Ĺ���
		template<typename T>
		Quaternion_T<T> conjugate(Quaternion_T<T> const & rhs);

		// ������ת�Ƕ�
		template<typename T>
		Quaternion_T<T> rotation_axis(Vector3_T<T> const & v, T const & angle);

		// 
		template <typename T>
		Quaternion_T<T> inverse(Quaternion_T<T> const & rhs);

		/** ���� */
		/// ת��
		template<typename T>
		Matrix4x4_T<T> transpose(Matrix4x4_T<T> const & m);

		/// ��Ԫ��ת����
		template<typename T>
		Matrix4x4_T<T> to_matrix(Quaternion_T<T> const & rhs);

		/// 3������ʽ
		template<typename T>
		T minor(Matrix4x4_T<T> const & m, T const r0, T const r1, T const r2,
			                              T const c0, T const c1, T const c2);
		/// ����ʽ
		template<typename T>
		T determinant(Matrix4x4_T<T> const & m);

		/// �����
		template<typename T>
		Matrix4x4_T<T> inverse(Matrix4x4_T<T> const & m);

		template<typename T>
		Matrix4x4_T<T> transformation(Vector3_T<T> const & pos, Vector3_T<T> const & scale, Quaternion_T<T> const & orientation);
	
		/**
			����ϵ��ͼ����

			zaxis = normal(At - Eye)
			xaxis = normal(cross(Up, zaxis))
			yaxis = cross(zaxis, xaxis)

			xaxis.x           yaxis.x           zaxis.x          0
			xaxis.y           yaxis.y           zaxis.y          0
			xaxis.z           yaxis.z           zaxis.z          0
			-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  1
		*/
		template<typename T>
		Matrix4x4_T<T> look_at_lh(Vector3_T<T> const & eye, Vector3_T<T> const & at, Vector3_T<T> const & up);

		/** 
			����ϵ��ͼ����

			zaxis = normal(Eye - At)
			xaxis = normal(cross(Up, zaxis))
			yaxis = cross(zaxis, xaxis)

			xaxis.x           yaxis.x           zaxis.x          0
			xaxis.y           yaxis.y           zaxis.y          0
			xaxis.z           yaxis.z           zaxis.z          0
			-dot(xaxis, eye)  -dot(yaxis, eye)  -dot(zaxis, eye)  1
		*/
		template<typename T>
		Matrix4x4_T<T> look_at_rh(Vector3_T<T> const & eye, Vector3_T<T> const & at, Vector3_T<T> const & up);
	
		/// ����ϵ͸��ͶӰ����
		template<typename T>
		Matrix4x4_T<T> perspective_fov_lh(T const fov, T const aspect, T const zn, T const zf);

		/// ����ϵ͸��ͶӰ����
		template<typename T>
		Matrix4x4_T<T> perspective_fov_rh(T const fov, T const aspect, T const zn, T const zf);

		/// ����ϵ����ͶӰ����
		template<typename T>
		Matrix4x4_T<T> ortho_lh(T const w, T const h, T const zn, T const zf);

		/// ����ϵ����ͶӰ����
		template<typename T>
		Matrix4x4_T<T> ortho_rh(T const w, T const h, T const zn, T const zf);
	}
}

#include <Math/Vector2.hpp>
#include <Math/Vector3.hpp>
#include <Math/Vector4.hpp>
#include <Math/Matrix4x4.hpp>
#include <Math/AABBox.hpp>
#include <Math/Sphere.hpp>
#include <Math/Color.hpp>
#include <Math/Plane.hpp>
#include <Math/Frustum.hpp>
#include <Math/Size.hpp>
#include <Math/Rect.hpp>
#include <Math/Ray.hpp>
#include <Math/Quaternion.hpp>
#include <Math/Math.inl>

#endif // Forge_Math_hpp__