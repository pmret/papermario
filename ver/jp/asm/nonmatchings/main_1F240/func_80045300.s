.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045300
/* 20700 80045300 3C07800B */  lui       $a3, %hi(D_800B0EF0)
/* 20704 80045304 24E70EF0 */  addiu     $a3, $a3, %lo(D_800B0EF0)
/* 20708 80045308 0000302D */  daddu     $a2, $zero, $zero
/* 2070C 8004530C 00C0282D */  daddu     $a1, $a2, $zero
.L80045310:
/* 20710 80045310 0000202D */  daddu     $a0, $zero, $zero
/* 20714 80045314 00A0182D */  daddu     $v1, $a1, $zero
.L80045318:
/* 20718 80045318 00E31021 */  addu      $v0, $a3, $v1
/* 2071C 8004531C AC4000B0 */  sw        $zero, 0xb0($v0)
/* 20720 80045320 24840001 */  addiu     $a0, $a0, 1
/* 20724 80045324 2882000C */  slti      $v0, $a0, 0xc
/* 20728 80045328 1440FFFB */  bnez      $v0, .L80045318
/* 2072C 8004532C 24630004 */   addiu    $v1, $v1, 4
/* 20730 80045330 24C60001 */  addiu     $a2, $a2, 1
/* 20734 80045334 28C2003C */  slti      $v0, $a2, 0x3c
/* 20738 80045338 1440FFF5 */  bnez      $v0, .L80045310
/* 2073C 8004533C 24A50030 */   addiu    $a1, $a1, 0x30
/* 20740 80045340 03E00008 */  jr        $ra
/* 20744 80045344 24020002 */   addiu    $v0, $zero, 2
