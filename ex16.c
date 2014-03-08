#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
    struct Person *who = malloc(sizeof(struct Person));
    assert(who != NULL);

    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

void Person_destroy(struct Person *who)
{
    assert(who != NULL);

    free(who->name);
    free(who);
}

void Person_print(struct Person *who)
{
    struct Person this = *who;

    printf("Name: %s\n", this.name);
    printf("\tAge: %d\n", this.age);
    printf("\tHeight: %d\n", this.height);
    printf("\tWeight: %d\n", this.weight);
}

int main(int argc, char *argv[])
{
    struct Person *joe = Person_create("Joe Bro", 32, 64, 140);
    struct Person *frank = Person_create("frank bro", 20, 72, 180);

    printf("Joe is at the memory location %p:\n", joe);
    Person_print(joe);
    printf("Frank is at the memory location %p:\n", frank);
    Person_print(frank);

    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
