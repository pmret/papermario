.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0056BD0
/* 35E5D0 E0056BD0 27BDFEF0 */  addiu     $sp, $sp, -0x110
/* 35E5D4 E0056BD4 AFBE00F8 */  sw        $fp, 0xf8($sp)
/* 35E5D8 E0056BD8 0080F02D */  daddu     $fp, $a0, $zero
/* 35E5DC E0056BDC AFBF00FC */  sw        $ra, 0xfc($sp)
/* 35E5E0 E0056BE0 AFB700F4 */  sw        $s7, 0xf4($sp)
/* 35E5E4 E0056BE4 AFB600F0 */  sw        $s6, 0xf0($sp)
/* 35E5E8 E0056BE8 AFB500EC */  sw        $s5, 0xec($sp)
/* 35E5EC E0056BEC AFB400E8 */  sw        $s4, 0xe8($sp)
/* 35E5F0 E0056BF0 AFB300E4 */  sw        $s3, 0xe4($sp)
/* 35E5F4 E0056BF4 AFB200E0 */  sw        $s2, 0xe0($sp)
/* 35E5F8 E0056BF8 AFB100DC */  sw        $s1, 0xdc($sp)
/* 35E5FC E0056BFC AFB000D8 */  sw        $s0, 0xd8($sp)
/* 35E600 E0056C00 F7B60108 */  sdc1      $f22, 0x108($sp)
/* 35E604 E0056C04 F7B40100 */  sdc1      $f20, 0x100($sp)
/* 35E608 E0056C08 8FD0000C */  lw        $s0, 0xc($fp)
/* 35E60C E0056C0C 8E020000 */  lw        $v0, ($s0)
/* 35E610 E0056C10 3C170900 */  lui       $s7, 0x900
/* 35E614 E0056C14 26F71280 */  addiu     $s7, $s7, 0x1280
/* 35E618 E0056C18 14400003 */  bnez      $v0, .LE0056C28
/* 35E61C E0056C1C 3C02DB06 */   lui      $v0, 0xdb06
/* 35E620 E0056C20 3C170900 */  lui       $s7, 0x900
/* 35E624 E0056C24 26F71258 */  addiu     $s7, $s7, 0x1258
.LE0056C28:
/* 35E628 E0056C28 34420024 */  ori       $v0, $v0, 0x24
/* 35E62C E0056C2C 3C061464 */  lui       $a2, 0x1464
/* 35E630 E0056C30 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 35E634 E0056C34 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 35E638 E0056C38 8E650000 */  lw        $a1, ($s3)
/* 35E63C E0056C3C 34C61400 */  ori       $a2, $a2, 0x1400
/* 35E640 E0056C40 00A0202D */  daddu     $a0, $a1, $zero
/* 35E644 E0056C44 24A50008 */  addiu     $a1, $a1, 8
/* 35E648 E0056C48 AE650000 */  sw        $a1, ($s3)
/* 35E64C E0056C4C AC820000 */  sw        $v0, ($a0)
/* 35E650 E0056C50 24A20008 */  addiu     $v0, $a1, 8
/* 35E654 E0056C54 AE620000 */  sw        $v0, ($s3)
/* 35E658 E0056C58 8FC30010 */  lw        $v1, 0x10($fp)
/* 35E65C E0056C5C 24A20010 */  addiu     $v0, $a1, 0x10
/* 35E660 E0056C60 AE620000 */  sw        $v0, ($s3)
/* 35E664 E0056C64 8C62001C */  lw        $v0, 0x1c($v1)
/* 35E668 E0056C68 3C038000 */  lui       $v1, 0x8000
/* 35E66C E0056C6C 00431021 */  addu      $v0, $v0, $v1
/* 35E670 E0056C70 AC820004 */  sw        $v0, 4($a0)
/* 35E674 E0056C74 3C02DE00 */  lui       $v0, 0xde00
/* 35E678 E0056C78 ACA20000 */  sw        $v0, ($a1)
/* 35E67C E0056C7C 3C020900 */  lui       $v0, 0x900
/* 35E680 E0056C80 24421180 */  addiu     $v0, $v0, 0x1180
/* 35E684 E0056C84 ACA20004 */  sw        $v0, 4($a1)
/* 35E688 E0056C88 3C02FA00 */  lui       $v0, 0xfa00
/* 35E68C E0056C8C ACA20008 */  sw        $v0, 8($a1)
/* 35E690 E0056C90 92020027 */  lbu       $v0, 0x27($s0)
/* 35E694 E0056C94 24120001 */  addiu     $s2, $zero, 1
/* 35E698 E0056C98 00461025 */  or        $v0, $v0, $a2
/* 35E69C E0056C9C ACA2000C */  sw        $v0, 0xc($a1)
/* 35E6A0 E0056CA0 8E050004 */  lw        $a1, 4($s0)
/* 35E6A4 E0056CA4 8E060008 */  lw        $a2, 8($s0)
/* 35E6A8 E0056CA8 8E07000C */  lw        $a3, 0xc($s0)
/* 35E6AC E0056CAC 0C080108 */  jal       shim_guTranslateF
/* 35E6B0 E0056CB0 27A40018 */   addiu    $a0, $sp, 0x18
/* 35E6B4 E0056CB4 27B10058 */  addiu     $s1, $sp, 0x58
/* 35E6B8 E0056CB8 4480A000 */  mtc1      $zero, $f20
/* 35E6BC E0056CBC 3C038007 */  lui       $v1, %hi(gCurrentCameraID)
/* 35E6C0 E0056CC0 8C637410 */  lw        $v1, %lo(gCurrentCameraID)($v1)
/* 35E6C4 E0056CC4 3C013F80 */  lui       $at, 0x3f80
/* 35E6C8 E0056CC8 4481B000 */  mtc1      $at, $f22
/* 35E6CC E0056CCC 00031080 */  sll       $v0, $v1, 2
/* 35E6D0 E0056CD0 00431021 */  addu      $v0, $v0, $v1
/* 35E6D4 E0056CD4 00021080 */  sll       $v0, $v0, 2
/* 35E6D8 E0056CD8 00431023 */  subu      $v0, $v0, $v1
/* 35E6DC E0056CDC 000218C0 */  sll       $v1, $v0, 3
/* 35E6E0 E0056CE0 00431021 */  addu      $v0, $v0, $v1
/* 35E6E4 E0056CE4 000210C0 */  sll       $v0, $v0, 3
/* 35E6E8 E0056CE8 4406A000 */  mfc1      $a2, $f20
/* 35E6EC E0056CEC 3C01800B */  lui       $at, %hi(gCameras+0x6C)
/* 35E6F0 E0056CF0 00220821 */  addu      $at, $at, $v0
/* 35E6F4 E0056CF4 C4201DEC */  lwc1      $f0, %lo(gCameras+0x6C)($at)
/* 35E6F8 E0056CF8 4407B000 */  mfc1      $a3, $f22
/* 35E6FC E0056CFC 46000007 */  neg.s     $f0, $f0
/* 35E700 E0056D00 44050000 */  mfc1      $a1, $f0
/* 35E704 E0056D04 0220202D */  daddu     $a0, $s1, $zero
/* 35E708 E0056D08 0C080104 */  jal       shim_guRotateF
/* 35E70C E0056D0C E7B40010 */   swc1     $f20, 0x10($sp)
/* 35E710 E0056D10 0220202D */  daddu     $a0, $s1, $zero
/* 35E714 E0056D14 27A50018 */  addiu     $a1, $sp, 0x18
/* 35E718 E0056D18 0C080114 */  jal       shim_guMtxCatF
/* 35E71C E0056D1C 27A60098 */   addiu    $a2, $sp, 0x98
/* 35E720 E0056D20 8FC20008 */  lw        $v0, 8($fp)
/* 35E724 E0056D24 0242102A */  slt       $v0, $s2, $v0
/* 35E728 E0056D28 1040004C */  beqz      $v0, .LE0056E5C
/* 35E72C E0056D2C 2610003C */   addiu    $s0, $s0, 0x3c
/* 35E730 E0056D30 3C16800A */  lui       $s6, %hi(gDisplayContext)
/* 35E734 E0056D34 26D6A674 */  addiu     $s6, $s6, %lo(gDisplayContext)
/* 35E738 E0056D38 3C158007 */  lui       $s5, %hi(gMatrixListPos)
/* 35E73C E0056D3C 26B541F0 */  addiu     $s5, $s5, %lo(gMatrixListPos)
/* 35E740 E0056D40 3C140001 */  lui       $s4, 1
/* 35E744 E0056D44 36941630 */  ori       $s4, $s4, 0x1630
/* 35E748 E0056D48 26100020 */  addiu     $s0, $s0, 0x20
.LE0056D4C:
/* 35E74C E0056D4C 0220202D */  daddu     $a0, $s1, $zero
/* 35E750 E0056D50 8E05FFE4 */  lw        $a1, -0x1c($s0)
/* 35E754 E0056D54 8E06FFE8 */  lw        $a2, -0x18($s0)
/* 35E758 E0056D58 8E07FFEC */  lw        $a3, -0x14($s0)
/* 35E75C E0056D5C 0C080108 */  jal       shim_guTranslateF
/* 35E760 E0056D60 26520001 */   addiu    $s2, $s2, 1
/* 35E764 E0056D64 0220202D */  daddu     $a0, $s1, $zero
/* 35E768 E0056D68 27A50098 */  addiu     $a1, $sp, 0x98
/* 35E76C E0056D6C 0C080114 */  jal       shim_guMtxCatF
/* 35E770 E0056D70 27A60018 */   addiu    $a2, $sp, 0x18
/* 35E774 E0056D74 E7B60010 */  swc1      $f22, 0x10($sp)
/* 35E778 E0056D78 8E05FFF8 */  lw        $a1, -8($s0)
/* 35E77C E0056D7C 4406A000 */  mfc1      $a2, $f20
/* 35E780 E0056D80 4407A000 */  mfc1      $a3, $f20
/* 35E784 E0056D84 0C080104 */  jal       shim_guRotateF
/* 35E788 E0056D88 0220202D */   daddu    $a0, $s1, $zero
/* 35E78C E0056D8C 0220202D */  daddu     $a0, $s1, $zero
/* 35E790 E0056D90 27A50018 */  addiu     $a1, $sp, 0x18
/* 35E794 E0056D94 0C080114 */  jal       shim_guMtxCatF
/* 35E798 E0056D98 00A0302D */   daddu    $a2, $a1, $zero
/* 35E79C E0056D9C 0220202D */  daddu     $a0, $s1, $zero
/* 35E7A0 E0056DA0 E7B40010 */  swc1      $f20, 0x10($sp)
/* 35E7A4 E0056DA4 8E050000 */  lw        $a1, ($s0)
/* 35E7A8 E0056DA8 4406A000 */  mfc1      $a2, $f20
/* 35E7AC E0056DAC 4407B000 */  mfc1      $a3, $f22
/* 35E7B0 E0056DB0 0C080104 */  jal       shim_guRotateF
/* 35E7B4 E0056DB4 2610003C */   addiu    $s0, $s0, 0x3c
/* 35E7B8 E0056DB8 0220202D */  daddu     $a0, $s1, $zero
/* 35E7BC E0056DBC 27A50018 */  addiu     $a1, $sp, 0x18
/* 35E7C0 E0056DC0 0C080114 */  jal       shim_guMtxCatF
/* 35E7C4 E0056DC4 00A0302D */   daddu    $a2, $a1, $zero
/* 35E7C8 E0056DC8 27A40018 */  addiu     $a0, $sp, 0x18
/* 35E7CC E0056DCC 96A50000 */  lhu       $a1, ($s5)
/* 35E7D0 E0056DD0 8EC20000 */  lw        $v0, ($s6)
/* 35E7D4 E0056DD4 00052980 */  sll       $a1, $a1, 6
/* 35E7D8 E0056DD8 00B42821 */  addu      $a1, $a1, $s4
/* 35E7DC E0056DDC 0C080118 */  jal       shim_guMtxF2L
/* 35E7E0 E0056DE0 00452821 */   addu     $a1, $v0, $a1
/* 35E7E4 E0056DE4 3C06D838 */  lui       $a2, 0xd838
/* 35E7E8 E0056DE8 8E640000 */  lw        $a0, ($s3)
/* 35E7EC E0056DEC 34C60002 */  ori       $a2, $a2, 2
/* 35E7F0 E0056DF0 0080282D */  daddu     $a1, $a0, $zero
/* 35E7F4 E0056DF4 24840008 */  addiu     $a0, $a0, 8
/* 35E7F8 E0056DF8 AE640000 */  sw        $a0, ($s3)
/* 35E7FC E0056DFC 96A20000 */  lhu       $v0, ($s5)
/* 35E800 E0056E00 3C03DA38 */  lui       $v1, 0xda38
/* 35E804 E0056E04 ACA30000 */  sw        $v1, ($a1)
/* 35E808 E0056E08 24430001 */  addiu     $v1, $v0, 1
/* 35E80C E0056E0C 3042FFFF */  andi      $v0, $v0, 0xffff
/* 35E810 E0056E10 00021180 */  sll       $v0, $v0, 6
/* 35E814 E0056E14 A6A30000 */  sh        $v1, ($s5)
/* 35E818 E0056E18 8EC30000 */  lw        $v1, ($s6)
/* 35E81C E0056E1C 00541021 */  addu      $v0, $v0, $s4
/* 35E820 E0056E20 00621821 */  addu      $v1, $v1, $v0
/* 35E824 E0056E24 24820008 */  addiu     $v0, $a0, 8
/* 35E828 E0056E28 ACA30004 */  sw        $v1, 4($a1)
/* 35E82C E0056E2C AE620000 */  sw        $v0, ($s3)
/* 35E830 E0056E30 3C02DE00 */  lui       $v0, 0xde00
/* 35E834 E0056E34 AC820000 */  sw        $v0, ($a0)
/* 35E838 E0056E38 24020040 */  addiu     $v0, $zero, 0x40
/* 35E83C E0056E3C AC970004 */  sw        $s7, 4($a0)
/* 35E840 E0056E40 AC860008 */  sw        $a2, 8($a0)
/* 35E844 E0056E44 AC82000C */  sw        $v0, 0xc($a0)
/* 35E848 E0056E48 8FC20008 */  lw        $v0, 8($fp)
/* 35E84C E0056E4C 24840010 */  addiu     $a0, $a0, 0x10
/* 35E850 E0056E50 0242102A */  slt       $v0, $s2, $v0
/* 35E854 E0056E54 1440FFBD */  bnez      $v0, .LE0056D4C
/* 35E858 E0056E58 AE640000 */   sw       $a0, ($s3)
.LE0056E5C:
/* 35E85C E0056E5C 8FBF00FC */  lw        $ra, 0xfc($sp)
/* 35E860 E0056E60 8FBE00F8 */  lw        $fp, 0xf8($sp)
/* 35E864 E0056E64 8FB700F4 */  lw        $s7, 0xf4($sp)
/* 35E868 E0056E68 8FB600F0 */  lw        $s6, 0xf0($sp)
/* 35E86C E0056E6C 8FB500EC */  lw        $s5, 0xec($sp)
/* 35E870 E0056E70 8FB400E8 */  lw        $s4, 0xe8($sp)
/* 35E874 E0056E74 8FB300E4 */  lw        $s3, 0xe4($sp)
/* 35E878 E0056E78 8FB200E0 */  lw        $s2, 0xe0($sp)
/* 35E87C E0056E7C 8FB100DC */  lw        $s1, 0xdc($sp)
/* 35E880 E0056E80 8FB000D8 */  lw        $s0, 0xd8($sp)
/* 35E884 E0056E84 D7B60108 */  ldc1      $f22, 0x108($sp)
/* 35E888 E0056E88 D7B40100 */  ldc1      $f20, 0x100($sp)
/* 35E88C E0056E8C 03E00008 */  jr        $ra
/* 35E890 E0056E90 27BD0110 */   addiu    $sp, $sp, 0x110
/* 35E894 E0056E94 00000000 */  nop
/* 35E898 E0056E98 00000000 */  nop
/* 35E89C E0056E9C 00000000 */  nop
