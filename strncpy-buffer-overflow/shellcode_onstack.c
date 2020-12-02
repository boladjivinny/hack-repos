// to compile: gcc -ggdb -Wl,--omagic -o shellcode_onstack shellcode_onstack.c -static -fno-stack-protector -mpreferred-stack-boundary=3
//

const char shellcode[] = "\xeb\x13\x5b\x48\x31\xd2\x52\x88\x53\x11\x53\x48\x89\xe6\x53\x5f\x6a\x3b\x58\x0f\x05"		"\xe8\xe8\xff\xff\xff/usr/bin/updatedbx";

int main(int argc, char **argv)
{
	long int *ret;
	ret = (long int *)&ret+2;
	*ret = (long int) shellcode;
}
