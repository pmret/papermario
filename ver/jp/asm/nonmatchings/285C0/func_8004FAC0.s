.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FAC0
/* 2AEC0 8004FAC0 908200D6 */  lbu       $v0, 0xd6($a0)
/* 2AEC4 8004FAC4 948500D4 */  lhu       $a1, 0xd4($a0)
/* 2AEC8 8004FAC8 3046007F */  andi      $a2, $v0, 0x7f
/* 2AECC 8004FACC 54C00001 */  bnel      $a2, $zero, .L8004FAD4
/* 2AED0 8004FAD0 00063600 */   sll      $a2, $a2, 0x18
.L8004FAD4:
/* 2AED4 8004FAD4 58A00001 */  blezl     $a1, .L8004FADC
/* 2AED8 8004FAD8 24050001 */   addiu    $a1, $zero, 1
.L8004FADC:
/* 2AEDC 8004FADC 8C8200C0 */  lw        $v0, 0xc0($a0)
/* 2AEE0 8004FAE0 00C21023 */  subu      $v0, $a2, $v0
/* 2AEE4 8004FAE4 14A00002 */  bnez      $a1, .L8004FAF0
/* 2AEE8 8004FAE8 0045001A */   div      $zero, $v0, $a1
/* 2AEEC 8004FAEC 0007000D */  break     7
.L8004FAF0:
/* 2AEF0 8004FAF0 2401FFFF */   addiu    $at, $zero, -1
/* 2AEF4 8004FAF4 14A10004 */  bne       $a1, $at, .L8004FB08
/* 2AEF8 8004FAF8 3C018000 */   lui      $at, 0x8000
/* 2AEFC 8004FAFC 14410002 */  bne       $v0, $at, .L8004FB08
/* 2AF00 8004FB00 00000000 */   nop
/* 2AF04 8004FB04 0006000D */  break     6
.L8004FB08:
/* 2AF08 8004FB08 00001012 */   mflo     $v0
/* 2AF0C 8004FB0C AC8500CC */  sw        $a1, 0xcc($a0)
/* 2AF10 8004FB10 AC8600C8 */  sw        $a2, 0xc8($a0)
/* 2AF14 8004FB14 03E00008 */  jr        $ra
/* 2AF18 8004FB18 AC8200C4 */   sw       $v0, 0xc4($a0)
