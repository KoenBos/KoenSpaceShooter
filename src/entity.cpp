// entity.cpp

#include "entity.h"

Entity::Entity(Texture2D t)
{
    texture = t;
}

Entity::~Entity()
{

}

void Entity::show()
{
    DrawTexture(texture, this->x, this->y, WHITE);
}
