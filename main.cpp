
#include "./class/Player.h"
#include "./class/Inputs.h"
#include "./class/Tube.h"
#include "./class/Background.h"
#include "./class/StartMenu.h"
using namespace std;

ALLEGRO_MOUSE_STATE Inputs::state;
unsigned char Inputs::keys[ALLEGRO_KEY_MAX];
#define D_BACKGROUND_RED 000
#define D_BACKGROUND_GREEN 000
#define D_BACKGROUND_BLUE 000

#pragma region default functions

double setSpeed()
{
    double speed = 1.0 / 60;
    return speed;
}

void update(const vector<GameObject *> &objectVector)
{

    for (auto it = objectVector.begin(); it != objectVector.end(); it++)
    {

        (*it)->update();
    }
}

void destroyTube(const vector<Tube *> &tubeVector)
{
    for (auto it = tubeVector.begin(); it != tubeVector.end(); it++)
    {
        delete *it;
    }
}
void destroy(const vector<GameObject *> &objectVector)
{
    for (auto it = objectVector.begin(); it != objectVector.end(); it++)
    {
        delete *it;
    }
}
bool checkCollision(const vector<Tube *> &tubeVector, Player *InitialPlayer)
{
    for (auto it = tubeVector.begin(); it != tubeVector.end(); it++)
    {
        

        if ((*it)->collision(InitialPlayer))
        {
            
            return true;
        }else{
            (*it)->update();
        }
    }
    return false;
}
void draw(const vector<GameObject *> &objectVector)
{

    for (auto it = objectVector.begin(); it != objectVector.end(); it++)
    {
        (*it)->draw();
    }
    al_flip_display();
}
void drawTube(const vector<Tube *> &tubeVector)
{

    for (auto it = tubeVector.begin(); it != tubeVector.end(); it++)
    {
        (*it)->draw();
    }
    al_flip_display();
}

#pragma endregion
void mustInit(bool isWorking, string errorMesage)
{
    if (isWorking)
    {
        return;
    }
    cout << "Erro não foi possivel inicializar " << errorMesage << endl;
}
int main()
{
#pragma region Allegro init
    al_init();
    mustInit(al_init(), "al_init");
    mustInit(al_init_primitives_addon(), "primitives_addon");
    mustInit(al_install_keyboard(), "al_install_keyboard");
    mustInit(al_install_mouse(), "al_install_mouse");
    mustInit(al_init_image_addon(), "al_init_image_addon");

    double speed = setSpeed();
    bool done = false;

#pragma endregion
#pragma region Allegro Variaveis
    ALLEGRO_EVENT_QUEUE *queue = al_create_event_queue();
    ALLEGRO_TIMER *timer = al_create_timer(speed);
    ALLEGRO_DISPLAY *display = al_create_display(D_WIDHT, D_HEIGTH);
    ALLEGRO_EVENT event;
    const char *imagePath[] = {
        "img/1.png",
        "img/2.png",
        "img/3.png",
        "img/4.png",
        "img/Player.png",
        "img/cano.png",
        "img/start_buton.png"};

    mustInit(queue, "quee");
    mustInit(timer, "timer");
    mustInit(display, "display");

    al_register_event_source(queue, al_get_display_event_source(display));
    al_register_event_source(queue, al_get_timer_event_source(timer));
    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_mouse_event_source());
    al_start_timer(timer);
#pragma endregion
#pragma region ObjectVector
    vector<GameObject *> objectVector;
    vector<Tube *> TubeVector;
    for (int i = 0; i <= 3; i++)
    {
        objectVector.push_back(new Background(0, 0, 0.3 * (i + 1), 0, -1, 1, D_WIDHT, D_HEIGTH, imagePath[i]));
    }
    StartMenu *btnMenu = new StartMenu(D_WIDHT, D_HEIGTH, imagePath[6]);
    Player *InitialPlayer = new Player(Position(200, D_HEIGTH / 2), imagePath[4],6);
    Tube *tube = new Tube(Position(D_WIDHT + 2, -tube->randmWithLimit(40, 200)), imagePath[5]);

    objectVector.push_back(btnMenu);

#pragma endregion
#pragma region logic

    Inputs::init();
    while (!done)
    {
        if (btnMenu->getStart() && !btnMenu->checkBtnIsPress())
        {
            delete btnMenu;
            objectVector.pop_back();
        }
        else if (btnMenu->checkBtnIsPress())
        {
            objectVector.push_back(InitialPlayer);
            TubeVector.push_back(tube);

            for (int i = 1; i < 6; i++)
            {
                TubeVector.push_back(new Tube(Position(D_WIDHT + 200 * i, -tube->randmWithLimit(40, 200)), imagePath[5]));
            }

               
            btnMenu->changePressState(false);
        }
        al_wait_for_event(queue, &event);
        switch (event.type)
        {
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
            done = true;
            break;

        case ALLEGRO_EVENT_TIMER:
        if(checkCollision(TubeVector, InitialPlayer)){
           
        }else{
 update(objectVector);

            draw(objectVector);
            drawTube(TubeVector);
        }
            al_add_timer_count(timer, 1);
            break;
        }
        if (checkCollision(TubeVector, InitialPlayer))
        {
            // done = true;
        }else{
            
        }
        Inputs::update(event);
    }

#pragma endregion
#pragma region destroy
    destroy(objectVector);
    al_destroy_timer(timer);
    al_destroy_event_queue(queue);
    al_destroy_display(display);
#pragma endregion
    return 0;
}
