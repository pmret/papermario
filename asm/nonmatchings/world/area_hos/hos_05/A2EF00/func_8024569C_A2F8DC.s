.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024569C_A2F8DC
/* A2F8DC 8024569C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2F8E0 802456A0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A2F8E4 802456A4 8C82000C */  lw        $v0, 0xc($a0)
/* A2F8E8 802456A8 0C0B1EAF */  jal       get_variable
/* A2F8EC 802456AC 8C450000 */   lw       $a1, ($v0)
/* A2F8F0 802456B0 8FBF0010 */  lw        $ra, 0x10($sp)
/* A2F8F4 802456B4 3C01802E */  lui       $at, 0x802e
/* A2F8F8 802456B8 A4229D72 */  sh        $v0, -0x628e($at)
/* A2F8FC 802456BC 24020002 */  addiu     $v0, $zero, 2
/* A2F900 802456C0 03E00008 */  jr        $ra
/* A2F904 802456C4 27BD0018 */   addiu    $sp, $sp, 0x18
