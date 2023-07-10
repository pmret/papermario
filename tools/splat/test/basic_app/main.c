// .data
volatile int test = 1;

// bin (.rodata)
const char bin_data[] = {0,1,2,3,4,5,6,7};

// .bss
unsigned long long bss_data[0x10];

// .data
volatile int switch_arg = 0;

int do_switch()
{
    switch(switch_arg)
    {
        case 0:
        return 7;
        case 1:
        return 6;
        case 2:
        return 5;
        case 3:
        return 4;
        case 4:
        return 3;
        case 5:
        return 2;
        case 6:
        return 1;
        case 7:
        return 0; 
    }
    return 0;
}

// c
void bootproc()
{
    do_switch();
    for (;;)
    {
        test++;
    }
}
