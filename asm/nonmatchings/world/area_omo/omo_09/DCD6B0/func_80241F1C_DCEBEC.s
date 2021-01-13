.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F1C_DCEBEC
/* DCEBEC 80241F1C 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DCEBF0 80241F20 AFB10024 */  sw        $s1, 0x24($sp)
/* DCEBF4 80241F24 0080882D */  daddu     $s1, $a0, $zero
/* DCEBF8 80241F28 AFBF0028 */  sw        $ra, 0x28($sp)
/* DCEBFC 80241F2C AFB00020 */  sw        $s0, 0x20($sp)
/* DCEC00 80241F30 8E220148 */  lw        $v0, 0x148($s1)
/* DCEC04 80241F34 0C00EABB */  jal       get_npc_unsafe
/* DCEC08 80241F38 84440008 */   lh       $a0, 8($v0)
/* DCEC0C 80241F3C 0040802D */  daddu     $s0, $v0, $zero
/* DCEC10 80241F40 0200202D */  daddu     $a0, $s0, $zero
/* DCEC14 80241F44 C600000C */  lwc1      $f0, 0xc($s0)
/* DCEC18 80241F48 27A60018 */  addiu     $a2, $sp, 0x18
/* DCEC1C 80241F4C E7A00018 */  swc1      $f0, 0x18($sp)
/* DCEC20 80241F50 AFA00010 */  sw        $zero, 0x10($sp)
/* DCEC24 80241F54 AFA00014 */  sw        $zero, 0x14($sp)
/* DCEC28 80241F58 8E050018 */  lw        $a1, 0x18($s0)
/* DCEC2C 80241F5C 0C0129E1 */  jal       func_8004A784
/* DCEC30 80241F60 0000382D */   daddu    $a3, $zero, $zero
/* DCEC34 80241F64 14400005 */  bnez      $v0, .L80241F7C
/* DCEC38 80241F68 00000000 */   nop
/* DCEC3C 80241F6C 8E050018 */  lw        $a1, 0x18($s0)
/* DCEC40 80241F70 8E06000C */  lw        $a2, 0xc($s0)
/* DCEC44 80241F74 0C00EA95 */  jal       npc_move_heading
/* DCEC48 80241F78 0200202D */   daddu    $a0, $s0, $zero
.L80241F7C:
/* DCEC4C 80241F7C 9602008E */  lhu       $v0, 0x8e($s0)
/* DCEC50 80241F80 2442FFFF */  addiu     $v0, $v0, -1
/* DCEC54 80241F84 A602008E */  sh        $v0, 0x8e($s0)
/* DCEC58 80241F88 00021400 */  sll       $v0, $v0, 0x10
/* DCEC5C 80241F8C 14400004 */  bnez      $v0, .L80241FA0
/* DCEC60 80241F90 2402001E */   addiu    $v0, $zero, 0x1e
/* DCEC64 80241F94 A602008E */  sh        $v0, 0x8e($s0)
/* DCEC68 80241F98 24020011 */  addiu     $v0, $zero, 0x11
/* DCEC6C 80241F9C AE220070 */  sw        $v0, 0x70($s1)
.L80241FA0:
/* DCEC70 80241FA0 8FBF0028 */  lw        $ra, 0x28($sp)
/* DCEC74 80241FA4 8FB10024 */  lw        $s1, 0x24($sp)
/* DCEC78 80241FA8 8FB00020 */  lw        $s0, 0x20($sp)
/* DCEC7C 80241FAC 03E00008 */  jr        $ra
/* DCEC80 80241FB0 27BD0030 */   addiu    $sp, $sp, 0x30
