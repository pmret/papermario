.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FE10
/* 2B210 8004FE10 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2B214 8004FE14 948500D4 */  lhu       $a1, 0xd4($a0)
/* 2B218 8004FE18 3046007F */  andi      $a2, $v0, 0x7f
/* 2B21C 8004FE1C 54C00001 */  bnel      $a2, $zero, .L8004FE24
/* 2B220 8004FE20 00063600 */   sll      $a2, $a2, 0x18
.L8004FE24:
/* 2B224 8004FE24 58A00001 */  blezl     $a1, .L8004FE2C
/* 2B228 8004FE28 24050001 */   addiu    $a1, $zero, 1
.L8004FE2C:
/* 2B22C 8004FE2C 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 2B230 8004FE30 00C21023 */  subu      $v0, $a2, $v0
/* 2B234 8004FE34 14A00002 */  bnez      $a1, .L8004FE40
/* 2B238 8004FE38 0045001A */   div      $zero, $v0, $a1
/* 2B23C 8004FE3C 0007000D */  break     7
.L8004FE40:
/* 2B240 8004FE40 2401FFFF */   addiu    $at, $zero, -1
/* 2B244 8004FE44 14A10004 */  bne       $a1, $at, .L8004FE58
/* 2B248 8004FE48 3C018000 */   lui      $at, 0x8000
/* 2B24C 8004FE4C 14410002 */  bne       $v0, $at, .L8004FE58
/* 2B250 8004FE50 00000000 */   nop      
/* 2B254 8004FE54 0006000D */  break     6
.L8004FE58:
/* 2B258 8004FE58 00001012 */   mflo     $v0
/* 2B25C 8004FE5C AC8500CC */  sw        $a1, 0xcc($a0)
/* 2B260 8004FE60 AC8600C8 */  sw        $a2, 0xc8($a0)
/* 2B264 8004FE64 03E00008 */  jr        $ra
/* 2B268 8004FE68 AC8200C4 */   sw       $v0, 0xc4($a0)
