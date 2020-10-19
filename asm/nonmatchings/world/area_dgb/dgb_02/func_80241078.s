.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241078
/* C2FC18 80241078 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C2FC1C 8024107C AFB00010 */  sw        $s0, 0x10($sp)
/* C2FC20 80241080 0080802D */  daddu     $s0, $a0, $zero
/* C2FC24 80241084 AFBF0014 */  sw        $ra, 0x14($sp)
/* C2FC28 80241088 8E020148 */  lw        $v0, 0x148($s0)
/* C2FC2C 8024108C 0C00EABB */  jal       get_npc_unsafe
/* C2FC30 80241090 84440008 */   lh       $a0, 8($v0)
/* C2FC34 80241094 0040182D */  daddu     $v1, $v0, $zero
/* C2FC38 80241098 8462008C */  lh        $v0, 0x8c($v1)
/* C2FC3C 8024109C 14400009 */  bnez      $v0, .L802410C4
/* C2FC40 802410A0 00000000 */   nop      
/* C2FC44 802410A4 9462008E */  lhu       $v0, 0x8e($v1)
/* C2FC48 802410A8 2442FFFF */  addiu     $v0, $v0, -1
/* C2FC4C 802410AC A462008E */  sh        $v0, 0x8e($v1)
/* C2FC50 802410B0 00021400 */  sll       $v0, $v0, 0x10
/* C2FC54 802410B4 1C400003 */  bgtz      $v0, .L802410C4
/* C2FC58 802410B8 00000000 */   nop      
/* C2FC5C 802410BC A460008E */  sh        $zero, 0x8e($v1)
/* C2FC60 802410C0 AE000070 */  sw        $zero, 0x70($s0)
.L802410C4:
/* C2FC64 802410C4 8FBF0014 */  lw        $ra, 0x14($sp)
/* C2FC68 802410C8 8FB00010 */  lw        $s0, 0x10($sp)
/* C2FC6C 802410CC 03E00008 */  jr        $ra
/* C2FC70 802410D0 27BD0018 */   addiu    $sp, $sp, 0x18
