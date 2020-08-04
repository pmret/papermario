.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80033788
/* 00EB88 80033788 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 00EB8C 8003378C 240200FF */  addiu $v0, $zero, 0xff
/* 00EB90 80033790 0000202D */  daddu $a0, $zero, $zero
/* 00EB94 80033794 0080282D */  daddu $a1, $a0, $zero
/* 00EB98 80033798 2406013F */  addiu $a2, $zero, 0x13f
/* 00EB9C 8003379C 240700EF */  addiu $a3, $zero, 0xef
/* 00EBA0 800337A0 AFBF0020 */  sw    $ra, 0x20($sp)
/* 00EBA4 800337A4 AFA00010 */  sw    $zero, 0x10($sp)
/* 00EBA8 800337A8 AFA00014 */  sw    $zero, 0x14($sp)
/* 00EBAC 800337AC AFA00018 */  sw    $zero, 0x18($sp)
/* 00EBB0 800337B0 0C00AAD7 */  jal   func_8002AB5C
/* 00EBB4 800337B4 AFA2001C */   sw    $v0, 0x1c($sp)
/* 00EBB8 800337B8 8FBF0020 */  lw    $ra, 0x20($sp)
/* 00EBBC 800337BC 03E00008 */  jr    $ra
/* 00EBC0 800337C0 27BD0028 */   addiu $sp, $sp, 0x28

/* 00EBC4 800337C4 00000000 */  nop   
/* 00EBC8 800337C8 00000000 */  nop   
/* 00EBCC 800337CC 00000000 */  nop   

.set reorder
