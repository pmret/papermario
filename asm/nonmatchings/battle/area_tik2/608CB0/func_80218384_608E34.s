.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218384_608E34
/* 608E34 80218384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 608E38 80218388 AFB00010 */  sw        $s0, 0x10($sp)
/* 608E3C 8021838C 0080802D */  daddu     $s0, $a0, $zero
/* 608E40 80218390 10A00003 */  beqz      $a1, .L802183A0
/* 608E44 80218394 AFBF0014 */   sw       $ra, 0x14($sp)
/* 608E48 80218398 24020014 */  addiu     $v0, $zero, 0x14
/* 608E4C 8021839C AE020070 */  sw        $v0, 0x70($s0)
.L802183A0:
/* 608E50 802183A0 0000202D */  daddu     $a0, $zero, $zero
/* 608E54 802183A4 0080282D */  daddu     $a1, $a0, $zero
/* 608E58 802183A8 8E020070 */  lw        $v0, 0x70($s0)
/* 608E5C 802183AC 0080302D */  daddu     $a2, $a0, $zero
/* 608E60 802183B0 00023880 */  sll       $a3, $v0, 2
/* 608E64 802183B4 00E23821 */  addu      $a3, $a3, $v0
/* 608E68 802183B8 00073840 */  sll       $a3, $a3, 1
/* 608E6C 802183BC 0C046F97 */  jal       set_background_color_blend
/* 608E70 802183C0 30E700FE */   andi     $a3, $a3, 0xfe
/* 608E74 802183C4 8E020070 */  lw        $v0, 0x70($s0)
/* 608E78 802183C8 2442FFFF */  addiu     $v0, $v0, -1
/* 608E7C 802183CC 10400003 */  beqz      $v0, .L802183DC
/* 608E80 802183D0 AE020070 */   sw       $v0, 0x70($s0)
/* 608E84 802183D4 080860FD */  j         .L802183F4
/* 608E88 802183D8 0000102D */   daddu    $v0, $zero, $zero
.L802183DC:
/* 608E8C 802183DC 0000202D */  daddu     $a0, $zero, $zero
/* 608E90 802183E0 0080282D */  daddu     $a1, $a0, $zero
/* 608E94 802183E4 0080302D */  daddu     $a2, $a0, $zero
/* 608E98 802183E8 0C046F97 */  jal       set_background_color_blend
/* 608E9C 802183EC 0080382D */   daddu    $a3, $a0, $zero
/* 608EA0 802183F0 24020002 */  addiu     $v0, $zero, 2
.L802183F4:
/* 608EA4 802183F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 608EA8 802183F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 608EAC 802183FC 03E00008 */  jr        $ra
/* 608EB0 80218400 27BD0018 */   addiu    $sp, $sp, 0x18
