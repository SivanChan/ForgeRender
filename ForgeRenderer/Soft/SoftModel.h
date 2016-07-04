/********************************************************************
	created:	2016/07/03
	created:	2016/7/3   15:11
	filename: 	SoftModel.h
	author:		Sivan
	purpose:	����Ⱦģ��
*********************************************************************/

#ifndef Forge_SoftModel_hpp__
#define Forge_SoftModel_hpp__

#pragma once

#include <Model.h>
#include <RenderDevice.h>

namespace Forge
{
	class SoftModel : public Model
	{
	public:
		SoftModel();
		~SoftModel();

		virtual void Initialize(std::string const & mesh_file, std::string const & texture_file, RenderDevice* device);
		virtual void SetRenderMode(RenderMode mode);
		virtual void Render();

	protected:
		virtual void InitTexture(std::string const & texture_file);

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
		uint32_t                texture_buffer_[256][256];			
	};
	typedef std::shared_ptr<SoftModel> SoftModelPtr;
}

#endif // Forge_SoftModel_hpp__