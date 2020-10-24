.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241094_916E04
/* 916E04 80241094 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 916E08 80241098 AFB00010 */  sw        $s0, 0x10($sp)
/* 916E0C 8024109C 0080802D */  daddu     $s0, $a0, $zero
/* 916E10 802410A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 916E14 802410A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 916E18 802410A8 8E02000C */  lw        $v0, 0xc($s0)
/* 916E1C 802410AC 8C510000 */  lw        $s1, ($v0)
/* 916E20 802410B0 0C0B1EAF */  jal       get_variable
/* 916E24 802410B4 0220282D */   daddu    $a1, $s1, $zero
/* 916E28 802410B8 3C03FFF0 */  lui       $v1, 0xfff0
/* 916E2C 802410BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 916E30 802410C0 0200202D */  daddu     $a0, $s0, $zero
/* 916E34 802410C4 00431024 */  and       $v0, $v0, $v1
/* 916E38 802410C8 00021140 */  sll       $v0, $v0, 5
/* 916E3C 802410CC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 916E40 802410D0 00C23021 */  addu      $a2, $a2, $v0
/* 916E44 802410D4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 916E48 802410D8 0C0B2026 */  jal       set_variable
/* 916E4C 802410DC 0220282D */   daddu    $a1, $s1, $zero
/* 916E50 802410E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 916E54 802410E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 916E58 802410E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 916E5C 802410EC 24020002 */  addiu     $v0, $zero, 2
/* 916E60 802410F0 03E00008 */  jr        $ra
/* 916E64 802410F4 27BD0020 */   addiu    $sp, $sp, 0x20
/* 916E68 802410F8 00000000 */  nop       
/* 916E6C 802410FC 00000000 */  nop       
