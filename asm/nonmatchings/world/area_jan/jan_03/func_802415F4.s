.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802415F4
/* B361C4 802415F4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B361C8 802415F8 AFBF0010 */  sw        $ra, 0x10($sp)
/* B361CC 802415FC 8C82000C */  lw        $v0, 0xc($a0)
/* B361D0 80241600 0C0B1EAF */  jal       get_variable
/* B361D4 80241604 8C450000 */   lw       $a1, ($v0)
/* B361D8 80241608 0C0B1059 */  jal       does_script_exist
/* B361DC 8024160C 0040202D */   daddu    $a0, $v0, $zero
/* B361E0 80241610 2C420001 */  sltiu     $v0, $v0, 1
/* B361E4 80241614 8FBF0010 */  lw        $ra, 0x10($sp)
/* B361E8 80241618 00021040 */  sll       $v0, $v0, 1
/* B361EC 8024161C 03E00008 */  jr        $ra
/* B361F0 80241620 27BD0018 */   addiu    $sp, $sp, 0x18
