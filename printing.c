#include <stdio.h>
int main()

{
    int a=15,b=7;
    printf("%d\n",b);
    printf("13 d: %13d\n",b);
    printf("13 d & a Value: %13d,%d\n",b,a);
    printf("013 d then:%013d\n",b);
    printf("013 d & a Value %013d,%d\n",b,a);
    printf("-13 d then: %-13d\n",b);  //spaces after number is printed
    printf("-13 d & a Value %-13d,%d\n",b,a);

    printf("Printing floating: \n");
    a=5; float c = 15.3886213214;
    printf("1 :%f\n",c);  //by default it prints only till 6 decimal places
    printf("2:%.2f\n",c);
    printf("3 :%13d\n",a);
    printf("4 :%13f\n",c);  
    //even if 13 is mentioned float takes only 6 values after decimal place by default. 
    //Therefore there are 4 spaces before number is printed
    //take double float for more decimal places to be considered
    printf("5 :%13f\n",c);
    printf("6:%013f\n",c);
    printf("7:%-13f\n",c);
    printf("8:%-13f,%d\n",c,a);
    printf("9:%13.5f\n",c);  //reserving 13 spaces and printing up to 5 decimal places
    printf("10:%13.2f\n",c);
    printf("11:%-13.2f,%d\n",c,a);
    printf("12:%e\n",c);

    printf("Printing Strings: \n");
    printf("1:%s:\n", "Ace Academy Hyd");
    printf("2:%25s: \n", "Ace Academy Hyd");
    printf("3:%-25s: \n", "Ace Academy Hyd");
    printf("4 :%10s:\n", "Ace Academy Hyd");
    printf("5:%-10s:\n", "Ace Academy Hyd");
    printf("6 :%.30s: \n", "Ace Academy Hyd");
    printf("7 :%.10s:\n", "Ace Academy Hyd");

    printf("8 :%015.5s:\n", "Ace Academy Hyd");
    //first it truncates the string to 5 characters and prints 'Ace A'
    //then it fills up the rest of the spaces with ' ' until 15 characters are printed.
    //without '.5', it prints "Ace Academy Hyd" the puts spaces until 15 characters are done.

    printf("9:%-15.5s:\n", "Ace Academy Hyd");
    printf("10 :%10s:\n", "Ace Academy Hyd");
    //even if 10 spaces need to be filled it prints whole string first
    //as 10 characters are already done it just does not put spaces
    printf("\n");
    //get c++ and java equivalent of this
    int x =3/5*2;
    int y=3*2/5;
    int z=5*2*8/12 + 3*50%4;
    printf("%d\t%d\t%d",x,y,z);
    /*Output:
    0
    1
    8
    */
   printf("\n");
    int v = 5;
    int d = 10;
    printf("%d\n",v++);
    printf("%2d", ++d);

    //printf("%d\n",++10 + 2);  
    //gives an error as you can't directly increment a constant value
    return 0;
}