.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241870_A94FB0
/* A94FB0 80241870 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* A94FB4 80241874 AFB10014 */  sw        $s1, 0x14($sp)
/* A94FB8 80241878 0080882D */  daddu     $s1, $a0, $zero
/* A94FBC 8024187C AFBF0018 */  sw        $ra, 0x18($sp)
/* A94FC0 80241880 AFB00010 */  sw        $s0, 0x10($sp)
/* A94FC4 80241884 8E300148 */  lw        $s0, 0x148($s1)
/* A94FC8 80241888 0C00EABB */  jal       get_npc_unsafe
/* A94FCC 8024188C 86040008 */   lh       $a0, 8($s0)
/* A94FD0 80241890 0040202D */  daddu     $a0, $v0, $zero
/* A94FD4 80241894 9482008E */  lhu       $v0, 0x8e($a0)
/* A94FD8 80241898 24030003 */  addiu     $v1, $zero, 3
/* A94FDC 8024189C 24420001 */  addiu     $v0, $v0, 1
/* A94FE0 802418A0 A482008E */  sh        $v0, 0x8e($a0)
/* A94FE4 802418A4 00021400 */  sll       $v0, $v0, 0x10
/* A94FE8 802418A8 00021403 */  sra       $v0, $v0, 0x10
/* A94FEC 802418AC 14430003 */  bne       $v0, $v1, .L802418BC
/* A94FF0 802418B0 00000000 */   nop      
/* A94FF4 802418B4 96020086 */  lhu       $v0, 0x86($s0)
/* A94FF8 802418B8 A48200A8 */  sh        $v0, 0xa8($a0)
.L802418BC:
/* A94FFC 802418BC 8482008E */  lh        $v0, 0x8e($a0)
/* A95000 802418C0 8E030080 */  lw        $v1, 0x80($s0)
/* A95004 802418C4 0043102A */  slt       $v0, $v0, $v1
/* A95008 802418C8 14400004 */  bnez      $v0, .L802418DC
/* A9500C 802418CC 00000000 */   nop      
/* A95010 802418D0 96020086 */  lhu       $v0, 0x86($s0)
/* A95014 802418D4 A48200A8 */  sh        $v0, 0xa8($a0)
/* A95018 802418D8 AE200070 */  sw        $zero, 0x70($s1)
.L802418DC:
/* A9501C 802418DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* A95020 802418E0 8FB10014 */  lw        $s1, 0x14($sp)
/* A95024 802418E4 8FB00010 */  lw        $s0, 0x10($sp)
/* A95028 802418E8 03E00008 */  jr        $ra
/* A9502C 802418EC 27BD0020 */   addiu    $sp, $sp, 0x20
