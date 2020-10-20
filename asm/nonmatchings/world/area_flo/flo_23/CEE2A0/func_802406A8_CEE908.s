.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406A8_CEE908
/* CEE908 802406A8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CEE90C 802406AC AFB10014 */  sw        $s1, 0x14($sp)
/* CEE910 802406B0 0080882D */  daddu     $s1, $a0, $zero
/* CEE914 802406B4 AFBF0018 */  sw        $ra, 0x18($sp)
/* CEE918 802406B8 AFB00010 */  sw        $s0, 0x10($sp)
/* CEE91C 802406BC 8E300148 */  lw        $s0, 0x148($s1)
/* CEE920 802406C0 0C00EABB */  jal       get_npc_unsafe
/* CEE924 802406C4 86040008 */   lh       $a0, 8($s0)
/* CEE928 802406C8 0040202D */  daddu     $a0, $v0, $zero
/* CEE92C 802406CC 9482008E */  lhu       $v0, 0x8e($a0)
/* CEE930 802406D0 24030003 */  addiu     $v1, $zero, 3
/* CEE934 802406D4 24420001 */  addiu     $v0, $v0, 1
/* CEE938 802406D8 A482008E */  sh        $v0, 0x8e($a0)
/* CEE93C 802406DC 00021400 */  sll       $v0, $v0, 0x10
/* CEE940 802406E0 00021403 */  sra       $v0, $v0, 0x10
/* CEE944 802406E4 14430003 */  bne       $v0, $v1, .L802406F4
/* CEE948 802406E8 00000000 */   nop      
/* CEE94C 802406EC 96020086 */  lhu       $v0, 0x86($s0)
/* CEE950 802406F0 A48200A8 */  sh        $v0, 0xa8($a0)
.L802406F4:
/* CEE954 802406F4 8482008E */  lh        $v0, 0x8e($a0)
/* CEE958 802406F8 8E030080 */  lw        $v1, 0x80($s0)
/* CEE95C 802406FC 0043102A */  slt       $v0, $v0, $v1
/* CEE960 80240700 14400004 */  bnez      $v0, .L80240714
/* CEE964 80240704 00000000 */   nop      
/* CEE968 80240708 96020086 */  lhu       $v0, 0x86($s0)
/* CEE96C 8024070C A48200A8 */  sh        $v0, 0xa8($a0)
/* CEE970 80240710 AE200070 */  sw        $zero, 0x70($s1)
.L80240714:
/* CEE974 80240714 8FBF0018 */  lw        $ra, 0x18($sp)
/* CEE978 80240718 8FB10014 */  lw        $s1, 0x14($sp)
/* CEE97C 8024071C 8FB00010 */  lw        $s0, 0x10($sp)
/* CEE980 80240720 03E00008 */  jr        $ra
/* CEE984 80240724 27BD0020 */   addiu    $sp, $sp, 0x20
