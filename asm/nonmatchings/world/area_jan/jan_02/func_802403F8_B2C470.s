.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403F8_B2C868
/* B2C868 802403F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B2C86C 802403FC 0000202D */  daddu     $a0, $zero, $zero
/* B2C870 80240400 0080282D */  daddu     $a1, $a0, $zero
/* B2C874 80240404 0080302D */  daddu     $a2, $a0, $zero
/* B2C878 80240408 0080382D */  daddu     $a3, $a0, $zero
/* B2C87C 8024040C AFBF0018 */  sw        $ra, 0x18($sp)
/* B2C880 80240410 AFA00010 */  sw        $zero, 0x10($sp)
/* B2C884 80240414 0C01CA54 */  jal       func_80072950
/* B2C888 80240418 AFA00014 */   sw       $zero, 0x14($sp)
/* B2C88C 8024041C 8FBF0018 */  lw        $ra, 0x18($sp)
/* B2C890 80240420 24020002 */  addiu     $v0, $zero, 2
/* B2C894 80240424 03E00008 */  jr        $ra
/* B2C898 80240428 27BD0020 */   addiu    $sp, $sp, 0x20
/* B2C89C 8024042C 00000000 */  nop       
