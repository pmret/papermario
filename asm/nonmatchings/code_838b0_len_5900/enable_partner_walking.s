.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel enable_partner_walking
/* 84D58 800EB8A8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 84D5C 800EB8AC AFB00010 */  sw        $s0, 0x10($sp)
/* 84D60 800EB8B0 0080802D */  daddu     $s0, $a0, $zero
/* 84D64 800EB8B4 3C078011 */  lui       $a3, %hi(gPlayerStatus)
/* 84D68 800EB8B8 24E7EFC8 */  addiu     $a3, $a3, %lo(gPlayerStatus)
/* 84D6C 800EB8BC 3C048011 */  lui       $a0, %hi(D_8010CD38)
/* 84D70 800EB8C0 2484CD38 */  addiu     $a0, $a0, %lo(D_8010CD38)
/* 84D74 800EB8C4 0000302D */  daddu     $a2, $zero, $zero
/* 84D78 800EB8C8 3C018010 */  lui       $at, %hi(D_800F833C)
/* 84D7C 800EB8CC C420833C */  lwc1      $f0, %lo(D_800F833C)($at)
/* 84D80 800EB8D0 3C018010 */  lui       $at, %hi(D_800F8340)
/* 84D84 800EB8D4 C4228340 */  lwc1      $f2, %lo(D_800F8340)($at)
/* 84D88 800EB8D8 3C018010 */  lui       $at, %hi(D_800F8344)
/* 84D8C 800EB8DC C4248344 */  lwc1      $f4, %lo(D_800F8344)($at)
/* 84D90 800EB8E0 2483000C */  addiu     $v1, $a0, 0xc
/* 84D94 800EB8E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 84D98 800EB8E8 E6000038 */  swc1      $f0, 0x38($s0)
/* 84D9C 800EB8EC E602003C */  swc1      $f2, 0x3c($s0)
/* 84DA0 800EB8F0 E6040040 */  swc1      $f4, 0x40($s0)
.L800EB8F4:
/* 84DA4 800EB8F4 C4E00028 */  lwc1      $f0, 0x28($a3)
/* 84DA8 800EB8F8 E460FFF8 */  swc1      $f0, -8($v1)
/* 84DAC 800EB8FC C4E0002C */  lwc1      $f0, 0x2c($a3)
/* 84DB0 800EB900 24C60001 */  addiu     $a2, $a2, 1
/* 84DB4 800EB904 E460FFFC */  swc1      $f0, -4($v1)
/* 84DB8 800EB908 C4E00030 */  lwc1      $f0, 0x30($a3)
/* 84DBC 800EB90C 28C20028 */  slti      $v0, $a2, 0x28
/* 84DC0 800EB910 E4600000 */  swc1      $f0, ($v1)
/* 84DC4 800EB914 24630010 */  addiu     $v1, $v1, 0x10
/* 84DC8 800EB918 A0800000 */  sb        $zero, ($a0)
/* 84DCC 800EB91C 1440FFF5 */  bnez      $v0, .L800EB8F4
/* 84DD0 800EB920 24840010 */   addiu    $a0, $a0, 0x10
/* 84DD4 800EB924 3C038011 */  lui       $v1, %hi(D_8010CFCA)
/* 84DD8 800EB928 2463CFCA */  addiu     $v1, $v1, %lo(D_8010CFCA)
/* 84DDC 800EB92C 3C018011 */  lui       $at, %hi(D_8010CFB8)
/* 84DE0 800EB930 AC20CFB8 */  sw        $zero, %lo(D_8010CFB8)($at)
/* 84DE4 800EB934 3C018011 */  lui       $at, %hi(D_8010CFBC)
/* 84DE8 800EB938 AC20CFBC */  sw        $zero, %lo(D_8010CFBC)($at)
/* 84DEC 800EB93C 10A00003 */  beqz      $a1, .L800EB94C
/* 84DF0 800EB940 24020002 */   addiu    $v0, $zero, 2
/* 84DF4 800EB944 0803AE54 */  j         .L800EB950
/* 84DF8 800EB948 A4620000 */   sh       $v0, ($v1)
.L800EB94C:
/* 84DFC 800EB94C A4600000 */  sh        $zero, ($v1)
.L800EB950:
/* 84E00 800EB950 3C048011 */  lui       $a0, %hi(D_8010CFC8)
/* 84E04 800EB954 2484CFC8 */  addiu     $a0, $a0, %lo(D_8010CFC8)
/* 84E08 800EB958 3C058011 */  lui       $a1, %hi(D_8010CFC4)
/* 84E0C 800EB95C 24A5CFC4 */  addiu     $a1, $a1, %lo(D_8010CFC4)
/* 84E10 800EB960 A4800000 */  sh        $zero, ($a0)
/* 84E14 800EB964 8CA30000 */  lw        $v1, ($a1)
/* 84E18 800EB968 24020001 */  addiu     $v0, $zero, 1
/* 84E1C 800EB96C 10620003 */  beq       $v1, $v0, .L800EB97C
/* 84E20 800EB970 24020003 */   addiu    $v0, $zero, 3
/* 84E24 800EB974 14620006 */  bne       $v1, $v0, .L800EB990
/* 84E28 800EB978 24020002 */   addiu    $v0, $zero, 2
.L800EB97C:
/* 84E2C 800EB97C ACA00000 */  sw        $zero, ($a1)
/* 84E30 800EB980 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 84E34 800EB984 A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
/* 84E38 800EB988 0803AE69 */  j         .L800EB9A4
/* 84E3C 800EB98C A4800000 */   sh       $zero, ($a0)
.L800EB990:
/* 84E40 800EB990 14620004 */  bne       $v1, $v0, .L800EB9A4
/* 84E44 800EB994 24020032 */   addiu    $v0, $zero, 0x32
/* 84E48 800EB998 3C018011 */  lui       $at, %hi(D_8010CFCA)
/* 84E4C 800EB99C A420CFCA */  sh        $zero, %lo(D_8010CFCA)($at)
/* 84E50 800EB9A0 A4820000 */  sh        $v0, ($a0)
.L800EB9A4:
/* 84E54 800EB9A4 3C038011 */  lui       $v1, %hi(D_8010CFD8)
/* 84E58 800EB9A8 8C63CFD8 */  lw        $v1, %lo(D_8010CFD8)($v1)
/* 84E5C 800EB9AC 3C014220 */  lui       $at, 0x4220
/* 84E60 800EB9B0 44810000 */  mtc1      $at, $f0
/* 84E64 800EB9B4 0200202D */  daddu     $a0, $s0, $zero
/* 84E68 800EB9B8 3C018011 */  lui       $at, %hi(D_8010CFCE)
/* 84E6C 800EB9BC A420CFCE */  sh        $zero, %lo(D_8010CFCE)($at)
/* 84E70 800EB9C0 3C018011 */  lui       $at, %hi(D_8010CFCC)
/* 84E74 800EB9C4 A420CFCC */  sh        $zero, %lo(D_8010CFCC)($at)
/* 84E78 800EB9C8 000310C0 */  sll       $v0, $v1, 3
/* 84E7C 800EB9CC 00431021 */  addu      $v0, $v0, $v1
/* 84E80 800EB9D0 00021080 */  sll       $v0, $v0, 2
/* 84E84 800EB9D4 3C038010 */  lui       $v1, %hi(gPartnerAnimations+0x14)
/* 84E88 800EB9D8 00621821 */  addu      $v1, $v1, $v0
/* 84E8C 800EB9DC 8C63835C */  lw        $v1, %lo(gPartnerAnimations+0x14)($v1)
/* 84E90 800EB9E0 24020010 */  addiu     $v0, $zero, 0x10
/* 84E94 800EB9E4 3C018010 */  lui       $at, %hi(D_800F802C)
/* 84E98 800EB9E8 AC22802C */  sw        $v0, %lo(D_800F802C)($at)
/* 84E9C 800EB9EC 3C018011 */  lui       $at, %hi(D_8010CFC0)
/* 84EA0 800EB9F0 E420CFC0 */  swc1      $f0, %lo(D_8010CFC0)($at)
/* 84EA4 800EB9F4 0C03A96E */  jal       func_800EA5B8
/* 84EA8 800EB9F8 AE030028 */   sw       $v1, 0x28($s0)
/* 84EAC 800EB9FC 3C030040 */  lui       $v1, 0x40
/* 84EB0 800EBA00 3C020001 */  lui       $v0, 1
/* 84EB4 800EBA04 AE020080 */  sw        $v0, 0x80($s0)
/* 84EB8 800EBA08 8E020000 */  lw        $v0, ($s0)
/* 84EBC 800EBA0C 3C013FE6 */  lui       $at, 0x3fe6
/* 84EC0 800EBA10 34216666 */  ori       $at, $at, 0x6666
/* 84EC4 800EBA14 44810000 */  mtc1      $at, $f0
/* 84EC8 800EBA18 34630300 */  ori       $v1, $v1, 0x300
/* 84ECC 800EBA1C AE00001C */  sw        $zero, 0x1c($s0)
/* 84ED0 800EBA20 00431025 */  or        $v0, $v0, $v1
/* 84ED4 800EBA24 AE020000 */  sw        $v0, ($s0)
/* 84ED8 800EBA28 E6000014 */  swc1      $f0, 0x14($s0)
/* 84EDC 800EBA2C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 84EE0 800EBA30 8FB00010 */  lw        $s0, 0x10($sp)
/* 84EE4 800EBA34 03E00008 */  jr        $ra
/* 84EE8 800EBA38 27BD0018 */   addiu    $sp, $sp, 0x18
