.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024011C_CD1F4C
/* CD1F4C 8024011C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CD1F50 80240120 AFBF0010 */  sw        $ra, 0x10($sp)
/* CD1F54 80240124 8C82000C */  lw        $v0, 0xc($a0)
/* CD1F58 80240128 0C0B1EAF */  jal       get_variable
/* CD1F5C 8024012C 8C450000 */   lw       $a1, ($v0)
/* CD1F60 80240130 0C0B95A4 */  jal       func_802E5690
/* CD1F64 80240134 0040202D */   daddu    $a0, $v0, $zero
/* CD1F68 80240138 8FBF0010 */  lw        $ra, 0x10($sp)
/* CD1F6C 8024013C 24020002 */  addiu     $v0, $zero, 2
/* CD1F70 80240140 03E00008 */  jr        $ra
/* CD1F74 80240144 27BD0018 */   addiu    $sp, $sp, 0x18
