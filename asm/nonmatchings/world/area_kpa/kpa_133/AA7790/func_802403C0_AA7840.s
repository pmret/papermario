.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403C0_AA7840
/* AA7840 802403C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* AA7844 802403C4 AFB20018 */  sw        $s2, 0x18($sp)
/* AA7848 802403C8 0080902D */  daddu     $s2, $a0, $zero
/* AA784C 802403CC 0000202D */  daddu     $a0, $zero, $zero
/* AA7850 802403D0 3C05FD05 */  lui       $a1, 0xfd05
/* AA7854 802403D4 AFBF001C */  sw        $ra, 0x1c($sp)
/* AA7858 802403D8 AFB10014 */  sw        $s1, 0x14($sp)
/* AA785C 802403DC AFB00010 */  sw        $s0, 0x10($sp)
/* AA7860 802403E0 8E50000C */  lw        $s0, 0xc($s2)
/* AA7864 802403E4 0C0B1EAF */  jal       get_variable
/* AA7868 802403E8 34A50F80 */   ori      $a1, $a1, 0xf80
/* AA786C 802403EC 0C04417A */  jal       get_entity_by_index
/* AA7870 802403F0 0040202D */   daddu    $a0, $v0, $zero
/* AA7874 802403F4 0240202D */  daddu     $a0, $s2, $zero
/* AA7878 802403F8 0040882D */  daddu     $s1, $v0, $zero
/* AA787C 802403FC 8E050000 */  lw        $a1, ($s0)
/* AA7880 80240400 0C0B1EAF */  jal       get_variable
/* AA7884 80240404 26100004 */   addiu    $s0, $s0, 4
/* AA7888 80240408 44820000 */  mtc1      $v0, $f0
/* AA788C 8024040C 00000000 */  nop
/* AA7890 80240410 46800020 */  cvt.s.w   $f0, $f0
/* AA7894 80240414 E6200048 */  swc1      $f0, 0x48($s1)
/* AA7898 80240418 8E050000 */  lw        $a1, ($s0)
/* AA789C 8024041C 26100004 */  addiu     $s0, $s0, 4
/* AA78A0 80240420 0C0B1EAF */  jal       get_variable
/* AA78A4 80240424 0240202D */   daddu    $a0, $s2, $zero
/* AA78A8 80240428 44820000 */  mtc1      $v0, $f0
/* AA78AC 8024042C 00000000 */  nop
/* AA78B0 80240430 46800020 */  cvt.s.w   $f0, $f0
/* AA78B4 80240434 E620004C */  swc1      $f0, 0x4c($s1)
/* AA78B8 80240438 8E050000 */  lw        $a1, ($s0)
/* AA78BC 8024043C 0C0B1EAF */  jal       get_variable
/* AA78C0 80240440 0240202D */   daddu    $a0, $s2, $zero
/* AA78C4 80240444 44820000 */  mtc1      $v0, $f0
/* AA78C8 80240448 00000000 */  nop
/* AA78CC 8024044C 46800020 */  cvt.s.w   $f0, $f0
/* AA78D0 80240450 E6200050 */  swc1      $f0, 0x50($s1)
/* AA78D4 80240454 8FBF001C */  lw        $ra, 0x1c($sp)
/* AA78D8 80240458 8FB20018 */  lw        $s2, 0x18($sp)
/* AA78DC 8024045C 8FB10014 */  lw        $s1, 0x14($sp)
/* AA78E0 80240460 8FB00010 */  lw        $s0, 0x10($sp)
/* AA78E4 80240464 24020002 */  addiu     $v0, $zero, 2
/* AA78E8 80240468 03E00008 */  jr        $ra
/* AA78EC 8024046C 27BD0020 */   addiu    $sp, $sp, 0x20
