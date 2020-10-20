.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CC0E30
/* CC0E30 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CC0E34 80240004 0000202D */  daddu     $a0, $zero, $zero
/* CC0E38 80240008 0080282D */  daddu     $a1, $a0, $zero
/* CC0E3C 8024000C 0080302D */  daddu     $a2, $a0, $zero
/* CC0E40 80240010 0080382D */  daddu     $a3, $a0, $zero
/* CC0E44 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CC0E48 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CC0E4C 8024001C 0C01CA54 */  jal       func_80072950
/* CC0E50 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CC0E54 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CC0E58 80240028 24020002 */  addiu     $v0, $zero, 2
/* CC0E5C 8024002C 03E00008 */  jr        $ra
/* CC0E60 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CC0E64 80240034 00000000 */  nop       
/* CC0E68 80240038 00000000 */  nop       
/* CC0E6C 8024003C 00000000 */  nop       
