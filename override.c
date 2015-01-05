// 
// Portmaster password override
//
// gcc -ooverride -lbsd override.c
//
// Christopher Hewitt, 2015
// 

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <bsd/md5.h>

void md5_calc(unsigned char * output, unsigned char * input, unsigned int len)
{
	MD5_CTX ctx;

	MD5Init(&ctx);
	MD5Update(&ctx, input, len);
	MD5Final(output, &ctx);
}

unsigned char * err_dest_msg = "Error: Host Address must be in the format 999.999.999.999\r\n";
unsigned char * entry        = "Enter User Challenge: ";
unsigned char * response     = "Response: %s\r\n";

int main(int argc, char * argv[])
{
	unsigned char buf[17];
	unsigned char genbuf[56];
	int i;

	printf(entry);
	fgets(buf, 17, stdin);
	
	memcpy(genbuf, buf, 16);
	memcpy(genbuf + 16, err_dest_msg + 1, 40);

        md5_calc(buf, genbuf, 56);

	for(i = 0; i < 16; i++) {
		buf[i] = (buf[i] % 0x2bU) + 0x30U;
        }
	buf[i] = 0;

	printf(response, buf);

        return 200;
}

