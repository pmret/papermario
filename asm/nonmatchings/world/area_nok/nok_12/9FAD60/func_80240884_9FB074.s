.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240884_9FB074
/* 9FB074 80240884 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9FB078 80240888 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FB07C 8024088C 0080882D */  daddu     $s1, $a0, $zero
/* 9FB080 80240890 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9FB084 80240894 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FB088 80240898 8E300148 */  lw        $s0, 0x148($s1)
/* 9FB08C 8024089C 0C00EABB */  jal       get_npc_unsafe
/* 9FB090 802408A0 86040008 */   lh       $a0, 8($s0)
/* 9FB094 802408A4 0040202D */  daddu     $a0, $v0, $zero
/* 9FB098 802408A8 9482008E */  lhu       $v0, 0x8e($a0)
/* 9FB09C 802408AC 24030003 */  addiu     $v1, $zero, 3
/* 9FB0A0 802408B0 24420001 */  addiu     $v0, $v0, 1
/* 9FB0A4 802408B4 A482008E */  sh        $v0, 0x8e($a0)
/* 9FB0A8 802408B8 00021400 */  sll       $v0, $v0, 0x10
/* 9FB0AC 802408BC 00021403 */  sra       $v0, $v0, 0x10
/* 9FB0B0 802408C0 14430003 */  bne       $v0, $v1, .L802408D0
/* 9FB0B4 802408C4 00000000 */   nop      
/* 9FB0B8 802408C8 96020086 */  lhu       $v0, 0x86($s0)
/* 9FB0BC 802408CC A48200A8 */  sh        $v0, 0xa8($a0)
.L802408D0:
/* 9FB0C0 802408D0 8482008E */  lh        $v0, 0x8e($a0)
/* 9FB0C4 802408D4 8E030080 */  lw        $v1, 0x80($s0)
/* 9FB0C8 802408D8 0043102A */  slt       $v0, $v0, $v1
/* 9FB0CC 802408DC 14400004 */  bnez      $v0, .L802408F0
/* 9FB0D0 802408E0 00000000 */   nop      
/* 9FB0D4 802408E4 96020086 */  lhu       $v0, 0x86($s0)
/* 9FB0D8 802408E8 A48200A8 */  sh        $v0, 0xa8($a0)
/* 9FB0DC 802408EC AE200070 */  sw        $zero, 0x70($s1)
.L802408F0:
/* 9FB0E0 802408F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9FB0E4 802408F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FB0E8 802408F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FB0EC 802408FC 03E00008 */  jr        $ra
/* 9FB0F0 80240900 27BD0020 */   addiu    $sp, $sp, 0x20
