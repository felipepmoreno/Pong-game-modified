#include Game.h

class Ball 
{
    Vector2 pos();
    Vector2 vel();
    float height = 15f;
    float width = 15f;
    bool isInsanced = false;

    public:
        Ball() {

        }

        void populate(float posX, float posY, float velX, float velY) {
            this->pos.x = posX;
            this->pos.y = posY;
            this->vel.x = velX;
            this->vel.y = velY;

            this->isInsanced = true;
        }

        void Update(float deltaTime, Vector2 paddle1, Vector2 paddle2) {
            // atualiza a posi��o da bola com base na sua velocidade
            this->pos.x += this->vel.x * deltaTime;
            this->pos.y += this->vel.y * deltaTime;

            // atualiza a posi��o da bola se ela colidiu com a raquete
            float diff = paddle1.y - this->pos.y;
            float diff2 = paddle2.y - this->pos.y;
            //pegue o valor absoluto de diferen�a entre o eixo y da bolinha e da raquete
            //isso � necess�rio para os casos em que no pr�ximo frame a bolinha ainda n�o esteja t�o distante da raquete
            //verifica se a bola est� na area da raquete e na mesma posi��o no eixo x
            diff = (diff > 0.0f) ? diff : -diff;
            diff2 = (diff2 > 0.0f) ? diff2 : -diff2;
            if (
                // A diferen�a no eixo y y-difference is small enough
                (diff <= paddleH / 2.0f || diff2 <= paddleH) &&
                // Estamos na posicao x correta
                this->pos.x <= 25.0f && this->pos.x >= 20.0f &&
                // A bolinha est� se movendo para a esquerda
                this->vel.x < 0.0f)
            {
                this->vel.x *= -1.0f;
            }

            //Verifica se a bola saiu da tela (no lado esquerdo ou direito, onde � permitido)
            //Se sim, encerra o jogo
            // 

            // else if (this->pos.x <= 0.0f || this->pos.x >= 1024)
            // {
            //     Reposition();
            //     UpdatePoints();
            //     //mIsRunning = false;
            // }
        };

        bool isOut() {
            return (this->pos.x <= 0.0f || this->pos.x >= 1024)
        }

        bool isInstanced() {
            return this->isInstanced;
        }
};