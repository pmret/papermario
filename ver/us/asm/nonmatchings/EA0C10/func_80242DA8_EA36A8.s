.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242DA8_EA36A8
/* EA36A8 80242DA8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* EA36AC 80242DAC AFBF0010 */  sw        $ra, 0x10($sp)
/* EA36B0 80242DB0 0C00F92F */  jal       dead_get_npc_unsafe
/* EA36B4 80242DB4 8C84008C */   lw       $a0, 0x8c($a0)
/* EA36B8 80242DB8 3C038024 */  lui       $v1, %hi(D_80246894)
/* EA36BC 80242DBC 8C636894 */  lw        $v1, %lo(D_80246894)($v1)
/* EA36C0 80242DC0 AC430028 */  sw        $v1, 0x28($v0)
/* EA36C4 80242DC4 8FBF0010 */  lw        $ra, 0x10($sp)
/* EA36C8 80242DC8 24020002 */  addiu     $v0, $zero, 2
/* EA36CC 80242DCC 03E00008 */  jr        $ra
/* EA36D0 80242DD0 27BD0018 */   addiu    $sp, $sp, 0x18
/* EA36D4 80242DD4 00000000 */  nop
/* EA36D8 80242DD8 00000000 */  nop
/* EA36DC 80242DDC 00000000 */  nop
