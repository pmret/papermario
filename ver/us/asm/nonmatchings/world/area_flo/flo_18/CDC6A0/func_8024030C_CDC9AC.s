.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024030C_CDC9AC
/* CDC9AC 8024030C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CDC9B0 80240310 24040001 */  addiu     $a0, $zero, 1
/* CDC9B4 80240314 0000282D */  daddu     $a1, $zero, $zero
/* CDC9B8 80240318 00A0302D */  daddu     $a2, $a1, $zero
/* CDC9BC 8024031C 00A0382D */  daddu     $a3, $a1, $zero
/* CDC9C0 80240320 AFBF0018 */  sw        $ra, 0x18($sp)
/* CDC9C4 80240324 AFA00010 */  sw        $zero, 0x10($sp)
/* CDC9C8 80240328 0C01CA54 */  jal       func_80072950
/* CDC9CC 8024032C AFA00014 */   sw       $zero, 0x14($sp)
/* CDC9D0 80240330 8FBF0018 */  lw        $ra, 0x18($sp)
/* CDC9D4 80240334 24020002 */  addiu     $v0, $zero, 2
/* CDC9D8 80240338 03E00008 */  jr        $ra
/* CDC9DC 8024033C 27BD0020 */   addiu    $sp, $sp, 0x20
