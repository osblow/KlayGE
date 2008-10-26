// OGLRenderEngine.hpp
// KlayGE OpenGL渲染引擎类 头文件
// Ver 3.4.0
// 版权所有(C) 龚敏敏, 2003-2006
// Homepage: http://klayge.sourceforge.net
//
// 3.4.0
// 增加了TexelToPixelOffset (2006.8.27)
//
// 3.3.0
// 只支持OpenGL 2.0 (2006.5.21)
//
// 3.0.0
// 去掉了固定流水线 (2005.8.18)
//
// 2.8.0
// 增加了RenderDeviceCaps (2005.7.17)
// 简化了StencilBuffer相关操作 (2005.7.20)
//
// 2.7.0
// 去掉了TextureCoordSet (2005.6.26)
// TextureAddressingMode, TextureFiltering和TextureAnisotropy移到Texture中 (2005.6.27)
//
// 2.4.0
// 增加了PolygonMode (2005.3.20)
//
// 修改记录
//////////////////////////////////////////////////////////////////////////////////

#ifndef _OGLRENDERENGINE_HPP
#define _OGLRENDERENGINE_HPP

#include <KlayGE/Vector.hpp>

#include <vector>
#include <map>
#include <boost/array.hpp>

#include <glloader/glloader.h>

#include <KlayGE/RenderEngine.hpp>
#include <KlayGE/ShaderObject.hpp>

namespace KlayGE
{
	class OGLRenderEngine : public RenderEngine
	{
	public:
		OGLRenderEngine();
		~OGLRenderEngine();

		std::wstring const & Name() const;

		void CreateRenderWindow(std::string const & name, RenderSettings const & settings);
		
		void StartRendering();

		void BeginFrame();
		void EndFrame();

		uint16_t StencilBufferBitDepth();

		void ScissorRect(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

		float4 TexelToPixelOffset() const
		{
			return float4(0, 0, 0, 0);
		}

		void Resize(uint32_t width, uint32_t height);
		bool FullScreen() const;
		void FullScreen(bool fs);

		void TexParameter(GLuint tex, GLenum target, GLenum pname, GLint param);
		void TexEnv(GLenum tex_unit, GLenum target, GLenum pname, GLfloat param);
		void ClearColor(GLfloat r, GLfloat g, GLfloat b, GLfloat a);
		void ClearDepth(GLfloat depth);
		void ClearStencil(GLuint stencil);

		void GetFBOForBlit(GLuint& src, GLuint& dst)
		{
			src = fbo_blit_src_;
			dst = fbo_blit_dst_;
		}

	private:
		void DoBindFrameBuffer(FrameBufferPtr const & fb);
		void DoRender(RenderTechnique const & tech, RenderLayout const & rl);

		void FillRenderDeviceCaps();
		void InitRenderStates();

	private:
		GLuint fbo_blit_src_;
		GLuint fbo_blit_dst_;

		boost::array<GLfloat, 4> clear_clr_;
		GLfloat clear_depth_;
		GLuint clear_stencil_;

		GLint vp_x_, vp_y_;
		GLsizei vp_width_, vp_height_;
	};

	typedef boost::shared_ptr<OGLRenderEngine> OGLRenderEnginePtr;
}

#endif			// _OGLRENDERENGINE_HPP
