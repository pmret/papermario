.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E9C_B2D30C
/* B2D30C 80240E9C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2D310 80240EA0 AFB10014 */  sw        $s1, 0x14($sp)
/* B2D314 80240EA4 0080882D */  daddu     $s1, $a0, $zero
/* B2D318 80240EA8 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2D31C 80240EAC AFB00010 */  sw        $s0, 0x10($sp)
/* B2D320 80240EB0 8E300148 */  lw        $s0, 0x148($s1)
/* B2D324 80240EB4 0C00EABB */  jal       get_npc_unsafe
/* B2D328 80240EB8 86040008 */   lh       $a0, 8($s0)
/* B2D32C 80240EBC 9443008E */  lhu       $v1, 0x8e($v0)
/* B2D330 80240EC0 2463FFFF */  addiu     $v1, $v1, -1
/* B2D334 80240EC4 A443008E */  sh        $v1, 0x8e($v0)
/* B2D338 80240EC8 00031C00 */  sll       $v1, $v1, 0x10
/* B2D33C 80240ECC 14600008 */  bnez      $v1, .L80240EF0
/* B2D340 80240ED0 00000000 */   nop      
/* B2D344 80240ED4 8E0200B0 */  lw        $v0, 0xb0($s0)
/* B2D348 80240ED8 30420080 */  andi      $v0, $v0, 0x80
/* B2D34C 80240EDC 10400003 */  beqz      $v0, .L80240EEC
/* B2D350 80240EE0 2402000F */   addiu    $v0, $zero, 0xf
/* B2D354 80240EE4 080903BC */  j         .L80240EF0
/* B2D358 80240EE8 AE220070 */   sw       $v0, 0x70($s1)
.L80240EEC:
/* B2D35C 80240EEC AE200070 */  sw        $zero, 0x70($s1)
.L80240EF0:
/* B2D360 80240EF0 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2D364 80240EF4 8FB10014 */  lw        $s1, 0x14($sp)
/* B2D368 80240EF8 8FB00010 */  lw        $s0, 0x10($sp)
/* B2D36C 80240EFC 03E00008 */  jr        $ra
/* B2D370 80240F00 27BD0020 */   addiu    $sp, $sp, 0x20
