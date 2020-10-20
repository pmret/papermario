.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241284
/* A8DD04 80241284 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A8DD08 80241288 AFB10014 */  sw        $s1, 0x14($sp)
/* A8DD0C 8024128C 0080882D */  daddu     $s1, $a0, $zero
/* A8DD10 80241290 AFBF0018 */  sw        $ra, 0x18($sp)
/* A8DD14 80241294 AFB00010 */  sw        $s0, 0x10($sp)
/* A8DD18 80241298 8E300148 */  lw        $s0, 0x148($s1)
/* A8DD1C 8024129C 0C00EABB */  jal       get_npc_unsafe
/* A8DD20 802412A0 86040008 */   lh       $a0, 8($s0)
/* A8DD24 802412A4 0040202D */  daddu     $a0, $v0, $zero
/* A8DD28 802412A8 9482008E */  lhu       $v0, 0x8e($a0)
/* A8DD2C 802412AC 24030003 */  addiu     $v1, $zero, 3
/* A8DD30 802412B0 24420001 */  addiu     $v0, $v0, 1
/* A8DD34 802412B4 A482008E */  sh        $v0, 0x8e($a0)
/* A8DD38 802412B8 00021400 */  sll       $v0, $v0, 0x10
/* A8DD3C 802412BC 00021403 */  sra       $v0, $v0, 0x10
/* A8DD40 802412C0 14430003 */  bne       $v0, $v1, .L802412D0
/* A8DD44 802412C4 00000000 */   nop      
/* A8DD48 802412C8 96020086 */  lhu       $v0, 0x86($s0)
/* A8DD4C 802412CC A48200A8 */  sh        $v0, 0xa8($a0)
.L802412D0:
/* A8DD50 802412D0 8482008E */  lh        $v0, 0x8e($a0)
/* A8DD54 802412D4 8E030080 */  lw        $v1, 0x80($s0)
/* A8DD58 802412D8 0043102A */  slt       $v0, $v0, $v1
/* A8DD5C 802412DC 14400004 */  bnez      $v0, .L802412F0
/* A8DD60 802412E0 00000000 */   nop      
/* A8DD64 802412E4 96020086 */  lhu       $v0, 0x86($s0)
/* A8DD68 802412E8 A48200A8 */  sh        $v0, 0xa8($a0)
/* A8DD6C 802412EC AE200070 */  sw        $zero, 0x70($s1)
.L802412F0:
/* A8DD70 802412F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* A8DD74 802412F4 8FB10014 */  lw        $s1, 0x14($sp)
/* A8DD78 802412F8 8FB00010 */  lw        $s0, 0x10($sp)
/* A8DD7C 802412FC 03E00008 */  jr        $ra
/* A8DD80 80241300 27BD0020 */   addiu    $sp, $sp, 0x20
