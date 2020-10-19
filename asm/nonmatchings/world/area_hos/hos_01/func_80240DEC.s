.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240DEC
/* A1166C 80240DEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A11670 80240DF0 AFBF0010 */  sw        $ra, 0x10($sp)
/* A11674 80240DF4 8C82000C */  lw        $v0, 0xc($a0)
/* A11678 80240DF8 3C068016 */  lui       $a2, 0x8016
/* A1167C 80240DFC 84C6A552 */  lh        $a2, -0x5aae($a2)
/* A11680 80240E00 0C0B2026 */  jal       set_variable
/* A11684 80240E04 8C450000 */   lw       $a1, ($v0)
/* A11688 80240E08 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1168C 80240E0C 24020002 */  addiu     $v0, $zero, 2
/* A11690 80240E10 03E00008 */  jr        $ra
/* A11694 80240E14 27BD0018 */   addiu    $sp, $sp, 0x18
/* A11698 80240E18 00000000 */  nop       
/* A1169C 80240E1C 00000000 */  nop       
