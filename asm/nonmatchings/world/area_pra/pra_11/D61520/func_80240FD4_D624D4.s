.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FD4_D624D4
/* D624D4 80240FD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D624D8 80240FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* D624DC 80240FDC 0080802D */  daddu     $s0, $a0, $zero
/* D624E0 80240FE0 AFBF0018 */  sw        $ra, 0x18($sp)
/* D624E4 80240FE4 AFB10014 */  sw        $s1, 0x14($sp)
/* D624E8 80240FE8 8E02000C */  lw        $v0, 0xc($s0)
/* D624EC 80240FEC 8C510000 */  lw        $s1, ($v0)
/* D624F0 80240FF0 0C0B1EAF */  jal       get_variable
/* D624F4 80240FF4 0220282D */   daddu    $a1, $s1, $zero
/* D624F8 80240FF8 3C03FFF0 */  lui       $v1, 0xfff0
/* D624FC 80240FFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* D62500 80241000 0200202D */  daddu     $a0, $s0, $zero
/* D62504 80241004 00431024 */  and       $v0, $v0, $v1
/* D62508 80241008 00021140 */  sll       $v0, $v0, 5
/* D6250C 8024100C 3C068008 */  lui       $a2, %hi(gItemTable)
/* D62510 80241010 00C23021 */  addu      $a2, $a2, $v0
/* D62514 80241014 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D62518 80241018 0C0B2026 */  jal       set_variable
/* D6251C 8024101C 0220282D */   daddu    $a1, $s1, $zero
/* D62520 80241020 8FBF0018 */  lw        $ra, 0x18($sp)
/* D62524 80241024 8FB10014 */  lw        $s1, 0x14($sp)
/* D62528 80241028 8FB00010 */  lw        $s0, 0x10($sp)
/* D6252C 8024102C 24020002 */  addiu     $v0, $zero, 2
/* D62530 80241030 03E00008 */  jr        $ra
/* D62534 80241034 27BD0020 */   addiu    $sp, $sp, 0x20
