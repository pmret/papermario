.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel trd_04_UnkFunc15
/* 9A99C0 802415D0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 9A99C4 802415D4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 9A99C8 802415D8 0080982D */  daddu     $s3, $a0, $zero
/* 9A99CC 802415DC AFBF0040 */  sw        $ra, 0x40($sp)
/* 9A99D0 802415E0 AFB20038 */  sw        $s2, 0x38($sp)
/* 9A99D4 802415E4 AFB10034 */  sw        $s1, 0x34($sp)
/* 9A99D8 802415E8 AFB00030 */  sw        $s0, 0x30($sp)
/* 9A99DC 802415EC 8E720148 */  lw        $s2, 0x148($s3)
/* 9A99E0 802415F0 00A0882D */  daddu     $s1, $a1, $zero
/* 9A99E4 802415F4 86440008 */  lh        $a0, 8($s2)
/* 9A99E8 802415F8 0C00EABB */  jal       get_npc_unsafe
/* 9A99EC 802415FC 00C0802D */   daddu    $s0, $a2, $zero
/* 9A99F0 80241600 0200202D */  daddu     $a0, $s0, $zero
/* 9A99F4 80241604 0240282D */  daddu     $a1, $s2, $zero
/* 9A99F8 80241608 24030001 */  addiu     $v1, $zero, 1
/* 9A99FC 8024160C AFA30010 */  sw        $v1, 0x10($sp)
/* 9A9A00 80241610 8E260024 */  lw        $a2, 0x24($s1)
/* 9A9A04 80241614 8E270028 */  lw        $a3, 0x28($s1)
/* 9A9A08 80241618 0C01242D */  jal       func_800490B4
/* 9A9A0C 8024161C 0040802D */   daddu    $s0, $v0, $zero
/* 9A9A10 80241620 1440001E */  bnez      $v0, .L8024169C
/* 9A9A14 80241624 0200202D */   daddu    $a0, $s0, $zero
/* 9A9A18 80241628 24040002 */  addiu     $a0, $zero, 2
/* 9A9A1C 8024162C 0200282D */  daddu     $a1, $s0, $zero
/* 9A9A20 80241630 0000302D */  daddu     $a2, $zero, $zero
/* 9A9A24 80241634 860300A8 */  lh        $v1, 0xa8($s0)
/* 9A9A28 80241638 3C013F80 */  lui       $at, 0x3f80
/* 9A9A2C 8024163C 44810000 */  mtc1      $at, $f0
/* 9A9A30 80241640 3C014000 */  lui       $at, 0x4000
/* 9A9A34 80241644 44811000 */  mtc1      $at, $f2
/* 9A9A38 80241648 3C01C1A0 */  lui       $at, 0xc1a0
/* 9A9A3C 8024164C 44812000 */  mtc1      $at, $f4
/* 9A9A40 80241650 2402000F */  addiu     $v0, $zero, 0xf
/* 9A9A44 80241654 AFA2001C */  sw        $v0, 0x1c($sp)
/* 9A9A48 80241658 44833000 */  mtc1      $v1, $f6
/* 9A9A4C 8024165C 00000000 */  nop
/* 9A9A50 80241660 468031A0 */  cvt.s.w   $f6, $f6
/* 9A9A54 80241664 44073000 */  mfc1      $a3, $f6
/* 9A9A58 80241668 27A20028 */  addiu     $v0, $sp, 0x28
/* 9A9A5C 8024166C AFA20020 */  sw        $v0, 0x20($sp)
/* 9A9A60 80241670 E7A00010 */  swc1      $f0, 0x10($sp)
/* 9A9A64 80241674 E7A20014 */  swc1      $f2, 0x14($sp)
/* 9A9A68 80241678 0C01BFA4 */  jal       fx_emote
/* 9A9A6C 8024167C E7A40018 */   swc1     $f4, 0x18($sp)
/* 9A9A70 80241680 8E4200CC */  lw        $v0, 0xcc($s2)
/* 9A9A74 80241684 8C430000 */  lw        $v1, ($v0)
/* 9A9A78 80241688 24020019 */  addiu     $v0, $zero, 0x19
/* 9A9A7C 8024168C A602008E */  sh        $v0, 0x8e($s0)
/* 9A9A80 80241690 2402000E */  addiu     $v0, $zero, 0xe
/* 9A9A84 80241694 080905B4 */  j         .L802416D0
/* 9A9A88 80241698 AE030028 */   sw       $v1, 0x28($s0)
.L8024169C:
/* 9A9A8C 8024169C 0C00F598 */  jal       func_8003D660
/* 9A9A90 802416A0 24050001 */   addiu    $a1, $zero, 1
/* 9A9A94 802416A4 8E050018 */  lw        $a1, 0x18($s0)
/* 9A9A98 802416A8 8E06000C */  lw        $a2, 0xc($s0)
/* 9A9A9C 802416AC 0C00EA95 */  jal       npc_move_heading
/* 9A9AA0 802416B0 0200202D */   daddu    $a0, $s0, $zero
/* 9A9AA4 802416B4 8602008E */  lh        $v0, 0x8e($s0)
/* 9A9AA8 802416B8 9603008E */  lhu       $v1, 0x8e($s0)
/* 9A9AAC 802416BC 18400003 */  blez      $v0, .L802416CC
/* 9A9AB0 802416C0 2462FFFF */   addiu    $v0, $v1, -1
/* 9A9AB4 802416C4 080905B5 */  j         .L802416D4
/* 9A9AB8 802416C8 A602008E */   sh       $v0, 0x8e($s0)
.L802416CC:
/* 9A9ABC 802416CC 2402000C */  addiu     $v0, $zero, 0xc
.L802416D0:
/* 9A9AC0 802416D0 AE620070 */  sw        $v0, 0x70($s3)
.L802416D4:
/* 9A9AC4 802416D4 8FBF0040 */  lw        $ra, 0x40($sp)
/* 9A9AC8 802416D8 8FB3003C */  lw        $s3, 0x3c($sp)
/* 9A9ACC 802416DC 8FB20038 */  lw        $s2, 0x38($sp)
/* 9A9AD0 802416E0 8FB10034 */  lw        $s1, 0x34($sp)
/* 9A9AD4 802416E4 8FB00030 */  lw        $s0, 0x30($sp)
/* 9A9AD8 802416E8 03E00008 */  jr        $ra
/* 9A9ADC 802416EC 27BD0048 */   addiu    $sp, $sp, 0x48
