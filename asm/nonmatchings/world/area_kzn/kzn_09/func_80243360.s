.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243360
/* C7A040 80243360 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C7A044 80243364 AFB00010 */  sw        $s0, 0x10($sp)
/* C7A048 80243368 0080802D */  daddu     $s0, $a0, $zero
/* C7A04C 8024336C AFBF0018 */  sw        $ra, 0x18($sp)
/* C7A050 80243370 AFB10014 */  sw        $s1, 0x14($sp)
/* C7A054 80243374 8E02000C */  lw        $v0, 0xc($s0)
/* C7A058 80243378 8C510000 */  lw        $s1, ($v0)
/* C7A05C 8024337C 0C0B1EAF */  jal       get_variable
/* C7A060 80243380 0220282D */   daddu    $a1, $s1, $zero
/* C7A064 80243384 3C03FFF0 */  lui       $v1, 0xfff0
/* C7A068 80243388 3463FFFF */  ori       $v1, $v1, 0xffff
/* C7A06C 8024338C 0200202D */  daddu     $a0, $s0, $zero
/* C7A070 80243390 00431024 */  and       $v0, $v0, $v1
/* C7A074 80243394 00021140 */  sll       $v0, $v0, 5
/* C7A078 80243398 3C068008 */  lui       $a2, %hi(gItemTable)
/* C7A07C 8024339C 00C23021 */  addu      $a2, $a2, $v0
/* C7A080 802433A0 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* C7A084 802433A4 0C0B2026 */  jal       set_variable
/* C7A088 802433A8 0220282D */   daddu    $a1, $s1, $zero
/* C7A08C 802433AC 8FBF0018 */  lw        $ra, 0x18($sp)
/* C7A090 802433B0 8FB10014 */  lw        $s1, 0x14($sp)
/* C7A094 802433B4 8FB00010 */  lw        $s0, 0x10($sp)
/* C7A098 802433B8 24020002 */  addiu     $v0, $zero, 2
/* C7A09C 802433BC 03E00008 */  jr        $ra
/* C7A0A0 802433C0 27BD0020 */   addiu    $sp, $sp, 0x20
