.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024104C_95C24C
/* 95C24C 8024104C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 95C250 80241050 AFB10014 */  sw        $s1, 0x14($sp)
/* 95C254 80241054 0080882D */  daddu     $s1, $a0, $zero
/* 95C258 80241058 AFBF0018 */  sw        $ra, 0x18($sp)
/* 95C25C 8024105C AFB00010 */  sw        $s0, 0x10($sp)
/* 95C260 80241060 8E300148 */  lw        $s0, 0x148($s1)
/* 95C264 80241064 0C00EABB */  jal       get_npc_unsafe
/* 95C268 80241068 86040008 */   lh       $a0, 8($s0)
/* 95C26C 8024106C 9443008E */  lhu       $v1, 0x8e($v0)
/* 95C270 80241070 2463FFFF */  addiu     $v1, $v1, -1
/* 95C274 80241074 A443008E */  sh        $v1, 0x8e($v0)
/* 95C278 80241078 00031C00 */  sll       $v1, $v1, 0x10
/* 95C27C 8024107C 14600008 */  bnez      $v1, .L802410A0
/* 95C280 80241080 00000000 */   nop      
/* 95C284 80241084 8E0200B0 */  lw        $v0, 0xb0($s0)
/* 95C288 80241088 30420080 */  andi      $v0, $v0, 0x80
/* 95C28C 8024108C 10400003 */  beqz      $v0, .L8024109C
/* 95C290 80241090 2402000F */   addiu    $v0, $zero, 0xf
/* 95C294 80241094 08090428 */  j         .L802410A0
/* 95C298 80241098 AE220070 */   sw       $v0, 0x70($s1)
.L8024109C:
/* 95C29C 8024109C AE200070 */  sw        $zero, 0x70($s1)
.L802410A0:
/* 95C2A0 802410A0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 95C2A4 802410A4 8FB10014 */  lw        $s1, 0x14($sp)
/* 95C2A8 802410A8 8FB00010 */  lw        $s0, 0x10($sp)
/* 95C2AC 802410AC 03E00008 */  jr        $ra
/* 95C2B0 802410B0 27BD0020 */   addiu    $sp, $sp, 0x20
