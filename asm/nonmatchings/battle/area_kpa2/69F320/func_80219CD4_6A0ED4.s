.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219CD4_6A0ED4
/* 6A0ED4 80219CD4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 6A0ED8 80219CD8 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 6A0EDC 80219CDC 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 6A0EE0 80219CE0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 6A0EE4 80219CE4 80620002 */  lb        $v0, 2($v1)
/* 6A0EE8 80219CE8 00023040 */  sll       $a2, $v0, 1
/* 6A0EEC 80219CEC 00C23021 */  addu      $a2, $a2, $v0
/* 6A0EF0 80219CF0 000630C0 */  sll       $a2, $a2, 3
/* 6A0EF4 80219CF4 00C23021 */  addu      $a2, $a2, $v0
/* 6A0EF8 80219CF8 80620003 */  lb        $v0, 3($v1)
/* 6A0EFC 80219CFC 00063080 */  sll       $a2, $a2, 2
/* 6A0F00 80219D00 14400002 */  bnez      $v0, .L80219D0C
/* 6A0F04 80219D04 00C2001A */   div      $zero, $a2, $v0
/* 6A0F08 80219D08 0007000D */  break     7
.L80219D0C:
/* 6A0F0C 80219D0C 2401FFFF */   addiu    $at, $zero, -1
/* 6A0F10 80219D10 14410004 */  bne       $v0, $at, .L80219D24
/* 6A0F14 80219D14 3C018000 */   lui      $at, 0x8000
/* 6A0F18 80219D18 14C10002 */  bne       $a2, $at, .L80219D24
/* 6A0F1C 80219D1C 00000000 */   nop      
/* 6A0F20 80219D20 0006000D */  break     6
.L80219D24:
/* 6A0F24 80219D24 00003012 */   mflo     $a2
/* 6A0F28 80219D28 8C82000C */  lw        $v0, 0xc($a0)
/* 6A0F2C 80219D2C 0C0B2026 */  jal       set_variable
/* 6A0F30 80219D30 8C450000 */   lw       $a1, ($v0)
/* 6A0F34 80219D34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 6A0F38 80219D38 24020002 */  addiu     $v0, $zero, 2
/* 6A0F3C 80219D3C 03E00008 */  jr        $ra
/* 6A0F40 80219D40 27BD0018 */   addiu    $sp, $sp, 0x18
