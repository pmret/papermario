.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D1270
/* F5C20 802D1270 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* F5C24 802D1274 AFB10014 */  sw        $s1, 0x14($sp)
/* F5C28 802D1278 0080882D */  daddu     $s1, $a0, $zero
/* F5C2C 802D127C AFB20018 */  sw        $s2, 0x18($sp)
/* F5C30 802D1280 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* F5C34 802D1284 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* F5C38 802D1288 AFBF001C */  sw        $ra, 0x1c($sp)
/* F5C3C 802D128C AFB00010 */  sw        $s0, 0x10($sp)
/* F5C40 802D1290 F7B80030 */  sdc1      $f24, 0x30($sp)
/* F5C44 802D1294 F7B60028 */  sdc1      $f22, 0x28($sp)
/* F5C48 802D1298 F7B40020 */  sdc1      $f20, 0x20($sp)
/* F5C4C 802D129C 10A0002A */  beqz      $a1, .L802D1348
/* F5C50 802D12A0 8E30000C */   lw       $s0, 0xc($s1)
/* F5C54 802D12A4 8E050000 */  lw        $a1, ($s0)
/* F5C58 802D12A8 0C0B1EAF */  jal       get_variable
/* F5C5C 802D12AC 26100004 */   addiu    $s0, $s0, 4
/* F5C60 802D12B0 8E050000 */  lw        $a1, ($s0)
/* F5C64 802D12B4 26100004 */  addiu     $s0, $s0, 4
/* F5C68 802D12B8 4482C000 */  mtc1      $v0, $f24
/* F5C6C 802D12BC 00000000 */  nop
/* F5C70 802D12C0 4680C620 */  cvt.s.w   $f24, $f24
/* F5C74 802D12C4 0C0B1EAF */  jal       get_variable
/* F5C78 802D12C8 0220202D */   daddu    $a0, $s1, $zero
/* F5C7C 802D12CC 8E050000 */  lw        $a1, ($s0)
/* F5C80 802D12D0 4482B000 */  mtc1      $v0, $f22
/* F5C84 802D12D4 00000000 */  nop
/* F5C88 802D12D8 4680B5A0 */  cvt.s.w   $f22, $f22
/* F5C8C 802D12DC 0C0B210B */  jal       get_float_variable
/* F5C90 802D12E0 0220202D */   daddu    $a0, $s1, $zero
/* F5C94 802D12E4 C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5C98 802D12E8 C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5C9C 802D12EC 4406C000 */  mfc1      $a2, $f24
/* F5CA0 802D12F0 4407B000 */  mfc1      $a3, $f22
/* F5CA4 802D12F4 0C00A720 */  jal       atan2
/* F5CA8 802D12F8 46000506 */   mov.s    $f20, $f0
/* F5CAC 802D12FC C64C0028 */  lwc1      $f12, 0x28($s2)
/* F5CB0 802D1300 C64E0030 */  lwc1      $f14, 0x30($s2)
/* F5CB4 802D1304 4406C000 */  mfc1      $a2, $f24
/* F5CB8 802D1308 4407B000 */  mfc1      $a3, $f22
/* F5CBC 802D130C 0C00A7B5 */  jal       dist2D
/* F5CC0 802D1310 E6400080 */   swc1     $f0, 0x80($s2)
/* F5CC4 802D1314 46140503 */  div.s     $f20, $f0, $f20
/* F5CC8 802D1318 4600A10D */  trunc.w.s $f4, $f20
/* F5CCC 802D131C 44042000 */  mfc1      $a0, $f4
/* F5CD0 802D1320 00000000 */  nop
/* F5CD4 802D1324 44841000 */  mtc1      $a0, $f2
/* F5CD8 802D1328 00000000 */  nop
/* F5CDC 802D132C 468010A0 */  cvt.s.w   $f2, $f2
/* F5CE0 802D1330 46020003 */  div.s     $f0, $f0, $f2
/* F5CE4 802D1334 AE240070 */  sw        $a0, 0x70($s1)
/* F5CE8 802D1338 8E450080 */  lw        $a1, 0x80($s2)
/* F5CEC 802D133C 44060000 */  mfc1      $a2, $f0
/* F5CF0 802D1340 0C0389DE */  jal       move_player
/* F5CF4 802D1344 00000000 */   nop
.L802D1348:
/* F5CF8 802D1348 8E230070 */  lw        $v1, 0x70($s1)
/* F5CFC 802D134C 2463FFFF */  addiu     $v1, $v1, -1
/* F5D00 802D1350 000317C3 */  sra       $v0, $v1, 0x1f
/* F5D04 802D1354 AE230070 */  sw        $v1, 0x70($s1)
/* F5D08 802D1358 8FBF001C */  lw        $ra, 0x1c($sp)
/* F5D0C 802D135C 8FB20018 */  lw        $s2, 0x18($sp)
/* F5D10 802D1360 8FB10014 */  lw        $s1, 0x14($sp)
/* F5D14 802D1364 8FB00010 */  lw        $s0, 0x10($sp)
/* F5D18 802D1368 D7B80030 */  ldc1      $f24, 0x30($sp)
/* F5D1C 802D136C D7B60028 */  ldc1      $f22, 0x28($sp)
/* F5D20 802D1370 D7B40020 */  ldc1      $f20, 0x20($sp)
/* F5D24 802D1374 30420002 */  andi      $v0, $v0, 2
/* F5D28 802D1378 03E00008 */  jr        $ra
/* F5D2C 802D137C 27BD0038 */   addiu    $sp, $sp, 0x38
