.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80238D48_70CA58
/* 70CA58 80238D48 3C05800E */  lui       $a1, %hi(gBattleStatus)
/* 70CA5C 80238D4C 24A5C070 */  addiu     $a1, $a1, %lo(gBattleStatus)
/* 70CA60 80238D50 80A200A4 */  lb        $v0, 0xa4($a1)
/* 70CA64 80238D54 8C8300AC */  lw        $v1, 0xac($a0)
/* 70CA68 80238D58 0043102A */  slt       $v0, $v0, $v1
/* 70CA6C 80238D5C 10400009 */  beqz      $v0, .L80238D84
/* 70CA70 80238D60 24020032 */   addiu    $v0, $zero, 0x32
/* 70CA74 80238D64 908300AF */  lbu       $v1, 0xaf($a0)
/* 70CA78 80238D68 A0A200A5 */  sb        $v0, 0xa5($a1)
/* 70CA7C 80238D6C 8CA2043C */  lw        $v0, 0x43c($a1)
/* 70CA80 80238D70 A0A300A4 */  sb        $v1, 0xa4($a1)
/* 70CA84 80238D74 00031E00 */  sll       $v1, $v1, 0x18
/* 70CA88 80238D78 8C42000C */  lw        $v0, 0xc($v0)
/* 70CA8C 80238D7C 00031E03 */  sra       $v1, $v1, 0x18
/* 70CA90 80238D80 A443001A */  sh        $v1, 0x1a($v0)
.L80238D84:
/* 70CA94 80238D84 03E00008 */  jr        $ra
/* 70CA98 80238D88 24020002 */   addiu    $v0, $zero, 2
