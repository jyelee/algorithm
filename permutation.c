#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isSwap(char *org, int start, int end) {
    for(; start < end; start++) {
        if(org[start] == org[end]) {
            return 0;
        }
    }
    return 1;
}

void swap(char *org, char *dest) {
    char temp = *org;
    *org = *dest;
    *dest = temp;
}

//let cur element swap every element which locate after it
//这样我们也得到了在全排列中去掉重复的规则——去重的全排列就是从第一个数字起每个数分别与它后面非重复出现的数字交换。用编程的话描述就是第i个数与第j个数交换时，要求[i,j)中没有与第j个数相等的数。
void perm(const char *orgStr, int startPos, int len) {
    if(orgStr == NULL) return;
    if(startPos == len - 1) {
        printf("%s ", orgStr);
        return;
    }
    int next = startPos;
    for(; next < len; next++) {
        if(isSwap(orgStr, startPos, next)) {
            if(next != startPos) {
                swap(orgStr + startPos, orgStr + next);
            }
            perm(orgStr, startPos + 1, len);
            if(next != startPos) {
                swap(orgStr + startPos, orgStr + next);
            }
        }
    }
}


//反转区间  
void Reverse(char *a, char *b)  
{  
    while (a < b)  
        swap(a++, b--);  
}  
//下一个排列  
int Next_permutation(char a[])  
{  
    char *pEnd = a + strlen(a);  
    if (a == pEnd)  
        return 0;  
    char *p, *q, *pFind;  
    pEnd--;  
    p = pEnd;  
    while (p != a)  
    {  
        q = p;  
        --p;  
        if (*p < *q) //找降序的相邻2数,前一个数即替换数  
        {  
            //从后向前找比替换点大的第一个数  
            pFind = pEnd;  
            while (*pFind <= *p)  
                --pFind;  
            //替换  
            swap(pFind, p);  
            //替换点后的数全部反转  
            Reverse(q, pEnd);  
            return 1;  
        }  
    }  
    Reverse(p, pEnd);//如果没有下一个排列,全部反转后返回true  
    return 0;  
}  
int QsortCmp(const void *pa, const void *pb)  
{  
    return *(char*)pa - *(char*)pb;  
}  


/*void func(const char *str_in)  
{  
    std::string str(str_in);  
    std::sort(str.begin(),str.end());  
    do   
    {  
        std::cout << str << std::endl;  
    }while (std::next_permutation(str.begin(),str.end()));  
}*/



int main(int argc, char *argv[]) {
    char *str = "abc";
    perm(str, 0, strlen(str));
    /*qsort(str, strlen(str), sizeof(str[0]), QsortCmp);
    printf("%s\n", str);
    do {
        printf("%s ", str);
    } while(Next_permutation(str));*/
    return EXIT_SUCCESS;
}

    //全排列的递归实现  
    /*#include <stdio.h>  
    #include <string.h>  
    void Swap(char *a, char *b)  
    {  
        char t = *a;  
        *a = *b;  
        *b = t;  
    }  
    //k表示当前选取到第几个数,m表示共有多少数.  
    void AllRange(char *pszStr, int k, int m)  
    {  
        if (k == m)  
        {  
            static int s_i = 1;  
            printf("  第%3d个排列\t%s\n", s_i++, pszStr);  
        }  
        else  
        {  
            for (int i = k; i <= m; i++) //第i个数分别与它后面的数字交换就能得到新的排列  
            {  
                Swap(pszStr + k, pszStr + i);  
                AllRange(pszStr, k + 1, m);  
                Swap(pszStr + k, pszStr + i);  
            }  
        }  
    }  
    void Foo(char *pszStr)  
    {  
        AllRange(pszStr, 0, strlen(pszStr) - 1);  
    }  
    int main()  
    {  
        printf("         全排列的递归实现\n");  
        printf("  --by MoreWindows( http://blog.csdn.net/MoreWindows )--\n\n");  
        char szTextStr[] = "123";  
        printf("%s的全排列如下:\n", szTextStr);  
        Foo(szTextStr);  
        return 0;  
    }  
*/
