.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_13_appendGfx
/* 330270 E001A440 27BDFF40 */  addiu     $sp, $sp, -0xc0
/* 330274 E001A444 0080382D */  daddu     $a3, $a0, $zero
/* 330278 E001A448 3C08DB06 */  lui       $t0, 0xdb06
/* 33027C E001A44C 35080024 */  ori       $t0, $t0, 0x24
/* 330280 E001A450 AFB400B8 */  sw        $s4, 0xb8($sp)
/* 330284 E001A454 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 330288 E001A458 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 33028C E001A45C 27A40020 */  addiu     $a0, $sp, 0x20
/* 330290 E001A460 3C02E700 */  lui       $v0, 0xe700
/* 330294 E001A464 AFBF00BC */  sw        $ra, 0xbc($sp)
/* 330298 E001A468 AFB300B4 */  sw        $s3, 0xb4($sp)
/* 33029C E001A46C AFB200B0 */  sw        $s2, 0xb0($sp)
/* 3302A0 E001A470 AFB100AC */  sw        $s1, 0xac($sp)
/* 3302A4 E001A474 AFB000A8 */  sw        $s0, 0xa8($sp)
/* 3302A8 E001A478 8E830000 */  lw        $v1, ($s4)
/* 3302AC E001A47C 8CE6000C */  lw        $a2, 0xc($a3)
/* 3302B0 E001A480 0060282D */  daddu     $a1, $v1, $zero
/* 3302B4 E001A484 24630008 */  addiu     $v1, $v1, 8
/* 3302B8 E001A488 ACA20000 */  sw        $v0, ($a1)
/* 3302BC E001A48C ACA00004 */  sw        $zero, 4($a1)
/* 3302C0 E001A490 AC680000 */  sw        $t0, ($v1)
/* 3302C4 E001A494 8CE20010 */  lw        $v0, 0x10($a3)
/* 3302C8 E001A498 3C013F80 */  lui       $at, 0x3f80
/* 3302CC E001A49C 44810000 */  mtc1      $at, $f0
/* 3302D0 E001A4A0 8C42001C */  lw        $v0, 0x1c($v0)
/* 3302D4 E001A4A4 3C058000 */  lui       $a1, 0x8000
/* 3302D8 E001A4A8 00451021 */  addu      $v0, $v0, $a1
/* 3302DC E001A4AC AC620004 */  sw        $v0, 4($v1)
/* 3302E0 E001A4B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3302E4 E001A4B4 C4C00004 */  lwc1      $f0, 4($a2)
/* 3302E8 E001A4B8 3C120001 */  lui       $s2, 1
/* 3302EC E001A4BC E7A00014 */  swc1      $f0, 0x14($sp)
/* 3302F0 E001A4C0 C4C00008 */  lwc1      $f0, 8($a2)
/* 3302F4 E001A4C4 36521630 */  ori       $s2, $s2, 0x1630
/* 3302F8 E001A4C8 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3302FC E001A4CC C4C0000C */  lwc1      $f0, 0xc($a2)
/* 330300 E001A4D0 0000382D */  daddu     $a3, $zero, $zero
/* 330304 E001A4D4 AE830000 */  sw        $v1, ($s4)
/* 330308 E001A4D8 E7A0001C */  swc1      $f0, 0x1c($sp)
/* 33030C E001A4DC 8CC50024 */  lw        $a1, 0x24($a2)
/* 330310 E001A4E0 8CC60028 */  lw        $a2, 0x28($a2)
/* 330314 E001A4E4 24630008 */  addiu     $v1, $v1, 8
/* 330318 E001A4E8 0C080180 */  jal       shim_guPositionF
/* 33031C E001A4EC AE830000 */   sw       $v1, ($s4)
/* 330320 E001A4F0 27A40020 */  addiu     $a0, $sp, 0x20
/* 330324 E001A4F4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 330328 E001A4F8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 33032C E001A4FC 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 330330 E001A500 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 330334 E001A504 96050000 */  lhu       $a1, ($s0)
/* 330338 E001A508 8E220000 */  lw        $v0, ($s1)
/* 33033C E001A50C 00052980 */  sll       $a1, $a1, 6
/* 330340 E001A510 00B22821 */  addu      $a1, $a1, $s2
/* 330344 E001A514 0C080118 */  jal       shim_guMtxF2L
/* 330348 E001A518 00452821 */   addu     $a1, $v0, $a1
/* 33034C E001A51C 8E820000 */  lw        $v0, ($s4)
/* 330350 E001A520 241300FF */  addiu     $s3, $zero, 0xff
/* 330354 E001A524 A3B300A1 */  sb        $s3, 0xa1($sp)
/* 330358 E001A528 0040282D */  daddu     $a1, $v0, $zero
/* 33035C E001A52C 24420008 */  addiu     $v0, $v0, 8
/* 330360 E001A530 AE820000 */  sw        $v0, ($s4)
/* 330364 E001A534 96020000 */  lhu       $v0, ($s0)
/* 330368 E001A538 3C03DA38 */  lui       $v1, 0xda38
/* 33036C E001A53C ACA30000 */  sw        $v1, ($a1)
/* 330370 E001A540 24430001 */  addiu     $v1, $v0, 1
/* 330374 E001A544 3042FFFF */  andi      $v0, $v0, 0xffff
/* 330378 E001A548 00021180 */  sll       $v0, $v0, 6
/* 33037C E001A54C 00521021 */  addu      $v0, $v0, $s2
/* 330380 E001A550 A6030000 */  sh        $v1, ($s0)
/* 330384 E001A554 8E230000 */  lw        $v1, ($s1)
/* 330388 E001A558 3C048015 */  lui       $a0, %hi(D_801512F0)
/* 33038C E001A55C 8C8412F0 */  lw        $a0, %lo(D_801512F0)($a0)
/* 330390 E001A560 00621821 */  addu      $v1, $v1, $v0
/* 330394 E001A564 ACA30004 */  sw        $v1, 4($a1)
/* 330398 E001A568 90830000 */  lbu       $v1, ($a0)
/* 33039C E001A56C 24020001 */  addiu     $v0, $zero, 1
/* 3303A0 E001A570 14620007 */  bne       $v1, $v0, .LE001A590
/* 3303A4 E001A574 27A400A0 */   addiu    $a0, $sp, 0xa0
/* 3303A8 E001A578 0080282D */  daddu     $a1, $a0, $zero
/* 3303AC E001A57C 0080302D */  daddu     $a2, $a0, $zero
/* 3303B0 E001A580 0C08019C */  jal       shim_get_background_color_blend
/* 3303B4 E001A584 27A700A1 */   addiu    $a3, $sp, 0xa1
/* 3303B8 E001A588 93A200A1 */  lbu       $v0, 0xa1($sp)
/* 3303BC E001A58C 02629823 */  subu      $s3, $s3, $v0
.LE001A590:
/* 3303C0 E001A590 12600016 */  beqz      $s3, .LE001A5EC
/* 3303C4 E001A594 3C05D838 */   lui      $a1, 0xd838
/* 3303C8 E001A598 34A50002 */  ori       $a1, $a1, 2
/* 3303CC E001A59C 8E830000 */  lw        $v1, ($s4)
/* 3303D0 E001A5A0 3C02FA00 */  lui       $v0, 0xfa00
/* 3303D4 E001A5A4 0060202D */  daddu     $a0, $v1, $zero
/* 3303D8 E001A5A8 24630008 */  addiu     $v1, $v1, 8
/* 3303DC E001A5AC AE830000 */  sw        $v1, ($s4)
/* 3303E0 E001A5B0 AC820000 */  sw        $v0, ($a0)
/* 3303E4 E001A5B4 326200FF */  andi      $v0, $s3, 0xff
/* 3303E8 E001A5B8 AC820004 */  sw        $v0, 4($a0)
/* 3303EC E001A5BC 24620008 */  addiu     $v0, $v1, 8
/* 3303F0 E001A5C0 AE820000 */  sw        $v0, ($s4)
/* 3303F4 E001A5C4 3C02DE00 */  lui       $v0, 0xde00
/* 3303F8 E001A5C8 AC620000 */  sw        $v0, ($v1)
/* 3303FC E001A5CC 3C020900 */  lui       $v0, 0x900
/* 330400 E001A5D0 244202F0 */  addiu     $v0, $v0, 0x2f0
/* 330404 E001A5D4 AC620004 */  sw        $v0, 4($v1)
/* 330408 E001A5D8 24620010 */  addiu     $v0, $v1, 0x10
/* 33040C E001A5DC AE820000 */  sw        $v0, ($s4)
/* 330410 E001A5E0 24020040 */  addiu     $v0, $zero, 0x40
/* 330414 E001A5E4 AC650008 */  sw        $a1, 8($v1)
/* 330418 E001A5E8 AC62000C */  sw        $v0, 0xc($v1)
.LE001A5EC:
/* 33041C E001A5EC 8FBF00BC */  lw        $ra, 0xbc($sp)
/* 330420 E001A5F0 8FB400B8 */  lw        $s4, 0xb8($sp)
/* 330424 E001A5F4 8FB300B4 */  lw        $s3, 0xb4($sp)
/* 330428 E001A5F8 8FB200B0 */  lw        $s2, 0xb0($sp)
/* 33042C E001A5FC 8FB100AC */  lw        $s1, 0xac($sp)
/* 330430 E001A600 8FB000A8 */  lw        $s0, 0xa8($sp)
/* 330434 E001A604 03E00008 */  jr        $ra
/* 330438 E001A608 27BD00C0 */   addiu    $sp, $sp, 0xc0
/* 33043C E001A60C 00000000 */  nop
