.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_CAED7C
/* CAED7C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CAED80 80240040 AFBF0010 */  sw        $ra, 0x10($sp)
/* CAED84 80240044 8C82000C */  lw        $v0, 0xc($a0)
/* CAED88 80240048 0C0B1EAF */  jal       get_variable
/* CAED8C 8024004C 8C450000 */   lw       $a1, ($v0)
/* CAED90 80240050 0C0B95A4 */  jal       func_802E5690
/* CAED94 80240054 0040202D */   daddu    $a0, $v0, $zero
/* CAED98 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* CAED9C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* CAEDA0 80240060 03E00008 */  jr        $ra
/* CAEDA4 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
