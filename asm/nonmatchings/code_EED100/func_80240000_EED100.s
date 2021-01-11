.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EED100
/* EED100 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EED104 80240004 24040001 */  addiu     $a0, $zero, 1
/* EED108 80240008 0000282D */  daddu     $a1, $zero, $zero
/* EED10C 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* EED110 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* EED114 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EED118 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EED11C 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EED120 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EED124 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EED128 80240028 24020002 */  addiu     $v0, $zero, 2
/* EED12C 8024002C 03E00008 */  jr        $ra
/* EED130 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EED134 80240034 00000000 */  nop       
/* EED138 80240038 00000000 */  nop       
/* EED13C 8024003C 00000000 */  nop       
