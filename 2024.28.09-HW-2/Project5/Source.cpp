#include <stdio.h>
#include <math.h>
#include <iostream>

int main() {
    int l1, w1, h1, l2, w2, h2, lc, wc, hc, l;
    scanf("%d %d %d %d %d %d %d %d %d", &l1, &w1, &h1, &l2, &w2, &h2, &lc, &wc, &hc);
    l = l1;
    l1 = max(l1, w1);
    w1 = min(l, w1);
    l = l2;
    l2 = max(l2, w2);
    w2 = min(l, w2);
    l = lc;
    lc = max(lc, wc);
    wc = min(l, wc);

    if (l1 <= lc && w1 <= wc && l2 <= lc && w2 <= wc) {
        if (h1 > hc || h2 > hc) {
            printf("NO");
            return 0;
        }
        if ( l1 <= lc && w1 <= wc) {
            if ( l2 <= wc - w1 && w2 <= lc) {
                printf("YES");
                return 0;
            }
            else if (w2 <= wc - w1 && l2 <= lc) {
                printf("YES");
                return 0;
            }
            else if ( l2 <= lc - l1 && w2 <= wc) {
                printf("YES");
                return 0;
            }
            else if (w2 <= lc - l1 && l2 <= wc) {
                printf("YES");
                return 0;
            }
        }
        if ( w1 <= lc && l1 <= wc) {
            if ( l2 <= wc - l1 && w2 <= lc) {
                printf("YES");
                return 0;
            }
            else if ( l2 <= lc && w2 <= wc - l1) {
                printf("YES");
                return 0;
            }
            else if ( l2 <= lc - w1 && w2 <= wc) {
                printf("YES");
                return 0;
            }
            else if ( w2 <= lc - w1 && l2 <= wc) {
                printf("YES");
                return 0;
            }
        }
        if (h1 + h2 <= hc && l1 <= lc && w1 <= wc && l2 <= lc && w2 <= wc) {
            printf("YES");
            return 0;
        }
        printf("NO");
        return 0;
    }
    printf("NO");
    return 0;
}