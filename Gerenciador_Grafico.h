#pragma once
#include <SFML/Graphics.hpp>
#include "Vector2D.h"

#include <map>
#include <string>

//gerenciador gráfico baseado no tutorial do Matheus Burda!

//ps:o nome da classe de cada gerenciador se da pela sua funçao
//sua chamada por namespace ja nos diz que se trata de um gerenciador

class Ente;

typedef std::map <const std::string, sf::Texture*> MapaTextura;

namespace Gerenciadores
{
	class Grafico
	{
	private:
		MapaTextura EntityTextures;
		MapaTextura FontTextures;
		sf::RenderWindow* janelaPrincipal;
		sf::View cameraJogo;

		//Padrão de Projeto Singleton:
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
		bool foraDaCamera(Math::Vector2Df pos, sf::Vector2u size);

		//geracao de mundo
		//bool criarMapa(const std::string file_path);

		//render
		void desenharEnte(const std::string filePath, Math::Vector2Df pos);
		void desenhar(const std::string filePath, Math::Vector2Df pos);
		// pro botao
		void desenharForma(Math::Vector2Df pos, Math::Vector2Df tam, const std::string filePath);
		void desenharTexto(sf::Text t);
		bool carregarTextura(const std::string filePath);
		void deletarTexturas();
		Math::Vector2Df getDimensao(std::string texturePath);
	};
}
