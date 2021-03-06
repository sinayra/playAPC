
 /**
 * \file  playcb.h
 * \brief  Respons�vel pela interface da playcb com o aluno
 *
 * Para seu funcionamento correto, s�o necess�rio duas fun��es: a AbreJanela() e a Desenha() ou Desenha1Frame(). A Desenha(), em especial,
 * cria o loop de desenho travado em 30fps, enquanto a Desenha1Frame() necessariamente precisa estar dentro de um loop ou n�o funcionar� corretamente.
 *
 */

#pragma once
#include "Evento.h"
#include "Reta.h"
#include "PlanoCartesiano.h"
#include "Poligono.h"
#include "Circulo.h"
#include "Circunferencia.h"
#include "Elipse.h"
#include "Retangulo.h"
#include "Triangulo.h"
#include "Grupo.h"
#include "Pontinho.h"
#include "Grafico.h"
#include "SOIL/SOIL.h"
#include "ExtraiRGBdeBMP_impl.tcc"
#include <vector>
#include <algorithm>

/**
 * \enum Geometrias v�lidas
 * \brief Tipos de geometrias poss�veis para serem referenciadas por ::Pintar
 */
typedef enum { /// valor default
    NADA, /// referente a ::CriaPonto
    PONTO, /// referente a ::CriaReta
    RETA, /// referente a ::CriaTriangulo
    TRIANGULO, /// referente a ::CriaQuadrado
    QUADRADO, /// referente a ::CriaRetangulo
    RETANGULO, /// referente a ::CriaCirculo
    CIRCULO, /// referente a ::CriaCircunferencia
    CIRCUNFERENCIA, /// referente a ::CriaPoligono e ::CriaPoligonoVetor
    ELIPSE, /// referente a ::CriaElipse
    POLIGONO,
    GRAFICO
}geometrias_validas;

/**
 *  \defgroup init Fun��es necess�rias para o funcionamento da playcb
 *
 *  Este conjunto cont�m todas as inicializa��es e chamadas de fun��es necess�rias para a comunica��o entre a interface da playcb e a API opengl
 *
 */
void AbreJanela(int largura, int altura, const char *titulo); //Abre janela e prepara eventos da opengl
void Desenha(); //Loop de desenho
int Desenha1Frame(); //Desenha apenas um frame do desenho
void LimpaDesenho(); //Destr�i objetos
/**
 *  \defgroup aux Fun��es para organizar e auxiliar o desenvolvimento
 *
 * Este conjunto cria um modo que o aluno possa organizar as geometrias em grupos (geometrias que partilham a mesma transforma��o) e exibir um plano cartesiano
 *
 */
void Lupa(int espaco, Ponto pontoesq);
void MudaLimitesJanela(int limite);
void MostraPlanoCartesiano(int intervalo); //Exibe linhas de plano cartesiano de -limite � limite
int CriaGrupo(); //Cria conjunto de geometrias que partilham as mesmas transforma��es
int CriaSuperGrupo(); //Cria conjunto de grupos que partilham a mesma transforma��o resultante
void ApagaGrupo(int index); //Apaga um grupo de geometrias

int ApertouTecla(int tecla); //Verifica se tecla foi pressionada
int RetornaTecla(); //Retorna tecla que foi pressionada

void PosicaoMouse(int *x, int *y); //Pega posi��o x e y do mouse
int ApertouBotaoMouse(int tecla); //Verifica se usu�rio apertou um dos dois bot�es do mouse
int RetornaBotaoMouse(); //Retorna o bot�o que foi pressionado


/**
 *  \defgroup cor Fun��es para associa��o de cores/imagem
 *
 * Este conjunto define as fun��es para modificar cores em uma geometria ou o fundo da tela. Al�m disso, cont�m as fun��es de associa��o de geometria e imagem
 *
 */
void Pintar(int red, int green, int blue, geometrias_validas nome = NADA, int index = -1); //Define cor da �ltima geometria definida
void Grafite(float grossura); //Define largura da borda
void PintarFundo(int red, int green, int blue); //Define cor de fundo
void AssociaImagem(int textura, geometrias_validas nome = NADA, int index = -1); //Associa textura com geometria
int AbreImagem(const char *src); //abre uma imagem e deixa preparada para ser associada

template <size_t tam_x, size_t tam_y>
void ExtraiRGBdeBMP(const char *imagepath, int largura, int altura, int (&R)[tam_x][tam_y], int (&G)[tam_x][tam_y], int (&B)[tam_x][tam_y]); //extrai componentes RGB de uma imagem BMP 24bits


/**
 *  \defgroup transf Fun��es para anima��es simples/transforma��es
 *
 * Este conjunto define as fun��es que realizam a anima��o simples ou transforma��o (rota��o, tranla��o e redimensionamento) de uma geometria
 *
 */
void Gira(float angulo, int index = -1); //Gira em x um grupo
void Move(Ponto p, int index = -1); //Move em x,y um grupo
void Redimensiona(float x, float y, int index = -1); //Redimensiona um grupo

void SuperGira(float angulo, int index = -1); //Gira em x um grupo
void SuperMove(Ponto p, int index = -1); //Move em x,y um grupo
void SuperRedimensiona(float x, float y, int index = -1); //Redimensiona um grupo

/**
 *  \defgroup geo Fun��es para cria��o de geometrias
 *
 * Este conjunto cria objetos j� previamente definidos
 *
 */
int CriaPonto(Ponto p);
int CriaReta(Ponto p1, Ponto p2);
int CriaPoligono(short int qtd, ...); //OBS: n�o tem como colocar uma imagem em um poligno
int CriaPoligonoVetor(short int index, Ponto *p); //OBS: n�o tem como colocar uma imagem em um poligno
int CriaGrafico(short int index, Ponto *p, int verTipo = 0);
int CriaCirculo(float raio, Ponto meio);
int CriaCircunferencia(float raio, Ponto meio);
int CriaElipse(float a, float b, Ponto meio);
int CriaQuadrado(float lado, Ponto cantoesq);
int CriaRetangulo(float base, float altura, Ponto cantoesq);
int CriaTriangulo(float base, float altura, Ponto cantoesq);
