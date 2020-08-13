.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel fio_erase_flash
/* 006E1C 8002BA1C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 006E20 8002BA20 AFBF0010 */  sw    $ra, 0x10($sp)
/* 006E24 8002BA24 0C01BD09 */  jal   osFlashSectorErase
/* 006E28 8002BA28 000421C0 */   sll   $a0, $a0, 7
/* 006E2C 8002BA2C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 006E30 8002BA30 03E00008 */  jr    $ra
/* 006E34 8002BA34 27BD0018 */   addiu $sp, $sp, 0x18

/* 006E38 8002BA38 00000000 */  nop   
/* 006E3C 8002BA3C 00000000 */  nop   


