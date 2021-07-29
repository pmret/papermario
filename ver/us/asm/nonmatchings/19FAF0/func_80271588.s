.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80271588
/* 19FE68 80271588 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 19FE6C 8027158C F7B60030 */  sdc1      $f22, 0x30($sp)
/* 19FE70 80271590 3C013F80 */  lui       $at, 0x3f80
/* 19FE74 80271594 4481B000 */  mtc1      $at, $f22
/* 19FE78 80271598 AFB1001C */  sw        $s1, 0x1c($sp)
/* 19FE7C 8027159C 0080882D */  daddu     $s1, $a0, $zero
/* 19FE80 802715A0 AFB00018 */  sw        $s0, 0x18($sp)
/* 19FE84 802715A4 0000802D */  daddu     $s0, $zero, $zero
/* 19FE88 802715A8 AFB20020 */  sw        $s2, 0x20($sp)
/* 19FE8C 802715AC 24120019 */  addiu     $s2, $zero, 0x19
/* 19FE90 802715B0 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19FE94 802715B4 F7B40028 */  sdc1      $f20, 0x28($sp)
.L802715B8:
/* 19FE98 802715B8 0C00A67F */  jal       rand_int
/* 19FE9C 802715BC 2404001E */   addiu    $a0, $zero, 0x1e
/* 19FEA0 802715C0 24040014 */  addiu     $a0, $zero, 0x14
/* 19FEA4 802715C4 8E230084 */  lw        $v1, 0x84($s1)
/* 19FEA8 802715C8 00621821 */  addu      $v1, $v1, $v0
/* 19FEAC 802715CC 2463FFF1 */  addiu     $v1, $v1, -0xf
/* 19FEB0 802715D0 4483A000 */  mtc1      $v1, $f20
/* 19FEB4 802715D4 00000000 */  nop
/* 19FEB8 802715D8 4680A520 */  cvt.s.w   $f20, $f20
/* 19FEBC 802715DC 0C00A67F */  jal       rand_int
/* 19FEC0 802715E0 26100001 */   addiu    $s0, $s0, 1
/* 19FEC4 802715E4 8E230088 */  lw        $v1, 0x88($s1)
/* 19FEC8 802715E8 8E27008C */  lw        $a3, 0x8c($s1)
/* 19FECC 802715EC 4405A000 */  mfc1      $a1, $f20
/* 19FED0 802715F0 00621821 */  addu      $v1, $v1, $v0
/* 19FED4 802715F4 2463FFF1 */  addiu     $v1, $v1, -0xf
/* 19FED8 802715F8 24E70005 */  addiu     $a3, $a3, 5
/* 19FEDC 802715FC 44830000 */  mtc1      $v1, $f0
/* 19FEE0 80271600 00000000 */  nop
/* 19FEE4 80271604 46800020 */  cvt.s.w   $f0, $f0
/* 19FEE8 80271608 44060000 */  mfc1      $a2, $f0
/* 19FEEC 8027160C 44870000 */  mtc1      $a3, $f0
/* 19FEF0 80271610 00000000 */  nop
/* 19FEF4 80271614 46800020 */  cvt.s.w   $f0, $f0
/* 19FEF8 80271618 44070000 */  mfc1      $a3, $f0
/* 19FEFC 8027161C 0000202D */  daddu     $a0, $zero, $zero
/* 19FF00 80271620 E7B60010 */  swc1      $f22, 0x10($sp)
/* 19FF04 80271624 0C01C7FC */  jal       playFX_69
/* 19FF08 80271628 AFB20014 */   sw       $s2, 0x14($sp)
/* 19FF0C 8027162C 2A020014 */  slti      $v0, $s0, 0x14
/* 19FF10 80271630 1440FFE1 */  bnez      $v0, .L802715B8
/* 19FF14 80271634 24020002 */   addiu    $v0, $zero, 2
/* 19FF18 80271638 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19FF1C 8027163C 8FB20020 */  lw        $s2, 0x20($sp)
/* 19FF20 80271640 8FB1001C */  lw        $s1, 0x1c($sp)
/* 19FF24 80271644 8FB00018 */  lw        $s0, 0x18($sp)
/* 19FF28 80271648 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 19FF2C 8027164C D7B40028 */  ldc1      $f20, 0x28($sp)
/* 19FF30 80271650 03E00008 */  jr        $ra
/* 19FF34 80271654 27BD0038 */   addiu    $sp, $sp, 0x38
