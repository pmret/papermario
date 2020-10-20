.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802412B8_D9E788
/* D9E788 802412B8 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* D9E78C 802412BC AFB3003C */  sw        $s3, 0x3c($sp)
/* D9E790 802412C0 0080982D */  daddu     $s3, $a0, $zero
/* D9E794 802412C4 AFBF0040 */  sw        $ra, 0x40($sp)
/* D9E798 802412C8 AFB20038 */  sw        $s2, 0x38($sp)
/* D9E79C 802412CC AFB10034 */  sw        $s1, 0x34($sp)
/* D9E7A0 802412D0 AFB00030 */  sw        $s0, 0x30($sp)
/* D9E7A4 802412D4 8E720148 */  lw        $s2, 0x148($s3)
/* D9E7A8 802412D8 00A0882D */  daddu     $s1, $a1, $zero
/* D9E7AC 802412DC 86440008 */  lh        $a0, 8($s2)
/* D9E7B0 802412E0 0C00EABB */  jal       get_npc_unsafe
/* D9E7B4 802412E4 00C0802D */   daddu    $s0, $a2, $zero
/* D9E7B8 802412E8 0200202D */  daddu     $a0, $s0, $zero
/* D9E7BC 802412EC 0240282D */  daddu     $a1, $s2, $zero
/* D9E7C0 802412F0 24030001 */  addiu     $v1, $zero, 1
/* D9E7C4 802412F4 AFA30010 */  sw        $v1, 0x10($sp)
/* D9E7C8 802412F8 8E260018 */  lw        $a2, 0x18($s1)
/* D9E7CC 802412FC 8E27001C */  lw        $a3, 0x1c($s1)
/* D9E7D0 80241300 0C01242D */  jal       func_800490B4
/* D9E7D4 80241304 0040802D */   daddu    $s0, $v0, $zero
/* D9E7D8 80241308 1440001D */  bnez      $v0, .L80241380
/* D9E7DC 8024130C 24040002 */   addiu    $a0, $zero, 2
/* D9E7E0 80241310 0200282D */  daddu     $a1, $s0, $zero
/* D9E7E4 80241314 0000302D */  daddu     $a2, $zero, $zero
/* D9E7E8 80241318 860300A8 */  lh        $v1, 0xa8($s0)
/* D9E7EC 8024131C 3C013F80 */  lui       $at, 0x3f80
/* D9E7F0 80241320 44810000 */  mtc1      $at, $f0
/* D9E7F4 80241324 3C014000 */  lui       $at, 0x4000
/* D9E7F8 80241328 44811000 */  mtc1      $at, $f2
/* D9E7FC 8024132C 3C01C1A0 */  lui       $at, 0xc1a0
/* D9E800 80241330 44812000 */  mtc1      $at, $f4
/* D9E804 80241334 2402000F */  addiu     $v0, $zero, 0xf
/* D9E808 80241338 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9E80C 8024133C 44833000 */  mtc1      $v1, $f6
/* D9E810 80241340 00000000 */  nop       
/* D9E814 80241344 468031A0 */  cvt.s.w   $f6, $f6
/* D9E818 80241348 44073000 */  mfc1      $a3, $f6
/* D9E81C 8024134C 27A20028 */  addiu     $v0, $sp, 0x28
/* D9E820 80241350 AFA20020 */  sw        $v0, 0x20($sp)
/* D9E824 80241354 E7A00010 */  swc1      $f0, 0x10($sp)
/* D9E828 80241358 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9E82C 8024135C 0C01BFA4 */  jal       fx_emote
/* D9E830 80241360 E7A40018 */   swc1     $f4, 0x18($sp)
/* D9E834 80241364 8E4200CC */  lw        $v0, 0xcc($s2)
/* D9E838 80241368 8C430000 */  lw        $v1, ($v0)
/* D9E83C 8024136C 24020019 */  addiu     $v0, $zero, 0x19
/* D9E840 80241370 A602008E */  sh        $v0, 0x8e($s0)
/* D9E844 80241374 2402000E */  addiu     $v0, $zero, 0xe
/* D9E848 80241378 080904ED */  j         .L802413B4
/* D9E84C 8024137C AE030028 */   sw       $v1, 0x28($s0)
.L80241380:
/* D9E850 80241380 8E050018 */  lw        $a1, 0x18($s0)
/* D9E854 80241384 8E06000C */  lw        $a2, 0xc($s0)
/* D9E858 80241388 0C00EA95 */  jal       npc_move_heading
/* D9E85C 8024138C 0200202D */   daddu    $a0, $s0, $zero
/* D9E860 80241390 0200202D */  daddu     $a0, $s0, $zero
/* D9E864 80241394 0C00F598 */  jal       func_8003D660
/* D9E868 80241398 24050001 */   addiu    $a1, $zero, 1
/* D9E86C 8024139C 9602008E */  lhu       $v0, 0x8e($s0)
/* D9E870 802413A0 2442FFFF */  addiu     $v0, $v0, -1
/* D9E874 802413A4 A602008E */  sh        $v0, 0x8e($s0)
/* D9E878 802413A8 00021400 */  sll       $v0, $v0, 0x10
/* D9E87C 802413AC 14400002 */  bnez      $v0, .L802413B8
/* D9E880 802413B0 2402000C */   addiu    $v0, $zero, 0xc
.L802413B4:
/* D9E884 802413B4 AE620070 */  sw        $v0, 0x70($s3)
.L802413B8:
/* D9E888 802413B8 8FBF0040 */  lw        $ra, 0x40($sp)
/* D9E88C 802413BC 8FB3003C */  lw        $s3, 0x3c($sp)
/* D9E890 802413C0 8FB20038 */  lw        $s2, 0x38($sp)
/* D9E894 802413C4 8FB10034 */  lw        $s1, 0x34($sp)
/* D9E898 802413C8 8FB00030 */  lw        $s0, 0x30($sp)
/* D9E89C 802413CC 03E00008 */  jr        $ra
/* D9E8A0 802413D0 27BD0048 */   addiu    $sp, $sp, 0x48
