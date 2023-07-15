SECTIONS
{
  . = 0x80210000;
  .data : { *(.data) }
  .rodata : { *(.rodata) }

  /DISCARD/ :
  {
    *(*);
  }
}
