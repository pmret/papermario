.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241540_E0FCE0
/* E0FCE0 80241540 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* E0FCE4 80241544 0000202D */  daddu     $a0, $zero, $zero
/* E0FCE8 80241548 3C05FD05 */  lui       $a1, 0xfd05
/* E0FCEC 8024154C 34A50F8A */  ori       $a1, $a1, 0xf8a
/* E0FCF0 80241550 AFBF0020 */  sw        $ra, 0x20($sp)
/* E0FCF4 80241554 AFB1001C */  sw        $s1, 0x1c($sp)
/* E0FCF8 80241558 0C0B1EAF */  jal       get_variable
/* E0FCFC 8024155C AFB00018 */   sw       $s0, 0x18($sp)
/* E0FD00 80241560 0040802D */  daddu     $s0, $v0, $zero
/* E0FD04 80241564 8E030000 */  lw        $v1, ($s0)
/* E0FD08 80241568 2C620005 */  sltiu     $v0, $v1, 5
/* E0FD0C 8024156C 1040004C */  beqz      $v0, .L802416A0
/* E0FD10 80241570 00031080 */   sll      $v0, $v1, 2
/* E0FD14 80241574 3C018024 */  lui       $at, %hi(jtbl_80243FA0_E12740)
/* E0FD18 80241578 00220821 */  addu      $at, $at, $v0
/* E0FD1C 8024157C 8C223FA0 */  lw        $v0, %lo(jtbl_80243FA0_E12740)($at)
/* E0FD20 80241580 00400008 */  jr        $v0
/* E0FD24 80241584 00000000 */   nop
glabel L80241588_E0FD28
/* E0FD28 80241588 2404021C */  addiu     $a0, $zero, 0x21c
/* E0FD2C 8024158C 0000282D */  daddu     $a1, $zero, $zero
/* E0FD30 80241590 00A0302D */  daddu     $a2, $a1, $zero
/* E0FD34 80241594 24020001 */  addiu     $v0, $zero, 1
/* E0FD38 80241598 AE000004 */  sw        $zero, 4($s0)
/* E0FD3C 8024159C 0C015478 */  jal       snd_start_sound
/* E0FD40 802415A0 AE020000 */   sw       $v0, ($s0)
glabel L802415A4_E0FD44
/* E0FD44 802415A4 3C054200 */  lui       $a1, 0x4200
/* E0FD48 802415A8 8E020004 */  lw        $v0, 4($s0)
/* E0FD4C 802415AC 3C06437F */  lui       $a2, 0x437f
/* E0FD50 802415B0 24420001 */  addiu     $v0, $v0, 1
/* E0FD54 802415B4 AE020004 */  sw        $v0, 4($s0)
/* E0FD58 802415B8 24020005 */  addiu     $v0, $zero, 5
/* E0FD5C 802415BC AFA20010 */  sw        $v0, 0x10($sp)
/* E0FD60 802415C0 8E070004 */  lw        $a3, 4($s0)
/* E0FD64 802415C4 0C00A8ED */  jal       update_lerp
/* E0FD68 802415C8 0000202D */   daddu    $a0, $zero, $zero
/* E0FD6C 802415CC 8E020004 */  lw        $v0, 4($s0)
/* E0FD70 802415D0 4600008D */  trunc.w.s $f2, $f0
/* E0FD74 802415D4 44031000 */  mfc1      $v1, $f2
/* E0FD78 802415D8 00000000 */  nop
/* E0FD7C 802415DC AE03000C */  sw        $v1, 0xc($s0)
/* E0FD80 802415E0 28420005 */  slti      $v0, $v0, 5
/* E0FD84 802415E4 1440002E */  bnez      $v0, .L802416A0
/* E0FD88 802415E8 AE030010 */   sw       $v1, 0x10($s0)
/* E0FD8C 802415EC 24020002 */  addiu     $v0, $zero, 2
/* E0FD90 802415F0 AE020000 */  sw        $v0, ($s0)
/* E0FD94 802415F4 240200FF */  addiu     $v0, $zero, 0xff
/* E0FD98 802415F8 AE02000C */  sw        $v0, 0xc($s0)
/* E0FD9C 802415FC 080905A8 */  j         .L802416A0
/* E0FDA0 80241600 AE020010 */   sw       $v0, 0x10($s0)
glabel L80241604_E0FDA4
/* E0FDA4 80241604 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E0FDA8 80241608 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E0FDAC 8024160C 240200FF */  addiu     $v0, $zero, 0xff
/* E0FDB0 80241610 AE02000C */  sw        $v0, 0xc($s0)
/* E0FDB4 80241614 AE020010 */  sw        $v0, 0x10($s0)
/* E0FDB8 80241618 8C620000 */  lw        $v0, ($v1)
/* E0FDBC 8024161C 3042C000 */  andi      $v0, $v0, 0xc000
/* E0FDC0 80241620 10400002 */  beqz      $v0, .L8024162C
/* E0FDC4 80241624 24020003 */   addiu    $v0, $zero, 3
/* E0FDC8 80241628 AE020000 */  sw        $v0, ($s0)
.L8024162C:
/* E0FDCC 8024162C 8E030000 */  lw        $v1, ($s0)
/* E0FDD0 80241630 24020003 */  addiu     $v0, $zero, 3
/* E0FDD4 80241634 1462001A */  bne       $v1, $v0, .L802416A0
/* E0FDD8 80241638 00000000 */   nop
glabel L8024163C_E0FDDC
/* E0FDDC 8024163C 240400CA */  addiu     $a0, $zero, 0xca
/* E0FDE0 80241640 0000282D */  daddu     $a1, $zero, $zero
/* E0FDE4 80241644 00A0302D */  daddu     $a2, $a1, $zero
/* E0FDE8 80241648 24020004 */  addiu     $v0, $zero, 4
/* E0FDEC 8024164C AE000004 */  sw        $zero, 4($s0)
/* E0FDF0 80241650 0C015478 */  jal       snd_start_sound
/* E0FDF4 80241654 AE020000 */   sw       $v0, ($s0)
glabel L80241658_E0FDF8
/* E0FDF8 80241658 0000202D */  daddu     $a0, $zero, $zero
/* E0FDFC 8024165C C6000010 */  lwc1      $f0, 0x10($s0)
/* E0FE00 80241660 46800020 */  cvt.s.w   $f0, $f0
/* E0FE04 80241664 24110005 */  addiu     $s1, $zero, 5
/* E0FE08 80241668 8E020004 */  lw        $v0, 4($s0)
/* E0FE0C 8024166C 44050000 */  mfc1      $a1, $f0
/* E0FE10 80241670 24420001 */  addiu     $v0, $v0, 1
/* E0FE14 80241674 AE020004 */  sw        $v0, 4($s0)
/* E0FE18 80241678 AFB10010 */  sw        $s1, 0x10($sp)
/* E0FE1C 8024167C 8E070004 */  lw        $a3, 4($s0)
/* E0FE20 80241680 0C00A8ED */  jal       update_lerp
/* E0FE24 80241684 0000302D */   daddu    $a2, $zero, $zero
/* E0FE28 80241688 8E020004 */  lw        $v0, 4($s0)
/* E0FE2C 8024168C 4600008D */  trunc.w.s $f2, $f0
/* E0FE30 80241690 E602000C */  swc1      $f2, 0xc($s0)
/* E0FE34 80241694 0051102A */  slt       $v0, $v0, $s1
/* E0FE38 80241698 50400001 */  beql      $v0, $zero, .L802416A0
/* E0FE3C 8024169C AE110000 */   sw       $s1, ($s0)
.L802416A0:
/* E0FE40 802416A0 8E05000C */  lw        $a1, 0xc($s0)
/* E0FE44 802416A4 0C090478 */  jal       func_802411E0_E0F980
/* E0FE48 802416A8 0200202D */   daddu    $a0, $s0, $zero
/* E0FE4C 802416AC 8FBF0020 */  lw        $ra, 0x20($sp)
/* E0FE50 802416B0 8FB1001C */  lw        $s1, 0x1c($sp)
/* E0FE54 802416B4 8FB00018 */  lw        $s0, 0x18($sp)
/* E0FE58 802416B8 03E00008 */  jr        $ra
/* E0FE5C 802416BC 27BD0028 */   addiu    $sp, $sp, 0x28
