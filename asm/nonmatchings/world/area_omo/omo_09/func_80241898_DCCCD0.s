.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241898_DCE568
/* DCE568 80241898 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* DCE56C 8024189C AFB3003C */  sw        $s3, 0x3c($sp)
/* DCE570 802418A0 0080982D */  daddu     $s3, $a0, $zero
/* DCE574 802418A4 AFBF0040 */  sw        $ra, 0x40($sp)
/* DCE578 802418A8 AFB20038 */  sw        $s2, 0x38($sp)
/* DCE57C 802418AC AFB10034 */  sw        $s1, 0x34($sp)
/* DCE580 802418B0 AFB00030 */  sw        $s0, 0x30($sp)
/* DCE584 802418B4 8E720148 */  lw        $s2, 0x148($s3)
/* DCE588 802418B8 00A0882D */  daddu     $s1, $a1, $zero
/* DCE58C 802418BC 86440008 */  lh        $a0, 8($s2)
/* DCE590 802418C0 0C00EABB */  jal       get_npc_unsafe
/* DCE594 802418C4 00C0802D */   daddu    $s0, $a2, $zero
/* DCE598 802418C8 0200202D */  daddu     $a0, $s0, $zero
/* DCE59C 802418CC 0240282D */  daddu     $a1, $s2, $zero
/* DCE5A0 802418D0 24030001 */  addiu     $v1, $zero, 1
/* DCE5A4 802418D4 AFA30010 */  sw        $v1, 0x10($sp)
/* DCE5A8 802418D8 8E260024 */  lw        $a2, 0x24($s1)
/* DCE5AC 802418DC 8E270028 */  lw        $a3, 0x28($s1)
/* DCE5B0 802418E0 0C01242D */  jal       func_800490B4
/* DCE5B4 802418E4 0040802D */   daddu    $s0, $v0, $zero
/* DCE5B8 802418E8 1440001E */  bnez      $v0, .L80241964
/* DCE5BC 802418EC 0200202D */   daddu    $a0, $s0, $zero
/* DCE5C0 802418F0 24040002 */  addiu     $a0, $zero, 2
/* DCE5C4 802418F4 0200282D */  daddu     $a1, $s0, $zero
/* DCE5C8 802418F8 0000302D */  daddu     $a2, $zero, $zero
/* DCE5CC 802418FC 860300A8 */  lh        $v1, 0xa8($s0)
/* DCE5D0 80241900 3C013F80 */  lui       $at, 0x3f80
/* DCE5D4 80241904 44810000 */  mtc1      $at, $f0
/* DCE5D8 80241908 3C014000 */  lui       $at, 0x4000
/* DCE5DC 8024190C 44811000 */  mtc1      $at, $f2
/* DCE5E0 80241910 3C01C1A0 */  lui       $at, 0xc1a0
/* DCE5E4 80241914 44812000 */  mtc1      $at, $f4
/* DCE5E8 80241918 2402000F */  addiu     $v0, $zero, 0xf
/* DCE5EC 8024191C AFA2001C */  sw        $v0, 0x1c($sp)
/* DCE5F0 80241920 44833000 */  mtc1      $v1, $f6
/* DCE5F4 80241924 00000000 */  nop       
/* DCE5F8 80241928 468031A0 */  cvt.s.w   $f6, $f6
/* DCE5FC 8024192C 44073000 */  mfc1      $a3, $f6
/* DCE600 80241930 27A20028 */  addiu     $v0, $sp, 0x28
/* DCE604 80241934 AFA20020 */  sw        $v0, 0x20($sp)
/* DCE608 80241938 E7A00010 */  swc1      $f0, 0x10($sp)
/* DCE60C 8024193C E7A20014 */  swc1      $f2, 0x14($sp)
/* DCE610 80241940 0C01BFA4 */  jal       fx_emote
/* DCE614 80241944 E7A40018 */   swc1     $f4, 0x18($sp)
/* DCE618 80241948 8E4200CC */  lw        $v0, 0xcc($s2)
/* DCE61C 8024194C 8C430000 */  lw        $v1, ($v0)
/* DCE620 80241950 24020019 */  addiu     $v0, $zero, 0x19
/* DCE624 80241954 A602008E */  sh        $v0, 0x8e($s0)
/* DCE628 80241958 2402000E */  addiu     $v0, $zero, 0xe
/* DCE62C 8024195C 08090666 */  j         .L80241998
/* DCE630 80241960 AE030028 */   sw       $v1, 0x28($s0)
.L80241964:
/* DCE634 80241964 0C00F598 */  jal       func_8003D660
/* DCE638 80241968 24050001 */   addiu    $a1, $zero, 1
/* DCE63C 8024196C 8E050018 */  lw        $a1, 0x18($s0)
/* DCE640 80241970 8E06000C */  lw        $a2, 0xc($s0)
/* DCE644 80241974 0C00EA95 */  jal       npc_move_heading
/* DCE648 80241978 0200202D */   daddu    $a0, $s0, $zero
/* DCE64C 8024197C 8602008E */  lh        $v0, 0x8e($s0)
/* DCE650 80241980 9603008E */  lhu       $v1, 0x8e($s0)
/* DCE654 80241984 18400003 */  blez      $v0, .L80241994
/* DCE658 80241988 2462FFFF */   addiu    $v0, $v1, -1
/* DCE65C 8024198C 08090667 */  j         .L8024199C
/* DCE660 80241990 A602008E */   sh       $v0, 0x8e($s0)
.L80241994:
/* DCE664 80241994 2402000C */  addiu     $v0, $zero, 0xc
.L80241998:
/* DCE668 80241998 AE620070 */  sw        $v0, 0x70($s3)
.L8024199C:
/* DCE66C 8024199C 8FBF0040 */  lw        $ra, 0x40($sp)
/* DCE670 802419A0 8FB3003C */  lw        $s3, 0x3c($sp)
/* DCE674 802419A4 8FB20038 */  lw        $s2, 0x38($sp)
/* DCE678 802419A8 8FB10034 */  lw        $s1, 0x34($sp)
/* DCE67C 802419AC 8FB00030 */  lw        $s0, 0x30($sp)
/* DCE680 802419B0 03E00008 */  jr        $ra
/* DCE684 802419B4 27BD0048 */   addiu    $sp, $sp, 0x48
