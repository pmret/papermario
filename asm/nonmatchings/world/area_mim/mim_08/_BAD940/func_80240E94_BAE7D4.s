.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E94_BAE7D4
/* BAE7D4 80240E94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BAE7D8 80240E98 AFB00010 */  sw        $s0, 0x10($sp)
/* BAE7DC 80240E9C 0080802D */  daddu     $s0, $a0, $zero
/* BAE7E0 80240EA0 AFBF0014 */  sw        $ra, 0x14($sp)
/* BAE7E4 80240EA4 8E020148 */  lw        $v0, 0x148($s0)
/* BAE7E8 80240EA8 0C00EABB */  jal       get_npc_unsafe
/* BAE7EC 80240EAC 84440008 */   lh       $a0, 8($v0)
/* BAE7F0 80240EB0 0040202D */  daddu     $a0, $v0, $zero
/* BAE7F4 80240EB4 8482008E */  lh        $v0, 0x8e($a0)
/* BAE7F8 80240EB8 9483008E */  lhu       $v1, 0x8e($a0)
/* BAE7FC 80240EBC 18400005 */  blez      $v0, .L80240ED4
/* BAE800 80240EC0 2462FFFF */   addiu    $v0, $v1, -1
/* BAE804 80240EC4 A482008E */  sh        $v0, 0x8e($a0)
/* BAE808 80240EC8 00021400 */  sll       $v0, $v0, 0x10
/* BAE80C 80240ECC 1C400006 */  bgtz      $v0, .L80240EE8
/* BAE810 80240ED0 00000000 */   nop      
.L80240ED4:
/* BAE814 80240ED4 8482008C */  lh        $v0, 0x8c($a0)
/* BAE818 80240ED8 14400003 */  bnez      $v0, .L80240EE8
/* BAE81C 80240EDC 2402000E */   addiu    $v0, $zero, 0xe
/* BAE820 80240EE0 A480008E */  sh        $zero, 0x8e($a0)
/* BAE824 80240EE4 AE020070 */  sw        $v0, 0x70($s0)
.L80240EE8:
/* BAE828 80240EE8 8FBF0014 */  lw        $ra, 0x14($sp)
/* BAE82C 80240EEC 8FB00010 */  lw        $s0, 0x10($sp)
/* BAE830 80240EF0 03E00008 */  jr        $ra
/* BAE834 80240EF4 27BD0018 */   addiu    $sp, $sp, 0x18
