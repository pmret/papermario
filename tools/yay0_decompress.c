#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define U32(s) ((uint32_t)(*(s) << 24 | *((s) + 1) << 16 | *((s) + 2) << 8 | *((s) + 3)))

#define ERROR_UNSUPPORTED                -1
#define ERROR_CORRUPTED                  -2
#define ERROR_UNRECOGNIZED               -3
#define ERROR_MEMORY                     -4
#define ERROR_BACKREFERENCE_TOO_DISTANT  -5
#define ERROR_OVERFLOW                   -6

uint8_t yay0_magic[] = {0x59, 0x61, 0x79, 0x30};

typedef struct __attribute__ ((packed)) yay0_header
{
  uint8_t magic[4];
  uint32_t size;
  uint32_t count_offset;
  uint32_t data_offset;
} yay0_header_t;

typedef struct
{
  uint8_t *control;
  uint8_t *count;
  uint8_t *data;
  size_t error;
} yay0_info;

size_t yay0_decompress(void* _in, void** _out, size_t stop_after_size);

size_t get_file_size(char *filename)
{
    struct stat file_stat;
    if(stat(filename, &file_stat) < 0)
    {
      printf("Failed to get file size!\n");
      exit(1);
    }

    return file_stat.st_size;
}

int main(int argc, char **argv)
{
    if(argc < 2)
        return 1;
    FILE *rom_f = fopen(argv[1], "rb");
    if(!rom_f)
    {
      printf("Failed to open input file...\n");
      return 1;
    }
    size_t romSize = get_file_size(argv[1]);
    uint8_t *romData = malloc(romSize);
    fread(romData, 1, romSize, rom_f);
    yay0_header_t *header = (yay0_header_t *)romData;
    size_t decomp_size = U32((uint8_t *)&header->size);
    uint8_t *dest = NULL;
    size_t bytes_written = yay0_decompress(&romData[0], (void **)&dest, decomp_size);
    char *out_path = malloc(strlen(argv[1]) + strlen(".dec") + 2);
    strcpy(out_path, argv[1]);
    strcat(out_path, ".dec");
    FILE *out_f = fopen(out_path, "wb");
    fwrite(dest, 1, bytes_written, out_f);
    free(dest);
    free(romData);
    fclose(rom_f);
    fclose(out_f);

    return 0;
}

size_t yay0_decompress(void* _in, void** _out, size_t stop_after_size)
{
  yay0_info *info = malloc(sizeof(yay0_info));
  yay0_header_t* header = (yay0_header_t*)_in;

  if (memcmp(yay0_magic, &header->magic[0], 4))
    return ERROR_UNRECOGNIZED;

  uint32_t total_size = U32((uint8_t *)&header->size);
  if (total_size == 0) {
    return 0;
  }
  if (stop_after_size && total_size > stop_after_size) {
    total_size = stop_after_size;
  }

  *_out = malloc(total_size);
  if (!*_out)
    return ERROR_MEMORY;

  uint32_t count_offset = U32((uint8_t *)&header->count_offset);
  uint32_t data_offset = U32((uint8_t *)&header->data_offset);

  info->control = (uint8_t*)(_in + sizeof(yay0_header_t));
  info->count = (uint8_t*)_in + count_offset;
  info->data = (uint8_t*)_in + data_offset;
  uint8_t* out_stream = (uint8_t*)*_out;

  size_t bytes_written = 0;
  uint8_t control_bits_remaining = 0;
  uint8_t control_byte;

  while (bytes_written < total_size)
  {

    if (control_bits_remaining == 0)
    {
      control_byte = *(info->control++);
      control_bits_remaining = 8;
    }

    if ((control_byte & 0x80) != 0)
    {
      out_stream[bytes_written] = *(info->data++);
      bytes_written++;

    }
    else
    {
      uint16_t nr = (*(info->count++) << 8);
      nr |= *(info->count++);
      uint16_t r = (nr & 0x0FFF) + 1;
      uint16_t n = (nr & 0xF000) >> 12;
      if (n == 0)
        n = *(info->data++) + 0x12; // TODO is this really read from the data stream? (not the count stream?)
      else
        n += 2;

      if (r > bytes_written)
        return ERROR_BACKREFERENCE_TOO_DISTANT;

      if (bytes_written + n > total_size && stop_after_size == total_size)
        return ERROR_OVERFLOW;

      for (; n > 0; n--) 
      {
        out_stream[bytes_written] = out_stream[bytes_written - r];
        bytes_written++;
      }
    }

    control_byte <<= 1;
    control_bits_remaining--;    
  }

  return bytes_written;
}