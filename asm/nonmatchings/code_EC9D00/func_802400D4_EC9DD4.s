.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D4_EC9DD4
/* EC9DD4 802400D4 3C028011 */  lui       $v0, %hi(D_80117840)
/* EC9DD8 802400D8 24427840 */  addiu     $v0, $v0, %lo(D_80117840)
/* EC9DDC 802400DC 000420C0 */  sll       $a0, $a0, 3
/* EC9DE0 802400E0 00822021 */  addu      $a0, $a0, $v0
/* EC9DE4 802400E4 90820014 */  lbu       $v0, 0x14($a0)
/* EC9DE8 802400E8 10400009 */  beqz      $v0, .L80240110
/* EC9DEC 802400EC 00000000 */   nop      
/* EC9DF0 802400F0 90820015 */  lbu       $v0, 0x15($a0)
/* EC9DF4 802400F4 00022600 */  sll       $a0, $v0, 0x18
/* EC9DF8 802400F8 00041E03 */  sra       $v1, $a0, 0x18
/* EC9DFC 802400FC 00051400 */  sll       $v0, $a1, 0x10
/* EC9E00 80240100 00021403 */  sra       $v0, $v0, 0x10
/* EC9E04 80240104 0043102A */  slt       $v0, $v0, $v1
/* EC9E08 80240108 10400003 */  beqz      $v0, .L80240118
/* EC9E0C 8024010C 00000000 */   nop      
.L80240110:
/* EC9E10 80240110 03E00008 */  jr        $ra
/* EC9E14 80240114 2402FFFF */   addiu    $v0, $zero, -1
.L80240118:
/* EC9E18 80240118 03E00008 */  jr        $ra
/* EC9E1C 8024011C 00041603 */   sra      $v0, $a0, 0x18
