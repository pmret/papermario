.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243740
/* 803FC0 80243740 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 803FC4 80243744 AFB10014 */  sw        $s1, 0x14($sp)
/* 803FC8 80243748 0080882D */  daddu     $s1, $a0, $zero
/* 803FCC 8024374C AFBF0018 */  sw        $ra, 0x18($sp)
/* 803FD0 80243750 AFB00010 */  sw        $s0, 0x10($sp)
/* 803FD4 80243754 8E30000C */  lw        $s0, 0xc($s1)
/* 803FD8 80243758 8E050000 */  lw        $a1, ($s0)
/* 803FDC 8024375C 0C0B1EAF */  jal       get_variable
/* 803FE0 80243760 26100004 */   addiu    $s0, $s0, 4
/* 803FE4 80243764 0220202D */  daddu     $a0, $s1, $zero
/* 803FE8 80243768 8E050000 */  lw        $a1, ($s0)
/* 803FEC 8024376C 0C0B1EAF */  jal       get_variable
/* 803FF0 80243770 0040882D */   daddu    $s1, $v0, $zero
/* 803FF4 80243774 0000202D */  daddu     $a0, $zero, $zero
/* 803FF8 80243778 3C05FD05 */  lui       $a1, 0xfd05
/* 803FFC 8024377C 34A50F8A */  ori       $a1, $a1, 0xf8a
/* 804000 80243780 0C0B1EAF */  jal       get_variable
/* 804004 80243784 0040802D */   daddu    $s0, $v0, $zero
/* 804008 80243788 0040182D */  daddu     $v1, $v0, $zero
/* 80400C 8024378C AC710008 */  sw        $s1, 8($v1)
/* 804010 80243790 AC70000C */  sw        $s0, 0xc($v1)
/* 804014 80243794 8FBF0018 */  lw        $ra, 0x18($sp)
/* 804018 80243798 8FB10014 */  lw        $s1, 0x14($sp)
/* 80401C 8024379C 8FB00010 */  lw        $s0, 0x10($sp)
/* 804020 802437A0 24020002 */  addiu     $v0, $zero, 2
/* 804024 802437A4 03E00008 */  jr        $ra
/* 804028 802437A8 27BD0020 */   addiu    $sp, $sp, 0x20
