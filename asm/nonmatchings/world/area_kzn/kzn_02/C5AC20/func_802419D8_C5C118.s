.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D8_C5C118
/* C5C118 802419D8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* C5C11C 802419DC AFB3001C */  sw        $s3, 0x1c($sp)
/* C5C120 802419E0 0080982D */  daddu     $s3, $a0, $zero
/* C5C124 802419E4 AFBF0020 */  sw        $ra, 0x20($sp)
/* C5C128 802419E8 AFB20018 */  sw        $s2, 0x18($sp)
/* C5C12C 802419EC AFB10014 */  sw        $s1, 0x14($sp)
/* C5C130 802419F0 AFB00010 */  sw        $s0, 0x10($sp)
/* C5C134 802419F4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* C5C138 802419F8 8E710148 */  lw        $s1, 0x148($s3)
/* C5C13C 802419FC 86240008 */  lh        $a0, 8($s1)
/* C5C140 80241A00 0C00EABB */  jal       get_npc_unsafe
/* C5C144 80241A04 00A0802D */   daddu    $s0, $a1, $zero
/* C5C148 80241A08 8E040020 */  lw        $a0, 0x20($s0)
/* C5C14C 80241A0C 0040902D */  daddu     $s2, $v0, $zero
/* C5C150 80241A10 00041FC2 */  srl       $v1, $a0, 0x1f
/* C5C154 80241A14 00832021 */  addu      $a0, $a0, $v1
/* C5C158 80241A18 00042043 */  sra       $a0, $a0, 1
/* C5C15C 80241A1C 0C00A67F */  jal       rand_int
/* C5C160 80241A20 24840001 */   addiu    $a0, $a0, 1
/* C5C164 80241A24 8E030020 */  lw        $v1, 0x20($s0)
/* C5C168 80241A28 C64C0038 */  lwc1      $f12, 0x38($s2)
/* C5C16C 80241A2C 000327C2 */  srl       $a0, $v1, 0x1f
/* C5C170 80241A30 00641821 */  addu      $v1, $v1, $a0
/* C5C174 80241A34 00031843 */  sra       $v1, $v1, 1
/* C5C178 80241A38 00621821 */  addu      $v1, $v1, $v0
/* C5C17C 80241A3C A643008E */  sh        $v1, 0x8e($s2)
/* C5C180 80241A40 8E2200CC */  lw        $v0, 0xcc($s1)
/* C5C184 80241A44 C64E0040 */  lwc1      $f14, 0x40($s2)
/* C5C188 80241A48 8C42000C */  lw        $v0, 0xc($v0)
/* C5C18C 80241A4C AE420028 */  sw        $v0, 0x28($s2)
/* C5C190 80241A50 C6000018 */  lwc1      $f0, 0x18($s0)
/* C5C194 80241A54 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5C198 80241A58 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5C19C 80241A5C E6400018 */  swc1      $f0, 0x18($s2)
/* C5C1A0 80241A60 8C460028 */  lw        $a2, 0x28($v0)
/* C5C1A4 80241A64 0C00A720 */  jal       atan2
/* C5C1A8 80241A68 8C470030 */   lw       $a3, 0x30($v0)
/* C5C1AC 80241A6C 46000506 */  mov.s     $f20, $f0
/* C5C1B0 80241A70 C64C000C */  lwc1      $f12, 0xc($s2)
/* C5C1B4 80241A74 0C00A70A */  jal       get_clamped_angle_diff
/* C5C1B8 80241A78 4600A386 */   mov.s    $f14, $f20
/* C5C1BC 80241A7C 46000086 */  mov.s     $f2, $f0
/* C5C1C0 80241A80 8E02001C */  lw        $v0, 0x1c($s0)
/* C5C1C4 80241A84 46001005 */  abs.s     $f0, $f2
/* C5C1C8 80241A88 44822000 */  mtc1      $v0, $f4
/* C5C1CC 80241A8C 00000000 */  nop       
/* C5C1D0 80241A90 46802120 */  cvt.s.w   $f4, $f4
/* C5C1D4 80241A94 4600203C */  c.lt.s    $f4, $f0
/* C5C1D8 80241A98 00000000 */  nop       
/* C5C1DC 80241A9C 4500000D */  bc1f      .L80241AD4
/* C5C1E0 80241AA0 00000000 */   nop      
/* C5C1E4 80241AA4 44800000 */  mtc1      $zero, $f0
/* C5C1E8 80241AA8 C654000C */  lwc1      $f20, 0xc($s2)
/* C5C1EC 80241AAC 4600103C */  c.lt.s    $f2, $f0
/* C5C1F0 80241AB0 00000000 */  nop       
/* C5C1F4 80241AB4 45000006 */  bc1f      .L80241AD0
/* C5C1F8 80241AB8 00021023 */   negu     $v0, $v0
/* C5C1FC 80241ABC 44820000 */  mtc1      $v0, $f0
/* C5C200 80241AC0 00000000 */  nop       
/* C5C204 80241AC4 46800020 */  cvt.s.w   $f0, $f0
/* C5C208 80241AC8 080906B5 */  j         .L80241AD4
/* C5C20C 80241ACC 4600A500 */   add.s    $f20, $f20, $f0
.L80241AD0:
/* C5C210 80241AD0 4604A500 */  add.s     $f20, $f20, $f4
.L80241AD4:
/* C5C214 80241AD4 0C00A6C9 */  jal       clamp_angle
/* C5C218 80241AD8 4600A306 */   mov.s    $f12, $f20
/* C5C21C 80241ADC 2402000D */  addiu     $v0, $zero, 0xd
/* C5C220 80241AE0 E640000C */  swc1      $f0, 0xc($s2)
/* C5C224 80241AE4 AE620070 */  sw        $v0, 0x70($s3)
/* C5C228 80241AE8 8FBF0020 */  lw        $ra, 0x20($sp)
/* C5C22C 80241AEC 8FB3001C */  lw        $s3, 0x1c($sp)
/* C5C230 80241AF0 8FB20018 */  lw        $s2, 0x18($sp)
/* C5C234 80241AF4 8FB10014 */  lw        $s1, 0x14($sp)
/* C5C238 80241AF8 8FB00010 */  lw        $s0, 0x10($sp)
/* C5C23C 80241AFC D7B40028 */  ldc1      $f20, 0x28($sp)
/* C5C240 80241B00 03E00008 */  jr        $ra
/* C5C244 80241B04 27BD0030 */   addiu    $sp, $sp, 0x30
