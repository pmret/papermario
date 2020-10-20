.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB4
/* 9085E4 80240BB4 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 9085E8 80240BB8 AFB20020 */  sw        $s2, 0x20($sp)
/* 9085EC 80240BBC 0080902D */  daddu     $s2, $a0, $zero
/* 9085F0 80240BC0 AFB00018 */  sw        $s0, 0x18($sp)
/* 9085F4 80240BC4 00A0802D */  daddu     $s0, $a1, $zero
/* 9085F8 80240BC8 3C05FD05 */  lui       $a1, 0xfd05
/* 9085FC 80240BCC AFBF0028 */  sw        $ra, 0x28($sp)
/* 908600 80240BD0 AFB30024 */  sw        $s3, 0x24($sp)
/* 908604 80240BD4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 908608 80240BD8 8E51000C */  lw        $s1, 0xc($s2)
/* 90860C 80240BDC 0C0B1EAF */  jal       get_variable
/* 908610 80240BE0 34A50F80 */   ori      $a1, $a1, 0xf80
/* 908614 80240BE4 12000012 */  beqz      $s0, .L80240C30
/* 908618 80240BE8 0040982D */   daddu    $s3, $v0, $zero
/* 90861C 80240BEC AE400070 */  sw        $zero, 0x70($s2)
/* 908620 80240BF0 8E250000 */  lw        $a1, ($s1)
/* 908624 80240BF4 26310004 */  addiu     $s1, $s1, 4
/* 908628 80240BF8 0C0B1EAF */  jal       get_variable
/* 90862C 80240BFC 0240202D */   daddu    $a0, $s2, $zero
/* 908630 80240C00 AE420074 */  sw        $v0, 0x74($s2)
/* 908634 80240C04 8E250000 */  lw        $a1, ($s1)
/* 908638 80240C08 26310004 */  addiu     $s1, $s1, 4
/* 90863C 80240C0C 0C0B1EAF */  jal       get_variable
/* 908640 80240C10 0240202D */   daddu    $a0, $s2, $zero
/* 908644 80240C14 AE420078 */  sw        $v0, 0x78($s2)
/* 908648 80240C18 8E250000 */  lw        $a1, ($s1)
/* 90864C 80240C1C 0C0B1EAF */  jal       get_variable
/* 908650 80240C20 0240202D */   daddu    $a0, $s2, $zero
/* 908654 80240C24 AE42007C */  sw        $v0, 0x7c($s2)
/* 908658 80240C28 24020001 */  addiu     $v0, $zero, 1
/* 90865C 80240C2C A662001E */  sh        $v0, 0x1e($s3)
.L80240C30:
/* 908660 80240C30 C6400074 */  lwc1      $f0, 0x74($s2)
/* 908664 80240C34 46800020 */  cvt.s.w   $f0, $f0
/* 908668 80240C38 44050000 */  mfc1      $a1, $f0
/* 90866C 80240C3C C6400078 */  lwc1      $f0, 0x78($s2)
/* 908670 80240C40 46800020 */  cvt.s.w   $f0, $f0
/* 908674 80240C44 8E42007C */  lw        $v0, 0x7c($s2)
/* 908678 80240C48 44060000 */  mfc1      $a2, $f0
/* 90867C 80240C4C AFA20010 */  sw        $v0, 0x10($sp)
/* 908680 80240C50 8E470070 */  lw        $a3, 0x70($s2)
/* 908684 80240C54 0C00A8ED */  jal       update_lerp
/* 908688 80240C58 0000202D */   daddu    $a0, $zero, $zero
/* 90868C 80240C5C E660000C */  swc1      $f0, 0xc($s3)
/* 908690 80240C60 8E430070 */  lw        $v1, 0x70($s2)
/* 908694 80240C64 8E42007C */  lw        $v0, 0x7c($s2)
/* 908698 80240C68 24630001 */  addiu     $v1, $v1, 1
/* 90869C 80240C6C 0062102A */  slt       $v0, $v1, $v0
/* 9086A0 80240C70 AE430070 */  sw        $v1, 0x70($s2)
/* 9086A4 80240C74 8FBF0028 */  lw        $ra, 0x28($sp)
/* 9086A8 80240C78 8FB30024 */  lw        $s3, 0x24($sp)
/* 9086AC 80240C7C 8FB20020 */  lw        $s2, 0x20($sp)
/* 9086B0 80240C80 8FB1001C */  lw        $s1, 0x1c($sp)
/* 9086B4 80240C84 8FB00018 */  lw        $s0, 0x18($sp)
/* 9086B8 80240C88 38420001 */  xori      $v0, $v0, 1
/* 9086BC 80240C8C 03E00008 */  jr        $ra
/* 9086C0 80240C90 27BD0030 */   addiu    $sp, $sp, 0x30
