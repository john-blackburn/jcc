struct Point
{
    int x,y;
};

struct Rect
{
    struct Point top;
    struct Point bot;
};

struct Point addPoints(struct Point p, struct Point q)
{
    struct Point tot;
    tot.x = p.x + q.x;
    tot.y = p.y + q.y;
        
    return tot;
}

int main()
{
    struct Rect r,s;
    
    r.top.x=1;
    r.top.y=2;

    r.bot.x=3;
    r.bot.y=4;
    
    struct Point another;
    another.x=10;
    another.y=20;

    s=r;
    s.top=another;
    
    struct Point p;
    p = addPoints(another, r.top);

    printf("%d %d\n",p.x,p.y);

    return s.bot.y + s.top.x;
}
