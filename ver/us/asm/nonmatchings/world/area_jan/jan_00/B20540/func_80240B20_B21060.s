.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B20_B21060
/* B21060 80240B20 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B21064 80240B24 AFBF0010 */  sw        $ra, 0x10($sp)
/* B21068 80240B28 0C00EABB */  jal       get_npc_unsafe
/* B2106C 80240B2C 8C84008C */   lw       $a0, 0x8c($a0)
/* B21070 80240B30 3C038024 */  lui       $v1, %hi(D_80247CB4)
/* B21074 80240B34 8C637CB4 */  lw        $v1, %lo(D_80247CB4)($v1)
/* B21078 80240B38 AC430028 */  sw        $v1, 0x28($v0)
/* B2107C 80240B3C 8FBF0010 */  lw        $ra, 0x10($sp)
/* B21080 80240B40 24020002 */  addiu     $v0, $zero, 2
/* B21084 80240B44 03E00008 */  jr        $ra
/* B21088 80240B48 27BD0018 */   addiu    $sp, $sp, 0x18
