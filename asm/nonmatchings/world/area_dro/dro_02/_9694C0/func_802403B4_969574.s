.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403B4_969574
/* 969574 802403B4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 969578 802403B8 AFB00010 */  sw        $s0, 0x10($sp)
/* 96957C 802403BC 0080802D */  daddu     $s0, $a0, $zero
/* 969580 802403C0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 969584 802403C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 969588 802403C8 8E02000C */  lw        $v0, 0xc($s0)
/* 96958C 802403CC 8C510000 */  lw        $s1, ($v0)
/* 969590 802403D0 0C0B1EAF */  jal       get_variable
/* 969594 802403D4 0220282D */   daddu    $a1, $s1, $zero
/* 969598 802403D8 3C03FFF0 */  lui       $v1, 0xfff0
/* 96959C 802403DC 3463FFFF */  ori       $v1, $v1, 0xffff
/* 9695A0 802403E0 0200202D */  daddu     $a0, $s0, $zero
/* 9695A4 802403E4 00431024 */  and       $v0, $v0, $v1
/* 9695A8 802403E8 00021140 */  sll       $v0, $v0, 5
/* 9695AC 802403EC 3C068008 */  lui       $a2, %hi(gItemTable)
/* 9695B0 802403F0 00C23021 */  addu      $a2, $a2, $v0
/* 9695B4 802403F4 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 9695B8 802403F8 0C0B2026 */  jal       set_variable
/* 9695BC 802403FC 0220282D */   daddu    $a1, $s1, $zero
/* 9695C0 80240400 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9695C4 80240404 8FB10014 */  lw        $s1, 0x14($sp)
/* 9695C8 80240408 8FB00010 */  lw        $s0, 0x10($sp)
/* 9695CC 8024040C 24020002 */  addiu     $v0, $zero, 2
/* 9695D0 80240410 03E00008 */  jr        $ra
/* 9695D4 80240414 27BD0020 */   addiu    $sp, $sp, 0x20
