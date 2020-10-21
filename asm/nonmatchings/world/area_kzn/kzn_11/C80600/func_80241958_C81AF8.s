.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241958_C81AF8
/* C81AF8 80241958 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C81AFC 8024195C AFB3001C */  sw        $s3, 0x1c($sp)
/* C81B00 80241960 0080982D */  daddu     $s3, $a0, $zero
/* C81B04 80241964 AFBF0020 */  sw        $ra, 0x20($sp)
/* C81B08 80241968 AFB20018 */  sw        $s2, 0x18($sp)
/* C81B0C 8024196C AFB10014 */  sw        $s1, 0x14($sp)
/* C81B10 80241970 AFB00010 */  sw        $s0, 0x10($sp)
/* C81B14 80241974 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C81B18 80241978 8E710148 */  lw        $s1, 0x148($s3)
/* C81B1C 8024197C 86240008 */  lh        $a0, 8($s1)
/* C81B20 80241980 0C00EABB */  jal       get_npc_unsafe
/* C81B24 80241984 00A0802D */   daddu    $s0, $a1, $zero
/* C81B28 80241988 8E040020 */  lw        $a0, 0x20($s0)
/* C81B2C 8024198C 0040902D */  daddu     $s2, $v0, $zero
/* C81B30 80241990 00041FC2 */  srl       $v1, $a0, 0x1f
/* C81B34 80241994 00832021 */  addu      $a0, $a0, $v1
/* C81B38 80241998 00042043 */  sra       $a0, $a0, 1
/* C81B3C 8024199C 0C00A67F */  jal       rand_int
/* C81B40 802419A0 24840001 */   addiu    $a0, $a0, 1
/* C81B44 802419A4 8E030020 */  lw        $v1, 0x20($s0)
/* C81B48 802419A8 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C81B4C 802419AC 000327C2 */  srl       $a0, $v1, 0x1f
/* C81B50 802419B0 00641821 */  addu      $v1, $v1, $a0
/* C81B54 802419B4 00031843 */  sra       $v1, $v1, 1
/* C81B58 802419B8 00621821 */  addu      $v1, $v1, $v0
/* C81B5C 802419BC A643008E */  sh        $v1, 0x8e($s2)
/* C81B60 802419C0 8E2200CC */  lw        $v0, 0xcc($s1)
/* C81B64 802419C4 C64E0040 */  lwc1      $f14, 0x40($s2)
/* C81B68 802419C8 8C42000C */  lw        $v0, 0xc($v0)
/* C81B6C 802419CC AE420028 */  sw        $v0, 0x28($s2)
/* C81B70 802419D0 C6000018 */  lwc1      $f0, 0x18($s0)
/* C81B74 802419D4 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C81B78 802419D8 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C81B7C 802419DC E6400018 */  swc1      $f0, 0x18($s2)
/* C81B80 802419E0 8C460028 */  lw        $a2, 0x28($v0)
/* C81B84 802419E4 0C00A720 */  jal       atan2
/* C81B88 802419E8 8C470030 */   lw       $a3, 0x30($v0)
/* C81B8C 802419EC 46000506 */  mov.s     $f20, $f0
/* C81B90 802419F0 C64C000C */  lwc1      $f12, 0xc($s2)
/* C81B94 802419F4 0C00A70A */  jal       get_clamped_angle_diff
/* C81B98 802419F8 4600A386 */   mov.s    $f14, $f20
/* C81B9C 802419FC 46000086 */  mov.s     $f2, $f0
/* C81BA0 80241A00 8E02001C */  lw        $v0, 0x1c($s0)
/* C81BA4 80241A04 46001005 */  abs.s     $f0, $f2
/* C81BA8 80241A08 44822000 */  mtc1      $v0, $f4
/* C81BAC 80241A0C 00000000 */  nop       
/* C81BB0 80241A10 46802120 */  cvt.s.w   $f4, $f4
/* C81BB4 80241A14 4600203C */  c.lt.s    $f4, $f0
/* C81BB8 80241A18 00000000 */  nop       
/* C81BBC 80241A1C 4500000D */  bc1f      .L80241A54
/* C81BC0 80241A20 00000000 */   nop      
/* C81BC4 80241A24 44800000 */  mtc1      $zero, $f0
/* C81BC8 80241A28 C654000C */  lwc1      $f20, 0xc($s2)
/* C81BCC 80241A2C 4600103C */  c.lt.s    $f2, $f0
/* C81BD0 80241A30 00000000 */  nop       
/* C81BD4 80241A34 45000006 */  bc1f      .L80241A50
/* C81BD8 80241A38 00021023 */   negu     $v0, $v0
/* C81BDC 80241A3C 44820000 */  mtc1      $v0, $f0
/* C81BE0 80241A40 00000000 */  nop       
/* C81BE4 80241A44 46800020 */  cvt.s.w   $f0, $f0
/* C81BE8 80241A48 08090695 */  j         .L80241A54
/* C81BEC 80241A4C 4600A500 */   add.s    $f20, $f20, $f0
.L80241A50:
/* C81BF0 80241A50 4604A500 */  add.s     $f20, $f20, $f4
.L80241A54:
/* C81BF4 80241A54 0C00A6C9 */  jal       clamp_angle
/* C81BF8 80241A58 4600A306 */   mov.s    $f12, $f20
/* C81BFC 80241A5C 2402000D */  addiu     $v0, $zero, 0xd
/* C81C00 80241A60 E640000C */  swc1      $f0, 0xc($s2)
/* C81C04 80241A64 AE620070 */  sw        $v0, 0x70($s3)
/* C81C08 80241A68 8FBF0020 */  lw        $ra, 0x20($sp)
/* C81C0C 80241A6C 8FB3001C */  lw        $s3, 0x1c($sp)
/* C81C10 80241A70 8FB20018 */  lw        $s2, 0x18($sp)
/* C81C14 80241A74 8FB10014 */  lw        $s1, 0x14($sp)
/* C81C18 80241A78 8FB00010 */  lw        $s0, 0x10($sp)
/* C81C1C 80241A7C D7B40028 */  ldc1      $f20, 0x28($sp)
/* C81C20 80241A80 03E00008 */  jr        $ra
/* C81C24 80241A84 27BD0030 */   addiu    $sp, $sp, 0x30
