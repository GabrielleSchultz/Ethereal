#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"

#include <map>
#include <string>

class Ente;

//gerenciador gr�fico baseado no tutorial do Matheus Burda!

//ps:o nome da classe de cada gerenciador se da pela sua fun�ao
//sua chamada por namespace ja nos diz que se trata de um gerenciador

typedef std::map <const char*, sf::Texture*> MapaTextura;

namespace Gerenciadores
{
	class Grafico
	{
	private:
		MapaTextura CharactersTextures;
		MapaTextura FontTextures;
		sf::RenderWindow* janelaPrincipal;
		sf::View cameraJogo;

		//Padr�o de Projeto Singleton:
		Grafico();
		static Gerenciadores::Grafico* instancia_pGG;

	public:
		~Grafico();
		static Grafico* getGerenciador_Grafico();

		//janela e camera
		bool isWindowOpen();
		void clearWindow(); //cor default (preto)
		void clearWindow(sf::Color color);
		void displayWindow();
		void centralizarCamera(Math::Vector2Df center);
		void setWindowTitle(std::string titulo);
		void closeWindow();
		void zoomOut(float coef);
		void zoomIn(float coef);
		sf::RenderWindow* getWindow();

		//geracao de mundo
		bool criarMapa(std::string file_path);

		//render
		void desenharEnte(std::string filePath, Math::Vector2Df pos);
		bool carregarTextura(std::string filePath);
	};
}
