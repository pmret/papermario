.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241064_C56FA4
/* C56FA4 80241064 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C56FA8 80241068 AFB00010 */  sw        $s0, 0x10($sp)
/* C56FAC 8024106C 0080802D */  daddu     $s0, $a0, $zero
/* C56FB0 80241070 AFBF0018 */  sw        $ra, 0x18($sp)
/* C56FB4 80241074 AFB10014 */  sw        $s1, 0x14($sp)
/* C56FB8 80241078 8E02000C */  lw        $v0, 0xc($s0)
/* C56FBC 8024107C 8C510000 */  lw        $s1, ($v0)
/* C56FC0 80241080 0C0B1EAF */  jal       get_variable
/* C56FC4 80241084 0220282D */   daddu    $a1, $s1, $zero
/* C56FC8 80241088 3C03FFF0 */  lui       $v1, 0xfff0
/* C56FCC 8024108C 3463FFFF */  ori       $v1, $v1, 0xffff
/* C56FD0 80241090 0200202D */  daddu     $a0, $s0, $zero
/* C56FD4 80241094 00431024 */  and       $v0, $v0, $v1
/* C56FD8 80241098 00021140 */  sll       $v0, $v0, 5
/* C56FDC 8024109C 3C068008 */  lui       $a2, %hi(gItemTable)
/* C56FE0 802410A0 00C23021 */  addu      $a2, $a2, $v0
/* C56FE4 802410A4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C56FE8 802410A8 0C0B2026 */  jal       set_variable
/* C56FEC 802410AC 0220282D */   daddu    $a1, $s1, $zero
/* C56FF0 802410B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C56FF4 802410B4 8FB10014 */  lw        $s1, 0x14($sp)
/* C56FF8 802410B8 8FB00010 */  lw        $s0, 0x10($sp)
/* C56FFC 802410BC 24020002 */  addiu     $v0, $zero, 2
/* C57000 802410C0 03E00008 */  jr        $ra
/* C57004 802410C4 27BD0020 */   addiu    $sp, $sp, 0x20
