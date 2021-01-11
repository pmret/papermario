.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B71E8_E202F8
/* E202F8 802B71E8 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E202FC 802B71EC 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E20300 802B71F0 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* E20304 802B71F4 AFBF00D0 */  sw        $ra, 0xd0($sp)
/* E20308 802B71F8 AFB500CC */  sw        $s5, 0xcc($sp)
/* E2030C 802B71FC AFB400C8 */  sw        $s4, 0xc8($sp)
/* E20310 802B7200 AFB300C4 */  sw        $s3, 0xc4($sp)
/* E20314 802B7204 AFB200C0 */  sw        $s2, 0xc0($sp)
/* E20318 802B7208 AFB100BC */  sw        $s1, 0xbc($sp)
/* E2031C 802B720C 30420010 */  andi      $v0, $v0, 0x10
/* E20320 802B7210 10400086 */  beqz      $v0, .L802B742C
/* E20324 802B7214 AFB000B8 */   sw       $s0, 0xb8($sp)
/* E20328 802B7218 27B00038 */  addiu     $s0, $sp, 0x38
/* E2032C 802B721C 3C14802B */  lui       $s4, %hi(D_802B7CB8)
/* E20330 802B7220 26947CB8 */  addiu     $s4, $s4, %lo(D_802B7CB8)
/* E20334 802B7224 8E820000 */  lw        $v0, ($s4)
/* E20338 802B7228 0200202D */  daddu     $a0, $s0, $zero
/* E2033C 802B722C 8C450010 */  lw        $a1, 0x10($v0)
/* E20340 802B7230 3C150001 */  lui       $s5, 1
/* E20344 802B7234 00A0302D */  daddu     $a2, $a1, $zero
/* E20348 802B7238 0C019DF0 */  jal       guScaleF
/* E2034C 802B723C 00A0382D */   daddu    $a3, $a1, $zero
/* E20350 802B7240 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E20354 802B7244 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E20358 802B7248 27B10078 */  addiu     $s1, $sp, 0x78
/* E2035C 802B724C 00031080 */  sll       $v0, $v1, 2
/* E20360 802B7250 00431021 */  addu      $v0, $v0, $v1
/* E20364 802B7254 00021080 */  sll       $v0, $v0, 2
/* E20368 802B7258 00431023 */  subu      $v0, $v0, $v1
/* E2036C 802B725C 000218C0 */  sll       $v1, $v0, 3
/* E20370 802B7260 00431021 */  addu      $v0, $v0, $v1
/* E20374 802B7264 000210C0 */  sll       $v0, $v0, 3
/* E20378 802B7268 8E830000 */  lw        $v1, ($s4)
/* E2037C 802B726C 3C01800B */  lui       $at, %hi(D_800B1DEC)
/* E20380 802B7270 00220821 */  addu      $at, $at, $v0
/* E20384 802B7274 C4221DEC */  lwc1      $f2, %lo(D_800B1DEC)($at)
/* E20388 802B7278 C464000C */  lwc1      $f4, 0xc($v1)
/* E2038C 802B727C 44800000 */  mtc1      $zero, $f0
/* E20390 802B7280 46022101 */  sub.s     $f4, $f4, $f2
/* E20394 802B7284 3C073F80 */  lui       $a3, 0x3f80
/* E20398 802B7288 44060000 */  mfc1      $a2, $f0
/* E2039C 802B728C 44052000 */  mfc1      $a1, $f4
/* E203A0 802B7290 0220202D */  daddu     $a0, $s1, $zero
/* E203A4 802B7294 0C019EC8 */  jal       guRotateF
/* E203A8 802B7298 AFA60010 */   sw       $a2, 0x10($sp)
/* E203AC 802B729C 0200202D */  daddu     $a0, $s0, $zero
/* E203B0 802B72A0 0220282D */  daddu     $a1, $s1, $zero
/* E203B4 802B72A4 0C019D80 */  jal       guMtxCatF
/* E203B8 802B72A8 0200302D */   daddu    $a2, $s0, $zero
/* E203BC 802B72AC 8E820000 */  lw        $v0, ($s4)
/* E203C0 802B72B0 36B51630 */  ori       $s5, $s5, 0x1630
/* E203C4 802B72B4 8C450000 */  lw        $a1, ($v0)
/* E203C8 802B72B8 8C460004 */  lw        $a2, 4($v0)
/* E203CC 802B72BC 8C470008 */  lw        $a3, 8($v0)
/* E203D0 802B72C0 0C019E40 */  jal       guTranslateF
/* E203D4 802B72C4 0220202D */   daddu    $a0, $s1, $zero
/* E203D8 802B72C8 0200202D */  daddu     $a0, $s0, $zero
/* E203DC 802B72CC 0220282D */  daddu     $a1, $s1, $zero
/* E203E0 802B72D0 0C019D80 */  jal       guMtxCatF
/* E203E4 802B72D4 0220302D */   daddu    $a2, $s1, $zero
/* E203E8 802B72D8 0220202D */  daddu     $a0, $s1, $zero
/* E203EC 802B72DC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E203F0 802B72E0 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E203F4 802B72E4 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E203F8 802B72E8 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E203FC 802B72EC 96050000 */  lhu       $a1, ($s0)
/* E20400 802B72F0 8E620000 */  lw        $v0, ($s3)
/* E20404 802B72F4 00052980 */  sll       $a1, $a1, 6
/* E20408 802B72F8 00B52821 */  addu      $a1, $a1, $s5
/* E2040C 802B72FC 0C019D40 */  jal       guMtxF2L
/* E20410 802B7300 00452821 */   addu     $a1, $v0, $a1
/* E20414 802B7304 3C03DA38 */  lui       $v1, 0xda38
/* E20418 802B7308 34630002 */  ori       $v1, $v1, 2
/* E2041C 802B730C 0000202D */  daddu     $a0, $zero, $zero
/* E20420 802B7310 0080282D */  daddu     $a1, $a0, $zero
/* E20424 802B7314 0080302D */  daddu     $a2, $a0, $zero
/* E20428 802B7318 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* E2042C 802B731C 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* E20430 802B7320 0080382D */  daddu     $a3, $a0, $zero
/* E20434 802B7324 8E480000 */  lw        $t0, ($s2)
/* E20438 802B7328 96020000 */  lhu       $v0, ($s0)
/* E2043C 802B732C 0100482D */  daddu     $t1, $t0, $zero
/* E20440 802B7330 25080008 */  addiu     $t0, $t0, 8
/* E20444 802B7334 AE480000 */  sw        $t0, ($s2)
/* E20448 802B7338 AD230000 */  sw        $v1, ($t1)
/* E2044C 802B733C 24430001 */  addiu     $v1, $v0, 1
/* E20450 802B7340 3042FFFF */  andi      $v0, $v0, 0xffff
/* E20454 802B7344 00021180 */  sll       $v0, $v0, 6
/* E20458 802B7348 A6030000 */  sh        $v1, ($s0)
/* E2045C 802B734C 8E630000 */  lw        $v1, ($s3)
/* E20460 802B7350 00551021 */  addu      $v0, $v0, $s5
/* E20464 802B7354 00621821 */  addu      $v1, $v1, $v0
/* E20468 802B7358 25020008 */  addiu     $v0, $t0, 8
/* E2046C 802B735C AD230004 */  sw        $v1, 4($t1)
/* E20470 802B7360 AE420000 */  sw        $v0, ($s2)
/* E20474 802B7364 3C02DE00 */  lui       $v0, 0xde00
/* E20478 802B7368 AD020000 */  sw        $v0, ($t0)
/* E2047C 802B736C 3C02802B */  lui       $v0, %hi(D_802B7C40)
/* E20480 802B7370 24427C40 */  addiu     $v0, $v0, %lo(D_802B7C40)
/* E20484 802B7374 AD020004 */  sw        $v0, 4($t0)
/* E20488 802B7378 3C02802B */  lui       $v0, %hi(D_802B7A20)
/* E2048C 802B737C 24427A20 */  addiu     $v0, $v0, %lo(D_802B7A20)
/* E20490 802B7380 AFA20020 */  sw        $v0, 0x20($sp)
/* E20494 802B7384 3C02802B */  lui       $v0, %hi(D_802B7C20)
/* E20498 802B7388 24427C20 */  addiu     $v0, $v0, %lo(D_802B7C20)
/* E2049C 802B738C AFA20024 */  sw        $v0, 0x24($sp)
/* E204A0 802B7390 24020020 */  addiu     $v0, $zero, 0x20
/* E204A4 802B7394 A7A20028 */  sh        $v0, 0x28($sp)
/* E204A8 802B7398 A7A2002A */  sh        $v0, 0x2a($sp)
/* E204AC 802B739C 2402FFF0 */  addiu     $v0, $zero, -0x10
/* E204B0 802B73A0 A7A2002C */  sh        $v0, 0x2c($sp)
/* E204B4 802B73A4 2402001A */  addiu     $v0, $zero, 0x1a
/* E204B8 802B73A8 A7A2002E */  sh        $v0, 0x2e($sp)
/* E204BC 802B73AC 240200FF */  addiu     $v0, $zero, 0xff
/* E204C0 802B73B0 A3A20030 */  sb        $v0, 0x30($sp)
/* E204C4 802B73B4 24020440 */  addiu     $v0, $zero, 0x440
/* E204C8 802B73B8 AFA00010 */  sw        $zero, 0x10($sp)
/* E204CC 802B73BC AFA00014 */  sw        $zero, 0x14($sp)
/* E204D0 802B73C0 0C04EAA7 */  jal       func_8013AA9C
/* E204D4 802B73C4 AFA20018 */   sw       $v0, 0x18($sp)
/* E204D8 802B73C8 0000202D */  daddu     $a0, $zero, $zero
/* E204DC 802B73CC 8E820000 */  lw        $v0, ($s4)
/* E204E0 802B73D0 24050006 */  addiu     $a1, $zero, 6
/* E204E4 802B73D4 90460024 */  lbu       $a2, 0x24($v0)
/* E204E8 802B73D8 240200FF */  addiu     $v0, $zero, 0xff
/* E204EC 802B73DC AFA20014 */  sw        $v0, 0x14($sp)
/* E204F0 802B73E0 24020448 */  addiu     $v0, $zero, 0x448
/* E204F4 802B73E4 AFA20018 */  sw        $v0, 0x18($sp)
/* E204F8 802B73E8 00C0382D */  daddu     $a3, $a2, $zero
/* E204FC 802B73EC 0C04EAA7 */  jal       func_8013AA9C
/* E20500 802B73F0 AFA60010 */   sw       $a2, 0x10($sp)
/* E20504 802B73F4 0000202D */  daddu     $a0, $zero, $zero
/* E20508 802B73F8 27A50020 */  addiu     $a1, $sp, 0x20
/* E2050C 802B73FC 0080302D */  daddu     $a2, $a0, $zero
/* E20510 802B7400 0C04EBDC */  jal       func_8013AF70
/* E20514 802B7404 0220382D */   daddu    $a3, $s1, $zero
/* E20518 802B7408 3C04D838 */  lui       $a0, 0xd838
/* E2051C 802B740C 8E420000 */  lw        $v0, ($s2)
/* E20520 802B7410 34840002 */  ori       $a0, $a0, 2
/* E20524 802B7414 0040182D */  daddu     $v1, $v0, $zero
/* E20528 802B7418 24420008 */  addiu     $v0, $v0, 8
/* E2052C 802B741C AE420000 */  sw        $v0, ($s2)
/* E20530 802B7420 24020040 */  addiu     $v0, $zero, 0x40
/* E20534 802B7424 AC640000 */  sw        $a0, ($v1)
/* E20538 802B7428 AC620004 */  sw        $v0, 4($v1)
.L802B742C:
/* E2053C 802B742C 8FBF00D0 */  lw        $ra, 0xd0($sp)
/* E20540 802B7430 8FB500CC */  lw        $s5, 0xcc($sp)
/* E20544 802B7434 8FB400C8 */  lw        $s4, 0xc8($sp)
/* E20548 802B7438 8FB300C4 */  lw        $s3, 0xc4($sp)
/* E2054C 802B743C 8FB200C0 */  lw        $s2, 0xc0($sp)
/* E20550 802B7440 8FB100BC */  lw        $s1, 0xbc($sp)
/* E20554 802B7444 8FB000B8 */  lw        $s0, 0xb8($sp)
/* E20558 802B7448 03E00008 */  jr        $ra
/* E2055C 802B744C 27BD00D8 */   addiu    $sp, $sp, 0xd8
