.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E008E4E0
/* 38F340 E008E4E0 27BDFEF8 */  addiu     $sp, $sp, -0x108
/* 38F344 E008E4E4 3C05DB06 */  lui       $a1, 0xdb06
/* 38F348 E008E4E8 34A50024 */  ori       $a1, $a1, 0x24
/* 38F34C E008E4EC AFA40108 */  sw        $a0, 0x108($sp)
/* 38F350 E008E4F0 27A40018 */  addiu     $a0, $sp, 0x18
/* 38F354 E008E4F4 AFB100DC */  sw        $s1, 0xdc($sp)
/* 38F358 E008E4F8 3C110001 */  lui       $s1, 1
/* 38F35C E008E4FC 36311630 */  ori       $s1, $s1, 0x1630
/* 38F360 E008E500 AFB400E8 */  sw        $s4, 0xe8($sp)
/* 38F364 E008E504 3C14800A */  lui       $s4, %hi(gMasterGfxPos)
/* 38F368 E008E508 2694A66C */  addiu     $s4, $s4, %lo(gMasterGfxPos)
/* 38F36C E008E50C 8FA90108 */  lw        $t1, 0x108($sp)
/* 38F370 E008E510 3C02E700 */  lui       $v0, 0xe700
/* 38F374 E008E514 AFBF00FC */  sw        $ra, 0xfc($sp)
/* 38F378 E008E518 AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 38F37C E008E51C AFB700F4 */  sw        $s7, 0xf4($sp)
/* 38F380 E008E520 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 38F384 E008E524 AFB500EC */  sw        $s5, 0xec($sp)
/* 38F388 E008E528 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 38F38C E008E52C AFB200E0 */  sw        $s2, 0xe0($sp)
/* 38F390 E008E530 AFB000D8 */  sw        $s0, 0xd8($sp)
/* 38F394 E008E534 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 38F398 E008E538 8E880000 */  lw        $t0, ($s4)
/* 38F39C E008E53C 8D32000C */  lw        $s2, 0xc($t1)
/* 38F3A0 E008E540 0100182D */  daddu     $v1, $t0, $zero
/* 38F3A4 E008E544 8E550030 */  lw        $s5, 0x30($s2)
/* 38F3A8 E008E548 8E570034 */  lw        $s7, 0x34($s2)
/* 38F3AC E008E54C 8E5E0038 */  lw        $fp, 0x38($s2)
/* 38F3B0 E008E550 25080008 */  addiu     $t0, $t0, 8
/* 38F3B4 E008E554 AC620000 */  sw        $v0, ($v1)
/* 38F3B8 E008E558 AC600004 */  sw        $zero, 4($v1)
/* 38F3BC E008E55C AD050000 */  sw        $a1, ($t0)
/* 38F3C0 E008E560 8D220010 */  lw        $v0, 0x10($t1)
/* 38F3C4 E008E564 24130001 */  addiu     $s3, $zero, 1
/* 38F3C8 E008E568 AE880000 */  sw        $t0, ($s4)
/* 38F3CC E008E56C 8C42001C */  lw        $v0, 0x1c($v0)
/* 38F3D0 E008E570 3C038000 */  lui       $v1, 0x8000
/* 38F3D4 E008E574 00431021 */  addu      $v0, $v0, $v1
/* 38F3D8 E008E578 AD020004 */  sw        $v0, 4($t0)
/* 38F3DC E008E57C 8E450008 */  lw        $a1, 8($s2)
/* 38F3E0 E008E580 8E46000C */  lw        $a2, 0xc($s2)
/* 38F3E4 E008E584 8E470010 */  lw        $a3, 0x10($s2)
/* 38F3E8 E008E588 25080008 */  addiu     $t0, $t0, 8
/* 38F3EC E008E58C 0C080108 */  jal       shim_guTranslateF
/* 38F3F0 E008E590 AE880000 */   sw       $t0, ($s4)
/* 38F3F4 E008E594 27B00098 */  addiu     $s0, $sp, 0x98
/* 38F3F8 E008E598 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 38F3FC E008E59C 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 38F400 E008E5A0 44800000 */  mtc1      $zero, $f0
/* 38F404 E008E5A4 00031080 */  sll       $v0, $v1, 2
/* 38F408 E008E5A8 00431021 */  addu      $v0, $v0, $v1
/* 38F40C E008E5AC 00021080 */  sll       $v0, $v0, 2
/* 38F410 E008E5B0 00431023 */  subu      $v0, $v0, $v1
/* 38F414 E008E5B4 000218C0 */  sll       $v1, $v0, 3
/* 38F418 E008E5B8 00431021 */  addu      $v0, $v0, $v1
/* 38F41C E008E5BC 000210C0 */  sll       $v0, $v0, 3
/* 38F420 E008E5C0 44060000 */  mfc1      $a2, $f0
/* 38F424 E008E5C4 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 38F428 E008E5C8 00220821 */  addu      $at, $at, $v0
/* 38F42C E008E5CC C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 38F430 E008E5D0 3C073F80 */  lui       $a3, 0x3f80
/* 38F434 E008E5D4 46000007 */  neg.s     $f0, $f0
/* 38F438 E008E5D8 44050000 */  mfc1      $a1, $f0
/* 38F43C E008E5DC 0200202D */  daddu     $a0, $s0, $zero
/* 38F440 E008E5E0 0C080104 */  jal       shim_guRotateF
/* 38F444 E008E5E4 AFA60010 */   sw       $a2, 0x10($sp)
/* 38F448 E008E5E8 0200202D */  daddu     $a0, $s0, $zero
/* 38F44C E008E5EC 27A50018 */  addiu     $a1, $sp, 0x18
/* 38F450 E008E5F0 0C080114 */  jal       shim_guMtxCatF
/* 38F454 E008E5F4 00A0302D */   daddu    $a2, $a1, $zero
/* 38F458 E008E5F8 27A40018 */  addiu     $a0, $sp, 0x18
/* 38F45C E008E5FC 3C108007 */  lui       $s0, %hi(gMatrixListPos)
/* 38F460 E008E600 261041F0 */  addiu     $s0, $s0, %lo(gMatrixListPos)
/* 38F464 E008E604 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 38F468 E008E608 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 38F46C E008E60C 96050000 */  lhu       $a1, ($s0)
/* 38F470 E008E610 8EC20000 */  lw        $v0, ($s6)
/* 38F474 E008E614 00052980 */  sll       $a1, $a1, 6
/* 38F478 E008E618 00B12821 */  addu      $a1, $a1, $s1
/* 38F47C E008E61C 0C080118 */  jal       shim_guMtxF2L
/* 38F480 E008E620 00452821 */   addu     $a1, $v0, $a1
/* 38F484 E008E624 3C03DA38 */  lui       $v1, 0xda38
/* 38F488 E008E628 34630002 */  ori       $v1, $v1, 2
/* 38F48C E008E62C 8E850000 */  lw        $a1, ($s4)
/* 38F490 E008E630 96020000 */  lhu       $v0, ($s0)
/* 38F494 E008E634 00A0202D */  daddu     $a0, $a1, $zero
/* 38F498 E008E638 24A50008 */  addiu     $a1, $a1, 8
/* 38F49C E008E63C AE850000 */  sw        $a1, ($s4)
/* 38F4A0 E008E640 AC830000 */  sw        $v1, ($a0)
/* 38F4A4 E008E644 00531821 */  addu      $v1, $v0, $s3
/* 38F4A8 E008E648 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38F4AC E008E64C 00021180 */  sll       $v0, $v0, 6
/* 38F4B0 E008E650 A6030000 */  sh        $v1, ($s0)
/* 38F4B4 E008E654 8EC30000 */  lw        $v1, ($s6)
/* 38F4B8 E008E658 00511021 */  addu      $v0, $v0, $s1
/* 38F4BC E008E65C 00621821 */  addu      $v1, $v1, $v0
/* 38F4C0 E008E660 24A20008 */  addiu     $v0, $a1, 8
/* 38F4C4 E008E664 AC830004 */  sw        $v1, 4($a0)
/* 38F4C8 E008E668 AE820000 */  sw        $v0, ($s4)
/* 38F4CC E008E66C 3C02DE00 */  lui       $v0, 0xde00
/* 38F4D0 E008E670 ACA20000 */  sw        $v0, ($a1)
/* 38F4D4 E008E674 3C020900 */  lui       $v0, 0x900
/* 38F4D8 E008E678 24420080 */  addiu     $v0, $v0, 0x80
/* 38F4DC E008E67C ACA20004 */  sw        $v0, 4($a1)
/* 38F4E0 E008E680 24A20010 */  addiu     $v0, $a1, 0x10
/* 38F4E4 E008E684 AE820000 */  sw        $v0, ($s4)
/* 38F4E8 E008E688 3C02FB00 */  lui       $v0, 0xfb00
/* 38F4EC E008E68C ACA20008 */  sw        $v0, 8($a1)
/* 38F4F0 E008E690 9242003F */  lbu       $v0, 0x3f($s2)
/* 38F4F4 E008E694 92440043 */  lbu       $a0, 0x43($s2)
/* 38F4F8 E008E698 92430047 */  lbu       $v1, 0x47($s2)
/* 38F4FC E008E69C 00021600 */  sll       $v0, $v0, 0x18
/* 38F500 E008E6A0 00042400 */  sll       $a0, $a0, 0x10
/* 38F504 E008E6A4 00441025 */  or        $v0, $v0, $a0
/* 38F508 E008E6A8 00031A00 */  sll       $v1, $v1, 8
/* 38F50C E008E6AC 00431025 */  or        $v0, $v0, $v1
/* 38F510 E008E6B0 ACA2000C */  sw        $v0, 0xc($a1)
/* 38F514 E008E6B4 8FA90108 */  lw        $t1, 0x108($sp)
/* 38F518 E008E6B8 8D220008 */  lw        $v0, 8($t1)
/* 38F51C E008E6BC 0262102A */  slt       $v0, $s3, $v0
/* 38F520 E008E6C0 1040005A */  beqz      $v0, .LE008E82C
/* 38F524 E008E6C4 26520048 */   addiu    $s2, $s2, 0x48
/* 38F528 E008E6C8 0280882D */  daddu     $s1, $s4, $zero
/* 38F52C E008E6CC 00151600 */  sll       $v0, $s5, 0x18
/* 38F530 E008E6D0 32E300FF */  andi      $v1, $s7, 0xff
/* 38F534 E008E6D4 00031C00 */  sll       $v1, $v1, 0x10
/* 38F538 E008E6D8 00431025 */  or        $v0, $v0, $v1
/* 38F53C E008E6DC 33C300FF */  andi      $v1, $fp, 0xff
/* 38F540 E008E6E0 00031A00 */  sll       $v1, $v1, 8
/* 38F544 E008E6E4 0043F025 */  or        $fp, $v0, $v1
/* 38F548 E008E6E8 27B50058 */  addiu     $s5, $sp, 0x58
/* 38F54C E008E6EC 02C0B82D */  daddu     $s7, $s6, $zero
/* 38F550 E008E6F0 0200B02D */  daddu     $s6, $s0, $zero
/* 38F554 E008E6F4 3C140001 */  lui       $s4, 1
/* 38F558 E008E6F8 36941630 */  ori       $s4, $s4, 0x1630
/* 38F55C E008E6FC 26500010 */  addiu     $s0, $s2, 0x10
.LE008E700:
/* 38F560 E008E700 C6140018 */  lwc1      $f20, 0x18($s0)
/* 38F564 E008E704 44800000 */  mtc1      $zero, $f0
/* 38F568 E008E708 00000000 */  nop
/* 38F56C E008E70C 4600A032 */  c.eq.s    $f20, $f0
/* 38F570 E008E710 00000000 */  nop
/* 38F574 E008E714 4501003F */  bc1t      .LE008E814
/* 38F578 E008E718 00000000 */   nop
/* 38F57C E008E71C 8E220000 */  lw        $v0, ($s1)
/* 38F580 E008E720 0040182D */  daddu     $v1, $v0, $zero
/* 38F584 E008E724 24420008 */  addiu     $v0, $v0, 8
/* 38F588 E008E728 AE220000 */  sw        $v0, ($s1)
/* 38F58C E008E72C 3C02FA00 */  lui       $v0, 0xfa00
/* 38F590 E008E730 AC620000 */  sw        $v0, ($v1)
/* 38F594 E008E734 92020007 */  lbu       $v0, 7($s0)
/* 38F598 E008E738 03C21025 */  or        $v0, $fp, $v0
/* 38F59C E008E73C AC620004 */  sw        $v0, 4($v1)
/* 38F5A0 E008E740 8E05FFF8 */  lw        $a1, -8($s0)
/* 38F5A4 E008E744 8E06FFFC */  lw        $a2, -4($s0)
/* 38F5A8 E008E748 8E070000 */  lw        $a3, ($s0)
/* 38F5AC E008E74C 0C080108 */  jal       shim_guTranslateF
/* 38F5B0 E008E750 27A40018 */   addiu    $a0, $sp, 0x18
/* 38F5B4 E008E754 4405A000 */  mfc1      $a1, $f20
/* 38F5B8 E008E758 02A0202D */  daddu     $a0, $s5, $zero
/* 38F5BC E008E75C 00A0302D */  daddu     $a2, $a1, $zero
/* 38F5C0 E008E760 0C080110 */  jal       shim_guScaleF
/* 38F5C4 E008E764 00A0382D */   daddu    $a3, $a1, $zero
/* 38F5C8 E008E768 02A0202D */  daddu     $a0, $s5, $zero
/* 38F5CC E008E76C 27A50018 */  addiu     $a1, $sp, 0x18
/* 38F5D0 E008E770 0C080114 */  jal       shim_guMtxCatF
/* 38F5D4 E008E774 00A0302D */   daddu    $a2, $a1, $zero
/* 38F5D8 E008E778 27A40018 */  addiu     $a0, $sp, 0x18
/* 38F5DC E008E77C 96C50000 */  lhu       $a1, ($s6)
/* 38F5E0 E008E780 8EE20000 */  lw        $v0, ($s7)
/* 38F5E4 E008E784 00052980 */  sll       $a1, $a1, 6
/* 38F5E8 E008E788 00B42821 */  addu      $a1, $a1, $s4
/* 38F5EC E008E78C 0C080118 */  jal       shim_guMtxF2L
/* 38F5F0 E008E790 00452821 */   addu     $a1, $v0, $a1
/* 38F5F4 E008E794 3C06D838 */  lui       $a2, 0xd838
/* 38F5F8 E008E798 8E240000 */  lw        $a0, ($s1)
/* 38F5FC E008E79C 34C60002 */  ori       $a2, $a2, 2
/* 38F600 E008E7A0 0080282D */  daddu     $a1, $a0, $zero
/* 38F604 E008E7A4 24840008 */  addiu     $a0, $a0, 8
/* 38F608 E008E7A8 AE240000 */  sw        $a0, ($s1)
/* 38F60C E008E7AC 96C20000 */  lhu       $v0, ($s6)
/* 38F610 E008E7B0 3C03DA38 */  lui       $v1, 0xda38
/* 38F614 E008E7B4 ACA30000 */  sw        $v1, ($a1)
/* 38F618 E008E7B8 24430001 */  addiu     $v1, $v0, 1
/* 38F61C E008E7BC 3042FFFF */  andi      $v0, $v0, 0xffff
/* 38F620 E008E7C0 00021180 */  sll       $v0, $v0, 6
/* 38F624 E008E7C4 A6C30000 */  sh        $v1, ($s6)
/* 38F628 E008E7C8 8EE30000 */  lw        $v1, ($s7)
/* 38F62C E008E7CC 00541021 */  addu      $v0, $v0, $s4
/* 38F630 E008E7D0 00621821 */  addu      $v1, $v1, $v0
/* 38F634 E008E7D4 24820008 */  addiu     $v0, $a0, 8
/* 38F638 E008E7D8 ACA30004 */  sw        $v1, 4($a1)
/* 38F63C E008E7DC AE220000 */  sw        $v0, ($s1)
/* 38F640 E008E7E0 3C02DE00 */  lui       $v0, 0xde00
/* 38F644 E008E7E4 AC820000 */  sw        $v0, ($a0)
/* 38F648 E008E7E8 32620001 */  andi      $v0, $s3, 1
/* 38F64C E008E7EC 00021080 */  sll       $v0, $v0, 2
/* 38F650 E008E7F0 3C03E009 */  lui       $v1, %hi(D_E008E890)
/* 38F654 E008E7F4 00621821 */  addu      $v1, $v1, $v0
/* 38F658 E008E7F8 8C63E890 */  lw        $v1, %lo(D_E008E890)($v1)
/* 38F65C E008E7FC 24820010 */  addiu     $v0, $a0, 0x10
/* 38F660 E008E800 AE220000 */  sw        $v0, ($s1)
/* 38F664 E008E804 24020040 */  addiu     $v0, $zero, 0x40
/* 38F668 E008E808 AC860008 */  sw        $a2, 8($a0)
/* 38F66C E008E80C AC82000C */  sw        $v0, 0xc($a0)
/* 38F670 E008E810 AC830004 */  sw        $v1, 4($a0)
.LE008E814:
/* 38F674 E008E814 8FA90108 */  lw        $t1, 0x108($sp)
/* 38F678 E008E818 26730001 */  addiu     $s3, $s3, 1
/* 38F67C E008E81C 8D220008 */  lw        $v0, 8($t1)
/* 38F680 E008E820 0262102A */  slt       $v0, $s3, $v0
/* 38F684 E008E824 1440FFB6 */  bnez      $v0, .LE008E700
/* 38F688 E008E828 26100048 */   addiu    $s0, $s0, 0x48
.LE008E82C:
/* 38F68C E008E82C 3C05D838 */  lui       $a1, 0xd838
/* 38F690 E008E830 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 38F694 E008E834 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 38F698 E008E838 8C620000 */  lw        $v0, ($v1)
/* 38F69C E008E83C 34A50002 */  ori       $a1, $a1, 2
/* 38F6A0 E008E840 0040202D */  daddu     $a0, $v0, $zero
/* 38F6A4 E008E844 24420008 */  addiu     $v0, $v0, 8
/* 38F6A8 E008E848 AC620000 */  sw        $v0, ($v1)
/* 38F6AC E008E84C 24020040 */  addiu     $v0, $zero, 0x40
/* 38F6B0 E008E850 AC850000 */  sw        $a1, ($a0)
/* 38F6B4 E008E854 AC820004 */  sw        $v0, 4($a0)
/* 38F6B8 E008E858 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 38F6BC E008E85C 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 38F6C0 E008E860 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 38F6C4 E008E864 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 38F6C8 E008E868 8FB500EC */  lw        $s5, 0xec($sp)
/* 38F6CC E008E86C 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 38F6D0 E008E870 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 38F6D4 E008E874 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 38F6D8 E008E878 8FB100DC */  lw        $s1, 0xdc($sp)
/* 38F6DC E008E87C 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 38F6E0 E008E880 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 38F6E4 E008E884 03E00008 */  jr        $ra
/* 38F6E8 E008E888 27BD0108 */   addiu    $sp, $sp, 0x108
/* 38F6EC E008E88C 00000000 */  nop
