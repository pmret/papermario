.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802409A8
/* 92AC58 802409A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 92AC5C 802409AC AFBF0010 */  sw        $ra, 0x10($sp)
/* 92AC60 802409B0 8C82000C */  lw        $v0, 0xc($a0)
/* 92AC64 802409B4 0C0B1EAF */  jal       get_variable
/* 92AC68 802409B8 8C450000 */   lw       $a1, ($v0)
/* 92AC6C 802409BC 0040182D */  daddu     $v1, $v0, $zero
/* 92AC70 802409C0 10600012 */  beqz      $v1, .L80240A0C
/* 92AC74 802409C4 0000202D */   daddu    $a0, $zero, $zero
/* 92AC78 802409C8 8C620000 */  lw        $v0, ($v1)
/* 92AC7C 802409CC 5040000A */  beql      $v0, $zero, .L802409F8
/* 92AC80 802409D0 00041080 */   sll      $v0, $a0, 2
/* 92AC84 802409D4 3C058024 */  lui       $a1, 0x8024
/* 92AC88 802409D8 24A55630 */  addiu     $a1, $a1, 0x5630
.L802409DC:
/* 92AC8C 802409DC 24630004 */  addiu     $v1, $v1, 4
/* 92AC90 802409E0 24840001 */  addiu     $a0, $a0, 1
/* 92AC94 802409E4 ACA20000 */  sw        $v0, ($a1)
/* 92AC98 802409E8 8C620000 */  lw        $v0, ($v1)
/* 92AC9C 802409EC 1440FFFB */  bnez      $v0, .L802409DC
/* 92ACA0 802409F0 24A50004 */   addiu    $a1, $a1, 4
/* 92ACA4 802409F4 00041080 */  sll       $v0, $a0, 2
.L802409F8:
/* 92ACA8 802409F8 3C018024 */  lui       $at, 0x8024
/* 92ACAC 802409FC 00220821 */  addu      $at, $at, $v0
/* 92ACB0 80240A00 AC205630 */  sw        $zero, 0x5630($at)
/* 92ACB4 80240A04 0809028D */  j         .L80240A34
/* 92ACB8 80240A08 00000000 */   nop      
.L80240A0C:
/* 92ACBC 80240A0C 3C038024 */  lui       $v1, 0x8024
/* 92ACC0 80240A10 24635630 */  addiu     $v1, $v1, 0x5630
/* 92ACC4 80240A14 0060282D */  daddu     $a1, $v1, $zero
.L80240A18:
/* 92ACC8 80240A18 24820080 */  addiu     $v0, $a0, 0x80
/* 92ACCC 80240A1C AC620000 */  sw        $v0, ($v1)
/* 92ACD0 80240A20 24630004 */  addiu     $v1, $v1, 4
/* 92ACD4 80240A24 24840001 */  addiu     $a0, $a0, 1
/* 92ACD8 80240A28 2882005B */  slti      $v0, $a0, 0x5b
/* 92ACDC 80240A2C 1440FFFA */  bnez      $v0, .L80240A18
/* 92ACE0 80240A30 ACA0016C */   sw       $zero, 0x16c($a1)
.L80240A34:
/* 92ACE4 80240A34 8FBF0010 */  lw        $ra, 0x10($sp)
/* 92ACE8 80240A38 24020002 */  addiu     $v0, $zero, 2
/* 92ACEC 80240A3C 03E00008 */  jr        $ra
/* 92ACF0 80240A40 27BD0018 */   addiu    $sp, $sp, 0x18
