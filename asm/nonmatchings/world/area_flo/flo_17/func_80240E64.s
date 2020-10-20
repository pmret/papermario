.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E64
/* CD8144 80240E64 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD8148 80240E68 AFB00010 */  sw        $s0, 0x10($sp)
/* CD814C 80240E6C 0080802D */  daddu     $s0, $a0, $zero
/* CD8150 80240E70 AFBF0014 */  sw        $ra, 0x14($sp)
/* CD8154 80240E74 8E020148 */  lw        $v0, 0x148($s0)
/* CD8158 80240E78 0C00EABB */  jal       get_npc_unsafe
/* CD815C 80240E7C 84440008 */   lh       $a0, 8($v0)
/* CD8160 80240E80 0040202D */  daddu     $a0, $v0, $zero
/* CD8164 80240E84 8482008E */  lh        $v0, 0x8e($a0)
/* CD8168 80240E88 9483008E */  lhu       $v1, 0x8e($a0)
/* CD816C 80240E8C 18400005 */  blez      $v0, .L80240EA4
/* CD8170 80240E90 2462FFFF */   addiu    $v0, $v1, -1
/* CD8174 80240E94 A482008E */  sh        $v0, 0x8e($a0)
/* CD8178 80240E98 00021400 */  sll       $v0, $v0, 0x10
/* CD817C 80240E9C 1C400006 */  bgtz      $v0, .L80240EB8
/* CD8180 80240EA0 00000000 */   nop      
.L80240EA4:
/* CD8184 80240EA4 8482008C */  lh        $v0, 0x8c($a0)
/* CD8188 80240EA8 14400003 */  bnez      $v0, .L80240EB8
/* CD818C 80240EAC 2402000E */   addiu    $v0, $zero, 0xe
/* CD8190 80240EB0 A480008E */  sh        $zero, 0x8e($a0)
/* CD8194 80240EB4 AE020070 */  sw        $v0, 0x70($s0)
.L80240EB8:
/* CD8198 80240EB8 8FBF0014 */  lw        $ra, 0x14($sp)
/* CD819C 80240EBC 8FB00010 */  lw        $s0, 0x10($sp)
/* CD81A0 80240EC0 03E00008 */  jr        $ra
/* CD81A4 80240EC4 27BD0018 */   addiu    $sp, $sp, 0x18
