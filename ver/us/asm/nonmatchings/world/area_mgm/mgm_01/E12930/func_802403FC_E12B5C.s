.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802403FC_E12B5C
/* E12B5C 802403FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E12B60 80240400 3C02800A */  lui       $v0, %hi(D_8009A650)
/* E12B64 80240404 2442A650 */  addiu     $v0, $v0, %lo(D_8009A650)
/* E12B68 80240408 AFBF0010 */  sw        $ra, 0x10($sp)
/* E12B6C 8024040C 8C430000 */  lw        $v1, ($v0)
/* E12B70 80240410 3C040004 */  lui       $a0, 4
/* E12B74 80240414 00641825 */  or        $v1, $v1, $a0
/* E12B78 80240418 0C03A625 */  jal       func_800E9894
/* E12B7C 8024041C AC430000 */   sw       $v1, ($v0)
/* E12B80 80240420 0C03A5EE */  jal       close_status_menu
/* E12B84 80240424 00000000 */   nop
/* E12B88 80240428 8FBF0010 */  lw        $ra, 0x10($sp)
/* E12B8C 8024042C 24020002 */  addiu     $v0, $zero, 2
/* E12B90 80240430 03E00008 */  jr        $ra
/* E12B94 80240434 27BD0018 */   addiu    $sp, $sp, 0x18
