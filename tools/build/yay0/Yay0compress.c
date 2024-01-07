#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int  main(int argc, const char** argv, const char** envp);
void encode(FILE* fp, int insize, unsigned char* bz);
void search(unsigned int a1, int insize, int* a3, unsigned int* a4, unsigned char* bz);
int  mischarsearch(unsigned char* pattern, int patternlen, unsigned char* data, int datalen);
void initskip(unsigned short* skip, unsigned char* a1, int a2);
void writeshort(FILE* fp, short a1);
void writeint4(FILE* fp, int a1);

int main(int argc, const char** argv, const char** envp) {
    FILE*          fp; // idb
    char           src[999];
    char           dest[999];
    int            insize; // idb
    unsigned char* bz;

    if (argc < 3) {
        fprintf(stderr, "Yay0compress [infile] [outfile]\n");
        return 1;
    }

    strcpy(src, argv[1]);
    strcpy(dest, argv[2]);

    if ((fp = fopen(src, "rb")) == NULL) {
        fprintf(stderr, "FILE OPEN ERROR![%s]\n", src);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    insize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    bz = malloc(insize);
    fread(bz, 1, insize, fp);
    fclose(fp);

    for (int i = 0; src[i]; i++) {
        if (src[i] == '.') {
            src[i] = 0;
            break;
        }
    }

    if ((fp = fopen(dest, "wb")) == NULL) {
        fprintf(stderr, "FILE CREATE ERROR![%s]\n", dest);
        exit(1);
    }

    encode(fp, insize, bz);

    return 0;
}

void encode(FILE* fp, int insize, unsigned char* bz) {
    int             pp; // weak
    int             dp; // idb
    unsigned int*   cmd;
    unsigned char*  def;
    unsigned short* pol;
    unsigned int    v0;  // esi
    unsigned int    v1 = 0;  // edi
    int             v2 = 0;  // edx
    int             v3 = 0;  // ebx
    int             v4 = 0;  // edx
    unsigned int    v6;  // [esp+10h] [ebp-14h]
    unsigned int    v7 = 0;  // [esp+14h] [ebp-10h]
    int             v8 = 0;  // [esp+18h] [ebp-Ch]
    unsigned int    a4 = 0;  // [esp+1Ch] [ebp-8h]
    int             a3 = 0;  // [esp+20h] [ebp-4h]
    int             ncp; // weak
    int             npp; // weak
    int             ndp; // weak
    int             cp;

    dp  = 0;
    pp  = 0;
    cp  = 0;
    npp = 0x1000;
    ndp = 0x1000;
    ncp = 0x1000;
    cmd = calloc(0x4000, 1);
    pol = malloc(2 * npp);
    def = malloc(4 * ndp);
    v0  = 0;
    v6  = 1024;
    v1  = 0x80000000;
    while (v0 < insize) {
        if (dp == 73) {
            int dog = 5;
        }

        if (v6 < v0) {
            v6 += 1024;
        }
        search(v0, insize, &a3, &a4, bz);
        if (a4 <= 2) {
            cmd[cp]   |= v1;
            def[dp++]  = bz[v0++];
            if (ndp == dp) {
                ndp = dp + 0x1000;
                def = realloc(def, dp + 0x1000);
            }
        } else {
            search(v0 + 1, insize, &v8, &v7, bz);
            if (v7 > a4 + 1) {
                cmd[cp]   |= v1;
                def[dp++]  = bz[v0++];
                if (ndp == dp) {
                    ndp = dp + 0x1000;
                    def = realloc(def, dp + 0x1000);
                }
                v1 >>= 1;
                if (!v1) {
                    v1 = 0x80000000;
                    v2 = cp++;
                    if (cp == ncp) {
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
            if (a4 > 0x11) {
                pol[pp++] = v3;
                def[dp++] = a4 - 18;
                if (ndp == dp) {
                    ndp = dp + 0x1000;
                    def = realloc(def, dp + 0x1000);
                }
            } else {
                pol[pp++] = v3 | (((short)a4 - 2) << 12);
            }
            if (npp == pp) {
                npp += 0x1000;
                pol = realloc(pol, 2 * (pp + 0x1000));
            }
            v0 += a4;
        }
        v1 >>= 1;
        if (!v1) {
            v1 = 0x80000000;
            v4 = cp++;
            if (cp == ncp) {
                ncp = v4 + 1025;
                cmd = realloc(cmd, 4 * (v4 + 1025));
            }
            cmd[cp] = 0;
        }
    }
    if (v1 != 0x80000000) {
        cp++;
    }

    fprintf(fp, "Yay0");

    writeint4(fp, insize);

    writeint4(fp, 4 * cp + 16);
    writeint4(fp, 2 * pp + 4 * cp + 16);

    for (int i = 0; i < cp; i++)
        writeint4(fp, cmd[i]);

    for (int i = 0; i < pp; i++)
        writeshort(fp, pol[i]);

    fwrite(def, 1, dp, fp);
    fclose(fp);
}

void search(unsigned int a1, int insize, int* a3, unsigned int* a4, unsigned char* bz) {
    unsigned int  patternlen; // ebx
    unsigned int  v5; // esi
    unsigned int* v6 = 0; // edi
    unsigned int  v7 = 0; // [esp+Ch] [ebp-10h]
    int           v8 = 0; // [esp+14h] [ebp-8h]
    unsigned int  v9; // [esp+18h] [ebp-4h]

    patternlen = 3;
    v5 = 0;
    if (a1 > 0x1000) {
        v5 = a1 - 0x1000;
    }
    v9 = 273;
    if (insize - a1 <= 273) {
        v9 = insize - a1;
    }
    if (v9 > 2) {
        while (a1 > v5) {
            v7 = mischarsearch(&bz[a1], patternlen, &bz[v5], patternlen + a1 - v5);

            if (v7 >= a1 - v5) {
                break;
            }

            for (; patternlen < v9; patternlen++) {
                if (bz[patternlen + v5 + v7] != bz[patternlen + a1]) {
                    break;
                }
            }
            if (v9 == patternlen) {
                *a3 = v7 + v5;
                *a4 = patternlen;
                return;
            }
            v8 = v5 + v7;
            patternlen++;
            v5 += v7 + 1;
        }
        *a3 = v8;
        if (patternlen > 3) {
            patternlen--;
            *a4 = patternlen;
            return;
        }
        v6 = a4;
    } else {
        *a4 = 0;
        v6  = a3;
    }
    *v6 = 0;
}

int mischarsearch(unsigned char* pattern, int patternlen, unsigned char* data, int datalen) {
    unsigned short skip[256]; // idb
    int            i;         // ebx
    int            v6;        // eax
    int            j;         // ecx

    if (patternlen <= datalen) {
        // initskip
        for (int k = 0; k < 256; k++) {
            skip[k] = patternlen;
        }

        for (int k = 0; k < patternlen; k++) {
            skip[pattern[k]] = patternlen - k - 1;
        }

        for (i = patternlen - 1;; i += v6) {
            if (pattern[patternlen - 1] == data[i]) {
                i--;
                j = patternlen - 2;
                if (j < 0) {
                    return i + 1;
                }

                while (pattern[j] == data[i]) {
                    i--;
                    j--;
                    if (j < 0) {
                        return i + 1;
                    }
                }

                if (skip[data[i]] <= patternlen - j) {
                    v6 = patternlen - j;
                    continue;
                }
            }
            v6 = skip[data[i]];
        }
    }
    return datalen;
}

void writeshort(FILE* fp, short val) {
    fputc((val & 0xff00) >> 8, fp);
    fputc((val & 0x00ff) >> 0, fp);
}

void writeint4(FILE* fp, int val) {
    fputc((val & 0x00ff000000) >> 24, fp);
    fputc((val & 0x0000ff0000) >> 16, fp);
    fputc((val & 0x000000ff00) >> 8, fp);
    fputc((val & 0x00000000ff) >> 0, fp);
}
