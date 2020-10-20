.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FDC_9B895C
/* 9B895C 80241FDC 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9B8960 80241FE0 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9B8964 80241FE4 0080982D */  daddu     $s3, $a0, $zero
/* 9B8968 80241FE8 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9B896C 80241FEC AFB20018 */  sw        $s2, 0x18($sp)
/* 9B8970 80241FF0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9B8974 80241FF4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9B8978 80241FF8 8E710148 */  lw        $s1, 0x148($s3)
/* 9B897C 80241FFC 0C00EABB */  jal       get_npc_unsafe
/* 9B8980 80242000 86240008 */   lh       $a0, 8($s1)
/* 9B8984 80242004 0040802D */  daddu     $s0, $v0, $zero
/* 9B8988 80242008 C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B898C 8024200C 8E2200CC */  lw        $v0, 0xcc($s1)
/* 9B8990 80242010 3C01C0A0 */  lui       $at, 0xc0a0
/* 9B8994 80242014 44811000 */  mtc1      $at, $f2
/* 9B8998 80242018 3C013E19 */  lui       $at, 0x3e19
/* 9B899C 8024201C 3421999A */  ori       $at, $at, 0x999a
/* 9B89A0 80242020 44810000 */  mtc1      $at, $f0
/* 9B89A4 80242024 8C420024 */  lw        $v0, 0x24($v0)
/* 9B89A8 80242028 3C12800F */  lui       $s2, %hi(gPlayerStatusPtr)
/* 9B89AC 8024202C 26527B30 */  addiu     $s2, $s2, %lo(gPlayerStatusPtr)
/* 9B89B0 80242030 E602001C */  swc1      $f2, 0x1c($s0)
/* 9B89B4 80242034 E6000014 */  swc1      $f0, 0x14($s0)
/* 9B89B8 80242038 AE020028 */  sw        $v0, 0x28($s0)
/* 9B89BC 8024203C 8E22008C */  lw        $v0, 0x8c($s1)
/* 9B89C0 80242040 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B89C4 80242044 00021FC2 */  srl       $v1, $v0, 0x1f
/* 9B89C8 80242048 00431021 */  addu      $v0, $v0, $v1
/* 9B89CC 8024204C 8E430000 */  lw        $v1, ($s2)
/* 9B89D0 80242050 00021043 */  sra       $v0, $v0, 1
/* 9B89D4 80242054 A60200A8 */  sh        $v0, 0xa8($s0)
/* 9B89D8 80242058 8C660028 */  lw        $a2, 0x28($v1)
/* 9B89DC 8024205C 0C00A7B5 */  jal       dist2D
/* 9B89E0 80242060 8C670030 */   lw       $a3, 0x30($v1)
/* 9B89E4 80242064 0200202D */  daddu     $a0, $s0, $zero
/* 9B89E8 80242068 0000302D */  daddu     $a2, $zero, $zero
/* 9B89EC 8024206C C6020038 */  lwc1      $f2, 0x38($s0)
/* 9B89F0 80242070 3C0140E0 */  lui       $at, 0x40e0
/* 9B89F4 80242074 44810000 */  mtc1      $at, $f0
/* 9B89F8 80242078 4600110D */  trunc.w.s $f4, $f2
/* 9B89FC 8024207C 44022000 */  mfc1      $v0, $f4
/* 9B8A00 80242080 E6000018 */  swc1      $f0, 0x18($s0)
/* 9B8A04 80242084 A6220010 */  sh        $v0, 0x10($s1)
/* 9B8A08 80242088 C600003C */  lwc1      $f0, 0x3c($s0)
/* 9B8A0C 8024208C 240502C1 */  addiu     $a1, $zero, 0x2c1
/* 9B8A10 80242090 4600010D */  trunc.w.s $f4, $f0
/* 9B8A14 80242094 44022000 */  mfc1      $v0, $f4
/* 9B8A18 80242098 00000000 */  nop       
/* 9B8A1C 8024209C A6220012 */  sh        $v0, 0x12($s1)
/* 9B8A20 802420A0 C6000040 */  lwc1      $f0, 0x40($s0)
/* 9B8A24 802420A4 24020001 */  addiu     $v0, $zero, 1
/* 9B8A28 802420A8 A2220007 */  sb        $v0, 7($s1)
/* 9B8A2C 802420AC 4600010D */  trunc.w.s $f4, $f0
/* 9B8A30 802420B0 44022000 */  mfc1      $v0, $f4
/* 9B8A34 802420B4 0C012530 */  jal       func_800494C0
/* 9B8A38 802420B8 A6220014 */   sh       $v0, 0x14($s1)
/* 9B8A3C 802420BC C60C0038 */  lwc1      $f12, 0x38($s0)
/* 9B8A40 802420C0 8E420000 */  lw        $v0, ($s2)
/* 9B8A44 802420C4 C60E0040 */  lwc1      $f14, 0x40($s0)
/* 9B8A48 802420C8 8C460028 */  lw        $a2, 0x28($v0)
/* 9B8A4C 802420CC 0C00A720 */  jal       atan2
/* 9B8A50 802420D0 8C470030 */   lw       $a3, 0x30($v0)
/* 9B8A54 802420D4 2402000C */  addiu     $v0, $zero, 0xc
/* 9B8A58 802420D8 A602008E */  sh        $v0, 0x8e($s0)
/* 9B8A5C 802420DC 2402000D */  addiu     $v0, $zero, 0xd
/* 9B8A60 802420E0 E600000C */  swc1      $f0, 0xc($s0)
/* 9B8A64 802420E4 AE620070 */  sw        $v0, 0x70($s3)
/* 9B8A68 802420E8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9B8A6C 802420EC 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9B8A70 802420F0 8FB20018 */  lw        $s2, 0x18($sp)
/* 9B8A74 802420F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9B8A78 802420F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9B8A7C 802420FC 03E00008 */  jr        $ra
/* 9B8A80 80242100 27BD0028 */   addiu    $sp, $sp, 0x28
