#include <stdint.h>
#include <stdio.h>

uint32_t htonf(float f)
{
	uint32_t p;
	uint32_t sign;

	if (f < 0) {
		sign = 1;
		f = -f;
	}
	else {
		sign = 0;
	}
	p = ((((uint32_t)f) & 0x7fff) << 16) | (sign << 31); // whole part and sign
	p |= (uint32_t)(((f - (int)f) * 65536.0f)) & 0xffff; //fraction

	return p;
}

float ntohf(uint32_t p)
{
	float f = ((p >> 16) & 0x7fff);
	f += (p & 0xffff) / 65536.0f; //fraction
	if (((p >> 31) & 0x01) == 0x01) {
		f = -f;
	}
	return f;
}

int main(void)
{
	float f = 3.1415926, f2;
	uint32_t netf;

	netf = htonf(f); // convert to "network" form
	f2 = ntohf(netf); // convert back to test
	printf("Original: %f\n", f);  //3.1415926
	printf("Network: 0x%08X\n", netf); // 0x0003243F
	printf("Unpacked: %f\n", f2); //3.141586

	return 0;
}