.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024074C_93FCFC
/* 93FCFC 8024074C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 93FD00 80240750 AFB3003C */  sw        $s3, 0x3c($sp)
/* 93FD04 80240754 0080982D */  daddu     $s3, $a0, $zero
/* 93FD08 80240758 AFBF0040 */  sw        $ra, 0x40($sp)
/* 93FD0C 8024075C AFB20038 */  sw        $s2, 0x38($sp)
/* 93FD10 80240760 AFB10034 */  sw        $s1, 0x34($sp)
/* 93FD14 80240764 AFB00030 */  sw        $s0, 0x30($sp)
/* 93FD18 80240768 8E720148 */  lw        $s2, 0x148($s3)
/* 93FD1C 8024076C 00A0882D */  daddu     $s1, $a1, $zero
/* 93FD20 80240770 86440008 */  lh        $a0, 8($s2)
/* 93FD24 80240774 0C00EABB */  jal       get_npc_unsafe
/* 93FD28 80240778 00C0802D */   daddu    $s0, $a2, $zero
/* 93FD2C 8024077C 0200202D */  daddu     $a0, $s0, $zero
/* 93FD30 80240780 0240282D */  daddu     $a1, $s2, $zero
/* 93FD34 80240784 24030001 */  addiu     $v1, $zero, 1
/* 93FD38 80240788 AFA30010 */  sw        $v1, 0x10($sp)
/* 93FD3C 8024078C 8E260018 */  lw        $a2, 0x18($s1)
/* 93FD40 80240790 8E27001C */  lw        $a3, 0x1c($s1)
/* 93FD44 80240794 0C01242D */  jal       func_800490B4
/* 93FD48 80240798 0040802D */   daddu    $s0, $v0, $zero
/* 93FD4C 8024079C 1440001D */  bnez      $v0, .L80240814
/* 93FD50 802407A0 24040002 */   addiu    $a0, $zero, 2
/* 93FD54 802407A4 0200282D */  daddu     $a1, $s0, $zero
/* 93FD58 802407A8 0000302D */  daddu     $a2, $zero, $zero
/* 93FD5C 802407AC 860300A8 */  lh        $v1, 0xa8($s0)
/* 93FD60 802407B0 3C013F80 */  lui       $at, 0x3f80
/* 93FD64 802407B4 44810000 */  mtc1      $at, $f0
/* 93FD68 802407B8 3C014000 */  lui       $at, 0x4000
/* 93FD6C 802407BC 44811000 */  mtc1      $at, $f2
/* 93FD70 802407C0 3C01C1A0 */  lui       $at, 0xc1a0
/* 93FD74 802407C4 44812000 */  mtc1      $at, $f4
/* 93FD78 802407C8 2402000F */  addiu     $v0, $zero, 0xf
/* 93FD7C 802407CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 93FD80 802407D0 44833000 */  mtc1      $v1, $f6
/* 93FD84 802407D4 00000000 */  nop       
/* 93FD88 802407D8 468031A0 */  cvt.s.w   $f6, $f6
/* 93FD8C 802407DC 44073000 */  mfc1      $a3, $f6
/* 93FD90 802407E0 27A20028 */  addiu     $v0, $sp, 0x28
/* 93FD94 802407E4 AFA20020 */  sw        $v0, 0x20($sp)
/* 93FD98 802407E8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 93FD9C 802407EC E7A20014 */  swc1      $f2, 0x14($sp)
/* 93FDA0 802407F0 0C01BFA4 */  jal       fx_emote
/* 93FDA4 802407F4 E7A40018 */   swc1     $f4, 0x18($sp)
/* 93FDA8 802407F8 8E4200CC */  lw        $v0, 0xcc($s2)
/* 93FDAC 802407FC 8C430000 */  lw        $v1, ($v0)
/* 93FDB0 80240800 24020019 */  addiu     $v0, $zero, 0x19
/* 93FDB4 80240804 A602008E */  sh        $v0, 0x8e($s0)
/* 93FDB8 80240808 2402000E */  addiu     $v0, $zero, 0xe
/* 93FDBC 8024080C 08090212 */  j         .L80240848
/* 93FDC0 80240810 AE030028 */   sw       $v1, 0x28($s0)
.L80240814:
/* 93FDC4 80240814 8E050018 */  lw        $a1, 0x18($s0)
/* 93FDC8 80240818 8E06000C */  lw        $a2, 0xc($s0)
/* 93FDCC 8024081C 0C00EA95 */  jal       npc_move_heading
/* 93FDD0 80240820 0200202D */   daddu    $a0, $s0, $zero
/* 93FDD4 80240824 0200202D */  daddu     $a0, $s0, $zero
/* 93FDD8 80240828 0C00F598 */  jal       func_8003D660
/* 93FDDC 8024082C 24050001 */   addiu    $a1, $zero, 1
/* 93FDE0 80240830 9602008E */  lhu       $v0, 0x8e($s0)
/* 93FDE4 80240834 2442FFFF */  addiu     $v0, $v0, -1
/* 93FDE8 80240838 A602008E */  sh        $v0, 0x8e($s0)
/* 93FDEC 8024083C 00021400 */  sll       $v0, $v0, 0x10
/* 93FDF0 80240840 14400002 */  bnez      $v0, .L8024084C
/* 93FDF4 80240844 2402000C */   addiu    $v0, $zero, 0xc
.L80240848:
/* 93FDF8 80240848 AE620070 */  sw        $v0, 0x70($s3)
.L8024084C:
/* 93FDFC 8024084C 8FBF0040 */  lw        $ra, 0x40($sp)
/* 93FE00 80240850 8FB3003C */  lw        $s3, 0x3c($sp)
/* 93FE04 80240854 8FB20038 */  lw        $s2, 0x38($sp)
/* 93FE08 80240858 8FB10034 */  lw        $s1, 0x34($sp)
/* 93FE0C 8024085C 8FB00030 */  lw        $s0, 0x30($sp)
/* 93FE10 80240860 03E00008 */  jr        $ra
/* 93FE14 80240864 27BD0048 */   addiu    $sp, $sp, 0x48
