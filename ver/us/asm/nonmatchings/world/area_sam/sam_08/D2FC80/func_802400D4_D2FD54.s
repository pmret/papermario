.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel sam_08_UnkFunc37
/* D2FD54 802400D4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* D2FD58 802400D8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* D2FD5C 802400DC 000420C0 */  sll       $a0, $a0, 3
/* D2FD60 802400E0 00822021 */  addu      $a0, $a0, $v0
/* D2FD64 802400E4 90820014 */  lbu       $v0, 0x14($a0)
/* D2FD68 802400E8 10400009 */  beqz      $v0, .L80240110
/* D2FD6C 802400EC 00000000 */   nop
/* D2FD70 802400F0 90820015 */  lbu       $v0, 0x15($a0)
/* D2FD74 802400F4 00022600 */  sll       $a0, $v0, 0x18
/* D2FD78 802400F8 00041E03 */  sra       $v1, $a0, 0x18
/* D2FD7C 802400FC 00051400 */  sll       $v0, $a1, 0x10
/* D2FD80 80240100 00021403 */  sra       $v0, $v0, 0x10
/* D2FD84 80240104 0043102A */  slt       $v0, $v0, $v1
/* D2FD88 80240108 10400003 */  beqz      $v0, .L80240118
/* D2FD8C 8024010C 00000000 */   nop
.L80240110:
/* D2FD90 80240110 03E00008 */  jr        $ra
/* D2FD94 80240114 2402FFFF */   addiu    $v0, $zero, -1
.L80240118:
/* D2FD98 80240118 03E00008 */  jr        $ra
/* D2FD9C 8024011C 00041603 */   sra      $v0, $a0, 0x18
