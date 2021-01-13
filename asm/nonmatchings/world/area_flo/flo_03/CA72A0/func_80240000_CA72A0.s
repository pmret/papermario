.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_CA72A0
/* CA72A0 80240000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CA72A4 80240004 24040001 */  addiu     $a0, $zero, 1
/* CA72A8 80240008 0000282D */  daddu     $a1, $zero, $zero
/* CA72AC 8024000C 00A0302D */  daddu     $a2, $a1, $zero
/* CA72B0 80240010 00A0382D */  daddu     $a3, $a1, $zero
/* CA72B4 80240014 AFBF0018 */  sw        $ra, 0x18($sp)
/* CA72B8 80240018 AFA00010 */  sw        $zero, 0x10($sp)
/* CA72BC 8024001C 0C01CA54 */  jal       func_80072950
/* CA72C0 80240020 AFA00014 */   sw       $zero, 0x14($sp)
/* CA72C4 80240024 8FBF0018 */  lw        $ra, 0x18($sp)
/* CA72C8 80240028 24020002 */  addiu     $v0, $zero, 2
/* CA72CC 8024002C 03E00008 */  jr        $ra
/* CA72D0 80240030 27BD0020 */   addiu    $sp, $sp, 0x20
/* CA72D4 80240034 00000000 */  nop
/* CA72D8 80240038 00000000 */  nop
/* CA72DC 8024003C 00000000 */  nop
