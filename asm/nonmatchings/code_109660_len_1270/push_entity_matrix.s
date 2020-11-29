.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel push_entity_matrix
/* 10A6CC 802E8E4C 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 10A6D0 802E8E50 AFB3009C */  sw        $s3, 0x9c($sp)
/* 10A6D4 802E8E54 3C13800A */  lui       $s3, %hi(D_8009A66C)
/* 10A6D8 802E8E58 2673A66C */  addiu     $s3, $s3, %lo(D_8009A66C)
/* 10A6DC 802E8E5C AFBF00A4 */  sw        $ra, 0xa4($sp)
/* 10A6E0 802E8E60 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 10A6E4 802E8E64 AFB20098 */  sw        $s2, 0x98($sp)
/* 10A6E8 802E8E68 AFB10094 */  sw        $s1, 0x94($sp)
/* 10A6EC 802E8E6C AFB00090 */  sw        $s0, 0x90($sp)
/* 10A6F0 802E8E70 8E710000 */  lw        $s1, ($s3)
/* 10A6F4 802E8E74 0C04417A */  jal       get_entity_by_index
/* 10A6F8 802E8E78 3C140001 */   lui      $s4, 1
/* 10A6FC 802E8E7C 27A40010 */  addiu     $a0, $sp, 0x10
/* 10A700 802E8E80 0040802D */  daddu     $s0, $v0, $zero
/* 10A704 802E8E84 8E050054 */  lw        $a1, 0x54($s0)
/* 10A708 802E8E88 8E060058 */  lw        $a2, 0x58($s0)
/* 10A70C 802E8E8C 8E07005C */  lw        $a3, 0x5c($s0)
/* 10A710 802E8E90 8E120040 */  lw        $s2, 0x40($s0)
/* 10A714 802E8E94 0C019DF0 */  jal       guScaleF
/* 10A718 802E8E98 36941630 */   ori      $s4, $s4, 0x1630
/* 10A71C 802E8E9C C6420018 */  lwc1      $f2, 0x18($s2)
/* 10A720 802E8EA0 3C013F80 */  lui       $at, 0x3f80
/* 10A724 802E8EA4 44810000 */  mtc1      $at, $f0
/* 10A728 802E8EA8 8E050048 */  lw        $a1, 0x48($s0)
/* 10A72C 802E8EAC 46001080 */  add.s     $f2, $f2, $f0
/* 10A730 802E8EB0 8E070050 */  lw        $a3, 0x50($s0)
/* 10A734 802E8EB4 27B00050 */  addiu     $s0, $sp, 0x50
/* 10A738 802E8EB8 44061000 */  mfc1      $a2, $f2
/* 10A73C 802E8EBC 0C019E40 */  jal       guTranslateF
/* 10A740 802E8EC0 0200202D */   daddu    $a0, $s0, $zero
/* 10A744 802E8EC4 27A40010 */  addiu     $a0, $sp, 0x10
/* 10A748 802E8EC8 0200282D */  daddu     $a1, $s0, $zero
/* 10A74C 802E8ECC 0C019D80 */  jal       guMtxCatF
/* 10A750 802E8ED0 0200302D */   daddu    $a2, $s0, $zero
/* 10A754 802E8ED4 0200202D */  daddu     $a0, $s0, $zero
/* 10A758 802E8ED8 3C108007 */  lui       $s0, %hi(D_800741F0)
/* 10A75C 802E8EDC 261041F0 */  addiu     $s0, $s0, %lo(D_800741F0)
/* 10A760 802E8EE0 3C12800A */  lui       $s2, %hi(D_8009A674)
/* 10A764 802E8EE4 2652A674 */  addiu     $s2, $s2, %lo(D_8009A674)
/* 10A768 802E8EE8 96050000 */  lhu       $a1, ($s0)
/* 10A76C 802E8EEC 8E420000 */  lw        $v0, ($s2)
/* 10A770 802E8EF0 00052980 */  sll       $a1, $a1, 6
/* 10A774 802E8EF4 00B42821 */  addu      $a1, $a1, $s4
/* 10A778 802E8EF8 0C019D40 */  jal       guMtxF2L
/* 10A77C 802E8EFC 00452821 */   addu     $a1, $v0, $a1
/* 10A780 802E8F00 0220202D */  daddu     $a0, $s1, $zero
/* 10A784 802E8F04 26310008 */  addiu     $s1, $s1, 8
/* 10A788 802E8F08 3C03DA38 */  lui       $v1, 0xda38
/* 10A78C 802E8F0C 34630002 */  ori       $v1, $v1, 2
/* 10A790 802E8F10 0220282D */  daddu     $a1, $s1, $zero
/* 10A794 802E8F14 26310008 */  addiu     $s1, $s1, 8
/* 10A798 802E8F18 0220302D */  daddu     $a2, $s1, $zero
/* 10A79C 802E8F1C 26310008 */  addiu     $s1, $s1, 8
/* 10A7A0 802E8F20 3C07D838 */  lui       $a3, 0xd838
/* 10A7A4 802E8F24 96020000 */  lhu       $v0, ($s0)
/* 10A7A8 802E8F28 34E70002 */  ori       $a3, $a3, 2
/* 10A7AC 802E8F2C AC830000 */  sw        $v1, ($a0)
/* 10A7B0 802E8F30 AE710000 */  sw        $s1, ($s3)
/* 10A7B4 802E8F34 24430001 */  addiu     $v1, $v0, 1
/* 10A7B8 802E8F38 3042FFFF */  andi      $v0, $v0, 0xffff
/* 10A7BC 802E8F3C 00021180 */  sll       $v0, $v0, 6
/* 10A7C0 802E8F40 A6030000 */  sh        $v1, ($s0)
/* 10A7C4 802E8F44 8E430000 */  lw        $v1, ($s2)
/* 10A7C8 802E8F48 00541021 */  addu      $v0, $v0, $s4
/* 10A7CC 802E8F4C 00621821 */  addu      $v1, $v1, $v0
/* 10A7D0 802E8F50 3C02DE00 */  lui       $v0, %hi(D_DE000680)
/* 10A7D4 802E8F54 AC830004 */  sw        $v1, 4($a0)
/* 10A7D8 802E8F58 ACA20000 */  sw        $v0, ($a1)
/* 10A7DC 802E8F5C 3C020A00 */  lui       $v0, 0xa00
/* 10A7E0 802E8F60 24420680 */  addiu     $v0, $v0, %lo(D_DE000680)
/* 10A7E4 802E8F64 ACA20004 */  sw        $v0, 4($a1)
/* 10A7E8 802E8F68 24020040 */  addiu     $v0, $zero, 0x40
/* 10A7EC 802E8F6C ACC70000 */  sw        $a3, ($a2)
/* 10A7F0 802E8F70 ACC20004 */  sw        $v0, 4($a2)
/* 10A7F4 802E8F74 8FBF00A4 */  lw        $ra, 0xa4($sp)
/* 10A7F8 802E8F78 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 10A7FC 802E8F7C 8FB3009C */  lw        $s3, 0x9c($sp)
/* 10A800 802E8F80 8FB20098 */  lw        $s2, 0x98($sp)
/* 10A804 802E8F84 8FB10094 */  lw        $s1, 0x94($sp)
/* 10A808 802E8F88 8FB00090 */  lw        $s0, 0x90($sp)
/* 10A80C 802E8F8C 03E00008 */  jr        $ra
/* 10A810 802E8F90 27BD00A8 */   addiu    $sp, $sp, 0xa8
