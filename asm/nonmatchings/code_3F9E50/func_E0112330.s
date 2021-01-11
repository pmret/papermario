.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0112330
/* 3FA180 E0112330 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 3FA184 E0112334 AFB000A0 */  sw        $s0, 0xa0($sp)
/* 3FA188 E0112338 AFBF00AC */  sw        $ra, 0xac($sp)
/* 3FA18C E011233C AFB200A8 */  sw        $s2, 0xa8($sp)
/* 3FA190 E0112340 AFB100A4 */  sw        $s1, 0xa4($sp)
/* 3FA194 E0112344 F7B400B0 */  sdc1      $f20, 0xb0($sp)
/* 3FA198 E0112348 1480000F */  bnez      $a0, .LE0112388
/* 3FA19C E011234C 00A0802D */   daddu    $s0, $a1, $zero
/* 3FA1A0 E0112350 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 3FA1A4 E0112354 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 3FA1A8 E0112358 00021880 */  sll       $v1, $v0, 2
/* 3FA1AC E011235C 00621821 */  addu      $v1, $v1, $v0
/* 3FA1B0 E0112360 00031880 */  sll       $v1, $v1, 2
/* 3FA1B4 E0112364 00621823 */  subu      $v1, $v1, $v0
/* 3FA1B8 E0112368 000310C0 */  sll       $v0, $v1, 3
/* 3FA1BC E011236C 00621821 */  addu      $v1, $v1, $v0
/* 3FA1C0 E0112370 000318C0 */  sll       $v1, $v1, 3
/* 3FA1C4 E0112374 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* 3FA1C8 E0112378 00230821 */  addu      $at, $at, $v1
/* 3FA1CC E011237C C4261DEC */  lwc1      $f6, %lo(D_800B1DEC)($at)
/* 3FA1D0 E0112380 080448E3 */  j         .LE011238C
/* 3FA1D4 E0112384 00000000 */   nop      
.LE0112388:
/* 3FA1D8 E0112388 44803000 */  mtc1      $zero, $f6
.LE011238C:
/* 3FA1DC E011238C C6000018 */  lwc1      $f0, 0x18($s0)
/* 3FA1E0 E0112390 C6040024 */  lwc1      $f4, 0x24($s0)
/* 3FA1E4 E0112394 3C014000 */  lui       $at, 0x4000
/* 3FA1E8 E0112398 44811000 */  mtc1      $at, $f2
/* 3FA1EC E011239C E7A00010 */  swc1      $f0, 0x10($sp)
/* 3FA1F0 E01123A0 C6000004 */  lwc1      $f0, 4($s0)
/* 3FA1F4 E01123A4 4480A000 */  mtc1      $zero, $f20
/* 3FA1F8 E01123A8 46020000 */  add.s     $f0, $f0, $f2
/* 3FA1FC E01123AC 4405A000 */  mfc1      $a1, $f20
/* 3FA200 E01123B0 27A40020 */  addiu     $a0, $sp, 0x20
/* 3FA204 E01123B4 E7A00014 */  swc1      $f0, 0x14($sp)
/* 3FA208 E01123B8 C6000008 */  lwc1      $f0, 8($s0)
/* 3FA20C E01123BC 46062101 */  sub.s     $f4, $f4, $f6
/* 3FA210 E01123C0 E7A00018 */  swc1      $f0, 0x18($sp)
/* 3FA214 E01123C4 C600000C */  lwc1      $f0, 0xc($s0)
/* 3FA218 E01123C8 4407A000 */  mfc1      $a3, $f20
/* 3FA21C E01123CC 46020000 */  add.s     $f0, $f0, $f2
/* 3FA220 E01123D0 44062000 */  mfc1      $a2, $f4
/* 3FA224 E01123D4 3C120001 */  lui       $s2, 1
/* 3FA228 E01123D8 0C080180 */  jal       func_E0200600
/* 3FA22C E01123DC E7A0001C */   swc1     $f0, 0x1c($sp)
/* 3FA230 E01123E0 4406A000 */  mfc1      $a2, $f20
/* 3FA234 E01123E4 4407A000 */  mfc1      $a3, $f20
/* 3FA238 E01123E8 3C013F80 */  lui       $at, 0x3f80
/* 3FA23C E01123EC 44810000 */  mtc1      $at, $f0
/* 3FA240 E01123F0 36521630 */  ori       $s2, $s2, 0x1630
/* 3FA244 E01123F4 E7A00010 */  swc1      $f0, 0x10($sp)
/* 3FA248 E01123F8 8E050020 */  lw        $a1, 0x20($s0)
/* 3FA24C E01123FC 27B00060 */  addiu     $s0, $sp, 0x60
/* 3FA250 E0112400 0C080104 */  jal       func_E0200410
/* 3FA254 E0112404 0200202D */   daddu    $a0, $s0, $zero
/* 3FA258 E0112408 0200202D */  daddu     $a0, $s0, $zero
/* 3FA25C E011240C 27A50020 */  addiu     $a1, $sp, 0x20
/* 3FA260 E0112410 0C080114 */  jal       func_E0200450
/* 3FA264 E0112414 00A0302D */   daddu    $a2, $a1, $zero
/* 3FA268 E0112418 0200202D */  daddu     $a0, $s0, $zero
/* 3FA26C E011241C 4405A000 */  mfc1      $a1, $f20
/* 3FA270 E0112420 3C07C000 */  lui       $a3, 0xc000
/* 3FA274 E0112424 0C080108 */  jal       func_E0200420
/* 3FA278 E0112428 00A0302D */   daddu    $a2, $a1, $zero
/* 3FA27C E011242C 0200202D */  daddu     $a0, $s0, $zero
/* 3FA280 E0112430 27A50020 */  addiu     $a1, $sp, 0x20
/* 3FA284 E0112434 0C080114 */  jal       func_E0200450
/* 3FA288 E0112438 00A0302D */   daddu    $a2, $a1, $zero
/* 3FA28C E011243C 27A40020 */  addiu     $a0, $sp, 0x20
/* 3FA290 E0112440 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 3FA294 E0112444 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 3FA298 E0112448 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* 3FA29C E011244C 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* 3FA2A0 E0112450 96050000 */  lhu       $a1, ($s0)
/* 3FA2A4 E0112454 8E220000 */  lw        $v0, ($s1)
/* 3FA2A8 E0112458 00052980 */  sll       $a1, $a1, 6
/* 3FA2AC E011245C 00B22821 */  addu      $a1, $a1, $s2
/* 3FA2B0 E0112460 0C080118 */  jal       func_E0200460
/* 3FA2B4 E0112464 00452821 */   addu     $a1, $v0, $a1
/* 3FA2B8 E0112468 3C05DA38 */  lui       $a1, 0xda38
/* 3FA2BC E011246C 3C04800A */  lui       $a0, %hi(gMasterGfxPos)
/* 3FA2C0 E0112470 2484A66C */  addiu     $a0, $a0, %lo(gMasterGfxPos)
/* 3FA2C4 E0112474 34A50002 */  ori       $a1, $a1, 2
/* 3FA2C8 E0112478 8C830000 */  lw        $v1, ($a0)
/* 3FA2CC E011247C 96020000 */  lhu       $v0, ($s0)
/* 3FA2D0 E0112480 0060302D */  daddu     $a2, $v1, $zero
/* 3FA2D4 E0112484 24630008 */  addiu     $v1, $v1, 8
/* 3FA2D8 E0112488 AC830000 */  sw        $v1, ($a0)
/* 3FA2DC E011248C 24430001 */  addiu     $v1, $v0, 1
/* 3FA2E0 E0112490 3042FFFF */  andi      $v0, $v0, 0xffff
/* 3FA2E4 E0112494 00021180 */  sll       $v0, $v0, 6
/* 3FA2E8 E0112498 ACC50000 */  sw        $a1, ($a2)
/* 3FA2EC E011249C A6030000 */  sh        $v1, ($s0)
/* 3FA2F0 E01124A0 8E230000 */  lw        $v1, ($s1)
/* 3FA2F4 E01124A4 00521021 */  addu      $v0, $v0, $s2
/* 3FA2F8 E01124A8 00621821 */  addu      $v1, $v1, $v0
/* 3FA2FC E01124AC ACC30004 */  sw        $v1, 4($a2)
/* 3FA300 E01124B0 8FBF00AC */  lw        $ra, 0xac($sp)
/* 3FA304 E01124B4 8FB200A8 */  lw        $s2, 0xa8($sp)
/* 3FA308 E01124B8 8FB100A4 */  lw        $s1, 0xa4($sp)
/* 3FA30C E01124BC 8FB000A0 */  lw        $s0, 0xa0($sp)
/* 3FA310 E01124C0 D7B400B0 */  ldc1      $f20, 0xb0($sp)
/* 3FA314 E01124C4 03E00008 */  jr        $ra
/* 3FA318 E01124C8 27BD00B8 */   addiu    $sp, $sp, 0xb8
