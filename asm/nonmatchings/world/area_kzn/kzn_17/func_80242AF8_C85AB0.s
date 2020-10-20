.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242AF8_C885A8
/* C885A8 80242AF8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C885AC 80242AFC AFB1001C */  sw        $s1, 0x1c($sp)
/* C885B0 80242B00 0080882D */  daddu     $s1, $a0, $zero
/* C885B4 80242B04 AFBF0034 */  sw        $ra, 0x34($sp)
/* C885B8 80242B08 AFB60030 */  sw        $s6, 0x30($sp)
/* C885BC 80242B0C AFB5002C */  sw        $s5, 0x2c($sp)
/* C885C0 80242B10 AFB40028 */  sw        $s4, 0x28($sp)
/* C885C4 80242B14 AFB30024 */  sw        $s3, 0x24($sp)
/* C885C8 80242B18 AFB20020 */  sw        $s2, 0x20($sp)
/* C885CC 80242B1C AFB00018 */  sw        $s0, 0x18($sp)
/* C885D0 80242B20 F7B60040 */  sdc1      $f22, 0x40($sp)
/* C885D4 80242B24 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C885D8 80242B28 8E30000C */  lw        $s0, 0xc($s1)
/* C885DC 80242B2C 8E160000 */  lw        $s6, ($s0)
/* C885E0 80242B30 26100004 */  addiu     $s0, $s0, 4
/* C885E4 80242B34 0C0B1EAF */  jal       get_variable
/* C885E8 80242B38 02C0282D */   daddu    $a1, $s6, $zero
/* C885EC 80242B3C 44820000 */  mtc1      $v0, $f0
/* C885F0 80242B40 00000000 */  nop       
/* C885F4 80242B44 46800020 */  cvt.s.w   $f0, $f0
/* C885F8 80242B48 E7A00010 */  swc1      $f0, 0x10($sp)
/* C885FC 80242B4C 8E140000 */  lw        $s4, ($s0)
/* C88600 80242B50 26100004 */  addiu     $s0, $s0, 4
/* C88604 80242B54 0220202D */  daddu     $a0, $s1, $zero
/* C88608 80242B58 0C0B1EAF */  jal       get_variable
/* C8860C 80242B5C 0280282D */   daddu    $a1, $s4, $zero
/* C88610 80242B60 0220202D */  daddu     $a0, $s1, $zero
/* C88614 80242B64 8E150000 */  lw        $s5, ($s0)
/* C88618 80242B68 4482B000 */  mtc1      $v0, $f22
/* C8861C 80242B6C 00000000 */  nop       
/* C88620 80242B70 4680B5A0 */  cvt.s.w   $f22, $f22
/* C88624 80242B74 0C0B1EAF */  jal       get_variable
/* C88628 80242B78 02A0282D */   daddu    $a1, $s5, $zero
/* C8862C 80242B7C 2404FFFC */  addiu     $a0, $zero, -4
/* C88630 80242B80 44820000 */  mtc1      $v0, $f0
/* C88634 80242B84 00000000 */  nop       
/* C88638 80242B88 46800020 */  cvt.s.w   $f0, $f0
/* C8863C 80242B8C 0C00EABB */  jal       get_npc_unsafe
/* C88640 80242B90 E7A00014 */   swc1     $f0, 0x14($sp)
/* C88644 80242B94 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C88648 80242B98 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C8864C 80242B9C 3C014334 */  lui       $at, 0x4334
/* C88650 80242BA0 44816000 */  mtc1      $at, $f12
/* C88654 80242BA4 00041880 */  sll       $v1, $a0, 2
/* C88658 80242BA8 00641821 */  addu      $v1, $v1, $a0
/* C8865C 80242BAC 00031880 */  sll       $v1, $v1, 2
/* C88660 80242BB0 00641823 */  subu      $v1, $v1, $a0
/* C88664 80242BB4 000320C0 */  sll       $a0, $v1, 3
/* C88668 80242BB8 00641821 */  addu      $v1, $v1, $a0
/* C8866C 80242BBC 000318C0 */  sll       $v1, $v1, 3
/* C88670 80242BC0 3C01800B */  lui       $at, 0x800b
/* C88674 80242BC4 00230821 */  addu      $at, $at, $v1
/* C88678 80242BC8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C8867C 80242BCC 460C0300 */  add.s     $f12, $f0, $f12
/* C88680 80242BD0 0C00A6C9 */  jal       clamp_angle
/* C88684 80242BD4 0040982D */   daddu    $s3, $v0, $zero
/* C88688 80242BD8 27B00010 */  addiu     $s0, $sp, 0x10
/* C8868C 80242BDC 0200202D */  daddu     $a0, $s0, $zero
/* C88690 80242BE0 27B20014 */  addiu     $s2, $sp, 0x14
/* C88694 80242BE4 0240282D */  daddu     $a1, $s2, $zero
/* C88698 80242BE8 3C064170 */  lui       $a2, 0x4170
/* C8869C 80242BEC 8E67000C */  lw        $a3, 0xc($s3)
/* C886A0 80242BF0 0C00A7E7 */  jal       add_vec2D_polar
/* C886A4 80242BF4 46000506 */   mov.s    $f20, $f0
/* C886A8 80242BF8 0200202D */  daddu     $a0, $s0, $zero
/* C886AC 80242BFC 3C064120 */  lui       $a2, 0x4120
/* C886B0 80242C00 4407A000 */  mfc1      $a3, $f20
/* C886B4 80242C04 0C00A7E7 */  jal       add_vec2D_polar
/* C886B8 80242C08 0240282D */   daddu    $a1, $s2, $zero
/* C886BC 80242C0C 0220202D */  daddu     $a0, $s1, $zero
/* C886C0 80242C10 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C886C4 80242C14 4600008D */  trunc.w.s $f2, $f0
/* C886C8 80242C18 44061000 */  mfc1      $a2, $f2
/* C886CC 80242C1C 0C0B2026 */  jal       set_variable
/* C886D0 80242C20 02C0282D */   daddu    $a1, $s6, $zero
/* C886D4 80242C24 0220202D */  daddu     $a0, $s1, $zero
/* C886D8 80242C28 4600B08D */  trunc.w.s $f2, $f22
/* C886DC 80242C2C 44061000 */  mfc1      $a2, $f2
/* C886E0 80242C30 0C0B2026 */  jal       set_variable
/* C886E4 80242C34 0280282D */   daddu    $a1, $s4, $zero
/* C886E8 80242C38 0220202D */  daddu     $a0, $s1, $zero
/* C886EC 80242C3C C7A00014 */  lwc1      $f0, 0x14($sp)
/* C886F0 80242C40 4600008D */  trunc.w.s $f2, $f0
/* C886F4 80242C44 44061000 */  mfc1      $a2, $f2
/* C886F8 80242C48 0C0B2026 */  jal       set_variable
/* C886FC 80242C4C 02A0282D */   daddu    $a1, $s5, $zero
/* C88700 80242C50 8FBF0034 */  lw        $ra, 0x34($sp)
/* C88704 80242C54 8FB60030 */  lw        $s6, 0x30($sp)
/* C88708 80242C58 8FB5002C */  lw        $s5, 0x2c($sp)
/* C8870C 80242C5C 8FB40028 */  lw        $s4, 0x28($sp)
/* C88710 80242C60 8FB30024 */  lw        $s3, 0x24($sp)
/* C88714 80242C64 8FB20020 */  lw        $s2, 0x20($sp)
/* C88718 80242C68 8FB1001C */  lw        $s1, 0x1c($sp)
/* C8871C 80242C6C 8FB00018 */  lw        $s0, 0x18($sp)
/* C88720 80242C70 D7B60040 */  ldc1      $f22, 0x40($sp)
/* C88724 80242C74 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C88728 80242C78 24020002 */  addiu     $v0, $zero, 2
/* C8872C 80242C7C 03E00008 */  jr        $ra
/* C88730 80242C80 27BD0048 */   addiu    $sp, $sp, 0x48
