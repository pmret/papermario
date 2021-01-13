.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024107C_91C95C
/* 91C95C 8024107C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 91C960 80241080 AFB00010 */  sw        $s0, 0x10($sp)
/* 91C964 80241084 0080802D */  daddu     $s0, $a0, $zero
/* 91C968 80241088 AFBF0018 */  sw        $ra, 0x18($sp)
/* 91C96C 8024108C AFB10014 */  sw        $s1, 0x14($sp)
/* 91C970 80241090 8E11000C */  lw        $s1, 0xc($s0)
/* 91C974 80241094 0C0B36B0 */  jal       resolve_npc
/* 91C978 80241098 2405FFFF */   addiu    $a1, $zero, -1
/* 91C97C 8024109C 0200202D */  daddu     $a0, $s0, $zero
/* 91C980 802410A0 8E250000 */  lw        $a1, ($s1)
/* 91C984 802410A4 0C0B1EAF */  jal       get_variable
/* 91C988 802410A8 0040802D */   daddu    $s0, $v0, $zero
/* 91C98C 802410AC 44820000 */  mtc1      $v0, $f0
/* 91C990 802410B0 00000000 */  nop
/* 91C994 802410B4 46800020 */  cvt.s.w   $f0, $f0
/* 91C998 802410B8 E6000034 */  swc1      $f0, 0x34($s0)
/* 91C99C 802410BC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 91C9A0 802410C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 91C9A4 802410C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 91C9A8 802410C8 24020002 */  addiu     $v0, $zero, 2
/* 91C9AC 802410CC 03E00008 */  jr        $ra
/* 91C9B0 802410D0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 91C9B4 802410D4 00000000 */  nop
/* 91C9B8 802410D8 00000000 */  nop
/* 91C9BC 802410DC 00000000 */  nop
