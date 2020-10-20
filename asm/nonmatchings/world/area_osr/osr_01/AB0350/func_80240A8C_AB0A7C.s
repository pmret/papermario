.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240A8C_AB0A7C
/* AB0A7C 80240A8C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AB0A80 80240A90 AFBF0010 */  sw        $ra, 0x10($sp)
/* AB0A84 80240A94 0C00EABB */  jal       get_npc_unsafe
/* AB0A88 80240A98 8C84008C */   lw       $a0, 0x8c($a0)
/* AB0A8C 80240A9C 3C038024 */  lui       $v1, 0x8024
/* AB0A90 80240AA0 8C632344 */  lw        $v1, 0x2344($v1)
/* AB0A94 80240AA4 AC430028 */  sw        $v1, 0x28($v0)
/* AB0A98 80240AA8 8FBF0010 */  lw        $ra, 0x10($sp)
/* AB0A9C 80240AAC 24020002 */  addiu     $v0, $zero, 2
/* AB0AA0 80240AB0 03E00008 */  jr        $ra
/* AB0AA4 80240AB4 27BD0018 */   addiu    $sp, $sp, 0x18
/* AB0AA8 80240AB8 00000000 */  nop       
/* AB0AAC 80240ABC 00000000 */  nop       
