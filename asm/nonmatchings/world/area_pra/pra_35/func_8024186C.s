.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024186C
/* D8EABC 8024186C 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D8EAC0 80241870 AFB3003C */  sw        $s3, 0x3c($sp)
/* D8EAC4 80241874 0080982D */  daddu     $s3, $a0, $zero
/* D8EAC8 80241878 AFBF0040 */  sw        $ra, 0x40($sp)
/* D8EACC 8024187C AFB20038 */  sw        $s2, 0x38($sp)
/* D8EAD0 80241880 AFB10034 */  sw        $s1, 0x34($sp)
/* D8EAD4 80241884 AFB00030 */  sw        $s0, 0x30($sp)
/* D8EAD8 80241888 8E720148 */  lw        $s2, 0x148($s3)
/* D8EADC 8024188C 00A0882D */  daddu     $s1, $a1, $zero
/* D8EAE0 80241890 86440008 */  lh        $a0, 8($s2)
/* D8EAE4 80241894 0C00EABB */  jal       get_npc_unsafe
/* D8EAE8 80241898 00C0802D */   daddu    $s0, $a2, $zero
/* D8EAEC 8024189C 0200202D */  daddu     $a0, $s0, $zero
/* D8EAF0 802418A0 0240282D */  daddu     $a1, $s2, $zero
/* D8EAF4 802418A4 24030001 */  addiu     $v1, $zero, 1
/* D8EAF8 802418A8 AFA30010 */  sw        $v1, 0x10($sp)
/* D8EAFC 802418AC 8E260024 */  lw        $a2, 0x24($s1)
/* D8EB00 802418B0 8E270028 */  lw        $a3, 0x28($s1)
/* D8EB04 802418B4 0C01242D */  jal       func_800490B4
/* D8EB08 802418B8 0040802D */   daddu    $s0, $v0, $zero
/* D8EB0C 802418BC 1440001E */  bnez      $v0, .L80241938
/* D8EB10 802418C0 0200202D */   daddu    $a0, $s0, $zero
/* D8EB14 802418C4 24040002 */  addiu     $a0, $zero, 2
/* D8EB18 802418C8 0200282D */  daddu     $a1, $s0, $zero
/* D8EB1C 802418CC 0000302D */  daddu     $a2, $zero, $zero
/* D8EB20 802418D0 860300A8 */  lh        $v1, 0xa8($s0)
/* D8EB24 802418D4 3C013F80 */  lui       $at, 0x3f80
/* D8EB28 802418D8 44810000 */  mtc1      $at, $f0
/* D8EB2C 802418DC 3C014000 */  lui       $at, 0x4000
/* D8EB30 802418E0 44811000 */  mtc1      $at, $f2
/* D8EB34 802418E4 3C01C1A0 */  lui       $at, 0xc1a0
/* D8EB38 802418E8 44812000 */  mtc1      $at, $f4
/* D8EB3C 802418EC 2402000F */  addiu     $v0, $zero, 0xf
/* D8EB40 802418F0 AFA2001C */  sw        $v0, 0x1c($sp)
/* D8EB44 802418F4 44833000 */  mtc1      $v1, $f6
/* D8EB48 802418F8 00000000 */  nop       
/* D8EB4C 802418FC 468031A0 */  cvt.s.w   $f6, $f6
/* D8EB50 80241900 44073000 */  mfc1      $a3, $f6
/* D8EB54 80241904 27A20028 */  addiu     $v0, $sp, 0x28
/* D8EB58 80241908 AFA20020 */  sw        $v0, 0x20($sp)
/* D8EB5C 8024190C E7A00010 */  swc1      $f0, 0x10($sp)
/* D8EB60 80241910 E7A20014 */  swc1      $f2, 0x14($sp)
/* D8EB64 80241914 0C01BFA4 */  jal       fx_emote
/* D8EB68 80241918 E7A40018 */   swc1     $f4, 0x18($sp)
/* D8EB6C 8024191C 8E4200CC */  lw        $v0, 0xcc($s2)
/* D8EB70 80241920 8C430000 */  lw        $v1, ($v0)
/* D8EB74 80241924 24020019 */  addiu     $v0, $zero, 0x19
/* D8EB78 80241928 A602008E */  sh        $v0, 0x8e($s0)
/* D8EB7C 8024192C 2402000E */  addiu     $v0, $zero, 0xe
/* D8EB80 80241930 0809065B */  j         .L8024196C
/* D8EB84 80241934 AE030028 */   sw       $v1, 0x28($s0)
.L80241938:
/* D8EB88 80241938 0C00F598 */  jal       func_8003D660
/* D8EB8C 8024193C 24050001 */   addiu    $a1, $zero, 1
/* D8EB90 80241940 8E050018 */  lw        $a1, 0x18($s0)
/* D8EB94 80241944 8E06000C */  lw        $a2, 0xc($s0)
/* D8EB98 80241948 0C00EA95 */  jal       npc_move_heading
/* D8EB9C 8024194C 0200202D */   daddu    $a0, $s0, $zero
/* D8EBA0 80241950 8602008E */  lh        $v0, 0x8e($s0)
/* D8EBA4 80241954 9603008E */  lhu       $v1, 0x8e($s0)
/* D8EBA8 80241958 18400003 */  blez      $v0, .L80241968
/* D8EBAC 8024195C 2462FFFF */   addiu    $v0, $v1, -1
/* D8EBB0 80241960 0809065C */  j         .L80241970
/* D8EBB4 80241964 A602008E */   sh       $v0, 0x8e($s0)
.L80241968:
/* D8EBB8 80241968 2402000C */  addiu     $v0, $zero, 0xc
.L8024196C:
/* D8EBBC 8024196C AE620070 */  sw        $v0, 0x70($s3)
.L80241970:
/* D8EBC0 80241970 8FBF0040 */  lw        $ra, 0x40($sp)
/* D8EBC4 80241974 8FB3003C */  lw        $s3, 0x3c($sp)
/* D8EBC8 80241978 8FB20038 */  lw        $s2, 0x38($sp)
/* D8EBCC 8024197C 8FB10034 */  lw        $s1, 0x34($sp)
/* D8EBD0 80241980 8FB00030 */  lw        $s0, 0x30($sp)
/* D8EBD4 80241984 03E00008 */  jr        $ra
/* D8EBD8 80241988 27BD0048 */   addiu    $sp, $sp, 0x48
