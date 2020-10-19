.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_A59754
/* A59754 802403C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A59758 802403C8 AFB00010 */  sw        $s0, 0x10($sp)
/* A5975C 802403CC 0080802D */  daddu     $s0, $a0, $zero
/* A59760 802403D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A59764 802403D4 AFB10014 */  sw        $s1, 0x14($sp)
/* A59768 802403D8 8E02000C */  lw        $v0, 0xc($s0)
/* A5976C 802403DC 8C510000 */  lw        $s1, ($v0)
/* A59770 802403E0 0C0B1EAF */  jal       get_variable
/* A59774 802403E4 0220282D */   daddu    $a1, $s1, $zero
/* A59778 802403E8 3C03FFF0 */  lui       $v1, 0xfff0
/* A5977C 802403EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* A59780 802403F0 0200202D */  daddu     $a0, $s0, $zero
/* A59784 802403F4 00431024 */  and       $v0, $v0, $v1
/* A59788 802403F8 00021140 */  sll       $v0, $v0, 5
/* A5978C 802403FC 3C068008 */  lui       $a2, %hi(gItemTable)
/* A59790 80240400 00C23021 */  addu      $a2, $a2, $v0
/* A59794 80240404 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* A59798 80240408 0C0B2026 */  jal       set_variable
/* A5979C 8024040C 0220282D */   daddu    $a1, $s1, $zero
/* A597A0 80240410 8FBF0018 */  lw        $ra, 0x18($sp)
/* A597A4 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* A597A8 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* A597AC 8024041C 24020002 */  addiu     $v0, $zero, 2
/* A597B0 80240420 03E00008 */  jr        $ra
/* A597B4 80240424 27BD0020 */   addiu    $sp, $sp, 0x20
