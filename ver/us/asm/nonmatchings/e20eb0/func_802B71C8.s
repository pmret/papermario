.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B71C8
/* E21078 802B71C8 3C028011 */  lui       $v0, %hi(gPlayerStatus+0x4)
/* E2107C 802B71CC 8C42EFCC */  lw        $v0, %lo(gPlayerStatus+0x4)($v0)
/* E21080 802B71D0 27BDFF28 */  addiu     $sp, $sp, -0xd8
/* E21084 802B71D4 AFBF00D0 */  sw        $ra, 0xd0($sp)
/* E21088 802B71D8 AFB500CC */  sw        $s5, 0xcc($sp)
/* E2108C 802B71DC AFB400C8 */  sw        $s4, 0xc8($sp)
/* E21090 802B71E0 AFB300C4 */  sw        $s3, 0xc4($sp)
/* E21094 802B71E4 AFB200C0 */  sw        $s2, 0xc0($sp)
/* E21098 802B71E8 AFB100BC */  sw        $s1, 0xbc($sp)
/* E2109C 802B71EC 30420020 */  andi      $v0, $v0, 0x20
/* E210A0 802B71F0 10400085 */  beqz      $v0, .L802B7408
/* E210A4 802B71F4 AFB000B8 */   sw       $s0, 0xb8($sp)
/* E210A8 802B71F8 27B00038 */  addiu     $s0, $sp, 0x38
/* E210AC 802B71FC 3C14802B */  lui       $s4, %hi(D_802B79A8_E21858)
/* E210B0 802B7200 269479A8 */  addiu     $s4, $s4, %lo(D_802B79A8_E21858)
/* E210B4 802B7204 8E820000 */  lw        $v0, ($s4)
/* E210B8 802B7208 0200202D */  daddu     $a0, $s0, $zero
/* E210BC 802B720C 8C450014 */  lw        $a1, 0x14($v0)
/* E210C0 802B7210 3C150001 */  lui       $s5, 1
/* E210C4 802B7214 00A0302D */  daddu     $a2, $a1, $zero
/* E210C8 802B7218 0C019DF0 */  jal       guScaleF
/* E210CC 802B721C 00A0382D */   daddu    $a3, $a1, $zero
/* E210D0 802B7220 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* E210D4 802B7224 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* E210D8 802B7228 27B10078 */  addiu     $s1, $sp, 0x78
/* E210DC 802B722C 00031080 */  sll       $v0, $v1, 2
/* E210E0 802B7230 00431021 */  addu      $v0, $v0, $v1
/* E210E4 802B7234 00021080 */  sll       $v0, $v0, 2
/* E210E8 802B7238 00431023 */  subu      $v0, $v0, $v1
/* E210EC 802B723C 000218C0 */  sll       $v1, $v0, 3
/* E210F0 802B7240 00431021 */  addu      $v0, $v0, $v1
/* E210F4 802B7244 000210C0 */  sll       $v0, $v0, 3
/* E210F8 802B7248 8E830000 */  lw        $v1, ($s4)
/* E210FC 802B724C 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* E21100 802B7250 00220821 */  addu      $at, $at, $v0
/* E21104 802B7254 C4221DEC */  lwc1      $f2, %lo(gCameras+0x6C)($at)
/* E21108 802B7258 C4640010 */  lwc1      $f4, 0x10($v1)
/* E2110C 802B725C 44800000 */  mtc1      $zero, $f0
/* E21110 802B7260 46022101 */  sub.s     $f4, $f4, $f2
/* E21114 802B7264 3C073F80 */  lui       $a3, 0x3f80
/* E21118 802B7268 44060000 */  mfc1      $a2, $f0
/* E2111C 802B726C 44052000 */  mfc1      $a1, $f4
/* E21120 802B7270 0220202D */  daddu     $a0, $s1, $zero
/* E21124 802B7274 0C019EC8 */  jal       guRotateF
/* E21128 802B7278 AFA60010 */   sw       $a2, 0x10($sp)
/* E2112C 802B727C 0200202D */  daddu     $a0, $s0, $zero
/* E21130 802B7280 0220282D */  daddu     $a1, $s1, $zero
/* E21134 802B7284 0C019D80 */  jal       guMtxCatF
/* E21138 802B7288 0200302D */   daddu    $a2, $s0, $zero
/* E2113C 802B728C 8E820000 */  lw        $v0, ($s4)
/* E21140 802B7290 36B51630 */  ori       $s5, $s5, 0x1630
/* E21144 802B7294 8C450004 */  lw        $a1, 4($v0)
/* E21148 802B7298 8C460008 */  lw        $a2, 8($v0)
/* E2114C 802B729C 8C47000C */  lw        $a3, 0xc($v0)
/* E21150 802B72A0 0C019E40 */  jal       guTranslateF
/* E21154 802B72A4 0220202D */   daddu    $a0, $s1, $zero
/* E21158 802B72A8 0200202D */  daddu     $a0, $s0, $zero
/* E2115C 802B72AC 0220282D */  daddu     $a1, $s1, $zero
/* E21160 802B72B0 0C019D80 */  jal       guMtxCatF
/* E21164 802B72B4 0220302D */   daddu    $a2, $s1, $zero
/* E21168 802B72B8 0220202D */  daddu     $a0, $s1, $zero
/* E2116C 802B72BC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* E21170 802B72C0 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* E21174 802B72C4 3C13800A */  lui       $s3, %hi(gDisplayContext)
/* E21178 802B72C8 2673A674 */  addiu     $s3, $s3, %lo(gDisplayContext)
/* E2117C 802B72CC 96050000 */  lhu       $a1, ($s0)
/* E21180 802B72D0 8E620000 */  lw        $v0, ($s3)
/* E21184 802B72D4 00052980 */  sll       $a1, $a1, 6
/* E21188 802B72D8 00B52821 */  addu      $a1, $a1, $s5
/* E2118C 802B72DC 0C019D40 */  jal       guMtxF2L
/* E21190 802B72E0 00452821 */   addu     $a1, $v0, $a1
/* E21194 802B72E4 3C03DA38 */  lui       $v1, 0xda38
/* E21198 802B72E8 34630002 */  ori       $v1, $v1, 2
/* E2119C 802B72EC 0000202D */  daddu     $a0, $zero, $zero
/* E211A0 802B72F0 0080282D */  daddu     $a1, $a0, $zero
/* E211A4 802B72F4 0080302D */  daddu     $a2, $a0, $zero
/* E211A8 802B72F8 3C12800A */  lui       $s2, %hi(gMasterGfxPos)
/* E211AC 802B72FC 2652A66C */  addiu     $s2, $s2, %lo(gMasterGfxPos)
/* E211B0 802B7300 0080382D */  daddu     $a3, $a0, $zero
/* E211B4 802B7304 8E480000 */  lw        $t0, ($s2)
/* E211B8 802B7308 96020000 */  lhu       $v0, ($s0)
/* E211BC 802B730C 0100482D */  daddu     $t1, $t0, $zero
/* E211C0 802B7310 25080008 */  addiu     $t0, $t0, 8
/* E211C4 802B7314 AE480000 */  sw        $t0, ($s2)
/* E211C8 802B7318 AD230000 */  sw        $v1, ($t1)
/* E211CC 802B731C 24430001 */  addiu     $v1, $v0, 1
/* E211D0 802B7320 3042FFFF */  andi      $v0, $v0, 0xffff
/* E211D4 802B7324 00021180 */  sll       $v0, $v0, 6
/* E211D8 802B7328 00551021 */  addu      $v0, $v0, $s5
/* E211DC 802B732C A6030000 */  sh        $v1, ($s0)
/* E211E0 802B7330 8E630000 */  lw        $v1, ($s3)
/* E211E4 802B7334 24100440 */  addiu     $s0, $zero, 0x440
/* E211E8 802B7338 00621821 */  addu      $v1, $v1, $v0
/* E211EC 802B733C 25020008 */  addiu     $v0, $t0, 8
/* E211F0 802B7340 AD230004 */  sw        $v1, 4($t1)
/* E211F4 802B7344 AE420000 */  sw        $v0, ($s2)
/* E211F8 802B7348 3C02DE00 */  lui       $v0, 0xde00
/* E211FC 802B734C AD020000 */  sw        $v0, ($t0)
/* E21200 802B7350 3C02802B */  lui       $v0, %hi(D_802B7930_E217E0)
/* E21204 802B7354 24427930 */  addiu     $v0, $v0, %lo(D_802B7930_E217E0)
/* E21208 802B7358 AD020004 */  sw        $v0, 4($t0)
/* E2120C 802B735C 3C02802B */  lui       $v0, %hi(D_802B7710_E215C0)
/* E21210 802B7360 24427710 */  addiu     $v0, $v0, %lo(D_802B7710_E215C0)
/* E21214 802B7364 AFA20020 */  sw        $v0, 0x20($sp)
/* E21218 802B7368 3C02802B */  lui       $v0, %hi(D_802B7910_E217C0)
/* E2121C 802B736C 24427910 */  addiu     $v0, $v0, %lo(D_802B7910_E217C0)
/* E21220 802B7370 AFA20024 */  sw        $v0, 0x24($sp)
/* E21224 802B7374 24020020 */  addiu     $v0, $zero, 0x20
/* E21228 802B7378 A7A20028 */  sh        $v0, 0x28($sp)
/* E2122C 802B737C A7A2002A */  sh        $v0, 0x2a($sp)
/* E21230 802B7380 2402FFF0 */  addiu     $v0, $zero, -0x10
/* E21234 802B7384 A7A2002C */  sh        $v0, 0x2c($sp)
/* E21238 802B7388 2402001A */  addiu     $v0, $zero, 0x1a
/* E2123C 802B738C A7A2002E */  sh        $v0, 0x2e($sp)
/* E21240 802B7390 240200FF */  addiu     $v0, $zero, 0xff
/* E21244 802B7394 A3A20030 */  sb        $v0, 0x30($sp)
/* E21248 802B7398 AFA00010 */  sw        $zero, 0x10($sp)
/* E2124C 802B739C AFA00014 */  sw        $zero, 0x14($sp)
/* E21250 802B73A0 0C04EAA7 */  jal       fold_update
/* E21254 802B73A4 AFB00018 */   sw       $s0, 0x18($sp)
/* E21258 802B73A8 0000202D */  daddu     $a0, $zero, $zero
/* E2125C 802B73AC 8E820000 */  lw        $v0, ($s4)
/* E21260 802B73B0 24050006 */  addiu     $a1, $zero, 6
/* E21264 802B73B4 9046002B */  lbu       $a2, 0x2b($v0)
/* E21268 802B73B8 240200FF */  addiu     $v0, $zero, 0xff
/* E2126C 802B73BC AFA20014 */  sw        $v0, 0x14($sp)
/* E21270 802B73C0 AFB00018 */  sw        $s0, 0x18($sp)
/* E21274 802B73C4 00C0382D */  daddu     $a3, $a2, $zero
/* E21278 802B73C8 0C04EAA7 */  jal       fold_update
/* E2127C 802B73CC AFA60010 */   sw       $a2, 0x10($sp)
/* E21280 802B73D0 0000202D */  daddu     $a0, $zero, $zero
/* E21284 802B73D4 27A50020 */  addiu     $a1, $sp, 0x20
/* E21288 802B73D8 24060040 */  addiu     $a2, $zero, 0x40
/* E2128C 802B73DC 0C04EBDC */  jal       fold_appendGfx_component
/* E21290 802B73E0 0220382D */   daddu    $a3, $s1, $zero
/* E21294 802B73E4 3C04D838 */  lui       $a0, 0xd838
/* E21298 802B73E8 8E420000 */  lw        $v0, ($s2)
/* E2129C 802B73EC 34840002 */  ori       $a0, $a0, 2
/* E212A0 802B73F0 0040182D */  daddu     $v1, $v0, $zero
/* E212A4 802B73F4 24420008 */  addiu     $v0, $v0, 8
/* E212A8 802B73F8 AE420000 */  sw        $v0, ($s2)
/* E212AC 802B73FC 24020040 */  addiu     $v0, $zero, 0x40
/* E212B0 802B7400 AC640000 */  sw        $a0, ($v1)
/* E212B4 802B7404 AC620004 */  sw        $v0, 4($v1)
.L802B7408:
/* E212B8 802B7408 8FBF00D0 */  lw        $ra, 0xd0($sp)
/* E212BC 802B740C 8FB500CC */  lw        $s5, 0xcc($sp)
/* E212C0 802B7410 8FB400C8 */  lw        $s4, 0xc8($sp)
/* E212C4 802B7414 8FB300C4 */  lw        $s3, 0xc4($sp)
/* E212C8 802B7418 8FB200C0 */  lw        $s2, 0xc0($sp)
/* E212CC 802B741C 8FB100BC */  lw        $s1, 0xbc($sp)
/* E212D0 802B7420 8FB000B8 */  lw        $s0, 0xb8($sp)
/* E212D4 802B7424 03E00008 */  jr        $ra
/* E212D8 802B7428 27BD00D8 */   addiu    $sp, $sp, 0xd8
