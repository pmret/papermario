.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411AC_94075C
/* 94075C 802411AC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 940760 802411B0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 940764 802411B4 8C82000C */  lw        $v0, 0xc($a0)
/* 940768 802411B8 0C0B1EAF */  jal       get_variable
/* 94076C 802411BC 8C450000 */   lw       $a1, ($v0)
/* 940770 802411C0 0040182D */  daddu     $v1, $v0, $zero
/* 940774 802411C4 10600012 */  beqz      $v1, .L80241210
/* 940778 802411C8 0000202D */   daddu    $a0, $zero, $zero
/* 94077C 802411CC 8C620000 */  lw        $v0, ($v1)
/* 940780 802411D0 5040000A */  beql      $v0, $zero, .L802411FC
/* 940784 802411D4 00041080 */   sll      $v0, $a0, 2
/* 940788 802411D8 3C058024 */  lui       $a1, %hi(end_battle)
/* 94078C 802411DC 24A54A50 */  addiu     $a1, $a1, %lo(end_battle)
.L802411E0:
/* 940790 802411E0 24630004 */  addiu     $v1, $v1, 4
/* 940794 802411E4 24840001 */  addiu     $a0, $a0, 1
/* 940798 802411E8 ACA20000 */  sw        $v0, ($a1)
/* 94079C 802411EC 8C620000 */  lw        $v0, ($v1)
/* 9407A0 802411F0 1440FFFB */  bnez      $v0, .L802411E0
/* 9407A4 802411F4 24A50004 */   addiu    $a1, $a1, 4
/* 9407A8 802411F8 00041080 */  sll       $v0, $a0, 2
.L802411FC:
/* 9407AC 802411FC 3C018024 */  lui       $at, %hi(end_battle)
/* 9407B0 80241200 00220821 */  addu      $at, $at, $v0
/* 9407B4 80241204 AC204A50 */  sw        $zero, %lo(end_battle)($at)
/* 9407B8 80241208 0809048E */  j         .L80241238
/* 9407BC 8024120C 00000000 */   nop      
.L80241210:
/* 9407C0 80241210 3C038024 */  lui       $v1, %hi(end_battle)
/* 9407C4 80241214 24634A50 */  addiu     $v1, $v1, %lo(end_battle)
/* 9407C8 80241218 0060282D */  daddu     $a1, $v1, $zero
.L8024121C:
/* 9407CC 8024121C 24820010 */  addiu     $v0, $a0, 0x10
/* 9407D0 80241220 AC620000 */  sw        $v0, ($v1)
/* 9407D4 80241224 24630004 */  addiu     $v1, $v1, 4
/* 9407D8 80241228 24840001 */  addiu     $a0, $a0, 1
/* 9407DC 8024122C 28820070 */  slti      $v0, $a0, 0x70
/* 9407E0 80241230 1440FFFA */  bnez      $v0, .L8024121C
/* 9407E4 80241234 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241238:
/* 9407E8 80241238 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9407EC 8024123C 24020002 */  addiu     $v0, $zero, 2
/* 9407F0 80241240 03E00008 */  jr        $ra
/* 9407F4 80241244 27BD0018 */   addiu    $sp, $sp, 0x18
