.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802E14D8
/* 102D58 802E14D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 102D5C 802E14DC AFBF0014 */  sw        $ra, 0x14($sp)
/* 102D60 802E14E0 AFB00010 */  sw        $s0, 0x10($sp)
/* 102D64 802E14E4 8C900040 */  lw        $s0, 0x40($a0)
/* 102D68 802E14E8 96020022 */  lhu       $v0, 0x22($s0)
/* 102D6C 802E14EC 2443FFFF */  addiu     $v1, $v0, -1
/* 102D70 802E14F0 3042FFFF */  andi      $v0, $v0, 0xffff
/* 102D74 802E14F4 10400009 */  beqz      $v0, .L802E151C
/* 102D78 802E14F8 A6030022 */   sh       $v1, 0x22($s0)
/* 102D7C 802E14FC C480004C */  lwc1      $f0, 0x4c($a0)
/* 102D80 802E1500 3C01802F */  lui       $at, %hi(D_802EB008)
/* 102D84 802E1504 D422B008 */  ldc1      $f2, %lo(D_802EB008)($at)
/* 102D88 802E1508 46000021 */  cvt.d.s   $f0, $f0
/* 102D8C 802E150C 46220000 */  add.d     $f0, $f0, $f2
/* 102D90 802E1510 46200020 */  cvt.s.d   $f0, $f0
/* 102D94 802E1514 080B854B */  j         .L802E152C
/* 102D98 802E1518 E480004C */   swc1     $f0, 0x4c($a0)
.L802E151C:
/* 102D9C 802E151C 0C043F5A */  jal       func_8010FD68
/* 102DA0 802E1520 00000000 */   nop      
/* 102DA4 802E1524 24020008 */  addiu     $v0, $zero, 8
/* 102DA8 802E1528 A6020022 */  sh        $v0, 0x22($s0)
.L802E152C:
/* 102DAC 802E152C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 102DB0 802E1530 8FB00010 */  lw        $s0, 0x10($sp)
/* 102DB4 802E1534 03E00008 */  jr        $ra
/* 102DB8 802E1538 27BD0018 */   addiu    $sp, $sp, 0x18
