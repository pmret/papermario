.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_EC9D3C
/* EC9D3C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EC9D40 80240040 AFBF0010 */  sw        $ra, 0x10($sp)
/* EC9D44 80240044 8C82000C */  lw        $v0, 0xc($a0)
/* EC9D48 80240048 0C0B53A3 */  jal       dead_get_variable
/* EC9D4C 8024004C 8C450000 */   lw       $a1, ($v0)
/* EC9D50 80240050 0C0BCEC0 */  jal       func_802F3B00
/* EC9D54 80240054 0040202D */   daddu    $a0, $v0, $zero
/* EC9D58 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* EC9D5C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* EC9D60 80240060 03E00008 */  jr        $ra
/* EC9D64 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
