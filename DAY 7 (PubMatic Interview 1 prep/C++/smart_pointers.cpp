#include <iostream>
#include <memory>

class Entity
{
public:
    Entity()
    {
        std::cout << "Entity Created!\n";
    }

    void print()
    {
        std::cout << "Hello\n";
    }

    ~Entity()
    {
        std::cout << "Entity Destroyed!\n";
    }
};

int main()
{
    // Raw Pointer
    // Entity *entity(new Entity());
    // entity->print();
    // delete (entity); // free the heap memory
    // entity = nullptr; // assign the obj pointer to nullptr, to avoid dangling pointer like scenario

    // Unique Pointer
    // std::unique_ptr<Entity> entity = std::make_unique<Entity>();
    // std::unique_ptr<Entity> e0 = std::move(entity);
    // entity->print();
    // e0->print();

    // Shared pointers and weak pointers
    std::weak_ptr<Entity> ent_shared;
    {
        std::shared_ptr<Entity> ent_shared_1 = std::make_shared<Entity>();
        ent_shared = ent_shared_1;
    }
    return 0;
}