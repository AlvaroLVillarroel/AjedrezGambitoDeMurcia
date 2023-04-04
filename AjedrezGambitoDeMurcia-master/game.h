

enum Estado {inicio,modos,modo_pvp,modo_rapido,pausa};
class game
{
public:
	void dibuja();
	void mousePress(int button, int state,int x,int y );
	void music();
	Estado estado;
};
