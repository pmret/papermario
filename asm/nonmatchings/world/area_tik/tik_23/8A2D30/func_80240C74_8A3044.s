.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C74_8A3044
/* 8A3044 80240C74 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 8A3048 80240C78 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A304C 80240C7C 0080882D */  daddu     $s1, $a0, $zero
/* 8A3050 80240C80 AFBF0018 */  sw        $ra, 0x18($sp)
/* 8A3054 80240C84 AFB00010 */  sw        $s0, 0x10($sp)
/* 8A3058 80240C88 8E300148 */  lw        $s0, 0x148($s1)
/* 8A305C 80240C8C 0C00EABB */  jal       get_npc_unsafe
/* 8A3060 80240C90 86040008 */   lh       $a0, 8($s0)
/* 8A3064 80240C94 0040202D */  daddu     $a0, $v0, $zero
/* 8A3068 80240C98 9482008E */  lhu       $v0, 0x8e($a0)
/* 8A306C 80240C9C 24030003 */  addiu     $v1, $zero, 3
/* 8A3070 80240CA0 24420001 */  addiu     $v0, $v0, 1
/* 8A3074 80240CA4 A482008E */  sh        $v0, 0x8e($a0)
/* 8A3078 80240CA8 00021400 */  sll       $v0, $v0, 0x10
/* 8A307C 80240CAC 00021403 */  sra       $v0, $v0, 0x10
/* 8A3080 80240CB0 14430003 */  bne       $v0, $v1, .L80240CC0
/* 8A3084 80240CB4 00000000 */   nop      
/* 8A3088 80240CB8 96020086 */  lhu       $v0, 0x86($s0)
/* 8A308C 80240CBC A48200A8 */  sh        $v0, 0xa8($a0)
.L80240CC0:
/* 8A3090 80240CC0 8482008E */  lh        $v0, 0x8e($a0)
/* 8A3094 80240CC4 8E030080 */  lw        $v1, 0x80($s0)
/* 8A3098 80240CC8 0043102A */  slt       $v0, $v0, $v1
/* 8A309C 80240CCC 14400004 */  bnez      $v0, .L80240CE0
/* 8A30A0 80240CD0 00000000 */   nop      
/* 8A30A4 80240CD4 96020086 */  lhu       $v0, 0x86($s0)
/* 8A30A8 80240CD8 A48200A8 */  sh        $v0, 0xa8($a0)
/* 8A30AC 80240CDC AE200070 */  sw        $zero, 0x70($s1)
.L80240CE0:
/* 8A30B0 80240CE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8A30B4 80240CE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A30B8 80240CE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A30BC 80240CEC 03E00008 */  jr        $ra
/* 8A30C0 80240CF0 27BD0020 */   addiu    $sp, $sp, 0x20
