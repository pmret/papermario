#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char **argv, const char **envp);
void encode();
void search(unsigned int a1, int a2, int *a3, unsigned int *a4);
int mischarsearch(unsigned char *a1, int a2, unsigned char *a3, int a4);
void initskip(unsigned char *a1, int a2);
void writeshort(short a1);
void writeint4(int a1);

unsigned short skip[256]; // idb
int cp; // weak
int ndp; // weak
FILE *fp; // idb
unsigned char *def;
unsigned short *pol;
int pp; // weak
int insize; // idb
int ncp; // weak
int npp; // weak
unsigned char *bz;
int dp; // idb
unsigned int *cmd;

int main(int argc, const char **argv, const char **envp)
{
    char src[999];
	char dest[999];


	if (argc < 3)
	{
		fprintf(stderr, "Yay0compress [infile] [outfile]\n");
		return 1;
	}
	
	strcpy(src, argv[1]);
    strcpy(dest, argv[2]);
	
	if ((fp = fopen(src, "rb")) == NULL)
	{
		fprintf(stderr, "FILE OPEN ERROR![%s]\n", src);
		return 1;
	}
	
	fseek(fp, 0, SEEK_END);
	insize = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	
	bz = malloc(insize);
	fread(bz, 1, insize, fp);
	fclose(fp);
	
	for (int i = 0; src[i]; i++)
	{
		if (src[i] == '.')
		{
			src[i] = 0;
			break;
		}
	}
    
	if ((fp = fopen(dest, "wb")) == NULL)
	{
		fprintf(stderr, "FILE CREATE ERROR![%s]\n", dest);
		exit(1);
	}
	
	encode();
	
	fprintf(fp, "Yay0");
	
	writeint4(insize);
	
	writeint4(4 * cp + 16);
	writeint4(2 * pp + 4 * cp + 16);
	
	for (int i = 0; i < cp; i++)
		writeint4(cmd[i]);
	
	for (int i = 0; i < pp; i++)
		writeshort(pol[i]);
	
	fwrite(def, 1u, dp, fp);
	fclose(fp);
	
	return 0;
}

void encode()
{
	unsigned int v0; // esi
	unsigned int v1; // edi
	int v2; // edx
	int v3; // ebx
	int v4; // edx
	char v5; // [esp+Ch] [ebp-18h]
	unsigned int v6; // [esp+10h] [ebp-14h]
	unsigned int v7; // [esp+14h] [ebp-10h]
	int v8; // [esp+18h] [ebp-Ch]
	unsigned int a4; // [esp+1Ch] [ebp-8h]
	int a3; // [esp+20h] [ebp-4h]

	dp = 0;
	pp = 0;
	cp = 0;
	npp = 4096;
	ndp = 4096;
	ncp = 4096;
	cmd = calloc(0x4000u, 1u);
	pol = malloc(2 * npp);
	def = malloc(4 * ndp);
	v0 = 0;
	v6 = 1024;
	v1 = 2147483648;
	while ( insize > v0 )
	{
		if ( v6 < v0 )
			v6 += 1024;
		search(v0, insize, &a3, &a4);
		if ( a4 <= 2 )
		{
			cmd[cp] |= v1;
			def[dp++] = bz[v0++];
			if ( ndp == dp )
			{
				ndp = dp + 4096;
				def = realloc(def, dp + 4096);
			}
		}
		else
		{
			search(v0 + 1, insize, &v8, &v7);
			if ( v7 > a4 + 1 )
			{
				cmd[cp] |= v1;
				def[dp++] = bz[v0++];
				if ( ndp == dp )
				{
					ndp = dp + 4096;
					def = realloc(def, dp + 4096);
				}
				v1 >>= 1;
				if ( !v1 )
				{
					v1 = 2147483648;
					v2 = cp++;
					if ( cp == ncp )
					{
						ncp = v2 + 1025;
						cmd = realloc(cmd, 4 * (v2 + 1025));
					}
					cmd[cp] = 0;
				}
				a4 = v7;
				a3 = v8;
			}
			v3 = v0 - a3 - 1;
			a3 = v0 - a3 - 1;
			v5 = a4;
			if ( a4 > 0x11 )
			{
				pol[pp++] = v3;
				def[dp++] = v5 - 18;
				if ( ndp == dp )
				{
					ndp = dp + 4096;
					def = realloc(def, dp + 4096);
				}
			}
			else
			{
				pol[pp++] = v3 | (((short)a4 - 2) << 12);
			}
			if ( npp == pp )
			{
				npp = pp + 4096;
				pol = realloc(pol, 2 * (pp + 4096));
			}
			v0 += a4;
		}
		v1 >>= 1;
		if ( !v1 )
		{
			v1 = 2147483648;
			v4 = cp++;
			if ( cp == ncp )
			{
				ncp = v4 + 1025;
				cmd = realloc(cmd, 4 * (v4 + 1025));
			}
			cmd[cp] = 0;
		}
	}
	if ( v1 != 0x80000000 )
		++cp;
	//fprintf(stderr, "IN=%d OUT=%d\n", insize, dp + 2 * pp + 4 * cp + 16);
}

void search(unsigned int a1, int a2, int *a3, unsigned int *a4)
{
	unsigned int v4; // ebx
	unsigned int v5; // esi
	unsigned int *v6; // edi
	unsigned int v7; // [esp+Ch] [ebp-10h]
	int v8; // [esp+14h] [ebp-8h]
	unsigned int v9; // [esp+18h] [ebp-4h]

	v4 = 3;
	v5 = 0;
	if ( a1 > 0x1000 )
		v5 = a1 - 4096;
	v9 = 273;
	if ( a2 - a1 <= 0x111 )
		v9 = a2 - a1;
	if ( v9 > 2 )
	{
		while ( a1 > v5 )
		{
			v7 = mischarsearch(&bz[a1], v4, &bz[v5], v4 + a1 - v5);
			if ( v7 >= a1 - v5 )
				break;
			for ( ; v9 > v4; ++v4 )
			{
				if ( bz[v4 + v5 + v7] != bz[v4 + a1] )
					break;
			}
			if ( v9 == v4 )
			{
				*a3 = v7 + v5;
				goto LABEL_17;
			}
			v8 = v5 + v7;
			++v4;
			v5 += v7 + 1;
		}
		*a3 = v8;
		if ( v4 > 3 )
		{
			--v4;
LABEL_17:
			*a4 = v4;
			return;
		}
		v6 = a4;
	}
	else
	{
		*a4 = 0;
		v6 = a3;
	}
	*v6 = 0;
}

int mischarsearch(unsigned char *pattern, int patternlen, unsigned char *data, int datalen)
{
  int result; // eax
  int i; // ebx
  int v6; // eax
  int j; // ecx

  result = datalen;
  if ( patternlen <= datalen )
  {
    initskip(pattern, patternlen);
    for ( i = patternlen - 1; ; i += v6 )
    {
      if ( pattern[patternlen - 1] == data[i] )
      {
        --i;
        j = patternlen - 2;
        if ( patternlen - 2 < 0 )
          return i + 1;
        while ( pattern[j] == data[i] )
        {
          --i;
          if ( --j < 0 )
            return i + 1;
        }
        v6 = patternlen - j;
        if ( skip[data[i]] > patternlen - j )
          v6 = skip[data[i]];
      }
      else
      {
        v6 = skip[data[i]];
      }
    }
  }
  return result;
}

void initskip(unsigned char *pattern, int len)
{
	for (int i = 0; i < 256; i++)
		skip[i] = len;
	
	for (int i = 0; i < len; i++)
		skip[pattern[i]] = len - i - 1;
}

void writeshort(short val)
{
	fputc((val & 0xff00) >> 8, fp);
	fputc((val & 0x00ff) >> 0, fp);
}

void writeint4(int val)
{
	fputc((val & 0x00ff000000) >> 24, fp);
	fputc((val & 0x0000ff0000) >> 16, fp);
	fputc((val & 0x000000ff00) >>  8, fp);
	fputc((val & 0x00000000ff) >>  0, fp);
}
