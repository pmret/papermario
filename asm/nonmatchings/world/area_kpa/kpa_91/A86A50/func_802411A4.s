.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411A4
/* A87BF4 802411A4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A87BF8 802411A8 AFB10014 */  sw        $s1, 0x14($sp)
/* A87BFC 802411AC 0080882D */  daddu     $s1, $a0, $zero
/* A87C00 802411B0 AFBF0018 */  sw        $ra, 0x18($sp)
/* A87C04 802411B4 AFB00010 */  sw        $s0, 0x10($sp)
/* A87C08 802411B8 8E300148 */  lw        $s0, 0x148($s1)
/* A87C0C 802411BC 0C00EABB */  jal       get_npc_unsafe
/* A87C10 802411C0 86040008 */   lh       $a0, 8($s0)
/* A87C14 802411C4 0040202D */  daddu     $a0, $v0, $zero
/* A87C18 802411C8 9482008E */  lhu       $v0, 0x8e($a0)
/* A87C1C 802411CC 24030003 */  addiu     $v1, $zero, 3
/* A87C20 802411D0 24420001 */  addiu     $v0, $v0, 1
/* A87C24 802411D4 A482008E */  sh        $v0, 0x8e($a0)
/* A87C28 802411D8 00021400 */  sll       $v0, $v0, 0x10
/* A87C2C 802411DC 00021403 */  sra       $v0, $v0, 0x10
/* A87C30 802411E0 14430003 */  bne       $v0, $v1, .L802411F0
/* A87C34 802411E4 00000000 */   nop      
/* A87C38 802411E8 96020086 */  lhu       $v0, 0x86($s0)
/* A87C3C 802411EC A48200A8 */  sh        $v0, 0xa8($a0)
.L802411F0:
/* A87C40 802411F0 8482008E */  lh        $v0, 0x8e($a0)
/* A87C44 802411F4 8E030080 */  lw        $v1, 0x80($s0)
/* A87C48 802411F8 0043102A */  slt       $v0, $v0, $v1
/* A87C4C 802411FC 14400004 */  bnez      $v0, .L80241210
/* A87C50 80241200 00000000 */   nop      
/* A87C54 80241204 96020086 */  lhu       $v0, 0x86($s0)
/* A87C58 80241208 A48200A8 */  sh        $v0, 0xa8($a0)
/* A87C5C 8024120C AE200070 */  sw        $zero, 0x70($s1)
.L80241210:
/* A87C60 80241210 8FBF0018 */  lw        $ra, 0x18($sp)
/* A87C64 80241214 8FB10014 */  lw        $s1, 0x14($sp)
/* A87C68 80241218 8FB00010 */  lw        $s0, 0x10($sp)
/* A87C6C 8024121C 03E00008 */  jr        $ra
/* A87C70 80241220 27BD0020 */   addiu    $sp, $sp, 0x20
