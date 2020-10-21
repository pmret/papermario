.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240AFC_E0F29C
/* E0F29C 80240AFC 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* E0F2A0 80240B00 AFB3001C */  sw        $s3, 0x1c($sp)
/* E0F2A4 80240B04 0080982D */  daddu     $s3, $a0, $zero
/* E0F2A8 80240B08 AFBF0020 */  sw        $ra, 0x20($sp)
/* E0F2AC 80240B0C AFB20018 */  sw        $s2, 0x18($sp)
/* E0F2B0 80240B10 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F2B4 80240B14 AFB00010 */  sw        $s0, 0x10($sp)
/* E0F2B8 80240B18 F7B40028 */  sdc1      $f20, 0x28($sp)
/* E0F2BC 80240B1C 8E710148 */  lw        $s1, 0x148($s3)
/* E0F2C0 80240B20 86240008 */  lh        $a0, 8($s1)
/* E0F2C4 80240B24 0C00EABB */  jal       get_npc_unsafe
/* E0F2C8 80240B28 00A0802D */   daddu    $s0, $a1, $zero
/* E0F2CC 80240B2C 8E040020 */  lw        $a0, 0x20($s0)
/* E0F2D0 80240B30 0040902D */  daddu     $s2, $v0, $zero
/* E0F2D4 80240B34 00041FC2 */  srl       $v1, $a0, 0x1f
/* E0F2D8 80240B38 00832021 */  addu      $a0, $a0, $v1
/* E0F2DC 80240B3C 00042043 */  sra       $a0, $a0, 1
/* E0F2E0 80240B40 0C00A67F */  jal       rand_int
/* E0F2E4 80240B44 24840001 */   addiu    $a0, $a0, 1
/* E0F2E8 80240B48 8E030020 */  lw        $v1, 0x20($s0)
/* E0F2EC 80240B4C C64C0038 */  lwc1      $f12, 0x38($s2)
/* E0F2F0 80240B50 000327C2 */  srl       $a0, $v1, 0x1f
/* E0F2F4 80240B54 00641821 */  addu      $v1, $v1, $a0
/* E0F2F8 80240B58 00031843 */  sra       $v1, $v1, 1
/* E0F2FC 80240B5C 00621821 */  addu      $v1, $v1, $v0
/* E0F300 80240B60 A643008E */  sh        $v1, 0x8e($s2)
/* E0F304 80240B64 8E2200CC */  lw        $v0, 0xcc($s1)
/* E0F308 80240B68 C64E0040 */  lwc1      $f14, 0x40($s2)
/* E0F30C 80240B6C 8C42000C */  lw        $v0, 0xc($v0)
/* E0F310 80240B70 AE420028 */  sw        $v0, 0x28($s2)
/* E0F314 80240B74 C6000018 */  lwc1      $f0, 0x18($s0)
/* E0F318 80240B78 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* E0F31C 80240B7C 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* E0F320 80240B80 E6400018 */  swc1      $f0, 0x18($s2)
/* E0F324 80240B84 8C460028 */  lw        $a2, 0x28($v0)
/* E0F328 80240B88 0C00A720 */  jal       atan2
/* E0F32C 80240B8C 8C470030 */   lw       $a3, 0x30($v0)
/* E0F330 80240B90 46000506 */  mov.s     $f20, $f0
/* E0F334 80240B94 C64C000C */  lwc1      $f12, 0xc($s2)
/* E0F338 80240B98 0C00A70A */  jal       get_clamped_angle_diff
/* E0F33C 80240B9C 4600A386 */   mov.s    $f14, $f20
/* E0F340 80240BA0 46000086 */  mov.s     $f2, $f0
/* E0F344 80240BA4 8E02001C */  lw        $v0, 0x1c($s0)
/* E0F348 80240BA8 46001005 */  abs.s     $f0, $f2
/* E0F34C 80240BAC 44822000 */  mtc1      $v0, $f4
/* E0F350 80240BB0 00000000 */  nop       
/* E0F354 80240BB4 46802120 */  cvt.s.w   $f4, $f4
/* E0F358 80240BB8 4600203C */  c.lt.s    $f4, $f0
/* E0F35C 80240BBC 00000000 */  nop       
/* E0F360 80240BC0 4500000D */  bc1f      .L80240BF8
/* E0F364 80240BC4 00000000 */   nop      
/* E0F368 80240BC8 44800000 */  mtc1      $zero, $f0
/* E0F36C 80240BCC C654000C */  lwc1      $f20, 0xc($s2)
/* E0F370 80240BD0 4600103C */  c.lt.s    $f2, $f0
/* E0F374 80240BD4 00000000 */  nop       
/* E0F378 80240BD8 45000006 */  bc1f      .L80240BF4
/* E0F37C 80240BDC 00021023 */   negu     $v0, $v0
/* E0F380 80240BE0 44820000 */  mtc1      $v0, $f0
/* E0F384 80240BE4 00000000 */  nop       
/* E0F388 80240BE8 46800020 */  cvt.s.w   $f0, $f0
/* E0F38C 80240BEC 080902FE */  j         .L80240BF8
/* E0F390 80240BF0 4600A500 */   add.s    $f20, $f20, $f0
.L80240BF4:
/* E0F394 80240BF4 4604A500 */  add.s     $f20, $f20, $f4
.L80240BF8:
/* E0F398 80240BF8 0C00A6C9 */  jal       clamp_angle
/* E0F39C 80240BFC 4600A306 */   mov.s    $f12, $f20
/* E0F3A0 80240C00 2402000D */  addiu     $v0, $zero, 0xd
/* E0F3A4 80240C04 E640000C */  swc1      $f0, 0xc($s2)
/* E0F3A8 80240C08 AE620070 */  sw        $v0, 0x70($s3)
/* E0F3AC 80240C0C 8FBF0020 */  lw        $ra, 0x20($sp)
/* E0F3B0 80240C10 8FB3001C */  lw        $s3, 0x1c($sp)
/* E0F3B4 80240C14 8FB20018 */  lw        $s2, 0x18($sp)
/* E0F3B8 80240C18 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F3BC 80240C1C 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F3C0 80240C20 D7B40028 */  ldc1      $f20, 0x28($sp)
/* E0F3C4 80240C24 03E00008 */  jr        $ra
/* E0F3C8 80240C28 27BD0030 */   addiu    $sp, $sp, 0x30
