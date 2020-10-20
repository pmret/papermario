.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242528
/* C5CC68 80242528 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* C5CC6C 8024252C AFB1001C */  sw        $s1, 0x1c($sp)
/* C5CC70 80242530 0080882D */  daddu     $s1, $a0, $zero
/* C5CC74 80242534 AFBF0034 */  sw        $ra, 0x34($sp)
/* C5CC78 80242538 AFB60030 */  sw        $s6, 0x30($sp)
/* C5CC7C 8024253C AFB5002C */  sw        $s5, 0x2c($sp)
/* C5CC80 80242540 AFB40028 */  sw        $s4, 0x28($sp)
/* C5CC84 80242544 AFB30024 */  sw        $s3, 0x24($sp)
/* C5CC88 80242548 AFB20020 */  sw        $s2, 0x20($sp)
/* C5CC8C 8024254C AFB00018 */  sw        $s0, 0x18($sp)
/* C5CC90 80242550 F7B60040 */  sdc1      $f22, 0x40($sp)
/* C5CC94 80242554 F7B40038 */  sdc1      $f20, 0x38($sp)
/* C5CC98 80242558 8E30000C */  lw        $s0, 0xc($s1)
/* C5CC9C 8024255C 8E160000 */  lw        $s6, ($s0)
/* C5CCA0 80242560 26100004 */  addiu     $s0, $s0, 4
/* C5CCA4 80242564 0C0B1EAF */  jal       get_variable
/* C5CCA8 80242568 02C0282D */   daddu    $a1, $s6, $zero
/* C5CCAC 8024256C 44820000 */  mtc1      $v0, $f0
/* C5CCB0 80242570 00000000 */  nop       
/* C5CCB4 80242574 46800020 */  cvt.s.w   $f0, $f0
/* C5CCB8 80242578 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5CCBC 8024257C 8E140000 */  lw        $s4, ($s0)
/* C5CCC0 80242580 26100004 */  addiu     $s0, $s0, 4
/* C5CCC4 80242584 0220202D */  daddu     $a0, $s1, $zero
/* C5CCC8 80242588 0C0B1EAF */  jal       get_variable
/* C5CCCC 8024258C 0280282D */   daddu    $a1, $s4, $zero
/* C5CCD0 80242590 0220202D */  daddu     $a0, $s1, $zero
/* C5CCD4 80242594 8E150000 */  lw        $s5, ($s0)
/* C5CCD8 80242598 4482B000 */  mtc1      $v0, $f22
/* C5CCDC 8024259C 00000000 */  nop       
/* C5CCE0 802425A0 4680B5A0 */  cvt.s.w   $f22, $f22
/* C5CCE4 802425A4 0C0B1EAF */  jal       get_variable
/* C5CCE8 802425A8 02A0282D */   daddu    $a1, $s5, $zero
/* C5CCEC 802425AC 2404FFFC */  addiu     $a0, $zero, -4
/* C5CCF0 802425B0 44820000 */  mtc1      $v0, $f0
/* C5CCF4 802425B4 00000000 */  nop       
/* C5CCF8 802425B8 46800020 */  cvt.s.w   $f0, $f0
/* C5CCFC 802425BC 0C00EABB */  jal       get_npc_unsafe
/* C5CD00 802425C0 E7A00014 */   swc1     $f0, 0x14($sp)
/* C5CD04 802425C4 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* C5CD08 802425C8 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* C5CD0C 802425CC 3C014334 */  lui       $at, 0x4334
/* C5CD10 802425D0 44816000 */  mtc1      $at, $f12
/* C5CD14 802425D4 00041880 */  sll       $v1, $a0, 2
/* C5CD18 802425D8 00641821 */  addu      $v1, $v1, $a0
/* C5CD1C 802425DC 00031880 */  sll       $v1, $v1, 2
/* C5CD20 802425E0 00641823 */  subu      $v1, $v1, $a0
/* C5CD24 802425E4 000320C0 */  sll       $a0, $v1, 3
/* C5CD28 802425E8 00641821 */  addu      $v1, $v1, $a0
/* C5CD2C 802425EC 000318C0 */  sll       $v1, $v1, 3
/* C5CD30 802425F0 3C01800B */  lui       $at, 0x800b
/* C5CD34 802425F4 00230821 */  addu      $at, $at, $v1
/* C5CD38 802425F8 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* C5CD3C 802425FC 460C0300 */  add.s     $f12, $f0, $f12
/* C5CD40 80242600 0C00A6C9 */  jal       clamp_angle
/* C5CD44 80242604 0040982D */   daddu    $s3, $v0, $zero
/* C5CD48 80242608 27B00010 */  addiu     $s0, $sp, 0x10
/* C5CD4C 8024260C 0200202D */  daddu     $a0, $s0, $zero
/* C5CD50 80242610 27B20014 */  addiu     $s2, $sp, 0x14
/* C5CD54 80242614 0240282D */  daddu     $a1, $s2, $zero
/* C5CD58 80242618 3C064170 */  lui       $a2, 0x4170
/* C5CD5C 8024261C 8E67000C */  lw        $a3, 0xc($s3)
/* C5CD60 80242620 0C00A7E7 */  jal       add_vec2D_polar
/* C5CD64 80242624 46000506 */   mov.s    $f20, $f0
/* C5CD68 80242628 0200202D */  daddu     $a0, $s0, $zero
/* C5CD6C 8024262C 3C064120 */  lui       $a2, 0x4120
/* C5CD70 80242630 4407A000 */  mfc1      $a3, $f20
/* C5CD74 80242634 0C00A7E7 */  jal       add_vec2D_polar
/* C5CD78 80242638 0240282D */   daddu    $a1, $s2, $zero
/* C5CD7C 8024263C 0220202D */  daddu     $a0, $s1, $zero
/* C5CD80 80242640 C7A00010 */  lwc1      $f0, 0x10($sp)
/* C5CD84 80242644 4600008D */  trunc.w.s $f2, $f0
/* C5CD88 80242648 44061000 */  mfc1      $a2, $f2
/* C5CD8C 8024264C 0C0B2026 */  jal       set_variable
/* C5CD90 80242650 02C0282D */   daddu    $a1, $s6, $zero
/* C5CD94 80242654 0220202D */  daddu     $a0, $s1, $zero
/* C5CD98 80242658 4600B08D */  trunc.w.s $f2, $f22
/* C5CD9C 8024265C 44061000 */  mfc1      $a2, $f2
/* C5CDA0 80242660 0C0B2026 */  jal       set_variable
/* C5CDA4 80242664 0280282D */   daddu    $a1, $s4, $zero
/* C5CDA8 80242668 0220202D */  daddu     $a0, $s1, $zero
/* C5CDAC 8024266C C7A00014 */  lwc1      $f0, 0x14($sp)
/* C5CDB0 80242670 4600008D */  trunc.w.s $f2, $f0
/* C5CDB4 80242674 44061000 */  mfc1      $a2, $f2
/* C5CDB8 80242678 0C0B2026 */  jal       set_variable
/* C5CDBC 8024267C 02A0282D */   daddu    $a1, $s5, $zero
/* C5CDC0 80242680 8FBF0034 */  lw        $ra, 0x34($sp)
/* C5CDC4 80242684 8FB60030 */  lw        $s6, 0x30($sp)
/* C5CDC8 80242688 8FB5002C */  lw        $s5, 0x2c($sp)
/* C5CDCC 8024268C 8FB40028 */  lw        $s4, 0x28($sp)
/* C5CDD0 80242690 8FB30024 */  lw        $s3, 0x24($sp)
/* C5CDD4 80242694 8FB20020 */  lw        $s2, 0x20($sp)
/* C5CDD8 80242698 8FB1001C */  lw        $s1, 0x1c($sp)
/* C5CDDC 8024269C 8FB00018 */  lw        $s0, 0x18($sp)
/* C5CDE0 802426A0 D7B60040 */  ldc1      $f22, 0x40($sp)
/* C5CDE4 802426A4 D7B40038 */  ldc1      $f20, 0x38($sp)
/* C5CDE8 802426A8 24020002 */  addiu     $v0, $zero, 2
/* C5CDEC 802426AC 03E00008 */  jr        $ra
/* C5CDF0 802426B0 27BD0048 */   addiu    $sp, $sp, 0x48
