.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel jan_08_UnkFunc37
/* B5E9E4 80240734 3C028011 */  lui       $v0, %hi(gPlayerData)
/* B5E9E8 80240738 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* B5E9EC 8024073C 000420C0 */  sll       $a0, $a0, 3
/* B5E9F0 80240740 00822021 */  addu      $a0, $a0, $v0
/* B5E9F4 80240744 90820014 */  lbu       $v0, 0x14($a0)
/* B5E9F8 80240748 10400009 */  beqz      $v0, .L80240770
/* B5E9FC 8024074C 00000000 */   nop
/* B5EA00 80240750 90820015 */  lbu       $v0, 0x15($a0)
/* B5EA04 80240754 00022600 */  sll       $a0, $v0, 0x18
/* B5EA08 80240758 00041E03 */  sra       $v1, $a0, 0x18
/* B5EA0C 8024075C 00051400 */  sll       $v0, $a1, 0x10
/* B5EA10 80240760 00021403 */  sra       $v0, $v0, 0x10
/* B5EA14 80240764 0043102A */  slt       $v0, $v0, $v1
/* B5EA18 80240768 10400003 */  beqz      $v0, .L80240778
/* B5EA1C 8024076C 00000000 */   nop
.L80240770:
/* B5EA20 80240770 03E00008 */  jr        $ra
/* B5EA24 80240774 2402FFFF */   addiu    $v0, $zero, -1
.L80240778:
/* B5EA28 80240778 03E00008 */  jr        $ra
/* B5EA2C 8024077C 00041603 */   sra      $v0, $a0, 0x18
