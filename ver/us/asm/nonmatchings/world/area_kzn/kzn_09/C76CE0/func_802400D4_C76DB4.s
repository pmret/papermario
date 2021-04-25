.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel kzn_09_UnkFunc37
/* C76DB4 802400D4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* C76DB8 802400D8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* C76DBC 802400DC 000420C0 */  sll       $a0, $a0, 3
/* C76DC0 802400E0 00822021 */  addu      $a0, $a0, $v0
/* C76DC4 802400E4 90820014 */  lbu       $v0, 0x14($a0)
/* C76DC8 802400E8 10400009 */  beqz      $v0, .L80240110
/* C76DCC 802400EC 00000000 */   nop
/* C76DD0 802400F0 90820015 */  lbu       $v0, 0x15($a0)
/* C76DD4 802400F4 00022600 */  sll       $a0, $v0, 0x18
/* C76DD8 802400F8 00041E03 */  sra       $v1, $a0, 0x18
/* C76DDC 802400FC 00051400 */  sll       $v0, $a1, 0x10
/* C76DE0 80240100 00021403 */  sra       $v0, $v0, 0x10
/* C76DE4 80240104 0043102A */  slt       $v0, $v0, $v1
/* C76DE8 80240108 10400003 */  beqz      $v0, .L80240118
/* C76DEC 8024010C 00000000 */   nop
.L80240110:
/* C76DF0 80240110 03E00008 */  jr        $ra
/* C76DF4 80240114 2402FFFF */   addiu    $v0, $zero, -1
.L80240118:
/* C76DF8 80240118 03E00008 */  jr        $ra
/* C76DFC 8024011C 00041603 */   sra      $v0, $a0, 0x18
