.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E001C30C
/* 330C1C E001C30C 27BDFE70 */  addiu     $sp, $sp, -0x190
/* 330C20 E001C310 0080302D */  daddu     $a2, $a0, $zero
/* 330C24 E001C314 3C07DB06 */  lui       $a3, 0xdb06
/* 330C28 E001C318 34E70024 */  ori       $a3, $a3, 0x24
/* 330C2C E001C31C 27A40018 */  addiu     $a0, $sp, 0x18
/* 330C30 E001C320 AFB70174 */  sw        $s7, 0x174($sp)
/* 330C34 E001C324 3C170001 */  lui       $s7, 1
/* 330C38 E001C328 AFB1015C */  sw        $s1, 0x15c($sp)
/* 330C3C E001C32C 3C11800A */  lui       $s1, %hi(gMasterGfxPos)
/* 330C40 E001C330 2631A66C */  addiu     $s1, $s1, %lo(gMasterGfxPos)
/* 330C44 E001C334 AFBF017C */  sw        $ra, 0x17c($sp)
/* 330C48 E001C338 AFBE0178 */  sw        $fp, 0x178($sp)
/* 330C4C E001C33C AFB60170 */  sw        $s6, 0x170($sp)
/* 330C50 E001C340 AFB5016C */  sw        $s5, 0x16c($sp)
/* 330C54 E001C344 AFB40168 */  sw        $s4, 0x168($sp)
/* 330C58 E001C348 AFB30164 */  sw        $s3, 0x164($sp)
/* 330C5C E001C34C AFB20160 */  sw        $s2, 0x160($sp)
/* 330C60 E001C350 AFB00158 */  sw        $s0, 0x158($sp)
/* 330C64 E001C354 F7B60188 */  sdc1      $f22, 0x188($sp)
/* 330C68 E001C358 F7B40180 */  sdc1      $f20, 0x180($sp)
/* 330C6C E001C35C 8E230000 */  lw        $v1, ($s1)
/* 330C70 E001C360 36F71630 */  ori       $s7, $s7, 0x1630
/* 330C74 E001C364 0060282D */  daddu     $a1, $v1, $zero
/* 330C78 E001C368 24630008 */  addiu     $v1, $v1, 8
/* 330C7C E001C36C AE230000 */  sw        $v1, ($s1)
/* 330C80 E001C370 8CD6000C */  lw        $s6, 0xc($a2)
/* 330C84 E001C374 3C02E700 */  lui       $v0, 0xe700
/* 330C88 E001C378 ACA20000 */  sw        $v0, ($a1)
/* 330C8C E001C37C ACA00004 */  sw        $zero, 4($a1)
/* 330C90 E001C380 AC670000 */  sw        $a3, ($v1)
/* 330C94 E001C384 8CC50010 */  lw        $a1, 0x10($a2)
/* 330C98 E001C388 24620008 */  addiu     $v0, $v1, 8
/* 330C9C E001C38C AE220000 */  sw        $v0, ($s1)
/* 330CA0 E001C390 3C020900 */  lui       $v0, 0x900
/* 330CA4 E001C394 24420900 */  addiu     $v0, $v0, 0x900
/* 330CA8 E001C398 8CA5001C */  lw        $a1, 0x1c($a1)
/* 330CAC E001C39C 3C0ADE00 */  lui       $t2, 0xde00
/* 330CB0 E001C3A0 AC62000C */  sw        $v0, 0xc($v1)
/* 330CB4 E001C3A4 3C028000 */  lui       $v0, 0x8000
/* 330CB8 E001C3A8 AC6A0008 */  sw        $t2, 8($v1)
/* 330CBC E001C3AC 00A22821 */  addu      $a1, $a1, $v0
/* 330CC0 E001C3B0 AC650004 */  sw        $a1, 4($v1)
/* 330CC4 E001C3B4 8EC50000 */  lw        $a1, ($s6)
/* 330CC8 E001C3B8 8EC60004 */  lw        $a2, 4($s6)
/* 330CCC E001C3BC 8EC70008 */  lw        $a3, 8($s6)
/* 330CD0 E001C3C0 24630010 */  addiu     $v1, $v1, 0x10
/* 330CD4 E001C3C4 0C080108 */  jal       shim_guTranslateF
/* 330CD8 E001C3C8 AE230000 */   sw       $v1, ($s1)
/* 330CDC E001C3CC 27B000D8 */  addiu     $s0, $sp, 0xd8
/* 330CE0 E001C3D0 4480A000 */  mtc1      $zero, $f20
/* 330CE4 E001C3D4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 330CE8 E001C3D8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 330CEC E001C3DC 3C013F80 */  lui       $at, 0x3f80
/* 330CF0 E001C3E0 4481B000 */  mtc1      $at, $f22
/* 330CF4 E001C3E4 00031080 */  sll       $v0, $v1, 2
/* 330CF8 E001C3E8 00431021 */  addu      $v0, $v0, $v1
/* 330CFC E001C3EC 00021080 */  sll       $v0, $v0, 2
/* 330D00 E001C3F0 00431023 */  subu      $v0, $v0, $v1
/* 330D04 E001C3F4 000218C0 */  sll       $v1, $v0, 3
/* 330D08 E001C3F8 00431021 */  addu      $v0, $v0, $v1
/* 330D0C E001C3FC 000210C0 */  sll       $v0, $v0, 3
/* 330D10 E001C400 4406A000 */  mfc1      $a2, $f20
/* 330D14 E001C404 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 330D18 E001C408 00220821 */  addu      $at, $at, $v0
/* 330D1C E001C40C C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 330D20 E001C410 4407B000 */  mfc1      $a3, $f22
/* 330D24 E001C414 46000007 */  neg.s     $f0, $f0
/* 330D28 E001C418 44050000 */  mfc1      $a1, $f0
/* 330D2C E001C41C 0200202D */  daddu     $a0, $s0, $zero
/* 330D30 E001C420 0C080104 */  jal       shim_guRotateF
/* 330D34 E001C424 E7B40010 */   swc1     $f20, 0x10($sp)
/* 330D38 E001C428 0200202D */  daddu     $a0, $s0, $zero
/* 330D3C E001C42C 27A50018 */  addiu     $a1, $sp, 0x18
/* 330D40 E001C430 27B40118 */  addiu     $s4, $sp, 0x118
/* 330D44 E001C434 0C080114 */  jal       shim_guMtxCatF
/* 330D48 E001C438 0280302D */   daddu    $a2, $s4, $zero
/* 330D4C E001C43C 0280202D */  daddu     $a0, $s4, $zero
/* 330D50 E001C440 3C128007 */  lui       $s2, %hi(gMatrixListPos)
/* 330D54 E001C444 265241F0 */  addiu     $s2, $s2, %lo(gMatrixListPos)
/* 330D58 E001C448 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 330D5C E001C44C 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 330D60 E001C450 96450000 */  lhu       $a1, ($s2)
/* 330D64 E001C454 8EA20000 */  lw        $v0, ($s5)
/* 330D68 E001C458 00052980 */  sll       $a1, $a1, 6
/* 330D6C E001C45C 00B72821 */  addu      $a1, $a1, $s7
/* 330D70 E001C460 0C080118 */  jal       shim_guMtxF2L
/* 330D74 E001C464 00452821 */   addu     $a1, $v0, $a1
/* 330D78 E001C468 3C1EDA38 */  lui       $fp, 0xda38
/* 330D7C E001C46C 27B30058 */  addiu     $s3, $sp, 0x58
/* 330D80 E001C470 8E280000 */  lw        $t0, ($s1)
/* 330D84 E001C474 4406B000 */  mfc1      $a2, $f22
/* 330D88 E001C478 4407A000 */  mfc1      $a3, $f20
/* 330D8C E001C47C 96490000 */  lhu       $t1, ($s2)
/* 330D90 E001C480 0100202D */  daddu     $a0, $t0, $zero
/* 330D94 E001C484 25080008 */  addiu     $t0, $t0, 8
/* 330D98 E001C488 3122FFFF */  andi      $v0, $t1, 0xffff
/* 330D9C E001C48C 00021180 */  sll       $v0, $v0, 6
/* 330DA0 E001C490 00571021 */  addu      $v0, $v0, $s7
/* 330DA4 E001C494 AC9E0000 */  sw        $fp, ($a0)
/* 330DA8 E001C498 8EA30000 */  lw        $v1, ($s5)
/* 330DAC E001C49C 25290001 */  addiu     $t1, $t1, 1
/* 330DB0 E001C4A0 00621821 */  addu      $v1, $v1, $v0
/* 330DB4 E001C4A4 3C02FA00 */  lui       $v0, 0xfa00
/* 330DB8 E001C4A8 AC830004 */  sw        $v1, 4($a0)
/* 330DBC E001C4AC AD020000 */  sw        $v0, ($t0)
/* 330DC0 E001C4B0 240200FF */  addiu     $v0, $zero, 0xff
/* 330DC4 E001C4B4 AD020004 */  sw        $v0, 4($t0)
/* 330DC8 E001C4B8 E7B40010 */  swc1      $f20, 0x10($sp)
/* 330DCC E001C4BC 8EC50018 */  lw        $a1, 0x18($s6)
/* 330DD0 E001C4C0 0260202D */  daddu     $a0, $s3, $zero
/* 330DD4 E001C4C4 AE280000 */  sw        $t0, ($s1)
/* 330DD8 E001C4C8 25080008 */  addiu     $t0, $t0, 8
/* 330DDC E001C4CC A6490000 */  sh        $t1, ($s2)
/* 330DE0 E001C4D0 0C080104 */  jal       shim_guRotateF
/* 330DE4 E001C4D4 AE280000 */   sw       $t0, ($s1)
/* 330DE8 E001C4D8 27B00098 */  addiu     $s0, $sp, 0x98
/* 330DEC E001C4DC E7B40010 */  swc1      $f20, 0x10($sp)
/* 330DF0 E001C4E0 8EC5001C */  lw        $a1, 0x1c($s6)
/* 330DF4 E001C4E4 4406A000 */  mfc1      $a2, $f20
/* 330DF8 E001C4E8 4407B000 */  mfc1      $a3, $f22
/* 330DFC E001C4EC 0C080104 */  jal       shim_guRotateF
/* 330E00 E001C4F0 0200202D */   daddu    $a0, $s0, $zero
/* 330E04 E001C4F4 0260202D */  daddu     $a0, $s3, $zero
/* 330E08 E001C4F8 0200282D */  daddu     $a1, $s0, $zero
/* 330E0C E001C4FC 0C080114 */  jal       shim_guMtxCatF
/* 330E10 E001C500 0280302D */   daddu    $a2, $s4, $zero
/* 330E14 E001C504 0280202D */  daddu     $a0, $s4, $zero
/* 330E18 E001C508 96450000 */  lhu       $a1, ($s2)
/* 330E1C E001C50C 8EA20000 */  lw        $v0, ($s5)
/* 330E20 E001C510 00052980 */  sll       $a1, $a1, 6
/* 330E24 E001C514 00B72821 */  addu      $a1, $a1, $s7
/* 330E28 E001C518 0C080118 */  jal       shim_guMtxF2L
/* 330E2C E001C51C 00452821 */   addu     $a1, $v0, $a1
/* 330E30 E001C520 3C06D838 */  lui       $a2, 0xd838
/* 330E34 E001C524 34C60002 */  ori       $a2, $a2, 2
/* 330E38 E001C528 8E240000 */  lw        $a0, ($s1)
/* 330E3C E001C52C 96420000 */  lhu       $v0, ($s2)
/* 330E40 E001C530 0080282D */  daddu     $a1, $a0, $zero
/* 330E44 E001C534 24840008 */  addiu     $a0, $a0, 8
/* 330E48 E001C538 24430001 */  addiu     $v1, $v0, 1
/* 330E4C E001C53C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 330E50 E001C540 00021180 */  sll       $v0, $v0, 6
/* 330E54 E001C544 AE240000 */  sw        $a0, ($s1)
/* 330E58 E001C548 ACBE0000 */  sw        $fp, ($a1)
/* 330E5C E001C54C A6430000 */  sh        $v1, ($s2)
/* 330E60 E001C550 8EA30000 */  lw        $v1, ($s5)
/* 330E64 E001C554 00571021 */  addu      $v0, $v0, $s7
/* 330E68 E001C558 00621821 */  addu      $v1, $v1, $v0
/* 330E6C E001C55C 24820008 */  addiu     $v0, $a0, 8
/* 330E70 E001C560 ACA30004 */  sw        $v1, 4($a1)
/* 330E74 E001C564 3C0ADE00 */  lui       $t2, 0xde00
/* 330E78 E001C568 AE220000 */  sw        $v0, ($s1)
/* 330E7C E001C56C 3C020900 */  lui       $v0, 0x900
/* 330E80 E001C570 244209E8 */  addiu     $v0, $v0, 0x9e8
/* 330E84 E001C574 AC820004 */  sw        $v0, 4($a0)
/* 330E88 E001C578 24820010 */  addiu     $v0, $a0, 0x10
/* 330E8C E001C57C 24030040 */  addiu     $v1, $zero, 0x40
/* 330E90 E001C580 AC8A0000 */  sw        $t2, ($a0)
/* 330E94 E001C584 AE220000 */  sw        $v0, ($s1)
/* 330E98 E001C588 24820018 */  addiu     $v0, $a0, 0x18
/* 330E9C E001C58C AC860008 */  sw        $a2, 8($a0)
/* 330EA0 E001C590 AC83000C */  sw        $v1, 0xc($a0)
/* 330EA4 E001C594 AE220000 */  sw        $v0, ($s1)
/* 330EA8 E001C598 AC860010 */  sw        $a2, 0x10($a0)
/* 330EAC E001C59C AC830014 */  sw        $v1, 0x14($a0)
/* 330EB0 E001C5A0 8FBF017C */  lw        $ra, 0x17c($sp)
/* 330EB4 E001C5A4 8FBE0178 */  lw        $fp, 0x178($sp)
/* 330EB8 E001C5A8 8FB70174 */  lw        $s7, 0x174($sp)
/* 330EBC E001C5AC 8FB60170 */  lw        $s6, 0x170($sp)
/* 330EC0 E001C5B0 8FB5016C */  lw        $s5, 0x16c($sp)
/* 330EC4 E001C5B4 8FB40168 */  lw        $s4, 0x168($sp)
/* 330EC8 E001C5B8 8FB30164 */  lw        $s3, 0x164($sp)
/* 330ECC E001C5BC 8FB20160 */  lw        $s2, 0x160($sp)
/* 330ED0 E001C5C0 8FB1015C */  lw        $s1, 0x15c($sp)
/* 330ED4 E001C5C4 8FB00158 */  lw        $s0, 0x158($sp)
/* 330ED8 E001C5C8 D7B60188 */  ldc1      $f22, 0x188($sp)
/* 330EDC E001C5CC D7B40180 */  ldc1      $f20, 0x180($sp)
/* 330EE0 E001C5D0 03E00008 */  jr        $ra
/* 330EE4 E001C5D4 27BD0190 */   addiu    $sp, $sp, 0x190
/* 330EE8 E001C5D8 00000000 */  nop
/* 330EEC E001C5DC 00000000 */  nop
