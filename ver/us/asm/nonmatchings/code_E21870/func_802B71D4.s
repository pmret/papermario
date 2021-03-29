.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802B7D20_E22590
.word L802B73C0_E21C30, L802B73C8_E21C38, L802B73D0_E21C40, L802B73D8_E21C48, L802B73E0_E21C50, L802B73E8_E21C58, 0, 0

.section .text

glabel func_802B71D4
/* E21A44 802B71D4 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E21A48 802B71D8 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E21A4C 802B71DC 27BDFF38 */  addiu     $sp, $sp, -0xc8
/* E21A50 802B71E0 AFBF00C0 */  sw        $ra, 0xc0($sp)
/* E21A54 802B71E4 AFB300BC */  sw        $s3, 0xbc($sp)
/* E21A58 802B71E8 AFB200B8 */  sw        $s2, 0xb8($sp)
/* E21A5C 802B71EC AFB100B4 */  sw        $s1, 0xb4($sp)
/* E21A60 802B71F0 30420040 */  andi      $v0, $v0, 0x40
/* E21A64 802B71F4 104000B7 */  beqz      $v0, .L802B74D4
/* E21A68 802B71F8 AFB000B0 */   sw       $s0, 0xb0($sp)
/* E21A6C 802B71FC 3C13802B */  lui       $s3, %hi(D_802B7D18_E22588)
/* E21A70 802B7200 26737D18 */  addiu     $s3, $s3, %lo(D_802B7D18_E22588)
/* E21A74 802B7204 8E620000 */  lw        $v0, ($s3)
/* E21A78 802B7208 27A40018 */  addiu     $a0, $sp, 0x18
/* E21A7C 802B720C 8C45000C */  lw        $a1, 0xc($v0)
/* E21A80 802B7210 3C120001 */  lui       $s2, 1
/* E21A84 802B7214 00A0302D */  daddu     $a2, $a1, $zero
/* E21A88 802B7218 0C019DF0 */  jal       guScaleF
/* E21A8C 802B721C 00A0382D */   daddu    $a3, $a1, $zero
/* E21A90 802B7220 27B00058 */  addiu     $s0, $sp, 0x58
/* E21A94 802B7224 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E21A98 802B7228 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E21A9C 802B722C 44800000 */  mtc1      $zero, $f0
/* E21AA0 802B7230 00031080 */  sll       $v0, $v1, 2
/* E21AA4 802B7234 00431021 */  addu      $v0, $v0, $v1
/* E21AA8 802B7238 00021080 */  sll       $v0, $v0, 2
/* E21AAC 802B723C 00431023 */  subu      $v0, $v0, $v1
/* E21AB0 802B7240 000218C0 */  sll       $v1, $v0, 3
/* E21AB4 802B7244 00431021 */  addu      $v0, $v0, $v1
/* E21AB8 802B7248 000210C0 */  sll       $v0, $v0, 3
/* E21ABC 802B724C 44060000 */  mfc1      $a2, $f0
/* E21AC0 802B7250 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E21AC4 802B7254 00220821 */  addu      $at, $at, $v0
/* E21AC8 802B7258 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* E21ACC 802B725C 3C073F80 */  lui       $a3, 0x3f80
/* E21AD0 802B7260 46000007 */  neg.s     $f0, $f0
/* E21AD4 802B7264 44050000 */  mfc1      $a1, $f0
/* E21AD8 802B7268 0200202D */  daddu     $a0, $s0, $zero
/* E21ADC 802B726C 0C019EC8 */  jal       guRotateF
/* E21AE0 802B7270 AFA60010 */   sw       $a2, 0x10($sp)
/* E21AE4 802B7274 27A40018 */  addiu     $a0, $sp, 0x18
/* E21AE8 802B7278 0200282D */  daddu     $a1, $s0, $zero
/* E21AEC 802B727C 0C019D80 */  jal       guMtxCatF
/* E21AF0 802B7280 0080302D */   daddu    $a2, $a0, $zero
/* E21AF4 802B7284 8E620000 */  lw        $v0, ($s3)
/* E21AF8 802B7288 36521630 */  ori       $s2, $s2, 0x1630
/* E21AFC 802B728C 8C450000 */  lw        $a1, ($v0)
/* E21B00 802B7290 8C460004 */  lw        $a2, 4($v0)
/* E21B04 802B7294 8C470008 */  lw        $a3, 8($v0)
/* E21B08 802B7298 0C019E40 */  jal       guTranslateF
/* E21B0C 802B729C 0200202D */   daddu    $a0, $s0, $zero
/* E21B10 802B72A0 27A40018 */  addiu     $a0, $sp, 0x18
/* E21B14 802B72A4 0200282D */  daddu     $a1, $s0, $zero
/* E21B18 802B72A8 0C019D80 */  jal       guMtxCatF
/* E21B1C 802B72AC 0200302D */   daddu    $a2, $s0, $zero
/* E21B20 802B72B0 0200202D */  daddu     $a0, $s0, $zero
/* E21B24 802B72B4 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E21B28 802B72B8 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E21B2C 802B72BC 3C11800A */  lui       $s1, %hi(gDisplayContext)
/* E21B30 802B72C0 2631A674 */  addiu     $s1, $s1, %lo(gDisplayContext)
/* E21B34 802B72C4 96050000 */  lhu       $a1, ($s0)
/* E21B38 802B72C8 8E220000 */  lw        $v0, ($s1)
/* E21B3C 802B72CC 00052980 */  sll       $a1, $a1, 6
/* E21B40 802B72D0 00B22821 */  addu      $a1, $a1, $s2
/* E21B44 802B72D4 0C019D40 */  jal       guMtxF2L
/* E21B48 802B72D8 00452821 */   addu     $a1, $v0, $a1
/* E21B4C 802B72DC 3C02DA38 */  lui       $v0, 0xda38
/* E21B50 802B72E0 34420002 */  ori       $v0, $v0, 2
/* E21B54 802B72E4 3C07800A */  lui       $a3, %hi(gMasterGfxPos)
/* E21B58 802B72E8 24E7A66C */  addiu     $a3, $a3, %lo(gMasterGfxPos)
/* E21B5C 802B72EC 3C089249 */  lui       $t0, 0x9249
/* E21B60 802B72F0 35082493 */  ori       $t0, $t0, 0x2493
/* E21B64 802B72F4 8CE50000 */  lw        $a1, ($a3)
/* E21B68 802B72F8 96060000 */  lhu       $a2, ($s0)
/* E21B6C 802B72FC 00A0202D */  daddu     $a0, $a1, $zero
/* E21B70 802B7300 24A50008 */  addiu     $a1, $a1, 8
/* E21B74 802B7304 AC820000 */  sw        $v0, ($a0)
/* E21B78 802B7308 30C2FFFF */  andi      $v0, $a2, 0xffff
/* E21B7C 802B730C 00021180 */  sll       $v0, $v0, 6
/* E21B80 802B7310 8E230000 */  lw        $v1, ($s1)
/* E21B84 802B7314 00521021 */  addu      $v0, $v0, $s2
/* E21B88 802B7318 00621821 */  addu      $v1, $v1, $v0
/* E21B8C 802B731C AC830004 */  sw        $v1, 4($a0)
/* E21B90 802B7320 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E21B94 802B7324 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E21B98 802B7328 3C02DE00 */  lui       $v0, 0xde00
/* E21B9C 802B732C ACA20000 */  sw        $v0, ($a1)
/* E21BA0 802B7330 3C02802B */  lui       $v0, %hi(D_802B7CA0_E22510)
/* E21BA4 802B7334 24427CA0 */  addiu     $v0, $v0, %lo(D_802B7CA0_E22510)
/* E21BA8 802B7338 ACA20004 */  sw        $v0, 4($a1)
/* E21BAC 802B733C 9462008C */  lhu       $v0, 0x8c($v1)
/* E21BB0 802B7340 24C60001 */  addiu     $a2, $a2, 1
/* E21BB4 802B7344 ACE50000 */  sw        $a1, ($a3)
/* E21BB8 802B7348 00021400 */  sll       $v0, $v0, 0x10
/* E21BBC 802B734C 00022403 */  sra       $a0, $v0, 0x10
/* E21BC0 802B7350 00880018 */  mult      $a0, $t0
/* E21BC4 802B7354 24A50008 */  addiu     $a1, $a1, 8
/* E21BC8 802B7358 A6060000 */  sh        $a2, ($s0)
/* E21BCC 802B735C 000217C3 */  sra       $v0, $v0, 0x1f
/* E21BD0 802B7360 00004810 */  mfhi      $t1
/* E21BD4 802B7364 01241821 */  addu      $v1, $t1, $a0
/* E21BD8 802B7368 00031883 */  sra       $v1, $v1, 2
/* E21BDC 802B736C 00621823 */  subu      $v1, $v1, $v0
/* E21BE0 802B7370 000310C0 */  sll       $v0, $v1, 3
/* E21BE4 802B7374 00431023 */  subu      $v0, $v0, $v1
/* E21BE8 802B7378 00822023 */  subu      $a0, $a0, $v0
/* E21BEC 802B737C 00042400 */  sll       $a0, $a0, 0x10
/* E21BF0 802B7380 00042403 */  sra       $a0, $a0, 0x10
/* E21BF4 802B7384 2484FFFE */  addiu     $a0, $a0, -2
/* E21BF8 802B7388 04820001 */  bltzl     $a0, .L802B7390
/* E21BFC 802B738C 00042023 */   negu     $a0, $a0
.L802B7390:
/* E21C00 802B7390 00031C00 */  sll       $v1, $v1, 0x10
/* E21C04 802B7394 00031C03 */  sra       $v1, $v1, 0x10
/* E21C08 802B7398 00832021 */  addu      $a0, $a0, $v1
/* E21C0C 802B739C 2C820006 */  sltiu     $v0, $a0, 6
/* E21C10 802B73A0 10400013 */  beqz      $v0, .L802B73F0
/* E21C14 802B73A4 ACE50000 */   sw       $a1, ($a3)
/* E21C18 802B73A8 00041080 */  sll       $v0, $a0, 2
/* E21C1C 802B73AC 3C01802B */  lui       $at, %hi(jtbl_802B7D20_E22590)
/* E21C20 802B73B0 00220821 */  addu      $at, $at, $v0
/* E21C24 802B73B4 8C227D20 */  lw        $v0, %lo(jtbl_802B7D20_E22590)($at)
/* E21C28 802B73B8 00400008 */  jr        $v0
/* E21C2C 802B73BC 00000000 */   nop
glabel L802B73C0_E21C30
/* E21C30 802B73C0 080ADCFF */  j         .L802B73FC
/* E21C34 802B73C4 24030004 */   addiu    $v1, $zero, 4
glabel L802B73C8_E21C38
/* E21C38 802B73C8 080ADCFF */  j         .L802B73FC
/* E21C3C 802B73CC 24030008 */   addiu    $v1, $zero, 8
glabel L802B73D0_E21C40
/* E21C40 802B73D0 080ADCFF */  j         .L802B73FC
/* E21C44 802B73D4 24030010 */   addiu    $v1, $zero, 0x10
glabel L802B73D8_E21C48
/* E21C48 802B73D8 080ADCFF */  j         .L802B73FC
/* E21C4C 802B73DC 24030020 */   addiu    $v1, $zero, 0x20
glabel L802B73E0_E21C50
/* E21C50 802B73E0 080ADCFF */  j         .L802B73FC
/* E21C54 802B73E4 24030040 */   addiu    $v1, $zero, 0x40
glabel L802B73E8_E21C58
/* E21C58 802B73E8 080ADCFF */  j         .L802B73FC
/* E21C5C 802B73EC 24030080 */   addiu    $v1, $zero, 0x80
.L802B73F0:
/* E21C60 802B73F0 8E620000 */  lw        $v0, ($s3)
/* E21C64 802B73F4 2403FFFF */  addiu     $v1, $zero, -1
/* E21C68 802B73F8 AC400020 */  sw        $zero, 0x20($v0)
.L802B73FC:
/* E21C6C 802B73FC 3C11802B */  lui       $s1, %hi(D_802B7C60_E224D0)
/* E21C70 802B7400 26317C60 */  addiu     $s1, $s1, %lo(D_802B7C60_E224D0)
/* E21C74 802B7404 04600017 */  bltz      $v1, .L802B7464
/* E21C78 802B7408 AFB1009C */   sw       $s1, 0x9c($sp)
/* E21C7C 802B740C 3C10802B */  lui       $s0, %hi(D_802B7D18_E22588)
/* E21C80 802B7410 26107D18 */  addiu     $s0, $s0, %lo(D_802B7D18_E22588)
/* E21C84 802B7414 8E040000 */  lw        $a0, ($s0)
/* E21C88 802B7418 8C820020 */  lw        $v0, 0x20($a0)
/* E21C8C 802B741C 24630002 */  addiu     $v1, $v1, 2
/* E21C90 802B7420 24420001 */  addiu     $v0, $v0, 1
/* E21C94 802B7424 AC820020 */  sw        $v0, 0x20($a0)
/* E21C98 802B7428 0043102A */  slt       $v0, $v0, $v1
/* E21C9C 802B742C 14400005 */  bnez      $v0, .L802B7444
/* E21CA0 802B7430 00000000 */   nop
/* E21CA4 802B7434 AC800020 */  sw        $zero, 0x20($a0)
/* E21CA8 802B7438 2404007D */  addiu     $a0, $zero, 0x7d
/* E21CAC 802B743C 0C052736 */  jal       sfx_play_sound_at_player
/* E21CB0 802B7440 0000282D */   daddu    $a1, $zero, $zero
.L802B7444:
/* E21CB4 802B7444 8E020000 */  lw        $v0, ($s0)
/* E21CB8 802B7448 8C420020 */  lw        $v0, 0x20($v0)
/* E21CBC 802B744C 28420002 */  slti      $v0, $v0, 2
/* E21CC0 802B7450 50400004 */  beql      $v0, $zero, .L802B7464
/* E21CC4 802B7454 AFB1009C */   sw       $s1, 0x9c($sp)
/* E21CC8 802B7458 3C02802B */  lui       $v0, %hi(D_802B7C80_E224F0)
/* E21CCC 802B745C 24427C80 */  addiu     $v0, $v0, %lo(D_802B7C80_E224F0)
/* E21CD0 802B7460 AFA2009C */  sw        $v0, 0x9c($sp)
.L802B7464:
/* E21CD4 802B7464 0000202D */  daddu     $a0, $zero, $zero
/* E21CD8 802B7468 27A50098 */  addiu     $a1, $sp, 0x98
/* E21CDC 802B746C 0080302D */  daddu     $a2, $a0, $zero
/* E21CE0 802B7470 27A70058 */  addiu     $a3, $sp, 0x58
/* E21CE4 802B7474 3C02802B */  lui       $v0, %hi(D_802B7640_E21EB0)
/* E21CE8 802B7478 24427640 */  addiu     $v0, $v0, %lo(D_802B7640_E21EB0)
/* E21CEC 802B747C AFA20098 */  sw        $v0, 0x98($sp)
/* E21CF0 802B7480 24020038 */  addiu     $v0, $zero, 0x38
/* E21CF4 802B7484 A7A200A0 */  sh        $v0, 0xa0($sp)
/* E21CF8 802B7488 A7A200A2 */  sh        $v0, 0xa2($sp)
/* E21CFC 802B748C 2402FFE4 */  addiu     $v0, $zero, -0x1c
/* E21D00 802B7490 A7A200A4 */  sh        $v0, 0xa4($sp)
/* E21D04 802B7494 2402002E */  addiu     $v0, $zero, 0x2e
/* E21D08 802B7498 A7A200A6 */  sh        $v0, 0xa6($sp)
/* E21D0C 802B749C 240200FF */  addiu     $v0, $zero, 0xff
/* E21D10 802B74A0 0C04EBDC */  jal       func_8013AF70
/* E21D14 802B74A4 A3A200A8 */   sb       $v0, 0xa8($sp)
/* E21D18 802B74A8 3C05D838 */  lui       $a1, 0xd838
/* E21D1C 802B74AC 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* E21D20 802B74B0 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* E21D24 802B74B4 8C620000 */  lw        $v0, ($v1)
/* E21D28 802B74B8 34A50002 */  ori       $a1, $a1, 2
/* E21D2C 802B74BC 0040202D */  daddu     $a0, $v0, $zero
/* E21D30 802B74C0 24420008 */  addiu     $v0, $v0, 8
/* E21D34 802B74C4 AC620000 */  sw        $v0, ($v1)
/* E21D38 802B74C8 24020040 */  addiu     $v0, $zero, 0x40
/* E21D3C 802B74CC AC850000 */  sw        $a1, ($a0)
/* E21D40 802B74D0 AC820004 */  sw        $v0, 4($a0)
.L802B74D4:
/* E21D44 802B74D4 8FBF00C0 */  lw        $ra, 0xc0($sp)
/* E21D48 802B74D8 8FB300BC */  lw        $s3, 0xbc($sp)
/* E21D4C 802B74DC 8FB200B8 */  lw        $s2, 0xb8($sp)
/* E21D50 802B74E0 8FB100B4 */  lw        $s1, 0xb4($sp)
/* E21D54 802B74E4 8FB000B0 */  lw        $s0, 0xb0($sp)
/* E21D58 802B74E8 03E00008 */  jr        $ra
/* E21D5C 802B74EC 27BD00C8 */   addiu    $sp, $sp, 0xc8
