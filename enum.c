enum Color
{
   RED=3, BLACK
};

enum
{
    False,
    True
};

int main()
{
   enum Color c=RED;
   if (c==RED) c=BLACK+True;

   return c;
}
