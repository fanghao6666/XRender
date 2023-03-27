#pragma once

// XRenderEngine.h


namespace XRender
{
	class XRenderEngine
	{
	public:
		XRenderEngine();
		~XRenderEngine();

		
		bool			Init();
		void			Run();
		void			Update();
		void			Exit();

	protected:
		bool			InitWindow();


	private:


	};
}