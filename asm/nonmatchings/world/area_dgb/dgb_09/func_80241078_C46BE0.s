.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241078_C47C58
/* C47C58 80241078 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C47C5C 8024107C AFB00010 */  sw        $s0, 0x10($sp)
/* C47C60 80241080 0080802D */  daddu     $s0, $a0, $zero
/* C47C64 80241084 AFBF0014 */  sw        $ra, 0x14($sp)
/* C47C68 80241088 8E020148 */  lw        $v0, 0x148($s0)
/* C47C6C 8024108C 0C00EABB */  jal       get_npc_unsafe
/* C47C70 80241090 84440008 */   lh       $a0, 8($v0)
/* C47C74 80241094 0040182D */  daddu     $v1, $v0, $zero
/* C47C78 80241098 8462008C */  lh        $v0, 0x8c($v1)
/* C47C7C 8024109C 14400009 */  bnez      $v0, .L802410C4
/* C47C80 802410A0 00000000 */   nop      
/* C47C84 802410A4 9462008E */  lhu       $v0, 0x8e($v1)
/* C47C88 802410A8 2442FFFF */  addiu     $v0, $v0, -1
/* C47C8C 802410AC A462008E */  sh        $v0, 0x8e($v1)
/* C47C90 802410B0 00021400 */  sll       $v0, $v0, 0x10
/* C47C94 802410B4 1C400003 */  bgtz      $v0, .L802410C4
/* C47C98 802410B8 00000000 */   nop      
/* C47C9C 802410BC A460008E */  sh        $zero, 0x8e($v1)
/* C47CA0 802410C0 AE000070 */  sw        $zero, 0x70($s0)
.L802410C4:
/* C47CA4 802410C4 8FBF0014 */  lw        $ra, 0x14($sp)
/* C47CA8 802410C8 8FB00010 */  lw        $s0, 0x10($sp)
/* C47CAC 802410CC 03E00008 */  jr        $ra
/* C47CB0 802410D0 27BD0018 */   addiu    $sp, $sp, 0x18
