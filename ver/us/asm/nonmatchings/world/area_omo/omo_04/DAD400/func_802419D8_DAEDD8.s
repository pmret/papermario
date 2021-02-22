.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419D8_DAEDD8
/* DAEDD8 802419D8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* DAEDDC 802419DC AFB10024 */  sw        $s1, 0x24($sp)
/* DAEDE0 802419E0 0080882D */  daddu     $s1, $a0, $zero
/* DAEDE4 802419E4 AFBF0028 */  sw        $ra, 0x28($sp)
/* DAEDE8 802419E8 AFB00020 */  sw        $s0, 0x20($sp)
/* DAEDEC 802419EC 8E220148 */  lw        $v0, 0x148($s1)
/* DAEDF0 802419F0 0C00EABB */  jal       get_npc_unsafe
/* DAEDF4 802419F4 84440008 */   lh       $a0, 8($v0)
/* DAEDF8 802419F8 0040802D */  daddu     $s0, $v0, $zero
/* DAEDFC 802419FC 0200202D */  daddu     $a0, $s0, $zero
/* DAEE00 80241A00 C600000C */  lwc1      $f0, 0xc($s0)
/* DAEE04 80241A04 27A60018 */  addiu     $a2, $sp, 0x18
/* DAEE08 80241A08 E7A00018 */  swc1      $f0, 0x18($sp)
/* DAEE0C 80241A0C AFA00010 */  sw        $zero, 0x10($sp)
/* DAEE10 80241A10 AFA00014 */  sw        $zero, 0x14($sp)
/* DAEE14 80241A14 8E050018 */  lw        $a1, 0x18($s0)
/* DAEE18 80241A18 0C0129E1 */  jal       func_8004A784
/* DAEE1C 80241A1C 0000382D */   daddu    $a3, $zero, $zero
/* DAEE20 80241A20 14400005 */  bnez      $v0, .L80241A38
/* DAEE24 80241A24 00000000 */   nop
/* DAEE28 80241A28 8E050018 */  lw        $a1, 0x18($s0)
/* DAEE2C 80241A2C 8E06000C */  lw        $a2, 0xc($s0)
/* DAEE30 80241A30 0C00EA95 */  jal       npc_move_heading
/* DAEE34 80241A34 0200202D */   daddu    $a0, $s0, $zero
.L80241A38:
/* DAEE38 80241A38 9602008E */  lhu       $v0, 0x8e($s0)
/* DAEE3C 80241A3C 2442FFFF */  addiu     $v0, $v0, -1
/* DAEE40 80241A40 A602008E */  sh        $v0, 0x8e($s0)
/* DAEE44 80241A44 00021400 */  sll       $v0, $v0, 0x10
/* DAEE48 80241A48 14400004 */  bnez      $v0, .L80241A5C
/* DAEE4C 80241A4C 2402001E */   addiu    $v0, $zero, 0x1e
/* DAEE50 80241A50 A602008E */  sh        $v0, 0x8e($s0)
/* DAEE54 80241A54 24020011 */  addiu     $v0, $zero, 0x11
/* DAEE58 80241A58 AE220070 */  sw        $v0, 0x70($s1)
.L80241A5C:
/* DAEE5C 80241A5C 8FBF0028 */  lw        $ra, 0x28($sp)
/* DAEE60 80241A60 8FB10024 */  lw        $s1, 0x24($sp)
/* DAEE64 80241A64 8FB00020 */  lw        $s0, 0x20($sp)
/* DAEE68 80241A68 03E00008 */  jr        $ra
/* DAEE6C 80241A6C 27BD0030 */   addiu    $sp, $sp, 0x30
