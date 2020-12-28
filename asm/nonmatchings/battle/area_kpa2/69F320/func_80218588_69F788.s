.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218588_69F788
/* 69F788 80218588 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 69F78C 8021858C AFB00010 */  sw        $s0, 0x10($sp)
/* 69F790 80218590 0080802D */  daddu     $s0, $a0, $zero
/* 69F794 80218594 10A0000E */  beqz      $a1, .L802185D0
/* 69F798 80218598 AFBF0014 */   sw       $ra, 0x14($sp)
/* 69F79C 8021859C 0C04760B */  jal       func_8011D82C
/* 69F7A0 802185A0 24040001 */   addiu    $a0, $zero, 1
/* 69F7A4 802185A4 0000202D */  daddu     $a0, $zero, $zero
/* 69F7A8 802185A8 0080282D */  daddu     $a1, $a0, $zero
/* 69F7AC 802185AC 0080302D */  daddu     $a2, $a0, $zero
/* 69F7B0 802185B0 0080382D */  daddu     $a3, $a0, $zero
/* 69F7B4 802185B4 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 69F7B8 802185B8 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 69F7BC 802185BC 24030001 */  addiu     $v1, $zero, 1
/* 69F7C0 802185C0 0C046F97 */  jal       set_background_color_blend
/* 69F7C4 802185C4 A0430000 */   sb       $v1, ($v0)
/* 69F7C8 802185C8 24020014 */  addiu     $v0, $zero, 0x14
/* 69F7CC 802185CC AE020070 */  sw        $v0, 0x70($s0)
.L802185D0:
/* 69F7D0 802185D0 0000202D */  daddu     $a0, $zero, $zero
/* 69F7D4 802185D4 0080282D */  daddu     $a1, $a0, $zero
/* 69F7D8 802185D8 0080302D */  daddu     $a2, $a0, $zero
/* 69F7DC 802185DC 8E030070 */  lw        $v1, 0x70($s0)
/* 69F7E0 802185E0 24020014 */  addiu     $v0, $zero, 0x14
/* 69F7E4 802185E4 00431023 */  subu      $v0, $v0, $v1
/* 69F7E8 802185E8 00023880 */  sll       $a3, $v0, 2
/* 69F7EC 802185EC 00E23821 */  addu      $a3, $a3, $v0
/* 69F7F0 802185F0 00073840 */  sll       $a3, $a3, 1
/* 69F7F4 802185F4 0C046F97 */  jal       set_background_color_blend
/* 69F7F8 802185F8 30E700FE */   andi     $a3, $a3, 0xfe
/* 69F7FC 802185FC 8E020070 */  lw        $v0, 0x70($s0)
/* 69F800 80218600 2442FFFF */  addiu     $v0, $v0, -1
/* 69F804 80218604 AE020070 */  sw        $v0, 0x70($s0)
/* 69F808 80218608 2C420001 */  sltiu     $v0, $v0, 1
/* 69F80C 8021860C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 69F810 80218610 8FB00010 */  lw        $s0, 0x10($sp)
/* 69F814 80218614 00021040 */  sll       $v0, $v0, 1
/* 69F818 80218618 03E00008 */  jr        $ra
/* 69F81C 8021861C 27BD0018 */   addiu    $sp, $sp, 0x18
