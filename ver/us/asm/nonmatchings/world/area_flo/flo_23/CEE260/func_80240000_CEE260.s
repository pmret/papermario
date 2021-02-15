.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CEE260
/* CEE260 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CEE264 80240004 0000202D */  daddu     $a0, $zero, $zero
/* CEE268 80240008 0080282D */  daddu     $a1, $a0, $zero
/* CEE26C 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* CEE270 80240010 0080382D */  daddu     $a3, $a0, $zero
/* CEE274 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CEE278 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CEE27C 8024001C 0C01CA54 */  jal       func_80072950
/* CEE280 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CEE284 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CEE288 80240028 24020002 */  addiu     $v0, $zero, 2
/* CEE28C 8024002C 03E00008 */  jr        $ra
/* CEE290 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CEE294 80240034 00000000 */  nop
/* CEE298 80240038 00000000 */  nop
/* CEE29C 8024003C 00000000 */  nop
