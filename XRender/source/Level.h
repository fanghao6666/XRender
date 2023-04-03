// Level.h
// // Created by Haony 2023/4/3

#include "Component.h"
#include <string>

namespace XRender
{
	class XRenderEngine;


	class Level : public Component 
	{
	public:
		Level(XRenderEngine* engine,const std::string& levelName);
		virtual ~Level();

		virtual bool			Init() override;
		virtual void			Update() override;

	private:
		XRenderEngine*			mEngine;


	};

}