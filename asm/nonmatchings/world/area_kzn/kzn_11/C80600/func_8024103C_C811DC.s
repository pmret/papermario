.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024103C_C811DC
/* C811DC 8024103C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C811E0 80241040 AFB20018 */  sw        $s2, 0x18($sp)
/* C811E4 80241044 0080902D */  daddu     $s2, $a0, $zero
/* C811E8 80241048 AFBF001C */  sw        $ra, 0x1c($sp)
/* C811EC 8024104C AFB10014 */  sw        $s1, 0x14($sp)
/* C811F0 80241050 AFB00010 */  sw        $s0, 0x10($sp)
/* C811F4 80241054 8E510148 */  lw        $s1, 0x148($s2)
/* C811F8 80241058 0C00EABB */  jal       get_npc_unsafe
/* C811FC 8024105C 86240008 */   lh       $a0, 8($s1)
/* C81200 80241060 0040802D */  daddu     $s0, $v0, $zero
/* C81204 80241064 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C81208 80241068 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C8120C 8024106C C60C0038 */  lwc1      $f12, 0x38($s0)
/* C81210 80241070 C60E0040 */  lwc1      $f14, 0x40($s0)
/* C81214 80241074 A600008E */  sh        $zero, 0x8e($s0)
/* C81218 80241078 8C460028 */  lw        $a2, 0x28($v0)
/* C8121C 8024107C 0C00A720 */  jal       atan2
/* C81220 80241080 8C470030 */   lw       $a3, 0x30($v0)
/* C81224 80241084 E600000C */  swc1      $f0, 0xc($s0)
/* C81228 80241088 8E2200CC */  lw        $v0, 0xcc($s1)
/* C8122C 8024108C 8C420020 */  lw        $v0, 0x20($v0)
/* C81230 80241090 AE020028 */  sw        $v0, 0x28($s0)
/* C81234 80241094 2402000B */  addiu     $v0, $zero, 0xb
/* C81238 80241098 AE420070 */  sw        $v0, 0x70($s2)
/* C8123C 8024109C 8FBF001C */  lw        $ra, 0x1c($sp)
/* C81240 802410A0 8FB20018 */  lw        $s2, 0x18($sp)
/* C81244 802410A4 8FB10014 */  lw        $s1, 0x14($sp)
/* C81248 802410A8 8FB00010 */  lw        $s0, 0x10($sp)
/* C8124C 802410AC 03E00008 */  jr        $ra
/* C81250 802410B0 27BD0020 */   addiu    $sp, $sp, 0x20
