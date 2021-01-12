.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D18_C70048
/* C70048 80241D18 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C7004C 80241D1C AFB3001C */  sw        $s3, 0x1c($sp)
/* C70050 80241D20 0080982D */  daddu     $s3, $a0, $zero
/* C70054 80241D24 AFBF0020 */  sw        $ra, 0x20($sp)
/* C70058 80241D28 AFB20018 */  sw        $s2, 0x18($sp)
/* C7005C 80241D2C AFB10014 */  sw        $s1, 0x14($sp)
/* C70060 80241D30 AFB00010 */  sw        $s0, 0x10($sp)
/* C70064 80241D34 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C70068 80241D38 8E710148 */  lw        $s1, 0x148($s3)
/* C7006C 80241D3C 86240008 */  lh        $a0, 8($s1)
/* C70070 80241D40 0C00EABB */  jal       get_npc_unsafe
/* C70074 80241D44 00A0802D */   daddu    $s0, $a1, $zero
/* C70078 80241D48 8E040020 */  lw        $a0, 0x20($s0)
/* C7007C 80241D4C 0040902D */  daddu     $s2, $v0, $zero
/* C70080 80241D50 00041FC2 */  srl       $v1, $a0, 0x1f
/* C70084 80241D54 00832021 */  addu      $a0, $a0, $v1
/* C70088 80241D58 00042043 */  sra       $a0, $a0, 1
/* C7008C 80241D5C 0C00A67F */  jal       rand_int
/* C70090 80241D60 24840001 */   addiu    $a0, $a0, 1
/* C70094 80241D64 8E030020 */  lw        $v1, 0x20($s0)
/* C70098 80241D68 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C7009C 80241D6C 000327C2 */  srl       $a0, $v1, 0x1f
/* C700A0 80241D70 00641821 */  addu      $v1, $v1, $a0
/* C700A4 80241D74 00031843 */  sra       $v1, $v1, 1
/* C700A8 80241D78 00621821 */  addu      $v1, $v1, $v0
/* C700AC 80241D7C A643008E */  sh        $v1, 0x8e($s2)
/* C700B0 80241D80 8E2200CC */  lw        $v0, 0xcc($s1)
/* C700B4 80241D84 C64E0040 */  lwc1      $f14, 0x40($s2)
/* C700B8 80241D88 8C42000C */  lw        $v0, 0xc($v0)
/* C700BC 80241D8C AE420028 */  sw        $v0, 0x28($s2)
/* C700C0 80241D90 C6000018 */  lwc1      $f0, 0x18($s0)
/* C700C4 80241D94 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C700C8 80241D98 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C700CC 80241D9C E6400018 */  swc1      $f0, 0x18($s2)
/* C700D0 80241DA0 8C460028 */  lw        $a2, 0x28($v0)
/* C700D4 80241DA4 0C00A720 */  jal       atan2
/* C700D8 80241DA8 8C470030 */   lw       $a3, 0x30($v0)
/* C700DC 80241DAC 46000506 */  mov.s     $f20, $f0
/* C700E0 80241DB0 C64C000C */  lwc1      $f12, 0xc($s2)
/* C700E4 80241DB4 0C00A70A */  jal       get_clamped_angle_diff
/* C700E8 80241DB8 4600A386 */   mov.s    $f14, $f20
/* C700EC 80241DBC 46000086 */  mov.s     $f2, $f0
/* C700F0 80241DC0 8E02001C */  lw        $v0, 0x1c($s0)
/* C700F4 80241DC4 46001005 */  abs.s     $f0, $f2
/* C700F8 80241DC8 44822000 */  mtc1      $v0, $f4
/* C700FC 80241DCC 00000000 */  nop
/* C70100 80241DD0 46802120 */  cvt.s.w   $f4, $f4
/* C70104 80241DD4 4600203C */  c.lt.s    $f4, $f0
/* C70108 80241DD8 00000000 */  nop
/* C7010C 80241DDC 4500000D */  bc1f      .L80241E14
/* C70110 80241DE0 00000000 */   nop
/* C70114 80241DE4 44800000 */  mtc1      $zero, $f0
/* C70118 80241DE8 C654000C */  lwc1      $f20, 0xc($s2)
/* C7011C 80241DEC 4600103C */  c.lt.s    $f2, $f0
/* C70120 80241DF0 00000000 */  nop
/* C70124 80241DF4 45000006 */  bc1f      .L80241E10
/* C70128 80241DF8 00021023 */   negu     $v0, $v0
/* C7012C 80241DFC 44820000 */  mtc1      $v0, $f0
/* C70130 80241E00 00000000 */  nop
/* C70134 80241E04 46800020 */  cvt.s.w   $f0, $f0
/* C70138 80241E08 08090785 */  j         .L80241E14
/* C7013C 80241E0C 4600A500 */   add.s    $f20, $f20, $f0
.L80241E10:
/* C70140 80241E10 4604A500 */  add.s     $f20, $f20, $f4
.L80241E14:
/* C70144 80241E14 0C00A6C9 */  jal       clamp_angle
/* C70148 80241E18 4600A306 */   mov.s    $f12, $f20
/* C7014C 80241E1C 2402000D */  addiu     $v0, $zero, 0xd
/* C70150 80241E20 E640000C */  swc1      $f0, 0xc($s2)
/* C70154 80241E24 AE620070 */  sw        $v0, 0x70($s3)
/* C70158 80241E28 8FBF0020 */  lw        $ra, 0x20($sp)
/* C7015C 80241E2C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C70160 80241E30 8FB20018 */  lw        $s2, 0x18($sp)
/* C70164 80241E34 8FB10014 */  lw        $s1, 0x14($sp)
/* C70168 80241E38 8FB00010 */  lw        $s0, 0x10($sp)
/* C7016C 80241E3C D7B40028 */  ldc1      $f20, 0x28($sp)
/* C70170 80241E40 03E00008 */  jr        $ra
/* C70174 80241E44 27BD0030 */   addiu    $sp, $sp, 0x30
