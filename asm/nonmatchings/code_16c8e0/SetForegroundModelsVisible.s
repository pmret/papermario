.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SetForegroundModelsVisible
/* 1823CC 80253AEC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 1823D0 80253AF0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 1823D4 80253AF4 8C82000C */  lw    $v0, 0xc($a0)
/* 1823D8 80253AF8 0C0B1EAF */  jal   get_variable
/* 1823DC 80253AFC 8C450000 */   lw    $a1, ($v0)
/* 1823E0 80253B00 10400005 */  beqz  $v0, .L80253B18
/* 1823E4 80253B04 00000000 */   nop   
/* 1823E8 80253B08 0C099F4A */  jal   show_foreground_models
/* 1823EC 80253B0C 00000000 */   nop   
/* 1823F0 80253B10 08094EC8 */  j     .L80253B20
/* 1823F4 80253B14 00000000 */   nop   

.L80253B18:
/* 1823F8 80253B18 0C099F2D */  jal   hide_foreground_models
/* 1823FC 80253B1C 00000000 */   nop   
.L80253B20:
/* 182400 80253B20 8FBF0010 */  lw    $ra, 0x10($sp)
/* 182404 80253B24 24020002 */  addiu $v0, $zero, 2
/* 182408 80253B28 03E00008 */  jr    $ra
/* 18240C 80253B2C 27BD0018 */   addiu $sp, $sp, 0x18

/* 182410 80253B30 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 182414 80253B34 AFB00010 */  sw    $s0, 0x10($sp)
/* 182418 80253B38 0080802D */  daddu $s0, $a0, $zero
/* 18241C 80253B3C AFBF001C */  sw    $ra, 0x1c($sp)
/* 182420 80253B40 AFB20018 */  sw    $s2, 0x18($sp)
/* 182424 80253B44 AFB10014 */  sw    $s1, 0x14($sp)
/* 182428 80253B48 8E02000C */  lw    $v0, 0xc($s0)
/* 18242C 80253B4C 8C510000 */  lw    $s1, ($v0)
/* 182430 80253B50 24420004 */  addiu $v0, $v0, 4
/* 182434 80253B54 8C450004 */  lw    $a1, 4($v0)
/* 182438 80253B58 0C0B1EAF */  jal   get_variable
/* 18243C 80253B5C 8C520000 */   lw    $s2, ($v0)
/* 182440 80253B60 0200202D */  daddu $a0, $s0, $zero
/* 182444 80253B64 0220282D */  daddu $a1, $s1, $zero
/* 182448 80253B68 00021200 */  sll   $v0, $v0, 8
/* 18244C 80253B6C 344200FE */  ori   $v0, $v0, 0xfe
/* 182450 80253B70 0C0B2026 */  jal   set_variable
/* 182454 80253B74 02423025 */   or    $a2, $s2, $v0
/* 182458 80253B78 8FBF001C */  lw    $ra, 0x1c($sp)
/* 18245C 80253B7C 8FB20018 */  lw    $s2, 0x18($sp)
/* 182460 80253B80 8FB10014 */  lw    $s1, 0x14($sp)
/* 182464 80253B84 8FB00010 */  lw    $s0, 0x10($sp)
/* 182468 80253B88 24020002 */  addiu $v0, $zero, 2
/* 18246C 80253B8C 03E00008 */  jr    $ra
/* 182470 80253B90 27BD0020 */   addiu $sp, $sp, 0x20

