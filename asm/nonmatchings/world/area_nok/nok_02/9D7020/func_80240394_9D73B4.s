.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240394_9D73B4
/* 9D73B4 80240394 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D73B8 80240398 AFB00010 */  sw        $s0, 0x10($sp)
/* 9D73BC 8024039C 0080802D */  daddu     $s0, $a0, $zero
/* 9D73C0 802403A0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D73C4 802403A4 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D73C8 802403A8 8E02000C */  lw        $v0, 0xc($s0)
/* 9D73CC 802403AC 8C510000 */  lw        $s1, ($v0)
/* 9D73D0 802403B0 0C0B1EAF */  jal       get_variable
/* 9D73D4 802403B4 0220282D */   daddu    $a1, $s1, $zero
/* 9D73D8 802403B8 3C03FFF0 */  lui       $v1, 0xfff0
/* 9D73DC 802403BC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9D73E0 802403C0 0200202D */  daddu     $a0, $s0, $zero
/* 9D73E4 802403C4 00431024 */  and       $v0, $v0, $v1
/* 9D73E8 802403C8 00021140 */  sll       $v0, $v0, 5
/* 9D73EC 802403CC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9D73F0 802403D0 00C23021 */  addu      $a2, $a2, $v0
/* 9D73F4 802403D4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9D73F8 802403D8 0C0B2026 */  jal       set_variable
/* 9D73FC 802403DC 0220282D */   daddu    $a1, $s1, $zero
/* 9D7400 802403E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D7404 802403E4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D7408 802403E8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D740C 802403EC 24020002 */  addiu     $v0, $zero, 2
/* 9D7410 802403F0 03E00008 */  jr        $ra
/* 9D7414 802403F4 27BD0020 */   addiu    $sp, $sp, 0x20
