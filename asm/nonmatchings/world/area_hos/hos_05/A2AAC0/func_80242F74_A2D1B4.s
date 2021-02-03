.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F74_A2D1B4
/* A2D1B4 80242F74 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A2D1B8 80242F78 AFB1001C */  sw        $s1, 0x1c($sp)
/* A2D1BC 80242F7C 3C118025 */  lui       $s1, %hi(D_8024A9C8_A34C08)
/* A2D1C0 80242F80 2631A9C8 */  addiu     $s1, $s1, %lo(D_8024A9C8_A34C08)
/* A2D1C4 80242F84 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* A2D1C8 80242F88 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* A2D1CC 80242F8C 3C018025 */  lui       $at, %hi(D_8024987C_A33ABC)
/* A2D1D0 80242F90 C42C987C */  lwc1      $f12, %lo(D_8024987C_A33ABC)($at)
/* A2D1D4 80242F94 3C018025 */  lui       $at, %hi(D_802498A8_A33AE8)
/* A2D1D8 80242F98 C42E98A8 */  lwc1      $f14, %lo(D_802498A8_A33AE8)($at)
/* A2D1DC 80242F9C 3C03800B */  lui       $v1, %hi(gCameras)
/* A2D1E0 80242FA0 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* A2D1E4 80242FA4 AFBF0020 */  sw        $ra, 0x20($sp)
/* A2D1E8 80242FA8 AFB00018 */  sw        $s0, 0x18($sp)
/* A2D1EC 80242FAC AFB10010 */  sw        $s1, 0x10($sp)
/* A2D1F0 80242FB0 8E260000 */  lw        $a2, ($s1)
/* A2D1F4 80242FB4 3C073F80 */  lui       $a3, 0x3f80
/* A2D1F8 80242FB8 00028080 */  sll       $s0, $v0, 2
/* A2D1FC 80242FBC 02028021 */  addu      $s0, $s0, $v0
/* A2D200 80242FC0 00108080 */  sll       $s0, $s0, 2
/* A2D204 80242FC4 02028023 */  subu      $s0, $s0, $v0
/* A2D208 80242FC8 001010C0 */  sll       $v0, $s0, 3
/* A2D20C 80242FCC 02028021 */  addu      $s0, $s0, $v0
/* A2D210 80242FD0 001080C0 */  sll       $s0, $s0, 3
/* A2D214 80242FD4 0C090411 */  jal       func_80241044_A2B284
/* A2D218 80242FD8 02038021 */   addu     $s0, $s0, $v1
/* A2D21C 80242FDC 24020001 */  addiu     $v0, $zero, 1
/* A2D220 80242FE0 C6200000 */  lwc1      $f0, ($s1)
/* A2D224 80242FE4 3C01442F */  lui       $at, 0x442f
/* A2D228 80242FE8 44811000 */  mtc1      $at, $f2
/* A2D22C 80242FEC 0040182D */  daddu     $v1, $v0, $zero
/* A2D230 80242FF0 A6030506 */  sh        $v1, 0x506($s0)
/* A2D234 80242FF4 46020032 */  c.eq.s    $f0, $f2
/* A2D238 80242FF8 00000000 */  nop
/* A2D23C 80242FFC 45010002 */  bc1t      .L80243008
/* A2D240 80243000 E60004DC */   swc1     $f0, 0x4dc($s0)
/* A2D244 80243004 0000102D */  daddu     $v0, $zero, $zero
.L80243008:
/* A2D248 80243008 8FBF0020 */  lw        $ra, 0x20($sp)
/* A2D24C 8024300C 8FB1001C */  lw        $s1, 0x1c($sp)
/* A2D250 80243010 8FB00018 */  lw        $s0, 0x18($sp)
/* A2D254 80243014 03E00008 */  jr        $ra
/* A2D258 80243018 27BD0028 */   addiu    $sp, $sp, 0x28
