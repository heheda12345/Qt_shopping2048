#include "mover.h"
using std::fstream;
using std::ios;

Mover::Mover()
{
    for (int i=0;i<GS;i++)
        for (int j=0;j<GS;j++)
            a[i][j]=0;
    hash_a = 1;
    mark = 0;
    srand(time(0));
}

Mover::Mover(int b[GS][GS],int m)
{
    for (int i=0;i<GS;i++)
        for (int j=0;j<GS;j++)
            a[i][j]=b[i][j];
    hash_a = 1;
    mark = m;
    srand(time(0));
}

void Mover::moveUp()
{
    int q[GS];
    for (int j=0;j!=GS;j++)
    {
        int cnt=0,hv=0;
        for (int i=0;i!=GS;i++)
        {
            if (a[i][j])
                q[cnt++]=a[i][j];
            a[i][j]=0;
        }
        for (int i=0;i!=cnt;i++)
            if (i+1<cnt&&q[i]==q[i+1])
                q[i]++,q[i+1]=0,mark+=1<<q[i];
        for (int i=0;i!=cnt;i++)
            if (q[i]) a[hv++][j]=q[i];
    }
}

void Mover::moveDown()
{
    int q[GS];
    for (int j=0;j!=GS;j++)
    {
        int cnt=0,hv=GS-1;
        for (int i=GS-1;i>=0;i--)
        {
            if (a[i][j])
                q[cnt++]=a[i][j];
            a[i][j]=0;
        }
        for (int i=0;i!=cnt;i++)
            if (i+1<cnt&&q[i]==q[i+1])
                q[i]++,q[i+1]=0,mark+=1<<q[i];
        for (int i=0;i!=cnt;i++)
            if (q[i]) a[hv--][j]=q[i];
    }
}

void Mover::moveLeft()
{
    int q[GS];
    for (int i=0;i!=GS;i++)
    {
        int cnt=0,hv=0;
        for (int j=0;j!=GS;j++)
        {
            if (a[i][j])
                q[cnt++]=a[i][j];
            a[i][j]=0;
        }
        for (int j=0;j!=cnt;j++)
            if (j+1<cnt&&q[j]==q[j+1])
                q[j]++,q[j+1]=0,mark+=1<<q[j];
        for (int j=0;j!=cnt;j++)
            if (q[j]) a[i][hv++]=q[j];
    }
}

void Mover::moveRight()
{
    int q[GS];
    for (int i=0;i!=GS;i++)
    {
        int cnt=0,hv=GS-1;
        for (int j=GS-1;j>=0;j--)
        {
            if (a[i][j])
                q[cnt++]=a[i][j];
            a[i][j]=0;
        }
        for (int j=0;j!=cnt;j++)
            if (j+1<cnt&&q[j]==q[j+1])
                q[j]++,q[j+1]=0,mark+=1<<q[j];
        for (int j=0;j!=cnt;j++)
            if (q[j]) a[i][hv--]=q[j];
    }
}

inline unsigned long long Mover::get_hash()
{
    unsigned long long hash_b=0;
    for (int i=0;i<GS;i++)
        for (int j=0;j<GS;j++)
            hash_b=hash_b*233+a[i][j];
    return hash_b;
}

MoveQuality Mover::check_live()
{
    for (int i=0;i!=GS;i++)
      for (int j=0;j!=GS;j++)
        if (!a[i][j]) return success;
    for (int i=0;i!=GS;i++)
      for (int j=1;j!=GS;j++)
        if (a[i][j-1]==a[i][j]) return success;
    for (int i=1;i!=GS;i++)
      for (int j=0;j!=GS;j++)
        if (a[i-1][j]==a[i][j]) return success;
    return dead;
}

MoveQuality Mover::newround()
{
    if (get_hash()==hash_a) return fail;
    std::vector<int*> vec;
    for (int i=0;i<GS;i++)
        for (int j=0;j<GS;j++)
            if (!a[i][j])
                vec.push_back(&a[i][j]);
    int t=rand();
    t=(t<0?-t:t)%vec.size();
    *vec[t]=(rand()&1)+1;
    hash_a=get_hash();
    return check_live();
}

int Mover::qMark()
{
    return mark;
}
