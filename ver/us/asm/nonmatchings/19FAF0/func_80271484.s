.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80271484
/* 19FD64 80271484 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 19FD68 80271488 AFB00028 */  sw        $s0, 0x28($sp)
/* 19FD6C 8027148C 0080802D */  daddu     $s0, $a0, $zero
/* 19FD70 80271490 AFBF0034 */  sw        $ra, 0x34($sp)
/* 19FD74 80271494 AFB20030 */  sw        $s2, 0x30($sp)
/* 19FD78 80271498 AFB1002C */  sw        $s1, 0x2c($sp)
/* 19FD7C 8027149C F7B80048 */  sdc1      $f24, 0x48($sp)
/* 19FD80 802714A0 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 19FD84 802714A4 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 19FD88 802714A8 C6000084 */  lwc1      $f0, 0x84($s0)
/* 19FD8C 802714AC 46800020 */  cvt.s.w   $f0, $f0
/* 19FD90 802714B0 44050000 */  mfc1      $a1, $f0
/* 19FD94 802714B4 C6000088 */  lwc1      $f0, 0x88($s0)
/* 19FD98 802714B8 46800020 */  cvt.s.w   $f0, $f0
/* 19FD9C 802714BC 44060000 */  mfc1      $a2, $f0
/* 19FDA0 802714C0 C600008C */  lwc1      $f0, 0x8c($s0)
/* 19FDA4 802714C4 46800020 */  cvt.s.w   $f0, $f0
/* 19FDA8 802714C8 0000202D */  daddu     $a0, $zero, $zero
/* 19FDAC 802714CC 2412000A */  addiu     $s2, $zero, 0xa
/* 19FDB0 802714D0 8E020090 */  lw        $v0, 0x90($s0)
/* 19FDB4 802714D4 44070000 */  mfc1      $a3, $f0
/* 19FDB8 802714D8 3C013F80 */  lui       $at, 0x3f80
/* 19FDBC 802714DC 4481C000 */  mtc1      $at, $f24
/* 19FDC0 802714E0 90430191 */  lbu       $v1, 0x191($v0)
/* 19FDC4 802714E4 90420190 */  lbu       $v0, 0x190($v0)
/* 19FDC8 802714E8 2411001E */  addiu     $s1, $zero, 0x1e
/* 19FDCC 802714EC E7B80018 */  swc1      $f24, 0x18($sp)
/* 19FDD0 802714F0 AFB2001C */  sw        $s2, 0x1c($sp)
/* 19FDD4 802714F4 AFB10020 */  sw        $s1, 0x20($sp)
/* 19FDD8 802714F8 4483B000 */  mtc1      $v1, $f22
/* 19FDDC 802714FC 00000000 */  nop
/* 19FDE0 80271500 4680B5A0 */  cvt.s.w   $f22, $f22
/* 19FDE4 80271504 00021042 */  srl       $v0, $v0, 1
/* 19FDE8 80271508 4482A000 */  mtc1      $v0, $f20
/* 19FDEC 8027150C 00000000 */  nop
/* 19FDF0 80271510 4680A520 */  cvt.s.w   $f20, $f20
/* 19FDF4 80271514 E7B60010 */  swc1      $f22, 0x10($sp)
/* 19FDF8 80271518 0C01C8D4 */  jal       playFX_72
/* 19FDFC 8027151C E7B40014 */   swc1     $f20, 0x14($sp)
/* 19FE00 80271520 C6000084 */  lwc1      $f0, 0x84($s0)
/* 19FE04 80271524 46800020 */  cvt.s.w   $f0, $f0
/* 19FE08 80271528 44050000 */  mfc1      $a1, $f0
/* 19FE0C 8027152C C6000088 */  lwc1      $f0, 0x88($s0)
/* 19FE10 80271530 46800020 */  cvt.s.w   $f0, $f0
/* 19FE14 80271534 44060000 */  mfc1      $a2, $f0
/* 19FE18 80271538 C600008C */  lwc1      $f0, 0x8c($s0)
/* 19FE1C 8027153C 46800020 */  cvt.s.w   $f0, $f0
/* 19FE20 80271540 44070000 */  mfc1      $a3, $f0
/* 19FE24 80271544 24040001 */  addiu     $a0, $zero, 1
/* 19FE28 80271548 E7B60010 */  swc1      $f22, 0x10($sp)
/* 19FE2C 8027154C E7B40014 */  swc1      $f20, 0x14($sp)
/* 19FE30 80271550 E7B80018 */  swc1      $f24, 0x18($sp)
/* 19FE34 80271554 AFB2001C */  sw        $s2, 0x1c($sp)
/* 19FE38 80271558 0C01C8D4 */  jal       playFX_72
/* 19FE3C 8027155C AFB10020 */   sw       $s1, 0x20($sp)
/* 19FE40 80271560 8FBF0034 */  lw        $ra, 0x34($sp)
/* 19FE44 80271564 8FB20030 */  lw        $s2, 0x30($sp)
/* 19FE48 80271568 8FB1002C */  lw        $s1, 0x2c($sp)
/* 19FE4C 8027156C 8FB00028 */  lw        $s0, 0x28($sp)
/* 19FE50 80271570 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 19FE54 80271574 D7B60040 */  ldc1      $f22, 0x40($sp)
/* 19FE58 80271578 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 19FE5C 8027157C 24020002 */  addiu     $v0, $zero, 2
/* 19FE60 80271580 03E00008 */  jr        $ra
/* 19FE64 80271584 27BD0050 */   addiu    $sp, $sp, 0x50
