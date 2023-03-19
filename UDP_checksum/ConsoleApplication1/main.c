#include<stdio.h>
unsigned short checksum(unsigned short* buf, int nword)
{
	unsigned long sum;
	for (sum = 0; nword > 0; nword--)
	{
		sum += *buf++;
		sum = (sum >> 16) + (sum & 0xffff);
	}
	printf("%x\t", sum);
	return ~sum;
}
void main()
{	
	//unsigned short buffer[20] = { 0x0aaa,0x3bbf,0xd20e,0x960d,0x0011,0x001c,0xd123,0x2742,0x001c,0x0000,0x6c41,0x5661,0x0000,0x0e00,0xf8b6,0xd401,0x9313,0x0000,0x0000,0x0000 }
	                           //  ip             ip              udp    len   端口  端口   len          //data
		unsigned short buffer[] = {
	0xc0a8,0x1f63, //e00b
	0xc0a8,0x7a01,
	0x0011,0x0010,
	0x202a,0x202a,
	0x0010,0x0000,
	0x0102,0x0304,
	0x0506,0x0708   
	};
	
	int n = (((buffer[5]-8)/2)+10);
	unsigned short re_checksum;
	re_checksum = checksum(buffer, n);
	printf("%x\t", re_checksum);
	if (re_checksum == 0x285c)
		printf("校验和正确!\n");
	else
		printf("校验和不正确!\n");
}