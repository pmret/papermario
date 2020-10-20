.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242FD4_DC0284
/* DC0284 80242FD4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DC0288 80242FD8 AFB00010 */  sw        $s0, 0x10($sp)
/* DC028C 80242FDC 0080802D */  daddu     $s0, $a0, $zero
/* DC0290 80242FE0 AFBF0018 */  sw        $ra, 0x18($sp)
/* DC0294 80242FE4 AFB10014 */  sw        $s1, 0x14($sp)
/* DC0298 80242FE8 8E02000C */  lw        $v0, 0xc($s0)
/* DC029C 80242FEC 8C510000 */  lw        $s1, ($v0)
/* DC02A0 80242FF0 0C0B1EAF */  jal       get_variable
/* DC02A4 80242FF4 0220282D */   daddu    $a1, $s1, $zero
/* DC02A8 80242FF8 3C03FFF0 */  lui       $v1, 0xfff0
/* DC02AC 80242FFC 3463FFFF */  ori       $v1, $v1, 0xffff
/* DC02B0 80243000 0200202D */  daddu     $a0, $s0, $zero
/* DC02B4 80243004 00431024 */  and       $v0, $v0, $v1
/* DC02B8 80243008 00021140 */  sll       $v0, $v0, 5
/* DC02BC 8024300C 3C068008 */  lui       $a2, %hi(gItemTable)
/* DC02C0 80243010 00C23021 */  addu      $a2, $a2, $v0
/* DC02C4 80243014 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* DC02C8 80243018 0C0B2026 */  jal       set_variable
/* DC02CC 8024301C 0220282D */   daddu    $a1, $s1, $zero
/* DC02D0 80243020 8FBF0018 */  lw        $ra, 0x18($sp)
/* DC02D4 80243024 8FB10014 */  lw        $s1, 0x14($sp)
/* DC02D8 80243028 8FB00010 */  lw        $s0, 0x10($sp)
/* DC02DC 8024302C 24020002 */  addiu     $v0, $zero, 2
/* DC02E0 80243030 03E00008 */  jr        $ra
/* DC02E4 80243034 27BD0020 */   addiu    $sp, $sp, 0x20
