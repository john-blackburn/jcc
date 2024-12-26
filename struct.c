struct Point
{
    int x;
    int y;
};

struct Point gp;

int test(struct Point* p, int s)
{
    return s*p->x;
}

int main()
{
    struct Point p[3];
    struct Point *pp;
    
    struct Point q;
    q.x=10;
    q.y=20;
    
    p[0].x=1;
    p[0].y=3;

    p[1].x=11;
    p[1].y=22;
    
    pp=&q;
    pp->y = 3 + pp->x; // 13
    
    return p[1].y+q.y+test(pp,20); // 22+13+10*20 = 235
}
