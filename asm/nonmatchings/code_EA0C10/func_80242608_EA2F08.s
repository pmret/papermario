.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242608_EA2F08
/* EA2F08 80242608 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EA2F0C 8024260C 0080102D */  daddu     $v0, $a0, $zero
/* EA2F10 80242610 AFB00010 */  sw        $s0, 0x10($sp)
/* EA2F14 80242614 AFBF0018 */  sw        $ra, 0x18($sp)
/* EA2F18 80242618 AFB10014 */  sw        $s1, 0x14($sp)
/* EA2F1C 8024261C 8C44014C */  lw        $a0, 0x14c($v0)
/* EA2F20 80242620 8C510148 */  lw        $s1, 0x148($v0)
/* EA2F24 80242624 0C00F94D */  jal       func_8003E534
/* EA2F28 80242628 00A0802D */   daddu    $s0, $a1, $zero
/* EA2F2C 8024262C 56000001 */  bnel      $s0, $zero, .L80242634
/* EA2F30 80242630 A04000AB */   sb       $zero, 0xab($v0)
.L80242634:
/* EA2F34 80242634 8C420000 */  lw        $v0, ($v0)
/* EA2F38 80242638 30421000 */  andi      $v0, $v0, 0x1000
/* EA2F3C 8024263C 1040000A */  beqz      $v0, .L80242668
/* EA2F40 80242640 0000102D */   daddu    $v0, $zero, $zero
/* EA2F44 80242644 82220004 */  lb        $v0, 4($s1)
/* EA2F48 80242648 3C03800B */  lui       $v1, %hi(D_800B7EF0)
/* EA2F4C 8024264C 24637EF0 */  addiu     $v1, $v1, %lo(D_800B7EF0)
/* EA2F50 80242650 00021080 */  sll       $v0, $v0, 2
/* EA2F54 80242654 00431021 */  addu      $v0, $v0, $v1
/* EA2F58 80242658 8C440028 */  lw        $a0, 0x28($v0)
/* EA2F5C 8024265C 9623006E */  lhu       $v1, 0x6e($s1)
/* EA2F60 80242660 24020002 */  addiu     $v0, $zero, 2
/* EA2F64 80242664 A4830044 */  sh        $v1, 0x44($a0)
.L80242668:
/* EA2F68 80242668 8FBF0018 */  lw        $ra, 0x18($sp)
/* EA2F6C 8024266C 8FB10014 */  lw        $s1, 0x14($sp)
/* EA2F70 80242670 8FB00010 */  lw        $s0, 0x10($sp)
/* EA2F74 80242674 03E00008 */  jr        $ra
/* EA2F78 80242678 27BD0020 */   addiu    $sp, $sp, 0x20
