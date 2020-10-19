.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240FA0_99D930
/* 99D930 80240FA0 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 99D934 80240FA4 AFB3003C */  sw        $s3, 0x3c($sp)
/* 99D938 80240FA8 0080982D */  daddu     $s3, $a0, $zero
/* 99D93C 80240FAC AFBF0040 */  sw        $ra, 0x40($sp)
/* 99D940 80240FB0 AFB20038 */  sw        $s2, 0x38($sp)
/* 99D944 80240FB4 AFB10034 */  sw        $s1, 0x34($sp)
/* 99D948 80240FB8 AFB00030 */  sw        $s0, 0x30($sp)
/* 99D94C 80240FBC 8E720148 */  lw        $s2, 0x148($s3)
/* 99D950 80240FC0 00A0882D */  daddu     $s1, $a1, $zero
/* 99D954 80240FC4 86440008 */  lh        $a0, 8($s2)
/* 99D958 80240FC8 0C00EABB */  jal       get_npc_unsafe
/* 99D95C 80240FCC 00C0802D */   daddu    $s0, $a2, $zero
/* 99D960 80240FD0 0200202D */  daddu     $a0, $s0, $zero
/* 99D964 80240FD4 0240282D */  daddu     $a1, $s2, $zero
/* 99D968 80240FD8 24030001 */  addiu     $v1, $zero, 1
/* 99D96C 80240FDC AFA30010 */  sw        $v1, 0x10($sp)
/* 99D970 80240FE0 8E260018 */  lw        $a2, 0x18($s1)
/* 99D974 80240FE4 8E27001C */  lw        $a3, 0x1c($s1)
/* 99D978 80240FE8 0C01242D */  jal       func_800490B4
/* 99D97C 80240FEC 0040802D */   daddu    $s0, $v0, $zero
/* 99D980 80240FF0 1440001D */  bnez      $v0, .L80241068
/* 99D984 80240FF4 24040002 */   addiu    $a0, $zero, 2
/* 99D988 80240FF8 0200282D */  daddu     $a1, $s0, $zero
/* 99D98C 80240FFC 0000302D */  daddu     $a2, $zero, $zero
/* 99D990 80241000 860300A8 */  lh        $v1, 0xa8($s0)
/* 99D994 80241004 3C013F80 */  lui       $at, 0x3f80
/* 99D998 80241008 44810000 */  mtc1      $at, $f0
/* 99D99C 8024100C 3C014000 */  lui       $at, 0x4000
/* 99D9A0 80241010 44811000 */  mtc1      $at, $f2
/* 99D9A4 80241014 3C01C1A0 */  lui       $at, 0xc1a0
/* 99D9A8 80241018 44812000 */  mtc1      $at, $f4
/* 99D9AC 8024101C 2402000F */  addiu     $v0, $zero, 0xf
/* 99D9B0 80241020 AFA2001C */  sw        $v0, 0x1c($sp)
/* 99D9B4 80241024 44833000 */  mtc1      $v1, $f6
/* 99D9B8 80241028 00000000 */  nop       
/* 99D9BC 8024102C 468031A0 */  cvt.s.w   $f6, $f6
/* 99D9C0 80241030 44073000 */  mfc1      $a3, $f6
/* 99D9C4 80241034 27A20028 */  addiu     $v0, $sp, 0x28
/* 99D9C8 80241038 AFA20020 */  sw        $v0, 0x20($sp)
/* 99D9CC 8024103C E7A00010 */  swc1      $f0, 0x10($sp)
/* 99D9D0 80241040 E7A20014 */  swc1      $f2, 0x14($sp)
/* 99D9D4 80241044 0C01BFA4 */  jal       fx_emote
/* 99D9D8 80241048 E7A40018 */   swc1     $f4, 0x18($sp)
/* 99D9DC 8024104C 8E4200CC */  lw        $v0, 0xcc($s2)
/* 99D9E0 80241050 8C430000 */  lw        $v1, ($v0)
/* 99D9E4 80241054 24020019 */  addiu     $v0, $zero, 0x19
/* 99D9E8 80241058 A602008E */  sh        $v0, 0x8e($s0)
/* 99D9EC 8024105C 2402000E */  addiu     $v0, $zero, 0xe
/* 99D9F0 80241060 08090427 */  j         .L8024109C
/* 99D9F4 80241064 AE030028 */   sw       $v1, 0x28($s0)
.L80241068:
/* 99D9F8 80241068 8E050018 */  lw        $a1, 0x18($s0)
/* 99D9FC 8024106C 8E06000C */  lw        $a2, 0xc($s0)
/* 99DA00 80241070 0C00EA95 */  jal       npc_move_heading
/* 99DA04 80241074 0200202D */   daddu    $a0, $s0, $zero
/* 99DA08 80241078 0200202D */  daddu     $a0, $s0, $zero
/* 99DA0C 8024107C 0C00F598 */  jal       func_8003D660
/* 99DA10 80241080 24050001 */   addiu    $a1, $zero, 1
/* 99DA14 80241084 9602008E */  lhu       $v0, 0x8e($s0)
/* 99DA18 80241088 2442FFFF */  addiu     $v0, $v0, -1
/* 99DA1C 8024108C A602008E */  sh        $v0, 0x8e($s0)
/* 99DA20 80241090 00021400 */  sll       $v0, $v0, 0x10
/* 99DA24 80241094 14400002 */  bnez      $v0, .L802410A0
/* 99DA28 80241098 2402000C */   addiu    $v0, $zero, 0xc
.L8024109C:
/* 99DA2C 8024109C AE620070 */  sw        $v0, 0x70($s3)
.L802410A0:
/* 99DA30 802410A0 8FBF0040 */  lw        $ra, 0x40($sp)
/* 99DA34 802410A4 8FB3003C */  lw        $s3, 0x3c($sp)
/* 99DA38 802410A8 8FB20038 */  lw        $s2, 0x38($sp)
/* 99DA3C 802410AC 8FB10034 */  lw        $s1, 0x34($sp)
/* 99DA40 802410B0 8FB00030 */  lw        $s0, 0x30($sp)
/* 99DA44 802410B4 03E00008 */  jr        $ra
/* 99DA48 802410B8 27BD0048 */   addiu    $sp, $sp, 0x48
