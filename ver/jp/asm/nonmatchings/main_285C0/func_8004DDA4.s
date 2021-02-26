.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DDA4
/* 291A4 8004DDA4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 291A8 8004DDA8 AFB10014 */  sw        $s1, 0x14($sp)
/* 291AC 8004DDAC 0080882D */  daddu     $s1, $a0, $zero
/* 291B0 8004DDB0 AFBF0018 */  sw        $ra, 0x18($sp)
/* 291B4 8004DDB4 AFB00010 */  sw        $s0, 0x10($sp)
/* 291B8 8004DDB8 8E240000 */  lw        $a0, ($s1)
/* 291BC 8004DDBC 1080000B */  beqz      $a0, .L8004DDEC
/* 291C0 8004DDC0 0000802D */   daddu    $s0, $zero, $zero
/* 291C4 8004DDC4 0C013511 */  jal       func_8004D444
/* 291C8 8004DDC8 00000000 */   nop
/* 291CC 8004DDCC 50400008 */  beql      $v0, $zero, .L8004DDF0
/* 291D0 8004DDD0 24100002 */   addiu    $s0, $zero, 2
/* 291D4 8004DDD4 8E250004 */  lw        $a1, 4($s1)
/* 291D8 8004DDD8 8E26000C */  lw        $a2, 0xc($s1)
/* 291DC 8004DDDC 0C014DED */  jal       func_800537B4
/* 291E0 8004DDE0 2444002C */   addiu    $a0, $v0, 0x2c
/* 291E4 8004DDE4 0801377D */  j         .L8004DDF4
/* 291E8 8004DDE8 0200102D */   daddu    $v0, $s0, $zero
.L8004DDEC:
/* 291EC 8004DDEC 24100003 */  addiu     $s0, $zero, 3
.L8004DDF0:
/* 291F0 8004DDF0 0200102D */  daddu     $v0, $s0, $zero
.L8004DDF4:
/* 291F4 8004DDF4 8FBF0018 */  lw        $ra, 0x18($sp)
/* 291F8 8004DDF8 8FB10014 */  lw        $s1, 0x14($sp)
/* 291FC 8004DDFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 29200 8004DE00 03E00008 */  jr        $ra
/* 29204 8004DE04 27BD0020 */   addiu    $sp, $sp, 0x20
