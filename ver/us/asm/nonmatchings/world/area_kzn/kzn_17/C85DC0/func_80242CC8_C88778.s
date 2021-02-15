.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242CC8_C88778
/* C88778 80242CC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8877C 80242CCC AFBF0010 */  sw        $ra, 0x10($sp)
/* C88780 80242CD0 0C00EABB */  jal       get_npc_unsafe
/* C88784 80242CD4 8C84008C */   lw       $a0, 0x8c($a0)
/* C88788 80242CD8 3C038024 */  lui       $v1, %hi(D_802467B4)
/* C8878C 80242CDC 8C6367B4 */  lw        $v1, %lo(D_802467B4)($v1)
/* C88790 80242CE0 AC430028 */  sw        $v1, 0x28($v0)
/* C88794 80242CE4 8FBF0010 */  lw        $ra, 0x10($sp)
/* C88798 80242CE8 24020002 */  addiu     $v0, $zero, 2
/* C8879C 80242CEC 03E00008 */  jr        $ra
/* C887A0 80242CF0 27BD0018 */   addiu    $sp, $sp, 0x18
/* C887A4 80242CF4 00000000 */  nop
/* C887A8 80242CF8 00000000 */  nop
/* C887AC 80242CFC 00000000 */  nop
