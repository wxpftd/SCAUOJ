#include <iostream>
#include <set>
using namespace std;

template <typename T>
void qSort(T list[], int l, int r)
{
    if (l < r)
    {
        T x = list[r];
        int i = l, j = r;
        while (i < j)
        {
            while (i < j && list[i].y <= x.y) 
                i++;
            if (i < j)
                list[j--] = list[i];
            while (i < j && list[j].y > x.y)
                j--;
            if (i < j)
                list[i++] = list[j];
        }
        list[j] = x;
        qSort(list, l, j-1);
        qSort(list, j+1, r);
    }
}

struct LevelLine
{
    double l;
    double r;
    double y;
    int upOrDown;
};

int main()
{
    int n;
    cin >> n;
    set<double> *X = new set<double>();
    LevelLine *ll = new LevelLine[200];
    double x1, x2, y1, y2;
    for (int i=1; i<=2*n; i+=2)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        ll[i].l = x1;
        ll[i].r = x2;
        ll[i].y = y1;
        ll[i].upOrDown = 0;

        ll[i+1].l = x1;
        ll[i+1].r = x2;
        ll[i+1].y = y2;
        ll[i+1].upOrDown = 1;
        X->insert(x1);
        X->insert(x2);
    }
    qSort(ll, 1, 2*n);
    int count = 0;
    bool isLowlevel = true;
    double minY;
    double Areas = 0;
    set<double>::iterator di;
    di = X->begin();
    for (int i=1; i< int(X->size()); ++i)
    {
        x1 = *(di);
        x2 = *(++di);
        for (int j=1; j<=2*n; ++j)
        {
            if (ll[j].l <= x1 && ll[j].r >= x2) 
            {
                if (isLowlevel)
                {
                    minY = ll[j].y;       
                    isLowlevel = false;
                }
                if (ll[j].upOrDown) 
                    ++count;
                else
                    --count;
                if (0 == count)
                {
                    isLowlevel = true;
                    Areas += (x2-x1)*(ll[j].y-minY);
                }
            }
        }
    }
    printf("%.2lf\n", Areas);
    delete X;
    delete ll;
    return 0;
}
