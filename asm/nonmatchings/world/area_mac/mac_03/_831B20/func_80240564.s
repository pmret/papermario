.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240564
/* 831D64 80240564 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 831D68 80240568 AFB00010 */  sw        $s0, 0x10($sp)
/* 831D6C 8024056C 0080802D */  daddu     $s0, $a0, $zero
/* 831D70 80240570 AFBF0018 */  sw        $ra, 0x18($sp)
/* 831D74 80240574 AFB10014 */  sw        $s1, 0x14($sp)
/* 831D78 80240578 8E02000C */  lw        $v0, 0xc($s0)
/* 831D7C 8024057C 8C510000 */  lw        $s1, ($v0)
/* 831D80 80240580 0C0B1EAF */  jal       get_variable
/* 831D84 80240584 0220282D */   daddu    $a1, $s1, $zero
/* 831D88 80240588 3C03FFF0 */  lui       $v1, 0xfff0
/* 831D8C 8024058C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 831D90 80240590 0200202D */  daddu     $a0, $s0, $zero
/* 831D94 80240594 00431024 */  and       $v0, $v0, $v1
/* 831D98 80240598 00021140 */  sll       $v0, $v0, 5
/* 831D9C 8024059C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 831DA0 802405A0 00C23021 */  addu      $a2, $a2, $v0
/* 831DA4 802405A4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 831DA8 802405A8 0C0B2026 */  jal       set_variable
/* 831DAC 802405AC 0220282D */   daddu    $a1, $s1, $zero
/* 831DB0 802405B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 831DB4 802405B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 831DB8 802405B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 831DBC 802405BC 24020002 */  addiu     $v0, $zero, 2
/* 831DC0 802405C0 03E00008 */  jr        $ra
/* 831DC4 802405C4 27BD0020 */   addiu    $sp, $sp, 0x20
