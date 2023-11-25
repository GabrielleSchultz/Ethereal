#pragma once
#include "Thread.h"
#include "Vinganca.h"

//baseado fortemente no código disponibilizado pelo Peteco

namespace Entidades{
	namespace Personagens
	{
		namespace Inimigos
		{
			class Vinganca_Thread : public Vinganca, public Thread
			{
			private:
				bool novo_frame;
				void run();

			public:
				Vinganca_Thread(int nv = 200, int mal = 100, const char* texturePath = "Assets/Sprites/boss.png", ID id = ID::boss);
				~Vinganca_Thread();
				void novoFrame();
				void salvar();
			};


		}
	}
}
