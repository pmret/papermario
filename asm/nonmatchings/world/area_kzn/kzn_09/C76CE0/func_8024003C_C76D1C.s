.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024003C_C76D1C
/* C76D1C 8024003C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C76D20 80240040 AFBF0010 */  sw        $ra, 0x10($sp)
/* C76D24 80240044 8C82000C */  lw        $v0, 0xc($a0)
/* C76D28 80240048 0C0B1EAF */  jal       get_variable
/* C76D2C 8024004C 8C450000 */   lw       $a1, ($v0)
/* C76D30 80240050 0C0B95A4 */  jal       func_802E5690
/* C76D34 80240054 0040202D */   daddu    $a0, $v0, $zero
/* C76D38 80240058 8FBF0010 */  lw        $ra, 0x10($sp)
/* C76D3C 8024005C 24020002 */  addiu     $v0, $zero, 2
/* C76D40 80240060 03E00008 */  jr        $ra
/* C76D44 80240064 27BD0018 */   addiu    $sp, $sp, 0x18
