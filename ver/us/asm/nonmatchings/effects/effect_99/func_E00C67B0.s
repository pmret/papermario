.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00C67B0
/* 3CD190 E00C67B0 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 3CD194 E00C67B4 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 3CD198 E00C67B8 27BDFF00 */  addiu     $sp, $sp, -0x100
/* 3CD19C E00C67BC AFA40100 */  sw        $a0, 0x100($sp)
/* 3CD1A0 E00C67C0 8FAA0100 */  lw        $t2, 0x100($sp)
/* 3CD1A4 E00C67C4 3C04800B */  lui       $a0, %hi(gCameras)
/* 3CD1A8 E00C67C8 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 3CD1AC E00C67CC AFBF00CC */  sw        $ra, 0xcc($sp)
/* 3CD1B0 E00C67D0 AFBE00C8 */  sw        $fp, 0xc8($sp)
/* 3CD1B4 E00C67D4 AFB700C4 */  sw        $s7, 0xc4($sp)
/* 3CD1B8 E00C67D8 AFB600C0 */  sw        $s6, 0xc0($sp)
/* 3CD1BC E00C67DC AFB500BC */  sw        $s5, 0xbc($sp)
/* 3CD1C0 E00C67E0 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 3CD1C4 E00C67E4 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 3CD1C8 E00C67E8 AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3CD1CC E00C67EC AFB100AC */  sw        $s1, 0xac($sp)
/* 3CD1D0 E00C67F0 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3CD1D4 E00C67F4 F7BE00F8 */  sdc1      $f30, 0xf8($sp)
/* 3CD1D8 E00C67F8 F7BC00F0 */  sdc1      $f28, 0xf0($sp)
/* 3CD1DC E00C67FC F7BA00E8 */  sdc1      $f26, 0xe8($sp)
/* 3CD1E0 E00C6800 F7B800E0 */  sdc1      $f24, 0xe0($sp)
/* 3CD1E4 E00C6804 F7B600D8 */  sdc1      $f22, 0xd8($sp)
/* 3CD1E8 E00C6808 F7B400D0 */  sdc1      $f20, 0xd0($sp)
/* 3CD1EC E00C680C 00031080 */  sll       $v0, $v1, 2
/* 3CD1F0 E00C6810 00431021 */  addu      $v0, $v0, $v1
/* 3CD1F4 E00C6814 00021080 */  sll       $v0, $v0, 2
/* 3CD1F8 E00C6818 00431023 */  subu      $v0, $v0, $v1
/* 3CD1FC E00C681C 000218C0 */  sll       $v1, $v0, 3
/* 3CD200 E00C6820 00431021 */  addu      $v0, $v0, $v1
/* 3CD204 E00C6824 000210C0 */  sll       $v0, $v0, 3
/* 3CD208 E00C6828 8D49000C */  lw        $t1, 0xc($t2)
/* 3CD20C E00C682C 00441021 */  addu      $v0, $v0, $a0
/* 3CD210 E00C6830 AFA20098 */  sw        $v0, 0x98($sp)
/* 3CD214 E00C6834 8D2A0000 */  lw        $t2, ($t1)
/* 3CD218 E00C6838 8D270034 */  lw        $a3, 0x34($t1)
/* 3CD21C E00C683C AFAA009C */  sw        $t2, 0x9c($sp)
/* 3CD220 E00C6840 C5380048 */  lwc1      $f24, 0x48($t1)
/* 3CD224 E00C6844 114000FD */  beqz      $t2, .LE00C6C3C
/* 3CD228 E00C6848 3C02E700 */   lui      $v0, 0xe700
/* 3CD22C E00C684C 3C05DB06 */  lui       $a1, 0xdb06
/* 3CD230 E00C6850 3C08800A */  lui       $t0, %hi(gMasterGfxPos)
/* 3CD234 E00C6854 2508A66C */  addiu     $t0, $t0, %lo(gMasterGfxPos)
/* 3CD238 E00C6858 34A50024 */  ori       $a1, $a1, 0x24
/* 3CD23C E00C685C 8D040000 */  lw        $a0, ($t0)
/* 3CD240 E00C6860 0080182D */  daddu     $v1, $a0, $zero
/* 3CD244 E00C6864 24840008 */  addiu     $a0, $a0, 8
/* 3CD248 E00C6868 AD040000 */  sw        $a0, ($t0)
/* 3CD24C E00C686C AC620000 */  sw        $v0, ($v1)
/* 3CD250 E00C6870 24820008 */  addiu     $v0, $a0, 8
/* 3CD254 E00C6874 AC600004 */  sw        $zero, 4($v1)
/* 3CD258 E00C6878 AD020000 */  sw        $v0, ($t0)
/* 3CD25C E00C687C AC850000 */  sw        $a1, ($a0)
/* 3CD260 E00C6880 8FAA0100 */  lw        $t2, 0x100($sp)
/* 3CD264 E00C6884 8D430010 */  lw        $v1, 0x10($t2)
/* 3CD268 E00C6888 24820010 */  addiu     $v0, $a0, 0x10
/* 3CD26C E00C688C AD020000 */  sw        $v0, ($t0)
/* 3CD270 E00C6890 8C63001C */  lw        $v1, 0x1c($v1)
/* 3CD274 E00C6894 3C02FA00 */  lui       $v0, 0xfa00
/* 3CD278 E00C6898 AC820008 */  sw        $v0, 8($a0)
/* 3CD27C E00C689C 3C028000 */  lui       $v0, 0x8000
/* 3CD280 E00C68A0 00621821 */  addu      $v1, $v1, $v0
/* 3CD284 E00C68A4 AC830004 */  sw        $v1, 4($a0)
/* 3CD288 E00C68A8 9122002B */  lbu       $v0, 0x2b($t1)
/* 3CD28C E00C68AC 9125002F */  lbu       $a1, 0x2f($t1)
/* 3CD290 E00C68B0 91260033 */  lbu       $a2, 0x33($t1)
/* 3CD294 E00C68B4 24830018 */  addiu     $v1, $a0, 0x18
/* 3CD298 E00C68B8 AD030000 */  sw        $v1, ($t0)
/* 3CD29C E00C68BC 3C03FB00 */  lui       $v1, 0xfb00
/* 3CD2A0 E00C68C0 AC830010 */  sw        $v1, 0x10($a0)
/* 3CD2A4 E00C68C4 30E300FF */  andi      $v1, $a3, 0xff
/* 3CD2A8 E00C68C8 00021600 */  sll       $v0, $v0, 0x18
/* 3CD2AC E00C68CC 00052C00 */  sll       $a1, $a1, 0x10
/* 3CD2B0 E00C68D0 00451025 */  or        $v0, $v0, $a1
/* 3CD2B4 E00C68D4 00063200 */  sll       $a2, $a2, 8
/* 3CD2B8 E00C68D8 00461025 */  or        $v0, $v0, $a2
/* 3CD2BC E00C68DC 00431025 */  or        $v0, $v0, $v1
/* 3CD2C0 E00C68E0 AC82000C */  sw        $v0, 0xc($a0)
/* 3CD2C4 E00C68E4 9122003B */  lbu       $v0, 0x3b($t1)
/* 3CD2C8 E00C68E8 9125003F */  lbu       $a1, 0x3f($t1)
/* 3CD2CC E00C68EC 91260043 */  lbu       $a2, 0x43($t1)
/* 3CD2D0 E00C68F0 91270047 */  lbu       $a3, 0x47($t1)
/* 3CD2D4 E00C68F4 3C03DE00 */  lui       $v1, 0xde00
/* 3CD2D8 E00C68F8 AC830018 */  sw        $v1, 0x18($a0)
/* 3CD2DC E00C68FC 00021600 */  sll       $v0, $v0, 0x18
/* 3CD2E0 E00C6900 00052C00 */  sll       $a1, $a1, 0x10
/* 3CD2E4 E00C6904 00451025 */  or        $v0, $v0, $a1
/* 3CD2E8 E00C6908 00063200 */  sll       $a2, $a2, 8
/* 3CD2EC E00C690C 00461025 */  or        $v0, $v0, $a2
/* 3CD2F0 E00C6910 00471025 */  or        $v0, $v0, $a3
/* 3CD2F4 E00C6914 AC820014 */  sw        $v0, 0x14($a0)
/* 3CD2F8 E00C6918 8FAA009C */  lw        $t2, 0x9c($sp)
/* 3CD2FC E00C691C 000A1080 */  sll       $v0, $t2, 2
/* 3CD300 E00C6920 3C01E00C */  lui       $at, %hi(D_E00C6C9C)
/* 3CD304 E00C6924 00220821 */  addu      $at, $at, $v0
/* 3CD308 E00C6928 8C226C9C */  lw        $v0, %lo(D_E00C6C9C)($at)
/* 3CD30C E00C692C AC82001C */  sw        $v0, 0x1c($a0)
/* 3CD310 E00C6930 8FAA0100 */  lw        $t2, 0x100($sp)
/* 3CD314 E00C6934 0000B02D */  daddu     $s6, $zero, $zero
/* 3CD318 E00C6938 8D420008 */  lw        $v0, 8($t2)
/* 3CD31C E00C693C 24840020 */  addiu     $a0, $a0, 0x20
/* 3CD320 E00C6940 184000BE */  blez      $v0, .LE00C6C3C
/* 3CD324 E00C6944 AD040000 */   sw       $a0, ($t0)
/* 3CD328 E00C6948 27B50058 */  addiu     $s5, $sp, 0x58
/* 3CD32C E00C694C 3C1E800A */  lui       $fp, %hi(gDisplayContext)
/* 3CD330 E00C6950 27DEA674 */  addiu     $fp, $fp, %lo(gDisplayContext)
/* 3CD334 E00C6954 3C178007 */  lui       $s7, %hi(gMatrixListPos)
/* 3CD338 E00C6958 26F741F0 */  addiu     $s7, $s7, %lo(gMatrixListPos)
/* 3CD33C E00C695C 3C140001 */  lui       $s4, 1
/* 3CD340 E00C6960 36941630 */  ori       $s4, $s4, 0x1630
/* 3CD344 E00C6964 0100982D */  daddu     $s3, $t0, $zero
/* 3CD348 E00C6968 3C0ADA38 */  lui       $t2, 0xda38
/* 3CD34C E00C696C 354A0001 */  ori       $t2, $t2, 1
/* 3CD350 E00C6970 4480B000 */  mtc1      $zero, $f22
/* 3CD354 E00C6974 3C014300 */  lui       $at, 0x4300
/* 3CD358 E00C6978 4481D000 */  mtc1      $at, $f26
/* 3CD35C E00C697C 3C014080 */  lui       $at, 0x4080
/* 3CD360 E00C6980 4481F000 */  mtc1      $at, $f30
/* 3CD364 E00C6984 3C013F80 */  lui       $at, 0x3f80
/* 3CD368 E00C6988 4481E000 */  mtc1      $at, $f28
/* 3CD36C E00C698C 25320074 */  addiu     $s2, $t1, 0x74
/* 3CD370 E00C6990 AFAA00A0 */  sw        $t2, 0xa0($sp)
.LE00C6994:
/* 3CD374 E00C6994 4600B306 */  mov.s     $f12, $f22
/* 3CD378 E00C6998 C644FFD8 */  lwc1      $f4, -0x28($s2)
/* 3CD37C E00C699C C640FFE0 */  lwc1      $f0, -0x20($s2)
/* 3CD380 E00C69A0 8E46FFEC */  lw        $a2, -0x14($s2)
/* 3CD384 E00C69A4 C642FFE4 */  lwc1      $f2, -0x1c($s2)
/* 3CD388 E00C69A8 46002100 */  add.s     $f4, $f4, $f0
/* 3CD38C E00C69AC C640FFDC */  lwc1      $f0, -0x24($s2)
/* 3CD390 E00C69B0 8E47FFF0 */  lw        $a3, -0x10($s2)
/* 3CD394 E00C69B4 46020000 */  add.s     $f0, $f0, $f2
/* 3CD398 E00C69B8 4600B386 */  mov.s     $f14, $f22
/* 3CD39C E00C69BC E644FFD8 */  swc1      $f4, -0x28($s2)
/* 3CD3A0 E00C69C0 0C080148 */  jal       shim_atan2
/* 3CD3A4 E00C69C4 E640FFDC */   swc1     $f0, -0x24($s2)
/* 3CD3A8 E00C69C8 C6420000 */  lwc1      $f2, ($s2)
/* 3CD3AC E00C69CC 46000507 */  neg.s     $f20, $f0
/* 3CD3B0 E00C69D0 4602A500 */  add.s     $f20, $f20, $f2
/* 3CD3B4 E00C69D4 0C080140 */  jal       shim_sin_deg
/* 3CD3B8 E00C69D8 4600A306 */   mov.s    $f12, $f20
/* 3CD3BC E00C69DC 4600A306 */  mov.s     $f12, $f20
/* 3CD3C0 E00C69E0 0C080144 */  jal       shim_cos_deg
/* 3CD3C4 E00C69E4 E640FFE0 */   swc1     $f0, -0x20($s2)
/* 3CD3C8 E00C69E8 C642FFD8 */  lwc1      $f2, -0x28($s2)
/* 3CD3CC E00C69EC 4616103C */  c.lt.s    $f2, $f22
/* 3CD3D0 E00C69F0 00000000 */  nop
/* 3CD3D4 E00C69F4 45000003 */  bc1f      .LE00C6A04
/* 3CD3D8 E00C69F8 E640FFE4 */   swc1     $f0, -0x1c($s2)
/* 3CD3DC E00C69FC 461A1000 */  add.s     $f0, $f2, $f26
/* 3CD3E0 E00C6A00 E640FFD8 */  swc1      $f0, -0x28($s2)
.LE00C6A04:
/* 3CD3E4 E00C6A04 C640FFDC */  lwc1      $f0, -0x24($s2)
/* 3CD3E8 E00C6A08 4600D03C */  c.lt.s    $f26, $f0
/* 3CD3EC E00C6A0C 00000000 */  nop
/* 3CD3F0 E00C6A10 45000003 */  bc1f      .LE00C6A20
/* 3CD3F4 E00C6A14 00000000 */   nop
/* 3CD3F8 E00C6A18 461A0001 */  sub.s     $f0, $f0, $f26
/* 3CD3FC E00C6A1C E640FFDC */  swc1      $f0, -0x24($s2)
.LE00C6A20:
/* 3CD400 E00C6A20 C642FFD8 */  lwc1      $f2, -0x28($s2)
/* 3CD404 E00C6A24 461E1082 */  mul.s     $f2, $f2, $f30
/* 3CD408 E00C6A28 00000000 */  nop
/* 3CD40C E00C6A2C 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CD410 E00C6A30 C640FFDC */  lwc1      $f0, -0x24($s2)
/* 3CD414 E00C6A34 461E0002 */  mul.s     $f0, $f0, $f30
/* 3CD418 E00C6A38 00000000 */  nop
/* 3CD41C E00C6A3C 8E45FF90 */  lw        $a1, -0x70($s2)
/* 3CD420 E00C6A40 8E46FF94 */  lw        $a2, -0x6c($s2)
/* 3CD424 E00C6A44 8E47FF98 */  lw        $a3, -0x68($s2)
/* 3CD428 E00C6A48 4600118D */  trunc.w.s $f6, $f2
/* 3CD42C E00C6A4C 44103000 */  mfc1      $s0, $f6
/* 3CD430 E00C6A50 4600018D */  trunc.w.s $f6, $f0
/* 3CD434 E00C6A54 44113000 */  mfc1      $s1, $f6
/* 3CD438 E00C6A58 0C080108 */  jal       shim_guTranslateF
/* 3CD43C E00C6A5C 26D60001 */   addiu    $s6, $s6, 1
/* 3CD440 E00C6A60 4405C000 */  mfc1      $a1, $f24
/* 3CD444 E00C6A64 4406C000 */  mfc1      $a2, $f24
/* 3CD448 E00C6A68 4407C000 */  mfc1      $a3, $f24
/* 3CD44C E00C6A6C 0C080110 */  jal       shim_guScaleF
/* 3CD450 E00C6A70 02A0202D */   daddu    $a0, $s5, $zero
/* 3CD454 E00C6A74 02A0202D */  daddu     $a0, $s5, $zero
/* 3CD458 E00C6A78 27A50018 */  addiu     $a1, $sp, 0x18
/* 3CD45C E00C6A7C 0C080114 */  jal       shim_guMtxCatF
/* 3CD460 E00C6A80 00A0302D */   daddu    $a2, $a1, $zero
/* 3CD464 E00C6A84 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CD468 E00C6A88 96E50000 */  lhu       $a1, ($s7)
/* 3CD46C E00C6A8C 8FC20000 */  lw        $v0, ($fp)
/* 3CD470 E00C6A90 00052980 */  sll       $a1, $a1, 6
/* 3CD474 E00C6A94 00B42821 */  addu      $a1, $a1, $s4
/* 3CD478 E00C6A98 0C080118 */  jal       shim_guMtxF2L
/* 3CD47C E00C6A9C 00452821 */   addu     $a1, $v0, $a1
/* 3CD480 E00C6AA0 3C02DA38 */  lui       $v0, 0xda38
/* 3CD484 E00C6AA4 34420002 */  ori       $v0, $v0, 2
/* 3CD488 E00C6AA8 8E680000 */  lw        $t0, ($s3)
/* 3CD48C E00C6AAC 96E50000 */  lhu       $a1, ($s7)
/* 3CD490 E00C6AB0 0100302D */  daddu     $a2, $t0, $zero
/* 3CD494 E00C6AB4 25080008 */  addiu     $t0, $t0, 8
/* 3CD498 E00C6AB8 AE680000 */  sw        $t0, ($s3)
/* 3CD49C E00C6ABC ACC20000 */  sw        $v0, ($a2)
/* 3CD4A0 E00C6AC0 30A2FFFF */  andi      $v0, $a1, 0xffff
/* 3CD4A4 E00C6AC4 00021180 */  sll       $v0, $v0, 6
/* 3CD4A8 E00C6AC8 8FC30000 */  lw        $v1, ($fp)
/* 3CD4AC E00C6ACC 00541021 */  addu      $v0, $v0, $s4
/* 3CD4B0 E00C6AD0 00621821 */  addu      $v1, $v1, $v0
/* 3CD4B4 E00C6AD4 ACC30004 */  sw        $v1, 4($a2)
/* 3CD4B8 E00C6AD8 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3CD4BC E00C6ADC 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CD4C0 E00C6AE0 AD0A0000 */  sw        $t2, ($t0)
/* 3CD4C4 E00C6AE4 8FAA0098 */  lw        $t2, 0x98($sp)
/* 3CD4C8 E00C6AE8 4407E000 */  mfc1      $a3, $f28
/* 3CD4CC E00C6AEC 8D420204 */  lw        $v0, 0x204($t2)
/* 3CD4D0 E00C6AF0 24A50001 */  addiu     $a1, $a1, 1
/* 3CD4D4 E00C6AF4 A6E50000 */  sh        $a1, ($s7)
/* 3CD4D8 E00C6AF8 AD020004 */  sw        $v0, 4($t0)
/* 3CD4DC E00C6AFC 8E45FFFC */  lw        $a1, -4($s2)
/* 3CD4E0 E00C6B00 8E46FFF8 */  lw        $a2, -8($s2)
/* 3CD4E4 E00C6B04 25080008 */  addiu     $t0, $t0, 8
/* 3CD4E8 E00C6B08 0C080110 */  jal       shim_guScaleF
/* 3CD4EC E00C6B0C AE680000 */   sw       $t0, ($s3)
/* 3CD4F0 E00C6B10 E7BC0010 */  swc1      $f28, 0x10($sp)
/* 3CD4F4 E00C6B14 8E450000 */  lw        $a1, ($s2)
/* 3CD4F8 E00C6B18 4406B000 */  mfc1      $a2, $f22
/* 3CD4FC E00C6B1C 4407B000 */  mfc1      $a3, $f22
/* 3CD500 E00C6B20 0C080104 */  jal       shim_guRotateF
/* 3CD504 E00C6B24 02A0202D */   daddu    $a0, $s5, $zero
/* 3CD508 E00C6B28 02A0202D */  daddu     $a0, $s5, $zero
/* 3CD50C E00C6B2C 27A50018 */  addiu     $a1, $sp, 0x18
/* 3CD510 E00C6B30 0C080114 */  jal       shim_guMtxCatF
/* 3CD514 E00C6B34 00A0302D */   daddu    $a2, $a1, $zero
/* 3CD518 E00C6B38 27A40018 */  addiu     $a0, $sp, 0x18
/* 3CD51C E00C6B3C 96E50000 */  lhu       $a1, ($s7)
/* 3CD520 E00C6B40 8FC20000 */  lw        $v0, ($fp)
/* 3CD524 E00C6B44 00052980 */  sll       $a1, $a1, 6
/* 3CD528 E00C6B48 00B42821 */  addu      $a1, $a1, $s4
/* 3CD52C E00C6B4C 0C080118 */  jal       shim_guMtxF2L
/* 3CD530 E00C6B50 00452821 */   addu     $a1, $v0, $a1
/* 3CD534 E00C6B54 3C06D838 */  lui       $a2, 0xd838
/* 3CD538 E00C6B58 8E650000 */  lw        $a1, ($s3)
/* 3CD53C E00C6B5C 96E30000 */  lhu       $v1, ($s7)
/* 3CD540 E00C6B60 00A0202D */  daddu     $a0, $a1, $zero
/* 3CD544 E00C6B64 24A50008 */  addiu     $a1, $a1, 8
/* 3CD548 E00C6B68 24620001 */  addiu     $v0, $v1, 1
/* 3CD54C E00C6B6C 3063FFFF */  andi      $v1, $v1, 0xffff
/* 3CD550 E00C6B70 AE650000 */  sw        $a1, ($s3)
/* 3CD554 E00C6B74 8FAA00A0 */  lw        $t2, 0xa0($sp)
/* 3CD558 E00C6B78 00031980 */  sll       $v1, $v1, 6
/* 3CD55C E00C6B7C AC8A0000 */  sw        $t2, ($a0)
/* 3CD560 E00C6B80 A6E20000 */  sh        $v0, ($s7)
/* 3CD564 E00C6B84 8FC20000 */  lw        $v0, ($fp)
/* 3CD568 E00C6B88 00741821 */  addu      $v1, $v1, $s4
/* 3CD56C E00C6B8C 00431021 */  addu      $v0, $v0, $v1
/* 3CD570 E00C6B90 AC820004 */  sw        $v0, 4($a0)
/* 3CD574 E00C6B94 24A20008 */  addiu     $v0, $a1, 8
/* 3CD578 E00C6B98 32040FFF */  andi      $a0, $s0, 0xfff
/* 3CD57C E00C6B9C 00042300 */  sll       $a0, $a0, 0xc
/* 3CD580 E00C6BA0 AE620000 */  sw        $v0, ($s3)
/* 3CD584 E00C6BA4 32220FFF */  andi      $v0, $s1, 0xfff
/* 3CD588 E00C6BA8 3C03F200 */  lui       $v1, 0xf200
/* 3CD58C E00C6BAC 00431025 */  or        $v0, $v0, $v1
/* 3CD590 E00C6BB0 00822025 */  or        $a0, $a0, $v0
/* 3CD594 E00C6BB4 2610003F */  addiu     $s0, $s0, 0x3f
/* 3CD598 E00C6BB8 00108080 */  sll       $s0, $s0, 2
/* 3CD59C E00C6BBC 32100FFF */  andi      $s0, $s0, 0xfff
/* 3CD5A0 E00C6BC0 00108300 */  sll       $s0, $s0, 0xc
/* 3CD5A4 E00C6BC4 2631000F */  addiu     $s1, $s1, 0xf
/* 3CD5A8 E00C6BC8 00118880 */  sll       $s1, $s1, 2
/* 3CD5AC E00C6BCC 32310FFF */  andi      $s1, $s1, 0xfff
/* 3CD5B0 E00C6BD0 3C020100 */  lui       $v0, 0x100
/* 3CD5B4 E00C6BD4 02228825 */  or        $s1, $s1, $v0
/* 3CD5B8 E00C6BD8 02118025 */  or        $s0, $s0, $s1
/* 3CD5BC E00C6BDC 3C02DE00 */  lui       $v0, 0xde00
/* 3CD5C0 E00C6BE0 ACA40000 */  sw        $a0, ($a1)
/* 3CD5C4 E00C6BE4 ACB00004 */  sw        $s0, 4($a1)
/* 3CD5C8 E00C6BE8 ACA20008 */  sw        $v0, 8($a1)
/* 3CD5CC E00C6BEC 8FAA009C */  lw        $t2, 0x9c($sp)
/* 3CD5D0 E00C6BF0 34C60002 */  ori       $a2, $a2, 2
/* 3CD5D4 E00C6BF4 000A1080 */  sll       $v0, $t2, 2
/* 3CD5D8 E00C6BF8 3C0AE00C */  lui       $t2, %hi(D_E00C6C90)
/* 3CD5DC E00C6BFC 254A6C90 */  addiu     $t2, $t2, %lo(D_E00C6C90)
/* 3CD5E0 E00C6C00 004A1021 */  addu      $v0, $v0, $t2
/* 3CD5E4 E00C6C04 8C430000 */  lw        $v1, ($v0)
/* 3CD5E8 E00C6C08 24A20010 */  addiu     $v0, $a1, 0x10
/* 3CD5EC E00C6C0C AE620000 */  sw        $v0, ($s3)
/* 3CD5F0 E00C6C10 24020040 */  addiu     $v0, $zero, 0x40
/* 3CD5F4 E00C6C14 ACA60010 */  sw        $a2, 0x10($a1)
/* 3CD5F8 E00C6C18 ACA20014 */  sw        $v0, 0x14($a1)
/* 3CD5FC E00C6C1C ACA3000C */  sw        $v1, 0xc($a1)
/* 3CD600 E00C6C20 8FAA0100 */  lw        $t2, 0x100($sp)
/* 3CD604 E00C6C24 2652007C */  addiu     $s2, $s2, 0x7c
/* 3CD608 E00C6C28 8D420008 */  lw        $v0, 8($t2)
/* 3CD60C E00C6C2C 24A50018 */  addiu     $a1, $a1, 0x18
/* 3CD610 E00C6C30 02C2102A */  slt       $v0, $s6, $v0
/* 3CD614 E00C6C34 1440FF57 */  bnez      $v0, .LE00C6994
/* 3CD618 E00C6C38 AE650000 */   sw       $a1, ($s3)
.LE00C6C3C:
/* 3CD61C E00C6C3C 8FBF00CC */  lw        $ra, 0xcc($sp)
/* 3CD620 E00C6C40 8FBE00C8 */  lw        $fp, 0xc8($sp)
/* 3CD624 E00C6C44 8FB700C4 */  lw        $s7, 0xc4($sp)
/* 3CD628 E00C6C48 8FB600C0 */  lw        $s6, 0xc0($sp)
/* 3CD62C E00C6C4C 8FB500BC */  lw        $s5, 0xbc($sp)
/* 3CD630 E00C6C50 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 3CD634 E00C6C54 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 3CD638 E00C6C58 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 3CD63C E00C6C5C 8FB100AC */  lw        $s1, 0xac($sp)
/* 3CD640 E00C6C60 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 3CD644 E00C6C64 D7BE00F8 */  ldc1      $f30, 0xf8($sp)
/* 3CD648 E00C6C68 D7BC00F0 */  ldc1      $f28, 0xf0($sp)
/* 3CD64C E00C6C6C D7BA00E8 */  ldc1      $f26, 0xe8($sp)
/* 3CD650 E00C6C70 D7B800E0 */  ldc1      $f24, 0xe0($sp)
/* 3CD654 E00C6C74 D7B600D8 */  ldc1      $f22, 0xd8($sp)
/* 3CD658 E00C6C78 D7B400D0 */  ldc1      $f20, 0xd0($sp)
/* 3CD65C E00C6C7C 03E00008 */  jr        $ra
/* 3CD660 E00C6C80 27BD0100 */   addiu    $sp, $sp, 0x100
/* 3CD664 E00C6C84 00000000 */  nop
/* 3CD668 E00C6C88 00000000 */  nop
/* 3CD66C E00C6C8C 00000000 */  nop
