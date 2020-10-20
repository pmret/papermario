.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242608
/* 833E08 80242608 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 833E0C 8024260C AFB10014 */  sw        $s1, 0x14($sp)
/* 833E10 80242610 0080882D */  daddu     $s1, $a0, $zero
/* 833E14 80242614 3C05FD05 */  lui       $a1, 0xfd05
/* 833E18 80242618 34A50F82 */  ori       $a1, $a1, 0xf82
/* 833E1C 8024261C AFBF001C */  sw        $ra, 0x1c($sp)
/* 833E20 80242620 AFB20018 */  sw        $s2, 0x18($sp)
/* 833E24 80242624 0C0B1EAF */  jal       get_variable
/* 833E28 80242628 AFB00010 */   sw       $s0, 0x10($sp)
/* 833E2C 8024262C 0220202D */  daddu     $a0, $s1, $zero
/* 833E30 80242630 8E30000C */  lw        $s0, 0xc($s1)
/* 833E34 80242634 0040902D */  daddu     $s2, $v0, $zero
/* 833E38 80242638 8E050000 */  lw        $a1, ($s0)
/* 833E3C 8024263C 0C0B1EAF */  jal       get_variable
/* 833E40 80242640 26100004 */   addiu    $s0, $s0, 4
/* 833E44 80242644 0220202D */  daddu     $a0, $s1, $zero
/* 833E48 80242648 8E050000 */  lw        $a1, ($s0)
/* 833E4C 8024264C 0C0B1EAF */  jal       get_variable
/* 833E50 80242650 0040802D */   daddu    $s0, $v0, $zero
/* 833E54 80242654 8E44000C */  lw        $a0, 0xc($s2)
/* 833E58 80242658 00101880 */  sll       $v1, $s0, 2
/* 833E5C 8024265C 00832021 */  addu      $a0, $a0, $v1
/* 833E60 80242660 8C830008 */  lw        $v1, 8($a0)
/* 833E64 80242664 34630002 */  ori       $v1, $v1, 2
/* 833E68 80242668 AC830008 */  sw        $v1, 8($a0)
/* 833E6C 8024266C 8E43000C */  lw        $v1, 0xc($s2)
/* 833E70 80242670 00701821 */  addu      $v1, $v1, $s0
/* 833E74 80242674 A06200EF */  sb        $v0, 0xef($v1)
/* 833E78 80242678 8FBF001C */  lw        $ra, 0x1c($sp)
/* 833E7C 8024267C 8FB20018 */  lw        $s2, 0x18($sp)
/* 833E80 80242680 8FB10014 */  lw        $s1, 0x14($sp)
/* 833E84 80242684 8FB00010 */  lw        $s0, 0x10($sp)
/* 833E88 80242688 24020002 */  addiu     $v0, $zero, 2
/* 833E8C 8024268C 03E00008 */  jr        $ra
/* 833E90 80242690 27BD0020 */   addiu    $sp, $sp, 0x20
