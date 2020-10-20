.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802434B4
/* 7EE1C4 802434B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EE1C8 802434B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 7EE1CC 802434BC 0080802D */  daddu     $s0, $a0, $zero
/* 7EE1D0 802434C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EE1D4 802434C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EE1D8 802434C8 8E02000C */  lw        $v0, 0xc($s0)
/* 7EE1DC 802434CC 8C510000 */  lw        $s1, ($v0)
/* 7EE1E0 802434D0 0C0B1EAF */  jal       get_variable
/* 7EE1E4 802434D4 0220282D */   daddu    $a1, $s1, $zero
/* 7EE1E8 802434D8 3C03FFF0 */  lui       $v1, 0xfff0
/* 7EE1EC 802434DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 7EE1F0 802434E0 0200202D */  daddu     $a0, $s0, $zero
/* 7EE1F4 802434E4 00431024 */  and       $v0, $v0, $v1
/* 7EE1F8 802434E8 00021140 */  sll       $v0, $v0, 5
/* 7EE1FC 802434EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 7EE200 802434F0 00C23021 */  addu      $a2, $a2, $v0
/* 7EE204 802434F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 7EE208 802434F8 0C0B2026 */  jal       set_variable
/* 7EE20C 802434FC 0220282D */   daddu    $a1, $s1, $zero
/* 7EE210 80243500 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EE214 80243504 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EE218 80243508 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EE21C 8024350C 24020002 */  addiu     $v0, $zero, 2
/* 7EE220 80243510 03E00008 */  jr        $ra
/* 7EE224 80243514 27BD0020 */   addiu    $sp, $sp, 0x20
