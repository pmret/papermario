.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240444
/* 8B04B4 80240444 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8B04B8 80240448 AFB00010 */  sw        $s0, 0x10($sp)
/* 8B04BC 8024044C 0080802D */  daddu     $s0, $a0, $zero
/* 8B04C0 80240450 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8B04C4 80240454 AFB10014 */  sw        $s1, 0x14($sp)
/* 8B04C8 80240458 8E02000C */  lw        $v0, 0xc($s0)
/* 8B04CC 8024045C 8C510000 */  lw        $s1, ($v0)
/* 8B04D0 80240460 0C0B1EAF */  jal       get_variable
/* 8B04D4 80240464 0220282D */   daddu    $a1, $s1, $zero
/* 8B04D8 80240468 3C03FFF0 */  lui       $v1, 0xfff0
/* 8B04DC 8024046C 3463FFFF */  ori       $v1, $v1, 0xffff
/* 8B04E0 80240470 0200202D */  daddu     $a0, $s0, $zero
/* 8B04E4 80240474 00431024 */  and       $v0, $v0, $v1
/* 8B04E8 80240478 00021140 */  sll       $v0, $v0, 5
/* 8B04EC 8024047C 3C068008 */  lui       $a2, %hi(gItemTable)
/* 8B04F0 80240480 00C23021 */  addu      $a2, $a2, $v0
/* 8B04F4 80240484 8CC678E0 */  lw        $a2, %lo(gItemTable)($a2)
/* 8B04F8 80240488 0C0B2026 */  jal       set_variable
/* 8B04FC 8024048C 0220282D */   daddu    $a1, $s1, $zero
/* 8B0500 80240490 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8B0504 80240494 8FB10014 */  lw        $s1, 0x14($sp)
/* 8B0508 80240498 8FB00010 */  lw        $s0, 0x10($sp)
/* 8B050C 8024049C 24020002 */  addiu     $v0, $zero, 2
/* 8B0510 802404A0 03E00008 */  jr        $ra
/* 8B0514 802404A4 27BD0020 */   addiu    $sp, $sp, 0x20
