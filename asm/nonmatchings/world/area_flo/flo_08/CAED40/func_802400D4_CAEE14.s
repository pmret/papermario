.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802400D4_CAEE14
/* CAEE14 802400D4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* CAEE18 802400D8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* CAEE1C 802400DC 000420C0 */  sll       $a0, $a0, 3
/* CAEE20 802400E0 00822021 */  addu      $a0, $a0, $v0
/* CAEE24 802400E4 90820014 */  lbu       $v0, 0x14($a0)
/* CAEE28 802400E8 10400009 */  beqz      $v0, .L80240110
/* CAEE2C 802400EC 00000000 */   nop      
/* CAEE30 802400F0 90820015 */  lbu       $v0, 0x15($a0)
/* CAEE34 802400F4 00022600 */  sll       $a0, $v0, 0x18
/* CAEE38 802400F8 00041E03 */  sra       $v1, $a0, 0x18
/* CAEE3C 802400FC 00051400 */  sll       $v0, $a1, 0x10
/* CAEE40 80240100 00021403 */  sra       $v0, $v0, 0x10
/* CAEE44 80240104 0043102A */  slt       $v0, $v0, $v1
/* CAEE48 80240108 10400003 */  beqz      $v0, .L80240118
/* CAEE4C 8024010C 00000000 */   nop      
.L80240110:
/* CAEE50 80240110 03E00008 */  jr        $ra
/* CAEE54 80240114 2402FFFF */   addiu    $v0, $zero, -1
.L80240118:
/* CAEE58 80240118 03E00008 */  jr        $ra
/* CAEE5C 8024011C 00041603 */   sra      $v0, $a0, 0x18
