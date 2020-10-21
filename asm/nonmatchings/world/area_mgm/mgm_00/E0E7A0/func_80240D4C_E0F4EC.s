.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D4C_E0F4EC
/* E0F4EC 80240D4C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E0F4F0 80240D50 AFB10014 */  sw        $s1, 0x14($sp)
/* E0F4F4 80240D54 0080882D */  daddu     $s1, $a0, $zero
/* E0F4F8 80240D58 AFBF0018 */  sw        $ra, 0x18($sp)
/* E0F4FC 80240D5C AFB00010 */  sw        $s0, 0x10($sp)
/* E0F500 80240D60 8E300148 */  lw        $s0, 0x148($s1)
/* E0F504 80240D64 0C00EABB */  jal       get_npc_unsafe
/* E0F508 80240D68 86040008 */   lh       $a0, 8($s0)
/* E0F50C 80240D6C 9443008E */  lhu       $v1, 0x8e($v0)
/* E0F510 80240D70 2463FFFF */  addiu     $v1, $v1, -1
/* E0F514 80240D74 A443008E */  sh        $v1, 0x8e($v0)
/* E0F518 80240D78 00031C00 */  sll       $v1, $v1, 0x10
/* E0F51C 80240D7C 14600008 */  bnez      $v1, .L80240DA0
/* E0F520 80240D80 00000000 */   nop      
/* E0F524 80240D84 8E0200B0 */  lw        $v0, 0xb0($s0)
/* E0F528 80240D88 30420080 */  andi      $v0, $v0, 0x80
/* E0F52C 80240D8C 10400003 */  beqz      $v0, .L80240D9C
/* E0F530 80240D90 2402000F */   addiu    $v0, $zero, 0xf
/* E0F534 80240D94 08090368 */  j         .L80240DA0
/* E0F538 80240D98 AE220070 */   sw       $v0, 0x70($s1)
.L80240D9C:
/* E0F53C 80240D9C AE200070 */  sw        $zero, 0x70($s1)
.L80240DA0:
/* E0F540 80240DA0 8FBF0018 */  lw        $ra, 0x18($sp)
/* E0F544 80240DA4 8FB10014 */  lw        $s1, 0x14($sp)
/* E0F548 80240DA8 8FB00010 */  lw        $s0, 0x10($sp)
/* E0F54C 80240DAC 03E00008 */  jr        $ra
/* E0F550 80240DB0 27BD0020 */   addiu    $sp, $sp, 0x20
