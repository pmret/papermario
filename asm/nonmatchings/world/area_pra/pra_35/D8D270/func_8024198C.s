.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024198C
/* D8EBDC 8024198C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D8EBE0 80241990 AFB10014 */  sw        $s1, 0x14($sp)
/* D8EBE4 80241994 0080882D */  daddu     $s1, $a0, $zero
/* D8EBE8 80241998 AFBF0018 */  sw        $ra, 0x18($sp)
/* D8EBEC 8024199C AFB00010 */  sw        $s0, 0x10($sp)
/* D8EBF0 802419A0 8E300148 */  lw        $s0, 0x148($s1)
/* D8EBF4 802419A4 0C00EABB */  jal       get_npc_unsafe
/* D8EBF8 802419A8 86040008 */   lh       $a0, 8($s0)
/* D8EBFC 802419AC 9443008E */  lhu       $v1, 0x8e($v0)
/* D8EC00 802419B0 2463FFFF */  addiu     $v1, $v1, -1
/* D8EC04 802419B4 A443008E */  sh        $v1, 0x8e($v0)
/* D8EC08 802419B8 00031C00 */  sll       $v1, $v1, 0x10
/* D8EC0C 802419BC 14600008 */  bnez      $v1, .L802419E0
/* D8EC10 802419C0 00000000 */   nop      
/* D8EC14 802419C4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* D8EC18 802419C8 30420080 */  andi      $v0, $v0, 0x80
/* D8EC1C 802419CC 10400003 */  beqz      $v0, .L802419DC
/* D8EC20 802419D0 2402000F */   addiu    $v0, $zero, 0xf
/* D8EC24 802419D4 08090678 */  j         .L802419E0
/* D8EC28 802419D8 AE220070 */   sw       $v0, 0x70($s1)
.L802419DC:
/* D8EC2C 802419DC AE200070 */  sw        $zero, 0x70($s1)
.L802419E0:
/* D8EC30 802419E0 8FBF0018 */  lw        $ra, 0x18($sp)
/* D8EC34 802419E4 8FB10014 */  lw        $s1, 0x14($sp)
/* D8EC38 802419E8 8FB00010 */  lw        $s0, 0x10($sp)
/* D8EC3C 802419EC 03E00008 */  jr        $ra
/* D8EC40 802419F0 27BD0020 */   addiu    $sp, $sp, 0x20
