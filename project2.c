#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}


void sort2(int list[], int n) // up to 1 million numbers (will give sorted file)
{
	qsort(list,n,sizeof(int),cmpfunc);
}




typedef unsigned uint;
#define swap(a, b) { tmp = a; a = b; b = tmp; }
#define each(i, x) for (i = 0; i < x; i++)
 
/* sort unsigned ints */
static void rad_sort_u(uint *from, uint *to, uint bit)
{
	if (!bit || to < from + 1) return;
 
	uint *ll = from, *rr = to - 1, tmp;
	while (1) {
		/* find left most with bit, and right most without bit, swap */
		while (ll < rr && !(*ll & bit)) ll++;
		while (ll < rr &&  (*rr & bit)) rr--;
		if (ll >= rr) break;
		swap(*ll, *rr);
	}
 
	if (!(bit & *ll) && ll < to) ll++;
	bit >>= 1;
 
	rad_sort_u(from, ll, bit);
	rad_sort_u(ll, to, bit);
}
 
static inline void radix_sort_unsigned(uint *a, const size_t len)
{
	rad_sort_u(a, a + len, (uint)INT_MIN);
}
 
/* sort signed ints: flip highest bit, sort as unsigned, flip back */
void sort(int *a, const size_t len)
{
	size_t i;
	uint *x = (uint*) a;
 
	each(i, len) x[i] ^= INT_MIN;
	rad_sort_u(x, x + len, INT_MIN);
	each(i, len) x[i] ^= INT_MIN;
}
 



