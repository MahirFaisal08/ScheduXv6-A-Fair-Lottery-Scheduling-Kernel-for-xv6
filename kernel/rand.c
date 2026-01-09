int

do_rand(unsigned long *ctx)

{
    long hi, lo, x;

    x = (*ctx % 0x7ffffffe) + 1;

    hi = x / 127773;

    lo = x % 127773;


    x = 16807 * lo - 2836 * hi;


    if (x < 0)

        x += 0x7fffffff;


    x--;


    *ctx = x;


    return (x);



}



unsigned long rand_next = 1;



int


rand(void)


{



    return (do_rand(&rand_next));

}

