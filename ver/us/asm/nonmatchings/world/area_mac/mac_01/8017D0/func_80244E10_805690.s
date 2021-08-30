.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80244E10_805690
/* 805690 80244E10 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 805694 80244E14 AFB00010 */  sw        $s0, 0x10($sp)
/* 805698 80244E18 0080802D */  daddu     $s0, $a0, $zero
/* 80569C 80244E1C AFBF0014 */  sw        $ra, 0x14($sp)
/* 8056A0 80244E20 8E02000C */  lw        $v0, 0xc($s0)
/* 8056A4 80244E24 0C0B1EAF */  jal       evt_get_variable
/* 8056A8 80244E28 8C450000 */   lw       $a1, ($v0)
/* 8056AC 80244E2C C6000084 */  lwc1      $f0, 0x84($s0)
/* 8056B0 80244E30 46800020 */  cvt.s.w   $f0, $f0
/* 8056B4 80244E34 00021100 */  sll       $v0, $v0, 4
/* 8056B8 80244E38 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 8056BC 80244E3C 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 8056C0 80244E40 44050000 */  mfc1      $a1, $f0
/* 8056C4 80244E44 C6000088 */  lwc1      $f0, 0x88($s0)
/* 8056C8 80244E48 46800020 */  cvt.s.w   $f0, $f0
/* 8056CC 80244E4C 8C630140 */  lw        $v1, 0x140($v1)
/* 8056D0 80244E50 44060000 */  mfc1      $a2, $f0
/* 8056D4 80244E54 00431021 */  addu      $v0, $v0, $v1
/* 8056D8 80244E58 8E03008C */  lw        $v1, 0x8c($s0)
/* 8056DC 80244E5C 8C440000 */  lw        $a0, ($v0)
/* 8056E0 80244E60 24630006 */  addiu     $v1, $v1, 6
/* 8056E4 80244E64 44830000 */  mtc1      $v1, $f0
/* 8056E8 80244E68 00000000 */  nop
/* 8056EC 80244E6C 46800020 */  cvt.s.w   $f0, $f0
/* 8056F0 80244E70 44070000 */  mfc1      $a3, $f0
/* 8056F4 80244E74 0C04D083 */  jal       set_item_entity_position
/* 8056F8 80244E78 00000000 */   nop
/* 8056FC 80244E7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 805700 80244E80 8FB00010 */  lw        $s0, 0x10($sp)
/* 805704 80244E84 24020002 */  addiu     $v0, $zero, 2
/* 805708 80244E88 03E00008 */  jr        $ra
/* 80570C 80244E8C 27BD0018 */   addiu    $sp, $sp, 0x18
