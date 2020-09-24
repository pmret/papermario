.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel SetPartRotation
/* 19AF14 8026C634 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19AF18 8026C638 AFB10014 */  sw        $s1, 0x14($sp)
/* 19AF1C 8026C63C 0080882D */  daddu     $s1, $a0, $zero
/* 19AF20 8026C640 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19AF24 8026C644 AFB40020 */  sw        $s4, 0x20($sp)
/* 19AF28 8026C648 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19AF2C 8026C64C AFB20018 */  sw        $s2, 0x18($sp)
/* 19AF30 8026C650 AFB00010 */  sw        $s0, 0x10($sp)
/* 19AF34 8026C654 8E30000C */  lw        $s0, 0xc($s1)
/* 19AF38 8026C658 8E050000 */  lw        $a1, ($s0)
/* 19AF3C 8026C65C 0C0B1EAF */  jal       get_variable
/* 19AF40 8026C660 26100004 */   addiu    $s0, $s0, 4
/* 19AF44 8026C664 0040982D */  daddu     $s3, $v0, $zero
/* 19AF48 8026C668 8E050000 */  lw        $a1, ($s0)
/* 19AF4C 8026C66C 26100004 */  addiu     $s0, $s0, 4
/* 19AF50 8026C670 0C0B1EAF */  jal       get_variable
/* 19AF54 8026C674 0220202D */   daddu    $a0, $s1, $zero
/* 19AF58 8026C678 0040A02D */  daddu     $s4, $v0, $zero
/* 19AF5C 8026C67C 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19AF60 8026C680 16620002 */  bne       $s3, $v0, .L8026C68C
/* 19AF64 8026C684 00000000 */   nop      
/* 19AF68 8026C688 8E330148 */  lw        $s3, 0x148($s1)
.L8026C68C:
/* 19AF6C 8026C68C 8E050000 */  lw        $a1, ($s0)
/* 19AF70 8026C690 26100004 */  addiu     $s0, $s0, 4
/* 19AF74 8026C694 0C0B210B */  jal       get_float_variable
/* 19AF78 8026C698 0220202D */   daddu    $a0, $s1, $zero
/* 19AF7C 8026C69C 8E050000 */  lw        $a1, ($s0)
/* 19AF80 8026C6A0 26100004 */  addiu     $s0, $s0, 4
/* 19AF84 8026C6A4 4600008D */  trunc.w.s $f2, $f0
/* 19AF88 8026C6A8 44121000 */  mfc1      $s2, $f2
/* 19AF8C 8026C6AC 0C0B210B */  jal       get_float_variable
/* 19AF90 8026C6B0 0220202D */   daddu    $a0, $s1, $zero
/* 19AF94 8026C6B4 0220202D */  daddu     $a0, $s1, $zero
/* 19AF98 8026C6B8 8E050000 */  lw        $a1, ($s0)
/* 19AF9C 8026C6BC 4600008D */  trunc.w.s $f2, $f0
/* 19AFA0 8026C6C0 44111000 */  mfc1      $s1, $f2
/* 19AFA4 8026C6C4 0C0B210B */  jal       get_float_variable
/* 19AFA8 8026C6C8 00000000 */   nop      
/* 19AFAC 8026C6CC 4600008D */  trunc.w.s $f2, $f0
/* 19AFB0 8026C6D0 44101000 */  mfc1      $s0, $f2
/* 19AFB4 8026C6D4 0C09A75B */  jal       get_actor
/* 19AFB8 8026C6D8 0260202D */   daddu    $a0, $s3, $zero
/* 19AFBC 8026C6DC 0040202D */  daddu     $a0, $v0, $zero
/* 19AFC0 8026C6E0 0C099117 */  jal       get_actor_part
/* 19AFC4 8026C6E4 0280282D */   daddu    $a1, $s4, $zero
/* 19AFC8 8026C6E8 0040182D */  daddu     $v1, $v0, $zero
/* 19AFCC 8026C6EC 44920000 */  mtc1      $s2, $f0
/* 19AFD0 8026C6F0 00000000 */  nop       
/* 19AFD4 8026C6F4 46800020 */  cvt.s.w   $f0, $f0
/* 19AFD8 8026C6F8 E4600038 */  swc1      $f0, 0x38($v1)
/* 19AFDC 8026C6FC 44910000 */  mtc1      $s1, $f0
/* 19AFE0 8026C700 00000000 */  nop       
/* 19AFE4 8026C704 46800020 */  cvt.s.w   $f0, $f0
/* 19AFE8 8026C708 E460003C */  swc1      $f0, 0x3c($v1)
/* 19AFEC 8026C70C 44900000 */  mtc1      $s0, $f0
/* 19AFF0 8026C710 00000000 */  nop       
/* 19AFF4 8026C714 46800020 */  cvt.s.w   $f0, $f0
/* 19AFF8 8026C718 E4600040 */  swc1      $f0, 0x40($v1)
/* 19AFFC 8026C71C 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19B000 8026C720 8FB40020 */  lw        $s4, 0x20($sp)
/* 19B004 8026C724 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19B008 8026C728 8FB20018 */  lw        $s2, 0x18($sp)
/* 19B00C 8026C72C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19B010 8026C730 8FB00010 */  lw        $s0, 0x10($sp)
/* 19B014 8026C734 24020002 */  addiu     $v0, $zero, 2
/* 19B018 8026C738 03E00008 */  jr        $ra
/* 19B01C 8026C73C 27BD0028 */   addiu    $sp, $sp, 0x28
