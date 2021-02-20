.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel draw_coin_sparkles
/* C720C 80130B0C 27BDFE78 */  addiu     $sp, $sp, -0x188
/* C7210 80130B10 AFB20150 */  sw        $s2, 0x150($sp)
/* C7214 80130B14 0080902D */  daddu     $s2, $a0, $zero
/* C7218 80130B18 AFB70164 */  sw        $s7, 0x164($sp)
/* C721C 80130B1C 3C170001 */  lui       $s7, 1
/* C7220 80130B20 3C03800A */  lui       $v1, %hi(D_8009A634)
/* C7224 80130B24 8463A634 */  lh        $v1, %lo(D_8009A634)($v1)
/* C7228 80130B28 3C014334 */  lui       $at, 0x4334
/* C722C 80130B2C 44816000 */  mtc1      $at, $f12
/* C7230 80130B30 36F71630 */  ori       $s7, $s7, 0x1630
/* C7234 80130B34 AFBF016C */  sw        $ra, 0x16c($sp)
/* C7238 80130B38 AFBE0168 */  sw        $fp, 0x168($sp)
/* C723C 80130B3C AFB60160 */  sw        $s6, 0x160($sp)
/* C7240 80130B40 AFB5015C */  sw        $s5, 0x15c($sp)
/* C7244 80130B44 AFB40158 */  sw        $s4, 0x158($sp)
/* C7248 80130B48 AFB30154 */  sw        $s3, 0x154($sp)
/* C724C 80130B4C AFB1014C */  sw        $s1, 0x14c($sp)
/* C7250 80130B50 AFB00148 */  sw        $s0, 0x148($sp)
/* C7254 80130B54 F7B80180 */  sdc1      $f24, 0x180($sp)
/* C7258 80130B58 F7B60178 */  sdc1      $f22, 0x178($sp)
/* C725C 80130B5C F7B40170 */  sdc1      $f20, 0x170($sp)
/* C7260 80130B60 00031080 */  sll       $v0, $v1, 2
/* C7264 80130B64 00431021 */  addu      $v0, $v0, $v1
/* C7268 80130B68 00021080 */  sll       $v0, $v0, 2
/* C726C 80130B6C 00431023 */  subu      $v0, $v0, $v1
/* C7270 80130B70 000218C0 */  sll       $v1, $v0, 3
/* C7274 80130B74 00431021 */  addu      $v0, $v0, $v1
/* C7278 80130B78 000210C0 */  sll       $v0, $v0, 3
/* C727C 80130B7C 3C038015 */  lui       $v1, %hi(D_80155D8C)
/* C7280 80130B80 84635D8C */  lh        $v1, %lo(D_80155D8C)($v1)
/* C7284 80130B84 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* C7288 80130B88 00220821 */  addu      $at, $at, $v0
/* C728C 80130B8C C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* C7290 80130B90 3C028015 */  lui       $v0, %hi(D_80155D8E)
/* C7294 80130B94 84425D8E */  lh        $v0, %lo(D_80155D8E)($v0)
/* C7298 80130B98 4483C000 */  mtc1      $v1, $f24
/* C729C 80130B9C 00000000 */  nop
/* C72A0 80130BA0 4680C620 */  cvt.s.w   $f24, $f24
/* C72A4 80130BA4 3C038015 */  lui       $v1, %hi(D_80155D90)
/* C72A8 80130BA8 84635D90 */  lh        $v1, %lo(D_80155D90)($v1)
/* C72AC 80130BAC 4482A000 */  mtc1      $v0, $f20
/* C72B0 80130BB0 00000000 */  nop
/* C72B4 80130BB4 4680A520 */  cvt.s.w   $f20, $f20
/* C72B8 80130BB8 4483B000 */  mtc1      $v1, $f22
/* C72BC 80130BBC 00000000 */  nop
/* C72C0 80130BC0 4680B5A0 */  cvt.s.w   $f22, $f22
/* C72C4 80130BC4 0C00A6C9 */  jal       clamp_angle
/* C72C8 80130BC8 46006301 */   sub.s    $f12, $f12, $f0
/* C72CC 80130BCC 27A40018 */  addiu     $a0, $sp, 0x18
/* C72D0 80130BD0 4405C000 */  mfc1      $a1, $f24
/* C72D4 80130BD4 4406A000 */  mfc1      $a2, $f20
/* C72D8 80130BD8 4407B000 */  mfc1      $a3, $f22
/* C72DC 80130BDC 0C019E40 */  jal       guTranslateF
/* C72E0 80130BE0 46000506 */   mov.s    $f20, $f0
/* C72E4 80130BE4 C642000C */  lwc1      $f2, 0xc($s2)
/* C72E8 80130BE8 3C014140 */  lui       $at, 0x4140
/* C72EC 80130BEC 44810000 */  mtc1      $at, $f0
/* C72F0 80130BF0 27B10058 */  addiu     $s1, $sp, 0x58
/* C72F4 80130BF4 46001080 */  add.s     $f2, $f2, $f0
/* C72F8 80130BF8 8E450008 */  lw        $a1, 8($s2)
/* C72FC 80130BFC 8E470010 */  lw        $a3, 0x10($s2)
/* C7300 80130C00 44061000 */  mfc1      $a2, $f2
/* C7304 80130C04 0C019E40 */  jal       guTranslateF
/* C7308 80130C08 0220202D */   daddu    $a0, $s1, $zero
/* C730C 80130C0C 27B00098 */  addiu     $s0, $sp, 0x98
/* C7310 80130C10 4405A000 */  mfc1      $a1, $f20
/* C7314 80130C14 44800000 */  mtc1      $zero, $f0
/* C7318 80130C18 3C073F80 */  lui       $a3, 0x3f80
/* C731C 80130C1C 44060000 */  mfc1      $a2, $f0
/* C7320 80130C20 0200202D */  daddu     $a0, $s0, $zero
/* C7324 80130C24 0C019EC8 */  jal       guRotateF
/* C7328 80130C28 AFA60010 */   sw       $a2, 0x10($sp)
/* C732C 80130C2C 27A40018 */  addiu     $a0, $sp, 0x18
/* C7330 80130C30 0200282D */  daddu     $a1, $s0, $zero
/* C7334 80130C34 0C019D80 */  jal       guMtxCatF
/* C7338 80130C38 0200302D */   daddu    $a2, $s0, $zero
/* C733C 80130C3C 0200202D */  daddu     $a0, $s0, $zero
/* C7340 80130C40 0220282D */  daddu     $a1, $s1, $zero
/* C7344 80130C44 27B100D8 */  addiu     $s1, $sp, 0xd8
/* C7348 80130C48 0C019D80 */  jal       guMtxCatF
/* C734C 80130C4C 0220302D */   daddu    $a2, $s1, $zero
/* C7350 80130C50 0220202D */  daddu     $a0, $s1, $zero
/* C7354 80130C54 3C138007 */  lui       $s3, %hi(gMatrixListPos)
/* C7358 80130C58 267341F0 */  addiu     $s3, $s3, %lo(gMatrixListPos)
/* C735C 80130C5C 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* C7360 80130C60 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* C7364 80130C64 96650000 */  lhu       $a1, ($s3)
/* C7368 80130C68 8E820000 */  lw        $v0, ($s4)
/* C736C 80130C6C 00052980 */  sll       $a1, $a1, 6
/* C7370 80130C70 00B72821 */  addu      $a1, $a1, $s7
/* C7374 80130C74 0C019D40 */  jal       guMtxF2L
/* C7378 80130C78 00452821 */   addu     $a1, $v0, $a1
/* C737C 80130C7C 3C08DA38 */  lui       $t0, 0xda38
/* C7380 80130C80 35080002 */  ori       $t0, $t0, 2
/* C7384 80130C84 3C0AE300 */  lui       $t2, 0xe300
/* C7388 80130C88 354A0A01 */  ori       $t2, $t2, 0xa01
/* C738C 80130C8C 3C0BD9C0 */  lui       $t3, 0xd9c0
/* C7390 80130C90 356BF9FA */  ori       $t3, $t3, 0xf9fa
/* C7394 80130C94 3C0DD9FF */  lui       $t5, 0xd9ff
/* C7398 80130C98 35ADFFFF */  ori       $t5, $t5, 0xffff
/* C739C 80130C9C 3C0C0022 */  lui       $t4, 0x22
/* C73A0 80130CA0 358C0005 */  ori       $t4, $t4, 5
/* C73A4 80130CA4 3C0EDC08 */  lui       $t6, 0xdc08
/* C73A8 80130CA8 35CE060A */  ori       $t6, $t6, 0x60a
/* C73AC 80130CAC 3C0FDC08 */  lui       $t7, 0xdc08
/* C73B0 80130CB0 35EF090A */  ori       $t7, $t7, 0x90a
/* C73B4 80130CB4 3C15D700 */  lui       $s5, 0xd700
/* C73B8 80130CB8 36B50002 */  ori       $s5, $s5, 2
/* C73BC 80130CBC 3C16E300 */  lui       $s6, 0xe300
/* C73C0 80130CC0 36D60F00 */  ori       $s6, $s6, 0xf00
/* C73C4 80130CC4 3C18E300 */  lui       $t8, 0xe300
/* C73C8 80130CC8 37180C00 */  ori       $t8, $t8, 0xc00
/* C73CC 80130CCC 3C19E300 */  lui       $t9, 0xe300
/* C73D0 80130CD0 37391201 */  ori       $t9, $t9, 0x1201
/* C73D4 80130CD4 3C1EE300 */  lui       $fp, 0xe300
/* C73D8 80130CD8 37DE1801 */  ori       $fp, $fp, 0x1801
/* C73DC 80130CDC AFAA0140 */  sw        $t2, 0x140($sp)
/* C73E0 80130CE0 3C0AE300 */  lui       $t2, 0xe300
/* C73E4 80130CE4 354A0D01 */  ori       $t2, $t2, 0xd01
/* C73E8 80130CE8 AFAA0130 */  sw        $t2, 0x130($sp)
/* C73EC 80130CEC 3C0AE300 */  lui       $t2, 0xe300
/* C73F0 80130CF0 354A1402 */  ori       $t2, $t2, 0x1402
/* C73F4 80130CF4 AFAA0134 */  sw        $t2, 0x134($sp)
/* C73F8 80130CF8 3C0AE300 */  lui       $t2, 0xe300
/* C73FC 80130CFC 354A1700 */  ori       $t2, $t2, 0x1700
/* C7400 80130D00 AFAA0138 */  sw        $t2, 0x138($sp)
/* C7404 80130D04 3C0AE200 */  lui       $t2, 0xe200
/* C7408 80130D08 354A1E01 */  ori       $t2, $t2, 0x1e01
/* C740C 80130D0C 0000202D */  daddu     $a0, $zero, $zero
/* C7410 80130D10 3C10800A */  lui       $s0, %hi(gMasterGfxPos)
/* C7414 80130D14 2610A66C */  addiu     $s0, $s0, %lo(gMasterGfxPos)
/* C7418 80130D18 AFAA013C */  sw        $t2, 0x13c($sp)
/* C741C 80130D1C 8E030000 */  lw        $v1, ($s0)
/* C7420 80130D20 96620000 */  lhu       $v0, ($s3)
/* C7424 80130D24 0060482D */  daddu     $t1, $v1, $zero
/* C7428 80130D28 24630008 */  addiu     $v1, $v1, 8
/* C742C 80130D2C AE030000 */  sw        $v1, ($s0)
/* C7430 80130D30 AD280000 */  sw        $t0, ($t1)
/* C7434 80130D34 24480001 */  addiu     $t0, $v0, 1
/* C7438 80130D38 3042FFFF */  andi      $v0, $v0, 0xffff
/* C743C 80130D3C 00021180 */  sll       $v0, $v0, 6
/* C7440 80130D40 A6680000 */  sh        $t0, ($s3)
/* C7444 80130D44 8E880000 */  lw        $t0, ($s4)
/* C7448 80130D48 00571021 */  addu      $v0, $v0, $s7
/* C744C 80130D4C 01024021 */  addu      $t0, $t0, $v0
/* C7450 80130D50 24620008 */  addiu     $v0, $v1, 8
/* C7454 80130D54 AD280004 */  sw        $t0, 4($t1)
/* C7458 80130D58 AE020000 */  sw        $v0, ($s0)
/* C745C 80130D5C 24620010 */  addiu     $v0, $v1, 0x10
/* C7460 80130D60 8FAA0140 */  lw        $t2, 0x140($sp)
/* C7464 80130D64 3C088015 */  lui       $t0, %hi(D_8014C6D0)
/* C7468 80130D68 2508C6D0 */  addiu     $t0, $t0, %lo(D_8014C6D0)
/* C746C 80130D6C AC6A0000 */  sw        $t2, ($v1)
/* C7470 80130D70 AC600004 */  sw        $zero, 4($v1)
/* C7474 80130D74 AE020000 */  sw        $v0, ($s0)
/* C7478 80130D78 24620018 */  addiu     $v0, $v1, 0x18
/* C747C 80130D7C AC6B0008 */  sw        $t3, 8($v1)
/* C7480 80130D80 AC60000C */  sw        $zero, 0xc($v1)
/* C7484 80130D84 AE020000 */  sw        $v0, ($s0)
/* C7488 80130D88 24620020 */  addiu     $v0, $v1, 0x20
/* C748C 80130D8C AC6D0010 */  sw        $t5, 0x10($v1)
/* C7490 80130D90 AC6C0014 */  sw        $t4, 0x14($v1)
/* C7494 80130D94 AE020000 */  sw        $v0, ($s0)
/* C7498 80130D98 3C02DB02 */  lui       $v0, 0xdb02
/* C749C 80130D9C AC620018 */  sw        $v0, 0x18($v1)
/* C74A0 80130DA0 24020018 */  addiu     $v0, $zero, 0x18
/* C74A4 80130DA4 AC62001C */  sw        $v0, 0x1c($v1)
/* C74A8 80130DA8 24620028 */  addiu     $v0, $v1, 0x28
/* C74AC 80130DAC AE020000 */  sw        $v0, ($s0)
/* C74B0 80130DB0 24620030 */  addiu     $v0, $v1, 0x30
/* C74B4 80130DB4 AC680024 */  sw        $t0, 0x24($v1)
/* C74B8 80130DB8 2508FFF8 */  addiu     $t0, $t0, -8
/* C74BC 80130DBC AC6E0020 */  sw        $t6, 0x20($v1)
/* C74C0 80130DC0 AE020000 */  sw        $v0, ($s0)
/* C74C4 80130DC4 24620038 */  addiu     $v0, $v1, 0x38
/* C74C8 80130DC8 AC6F0028 */  sw        $t7, 0x28($v1)
/* C74CC 80130DCC AC68002C */  sw        $t0, 0x2c($v1)
/* C74D0 80130DD0 AE020000 */  sw        $v0, ($s0)
/* C74D4 80130DD4 2402FFFF */  addiu     $v0, $zero, -1
/* C74D8 80130DD8 AC750030 */  sw        $s5, 0x30($v1)
/* C74DC 80130DDC AC620034 */  sw        $v0, 0x34($v1)
/* C74E0 80130DE0 24620040 */  addiu     $v0, $v1, 0x40
/* C74E4 80130DE4 AE020000 */  sw        $v0, ($s0)
/* C74E8 80130DE8 24620048 */  addiu     $v0, $v1, 0x48
/* C74EC 80130DEC AC760038 */  sw        $s6, 0x38($v1)
/* C74F0 80130DF0 AC60003C */  sw        $zero, 0x3c($v1)
/* C74F4 80130DF4 AE020000 */  sw        $v0, ($s0)
/* C74F8 80130DF8 3C020008 */  lui       $v0, 8
/* C74FC 80130DFC AC780040 */  sw        $t8, 0x40($v1)
/* C7500 80130E00 AC620044 */  sw        $v0, 0x44($v1)
/* C7504 80130E04 24620050 */  addiu     $v0, $v1, 0x50
/* C7508 80130E08 AE020000 */  sw        $v0, ($s0)
/* C750C 80130E0C 24022000 */  addiu     $v0, $zero, 0x2000
/* C7510 80130E10 AC62004C */  sw        $v0, 0x4c($v1)
/* C7514 80130E14 240200C0 */  addiu     $v0, $zero, 0xc0
/* C7518 80130E18 AC790048 */  sw        $t9, 0x48($v1)
/* C751C 80130E1C AC7E0050 */  sw        $fp, 0x50($v1)
/* C7520 80130E20 AC620054 */  sw        $v0, 0x54($v1)
/* C7524 80130E24 8FAA0130 */  lw        $t2, 0x130($sp)
/* C7528 80130E28 27A50118 */  addiu     $a1, $sp, 0x118
/* C752C 80130E2C AC6A0058 */  sw        $t2, 0x58($v1)
/* C7530 80130E30 AC60005C */  sw        $zero, 0x5c($v1)
/* C7534 80130E34 8FAA0134 */  lw        $t2, 0x134($sp)
/* C7538 80130E38 24020C00 */  addiu     $v0, $zero, 0xc00
/* C753C 80130E3C AC6A0060 */  sw        $t2, 0x60($v1)
/* C7540 80130E40 AC620064 */  sw        $v0, 0x64($v1)
/* C7544 80130E44 8FAA0138 */  lw        $t2, 0x138($sp)
/* C7548 80130E48 0080302D */  daddu     $a2, $a0, $zero
/* C754C 80130E4C AC6A0068 */  sw        $t2, 0x68($v1)
/* C7550 80130E50 AC60006C */  sw        $zero, 0x6c($v1)
/* C7554 80130E54 8FAA013C */  lw        $t2, 0x13c($sp)
/* C7558 80130E58 0220382D */  daddu     $a3, $s1, $zero
/* C755C 80130E5C AC6A0070 */  sw        $t2, 0x70($v1)
/* C7560 80130E60 AC600074 */  sw        $zero, 0x74($v1)
/* C7564 80130E64 8E48004C */  lw        $t0, 0x4c($s2)
/* C7568 80130E68 24620058 */  addiu     $v0, $v1, 0x58
/* C756C 80130E6C AE020000 */  sw        $v0, ($s0)
/* C7570 80130E70 AFA80118 */  sw        $t0, 0x118($sp)
/* C7574 80130E74 8E480050 */  lw        $t0, 0x50($s2)
/* C7578 80130E78 24620060 */  addiu     $v0, $v1, 0x60
/* C757C 80130E7C AE020000 */  sw        $v0, ($s0)
/* C7580 80130E80 AFA8011C */  sw        $t0, 0x11c($sp)
/* C7584 80130E84 96480056 */  lhu       $t0, 0x56($s2)
/* C7588 80130E88 24620068 */  addiu     $v0, $v1, 0x68
/* C758C 80130E8C AE020000 */  sw        $v0, ($s0)
/* C7590 80130E90 A7A80120 */  sh        $t0, 0x120($sp)
/* C7594 80130E94 9648005A */  lhu       $t0, 0x5a($s2)
/* C7598 80130E98 24620070 */  addiu     $v0, $v1, 0x70
/* C759C 80130E9C AE020000 */  sw        $v0, ($s0)
/* C75A0 80130EA0 A7A80122 */  sh        $t0, 0x122($sp)
/* C75A4 80130EA4 8E420054 */  lw        $v0, 0x54($s2)
/* C75A8 80130EA8 24630078 */  addiu     $v1, $v1, 0x78
/* C75AC 80130EAC AE030000 */  sw        $v1, ($s0)
/* C75B0 80130EB0 00021023 */  negu      $v0, $v0
/* C75B4 80130EB4 00021FC2 */  srl       $v1, $v0, 0x1f
/* C75B8 80130EB8 00431021 */  addu      $v0, $v0, $v1
/* C75BC 80130EBC 00021043 */  sra       $v0, $v0, 1
/* C75C0 80130EC0 A7A20124 */  sh        $v0, 0x124($sp)
/* C75C4 80130EC4 8E420058 */  lw        $v0, 0x58($s2)
/* C75C8 80130EC8 240300FF */  addiu     $v1, $zero, 0xff
/* C75CC 80130ECC A3A30128 */  sb        $v1, 0x128($sp)
/* C75D0 80130ED0 00021FC2 */  srl       $v1, $v0, 0x1f
/* C75D4 80130ED4 00431021 */  addu      $v0, $v0, $v1
/* C75D8 80130ED8 00021043 */  sra       $v0, $v0, 1
/* C75DC 80130EDC 0C04EBDC */  jal       func_8013AF70
/* C75E0 80130EE0 A7A20126 */   sh       $v0, 0x126($sp)
/* C75E4 80130EE4 3C03D838 */  lui       $v1, 0xd838
/* C75E8 80130EE8 8E020000 */  lw        $v0, ($s0)
/* C75EC 80130EEC 34630002 */  ori       $v1, $v1, 2
/* C75F0 80130EF0 0040202D */  daddu     $a0, $v0, $zero
/* C75F4 80130EF4 24420008 */  addiu     $v0, $v0, 8
/* C75F8 80130EF8 AE020000 */  sw        $v0, ($s0)
/* C75FC 80130EFC AC830000 */  sw        $v1, ($a0)
/* C7600 80130F00 24030040 */  addiu     $v1, $zero, 0x40
/* C7604 80130F04 AC830004 */  sw        $v1, 4($a0)
/* C7608 80130F08 24430008 */  addiu     $v1, $v0, 8
/* C760C 80130F0C AE030000 */  sw        $v1, ($s0)
/* C7610 80130F10 3C03E700 */  lui       $v1, 0xe700
/* C7614 80130F14 AC430000 */  sw        $v1, ($v0)
/* C7618 80130F18 AC400004 */  sw        $zero, 4($v0)
/* C761C 80130F1C 8FBF016C */  lw        $ra, 0x16c($sp)
/* C7620 80130F20 8FBE0168 */  lw        $fp, 0x168($sp)
/* C7624 80130F24 8FB70164 */  lw        $s7, 0x164($sp)
/* C7628 80130F28 8FB60160 */  lw        $s6, 0x160($sp)
/* C762C 80130F2C 8FB5015C */  lw        $s5, 0x15c($sp)
/* C7630 80130F30 8FB40158 */  lw        $s4, 0x158($sp)
/* C7634 80130F34 8FB30154 */  lw        $s3, 0x154($sp)
/* C7638 80130F38 8FB20150 */  lw        $s2, 0x150($sp)
/* C763C 80130F3C 8FB1014C */  lw        $s1, 0x14c($sp)
/* C7640 80130F40 8FB00148 */  lw        $s0, 0x148($sp)
/* C7644 80130F44 D7B80180 */  ldc1      $f24, 0x180($sp)
/* C7648 80130F48 D7B60178 */  ldc1      $f22, 0x178($sp)
/* C764C 80130F4C D7B40170 */  ldc1      $f20, 0x170($sp)
/* C7650 80130F50 03E00008 */  jr        $ra
/* C7654 80130F54 27BD0188 */   addiu    $sp, $sp, 0x188
