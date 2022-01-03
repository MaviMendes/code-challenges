#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// https://www.hackerrank.com/challenges/small-triangles-large-triangles/problem

struct triangle
{
	int a;
	int b;
	int c;
};

typedef struct triangle triangle;

float area(triangle t)
{
    float p = (t.a + t.b + t.c)/2.0;
    float area = p*(p-t.a)*(p-t.b)*(p-t.c);
   
    return area;
}

void sort_by_area(triangle* tr, int n) {
	/**
	* Sort an array a of the length n
	*/

    int i,j, indiceMenor;
    double area1,area2, areaMenor;
    triangle tmp;
    /*
    7 24 25
    5 12 13
    3 4 5
    */
    
    for(i=0;i<n;i++)
    {
        area1 = area(tr[i]);
        areaMenor = area1;
        indiceMenor = i;
        for(j=i+1;j<n;j++)
        {
            area2 = area(tr[j]);
            if(area2 < areaMenor)
            {
                areaMenor = area2;
                indiceMenor = j;
                tmp = tr[indiceMenor];
                tr[indiceMenor] = tr[i];
                tr[i] = tmp;
            }
        }
    }
    
}

int main()
{
	int n;
	scanf("%d", &n);
	triangle *tr = malloc(n * sizeof(triangle));
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	}
	sort_by_area(tr, n);
	for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}