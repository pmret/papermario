SECTIONS
{
  . = 0x80210000;
  .data : { *(.data) }
  .rodata : {
    *(.rodata)
    . = ALIGN(0x10);
  }

  /DISCARD/ :
  {
    *(*);
  }
}
