#pragmaonce

namespace Entidades {

    class Entidade : public Ente {
    private:
        int x;
        int y;

    public:
        Entidade();
        ~Entidade();
        int getX();
        int getY();
        virtual void executar() = 0;
        virtual void salvar() = 0;
    };
}
