.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7BA4
/* FC554 802D7BA4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* FC558 802D7BA8 AFB00018 */  sw        $s0, 0x18($sp)
/* FC55C 802D7BAC 0080802D */  daddu     $s0, $a0, $zero
/* FC560 802D7BB0 AFBF0034 */  sw        $ra, 0x34($sp)
/* FC564 802D7BB4 AFB60030 */  sw        $s6, 0x30($sp)
/* FC568 802D7BB8 AFB5002C */  sw        $s5, 0x2c($sp)
/* FC56C 802D7BBC AFB40028 */  sw        $s4, 0x28($sp)
/* FC570 802D7BC0 AFB30024 */  sw        $s3, 0x24($sp)
/* FC574 802D7BC4 AFB20020 */  sw        $s2, 0x20($sp)
/* FC578 802D7BC8 AFB1001C */  sw        $s1, 0x1c($sp)
/* FC57C 802D7BCC 8E130088 */  lw        $s3, 0x88($s0)
/* FC580 802D7BD0 8E14008C */  lw        $s4, 0x8c($s0)
/* FC584 802D7BD4 8E150090 */  lw        $s5, 0x90($s0)
/* FC588 802D7BD8 8E160094 */  lw        $s6, 0x94($s0)
/* FC58C 802D7BDC 8E120098 */  lw        $s2, 0x98($s0)
/* FC590 802D7BE0 8E11009C */  lw        $s1, 0x9c($s0)
/* FC594 802D7BE4 10A00012 */  beqz      $a1, .L802D7C30
/* FC598 802D7BE8 27A50010 */   addiu    $a1, $sp, 0x10
/* FC59C 802D7BEC 24040001 */  addiu     $a0, $zero, 1
/* FC5A0 802D7BF0 27A60014 */  addiu     $a2, $sp, 0x14
/* FC5A4 802D7BF4 0C04DF70 */  jal       func_80137DC0
/* FC5A8 802D7BF8 AE110070 */   sw       $s1, 0x70($s0)
/* FC5AC 802D7BFC 24040001 */  addiu     $a0, $zero, 1
/* FC5B0 802D7C00 0000282D */  daddu     $a1, $zero, $zero
/* FC5B4 802D7C04 0260302D */  daddu     $a2, $s3, $zero
/* FC5B8 802D7C08 C7A00014 */  lwc1      $f0, 0x14($sp)
/* FC5BC 802D7C0C 4600008D */  trunc.w.s $f2, $f0
/* FC5C0 802D7C10 E6020074 */  swc1      $f2, 0x74($s0)
/* FC5C4 802D7C14 0C04DF93 */  jal       func_80137E4C
/* FC5C8 802D7C18 0280382D */   daddu    $a3, $s4, $zero
/* FC5CC 802D7C1C 24040001 */  addiu     $a0, $zero, 1
/* FC5D0 802D7C20 0080282D */  daddu     $a1, $a0, $zero
/* FC5D4 802D7C24 02A0302D */  daddu     $a2, $s5, $zero
/* FC5D8 802D7C28 0C04DF93 */  jal       func_80137E4C
/* FC5DC 802D7C2C 02C0382D */   daddu    $a3, $s6, $zero
.L802D7C30:
/* FC5E0 802D7C30 24040001 */  addiu     $a0, $zero, 1
/* FC5E4 802D7C34 27A50010 */  addiu     $a1, $sp, 0x10
/* FC5E8 802D7C38 0C04DF70 */  jal       func_80137DC0
/* FC5EC 802D7C3C 27A60014 */   addiu    $a2, $sp, 0x14
/* FC5F0 802D7C40 8E020074 */  lw        $v0, 0x74($s0)
/* FC5F4 802D7C44 8E030070 */  lw        $v1, 0x70($s0)
/* FC5F8 802D7C48 00521023 */  subu      $v0, $v0, $s2
/* FC5FC 802D7C4C 00430018 */  mult      $v0, $v1
/* FC600 802D7C50 00001812 */  mflo      $v1
/* FC604 802D7C54 00000000 */  nop       
/* FC608 802D7C58 16200002 */  bnez      $s1, .L802D7C64
/* FC60C 802D7C5C 0071001A */   div      $zero, $v1, $s1
/* FC610 802D7C60 0007000D */  break     7
.L802D7C64:
/* FC614 802D7C64 2401FFFF */   addiu    $at, $zero, -1
/* FC618 802D7C68 16210004 */  bne       $s1, $at, .L802D7C7C
/* FC61C 802D7C6C 3C018000 */   lui      $at, 0x8000
/* FC620 802D7C70 14610002 */  bne       $v1, $at, .L802D7C7C
/* FC624 802D7C74 00000000 */   nop      
/* FC628 802D7C78 0006000D */  break     6
.L802D7C7C:
/* FC62C 802D7C7C 00001012 */   mflo     $v0
/* FC630 802D7C80 00521021 */  addu      $v0, $v0, $s2
/* FC634 802D7C84 44821000 */  mtc1      $v0, $f2
/* FC638 802D7C88 00000000 */  nop       
/* FC63C 802D7C8C 468010A0 */  cvt.s.w   $f2, $f2
/* FC640 802D7C90 44051000 */  mfc1      $a1, $f2
/* FC644 802D7C94 0C04DF69 */  jal       func_80137DA4
/* FC648 802D7C98 2404000C */   addiu    $a0, $zero, 0xc
/* FC64C 802D7C9C 8E020070 */  lw        $v0, 0x70($s0)
/* FC650 802D7CA0 2442FFFF */  addiu     $v0, $v0, -1
/* FC654 802D7CA4 04400003 */  bltz      $v0, .L802D7CB4
/* FC658 802D7CA8 AE020070 */   sw       $v0, 0x70($s0)
/* FC65C 802D7CAC 080B5F34 */  j         .L802D7CD0
/* FC660 802D7CB0 0000102D */   daddu    $v0, $zero, $zero
.L802D7CB4:
/* FC664 802D7CB4 44921000 */  mtc1      $s2, $f2
/* FC668 802D7CB8 00000000 */  nop       
/* FC66C 802D7CBC 468010A0 */  cvt.s.w   $f2, $f2
/* FC670 802D7CC0 44051000 */  mfc1      $a1, $f2
/* FC674 802D7CC4 0C04DF69 */  jal       func_80137DA4
/* FC678 802D7CC8 2404000C */   addiu    $a0, $zero, 0xc
/* FC67C 802D7CCC 24020002 */  addiu     $v0, $zero, 2
.L802D7CD0:
/* FC680 802D7CD0 8FBF0034 */  lw        $ra, 0x34($sp)
/* FC684 802D7CD4 8FB60030 */  lw        $s6, 0x30($sp)
/* FC688 802D7CD8 8FB5002C */  lw        $s5, 0x2c($sp)
/* FC68C 802D7CDC 8FB40028 */  lw        $s4, 0x28($sp)
/* FC690 802D7CE0 8FB30024 */  lw        $s3, 0x24($sp)
/* FC694 802D7CE4 8FB20020 */  lw        $s2, 0x20($sp)
/* FC698 802D7CE8 8FB1001C */  lw        $s1, 0x1c($sp)
/* FC69C 802D7CEC 8FB00018 */  lw        $s0, 0x18($sp)
/* FC6A0 802D7CF0 03E00008 */  jr        $ra
/* FC6A4 802D7CF4 27BD0038 */   addiu    $sp, $sp, 0x38
