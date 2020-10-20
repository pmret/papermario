.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802410C8_B9EA28
/* B9EA28 802410C8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B9EA2C 802410CC AFB00010 */  sw        $s0, 0x10($sp)
/* B9EA30 802410D0 0080802D */  daddu     $s0, $a0, $zero
/* B9EA34 802410D4 AFBF0018 */  sw        $ra, 0x18($sp)
/* B9EA38 802410D8 AFB10014 */  sw        $s1, 0x14($sp)
/* B9EA3C 802410DC 8E02000C */  lw        $v0, 0xc($s0)
/* B9EA40 802410E0 8C510000 */  lw        $s1, ($v0)
/* B9EA44 802410E4 0C0B1EAF */  jal       get_variable
/* B9EA48 802410E8 0220282D */   daddu    $a1, $s1, $zero
/* B9EA4C 802410EC 3C03FFF0 */  lui       $v1, 0xfff0
/* B9EA50 802410F0 3463FFFF */  ori       $v1, $v1, 0xffff
/* B9EA54 802410F4 0200202D */  daddu     $a0, $s0, $zero
/* B9EA58 802410F8 00431024 */  and       $v0, $v0, $v1
/* B9EA5C 802410FC 00021140 */  sll       $v0, $v0, 5
/* B9EA60 80241100 3C068008 */  lui       $a2, %hi(gItemTable)
/* B9EA64 80241104 00C23021 */  addu      $a2, $a2, $v0
/* B9EA68 80241108 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* B9EA6C 8024110C 0C0B2026 */  jal       set_variable
/* B9EA70 80241110 0220282D */   daddu    $a1, $s1, $zero
/* B9EA74 80241114 8FBF0018 */  lw        $ra, 0x18($sp)
/* B9EA78 80241118 8FB10014 */  lw        $s1, 0x14($sp)
/* B9EA7C 8024111C 8FB00010 */  lw        $s0, 0x10($sp)
/* B9EA80 80241120 24020002 */  addiu     $v0, $zero, 2
/* B9EA84 80241124 03E00008 */  jr        $ra
/* B9EA88 80241128 27BD0020 */   addiu    $sp, $sp, 0x20
/* B9EA8C 8024112C 00000000 */  nop       
