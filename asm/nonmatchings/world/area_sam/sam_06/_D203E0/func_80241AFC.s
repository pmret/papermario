.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241AFC
/* D2198C 80241AFC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D21990 80241B00 AFB00010 */  sw        $s0, 0x10($sp)
/* D21994 80241B04 0080802D */  daddu     $s0, $a0, $zero
/* D21998 80241B08 AFBF0018 */  sw        $ra, 0x18($sp)
/* D2199C 80241B0C AFB10014 */  sw        $s1, 0x14($sp)
/* D219A0 80241B10 8E02000C */  lw        $v0, 0xc($s0)
/* D219A4 80241B14 8C510000 */  lw        $s1, ($v0)
/* D219A8 80241B18 0C0B1EAF */  jal       get_variable
/* D219AC 80241B1C 0220282D */   daddu    $a1, $s1, $zero
/* D219B0 80241B20 3C03FFF0 */  lui       $v1, 0xfff0
/* D219B4 80241B24 3463FFFF */  ori       $v1, $v1, 0xffff
/* D219B8 80241B28 0200202D */  daddu     $a0, $s0, $zero
/* D219BC 80241B2C 00431024 */  and       $v0, $v0, $v1
/* D219C0 80241B30 00021140 */  sll       $v0, $v0, 5
/* D219C4 80241B34 3C068008 */  lui       $a2, %hi(gItemTable)
/* D219C8 80241B38 00C23021 */  addu      $a2, $a2, $v0
/* D219CC 80241B3C 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* D219D0 80241B40 0C0B2026 */  jal       set_variable
/* D219D4 80241B44 0220282D */   daddu    $a1, $s1, $zero
/* D219D8 80241B48 8FBF0018 */  lw        $ra, 0x18($sp)
/* D219DC 80241B4C 8FB10014 */  lw        $s1, 0x14($sp)
/* D219E0 80241B50 8FB00010 */  lw        $s0, 0x10($sp)
/* D219E4 80241B54 24020002 */  addiu     $v0, $zero, 2
/* D219E8 80241B58 03E00008 */  jr        $ra
/* D219EC 80241B5C 27BD0020 */   addiu    $sp, $sp, 0x20
