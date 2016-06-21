/********************************************************************
	created  :	2016/6/19
	author   :	Sivan
	source   :  ���
*********************************************************************/

#ifndef Forge_Camera_hpp__
#define Forge_Camera_hpp__

#pragma once

#include <Math/Math.hpp>

namespace Forge
{
	class Camera
	{
	public:
		Camera();
		~Camera();

		void SetViewParams(float3 const & eye_pos, float3 const & look_at, float3 const & up_vec);
		void SetProjParams(float fov, float aspect, float near_plane, float far_plane);

		float4x4 const & ViewMatrix() const;
		float4x4 const & ProjectionMatrix() const;
		float4x4 const & ViewProjMatrix() const;

	private:
		float fov_;               // Field of view
		float aspect_;
		float near_clip_;
		float far_clip_;

		mutable float4x4 view_mat_;        // ��ͼ����
		mutable float4x4 inv_view_mat_;    // ��ͼ���������
		mutable float4x4 proj_mat_;        // ͶӰ����
		mutable float4x4 inv_proj_mat_;    // ͶӰ���������
		mutable float4x4 view_proj_mat_;   // ��ͼͶӰ����

		mutable bool need_recalc_view_proj_;
	};
}

#endif // Forge_Camera_hpp__