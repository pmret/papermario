.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E01281E0
/* 414D80 E01281E0 27BDFF48 */  addiu     $sp, $sp, -0xb8
/* 414D84 E01281E4 0080302D */  daddu     $a2, $a0, $zero
/* 414D88 E01281E8 3C07DB06 */  lui       $a3, 0xdb06
/* 414D8C E01281EC 34E70024 */  ori       $a3, $a3, 0x24
/* 414D90 E01281F0 27A40010 */  addiu     $a0, $sp, 0x10
/* 414D94 E01281F4 AFB700AC */  sw        $s7, 0xac($sp)
/* 414D98 E01281F8 3C170001 */  lui       $s7, 1
/* 414D9C E01281FC AFB3009C */  sw        $s3, 0x9c($sp)
/* 414DA0 E0128200 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 414DA4 E0128204 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 414DA8 E0128208 36F71630 */  ori       $s7, $s7, 0x1630
/* 414DAC E012820C AFBF00B0 */  sw        $ra, 0xb0($sp)
/* 414DB0 E0128210 AFB600A8 */  sw        $s6, 0xa8($sp)
/* 414DB4 E0128214 AFB500A4 */  sw        $s5, 0xa4($sp)
/* 414DB8 E0128218 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 414DBC E012821C AFB20098 */  sw        $s2, 0x98($sp)
/* 414DC0 E0128220 AFB10094 */  sw        $s1, 0x94($sp)
/* 414DC4 E0128224 AFB00090 */  sw        $s0, 0x90($sp)
/* 414DC8 E0128228 8E650000 */  lw        $a1, ($s3)
/* 414DCC E012822C 8CD2000C */  lw        $s2, 0xc($a2)
/* 414DD0 E0128230 00A0182D */  daddu     $v1, $a1, $zero
/* 414DD4 E0128234 24A50008 */  addiu     $a1, $a1, 8
/* 414DD8 E0128238 AE650000 */  sw        $a1, ($s3)
/* 414DDC E012823C 8E560024 */  lw        $s6, 0x24($s2)
/* 414DE0 E0128240 8E540000 */  lw        $s4, ($s2)
/* 414DE4 E0128244 3C02E700 */  lui       $v0, 0xe700
/* 414DE8 E0128248 AC620000 */  sw        $v0, ($v1)
/* 414DEC E012824C AC600004 */  sw        $zero, 4($v1)
/* 414DF0 E0128250 ACA70000 */  sw        $a3, ($a1)
/* 414DF4 E0128254 8CC30010 */  lw        $v1, 0x10($a2)
/* 414DF8 E0128258 24A20008 */  addiu     $v0, $a1, 8
/* 414DFC E012825C AE620000 */  sw        $v0, ($s3)
/* 414E00 E0128260 8C62001C */  lw        $v0, 0x1c($v1)
/* 414E04 E0128264 3C038000 */  lui       $v1, 0x8000
/* 414E08 E0128268 00431021 */  addu      $v0, $v0, $v1
/* 414E0C E012826C 3C03800B */  lui       $v1, %hi(gCameras)
/* 414E10 E0128270 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 414E14 E0128274 ACA20004 */  sw        $v0, 4($a1)
/* 414E18 E0128278 8E450004 */  lw        $a1, 4($s2)
/* 414E1C E012827C 8E460008 */  lw        $a2, 8($s2)
/* 414E20 E0128280 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 414E24 E0128284 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 414E28 E0128288 8E47000C */  lw        $a3, 0xc($s2)
/* 414E2C E012828C 00028080 */  sll       $s0, $v0, 2
/* 414E30 E0128290 02028021 */  addu      $s0, $s0, $v0
/* 414E34 E0128294 00108080 */  sll       $s0, $s0, 2
/* 414E38 E0128298 02028023 */  subu      $s0, $s0, $v0
/* 414E3C E012829C 001010C0 */  sll       $v0, $s0, 3
/* 414E40 E01282A0 02028021 */  addu      $s0, $s0, $v0
/* 414E44 E01282A4 001080C0 */  sll       $s0, $s0, 3
/* 414E48 E01282A8 0C080108 */  jal       shim_guTranslateF
/* 414E4C E01282AC 02038021 */   addu     $s0, $s0, $v1
/* 414E50 E01282B0 27B10050 */  addiu     $s1, $sp, 0x50
/* 414E54 E01282B4 8E450034 */  lw        $a1, 0x34($s2)
/* 414E58 E01282B8 0220202D */  daddu     $a0, $s1, $zero
/* 414E5C E01282BC 00A0302D */  daddu     $a2, $a1, $zero
/* 414E60 E01282C0 0C080110 */  jal       shim_guScaleF
/* 414E64 E01282C4 00A0382D */   daddu    $a3, $a1, $zero
/* 414E68 E01282C8 0220202D */  daddu     $a0, $s1, $zero
/* 414E6C E01282CC 27A50010 */  addiu     $a1, $sp, 0x10
/* 414E70 E01282D0 0C080114 */  jal       shim_guMtxCatF
/* 414E74 E01282D4 00A0302D */   daddu    $a2, $a1, $zero
/* 414E78 E01282D8 27A40010 */  addiu     $a0, $sp, 0x10
/* 414E7C E01282DC 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 414E80 E01282E0 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 414E84 E01282E4 3C15800A */  lui       $s5, %hi(gDisplayContext)
/* 414E88 E01282E8 26B5A674 */  addiu     $s5, $s5, %lo(gDisplayContext)
/* 414E8C E01282EC 96250000 */  lhu       $a1, ($s1)
/* 414E90 E01282F0 8EA20000 */  lw        $v0, ($s5)
/* 414E94 E01282F4 00052980 */  sll       $a1, $a1, 6
/* 414E98 E01282F8 00B72821 */  addu      $a1, $a1, $s7
/* 414E9C E01282FC 0C080118 */  jal       shim_guMtxF2L
/* 414EA0 E0128300 00452821 */   addu     $a1, $v0, $a1
/* 414EA4 E0128304 3C03DA38 */  lui       $v1, 0xda38
/* 414EA8 E0128308 34630002 */  ori       $v1, $v1, 2
/* 414EAC E012830C 3C06DA38 */  lui       $a2, 0xda38
/* 414EB0 E0128310 34C60001 */  ori       $a2, $a2, 1
/* 414EB4 E0128314 3C082AAA */  lui       $t0, 0x2aaa
/* 414EB8 E0128318 3508AAAB */  ori       $t0, $t0, 0xaaab
/* 414EBC E012831C 3C09D838 */  lui       $t1, 0xd838
/* 414EC0 E0128320 35290002 */  ori       $t1, $t1, 2
/* 414EC4 E0128324 32D600FF */  andi      $s6, $s6, 0xff
/* 414EC8 E0128328 3C07DE00 */  lui       $a3, 0xde00
/* 414ECC E012832C 02880018 */  mult      $s4, $t0
/* 414ED0 E0128330 8E640000 */  lw        $a0, ($s3)
/* 414ED4 E0128334 96220000 */  lhu       $v0, ($s1)
/* 414ED8 E0128338 0080282D */  daddu     $a1, $a0, $zero
/* 414EDC E012833C 24840008 */  addiu     $a0, $a0, 8
/* 414EE0 E0128340 AE640000 */  sw        $a0, ($s3)
/* 414EE4 E0128344 ACA30000 */  sw        $v1, ($a1)
/* 414EE8 E0128348 24430001 */  addiu     $v1, $v0, 1
/* 414EEC E012834C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 414EF0 E0128350 00021180 */  sll       $v0, $v0, 6
/* 414EF4 E0128354 A6230000 */  sh        $v1, ($s1)
/* 414EF8 E0128358 8EA30000 */  lw        $v1, ($s5)
/* 414EFC E012835C 00571021 */  addu      $v0, $v0, $s7
/* 414F00 E0128360 00621821 */  addu      $v1, $v1, $v0
/* 414F04 E0128364 24820008 */  addiu     $v0, $a0, 8
/* 414F08 E0128368 ACA30004 */  sw        $v1, 4($a1)
/* 414F0C E012836C AE620000 */  sw        $v0, ($s3)
/* 414F10 E0128370 24820010 */  addiu     $v0, $a0, 0x10
/* 414F14 E0128374 AC860000 */  sw        $a2, ($a0)
/* 414F18 E0128378 AE620000 */  sw        $v0, ($s3)
/* 414F1C E012837C 8E030204 */  lw        $v1, 0x204($s0)
/* 414F20 E0128380 3C02FA00 */  lui       $v0, 0xfa00
/* 414F24 E0128384 AC820008 */  sw        $v0, 8($a0)
/* 414F28 E0128388 AC830004 */  sw        $v1, 4($a0)
/* 414F2C E012838C 9242001B */  lbu       $v0, 0x1b($s2)
/* 414F30 E0128390 9245001F */  lbu       $a1, 0x1f($s2)
/* 414F34 E0128394 92460023 */  lbu       $a2, 0x23($s2)
/* 414F38 E0128398 24830018 */  addiu     $v1, $a0, 0x18
/* 414F3C E012839C AE630000 */  sw        $v1, ($s3)
/* 414F40 E01283A0 3C03FB00 */  lui       $v1, 0xfb00
/* 414F44 E01283A4 AC830010 */  sw        $v1, 0x10($a0)
/* 414F48 E01283A8 24830020 */  addiu     $v1, $a0, 0x20
/* 414F4C E01283AC 00021600 */  sll       $v0, $v0, 0x18
/* 414F50 E01283B0 00052C00 */  sll       $a1, $a1, 0x10
/* 414F54 E01283B4 00451025 */  or        $v0, $v0, $a1
/* 414F58 E01283B8 00063200 */  sll       $a2, $a2, 8
/* 414F5C E01283BC 00461025 */  or        $v0, $v0, $a2
/* 414F60 E01283C0 00561025 */  or        $v0, $v0, $s6
/* 414F64 E01283C4 AC82000C */  sw        $v0, 0xc($a0)
/* 414F68 E01283C8 9242002B */  lbu       $v0, 0x2b($s2)
/* 414F6C E01283CC 9245002F */  lbu       $a1, 0x2f($s2)
/* 414F70 E01283D0 92460033 */  lbu       $a2, 0x33($s2)
/* 414F74 E01283D4 00005010 */  mfhi      $t2
/* 414F78 E01283D8 AE630000 */  sw        $v1, ($s3)
/* 414F7C E01283DC AC870018 */  sw        $a3, 0x18($a0)
/* 414F80 E01283E0 00021600 */  sll       $v0, $v0, 0x18
/* 414F84 E01283E4 00052C00 */  sll       $a1, $a1, 0x10
/* 414F88 E01283E8 00451025 */  or        $v0, $v0, $a1
/* 414F8C E01283EC 00063200 */  sll       $a2, $a2, 8
/* 414F90 E01283F0 00461025 */  or        $v0, $v0, $a2
/* 414F94 E01283F4 AC820014 */  sw        $v0, 0x14($a0)
/* 414F98 E01283F8 3C03E013 */  lui       $v1, %hi(D_E01284B0)
/* 414F9C E01283FC 8C6384B0 */  lw        $v1, %lo(D_E01284B0)($v1)
/* 414FA0 E0128400 24820028 */  addiu     $v0, $a0, 0x28
/* 414FA4 E0128404 AE620000 */  sw        $v0, ($s3)
/* 414FA8 E0128408 001417C3 */  sra       $v0, $s4, 0x1f
/* 414FAC E012840C AC870020 */  sw        $a3, 0x20($a0)
/* 414FB0 E0128410 AC83001C */  sw        $v1, 0x1c($a0)
/* 414FB4 E0128414 000A1843 */  sra       $v1, $t2, 1
/* 414FB8 E0128418 00621823 */  subu      $v1, $v1, $v0
/* 414FBC E012841C 00031040 */  sll       $v0, $v1, 1
/* 414FC0 E0128420 00431021 */  addu      $v0, $v0, $v1
/* 414FC4 E0128424 00021080 */  sll       $v0, $v0, 2
/* 414FC8 E0128428 0282A023 */  subu      $s4, $s4, $v0
/* 414FCC E012842C 0014A080 */  sll       $s4, $s4, 2
/* 414FD0 E0128430 3C03E013 */  lui       $v1, %hi(D_E0128480)
/* 414FD4 E0128434 00741821 */  addu      $v1, $v1, $s4
/* 414FD8 E0128438 8C638480 */  lw        $v1, %lo(D_E0128480)($v1)
/* 414FDC E012843C 24820030 */  addiu     $v0, $a0, 0x30
/* 414FE0 E0128440 AE620000 */  sw        $v0, ($s3)
/* 414FE4 E0128444 24020040 */  addiu     $v0, $zero, 0x40
/* 414FE8 E0128448 AC890028 */  sw        $t1, 0x28($a0)
/* 414FEC E012844C AC830024 */  sw        $v1, 0x24($a0)
/* 414FF0 E0128450 AC82002C */  sw        $v0, 0x2c($a0)
/* 414FF4 E0128454 8FBF00B0 */  lw        $ra, 0xb0($sp)
/* 414FF8 E0128458 8FB700AC */  lw        $s7, 0xac($sp)
/* 414FFC E012845C 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 415000 E0128460 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 415004 E0128464 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 415008 E0128468 8FB3009C */  lw        $s3, 0x9c($sp)
/* 41500C E012846C 8FB20098 */  lw        $s2, 0x98($sp)
/* 415010 E0128470 8FB10094 */  lw        $s1, 0x94($sp)
/* 415014 E0128474 8FB00090 */  lw        $s0, 0x90($sp)
/* 415018 E0128478 03E00008 */  jr        $ra
/* 41501C E012847C 27BD00B8 */   addiu    $sp, $sp, 0xb8
