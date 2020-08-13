.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel osViRepeatLine
/* 0427E0 800673E0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0427E4 800673E4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0427E8 800673E8 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0427EC 800673EC 0C01ACD8 */  jal   __osDisableInt
/* 0427F0 800673F0 00808021 */   addu  $s0, $a0, $zero
/* 0427F4 800673F4 321000FF */  andi  $s0, $s0, 0xff
/* 0427F8 800673F8 12000006 */  beqz  $s0, .L80067414
/* 0427FC 800673FC 00402021 */   addu  $a0, $v0, $zero
/* 042800 80067400 3C038009 */  lui   $v1, 0x8009
/* 042804 80067404 8C6359D4 */  lw    $v1, 0x59d4($v1)
/* 042808 80067408 94620000 */  lhu   $v0, ($v1)
/* 04280C 8006740C 08019D09 */  j     .L80067424
/* 042810 80067410 34420040 */   ori   $v0, $v0, 0x40

.L80067414:
/* 042814 80067414 3C038009 */  lui   $v1, 0x8009
/* 042818 80067418 8C6359D4 */  lw    $v1, 0x59d4($v1)
/* 04281C 8006741C 94620000 */  lhu   $v0, ($v1)
/* 042820 80067420 3042FFBF */  andi  $v0, $v0, 0xffbf
.L80067424:
/* 042824 80067424 0C01ACF4 */  jal   __osRestoreInt
/* 042828 80067428 A4620000 */   sh    $v0, ($v1)
/* 04282C 8006742C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 042830 80067430 8FB00010 */  lw    $s0, 0x10($sp)
/* 042834 80067434 03E00008 */  jr    $ra
/* 042838 80067438 27BD0018 */   addiu $sp, $sp, 0x18

/* 04283C 8006743C 00000000 */  nop   
