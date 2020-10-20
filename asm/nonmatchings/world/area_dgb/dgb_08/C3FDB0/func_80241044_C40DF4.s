.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241044_C40DF4
/* C40DF4 80241044 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C40DF8 80241048 AFB10014 */  sw        $s1, 0x14($sp)
/* C40DFC 8024104C 0080882D */  daddu     $s1, $a0, $zero
/* C40E00 80241050 AFBF0018 */  sw        $ra, 0x18($sp)
/* C40E04 80241054 AFB00010 */  sw        $s0, 0x10($sp)
/* C40E08 80241058 8E300148 */  lw        $s0, 0x148($s1)
/* C40E0C 8024105C 0C00EABB */  jal       get_npc_unsafe
/* C40E10 80241060 86040008 */   lh       $a0, 8($s0)
/* C40E14 80241064 9443008E */  lhu       $v1, 0x8e($v0)
/* C40E18 80241068 2463FFFF */  addiu     $v1, $v1, -1
/* C40E1C 8024106C A443008E */  sh        $v1, 0x8e($v0)
/* C40E20 80241070 00031C00 */  sll       $v1, $v1, 0x10
/* C40E24 80241074 1C600003 */  bgtz      $v1, .L80241084
/* C40E28 80241078 2402000C */   addiu    $v0, $zero, 0xc
/* C40E2C 8024107C AE00006C */  sw        $zero, 0x6c($s0)
/* C40E30 80241080 AE220070 */  sw        $v0, 0x70($s1)
.L80241084:
/* C40E34 80241084 8FBF0018 */  lw        $ra, 0x18($sp)
/* C40E38 80241088 8FB10014 */  lw        $s1, 0x14($sp)
/* C40E3C 8024108C 8FB00010 */  lw        $s0, 0x10($sp)
/* C40E40 80241090 03E00008 */  jr        $ra
/* C40E44 80241094 27BD0020 */   addiu    $sp, $sp, 0x20
