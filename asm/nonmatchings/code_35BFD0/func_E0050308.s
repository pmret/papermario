.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0050308
/* 35C2D8 E0050308 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 35C2DC E005030C 0080282D */  daddu     $a1, $a0, $zero
/* 35C2E0 E0050310 3C06DB06 */  lui       $a2, 0xdb06
/* 35C2E4 E0050314 34C60024 */  ori       $a2, $a2, 0x24
/* 35C2E8 E0050318 27A40018 */  addiu     $a0, $sp, 0x18
/* 35C2EC E005031C AFB400A8 */  sw        $s4, 0xa8($sp)
/* 35C2F0 E0050320 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 35C2F4 E0050324 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 35C2F8 E0050328 AFB200A0 */  sw        $s2, 0xa0($sp)
/* 35C2FC E005032C 3C120001 */  lui       $s2, 1
/* 35C300 E0050330 3C02E700 */  lui       $v0, 0xe700
/* 35C304 E0050334 AFBF00AC */  sw        $ra, 0xac($sp)
/* 35C308 E0050338 AFB300A4 */  sw        $s3, 0xa4($sp)
/* 35C30C E005033C AFB1009C */  sw        $s1, 0x9c($sp)
/* 35C310 E0050340 AFB00098 */  sw        $s0, 0x98($sp)
/* 35C314 E0050344 F7B600B8 */  sdc1      $f22, 0xb8($sp)
/* 35C318 E0050348 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 35C31C E005034C 8E880000 */  lw        $t0, ($s4)
/* 35C320 E0050350 8CB3000C */  lw        $s3, 0xc($a1)
/* 35C324 E0050354 0100182D */  daddu     $v1, $t0, $zero
/* 35C328 E0050358 25080008 */  addiu     $t0, $t0, 8
/* 35C32C E005035C AC620000 */  sw        $v0, ($v1)
/* 35C330 E0050360 AC600004 */  sw        $zero, 4($v1)
/* 35C334 E0050364 AD060000 */  sw        $a2, ($t0)
/* 35C338 E0050368 8CA20010 */  lw        $v0, 0x10($a1)
/* 35C33C E005036C 36521630 */  ori       $s2, $s2, 0x1630
/* 35C340 E0050370 AE880000 */  sw        $t0, ($s4)
/* 35C344 E0050374 8C42001C */  lw        $v0, 0x1c($v0)
/* 35C348 E0050378 3C038000 */  lui       $v1, 0x8000
/* 35C34C E005037C 00431021 */  addu      $v0, $v0, $v1
/* 35C350 E0050380 AD020004 */  sw        $v0, 4($t0)
/* 35C354 E0050384 8E650004 */  lw        $a1, 4($s3)
/* 35C358 E0050388 8E660008 */  lw        $a2, 8($s3)
/* 35C35C E005038C 8E67000C */  lw        $a3, 0xc($s3)
/* 35C360 E0050390 25080008 */  addiu     $t0, $t0, 8
/* 35C364 E0050394 0C080108 */  jal       func_E0200420
/* 35C368 E0050398 AE880000 */   sw       $t0, ($s4)
/* 35C36C E005039C 27B00058 */  addiu     $s0, $sp, 0x58
/* 35C370 E00503A0 4480A000 */  mtc1      $zero, $f20
/* 35C374 E00503A4 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 35C378 E00503A8 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35C37C E00503AC 3C013F80 */  lui       $at, 0x3f80
/* 35C380 E00503B0 4481B000 */  mtc1      $at, $f22
/* 35C384 E00503B4 00031080 */  sll       $v0, $v1, 2
/* 35C388 E00503B8 00431021 */  addu      $v0, $v0, $v1
/* 35C38C E00503BC 00021080 */  sll       $v0, $v0, 2
/* 35C390 E00503C0 00431023 */  subu      $v0, $v0, $v1
/* 35C394 E00503C4 000218C0 */  sll       $v1, $v0, 3
/* 35C398 E00503C8 00431021 */  addu      $v0, $v0, $v1
/* 35C39C E00503CC 000210C0 */  sll       $v0, $v0, 3
/* 35C3A0 E00503D0 4406A000 */  mfc1      $a2, $f20
/* 35C3A4 E00503D4 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 35C3A8 E00503D8 00220821 */  addu      $at, $at, $v0
/* 35C3AC E00503DC C4201DEC */  lwc1      $f0, %lo(D_800B1DEC)($at)
/* 35C3B0 E00503E0 4407B000 */  mfc1      $a3, $f22
/* 35C3B4 E00503E4 46000007 */  neg.s     $f0, $f0
/* 35C3B8 E00503E8 44050000 */  mfc1      $a1, $f0
/* 35C3BC E00503EC 0200202D */  daddu     $a0, $s0, $zero
/* 35C3C0 E00503F0 0C080104 */  jal       func_E0200410
/* 35C3C4 E00503F4 E7B40010 */   swc1     $f20, 0x10($sp)
/* 35C3C8 E00503F8 0200202D */  daddu     $a0, $s0, $zero
/* 35C3CC E00503FC 27A50018 */  addiu     $a1, $sp, 0x18
/* 35C3D0 E0050400 0C080114 */  jal       func_E0200450
/* 35C3D4 E0050404 00A0302D */   daddu    $a2, $a1, $zero
/* 35C3D8 E0050408 E7B60010 */  swc1      $f22, 0x10($sp)
/* 35C3DC E005040C 8E650010 */  lw        $a1, 0x10($s3)
/* 35C3E0 E0050410 4406A000 */  mfc1      $a2, $f20
/* 35C3E4 E0050414 4407A000 */  mfc1      $a3, $f20
/* 35C3E8 E0050418 0C080104 */  jal       func_E0200410
/* 35C3EC E005041C 0200202D */   daddu    $a0, $s0, $zero
/* 35C3F0 E0050420 0200202D */  daddu     $a0, $s0, $zero
/* 35C3F4 E0050424 27A50018 */  addiu     $a1, $sp, 0x18
/* 35C3F8 E0050428 0C080114 */  jal       func_E0200450
/* 35C3FC E005042C 00A0302D */   daddu    $a2, $a1, $zero
/* 35C400 E0050430 27A40018 */  addiu     $a0, $sp, 0x18
/* 35C404 E0050434 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 35C408 E0050438 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 35C40C E005043C 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 35C410 E0050440 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 35C414 E0050444 96050000 */  lhu       $a1, ($s0)
/* 35C418 E0050448 8E220000 */  lw        $v0, ($s1)
/* 35C41C E005044C 00052980 */  sll       $a1, $a1, 6
/* 35C420 E0050450 00B22821 */  addu      $a1, $a1, $s2
/* 35C424 E0050454 0C080118 */  jal       func_E0200460
/* 35C428 E0050458 00452821 */   addu     $a1, $v0, $a1
/* 35C42C E005045C 3C02DA38 */  lui       $v0, 0xda38
/* 35C430 E0050460 34420002 */  ori       $v0, $v0, 2
/* 35C434 E0050464 8E860000 */  lw        $a2, ($s4)
/* 35C438 E0050468 96040000 */  lhu       $a0, ($s0)
/* 35C43C E005046C 00C0282D */  daddu     $a1, $a2, $zero
/* 35C440 E0050470 24C60008 */  addiu     $a2, $a2, 8
/* 35C444 E0050474 AE860000 */  sw        $a2, ($s4)
/* 35C448 E0050478 ACA20000 */  sw        $v0, ($a1)
/* 35C44C E005047C 3082FFFF */  andi      $v0, $a0, 0xffff
/* 35C450 E0050480 00021180 */  sll       $v0, $v0, 6
/* 35C454 E0050484 8E230000 */  lw        $v1, ($s1)
/* 35C458 E0050488 00521021 */  addu      $v0, $v0, $s2
/* 35C45C E005048C 00621821 */  addu      $v1, $v1, $v0
/* 35C460 E0050490 ACA30004 */  sw        $v1, 4($a1)
/* 35C464 E0050494 C6600010 */  lwc1      $f0, 0x10($s3)
/* 35C468 E0050498 24840001 */  addiu     $a0, $a0, 1
/* 35C46C E005049C 4600A03C */  c.lt.s    $f20, $f0
/* 35C470 E00504A0 00000000 */  nop
/* 35C474 E00504A4 4500000D */  bc1f      .LE00504DC
/* 35C478 E00504A8 A6040000 */   sh       $a0, ($s0)
/* 35C47C E00504AC 3C040900 */  lui       $a0, 0x900
/* 35C480 E00504B0 248402C8 */  addiu     $a0, $a0, 0x2c8
/* 35C484 E00504B4 3C02DE00 */  lui       $v0, 0xde00
/* 35C488 E00504B8 ACC20000 */  sw        $v0, ($a2)
/* 35C48C E00504BC 8E630000 */  lw        $v1, ($s3)
/* 35C490 E00504C0 24C20008 */  addiu     $v0, $a2, 8
/* 35C494 E00504C4 1460000F */  bnez      $v1, .LE0050504
/* 35C498 E00504C8 AE820000 */   sw       $v0, ($s4)
/* 35C49C E00504CC 3C040900 */  lui       $a0, 0x900
/* 35C4A0 E00504D0 24840200 */  addiu     $a0, $a0, 0x200
/* 35C4A4 E00504D4 08014142 */  j         .LE0050508
/* 35C4A8 E00504D8 ACC40004 */   sw       $a0, 4($a2)
.LE00504DC:
/* 35C4AC E00504DC 3C040900 */  lui       $a0, 0x900
/* 35C4B0 E00504E0 24840460 */  addiu     $a0, $a0, 0x460
/* 35C4B4 E00504E4 3C02DE00 */  lui       $v0, 0xde00
/* 35C4B8 E00504E8 ACC20000 */  sw        $v0, ($a2)
/* 35C4BC E00504EC 8E630000 */  lw        $v1, ($s3)
/* 35C4C0 E00504F0 24C20008 */  addiu     $v0, $a2, 8
/* 35C4C4 E00504F4 14600003 */  bnez      $v1, .LE0050504
/* 35C4C8 E00504F8 AE820000 */   sw       $v0, ($s4)
/* 35C4CC E00504FC 3C040900 */  lui       $a0, 0x900
/* 35C4D0 E0050500 24840390 */  addiu     $a0, $a0, 0x390
.LE0050504:
/* 35C4D4 E0050504 ACC40004 */  sw        $a0, 4($a2)
.LE0050508:
/* 35C4D8 E0050508 3C05D838 */  lui       $a1, 0xd838
/* 35C4DC E005050C 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 35C4E0 E0050510 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 35C4E4 E0050514 8C620000 */  lw        $v0, ($v1)
/* 35C4E8 E0050518 34A50002 */  ori       $a1, $a1, 2
/* 35C4EC E005051C 0040202D */  daddu     $a0, $v0, $zero
/* 35C4F0 E0050520 24420008 */  addiu     $v0, $v0, 8
/* 35C4F4 E0050524 AC620000 */  sw        $v0, ($v1)
/* 35C4F8 E0050528 24020040 */  addiu     $v0, $zero, 0x40
/* 35C4FC E005052C AC850000 */  sw        $a1, ($a0)
/* 35C500 E0050530 AC820004 */  sw        $v0, 4($a0)
/* 35C504 E0050534 8FBF00AC */  lw        $ra, 0xac($sp)
/* 35C508 E0050538 8FB400A8 */  lw        $s4, 0xa8($sp)
/* 35C50C E005053C 8FB300A4 */  lw        $s3, 0xa4($sp)
/* 35C510 E0050540 8FB200A0 */  lw        $s2, 0xa0($sp)
/* 35C514 E0050544 8FB1009C */  lw        $s1, 0x9c($sp)
/* 35C518 E0050548 8FB00098 */  lw        $s0, 0x98($sp)
/* 35C51C E005054C D7B600B8 */  ldc1      $f22, 0xb8($sp)
/* 35C520 E0050550 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 35C524 E0050554 03E00008 */  jr        $ra
/* 35C528 E0050558 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 35C52C E005055C 00000000 */  nop
