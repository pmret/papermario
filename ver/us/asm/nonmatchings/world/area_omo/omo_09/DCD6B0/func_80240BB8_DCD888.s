.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB8_DCD888
/* DCD888 80240BB8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DCD88C 80240BBC AFB10014 */  sw        $s1, 0x14($sp)
/* DCD890 80240BC0 0080882D */  daddu     $s1, $a0, $zero
/* DCD894 80240BC4 AFBF0018 */  sw        $ra, 0x18($sp)
/* DCD898 80240BC8 AFB00010 */  sw        $s0, 0x10($sp)
/* DCD89C 80240BCC 8E300148 */  lw        $s0, 0x148($s1)
/* DCD8A0 80240BD0 0C00EABB */  jal       get_npc_unsafe
/* DCD8A4 80240BD4 86040008 */   lh       $a0, 8($s0)
/* DCD8A8 80240BD8 0040182D */  daddu     $v1, $v0, $zero
/* DCD8AC 80240BDC 9462008E */  lhu       $v0, 0x8e($v1)
/* DCD8B0 80240BE0 2442FFFF */  addiu     $v0, $v0, -1
/* DCD8B4 80240BE4 A462008E */  sh        $v0, 0x8e($v1)
/* DCD8B8 80240BE8 00021400 */  sll       $v0, $v0, 0x10
/* DCD8BC 80240BEC 14400005 */  bnez      $v0, .L80240C04
/* DCD8C0 80240BF0 00000000 */   nop
/* DCD8C4 80240BF4 8E0200CC */  lw        $v0, 0xcc($s0)
/* DCD8C8 80240BF8 8C420000 */  lw        $v0, ($v0)
/* DCD8CC 80240BFC AC620028 */  sw        $v0, 0x28($v1)
/* DCD8D0 80240C00 AE200070 */  sw        $zero, 0x70($s1)
.L80240C04:
/* DCD8D4 80240C04 8FBF0018 */  lw        $ra, 0x18($sp)
/* DCD8D8 80240C08 8FB10014 */  lw        $s1, 0x14($sp)
/* DCD8DC 80240C0C 8FB00010 */  lw        $s0, 0x10($sp)
/* DCD8E0 80240C10 03E00008 */  jr        $ra
/* DCD8E4 80240C14 27BD0020 */   addiu    $sp, $sp, 0x20
