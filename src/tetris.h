#ifndef TETRIS_H
#define TETRIS_H

#define TET_TICKS_START 30

// присутствует ли блок на поле
typedef struct TetBlock
{
    int b;
} TetBlock;

// структура для падающей фигуры
typedef struct TetFigure
{
    int x;
    int y;
    int size;
    TetBlock *blocks;
} TetFigure;

// для описания фигур
typedef struct TetFiguresT
{
    int count;
    int size;
    TetBlock *blocks;
} TetFiguresT;

// игровое поле
typedef struct TetField
{
    int width;
    int height;
    TetBlock *blocks; // для хранения массива из блоков
} TetField;

// набор констант для возможных состояний игры
enum
{
    TET_GAMEOVER = 0,
    TET_PLAYING
};

// набор констант, описывающих действие игрока
enum
{
    TET_PLAYER_NOP = 0,
    TET_PLAYER_UP,
    TET_PLAYER_DOWN,
    TET_PLAYER_LEFT,
    TET_PLAYER_RIGHT
};

// описывает действие игрока
typedef struct TetPlayer
{
    int action;
} TetPlayer;

// данные, необходимые для описания игровой ситуации
typedef struct TetGame
{
    TetField *field;       // игровое поле с расположенными на нем блоками
    TetFigure *figure;     // информация о падающей на данный момент фигуре
    TetFiguresT *figurest; // сведения о том, как вышдядят типовые фигуры
    TetPlayer *player;
    int ticks;
    int ticks_left;
    int playing;
    int score;
} TetGame;

// алгоритм инициализации набора шаблона
TetFiguresT *createTetFiguresT(int count, int figures_size, TetBlock *figures_template);
// функция очистки памяти
void freeTetFiguresT(TetFiguresT *tetft);
TetField *createTetField(int width, int height);
void freeTetField(TetField *tetf);
TetGame *createTetGame(int field_width, int field_height,
                       int figures_size, int count, TetBlock *figures_template);
void freeTetGame(TetGame *tetg);
void moveFigureDown(TetGame *tetg);
void moveFigureUp(TetGame *tetg);
void moveFigureRight(TetGame *tetg);
void moveFigureLeft(TetGame *tetg);
int collisionTet(TetGame *tetg);
// функция проверки заполнения строки
int lineFilledTet(int i, TetField *tfl);
// процедура сдвига на одну строку
void dropLineTet(int i, TetField *tfl);
// функция удаляющая строки и подсчитывающая их колчество
int eraseLinesTet(TetGame *tetg);
// процедура размещения фигуры после падения
void plantFigure(TetGame *tetg);
// функция создания и инициализации фигуры
TetFigure *createTetFigure(TetGame *tetg);
void freeTetFigure(TetFigure *tf);
// процедурв выброса новой фигуры
void dropNewFigure(TetGame *tetg);
TetFigure *rotTetFigure(TetGame *tetg);
void calculateTet(TetGame *tetg);

#endif
