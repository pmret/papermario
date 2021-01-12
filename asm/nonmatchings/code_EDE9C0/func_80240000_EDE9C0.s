.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_EDE9C0
/* EDE9C0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* EDE9C4 80240004 0000202D */  daddu     $a0, $zero, $zero
/* EDE9C8 80240008 0080282D */  daddu     $a1, $a0, $zero
/* EDE9CC 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* EDE9D0 80240010 0080382D */  daddu     $a3, $a0, $zero
/* EDE9D4 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* EDE9D8 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* EDE9DC 8024001C 0C01DEF4 */  jal       func_80077BD0
/* EDE9E0 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* EDE9E4 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* EDE9E8 80240028 24020002 */  addiu     $v0, $zero, 2
/* EDE9EC 8024002C 03E00008 */  jr        $ra
/* EDE9F0 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* EDE9F4 80240034 00000000 */  nop       
/* EDE9F8 80240038 00000000 */  nop       
/* EDE9FC 8024003C 00000000 */  nop       
