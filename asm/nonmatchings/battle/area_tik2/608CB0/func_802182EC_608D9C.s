.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802182EC_608D9C
/* 608D9C 802182EC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 608DA0 802182F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 608DA4 802182F4 0080802D */  daddu     $s0, $a0, $zero
/* 608DA8 802182F8 10A0000E */  beqz      $a1, .L80218334
/* 608DAC 802182FC AFBF0014 */   sw       $ra, 0x14($sp)
/* 608DB0 80218300 0C04760B */  jal       func_8011D82C
/* 608DB4 80218304 24040001 */   addiu    $a0, $zero, 1
/* 608DB8 80218308 0000202D */  daddu     $a0, $zero, $zero
/* 608DBC 8021830C 0080282D */  daddu     $a1, $a0, $zero
/* 608DC0 80218310 0080302D */  daddu     $a2, $a0, $zero
/* 608DC4 80218314 0080382D */  daddu     $a3, $a0, $zero
/* 608DC8 80218318 3C028015 */  lui       $v0, %hi(D_801512F0)
/* 608DCC 8021831C 8C4212F0 */  lw        $v0, %lo(D_801512F0)($v0)
/* 608DD0 80218320 24030001 */  addiu     $v1, $zero, 1
/* 608DD4 80218324 0C046F97 */  jal       set_background_color_blend
/* 608DD8 80218328 A0430000 */   sb       $v1, ($v0)
/* 608DDC 8021832C 24020014 */  addiu     $v0, $zero, 0x14
/* 608DE0 80218330 AE020070 */  sw        $v0, 0x70($s0)
.L80218334:
/* 608DE4 80218334 0000202D */  daddu     $a0, $zero, $zero
/* 608DE8 80218338 0080282D */  daddu     $a1, $a0, $zero
/* 608DEC 8021833C 0080302D */  daddu     $a2, $a0, $zero
/* 608DF0 80218340 8E030070 */  lw        $v1, 0x70($s0)
/* 608DF4 80218344 24020014 */  addiu     $v0, $zero, 0x14
/* 608DF8 80218348 00431023 */  subu      $v0, $v0, $v1
/* 608DFC 8021834C 00023880 */  sll       $a3, $v0, 2
/* 608E00 80218350 00E23821 */  addu      $a3, $a3, $v0
/* 608E04 80218354 00073840 */  sll       $a3, $a3, 1
/* 608E08 80218358 0C046F97 */  jal       set_background_color_blend
/* 608E0C 8021835C 30E700FE */   andi     $a3, $a3, 0xfe
/* 608E10 80218360 8E020070 */  lw        $v0, 0x70($s0)
/* 608E14 80218364 2442FFFF */  addiu     $v0, $v0, -1
/* 608E18 80218368 AE020070 */  sw        $v0, 0x70($s0)
/* 608E1C 8021836C 2C420001 */  sltiu     $v0, $v0, 1
/* 608E20 80218370 8FBF0014 */  lw        $ra, 0x14($sp)
/* 608E24 80218374 8FB00010 */  lw        $s0, 0x10($sp)
/* 608E28 80218378 00021040 */  sll       $v0, $v0, 1
/* 608E2C 8021837C 03E00008 */  jr        $ra
/* 608E30 80218380 27BD0018 */   addiu    $sp, $sp, 0x18
