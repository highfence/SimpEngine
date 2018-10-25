#pragma once

namespace SimpEngineLib
{
	class Dx11Renderer final : public ISimpRenderer
	{
	public:
		Dx11Renderer();
		~Dx11Renderer();

		void Do() override;

	private :
	};

}
