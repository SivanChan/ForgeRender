/********************************************************************
	created  :	2016/6/18
	author   :	Sivan
	source   :  ģ��
*********************************************************************/

#ifndef Forge_Model_hpp__
#define Forge_Model_hpp__

#pragma once

#include <Math/Math.hpp>
#include <vector>

namespace Forge
{
	enum RenderMode
	{
		RM_Line,
		RM_FillColor,
		RM_Texture
	};

	class Model
	{
	public:
		struct VertexData
		{
			float4 position;
			float2 texture;
			Color  color;
			float  rhw;
		};
		struct IndexData
		{
			uint32_t a;
			uint32_t b;
			uint32_t c;
		};

		Model();
		~Model();

		void Initialize(std::string const & mesh_file, std::string const & texture_file, RenderDevice * device);
		void SetRenderMode(RenderMode mode);
		void Render();

	protected:
		void InitMesh(std::string const & mesh_file);
		void InitTexture(std::string const & texture_file);
		void RenderTriangle(float4x4 const & wvp, VertexData & a, VertexData & b, VertexData & c);

		/**
			�ڹ���۲��壨CVV���н��ж���βü���������͸�ӳ��������÷���ֵ�����ж����ĸ������ϳ���CVV
		*/
		int  ClipInCVV(float4 const & p);

		/**
			�Զ������͸�ӳ�������ת��Ϊ��Ļ����
		*/
		float Homogenize(float4 & p);

		void MakeVertexRHW(VertexData & vd);

		void DrawLine(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2);
		void DrawPixel(uint32_t x, uint32_t y, uint32_t color);

	private:
		RenderMode              render_mode_;
		std::vector<VertexData> mesh_vb_;
		std::vector<IndexData>  mesh_ib_;
		uint32_t                texture_buffer_[256][256];
		RenderDevice*           device_;
		uint32_t                line_color_;
		uint32_t                count_;
	};
}

#endif // Forge_Model_hpp__