.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400F4_CA7394
/* CA7394 802400F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CA7398 802400F8 AFB00010 */  sw        $s0, 0x10($sp)
/* CA739C 802400FC 0080802D */  daddu     $s0, $a0, $zero
/* CA73A0 80240100 AFBF0018 */  sw        $ra, 0x18($sp)
/* CA73A4 80240104 AFB10014 */  sw        $s1, 0x14($sp)
/* CA73A8 80240108 8E02000C */  lw        $v0, 0xc($s0)
/* CA73AC 8024010C 8C510000 */  lw        $s1, ($v0)
/* CA73B0 80240110 0C0B1EAF */  jal       get_variable
/* CA73B4 80240114 0220282D */   daddu    $a1, $s1, $zero
/* CA73B8 80240118 3C03FFF0 */  lui       $v1, 0xfff0
/* CA73BC 8024011C 3463FFFF */  ori       $v1, $v1, 0xffff
/* CA73C0 80240120 0200202D */  daddu     $a0, $s0, $zero
/* CA73C4 80240124 00431024 */  and       $v0, $v0, $v1
/* CA73C8 80240128 00021140 */  sll       $v0, $v0, 5
/* CA73CC 8024012C 3C068008 */  lui       $a2, %hi(gItemTable)
/* CA73D0 80240130 00C23021 */  addu      $a2, $a2, $v0
/* CA73D4 80240134 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* CA73D8 80240138 0C0B2026 */  jal       set_variable
/* CA73DC 8024013C 0220282D */   daddu    $a1, $s1, $zero
/* CA73E0 80240140 8FBF0018 */  lw        $ra, 0x18($sp)
/* CA73E4 80240144 8FB10014 */  lw        $s1, 0x14($sp)
/* CA73E8 80240148 8FB00010 */  lw        $s0, 0x10($sp)
/* CA73EC 8024014C 24020002 */  addiu     $v0, $zero, 2
/* CA73F0 80240150 03E00008 */  jr        $ra
/* CA73F4 80240154 27BD0020 */   addiu    $sp, $sp, 0x20
