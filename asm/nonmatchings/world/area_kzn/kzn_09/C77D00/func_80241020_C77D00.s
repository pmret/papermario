.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241020_C77D00
/* C77D00 80241020 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C77D04 80241024 AFB10014 */  sw        $s1, 0x14($sp)
/* C77D08 80241028 0080882D */  daddu     $s1, $a0, $zero
/* C77D0C 8024102C AFBF0018 */  sw        $ra, 0x18($sp)
/* C77D10 80241030 AFB00010 */  sw        $s0, 0x10($sp)
/* C77D14 80241034 8E300148 */  lw        $s0, 0x148($s1)
/* C77D18 80241038 0C00EABB */  jal       get_npc_unsafe
/* C77D1C 8024103C 86040008 */   lh       $a0, 8($s0)
/* C77D20 80241040 24030001 */  addiu     $v1, $zero, 1
/* C77D24 80241044 0040202D */  daddu     $a0, $v0, $zero
/* C77D28 80241048 AE03006C */  sw        $v1, 0x6c($s0)
/* C77D2C 8024104C 8482008C */  lh        $v0, 0x8c($a0)
/* C77D30 80241050 14400009 */  bnez      $v0, .L80241078
/* C77D34 80241054 24020002 */   addiu    $v0, $zero, 2
/* C77D38 80241058 96030072 */  lhu       $v1, 0x72($s0)
/* C77D3C 8024105C AE02006C */  sw        $v0, 0x6c($s0)
/* C77D40 80241060 A483008E */  sh        $v1, 0x8e($a0)
/* C77D44 80241064 8E0200CC */  lw        $v0, 0xcc($s0)
/* C77D48 80241068 8C420020 */  lw        $v0, 0x20($v0)
/* C77D4C 8024106C AC820028 */  sw        $v0, 0x28($a0)
/* C77D50 80241070 2402001F */  addiu     $v0, $zero, 0x1f
/* C77D54 80241074 AE220070 */  sw        $v0, 0x70($s1)
.L80241078:
/* C77D58 80241078 8FBF0018 */  lw        $ra, 0x18($sp)
/* C77D5C 8024107C 8FB10014 */  lw        $s1, 0x14($sp)
/* C77D60 80241080 8FB00010 */  lw        $s0, 0x10($sp)
/* C77D64 80241084 03E00008 */  jr        $ra
/* C77D68 80241088 27BD0020 */   addiu    $sp, $sp, 0x20
