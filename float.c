// Our simple implementation of floats returns float value from function as eax 
// this doesn't comply with cdecl so cannot use math.h funcs like sqrt
// we link against asm lib floatlib.s which does things like float addition
// x87 functions like FLD are confined to this library
// Cannot write out floats with printf as it is a vararg and takes doubles (not supported)
// instead we write out as hex integers and check value using
// https://www.h-schmidt.net/FloatConverter/IEEE754.html

float pi=3.1415;

int main()
{
    float a;
    int i;
    a=5.0;

    printf("numbers: %0x %0x\n", pi, a);

    a=a+2;   // promote 2 to 2.0. a=7.0
    
    printf("result: %0x %0x %0x\n", a+3.5, a+pi, a-1.5); // 10.5 (41280000), 10.1415 (41224396), 5.5 (40b00000)
    
    float b=-3.0;
    printf("b=%0x\n",b);  // -3.0 (c0400000)
    
    i=3+a; // promote to 3.0, add to get 10.0, demote to 10
    return i+1; // 11
}
