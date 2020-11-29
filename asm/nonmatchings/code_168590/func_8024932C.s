.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024932C
/* 169B8C 8024932C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 169B90 80249330 AFB10014 */  sw        $s1, 0x14($sp)
/* 169B94 80249334 0000882D */  daddu     $s1, $zero, $zero
/* 169B98 80249338 AFB00010 */  sw        $s0, 0x10($sp)
/* 169B9C 8024933C 3C108025 */  lui       $s0, %hi(D_8024C100)
/* 169BA0 80249340 2610C100 */  addiu     $s0, $s0, %lo(D_8024C100)
/* 169BA4 80249344 AFBF0018 */  sw        $ra, 0x18($sp)
.L80249348:
/* 169BA8 80249348 8E040000 */  lw        $a0, ($s0)
/* 169BAC 8024934C 26100004 */  addiu     $s0, $s0, 4
/* 169BB0 80249350 0C05123D */  jal       free_icon
/* 169BB4 80249354 26310001 */   addiu    $s1, $s1, 1
/* 169BB8 80249358 2A220003 */  slti      $v0, $s1, 3
/* 169BBC 8024935C 1440FFFA */  bnez      $v0, .L80249348
/* 169BC0 80249360 00000000 */   nop      
/* 169BC4 80249364 8FBF0018 */  lw        $ra, 0x18($sp)
/* 169BC8 80249368 8FB10014 */  lw        $s1, 0x14($sp)
/* 169BCC 8024936C 8FB00010 */  lw        $s0, 0x10($sp)
/* 169BD0 80249370 03E00008 */  jr        $ra
/* 169BD4 80249374 27BD0020 */   addiu    $sp, $sp, 0x20
/* 169BD8 80249378 00000000 */  nop       
/* 169BDC 8024937C 00000000 */  nop       
