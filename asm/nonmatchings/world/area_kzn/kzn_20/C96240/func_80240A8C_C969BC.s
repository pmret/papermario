.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A8C_C969BC
/* C969BC 80240A8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C969C0 80240A90 AFBF0010 */  sw        $ra, 0x10($sp)
/* C969C4 80240A94 8C82000C */  lw        $v0, 0xc($a0)
/* C969C8 80240A98 3C068016 */  lui       $a2, 0x8016
/* C969CC 80240A9C 84C6A552 */  lh        $a2, -0x5aae($a2)
/* C969D0 80240AA0 0C0B2026 */  jal       set_variable
/* C969D4 80240AA4 8C450000 */   lw       $a1, ($v0)
/* C969D8 80240AA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* C969DC 80240AAC 24020002 */  addiu     $v0, $zero, 2
/* C969E0 80240AB0 03E00008 */  jr        $ra
/* C969E4 80240AB4 27BD0018 */   addiu    $sp, $sp, 0x18
/* C969E8 80240AB8 00000000 */  nop       
/* C969EC 80240ABC 00000000 */  nop       
