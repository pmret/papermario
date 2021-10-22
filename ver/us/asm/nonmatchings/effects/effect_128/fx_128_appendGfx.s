.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_128_appendGfx
/* 406D04 E011C1C4 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 406D08 E011C1C8 0080302D */  daddu     $a2, $a0, $zero
/* 406D0C E011C1CC 3C07DB06 */  lui       $a3, 0xdb06
/* 406D10 E011C1D0 34E70024 */  ori       $a3, $a3, 0x24
/* 406D14 E011C1D4 27A40018 */  addiu     $a0, $sp, 0x18
/* 406D18 E011C1D8 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 406D1C E011C1DC 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* 406D20 E011C1E0 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* 406D24 E011C1E4 AFB500AC */  sw        $s5, 0xac($sp)
/* 406D28 E011C1E8 AFBF00B4 */  sw        $ra, 0xb4($sp)
/* 406D2C E011C1EC AFB600B0 */  sw        $s6, 0xb0($sp)
/* 406D30 E011C1F0 AFB400A8 */  sw        $s4, 0xa8($sp)
/* 406D34 E011C1F4 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 406D38 E011C1F8 AFB1009C */  sw        $s1, 0x9c($sp)
/* 406D3C E011C1FC AFB00098 */  sw        $s0, 0x98($sp)
/* 406D40 E011C200 F7B400B8 */  sdc1      $f20, 0xb8($sp)
/* 406D44 E011C204 8E450000 */  lw        $a1, ($s2)
/* 406D48 E011C208 8CD4000C */  lw        $s4, 0xc($a2)
/* 406D4C E011C20C 00A0182D */  daddu     $v1, $a1, $zero
/* 406D50 E011C210 24A50008 */  addiu     $a1, $a1, 8
/* 406D54 E011C214 AE450000 */  sw        $a1, ($s2)
/* 406D58 E011C218 8E960014 */  lw        $s6, 0x14($s4)
/* 406D5C E011C21C 8E910018 */  lw        $s1, 0x18($s4)
/* 406D60 E011C220 3C02E700 */  lui       $v0, 0xe700
/* 406D64 E011C224 AC620000 */  sw        $v0, ($v1)
/* 406D68 E011C228 AC600004 */  sw        $zero, 4($v1)
/* 406D6C E011C22C ACA70000 */  sw        $a3, ($a1)
/* 406D70 E011C230 8CC30010 */  lw        $v1, 0x10($a2)
/* 406D74 E011C234 24A20008 */  addiu     $v0, $a1, 8
/* 406D78 E011C238 AE420000 */  sw        $v0, ($s2)
/* 406D7C E011C23C 8C62001C */  lw        $v0, 0x1c($v1)
/* 406D80 E011C240 3C038000 */  lui       $v1, 0x8000
/* 406D84 E011C244 00431021 */  addu      $v0, $v0, $v1
/* 406D88 E011C248 ACA20004 */  sw        $v0, 4($a1)
/* 406D8C E011C24C 8E850004 */  lw        $a1, 4($s4)
/* 406D90 E011C250 8E860008 */  lw        $a2, 8($s4)
/* 406D94 E011C254 8E87000C */  lw        $a3, 0xc($s4)
/* 406D98 E011C258 4480A000 */  mtc1      $zero, $f20
/* 406D9C E011C25C 0C080108 */  jal       shim_guTranslateF
/* 406DA0 E011C260 3C150001 */   lui      $s5, 1
/* 406DA4 E011C264 27B00058 */  addiu     $s0, $sp, 0x58
/* 406DA8 E011C268 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 406DAC E011C26C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 406DB0 E011C270 4406A000 */  mfc1      $a2, $f20
/* 406DB4 E011C274 00031080 */  sll       $v0, $v1, 2
/* 406DB8 E011C278 00431021 */  addu      $v0, $v0, $v1
/* 406DBC E011C27C 00021080 */  sll       $v0, $v0, 2
/* 406DC0 E011C280 00431023 */  subu      $v0, $v0, $v1
/* 406DC4 E011C284 000218C0 */  sll       $v1, $v0, 3
/* 406DC8 E011C288 00431021 */  addu      $v0, $v0, $v1
/* 406DCC E011C28C 000210C0 */  sll       $v0, $v0, 3
/* 406DD0 E011C290 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 406DD4 E011C294 00220821 */  addu      $at, $at, $v0
/* 406DD8 E011C298 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 406DDC E011C29C 3C073F80 */  lui       $a3, 0x3f80
/* 406DE0 E011C2A0 46000007 */  neg.s     $f0, $f0
/* 406DE4 E011C2A4 44050000 */  mfc1      $a1, $f0
/* 406DE8 E011C2A8 0200202D */  daddu     $a0, $s0, $zero
/* 406DEC E011C2AC 0C080104 */  jal       shim_guRotateF
/* 406DF0 E011C2B0 E7B40010 */   swc1     $f20, 0x10($sp)
/* 406DF4 E011C2B4 0200202D */  daddu     $a0, $s0, $zero
/* 406DF8 E011C2B8 27A50018 */  addiu     $a1, $sp, 0x18
/* 406DFC E011C2BC 0C080114 */  jal       shim_guMtxCatF
/* 406E00 E011C2C0 00A0302D */   daddu    $a2, $a1, $zero
/* 406E04 E011C2C4 3C0542B3 */  lui       $a1, 0x42b3
/* 406E08 E011C2C8 4406A000 */  mfc1      $a2, $f20
/* 406E0C E011C2CC 3C074000 */  lui       $a3, 0x4000
/* 406E10 E011C2D0 0C080108 */  jal       shim_guTranslateF
/* 406E14 E011C2D4 0200202D */   daddu    $a0, $s0, $zero
/* 406E18 E011C2D8 0200202D */  daddu     $a0, $s0, $zero
/* 406E1C E011C2DC 27A50018 */  addiu     $a1, $sp, 0x18
/* 406E20 E011C2E0 0C080114 */  jal       shim_guMtxCatF
/* 406E24 E011C2E4 00A0302D */   daddu    $a2, $a1, $zero
/* 406E28 E011C2E8 3C013F36 */  lui       $at, 0x3f36
/* 406E2C E011C2EC 3421DB6E */  ori       $at, $at, 0xdb6e
/* 406E30 E011C2F0 44810000 */  mtc1      $at, $f0
/* 406E34 E011C2F4 36B51630 */  ori       $s5, $s5, 0x1630
/* 406E38 E011C2F8 44050000 */  mfc1      $a1, $f0
/* 406E3C E011C2FC 0200202D */  daddu     $a0, $s0, $zero
/* 406E40 E011C300 00A0302D */  daddu     $a2, $a1, $zero
/* 406E44 E011C304 0C080110 */  jal       shim_guScaleF
/* 406E48 E011C308 00A0382D */   daddu    $a3, $a1, $zero
/* 406E4C E011C30C 0200202D */  daddu     $a0, $s0, $zero
/* 406E50 E011C310 27A50018 */  addiu     $a1, $sp, 0x18
/* 406E54 E011C314 0C080114 */  jal       shim_guMtxCatF
/* 406E58 E011C318 00A0302D */   daddu    $a2, $a1, $zero
/* 406E5C E011C31C 27A40018 */  addiu     $a0, $sp, 0x18
/* 406E60 E011C320 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 406E64 E011C324 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 406E68 E011C328 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* 406E6C E011C32C 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* 406E70 E011C330 96050000 */  lhu       $a1, ($s0)
/* 406E74 E011C334 8E620000 */  lw        $v0, ($s3)
/* 406E78 E011C338 00052980 */  sll       $a1, $a1, 6
/* 406E7C E011C33C 00B52821 */  addu      $a1, $a1, $s5
/* 406E80 E011C340 0C080118 */  jal       shim_guMtxF2L
/* 406E84 E011C344 00452821 */   addu     $a1, $v0, $a1
/* 406E88 E011C348 3C03DA38 */  lui       $v1, 0xda38
/* 406E8C E011C34C 34630002 */  ori       $v1, $v1, 2
/* 406E90 E011C350 323100FF */  andi      $s1, $s1, 0xff
/* 406E94 E011C354 8E440000 */  lw        $a0, ($s2)
/* 406E98 E011C358 96020000 */  lhu       $v0, ($s0)
/* 406E9C E011C35C 0080282D */  daddu     $a1, $a0, $zero
/* 406EA0 E011C360 24840008 */  addiu     $a0, $a0, 8
/* 406EA4 E011C364 AE440000 */  sw        $a0, ($s2)
/* 406EA8 E011C368 ACA30000 */  sw        $v1, ($a1)
/* 406EAC E011C36C 24430001 */  addiu     $v1, $v0, 1
/* 406EB0 E011C370 3042FFFF */  andi      $v0, $v0, 0xffff
/* 406EB4 E011C374 00021180 */  sll       $v0, $v0, 6
/* 406EB8 E011C378 A6030000 */  sh        $v1, ($s0)
/* 406EBC E011C37C 8E630000 */  lw        $v1, ($s3)
/* 406EC0 E011C380 00551021 */  addu      $v0, $v0, $s5
/* 406EC4 E011C384 00621821 */  addu      $v1, $v1, $v0
/* 406EC8 E011C388 24820008 */  addiu     $v0, $a0, 8
/* 406ECC E011C38C ACA30004 */  sw        $v1, 4($a1)
/* 406ED0 E011C390 AE420000 */  sw        $v0, ($s2)
/* 406ED4 E011C394 3C02FA00 */  lui       $v0, 0xfa00
/* 406ED8 E011C398 AC820000 */  sw        $v0, ($a0)
/* 406EDC E011C39C 00111600 */  sll       $v0, $s1, 0x18
/* 406EE0 E011C3A0 00111C00 */  sll       $v1, $s1, 0x10
/* 406EE4 E011C3A4 00431025 */  or        $v0, $v0, $v1
/* 406EE8 E011C3A8 00118A00 */  sll       $s1, $s1, 8
/* 406EEC E011C3AC 00511025 */  or        $v0, $v0, $s1
/* 406EF0 E011C3B0 344200FF */  ori       $v0, $v0, 0xff
/* 406EF4 E011C3B4 AC820004 */  sw        $v0, 4($a0)
/* 406EF8 E011C3B8 3C02DE00 */  lui       $v0, 0xde00
/* 406EFC E011C3BC AC820008 */  sw        $v0, 8($a0)
/* 406F00 E011C3C0 3C03E012 */  lui       $v1, %hi(D_E011C514)
/* 406F04 E011C3C4 8C63C514 */  lw        $v1, %lo(D_E011C514)($v1)
/* 406F08 E011C3C8 24820010 */  addiu     $v0, $a0, 0x10
/* 406F0C E011C3CC AE420000 */  sw        $v0, ($s2)
/* 406F10 E011C3D0 AC83000C */  sw        $v1, 0xc($a0)
/* 406F14 E011C3D4 8E83001C */  lw        $v1, 0x1c($s4)
/* 406F18 E011C3D8 24020001 */  addiu     $v0, $zero, 1
/* 406F1C E011C3DC 10620007 */  beq       $v1, $v0, .LE011C3FC
/* 406F20 E011C3E0 28620002 */   slti     $v0, $v1, 2
/* 406F24 E011C3E4 10400015 */  beqz      $v0, .LE011C43C
/* 406F28 E011C3E8 00000000 */   nop
/* 406F2C E011C3EC 14600013 */  bnez      $v1, .LE011C43C
/* 406F30 E011C3F0 0000282D */   daddu    $a1, $zero, $zero
/* 406F34 E011C3F4 0804711B */  j         .LE011C46C
/* 406F38 E011C3F8 3C07D838 */   lui      $a3, 0xd838
.LE011C3FC:
/* 406F3C E011C3FC 3C026666 */  lui       $v0, 0x6666
/* 406F40 E011C400 34426667 */  ori       $v0, $v0, 0x6667
/* 406F44 E011C404 02C20018 */  mult      $s6, $v0
/* 406F48 E011C408 001617C3 */  sra       $v0, $s6, 0x1f
/* 406F4C E011C40C 00004010 */  mfhi      $t0
/* 406F50 E011C410 00081843 */  sra       $v1, $t0, 1
/* 406F54 E011C414 00621823 */  subu      $v1, $v1, $v0
/* 406F58 E011C418 00031080 */  sll       $v0, $v1, 2
/* 406F5C E011C41C 00431021 */  addu      $v0, $v0, $v1
/* 406F60 E011C420 02C21023 */  subu      $v0, $s6, $v0
/* 406F64 E011C424 00021080 */  sll       $v0, $v0, 2
/* 406F68 E011C428 3C05E012 */  lui       $a1, %hi(D_E011C518)
/* 406F6C E011C42C 00A22821 */  addu      $a1, $a1, $v0
/* 406F70 E011C430 8CA5C518 */  lw        $a1, %lo(D_E011C518)($a1)
/* 406F74 E011C434 0804711B */  j         .LE011C46C
/* 406F78 E011C438 3C07D838 */   lui      $a3, 0xd838
.LE011C43C:
/* 406F7C E011C43C 06C10002 */  bgez      $s6, .LE011C448
/* 406F80 E011C440 02C0102D */   daddu    $v0, $s6, $zero
/* 406F84 E011C444 26C20003 */  addiu     $v0, $s6, 3
.LE011C448:
/* 406F88 E011C448 00021083 */  sra       $v0, $v0, 2
/* 406F8C E011C44C 00021080 */  sll       $v0, $v0, 2
/* 406F90 E011C450 02C21023 */  subu      $v0, $s6, $v0
/* 406F94 E011C454 00021080 */  sll       $v0, $v0, 2
/* 406F98 E011C458 3C03E012 */  lui       $v1, %hi(D_E011C52C)
/* 406F9C E011C45C 2463C52C */  addiu     $v1, $v1, %lo(D_E011C52C)
/* 406FA0 E011C460 00431021 */  addu      $v0, $v0, $v1
/* 406FA4 E011C464 8C450000 */  lw        $a1, ($v0)
/* 406FA8 E011C468 3C07D838 */  lui       $a3, 0xd838
.LE011C46C:
/* 406FAC E011C46C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 406FB0 E011C470 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 406FB4 E011C474 34E70002 */  ori       $a3, $a3, 2
/* 406FB8 E011C478 8C830000 */  lw        $v1, ($a0)
/* 406FBC E011C47C 3C02DE00 */  lui       $v0, 0xde00
/* 406FC0 E011C480 0060302D */  daddu     $a2, $v1, $zero
/* 406FC4 E011C484 24630008 */  addiu     $v1, $v1, 8
/* 406FC8 E011C488 AC830000 */  sw        $v1, ($a0)
/* 406FCC E011C48C ACC20000 */  sw        $v0, ($a2)
/* 406FD0 E011C490 24620008 */  addiu     $v0, $v1, 8
/* 406FD4 E011C494 AC820000 */  sw        $v0, ($a0)
/* 406FD8 E011C498 00051080 */  sll       $v0, $a1, 2
/* 406FDC E011C49C 3C05E012 */  lui       $a1, %hi(D_E011C500)
/* 406FE0 E011C4A0 00A22821 */  addu      $a1, $a1, $v0
/* 406FE4 E011C4A4 8CA5C500 */  lw        $a1, %lo(D_E011C500)($a1)
/* 406FE8 E011C4A8 24620010 */  addiu     $v0, $v1, 0x10
/* 406FEC E011C4AC AC820000 */  sw        $v0, ($a0)
/* 406FF0 E011C4B0 24020040 */  addiu     $v0, $zero, 0x40
/* 406FF4 E011C4B4 ACC50004 */  sw        $a1, 4($a2)
/* 406FF8 E011C4B8 AC620004 */  sw        $v0, 4($v1)
/* 406FFC E011C4BC 3C02E700 */  lui       $v0, 0xe700
/* 407000 E011C4C0 AC670000 */  sw        $a3, ($v1)
/* 407004 E011C4C4 AC620008 */  sw        $v0, 8($v1)
/* 407008 E011C4C8 AC60000C */  sw        $zero, 0xc($v1)
/* 40700C E011C4CC 8FBF00B4 */  lw        $ra, 0xb4($sp)
/* 407010 E011C4D0 8FB600B0 */  lw        $s6, 0xb0($sp)
/* 407014 E011C4D4 8FB500AC */  lw        $s5, 0xac($sp)
/* 407018 E011C4D8 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 40701C E011C4DC 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 407020 E011C4E0 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 407024 E011C4E4 8FB1009C */  lw        $s1, 0x9c($sp)
/* 407028 E011C4E8 8FB00098 */  lw        $s0, 0x98($sp)
/* 40702C E011C4EC D7B400B8 */  ldc1      $f20, 0xb8($sp)
/* 407030 E011C4F0 03E00008 */  jr        $ra
/* 407034 E011C4F4 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 407038 E011C4F8 00000000 */  nop
/* 40703C E011C4FC 00000000 */  nop
