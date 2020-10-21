.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B38_D9F008
/* D9F008 80241B38 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* D9F00C 80241B3C AFB20038 */  sw        $s2, 0x38($sp)
/* D9F010 80241B40 0080902D */  daddu     $s2, $a0, $zero
/* D9F014 80241B44 AFB00030 */  sw        $s0, 0x30($sp)
/* D9F018 80241B48 AFBF003C */  sw        $ra, 0x3c($sp)
/* D9F01C 80241B4C AFB10034 */  sw        $s1, 0x34($sp)
/* D9F020 80241B50 F7B60048 */  sdc1      $f22, 0x48($sp)
/* D9F024 80241B54 F7B40040 */  sdc1      $f20, 0x40($sp)
/* D9F028 80241B58 8E510148 */  lw        $s1, 0x148($s2)
/* D9F02C 80241B5C 4485A000 */  mtc1      $a1, $f20
/* D9F030 80241B60 86240008 */  lh        $a0, 8($s1)
/* D9F034 80241B64 4486B000 */  mtc1      $a2, $f22
/* D9F038 80241B68 0C00EABB */  jal       get_npc_unsafe
/* D9F03C 80241B6C 00E0802D */   daddu    $s0, $a3, $zero
/* D9F040 80241B70 0200202D */  daddu     $a0, $s0, $zero
/* D9F044 80241B74 0220282D */  daddu     $a1, $s1, $zero
/* D9F048 80241B78 24030001 */  addiu     $v1, $zero, 1
/* D9F04C 80241B7C 4406A000 */  mfc1      $a2, $f20
/* D9F050 80241B80 4407B000 */  mfc1      $a3, $f22
/* D9F054 80241B84 0040802D */  daddu     $s0, $v0, $zero
/* D9F058 80241B88 0C01242D */  jal       func_800490B4
/* D9F05C 80241B8C AFA30010 */   sw       $v1, 0x10($sp)
/* D9F060 80241B90 1440001D */  bnez      $v0, .L80241C08
/* D9F064 80241B94 24040002 */   addiu    $a0, $zero, 2
/* D9F068 80241B98 0200282D */  daddu     $a1, $s0, $zero
/* D9F06C 80241B9C 0000302D */  daddu     $a2, $zero, $zero
/* D9F070 80241BA0 860300A8 */  lh        $v1, 0xa8($s0)
/* D9F074 80241BA4 3C013F80 */  lui       $at, 0x3f80
/* D9F078 80241BA8 44810000 */  mtc1      $at, $f0
/* D9F07C 80241BAC 3C014000 */  lui       $at, 0x4000
/* D9F080 80241BB0 44811000 */  mtc1      $at, $f2
/* D9F084 80241BB4 3C01C1A0 */  lui       $at, 0xc1a0
/* D9F088 80241BB8 44812000 */  mtc1      $at, $f4
/* D9F08C 80241BBC 2402000F */  addiu     $v0, $zero, 0xf
/* D9F090 80241BC0 AFA2001C */  sw        $v0, 0x1c($sp)
/* D9F094 80241BC4 44833000 */  mtc1      $v1, $f6
/* D9F098 80241BC8 00000000 */  nop       
/* D9F09C 80241BCC 468031A0 */  cvt.s.w   $f6, $f6
/* D9F0A0 80241BD0 44073000 */  mfc1      $a3, $f6
/* D9F0A4 80241BD4 27A20028 */  addiu     $v0, $sp, 0x28
/* D9F0A8 80241BD8 AFA20020 */  sw        $v0, 0x20($sp)
/* D9F0AC 80241BDC E7A00010 */  swc1      $f0, 0x10($sp)
/* D9F0B0 80241BE0 E7A20014 */  swc1      $f2, 0x14($sp)
/* D9F0B4 80241BE4 0C01BFA4 */  jal       fx_emote
/* D9F0B8 80241BE8 E7A40018 */   swc1     $f4, 0x18($sp)
/* D9F0BC 80241BEC 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9F0C0 80241BF0 8C430000 */  lw        $v1, ($v0)
/* D9F0C4 80241BF4 24020014 */  addiu     $v0, $zero, 0x14
/* D9F0C8 80241BF8 A602008E */  sh        $v0, 0x8e($s0)
/* D9F0CC 80241BFC 24020021 */  addiu     $v0, $zero, 0x21
/* D9F0D0 80241C00 08090716 */  j         .L80241C58
/* D9F0D4 80241C04 AE030028 */   sw       $v1, 0x28($s0)
.L80241C08:
/* D9F0D8 80241C08 0C090652 */  jal       func_80241948_D9EE18
/* D9F0DC 80241C0C 0240202D */   daddu    $a0, $s2, $zero
/* D9F0E0 80241C10 0040202D */  daddu     $a0, $v0, $zero
/* D9F0E4 80241C14 2402FFFF */  addiu     $v0, $zero, -1
/* D9F0E8 80241C18 10820010 */  beq       $a0, $v0, .L80241C5C
/* D9F0EC 80241C1C 00000000 */   nop      
/* D9F0F0 80241C20 0C00FB3A */  jal       get_enemy
/* D9F0F4 80241C24 00000000 */   nop      
/* D9F0F8 80241C28 8C42006C */  lw        $v0, 0x6c($v0)
/* D9F0FC 80241C2C 1440000B */  bnez      $v0, .L80241C5C
/* D9F100 80241C30 00000000 */   nop      
/* D9F104 80241C34 8602008C */  lh        $v0, 0x8c($s0)
/* D9F108 80241C38 14400008 */  bnez      $v0, .L80241C5C
/* D9F10C 80241C3C 00000000 */   nop      
/* D9F110 80241C40 8E2200CC */  lw        $v0, 0xcc($s1)
/* D9F114 80241C44 8C420020 */  lw        $v0, 0x20($v0)
/* D9F118 80241C48 AE020028 */  sw        $v0, 0x28($s0)
/* D9F11C 80241C4C 96220072 */  lhu       $v0, 0x72($s1)
/* D9F120 80241C50 A602008E */  sh        $v0, 0x8e($s0)
/* D9F124 80241C54 2402001E */  addiu     $v0, $zero, 0x1e
.L80241C58:
/* D9F128 80241C58 AE420070 */  sw        $v0, 0x70($s2)
.L80241C5C:
/* D9F12C 80241C5C 8FBF003C */  lw        $ra, 0x3c($sp)
/* D9F130 80241C60 8FB20038 */  lw        $s2, 0x38($sp)
/* D9F134 80241C64 8FB10034 */  lw        $s1, 0x34($sp)
/* D9F138 80241C68 8FB00030 */  lw        $s0, 0x30($sp)
/* D9F13C 80241C6C D7B60048 */  ldc1      $f22, 0x48($sp)
/* D9F140 80241C70 D7B40040 */  ldc1      $f20, 0x40($sp)
/* D9F144 80241C74 03E00008 */  jr        $ra
/* D9F148 80241C78 27BD0050 */   addiu    $sp, $sp, 0x50
