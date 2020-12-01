.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024EF08
/* 17D7E8 8024EF08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 17D7EC 8024EF0C AFB10014 */  sw        $s1, 0x14($sp)
/* 17D7F0 8024EF10 0000882D */  daddu     $s1, $zero, $zero
/* 17D7F4 8024EF14 AFB00010 */  sw        $s0, 0x10($sp)
/* 17D7F8 8024EF18 3C10802A */  lui       $s0, %hi(D_8029F2C0)
/* 17D7FC 8024EF1C 2610F2C0 */  addiu     $s0, $s0, %lo(D_8029F2C0)
/* 17D800 8024EF20 AFBF0018 */  sw        $ra, 0x18($sp)
.L8024EF24:
/* 17D804 8024EF24 86020010 */  lh        $v0, 0x10($s0)
/* 17D808 8024EF28 50400007 */  beql      $v0, $zero, .L8024EF48
/* 17D80C 8024EF2C 26310001 */   addiu    $s1, $s1, 1
/* 17D810 8024EF30 8E02000C */  lw        $v0, 0xc($s0)
/* 17D814 8024EF34 50400004 */  beql      $v0, $zero, .L8024EF48
/* 17D818 8024EF38 26310001 */   addiu    $s1, $s1, 1
/* 17D81C 8024EF3C 0040F809 */  jalr      $v0
/* 17D820 8024EF40 0200202D */   daddu    $a0, $s0, $zero
/* 17D824 8024EF44 26310001 */  addiu     $s1, $s1, 1
.L8024EF48:
/* 17D828 8024EF48 2A220020 */  slti      $v0, $s1, 0x20
/* 17D82C 8024EF4C 1440FFF5 */  bnez      $v0, .L8024EF24
/* 17D830 8024EF50 2610001C */   addiu    $s0, $s0, 0x1c
/* 17D834 8024EF54 8FBF0018 */  lw        $ra, 0x18($sp)
/* 17D838 8024EF58 8FB10014 */  lw        $s1, 0x14($sp)
/* 17D83C 8024EF5C 8FB00010 */  lw        $s0, 0x10($sp)
/* 17D840 8024EF60 03E00008 */  jr        $ra
/* 17D844 8024EF64 27BD0020 */   addiu    $sp, $sp, 0x20
