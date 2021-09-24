.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E011E578
/* 409F08 E011E578 27BDFF50 */  addiu     $sp, $sp, -0xb0
/* 409F0C E011E57C 0080302D */  daddu     $a2, $a0, $zero
/* 409F10 E011E580 3C07DB06 */  lui       $a3, 0xdb06
/* 409F14 E011E584 34E70024 */  ori       $a3, $a3, 0x24
/* 409F18 E011E588 27A40010 */  addiu     $a0, $sp, 0x10
/* 409F1C E011E58C AFB500A4 */  sw        $s5, 0xa4($sp)
/* 409F20 E011E590 3C150001 */  lui       $s5, 1
/* 409F24 E011E594 36B51630 */  ori       $s5, $s5, 0x1630
/* 409F28 E011E598 AFB3009C */  sw        $s3, 0x9c($sp)
/* 409F2C E011E59C 3C13800A */  lui       $s3, %hi(gMasterGfxPos)
/* 409F30 E011E5A0 2673A66C */  addiu     $s3, $s3, %lo(gMasterGfxPos)
/* 409F34 E011E5A4 3C02E700 */  lui       $v0, 0xe700
/* 409F38 E011E5A8 AFBF00AC */  sw        $ra, 0xac($sp)
/* 409F3C E011E5AC AFB600A8 */  sw        $s6, 0xa8($sp)
/* 409F40 E011E5B0 AFB400A0 */  sw        $s4, 0xa0($sp)
/* 409F44 E011E5B4 AFB20098 */  sw        $s2, 0x98($sp)
/* 409F48 E011E5B8 AFB10094 */  sw        $s1, 0x94($sp)
/* 409F4C E011E5BC AFB00090 */  sw        $s0, 0x90($sp)
/* 409F50 E011E5C0 8E650000 */  lw        $a1, ($s3)
/* 409F54 E011E5C4 8CD2000C */  lw        $s2, 0xc($a2)
/* 409F58 E011E5C8 00A0182D */  daddu     $v1, $a1, $zero
/* 409F5C E011E5CC 9256001B */  lbu       $s6, 0x1b($s2)
/* 409F60 E011E5D0 24A50008 */  addiu     $a1, $a1, 8
/* 409F64 E011E5D4 AE650000 */  sw        $a1, ($s3)
/* 409F68 E011E5D8 AC620000 */  sw        $v0, ($v1)
/* 409F6C E011E5DC AC600004 */  sw        $zero, 4($v1)
/* 409F70 E011E5E0 ACA70000 */  sw        $a3, ($a1)
/* 409F74 E011E5E4 8CC30010 */  lw        $v1, 0x10($a2)
/* 409F78 E011E5E8 24A20008 */  addiu     $v0, $a1, 8
/* 409F7C E011E5EC AE620000 */  sw        $v0, ($s3)
/* 409F80 E011E5F0 8C62001C */  lw        $v0, 0x1c($v1)
/* 409F84 E011E5F4 3C038000 */  lui       $v1, 0x8000
/* 409F88 E011E5F8 00431021 */  addu      $v0, $v0, $v1
/* 409F8C E011E5FC 3C03800B */  lui       $v1, %hi(gCameras)
/* 409F90 E011E600 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* 409F94 E011E604 ACA20004 */  sw        $v0, 4($a1)
/* 409F98 E011E608 8E450004 */  lw        $a1, 4($s2)
/* 409F9C E011E60C 8E460008 */  lw        $a2, 8($s2)
/* 409FA0 E011E610 3C028007 */  lui       $v0, %hi(gCurrentCameraID)
/* 409FA4 E011E614 8C427410 */  lw        $v0, %lo(gCurrentCameraID)($v0)
/* 409FA8 E011E618 8E47000C */  lw        $a3, 0xc($s2)
/* 409FAC E011E61C 00028080 */  sll       $s0, $v0, 2
/* 409FB0 E011E620 02028021 */  addu      $s0, $s0, $v0
/* 409FB4 E011E624 00108080 */  sll       $s0, $s0, 2
/* 409FB8 E011E628 02028023 */  subu      $s0, $s0, $v0
/* 409FBC E011E62C 001010C0 */  sll       $v0, $s0, 3
/* 409FC0 E011E630 02028021 */  addu      $s0, $s0, $v0
/* 409FC4 E011E634 001080C0 */  sll       $s0, $s0, 3
/* 409FC8 E011E638 0C080108 */  jal       shim_guTranslateF
/* 409FCC E011E63C 02038021 */   addu     $s0, $s0, $v1
/* 409FD0 E011E640 27B10050 */  addiu     $s1, $sp, 0x50
/* 409FD4 E011E644 8E450020 */  lw        $a1, 0x20($s2)
/* 409FD8 E011E648 0220202D */  daddu     $a0, $s1, $zero
/* 409FDC E011E64C 00A0302D */  daddu     $a2, $a1, $zero
/* 409FE0 E011E650 0C080110 */  jal       shim_guScaleF
/* 409FE4 E011E654 00A0382D */   daddu    $a3, $a1, $zero
/* 409FE8 E011E658 0220202D */  daddu     $a0, $s1, $zero
/* 409FEC E011E65C 27A50010 */  addiu     $a1, $sp, 0x10
/* 409FF0 E011E660 0C080114 */  jal       shim_guMtxCatF
/* 409FF4 E011E664 00A0302D */   daddu    $a2, $a1, $zero
/* 409FF8 E011E668 27A40010 */  addiu     $a0, $sp, 0x10
/* 409FFC E011E66C 3C118007 */  lui       $s1, %hi(gMatrixListPos)
/* 40A000 E011E670 263141F0 */  addiu     $s1, $s1, %lo(gMatrixListPos)
/* 40A004 E011E674 3C14800A */  lui       $s4, %hi(gDisplayContext)
/* 40A008 E011E678 2694A674 */  addiu     $s4, $s4, %lo(gDisplayContext)
/* 40A00C E011E67C 96250000 */  lhu       $a1, ($s1)
/* 40A010 E011E680 8E820000 */  lw        $v0, ($s4)
/* 40A014 E011E684 00052980 */  sll       $a1, $a1, 6
/* 40A018 E011E688 00B52821 */  addu      $a1, $a1, $s5
/* 40A01C E011E68C 0C080118 */  jal       shim_guMtxF2L
/* 40A020 E011E690 00452821 */   addu     $a1, $v0, $a1
/* 40A024 E011E694 3C03DA38 */  lui       $v1, 0xda38
/* 40A028 E011E698 34630002 */  ori       $v1, $v1, 2
/* 40A02C E011E69C 3C06DA38 */  lui       $a2, 0xda38
/* 40A030 E011E6A0 34C60001 */  ori       $a2, $a2, 1
/* 40A034 E011E6A4 3C07DE00 */  lui       $a3, 0xde00
/* 40A038 E011E6A8 8E640000 */  lw        $a0, ($s3)
/* 40A03C E011E6AC 96220000 */  lhu       $v0, ($s1)
/* 40A040 E011E6B0 0080282D */  daddu     $a1, $a0, $zero
/* 40A044 E011E6B4 24840008 */  addiu     $a0, $a0, 8
/* 40A048 E011E6B8 AE640000 */  sw        $a0, ($s3)
/* 40A04C E011E6BC ACA30000 */  sw        $v1, ($a1)
/* 40A050 E011E6C0 24430001 */  addiu     $v1, $v0, 1
/* 40A054 E011E6C4 3042FFFF */  andi      $v0, $v0, 0xffff
/* 40A058 E011E6C8 00021180 */  sll       $v0, $v0, 6
/* 40A05C E011E6CC A6230000 */  sh        $v1, ($s1)
/* 40A060 E011E6D0 8E830000 */  lw        $v1, ($s4)
/* 40A064 E011E6D4 00551021 */  addu      $v0, $v0, $s5
/* 40A068 E011E6D8 00621821 */  addu      $v1, $v1, $v0
/* 40A06C E011E6DC 24820008 */  addiu     $v0, $a0, 8
/* 40A070 E011E6E0 ACA30004 */  sw        $v1, 4($a1)
/* 40A074 E011E6E4 AE620000 */  sw        $v0, ($s3)
/* 40A078 E011E6E8 24820010 */  addiu     $v0, $a0, 0x10
/* 40A07C E011E6EC AC860000 */  sw        $a2, ($a0)
/* 40A080 E011E6F0 AE620000 */  sw        $v0, ($s3)
/* 40A084 E011E6F4 8E030204 */  lw        $v1, 0x204($s0)
/* 40A088 E011E6F8 3C02FA00 */  lui       $v0, 0xfa00
/* 40A08C E011E6FC AC820008 */  sw        $v0, 8($a0)
/* 40A090 E011E700 AC830004 */  sw        $v1, 4($a0)
/* 40A094 E011E704 92420018 */  lbu       $v0, 0x18($s2)
/* 40A098 E011E708 92450019 */  lbu       $a1, 0x19($s2)
/* 40A09C E011E70C 9246001A */  lbu       $a2, 0x1a($s2)
/* 40A0A0 E011E710 24830018 */  addiu     $v1, $a0, 0x18
/* 40A0A4 E011E714 AE630000 */  sw        $v1, ($s3)
/* 40A0A8 E011E718 3C03FB00 */  lui       $v1, 0xfb00
/* 40A0AC E011E71C AC830010 */  sw        $v1, 0x10($a0)
/* 40A0B0 E011E720 00021600 */  sll       $v0, $v0, 0x18
/* 40A0B4 E011E724 00052C00 */  sll       $a1, $a1, 0x10
/* 40A0B8 E011E728 00451025 */  or        $v0, $v0, $a1
/* 40A0BC E011E72C 00063200 */  sll       $a2, $a2, 8
/* 40A0C0 E011E730 00461025 */  or        $v0, $v0, $a2
/* 40A0C4 E011E734 00561025 */  or        $v0, $v0, $s6
/* 40A0C8 E011E738 AC82000C */  sw        $v0, 0xc($a0)
/* 40A0CC E011E73C 9242001C */  lbu       $v0, 0x1c($s2)
/* 40A0D0 E011E740 9245001D */  lbu       $a1, 0x1d($s2)
/* 40A0D4 E011E744 9246001E */  lbu       $a2, 0x1e($s2)
/* 40A0D8 E011E748 9248001F */  lbu       $t0, 0x1f($s2)
/* 40A0DC E011E74C 24830020 */  addiu     $v1, $a0, 0x20
/* 40A0E0 E011E750 AE630000 */  sw        $v1, ($s3)
/* 40A0E4 E011E754 AC870018 */  sw        $a3, 0x18($a0)
/* 40A0E8 E011E758 00021600 */  sll       $v0, $v0, 0x18
/* 40A0EC E011E75C 00052C00 */  sll       $a1, $a1, 0x10
/* 40A0F0 E011E760 00451025 */  or        $v0, $v0, $a1
/* 40A0F4 E011E764 00063200 */  sll       $a2, $a2, 8
/* 40A0F8 E011E768 00461025 */  or        $v0, $v0, $a2
/* 40A0FC E011E76C 00481025 */  or        $v0, $v0, $t0
/* 40A100 E011E770 AC820014 */  sw        $v0, 0x14($a0)
/* 40A104 E011E774 3C03E012 */  lui       $v1, %hi(D_E011E800)
/* 40A108 E011E778 8C63E800 */  lw        $v1, %lo(D_E011E800)($v1)
/* 40A10C E011E77C 24820028 */  addiu     $v0, $a0, 0x28
/* 40A110 E011E780 AE620000 */  sw        $v0, ($s3)
/* 40A114 E011E784 AC870020 */  sw        $a3, 0x20($a0)
/* 40A118 E011E788 AC83001C */  sw        $v1, 0x1c($a0)
/* 40A11C E011E78C 82420024 */  lb        $v0, 0x24($s2)
/* 40A120 E011E790 3C03D838 */  lui       $v1, 0xd838
/* 40A124 E011E794 00021080 */  sll       $v0, $v0, 2
/* 40A128 E011E798 3C01E012 */  lui       $at, %hi(D_E011E7F0)
/* 40A12C E011E79C 00220821 */  addu      $at, $at, $v0
/* 40A130 E011E7A0 8C22E7F0 */  lw        $v0, %lo(D_E011E7F0)($at)
/* 40A134 E011E7A4 34630002 */  ori       $v1, $v1, 2
/* 40A138 E011E7A8 AC820024 */  sw        $v0, 0x24($a0)
/* 40A13C E011E7AC 24820030 */  addiu     $v0, $a0, 0x30
/* 40A140 E011E7B0 AE620000 */  sw        $v0, ($s3)
/* 40A144 E011E7B4 24020040 */  addiu     $v0, $zero, 0x40
/* 40A148 E011E7B8 AC830028 */  sw        $v1, 0x28($a0)
/* 40A14C E011E7BC AC82002C */  sw        $v0, 0x2c($a0)
/* 40A150 E011E7C0 8FBF00AC */  lw        $ra, 0xac($sp)
/* 40A154 E011E7C4 8FB600A8 */  lw        $s6, 0xa8($sp)
/* 40A158 E011E7C8 8FB500A4 */  lw        $s5, 0xa4($sp)
/* 40A15C E011E7CC 8FB400A0 */  lw        $s4, 0xa0($sp)
/* 40A160 E011E7D0 8FB3009C */  lw        $s3, 0x9c($sp)
/* 40A164 E011E7D4 8FB20098 */  lw        $s2, 0x98($sp)
/* 40A168 E011E7D8 8FB10094 */  lw        $s1, 0x94($sp)
/* 40A16C E011E7DC 8FB00090 */  lw        $s0, 0x90($sp)
/* 40A170 E011E7E0 03E00008 */  jr        $ra
/* 40A174 E011E7E4 27BD00B0 */   addiu    $sp, $sp, 0xb0
/* 40A178 E011E7E8 00000000 */  nop
/* 40A17C E011E7EC 00000000 */  nop
