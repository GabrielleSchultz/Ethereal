#include "Entidade.h"

namespace Entidades {

	const float Entidade::gravidade(9.8f / 10);

	Entidade::Entidade(const char* texturePath, ID identidade, Math::Vector2Df pos) : Ente(),
		caminho_textura(texturePath),
		id(identidade),
		position(pos),
		tamanho(0, 0)
	{
		inicializar();
	}

	Entidades::Entidade::~Entidade()
	{
	}

	void Entidade::inicializar()
	{
		pGerenciadorGrafico->carregarTextura(caminho_textura);
		tamanho = pGerenciadorGrafico->getDimensao(caminho_textura);
	}

	void Entidade::aplicar_gravidade(float dt)
	{
		position.y += gravidade * dt;
	}

	void Entidade::executar(float dt)
	{
		aplicar_gravidade(dt);
		update(dt);
	}


	void Entidade::desenhar()
	{
		pGerenciadorGrafico->desenharEnte(caminho_textura, position);
	}

	void Entidade::salvarEntidade(nlohmann::ordered_json& entrada)
	{
		entrada["ID"] = id;
		entrada["posicao"] = {{"x", getPosition().x}, {"y", getPosition().y }};
	}

	void Entidade::carregarDadosEntidade(nlohmann::ordered_json& saida)
	{
		//lê a posicao de acordo com o arquivo, fazendo as devidas conversões
		setPosition(Math::Vector2Df(saida["posicao"]["x"].template get<float>(), saida["posicao"]["y"].template get<float>()));
	}

	void Entidade::setPosition(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	void Entidade::setPosition(Math::Vector2Df v)
	{
		setPosition(v.x, v.y);
	}

	void Entidade::setTamanho(float x, float y)
	{
		tamanho.x = x;
		tamanho.y = y;
	}

	Math::Vector2Df Entidade::getPosition() const
	{
		return position;
	}

	Math::Vector2Df Entidade::getTamanho() const
	{
		return tamanho;
	}

	ID Entidade::getId()
	{
		return id;
	}

}