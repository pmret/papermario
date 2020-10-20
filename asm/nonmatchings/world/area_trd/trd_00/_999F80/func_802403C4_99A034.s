.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C4_99A034
/* 99A034 802403C4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 99A038 802403C8 AFB00010 */  sw        $s0, 0x10($sp)
/* 99A03C 802403CC 0080802D */  daddu     $s0, $a0, $zero
/* 99A040 802403D0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 99A044 802403D4 AFB10014 */  sw        $s1, 0x14($sp)
/* 99A048 802403D8 8E02000C */  lw        $v0, 0xc($s0)
/* 99A04C 802403DC 8C510000 */  lw        $s1, ($v0)
/* 99A050 802403E0 0C0B1EAF */  jal       get_variable
/* 99A054 802403E4 0220282D */   daddu    $a1, $s1, $zero
/* 99A058 802403E8 3C03FFF0 */  lui       $v1, 0xfff0
/* 99A05C 802403EC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 99A060 802403F0 0200202D */  daddu     $a0, $s0, $zero
/* 99A064 802403F4 00431024 */  and       $v0, $v0, $v1
/* 99A068 802403F8 00021140 */  sll       $v0, $v0, 5
/* 99A06C 802403FC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 99A070 80240400 00C23021 */  addu      $a2, $a2, $v0
/* 99A074 80240404 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 99A078 80240408 0C0B2026 */  jal       set_variable
/* 99A07C 8024040C 0220282D */   daddu    $a1, $s1, $zero
/* 99A080 80240410 8FBF0018 */  lw        $ra, 0x18($sp)
/* 99A084 80240414 8FB10014 */  lw        $s1, 0x14($sp)
/* 99A088 80240418 8FB00010 */  lw        $s0, 0x10($sp)
/* 99A08C 8024041C 24020002 */  addiu     $v0, $zero, 2
/* 99A090 80240420 03E00008 */  jr        $ra
/* 99A094 80240424 27BD0020 */   addiu    $sp, $sp, 0x20
