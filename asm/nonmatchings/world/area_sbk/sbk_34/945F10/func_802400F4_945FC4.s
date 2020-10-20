.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F4_945FC4
/* 945FC4 802400F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 945FC8 802400F8 AFB00010 */  sw        $s0, 0x10($sp)
/* 945FCC 802400FC 0080802D */  daddu     $s0, $a0, $zero
/* 945FD0 80240100 AFBF0018 */  sw        $ra, 0x18($sp)
/* 945FD4 80240104 AFB10014 */  sw        $s1, 0x14($sp)
/* 945FD8 80240108 8E02000C */  lw        $v0, 0xc($s0)
/* 945FDC 8024010C 8C510000 */  lw        $s1, ($v0)
/* 945FE0 80240110 0C0B1EAF */  jal       get_variable
/* 945FE4 80240114 0220282D */   daddu    $a1, $s1, $zero
/* 945FE8 80240118 3C03FFF0 */  lui       $v1, 0xfff0
/* 945FEC 8024011C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 945FF0 80240120 0200202D */  daddu     $a0, $s0, $zero
/* 945FF4 80240124 00431024 */  and       $v0, $v0, $v1
/* 945FF8 80240128 00021140 */  sll       $v0, $v0, 5
/* 945FFC 8024012C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 946000 80240130 00C23021 */  addu      $a2, $a2, $v0
/* 946004 80240134 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 946008 80240138 0C0B2026 */  jal       set_variable
/* 94600C 8024013C 0220282D */   daddu    $a1, $s1, $zero
/* 946010 80240140 8FBF0018 */  lw        $ra, 0x18($sp)
/* 946014 80240144 8FB10014 */  lw        $s1, 0x14($sp)
/* 946018 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* 94601C 8024014C 24020002 */  addiu     $v0, $zero, 2
/* 946020 80240150 03E00008 */  jr        $ra
/* 946024 80240154 27BD0020 */   addiu    $sp, $sp, 0x20
