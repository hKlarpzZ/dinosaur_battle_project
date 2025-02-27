﻿#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

#include <iostream>
using namespace sf;
using namespace std;

enum Terrain { Plain, River, Mountain };

class Dino
{ // класс должен быть абстрактный
protected:
    int strength; // сила 10 - 30
    int dexterity; // ловкость 10 - 30
    int intelligence; // интеллект 10 - 30
    int health; // здоровье
    string name; // имя
    int cost; // цена

public:
    Dino()
    {
        strength = 10 + (rand() % 21);
        dexterity = 10 + (rand() % 21);
        intelligence = 10 + (rand() % 21);
        health = 99;
        cost = int((strength + dexterity + intelligence) / 2);
    }

    ~Dino() {}

    /*void printCard()
    {
        cout << "\n-------=[Динозавр]=------\n"
            << " Имя:        " << name << endl
            << endl
            << " Сила:       " << strength << endl
            << " Ловкость:   " << dexterity << endl
            << " Интеллект:  " << intelligence << endl
            << endl
            << " Стоимость:  " << cost << endl
            << "----------={ }=----------\n" << endl;
    }*/

    void changeName(string newName)
    {
        name = newName;
    }

    void set(string dino_name, int dino_strength, int dino_dexterity, int dino_intelligence, int dino_cost)
    {
        name = dino_name;
        strength = dino_strength;
        dexterity = dino_dexterity;
        intelligence = dino_intelligence;
        cost = dino_cost;
    }

    void heal()
    {
        health = 99;
    }

    int get_cost()
    {
        return cost;
    }

    int get_hp()
    {
        return health;
    }

    void get_damage(int damage)
    {
        health = health - damage;
    }

    // переопределите след. метод для разных дочерних классов
    virtual int damage(Terrain terrain) { return 0; }

    virtual void dump(string* dino_type, string* dino_name, int* dino_strength, int* dino_dexterity, int* dino_intelligence, int* dino_cost) {}
};

class Velociraptor : public Dino // интеллект
{
public:
    Velociraptor()
    {
        name = "Velociraptor";
        // cout << "Создан Velociraptor" << endl;
    }

    ~Velociraptor() {}

    virtual int damage(Terrain terrain) override
    {
        if (terrain == Plain)
        {
            return strength;
        }
        else if (terrain == River)
        {
            return dexterity;
        }
        else
        {
            return 2 * intelligence;
        }

    }

    virtual void dump(string* dino_type, string* dino_name, int* dino_strength, int* dino_dexterity, int* dino_intelligence, int* dino_cost) override
    {
        *dino_type = "Velociraptor";
        *dino_name = name;
        *dino_strength = strength;
        *dino_dexterity = dexterity;
        *dino_intelligence = intelligence;
        *dino_cost = cost;
    }
};

class Triceratops : public Dino // сила
{
public:
    Triceratops()
    {
        name = "Triceratops";
        // cout << "Создан Triceratops" << endl;
    }

    ~Triceratops() {}

    virtual int damage(Terrain terrain) override
    {
        if (terrain == Plain)
        {
            return 2 * strength;
        }
        else if (terrain == River)
        {
            return dexterity;
        }
        else
        {
            return intelligence;
        }

    }

    virtual void dump(string* dino_type, string* dino_name, int* dino_strength, int* dino_dexterity, int* dino_intelligence, int* dino_cost) override
    {
        *dino_type = "Triceratops";
        *dino_name = name;
        *dino_strength = strength;
        *dino_dexterity = dexterity;
        *dino_intelligence = intelligence;
        *dino_cost = cost;
    }
};

class Dilophosaurus : public Dino // ловкость
{
public:
    Dilophosaurus()
    {
        name = "Dilophosaurus";
        // cout << "Создан Dilophosaurus" << endl;

    }

    ~Dilophosaurus() {}

    virtual int damage(Terrain terrain) override
    {
        if (terrain == Plain)
        {
            return strength;
        }
        else if (terrain == River)
        {
            return 2 * dexterity;
        }
        else
        {
            return intelligence;
        }

    }

    virtual void dump(string* dino_type, string* dino_name, int* dino_strength, int* dino_dexterity, int* dino_intelligence, int* dino_cost) override
    {
        *dino_type = "Dilophosaurus";
        *dino_name = name;
        *dino_strength = strength;
        *dino_dexterity = dexterity;
        *dino_intelligence = intelligence;
        *dino_cost = cost;
    }
};



class Pool
{
public:
    Dino* slot1;
    Dino* slot2;
    Dino* slot3;
    Pool()
    {
        slot1 = NULL;
        slot2 = NULL;
        slot3 = NULL;
    }

    ~Pool() {}

    /*void showPool()
    {
        cout << "=======[Текущий пул дино]=======" << endl;
        if (slot1 != NULL)
        {
            slot1->printCard();
        }
        else
        {
            cout << "\n[Тут пусто]\n" << endl;
        }
        if (slot2 != NULL)
        {
            slot2->printCard();
        }
        else
        {
            cout << "\n[Тут пусто]\n" << endl;
        }
        if (slot3 != NULL)
        {
            slot3->printCard();
        }
        else
        {
            cout << "\n[Тут пусто]\n" << endl;
        }
        cout << "================================" << endl;
    }*/

    void add(Dino* dino)
    {
        if (slot1 == NULL)
        {
            slot1 = dino;
        }
        else if (slot2 == NULL)
        {
            slot2 = dino;
        }
        else if (slot3 == NULL)
        {
            slot3 = dino;
        }
        /*else
        {
            cout << "\nВ текущем пуле нет места!\n" << endl;
        }*/

    }

    void remove(int id)
    {
        if (id == 1)
        {
            slot1 = NULL;
        }
        else if (id == 2)
        {
            slot2 = NULL;
        }
        else if (id == 3)
        {
            slot3 = NULL;
        }

    }

    bool isEmpty()
    {
        if (slot1 != NULL)
        {
            return false;
        }
        if (slot2 != NULL)
        {
            return false;
        }
        if (slot3 != NULL)
        {
            return false;
        }
        return true;
    }
};

class Box
{
public:
    vector<Dino*> box_dinos;

    vector<Velociraptor> velos;
    vector<Triceratops> trices;
    vector<Dilophosaurus> dilos;

    Box()
    {
        ifstream box_read;
        box_read.open("dino_box.txt");
        string line = "";

        while (getline(box_read, line))
        {
            istringstream line_stream(line); // Создаёт поток символов из строки
            vector<string> words; // Создаёт массив(вектор) слов
            string word;
            while (getline(line_stream, word, ' ')) // Разбивает слова из потока и записывает в массив(вектор)
            {
                if (!word.empty())
                {
                    words.push_back(word);
                }
            }

            string dino_type = words[0];
            string dino_name = words[1];
            int dino_strength = stoi(words[2]);
            int dino_dexterity = stoi(words[3]);
            int dino_intelligence = stoi(words[4]);
            int dino_cost = stoi(words[5]);
            if (dino_type == "Velociraptor")
            {
                Velociraptor dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                velos.push_back(dino);
            }
            else if (dino_type == "Triceratops")
            {
                Triceratops dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                trices.push_back(dino);
            }
            else if (dino_type == "Dilophosaurus")
            {
                Dilophosaurus dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                dilos.push_back(dino);
            }

        }

        for (int i = 0; i < velos.size(); i++)
        {
            box_dinos.push_back(&velos[i]);
        }

        for (int i = 0; i < trices.size(); i++)
        {
            box_dinos.push_back(&trices[i]);
        }

        for (int i = 0; i < dilos.size(); i++)
        {
            box_dinos.push_back(&dilos[i]);
        }

        box_read.close();

        // showBox();

    }

    ~Box() {}

    /*void showBox()
    {
        cout << "\nВ вашей коробке " << box_dinos.size() << " дино.\n" << endl;
        if (box_dinos.size() != 0)
        {
            cout << "\nВот они:\n" << endl;
            for (size_t i = 0; i < box_dinos.size(); i++)
            {
                cout << "\n№" << i << " -v-v-v-v-v" << endl;
                (*box_dinos[i]).printCard();
            }
        }
    }*/

    void re_init()
    {
        box_dinos.clear();

        velos.clear();
        trices.clear();
        dilos.clear();

        ifstream box_read;
        box_read.open("dino_box.txt");
        string line = "";

        while (getline(box_read, line))
        {
            istringstream line_stream(line); // Создаёт поток символов из строки
            vector<string> words; // Создаёт массив(вектор) слов
            string word;
            while (getline(line_stream, word, ' ')) // Разбивает слова из потока и записывает в массив(вектор)
            {
                if (!word.empty())
                {
                    words.push_back(word);
                }
            }

            string dino_type = words[0];
            string dino_name = words[1];
            int dino_strength = stoi(words[2]);
            int dino_dexterity = stoi(words[3]);
            int dino_intelligence = stoi(words[4]);
            int dino_cost = stoi(words[5]);
            if (dino_type == "Velociraptor")
            {
                Velociraptor dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                velos.push_back(dino);
            }
            else if (dino_type == "Triceratops")
            {
                Triceratops dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                trices.push_back(dino);
            }
            else if (dino_type == "Dilophosaurus")
            {
                Dilophosaurus dino;
                dino.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
                dilos.push_back(dino);
            }

        }

        for (int i = 0; i < velos.size(); i++)
        {
            box_dinos.push_back(&velos[i]);
        }

        for (int i = 0; i < trices.size(); i++)
        {
            box_dinos.push_back(&trices[i]);
        }

        for (int i = 0; i < dilos.size(); i++)
        {
            box_dinos.push_back(&dilos[i]);
        }

        box_read.close();
    }

    void add(Dino* dino)
    {
        string dino_type;
        string dino_name;
        int dino_strength;
        int dino_dexterity;
        int dino_intelligence;
        int dino_cost;

        (*dino).dump(&dino_type, &dino_name, &dino_strength, &dino_dexterity, &dino_intelligence, &dino_cost);

        if (dino_type == "Velociraptor")
        {
            Velociraptor dino_copy;
            dino_copy.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
            velos.push_back(dino_copy);
        }
        else if (dino_type == "Triceratops")
        {
            Triceratops dino_copy;
            dino_copy.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
            trices.push_back(dino_copy);
        }
        else if (dino_type == "Dilophosaurus")
        {
            Dilophosaurus dino_copy;
            dino_copy.set(dino_name, dino_strength, dino_dexterity, dino_intelligence, dino_cost);
            dilos.push_back(dino_copy);
        }

        box_dinos.push_back(dino);

        ofstream box_write;
        box_write.open("dino_box.txt", ios_base::app);
        box_write << dino_type << " " << dino_name << " " << dino_strength << " "
            << dino_dexterity << " " << dino_intelligence << " " << dino_cost << endl;
        box_write.close();

        //cout << dino_type << dino_name << dino_strength << dino_dexterity << dino_intelligence << dino_cost << endl;

    }

    /*void clear(int id)
    {
        if ((id < 0) || (id >= box_dinos.size()))
        {
            return;
        }
        rename("dino_box.txt", "dino_box_temp.txt");
        ifstream box_read;
        box_read.open("dino_box_temp.txt");
        string line = "";
        int counter = 0;
        ofstream box_write;
        box_write.open("dino_box.txt", ios_base::app);

        while (getline(box_read, line))
        {
            if (counter == id)
            {
                cout << "\nОтпускаем на волю:" << endl;
                (*box_dinos[counter]).printCard();
            }
            else
            {
                box_write << line << endl;
            }
            counter++;
        }

        box_dinos.erase((box_dinos.begin() + id));

        box_read.close();
        box_write.close();
        remove("dino_box_temp.txt");
    }*/
};

class Balance
{
public:
    int money;

    Balance()
    {
        ifstream balance_file;
        balance_file.open("balance.txt");

        string line = "";

        getline(balance_file, line);

        money = stoi(line);
        balance_file.close();
    }

    ~Balance() {}

    Balance operator + (int value) {
        money += value;
        ofstream balance_file;
        balance_file.open("balance.txt");
        balance_file << money;

        return *this;
    }

    Balance operator - (int value) {
        money -= value;
        ofstream balance_file;
        balance_file.open("balance.txt");
        balance_file << money;

        return *this;
    }

    bool can_afford(int value)
    {
        if (money >= value)
        {
            return true;
        }
        return false;
    }
};




enum Gamestage { Idle, Battle, Shop, Battle_end };

void center_text(Text& location_text_info, string text, RenderWindow& window)
{
    location_text_info.setString(text);
    location_text_info.setPosition(((window.getSize().x - location_text_info.getLocalBounds().width)) / 2, location_text_info.getPosition().y);
}

void go_to_shop(Velociraptor& shop_vel, Triceratops& shop_tri, Dilophosaurus& shop_dil, Pool& shopPool)
{
    shop_vel = Velociraptor();
    shopPool.add(&shop_vel);
    shop_tri = Triceratops();
    shopPool.add(&shop_tri);
    shop_dil = Dilophosaurus();
    shopPool.add(&shop_dil);
}

void go_out_of_shop(Pool& shopPool)
{
    shopPool.remove(1);
    shopPool.remove(2);
    shopPool.remove(3);
}

class TextHandler
{
public:
    sf::Text text;
    Font font;
    int height = 0;
    int width = 0;

    TextHandler() {}

    ~TextHandler() {}

    void init(string text_string)
    {
        font.loadFromFile("./assets/benguiat_bold.ttf");
        text.setFont(font);
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        text.setOutlineColor(Color::Black);
        text.setOutlineThickness(1);
        text.setString(text_string);
        height = text.getLocalBounds().height;
        width = text.getLocalBounds().width;
    }

    void update(string text_string)
    {
        text.setString(text_string);
        height = text.getLocalBounds().height;
        width = text.getLocalBounds().width;
    }

    void set_position(int x, int y)
    {
        text.setPosition(x, y);
    }

    void draw(RenderWindow& window)
    {
        //cout << "text positioned in (" << text.getGlobalBounds().left << ", " << text.getGlobalBounds().top << ")" << endl;
        window.draw(text);
    }
};

class Button
{
public:
    int mouse_press_cd = 0;
    bool is_pressed = false;
    RectangleShape background;

    Texture* btn;
    Texture* btn_hover;


    Button(vector<Texture*> btn_textures)
    {
        btn = btn_textures[0];
        btn_hover = btn_textures[1];

        Vector2f background_size(170, 170);
        background.setSize(background_size);
        background.setTexture(btn, true);
        //background.setFillColor(Color(255, 0, 0, 255));
    }

    ~Button() {}

    void set_position(int x, int y)
    {
        background.setPosition(x, y);
    }

    void draw(RenderWindow& window)
    {
        Vector2i mouse_position = Mouse::getPosition(window);

        check_press(mouse_position);

        if (check_hover(mouse_position))
        {
            background.setTexture(btn_hover);
        }
        else
        {
            background.setTexture(btn);
        }

        window.draw(background);
    }

    bool check_hover(Vector2i mouse_position)
    {
        if ((mouse_position.x > background.getGlobalBounds().left) && (mouse_position.x < background.getGlobalBounds().left + background.getGlobalBounds().width) && (mouse_position.y > background.getGlobalBounds().top) && (mouse_position.y < background.getGlobalBounds().top + background.getGlobalBounds().height))
        {
            //cout << "Hovering button on position (" << mouse_position.x << ", " << mouse_position.y << ")" << endl;
            return true;
        }
        return false;
    }

    void check_press(Vector2i mouse_position)
    {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd < 10))
        {
            if ((mouse_position.x > background.getGlobalBounds().left) && (mouse_position.x < background.getGlobalBounds().left + background.getGlobalBounds().width) && (mouse_position.y > background.getGlobalBounds().top) && (mouse_position.y < background.getGlobalBounds().top + background.getGlobalBounds().height))
            {
                mouse_press_cd++;
            }
        }
        if ((!Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd >= 10))
        {
            mouse_press_cd = 0;
            //cout << "Pressed on button at position (" << mouse_position.x << ", " << mouse_position.y << ")" << endl;
            on_press();
        }
    }

    void on_press()
    {
        is_pressed = true;
    }
};

class DinoCard
{
public:
    Dino* dino;
    RectangleShape card_bg;
    RectangleShape card_holder;
    RectangleShape card_holder_glow;
    RectangleShape card_stat_intelligence_bg;
    RectangleShape card_stat_strength_bg;
    RectangleShape card_stat_dexterity_bg;
    RectangleShape card_stat_cost_bg;
    string type;
    string name;
    TextHandler name_handler;
    int s;
    TextHandler s_handler;
    int d;
    TextHandler d_handler;
    int i;
    TextHandler i_handler;
    int cost;
    TextHandler cost_handler;
    Font font;
    Vector2i animate_offset_hover;
    Vector2i animate_offset_press;
    bool hoverable = true;
    bool pressable = true;
    int mouse_press_cd = 0;
    bool animate_press_to = false;
    bool animate_press_from = false;
    bool ready_to_check = false;

    DinoCard(Dino* dino_imported, vector<Texture*> dino_bg, vector<Texture*> dino_holder, vector<Texture*> dino_stat_holder, vector<Texture*> dino_holder_glow)
    {
        animate_offset_hover.x = 0;
        animate_offset_hover.y = 0;
        animate_offset_press.x = 0;
        animate_offset_press.y = 0;
        dino = dino_imported;
        Vector2f shop_card_size(250, 350);
        card_bg.setSize(shop_card_size);
        Vector2f card_holder_size(272, 400);
        card_holder.setSize(card_holder_size);
        Vector2f card_holder_glow_size(330, 458);
        card_holder_glow.setSize(card_holder_glow_size);
        Vector2f card_stat_bg_size(60, 60);
        card_stat_intelligence_bg.setSize(card_stat_bg_size);
        card_stat_strength_bg.setSize(card_stat_bg_size);
        card_stat_dexterity_bg.setSize(card_stat_bg_size);
        Vector2f card_stat_cost_bg_size(70, 90);
        card_stat_cost_bg.setSize(card_stat_cost_bg_size);


        string dinotype = typeid(*dino).name();
        dinotype.erase(0, 6);
        if (dinotype == "Velociraptor") {
            card_bg.setTexture(dino_bg[0], true);
            card_holder.setTexture(dino_holder[0], true);
            card_holder_glow.setTexture(dino_holder_glow[0], true);
        }
        else if (dinotype == "Triceratops") {
            card_bg.setTexture(dino_bg[1], true);
            card_holder.setTexture(dino_holder[1], true);
            card_holder_glow.setTexture(dino_holder_glow[1], true);
        }
        else {
            card_bg.setTexture(dino_bg[2], true);
            card_holder.setTexture(dino_holder[2], true);
            card_holder_glow.setTexture(dino_holder_glow[2], true);
        }

        dino->dump(&type, &name, &s, &d, &i, &cost);

        name_handler.init(name);
        s_handler.init(to_string(s));
        d_handler.init(to_string(d));
        i_handler.init(to_string(i));
        cost_handler.init(to_string(cost));

        card_stat_intelligence_bg.setTexture(dino_stat_holder[0], true);
        card_stat_strength_bg.setTexture(dino_stat_holder[1], true);
        card_stat_dexterity_bg.setTexture(dino_stat_holder[2], true);
        card_stat_cost_bg.setTexture(dino_stat_holder[3], true);
    }

    ~DinoCard() {}

    void set_position(int x, int y)
    {
        x = x + animate_offset_hover.x + animate_offset_press.x;
        y = y + animate_offset_hover.y + animate_offset_press.y;
        card_holder_glow.setPosition(x - 45, y - 48);
        card_bg.setPosition(x, y);
        card_holder.setPosition(x - 11, y - 25);
        name_handler.set_position(x + (fabs(250 - name_handler.width) / 2), y + 260);
        s_handler.set_position(x - 8, y + 231);
        d_handler.set_position(x - 8, y + 291);
        i_handler.set_position(x - 8, y + 171);
        card_stat_intelligence_bg.setPosition(x - 23, y + 156);
        card_stat_strength_bg.setPosition(x - 23, y + 216);
        card_stat_dexterity_bg.setPosition(x - 23, y + 276);
        card_stat_cost_bg.setPosition(x + 90, y + 300);
        cost_handler.set_position(x + (fabs(250 - cost_handler.width) / 2) + 1, y + 310);
    }

    void draw(RenderWindow& window)
    {
        Vector2i mouse_position = Mouse::getPosition(window);

        check_press(mouse_position);
        if (animate_press_to && (animate_offset_press.y < 1000))
        {
            animate_offset_press.y += 3;
            if (animate_offset_press.y >= 1000)
            {
                //cout << "Stopped animating dinocard press animation!" << endl;
                ready_to_check = true;
                animate_press_to = false;
            }
        }
        if (animate_press_from && (animate_offset_press.y > 0))
        {
            animate_offset_press.y -= 3;
            if (animate_offset_press.y <= 0)
            {
                //cout << "Stopped animating dinocard press animation!" << endl;
                animate_offset_press.y = 0;
                animate_press_from = false;
            }
        }

        if (check_hover(mouse_position) && hoverable)
        {
            window.draw(card_holder_glow);
        }
        window.draw(card_bg);
        name_handler.draw(window);

        window.draw(card_holder);
        window.draw(card_stat_intelligence_bg);
        i_handler.draw(window);
        window.draw(card_stat_strength_bg);
        s_handler.draw(window);
        window.draw(card_stat_dexterity_bg);
        d_handler.draw(window);
        window.draw(card_stat_cost_bg);
        cost_handler.draw(window);
    }

    bool check_hover(Vector2i mouse_position)
    {
        if ((mouse_position.x > card_bg.getGlobalBounds().left) && (mouse_position.x < card_bg.getGlobalBounds().left + card_bg.getGlobalBounds().width) && (mouse_position.y > card_bg.getGlobalBounds().top) && (mouse_position.y < card_bg.getGlobalBounds().top + card_bg.getGlobalBounds().height) && hoverable)
        {
            //cout << "Hovering dinocard on position (" << mouse_position.x << ", " << mouse_position.y << ")" << endl;
            if (animate_offset_hover.y > -20)
            {
                animate_offset_hover.y--;
            }
            return true;
        }
        if (animate_offset_hover.y < 0)
        {
            animate_offset_hover.y++;
        }
        return false;
    }

    void check_press(Vector2i mouse_position)
    {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd < 10))
        {
            if ((mouse_position.x > card_bg.getGlobalBounds().left) && (mouse_position.x < card_bg.getGlobalBounds().left + card_bg.getGlobalBounds().width) && (mouse_position.y > card_bg.getGlobalBounds().top) && (mouse_position.y < card_bg.getGlobalBounds().top + card_bg.getGlobalBounds().height) && pressable)
            {
                mouse_press_cd++;
            }
        }
        if ((!Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd >= 10))
        {
            mouse_press_cd = 0;
            //cout << "Pressed on dinocard at position (" << mouse_position.x << ", " << mouse_position.y << ")" << endl;
            on_press();
        }
    }

    void on_press()
    {
        hoverable = false;
        pressable = false;
        animate_press_to = true;
    }
};

DinoCard* check_for_confirm(DinoCard* shopcard1, DinoCard* shopcard2, DinoCard* shopcard3)
{
    if ((!shopcard1->ready_to_check) && (!shopcard2->ready_to_check) && (!shopcard3->ready_to_check))
    {
        shopcard1->hoverable = true;
        shopcard1->pressable = true;
        shopcard2->hoverable = true;
        shopcard2->pressable = true;
        shopcard3->hoverable = true;
        shopcard3->pressable = true;
        return NULL;
    }

    shopcard1->hoverable = false;
    shopcard1->pressable = false;
    shopcard2->hoverable = false;
    shopcard2->pressable = false;
    shopcard3->hoverable = false;
    shopcard3->pressable = false;

    if (shopcard1->ready_to_check)
    {
        return shopcard1;
    }
    if (shopcard2->ready_to_check)
    {
        return shopcard2;
    }
    return shopcard3;
}

class CardInventory
{
public:
    vector<DinoCard> cards;
    vector<Vector2i> card_positions;
    vector<int> visible;
    int scroll_offset = 0;
    int scroll_value = 0;
    //bool update_text_fields_flag = true; // fixed internal SFML draw custom objects error

    CardInventory(Box box, vector<Texture*> dino_bg, vector<Texture*> dino_holder, vector<Texture*> dino_stat_holder, vector<Texture*> dino_holder_glow)
    {
        for (int i = 0; i < box.box_dinos.size(); i++)
        {
            DinoCard dinocard(box.box_dinos[i], dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            cards.push_back(dinocard);
            Vector2i current_card_position(0, 0);
            if (i % 2 == 0)
            {
                current_card_position.x = 0;
                current_card_position.y = (i / 2) * (dinocard.card_bg.getSize().y + 80);
            }
            else
            {
                current_card_position.x = dinocard.card_bg.getSize().x + 60;
                current_card_position.y = ((i - 1) / 2) * (dinocard.card_bg.getSize().y + 80);
            }
            card_positions.push_back(current_card_position);
            visible.push_back(0);
        }
    }

    ~CardInventory() {}

    void re_init(Box box, vector<Texture*> dino_bg, vector<Texture*> dino_holder, vector<Texture*> dino_stat_holder, vector<Texture*> dino_holder_glow)
    {
        cards.clear();
        card_positions.clear();
        visible.clear();

        for (int i = 0; i < box.box_dinos.size(); i++)
        {
            DinoCard dinocard(box.box_dinos[i], dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            cards.push_back(dinocard);
            Vector2i current_card_position(0, 0);
            if (i % 2 == 0)
            {
                current_card_position.x = 0;
                current_card_position.y = (i / 2) * (dinocard.card_bg.getSize().y + 80);
            }
            else
            {
                current_card_position.x = dinocard.card_bg.getSize().x + 60;
                current_card_position.y = ((i - 1) / 2) * (dinocard.card_bg.getSize().y + 80);
            }
            card_positions.push_back(current_card_position);
            visible.push_back(0);
        }
    }

    void set_position(int x, int y)
    {
        y += 40 - scroll_offset;
        for (size_t i = 0; i < cards.size(); i++)
        {
            cards[i].set_position(x + card_positions[i].x, y + card_positions[i].y);
            //cout << "Set card position: (" << x + card_positions[i].x << ", " << y + card_positions[i].y - scroll_offset << ")" << endl;
        }
    }

    void draw(RenderWindow& window)
    {
        int window_vertical_size = window.getSize().y;
        check_scroll(window_vertical_size);

        for (size_t i = 0; i < cards.size(); i++)
        {
            if (check_for_visibility(&cards[i], &visible[i], window))
            {
                /*if (update_text_fields_flag)
                {
                    cards[i].name_handler.init(cards[i].name_handler.text.getString());
                    cards[i].i_handler.init(cards[i].i_handler.text.getString());
                    cards[i].s_handler.init(cards[i].s_handler.text.getString());
                    cards[i].d_handler.init(cards[i].d_handler.text.getString());
                    cards[i].cost_handler.init(cards[i].cost_handler.text.getString());
                }*/

                cards[i].draw(window);
            }
        }
        /*if (update_text_fields_flag)
        {
            update_text_fields_flag = false;
        }*/
        
    }

    void check_scroll(int window_vertical_size)
    {
        if (scroll_value > 0)
        {
            if (scroll_offset >= 50)
            {
                scroll_offset -= 50;
            }
        }
        if (scroll_value < 0)
        {
            if (scroll_offset <= card_positions[card_positions.size() - 1].y + cards[cards.size() - 1].card_bg.getSize().y - window_vertical_size + 60)
            {
                scroll_offset += 50;
            }
            
        }
        scroll_value = 0;
        //cout << Mouse::Wheel::VerticalWheel;
        /*if(Mouse::Wheel::VerticalWheel)
        {

        }*/

        /*if (Mouse::isButtonPressed(Mouse::VerticalWheel))
        {

        }*/
    }

    bool check_for_visibility(DinoCard* dinocard, int* visible_state, RenderWindow& window)
    {
        if ((dinocard->card_bg.getGlobalBounds().top > window.getSize().y) && (!dinocard->animate_press_to) && (!dinocard->animate_press_from))
        {
            *visible_state = 0;
            return false;
        }
        if ((dinocard->card_bg.getGlobalBounds().top + dinocard->card_bg.getGlobalBounds().height < 0) && (!dinocard->animate_press_to) && (!dinocard->animate_press_from))
        {
            *visible_state = 0;
            return false;
        }

        if (*visible_state == 0)
        {
            dinocard->name_handler.init(dinocard->name_handler.text.getString());
            dinocard->i_handler.init(dinocard->i_handler.text.getString());
            dinocard->s_handler.init(dinocard->s_handler.text.getString());
            dinocard->d_handler.init(dinocard->d_handler.text.getString());
            dinocard->cost_handler.init(dinocard->cost_handler.text.getString());

            *visible_state = 1;
        }
        return true;
    }
};

class InventoryPool{
public:
    Pool* player_pool;
    vector<Texture*> dino_bg;
    vector<Texture*> dino_holder;
    vector<Texture*> dino_stat_holder;
    vector<Texture*> dino_holder_glow;
    Vector2i pos;
    vector<DinoCard> slots;

    InventoryPool(Pool* player_pool_got, vector<Texture*> dino_bg_got, vector<Texture*> dino_holder_got, vector<Texture*> dino_stat_holder_got, vector<Texture*> dino_holder_glow_got)
    {
        player_pool = player_pool_got;
        for (size_t i = 0; i < dino_bg_got.size(); i++)
        {
            dino_bg.push_back(dino_bg_got[i]);
        }
        for (size_t i = 0; i < dino_holder_got.size(); i++)
        {
            dino_holder.push_back(dino_holder_got[i]);
        }
        for (size_t i = 0; i < dino_stat_holder_got.size(); i++)
        {
            dino_stat_holder.push_back(dino_stat_holder_got[i]);
        }
        for (size_t i = 0; i < dino_holder_glow_got.size(); i++)
        {
            dino_holder_glow.push_back(dino_holder_glow_got[i]);
        }
        Dino service_dino;
        service_dino.changeName("This is a bug");
        DinoCard service_slot(&service_dino, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
        slots.push_back(service_slot);
        slots.push_back(service_slot);
        slots.push_back(service_slot);
        pos.x = 40;
        pos.y = 200;
    }

    ~InventoryPool() {}

    void update()
    {
        if (player_pool->slot1 != NULL)
        {
            DinoCard slot1(player_pool->slot1, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[0] = slot1;
            //cout << string(slots[0].name_handler.text.getString()) << endl;
            slots[0].name_handler.init(slots[0].name_handler.text.getString());
            slots[0].i_handler.init(slots[0].i_handler.text.getString());
            slots[0].s_handler.init(slots[0].s_handler.text.getString());
            slots[0].d_handler.init(slots[0].d_handler.text.getString());
            slots[0].cost_handler.init(slots[0].cost_handler.text.getString());
        }
        if (player_pool->slot2 != NULL)
        {
            DinoCard slot2(player_pool->slot2, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[1] = slot2;
            //cout << string(slots[0].name_handler.text.getString()) << endl;
            slots[1].name_handler.init(slots[1].name_handler.text.getString());
            slots[1].i_handler.init(slots[1].i_handler.text.getString());
            slots[1].s_handler.init(slots[1].s_handler.text.getString());
            slots[1].d_handler.init(slots[1].d_handler.text.getString());
            slots[1].cost_handler.init(slots[1].cost_handler.text.getString());
        }
        if (player_pool->slot3 != NULL)
        {
            DinoCard slot3(player_pool->slot3, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[2] = slot3;
            //cout << string(slots[0].name_handler.text.getString()) << endl;
            slots[2].name_handler.init(slots[2].name_handler.text.getString());
            slots[2].i_handler.init(slots[2].i_handler.text.getString());
            slots[2].s_handler.init(slots[2].s_handler.text.getString());
            slots[2].d_handler.init(slots[2].d_handler.text.getString());
            slots[2].cost_handler.init(slots[2].cost_handler.text.getString());
        }
    }

    void draw(RenderWindow& window)
    {
        if (player_pool->slot1 != NULL)
        {
            slots[0].set_position(pos.x, pos.y);
            slots[0].draw(window);
        }
        if (player_pool->slot2 != NULL)
        {
            slots[1].set_position(pos.x + 200, pos.y + 40);
            slots[1].draw(window);
        }
        if (player_pool->slot3 != NULL)
        {
            slots[2].set_position(pos.x + 400, pos.y + 80);
            slots[2].draw(window);
        }
    }
};



class DinoBattleCard
{
public:
    Dino* dino;
    RectangleShape card_bg;
    RectangleShape card_holder;
    RectangleShape card_holder_glow;
    RectangleShape card_stat_attack_bg;
    RectangleShape card_stat_health_bg;

    string type;
    string name;
    TextHandler name_handler;
    TextHandler attack_handler;
    TextHandler health_handler;
    int s;
    int d;
    int i;
    int cost;
    int attack;
    int health;
    Vector2i animate_offset_hover;
    bool hoverable = true;
    bool pressable = true;
    int mouse_press_cd = 0;
    bool is_pressed = false;

    DinoBattleCard(Dino* dino_imported, vector<Texture*> dino_bg, vector<Texture*> dino_holder, vector<Texture*> dino_stat_holder, vector<Texture*> dino_holder_glow)
    {
        animate_offset_hover.x = 0;
        animate_offset_hover.y = 0;
        dino = dino_imported;
        attack = 0;
        health = dino->get_hp();
        Vector2f shop_card_size(250, 350);
        card_bg.setSize(shop_card_size);
        Vector2f card_holder_size(272, 400);
        card_holder.setSize(card_holder_size);
        Vector2f card_holder_glow_size(330, 446);
        card_holder_glow.setSize(card_holder_glow_size);
        Vector2f card_stat_attack_bg_size(60, 60);
        card_stat_attack_bg.setSize(card_stat_attack_bg_size);
        Vector2f card_stat_health_bg_size(60, 60);
        card_stat_health_bg.setSize(card_stat_health_bg_size);


        string dinotype = typeid(*dino).name();
        dinotype.erase(0, 6);
        if (dinotype == "Velociraptor") {
            card_bg.setTexture(dino_bg[0], true);
            card_holder.setTexture(dino_holder[0], true);
            card_holder_glow.setTexture(dino_holder_glow[0], true);
        }
        else if (dinotype == "Triceratops") {
            card_bg.setTexture(dino_bg[1], true);
            card_holder.setTexture(dino_holder[1], true);
            card_holder_glow.setTexture(dino_holder_glow[1], true);
        }
        else {
            card_bg.setTexture(dino_bg[2], true);
            card_holder.setTexture(dino_holder[2], true);
            card_holder_glow.setTexture(dino_holder_glow[2], true);
        }

        dino->dump(&type, &name, &s, &d, &i, &cost);

        name_handler.init(name);
        health_handler.init(to_string(health));
        attack_handler.init(to_string(attack));


        card_stat_attack_bg.setTexture(dino_stat_holder[0], true);
        card_stat_health_bg.setTexture(dino_stat_holder[1], true);
    }

    ~DinoBattleCard() {}

    void set_position(int x, int y)
    {
        x = x + animate_offset_hover.x;
        y = y + animate_offset_hover.y;
        card_holder_glow.setPosition(x - 45, y - 48);
        card_bg.setPosition(x, y);
        card_holder.setPosition(x - 11, y - 25);
        name_handler.set_position(x + (fabs(250 - name_handler.width) / 2), y + 260);

        attack_handler.set_position(x - 8, y + 231);
        health_handler.set_position(x - 8, y + 291);
        card_stat_attack_bg.setPosition(x - 23, y + 216);
        card_stat_health_bg.setPosition(x - 23, y + 276);
    }

    void draw(RenderWindow& window)
    {
        Vector2i mouse_position = Mouse::getPosition(window);

        check_press(mouse_position);

        if (check_hover(mouse_position) && hoverable)
        {
            window.draw(card_holder_glow);
        }
        window.draw(card_bg);
        name_handler.draw(window);

        window.draw(card_holder);
        window.draw(card_stat_attack_bg);
        attack_handler.draw(window);
        window.draw(card_stat_health_bg);
        health_handler.draw(window);
    }

    bool check_hover(Vector2i mouse_position)
    {
        if ((mouse_position.x > card_bg.getGlobalBounds().left) && (mouse_position.x < card_bg.getGlobalBounds().left + card_bg.getGlobalBounds().width) && (mouse_position.y > card_bg.getGlobalBounds().top) && (mouse_position.y < card_bg.getGlobalBounds().top + card_bg.getGlobalBounds().height) && hoverable)
        {
            if (animate_offset_hover.y > -20)
            {
                animate_offset_hover.y--;
            }
            return true;
        }
        if (animate_offset_hover.y < 0)
        {
            animate_offset_hover.y++;
        }
        return false;
    }

    void check_press(Vector2i mouse_position)
    {
        if ((Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd < 10))
        {
            if ((mouse_position.x > card_bg.getGlobalBounds().left) && (mouse_position.x < card_bg.getGlobalBounds().left + card_bg.getGlobalBounds().width) && (mouse_position.y > card_bg.getGlobalBounds().top) && (mouse_position.y < card_bg.getGlobalBounds().top + card_bg.getGlobalBounds().height) && pressable)
            {
                mouse_press_cd++;
            }
        }
        if ((!Mouse::isButtonPressed(Mouse::Left)) && (mouse_press_cd >= 10))
        {
            mouse_press_cd = 0;
            on_press();
        }
    }

    void on_press()
    {
        is_pressed = true;
        //cout << "Pressed on dinocard";
    }
};

class BattlePool
{
public:
    Pool* player_pool;
    vector<Texture*> dino_bg;
    vector<Texture*> dino_holder;
    vector<Texture*> dino_stat_holder;
    vector<Texture*> dino_holder_glow;
    Vector2i pos;
    Vector2i animation_pos;
    vector<DinoBattleCard> slots;
    bool animate_to_down = false;
    bool animate_to_up = false;
    bool animate_from_down = false;
    bool animate_from_up = false;
    bool animation_to_completed = false;
    bool animation_from_completed = false;

    BattlePool(Pool* player_pool_got, vector<Texture*> dino_bg_got, vector<Texture*> dino_holder_got, vector<Texture*> dino_stat_holder_got, vector<Texture*> dino_holder_glow_got)
    {
        player_pool = player_pool_got;
        for (size_t i = 0; i < dino_bg_got.size(); i++)
        {
            dino_bg.push_back(dino_bg_got[i]);
        }
        for (size_t i = 0; i < dino_holder_got.size(); i++)
        {
            dino_holder.push_back(dino_holder_got[i]);
        }
        for (size_t i = 0; i < dino_stat_holder_got.size(); i++)
        {
            dino_stat_holder.push_back(dino_stat_holder_got[i]);
        }
        for (size_t i = 0; i < dino_holder_glow_got.size(); i++)
        {
            dino_holder_glow.push_back(dino_holder_glow_got[i]);
        }
        Dino service_dino;
        service_dino.changeName("This is a bug");
        DinoBattleCard service_slot(&service_dino, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
        slots.push_back(service_slot);
        slots.push_back(service_slot);
        slots.push_back(service_slot);
        pos.x = 0;
        pos.y = 0;
        animation_pos.x = 0;
        animation_pos.y = 0;
    }

    ~BattlePool() {}

    void update(Terrain terrain)
    {
        if (player_pool->slot1 != NULL)
        {
            DinoBattleCard slot1(player_pool->slot1, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[0] = slot1;
            slots[0].name_handler.init(slots[0].name_handler.text.getString());
            slots[0].attack_handler.init(to_string(slots[0].dino->damage(terrain)));
            slots[0].health_handler.init(to_string(slots[0].dino->get_hp()));
        }
        if (player_pool->slot2 != NULL)
        {
            DinoBattleCard slot2(player_pool->slot2, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[1] = slot2;
            slots[1].name_handler.init(slots[1].name_handler.text.getString());
            slots[1].attack_handler.init(to_string(slots[1].dino->damage(terrain)));
            slots[1].health_handler.init(to_string(slots[1].dino->get_hp()));
        }
        if (player_pool->slot3 != NULL)
        {
            DinoBattleCard slot3(player_pool->slot3, dino_bg, dino_holder, dino_stat_holder, dino_holder_glow);
            slots[2] = slot3;
            slots[2].name_handler.init(slots[2].name_handler.text.getString());
            slots[2].attack_handler.init(to_string(slots[2].dino->damage(terrain)));
            slots[2].health_handler.init(to_string(slots[2].dino->get_hp()));
        }
    }

    void set_position(int x, int y)
    {
        if (animate_to_up && (animation_pos.y > -500))
        {
            animation_pos.y--;
            if (animation_pos.y == -500)
            {
                animate_to_up = false;
                animation_to_completed = true;
            }
        }
        if (animate_to_down && (animation_pos.y < 500))
        {
            animation_pos.y++;
            if (animation_pos.y == 500)
            {
                animate_to_down = false;
                animation_to_completed = true;
            }
        }
        if (animate_from_down && (animation_pos.y > 0))
        {
            animation_pos.y--;
            if (animation_pos.y == 0)
            {
                animate_from_down = false;
                animation_from_completed = true;
            }
        }
        if (animate_from_up && (animation_pos.y < 0))
        {
            animation_pos.y++;
            if (animation_pos.y == 0)
            {
                animate_from_up = false;
                animation_from_completed = true;
            }
        }

        pos.x = x + animation_pos.x;
        pos.y = y + animation_pos.y;
    }

    void draw(RenderWindow& window)
    {
        if (player_pool->slot1 != NULL)
        {
            slots[0].set_position(pos.x, pos.y);
            slots[0].draw(window);
        }
        if (player_pool->slot2 != NULL)
        {
            slots[1].set_position(pos.x + 240, pos.y + 30);
            slots[1].draw(window);
        }
        if (player_pool->slot3 != NULL)
        {
            slots[2].set_position(pos.x + 480, pos.y + 60);
            slots[2].draw(window);
        }
    }

    void set_visual()
    {
        slots[0].hoverable = false;
        slots[0].pressable = false;
        slots[1].hoverable = false;
        slots[1].pressable = false;
        slots[2].hoverable = false;
        slots[2].pressable = false;
    }
};

class Fight
{
public:
    Vector2i pos;
    DinoBattleCard* atacker;
    DinoBattleCard* defender;
    TextHandler dmg_on_atacker;
    TextHandler dmg_on_defender;
    int offset;
    bool animate_collision = false;
    bool animation_completed = false;
    int damage_animation_cd = 0;
    int death_animation_cd = 0;
    bool fight_completed = false;

    RectangleShape death_medallion_atacker;
    RectangleShape death_medallion_defender;
    Texture* death_medallion_texture;

    Fight(Texture* death_icon_texture)
    {
        death_medallion_texture = death_icon_texture;
        death_medallion_atacker.setSize(Vector2f(220, 220));
        death_medallion_atacker.setTexture(death_medallion_texture, true);
        death_medallion_defender.setSize(Vector2f(220, 220));
        death_medallion_defender.setTexture(death_medallion_texture, true);
        
        pos.x = 0;
        pos.y = 0;
        offset = 0;
    }

    ~Fight() {}

    void set_attacker(DinoBattleCard* atacker_got)
    {
        atacker = atacker_got;
    }

    void set_defender(DinoBattleCard* defender_got)
    {
        defender = defender_got;
    }

    void set_position(int x, int y, RenderWindow& window, Terrain terrain)
    {
        if (animate_collision && (offset < (window.getSize().x + 50) / 2))
        {
            offset++;
            if (offset == (window.getSize().x + 50) / 2)
            {
                animation_completed = true;
                animate_collision = false;
                dmg_on_atacker.init("-" + to_string(defender->dino->damage(terrain)));
                dmg_on_defender.init("-" + to_string(atacker->dino->damage(terrain)));
                dmg_on_atacker.text.setCharacterSize(80);
                dmg_on_defender.text.setCharacterSize(80);
                damage_animation_cd = 2000;
            }
        }
        pos.x = x;
        pos.y = (window.getSize().y - atacker->card_bg.getSize().y) / 2;

        Vector2i atacker_pos;
        atacker_pos.x = -50 - atacker->card_bg.getSize().x + offset;
        atacker_pos.y = pos.y;

        Vector2i defender_pos;
        defender_pos.x = 50 + window.getSize().x - offset;
        defender_pos.y = pos.y;

        atacker->set_position(atacker_pos.x, atacker_pos.y);
        defender->set_position(defender_pos.x, defender_pos.y);
        if (animation_completed)
        {
            dmg_on_atacker.set_position(atacker->card_bg.getPosition().x + (atacker->card_bg.getSize().x / 2) - (dmg_on_defender.text.getLocalBounds().width / 2), pos.y + atacker->card_bg.getSize().y / 2 - (dmg_on_defender.text.getLocalBounds().height));
            dmg_on_defender.set_position(defender->card_bg.getPosition().x + (defender->card_bg.getSize().x / 2) - (dmg_on_atacker.text.getLocalBounds().width / 2), pos.y + defender->card_bg.getSize().y / 2 - (dmg_on_atacker.text.getLocalBounds().height));
        }


        death_medallion_atacker.setPosition(atacker_pos.x + (atacker->card_bg.getSize().x - death_medallion_atacker.getSize().x) / 2, 
            atacker_pos.y + (atacker->card_bg.getSize().y - death_medallion_atacker.getSize().y) / 2);
        death_medallion_defender.setPosition(defender_pos.x + (defender->card_bg.getSize().x - death_medallion_defender.getSize().x) / 2,
            defender_pos.y + (defender->card_bg.getSize().y - death_medallion_defender.getSize().y) / 2);
    }

    void draw(RenderWindow& window)
    {
        atacker->draw(window);
        defender->draw(window);
        if (animation_completed && (damage_animation_cd > 0))
        {
            dmg_on_atacker.draw(window);
            dmg_on_defender.draw(window);
            damage_animation_cd--;
            if (damage_animation_cd == 0)
            {
                atacker->dino->get_damage(-1 * stoi(string(dmg_on_atacker.text.getString())));
                defender->dino->get_damage(-1 * stoi(string(dmg_on_defender.text.getString())));
                atacker->health = atacker->dino->get_hp();
                atacker->health_handler.init(to_string(atacker->health));
                defender->health = defender->dino->get_hp();
                defender->health_handler.init(to_string(defender->health));
                death_animation_cd = 4000;
            }
            //cout << animation_cd << endl;
        }
        if (animation_completed && (death_animation_cd > 0))
        {
            if (atacker->dino->get_hp() <= 0)
            {
                window.draw(death_medallion_atacker);
            }
            if (defender->dino->get_hp() <= 0)
            {
                window.draw(death_medallion_defender);
            }
            
            death_animation_cd--;
            if (death_animation_cd == 0)
            {
                animation_completed = false;
                fight_completed = true;
                offset = 0;
            }
        }
    }
};

void go_to_battle(Velociraptor& enemy_vel, Triceratops& enemy_tri, Dilophosaurus& enemy_dil, Pool& enemyPool, Pool& playerPool)
{
    if (playerPool.slot1 != NULL)
    {
        enemy_vel = Velociraptor();
        enemyPool.add(&enemy_vel);
    }
    if (playerPool.slot2 != NULL)
    {
        enemy_tri = Triceratops();
        enemyPool.add(&enemy_tri);
    }
    if (playerPool.slot3 != NULL)
    {
        enemy_dil = Dilophosaurus();
        enemyPool.add(&enemy_dil);
    }
}

void go_out_of_battle(Pool& enemyPool)
{
    enemyPool.remove(1);
    enemyPool.remove(2);
    enemyPool.remove(3);
}

class EndBattleInfoTable
{
public:
    TextHandler status_text;
    TextHandler money_got;
    int animation_time = 0;

    EndBattleInfoTable()
    {
        status_text.init("This is a bug");
        money_got.init("You got 0 coins!");

        status_text.text.setCharacterSize(100);
        money_got.text.setCharacterSize(40);

        status_text.update(status_text.text.getString());
        money_got.update(money_got.text.getString());
    }

    ~EndBattleInfoTable() {}

    void update(string new_status, int money)
    {
        status_text.update(new_status);
        money_got.update("You got " + to_string(money) + " coins!");
        animation_time = 4000;
    }

    void set_position(RenderWindow& window)
    {
        status_text.set_position(window.getSize().x / 2 - status_text.width / 2, window.getSize().y / 2 - status_text.height);
        money_got.set_position(window.getSize().x / 2 - money_got.width / 2, window.getSize().y / 2 + 20);
    }

    void draw(RenderWindow& window)
    {
        if (animation_time > 0)
        {
            animation_time--;
        }
        status_text.draw(window);
        money_got.draw(window);
    }
};

int main()
{
    //Инициализация пользовательских структур
    Balance balance;
    Terrain terrain;
    Box box;
    Pool playerPool;
    Pool enemyPool;
    Pool shopPool;
    Velociraptor enemy_vel;
    Triceratops enemy_tri;
    Dilophosaurus enemy_dil;
    Velociraptor shop_vel;
    Triceratops shop_tri;
    Dilophosaurus shop_dil;
    Dino* shop_selector;


    //Создание окна
    RenderWindow window(VideoMode(1344, 840), "Dinosaur battle"); //896, 696

    //Импорт ассетов
    Texture background_river;
    background_river.loadFromFile("./assets/river_bg.png");
    Texture background_plain;
    background_plain.loadFromFile("./assets/plains_bg.png");
    Texture background_mountain;
    background_mountain.loadFromFile("./assets/mountain_bg.png");
    Texture background_idle;
    background_idle.loadFromFile("./assets/idle_bg.png");
    Texture background_shop;
    background_shop.loadFromFile("./assets/shop.png");
    Font font;
    font.loadFromFile("./assets/benguiat_bold.ttf");

    vector<Texture*> dino_card_bg;
    Texture velociraptor_card_bg;
    velociraptor_card_bg.loadFromFile("./assets/velociraptor.png");
    dino_card_bg.push_back(&velociraptor_card_bg);
    Texture triceratops_card_bg;
    triceratops_card_bg.loadFromFile("./assets/triceratops.png");
    dino_card_bg.push_back(&triceratops_card_bg);
    Texture dilophosaurus_card_bg;
    dilophosaurus_card_bg.loadFromFile("./assets/dilophosaurus.png");
    dino_card_bg.push_back(&dilophosaurus_card_bg);

    vector<Texture*> dino_card_holder;
    Texture card_bg_intelligence;
    card_bg_intelligence.loadFromFile("./assets/card_bg_intelligence.png");
    dino_card_holder.push_back(&card_bg_intelligence);
    Texture card_bg_strength;
    card_bg_strength.loadFromFile("./assets/card_bg_strength.png");
    dino_card_holder.push_back(&card_bg_strength);
    Texture card_bg_dexterity;
    card_bg_dexterity.loadFromFile("./assets/card_bg_dexterity.png");
    dino_card_holder.push_back(&card_bg_dexterity);

    vector<Texture*> dino_card_stat_holder;
    Texture card_stat_bg_intelligence;
    card_stat_bg_intelligence.loadFromFile("./assets/card_stat_holder_intelligence.png");
    dino_card_stat_holder.push_back(&card_stat_bg_intelligence);
    Texture card_stat_bg_strength;
    card_stat_bg_strength.loadFromFile("./assets/card_stat_holder_strength.png");
    dino_card_stat_holder.push_back(&card_stat_bg_strength);
    Texture card_stat_bg_dexterity;
    card_stat_bg_dexterity.loadFromFile("./assets/card_stat_holder_dexterity.png");
    dino_card_stat_holder.push_back(&card_stat_bg_dexterity);
    Texture card_stat_bg_cost;
    card_stat_bg_cost.loadFromFile("./assets/card_stat_holder_cost.png");
    dino_card_stat_holder.push_back(&card_stat_bg_cost);

    vector<Texture*> dino_battle_card_stat_holder;
    Texture card_stat_bg_attack;
    card_stat_bg_attack.loadFromFile("./assets/card_stat_holder_attack.png");
    dino_battle_card_stat_holder.push_back(&card_stat_bg_attack);
    Texture card_stat_bg_health;
    card_stat_bg_health.loadFromFile("./assets/card_stat_holder_health.png");
    dino_battle_card_stat_holder.push_back(&card_stat_bg_health);

    vector<Texture*> dino_card_holder_glow;
    Texture card_bg_intelligence_glow;
    card_bg_intelligence_glow.loadFromFile("./assets/card_bg_intelligence_glow.png");
    dino_card_holder_glow.push_back(&card_bg_intelligence_glow);
    Texture card_bg_strength_glow;
    card_bg_strength_glow.loadFromFile("./assets/card_bg_strength_glow.png");
    dino_card_holder_glow.push_back(&card_bg_strength_glow);
    Texture card_bg_dexterity_glow;
    card_bg_dexterity_glow.loadFromFile("./assets/card_bg_dexterity_glow.png");
    dino_card_holder_glow.push_back(&card_bg_dexterity_glow);

    vector<Texture*> dino_card_holder_battle_glow;
    Texture card_bg_intelligence_battle_glow;
    card_bg_intelligence_battle_glow.loadFromFile("./assets/card_bg_intelligence_battle_glow.png");
    dino_card_holder_battle_glow.push_back(&card_bg_intelligence_battle_glow);
    Texture card_bg_strength_battle_glow;
    card_bg_strength_battle_glow.loadFromFile("./assets/card_bg_strength_battle_glow.png");
    dino_card_holder_battle_glow.push_back(&card_bg_strength_battle_glow);
    Texture card_bg_dexterity_battle_glow;
    card_bg_dexterity_battle_glow.loadFromFile("./assets/card_bg_dexterity_battle_glow.png");
    dino_card_holder_battle_glow.push_back(&card_bg_dexterity_battle_glow);

    Texture location_info_holder_idle;
    location_info_holder_idle.loadFromFile("./assets/title_handler_idle.png");
    Texture location_info_holder_battle;
    location_info_holder_battle.loadFromFile("./assets/title_handler_battle.png");
    Texture location_info_holder_shop;
    location_info_holder_shop.loadFromFile("./assets/title_handler_shop.png");

    vector<Texture*> button_textures;
    Texture button_texture;
    button_texture.loadFromFile("./assets/button.png");
    button_textures.push_back(&button_texture);
    Texture button_hover_texture;
    button_hover_texture.loadFromFile("./assets/button_hover.png");
    button_textures.push_back(&button_hover_texture);

    vector<Texture*> button_textures_red;
    Texture button_texture_red;
    button_texture_red.loadFromFile("./assets/button_red.png");
    button_textures_red.push_back(&button_texture_red);
    Texture button_hover_texture_red;
    button_hover_texture_red.loadFromFile("./assets/button_red_hover.png");
    button_textures_red.push_back(&button_hover_texture_red);

    Texture dead_icon;
    dead_icon.loadFromFile("./assets/dead_icon.png");
    
    Image icon;
    icon.loadFromFile("./assets/dead_icon.png");

    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    //Создание бэкграунда
    Sprite background(background_shop);

    //Создание подписи локации
    Text location_text_info("", font);
    location_text_info.setCharacterSize(30);
    location_text_info.setStyle(Text::Bold);
    location_text_info.setFillColor(Color::Black);
    location_text_info.setPosition(0, 76);
    RectangleShape location_text_info_background;
    Vector2f location_text_info_background_size(360, 100);
    location_text_info_background.setSize(location_text_info_background_size);
    //location_text_info_background.setFillColor(Color(250, 10, 10, 255));
    location_text_info_background.setPosition((window.getSize().x - location_text_info_background_size.x) / 2, 50);


    Gamestage gamestage = Idle;

    //// Создание экземляров для боёвки
    BattlePool player_battle_pool(&playerPool, dino_card_bg, dino_card_holder, dino_battle_card_stat_holder, dino_card_holder_battle_glow);
    BattlePool enemy_battle_pool(&enemyPool, dino_card_bg, dino_card_holder, dino_battle_card_stat_holder, dino_card_holder_battle_glow);

    Fight fight = Fight(&dead_icon);

    DinoBattleCard* atacker = NULL;
    DinoBattleCard* defender = NULL;

    int money_increment = 0;

    EndBattleInfoTable end_battle_info_tab;
    
    ///*Triceratops test_battle_dino;
    //DinoBattleCard battle_dinocard(&test_battle_dino, dino_card_bg, dino_card_holder, dino_battle_card_stat_holder, dino_card_holder_battle_glow);*/


    // Создание экземпляров для инвентаря

    CardInventory card_inventory(box, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
    InventoryPool inventory_pool(&playerPool, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
    inventory_pool.update();
    Button exit_idle_button = Button(button_textures);
    exit_idle_button.set_position(100, window.getSize().y - 200);
    //exit_idle_button.background.setFillColor(Color(0, 255, 0, 255));
    

    //Создание карточек в магазине

    go_to_shop(shop_vel, shop_tri, shop_dil, shopPool);

    DinoCard shopcard1(shopPool.slot1, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
    DinoCard shopcard2(shopPool.slot2, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
    DinoCard shopcard3(shopPool.slot3, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
    DinoCard* selected_shopcard;

    Button confirm_button = Button(button_textures);
    //confirm_button.background.setFillColor(Color(0, 255, 0, 255));
    Button reject_button = Button(button_textures_red);
    Button exit_shop_button = Button(button_textures_red);
    exit_shop_button.set_position(window.getSize().x - 300, window.getSize().y - 200);

    RectangleShape background_blur;
    Vector2f background_blur_size(window.getSize().x, window.getSize().y);
    background_blur.setSize(background_blur_size);
    background_blur.setFillColor(Color(0, 0, 0, 200));
    background_blur.setPosition(0, 0);

    TextHandler balance_handler;
    balance_handler.init(("Current balance: " + to_string(balance.money))); //string("Current balance: ", balance.money)
    balance_handler.set_position((window.getSize().x - balance_handler.width) / 2, window.getSize().y - 100);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseWheelScrolled)
            {
                //cout << "Scrolled a wheel: " << event.mouseWheel.delta << endl;
                /*if (event.mouseWheelScroll.delta > 0)
                {
                    cout << "Scrolled a wheel up: " << event.mouseWheelScroll.delta << endl;
                }
                else
                {
                    cout << "Scrolled a wheel down: " << event.mouseWheelScroll.delta << endl;
                }*/
                card_inventory.scroll_value = event.mouseWheelScroll.delta;
            }
        }

        window.clear();

        switch (gamestage)
        {
        case Idle:
            background.setTexture(background_idle, true);
            //background.setTexture(background_idle);
            //background.setColor(Color::White);
            center_text(location_text_info, "lobby", window);
            location_text_info.setPosition(335, 47);
            location_text_info_background.setTexture(&location_info_holder_idle);
            location_text_info_background.setPosition(200, 20);

            window.draw(background);
            window.draw(location_text_info_background);
            window.draw(location_text_info);

            
            //cout << card_inventory.cards[0].name;
            card_inventory.set_position(760, 0);
            card_inventory.draw(window);

            for (size_t i = 0; i < card_inventory.cards.size(); i++)
            {
                if (card_inventory.cards[i].ready_to_check)
                {
                    playerPool.add(card_inventory.cards[i].dino);
                    inventory_pool.update();
                    //cout << "Added dino to player pool: " << playerPool.slot1->get_cost() << endl;
                    card_inventory.cards[i].ready_to_check = false;
                    card_inventory.cards[i].hoverable = true;
                    card_inventory.cards[i].pressable = true;
                    card_inventory.cards[i].animate_press_from = true;
                }
            }

            for (size_t i = 0; i < 3; i++)
            {
                if (inventory_pool.slots[i].ready_to_check)
                {
                    inventory_pool.slots[i].hoverable = true;
                    inventory_pool.slots[i].pressable = true;
                    inventory_pool.slots[i].ready_to_check = false;
                    playerPool.remove(i + 1);
                }
            }

            inventory_pool.draw(window);

            exit_idle_button.draw(window);

            if (exit_idle_button.is_pressed)
            {
                exit_idle_button.is_pressed = false;
                if (!playerPool.isEmpty())
                {
                    switch (rand() % 3)
                    {
                    case 0:
                        terrain = Plain;
                        break;
                    case 1:
                        terrain = River;
                        break;
                    case 2:
                        terrain = Mountain;
                        break;
                    }
                    go_to_battle(enemy_vel, enemy_tri, enemy_dil, enemyPool, playerPool);
                    for (size_t i = 0; i < player_battle_pool.slots.size(); i++)
                    {
                        player_battle_pool.slots[i].dino->heal();
                    }
                    for (size_t i = 0; i < enemy_battle_pool.slots.size(); i++)
                    {
                        enemy_battle_pool.slots[i].dino->heal();
                    }
                    player_battle_pool.update(terrain);
                    enemy_battle_pool.update(terrain);
                    enemy_battle_pool.set_visual();
                    gamestage = Battle;
                }
            }

            break;



        case Battle:
            switch (terrain)
            {
            case Plain:
                background.setTexture(background_plain, true);
                break;
            case River:
                background.setTexture(background_river, true);
                break;
            case Mountain:
                background.setTexture(background_mountain, true);
                break;
            default:
                background.setTexture(background_shop, true);
                break;
            }

            center_text(location_text_info, "battle", window);
            location_text_info_background.setTexture(&location_info_holder_battle);
            //location_text_info_background.setPosition((window.getSize().x - location_text_info_background_size.x) / 2, 50);
            location_text_info.setPosition(230, 47);
            location_text_info_background.setPosition(100, 20);

            window.draw(background);
            window.draw(location_text_info_background);
            window.draw(location_text_info);

            player_battle_pool.set_position(20, 400);
            enemy_battle_pool.set_position(590, 30);
            //player_battle_pool.set_position(200, 200);
            player_battle_pool.draw(window);
            enemy_battle_pool.draw(window);


            if (player_battle_pool.slots[0].is_pressed)
            {
                player_battle_pool.animate_to_down = true;
                player_battle_pool.slots[0].is_pressed = false;
                atacker = &player_battle_pool.slots[0];
                atacker->hoverable = false;
                atacker->pressable = false;
            }
            if (player_battle_pool.slots[1].is_pressed)
            {
                player_battle_pool.animate_to_down = true;
                player_battle_pool.slots[1].is_pressed = false;
                atacker = &player_battle_pool.slots[1];
                atacker->hoverable = false;
                atacker->pressable = false;
            }
            if (player_battle_pool.slots[2].is_pressed)
            {
                player_battle_pool.animate_to_down = true;
                player_battle_pool.slots[2].is_pressed = false;
                atacker = &player_battle_pool.slots[2];
                atacker->hoverable = false;
                atacker->pressable = false;
            }

            if (player_battle_pool.animation_to_completed)
            {
                enemy_battle_pool.animate_to_up = true;
                player_battle_pool.animation_to_completed = false;
            }

            if (enemy_battle_pool.animation_to_completed)
            {
                while (true)
                {
                    switch (rand() % 3)
                    {
                    case 0:
                        if (enemyPool.slot1 != NULL)
                        {
                            defender = &enemy_battle_pool.slots[0];
                        }
                        break;
                    case 1:
                        if (enemyPool.slot2 != NULL)
                        {
                            defender = &enemy_battle_pool.slots[1];
                        }
                        break;
                    case 2:
                        if (enemyPool.slot3 != NULL)
                        {
                            defender = &enemy_battle_pool.slots[2];
                        }
                        break;
                    }
                    if (defender != NULL)
                    {
                        fight.set_attacker(atacker);
                        fight.set_defender(defender);
                        fight.animate_collision = true;
                        break;
                    }
                }

                enemy_battle_pool.animation_to_completed = false;
            }
            
            if (fight.animate_collision || fight.animation_completed)
            {
                fight.set_position(0, 0, window, terrain);
                fight.draw(window);
            }

            if (fight.fight_completed)
            {
                atacker->hoverable = true;
                atacker->pressable = true;
                player_battle_pool.animate_from_down = true;
                enemy_battle_pool.animate_from_up = true;
                fight.fight_completed = false;
                
                if ((playerPool.slot1 != NULL) && (playerPool.slot1->get_hp() <= 0))
                {
                    playerPool.slot1 = NULL;
                }
                if ((playerPool.slot2 != NULL) && (playerPool.slot2->get_hp() <= 0))
                {
                    playerPool.slot2 = NULL;
                }
                if ((playerPool.slot3 != NULL) && (playerPool.slot3->get_hp() <= 0))
                {
                    playerPool.slot3 = NULL;
                }

                if ((enemyPool.slot1 != NULL) && (enemyPool.slot1->get_hp() <= 0))
                {
                    enemyPool.slot1 = NULL;
                }
                if ((enemyPool.slot2 != NULL) && (enemyPool.slot2->get_hp() <= 0))
                {
                    enemyPool.slot2 = NULL;
                }
                if ((enemyPool.slot3 != NULL) && (enemyPool.slot3->get_hp() <= 0))
                {
                    enemyPool.slot3 = NULL;
                }

                atacker = NULL;
                defender = NULL;
            }

            if (player_battle_pool.animation_from_completed)
            {
                player_battle_pool.animation_from_completed = false;
            }
            
            if (enemy_battle_pool.animation_from_completed)
            {
                enemy_battle_pool.animation_from_completed = false;
                if (playerPool.isEmpty())
                {
                    go_to_shop(shop_vel, shop_tri, shop_dil, shopPool);

                    DinoCard shopcard1_new(shopPool.slot1, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard1 = shopcard1_new;
                    DinoCard shopcard2_new(shopPool.slot2, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard2 = shopcard2_new;
                    DinoCard shopcard3_new(shopPool.slot3, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard3 = shopcard3_new;

                    shopcard1.name_handler.init(shopcard1.name_handler.text.getString());
                    shopcard1.i_handler.init(shopcard1.i_handler.text.getString());
                    shopcard1.s_handler.init(shopcard1.s_handler.text.getString());
                    shopcard1.d_handler.init(shopcard1.d_handler.text.getString());
                    shopcard1.cost_handler.init(shopcard1.cost_handler.text.getString());

                    shopcard2.name_handler.init(shopcard2.name_handler.text.getString());
                    shopcard2.i_handler.init(shopcard2.i_handler.text.getString());
                    shopcard2.s_handler.init(shopcard2.s_handler.text.getString());
                    shopcard2.d_handler.init(shopcard2.d_handler.text.getString());
                    shopcard2.cost_handler.init(shopcard2.cost_handler.text.getString());

                    shopcard3.name_handler.init(shopcard3.name_handler.text.getString());
                    shopcard3.i_handler.init(shopcard3.i_handler.text.getString());
                    shopcard3.s_handler.init(shopcard3.s_handler.text.getString());
                    shopcard3.d_handler.init(shopcard3.d_handler.text.getString());
                    shopcard3.cost_handler.init(shopcard3.cost_handler.text.getString());

                    go_out_of_battle(enemyPool);
                    gamestage = Battle_end;
                    end_battle_info_tab.update("Loser", 0);
                }
                else if (enemyPool.isEmpty())
                {
                    go_to_shop(shop_vel, shop_tri, shop_dil, shopPool);

                    DinoCard shopcard1_new(shopPool.slot1, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard1 = shopcard1_new;
                    DinoCard shopcard2_new(shopPool.slot2, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard2 = shopcard2_new;
                    DinoCard shopcard3_new(shopPool.slot3, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    shopcard3 = shopcard3_new;

                    shopcard1.name_handler.init(shopcard1.name_handler.text.getString());
                    shopcard1.i_handler.init(shopcard1.i_handler.text.getString());
                    shopcard1.s_handler.init(shopcard1.s_handler.text.getString());
                    shopcard1.d_handler.init(shopcard1.d_handler.text.getString());
                    shopcard1.cost_handler.init(shopcard1.cost_handler.text.getString());

                    shopcard2.name_handler.init(shopcard2.name_handler.text.getString());
                    shopcard2.i_handler.init(shopcard2.i_handler.text.getString());
                    shopcard2.s_handler.init(shopcard2.s_handler.text.getString());
                    shopcard2.d_handler.init(shopcard2.d_handler.text.getString());
                    shopcard2.cost_handler.init(shopcard2.cost_handler.text.getString());

                    shopcard3.name_handler.init(shopcard3.name_handler.text.getString());
                    shopcard3.i_handler.init(shopcard3.i_handler.text.getString());
                    shopcard3.s_handler.init(shopcard3.s_handler.text.getString());
                    shopcard3.d_handler.init(shopcard3.d_handler.text.getString());
                    shopcard3.cost_handler.init(shopcard3.cost_handler.text.getString());

                    gamestage = Battle_end;
                    money_increment = 10 + (rand() % 20);
                    balance + money_increment;
                    end_battle_info_tab.update("Winner", money_increment);
                }
            }

            

            break;



        case Shop:
            shopcard1.set_position(window.getSize().x / 2 - 1.8 * shopcard1.card_bg.getSize().x, 200);
            shopcard2.set_position((window.getSize().x - shopcard2.card_bg.getSize().x) / 2, 200);
            shopcard3.set_position(window.getSize().x / 2 + 0.8 * shopcard1.card_bg.getSize().x, 200);

            //shopcard2.hoverable = false;

            background.setTexture(background_shop, true);
            location_text_info.setPosition(0, 76);
            center_text(location_text_info, "shop", window);
            location_text_info_background.setTexture(&location_info_holder_shop);
            location_text_info_background.setPosition((window.getSize().x - location_text_info_background_size.x) / 2, 50);

            window.draw(background);
            window.draw(location_text_info_background);
            window.draw(location_text_info);
            shopcard1.draw(window);
            shopcard2.draw(window);
            shopcard3.draw(window);

            selected_shopcard = check_for_confirm(&shopcard1, &shopcard2, &shopcard3);

            if (selected_shopcard != NULL)
            {
                window.draw(background_blur);
                selected_shopcard->set_position((window.getSize().x - selected_shopcard->card_bg.getSize().x) / 2 + 150, 150);
                selected_shopcard->animate_press_from = true;
                selected_shopcard->draw(window);
                confirm_button.set_position((window.getSize().x - selected_shopcard->card_bg.getSize().x) / 2 - 50, 150);
                reject_button.set_position((window.getSize().x - selected_shopcard->card_bg.getSize().x) / 2 - 50, 350);
                confirm_button.draw(window);
                reject_button.draw(window);
            }

            if (selected_shopcard == NULL)
            {
                exit_shop_button.draw(window);
            }

            balance_handler.update(("Current balance: " + to_string(balance.money))); //string("Current balance: ", balance.money)
            balance_handler.set_position((window.getSize().x - balance_handler.width) / 2, window.getSize().y - 100);
            balance_handler.draw(window);

            if (reject_button.is_pressed)
            {
                if (selected_shopcard != NULL)
                {
                    selected_shopcard->ready_to_check = false;
                }
                reject_button.is_pressed = false;
            }

            if (confirm_button.is_pressed)
            {
                if ((selected_shopcard != NULL) && (balance.can_afford(selected_shopcard->cost)))
                {
                    balance - selected_shopcard->cost;
                    //selected_shopcard->dino->printCard();
                    box.add(selected_shopcard->dino);

                    box.re_init();
                    card_inventory.re_init(box, dino_card_bg, dino_card_holder, dino_card_stat_holder, dino_card_holder_glow);
                    
                    selected_shopcard->ready_to_check = false;

                    gamestage = Idle;
                    go_out_of_shop(shopPool);
                }
                confirm_button.is_pressed = false;
            }

            if (exit_shop_button.is_pressed)
            {
                gamestage = Idle;
                go_out_of_shop(shopPool);
                exit_shop_button.is_pressed = false;
            }



            break;



        case Battle_end:
            end_battle_info_tab.set_position(window);
            end_battle_info_tab.draw(window);
            if (end_battle_info_tab.animation_time == 0)
            {
                gamestage = Shop;
            }


            break;
        }

        //window.draw(background);
        //window.draw(location_text_info_background);
        //window.draw(location_text_info);

        window.display();
    }

    go_out_of_shop(shopPool);

    return 0;
}