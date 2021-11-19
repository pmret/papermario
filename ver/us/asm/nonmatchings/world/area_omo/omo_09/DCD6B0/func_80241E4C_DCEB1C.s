.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

dlabel D_8024A978_DD7648
.double 0.6

.section .text

glabel func_80241E4C_DCEB1C
/* DCEB1C 80241E4C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCEB20 80241E50 AFB20028 */  sw        $s2, 0x28($sp)
/* DCEB24 80241E54 0080902D */  daddu     $s2, $a0, $zero
/* DCEB28 80241E58 AFBF002C */  sw        $ra, 0x2c($sp)
/* DCEB2C 80241E5C AFB10024 */  sw        $s1, 0x24($sp)
/* DCEB30 80241E60 AFB00020 */  sw        $s0, 0x20($sp)
/* DCEB34 80241E64 8E510148 */  lw        $s1, 0x148($s2)
/* DCEB38 80241E68 0C00EABB */  jal       get_npc_unsafe
/* DCEB3C 80241E6C 86240008 */   lh       $a0, 8($s1)
/* DCEB40 80241E70 0040802D */  daddu     $s0, $v0, $zero
/* DCEB44 80241E74 0200202D */  daddu     $a0, $s0, $zero
/* DCEB48 80241E78 C600000C */  lwc1      $f0, 0xc($s0)
/* DCEB4C 80241E7C 27A60018 */  addiu     $a2, $sp, 0x18
/* DCEB50 80241E80 E7A00018 */  swc1      $f0, 0x18($sp)
/* DCEB54 80241E84 AFA00010 */  sw        $zero, 0x10($sp)
/* DCEB58 80241E88 AFA00014 */  sw        $zero, 0x14($sp)
/* DCEB5C 80241E8C 8E050018 */  lw        $a1, 0x18($s0)
/* DCEB60 80241E90 0C0129E1 */  jal       func_8004A784
/* DCEB64 80241E94 0000382D */   daddu    $a3, $zero, $zero
/* DCEB68 80241E98 14400005 */  bnez      $v0, .L80241EB0
/* DCEB6C 80241E9C 00000000 */   nop
/* DCEB70 80241EA0 8E050018 */  lw        $a1, 0x18($s0)
/* DCEB74 80241EA4 8E06000C */  lw        $a2, 0xc($s0)
/* DCEB78 80241EA8 0C00EA95 */  jal       npc_move_heading
/* DCEB7C 80241EAC 0200202D */   daddu    $a0, $s0, $zero
.L80241EB0:
/* DCEB80 80241EB0 9602008E */  lhu       $v0, 0x8e($s0)
/* DCEB84 80241EB4 2442FFFF */  addiu     $v0, $v0, -1
/* DCEB88 80241EB8 A602008E */  sh        $v0, 0x8e($s0)
/* DCEB8C 80241EBC 00021400 */  sll       $v0, $v0, 0x10
/* DCEB90 80241EC0 14400010 */  bnez      $v0, .L80241F04
/* DCEB94 80241EC4 00000000 */   nop
/* DCEB98 80241EC8 C6000018 */  lwc1      $f0, 0x18($s0)
/* DCEB9C 80241ECC 3C018025 */  lui       $at, %hi(D_8024A978_DD7648)
/* DCEBA0 80241ED0 D422A978 */  ldc1      $f2, %lo(D_8024A978_DD7648)($at)
/* DCEBA4 80241ED4 46000021 */  cvt.d.s   $f0, $f0
/* DCEBA8 80241ED8 46220002 */  mul.d     $f0, $f0, $f2
/* DCEBAC 80241EDC 00000000 */  nop
/* DCEBB0 80241EE0 46200020 */  cvt.s.d   $f0, $f0
/* DCEBB4 80241EE4 E6000018 */  swc1      $f0, 0x18($s0)
/* DCEBB8 80241EE8 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCEBBC 80241EEC 8C43002C */  lw        $v1, 0x2c($v0)
/* DCEBC0 80241EF0 2402000A */  addiu     $v0, $zero, 0xa
/* DCEBC4 80241EF4 A602008E */  sh        $v0, 0x8e($s0)
/* DCEBC8 80241EF8 24020010 */  addiu     $v0, $zero, 0x10
/* DCEBCC 80241EFC AE030028 */  sw        $v1, 0x28($s0)
/* DCEBD0 80241F00 AE420070 */  sw        $v0, 0x70($s2)
.L80241F04:
/* DCEBD4 80241F04 8FBF002C */  lw        $ra, 0x2c($sp)
/* DCEBD8 80241F08 8FB20028 */  lw        $s2, 0x28($sp)
/* DCEBDC 80241F0C 8FB10024 */  lw        $s1, 0x24($sp)
/* DCEBE0 80241F10 8FB00020 */  lw        $s0, 0x20($sp)
/* DCEBE4 80241F14 03E00008 */  jr        $ra
/* DCEBE8 80241F18 27BD0030 */   addiu    $sp, $sp, 0x30
