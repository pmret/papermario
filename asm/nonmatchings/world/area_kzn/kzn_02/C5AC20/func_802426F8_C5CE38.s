.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802426F8_C5CE38
/* C5CE38 802426F8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C5CE3C 802426FC AFBF0010 */  sw        $ra, 0x10($sp)
/* C5CE40 80242700 0C00EABB */  jal       get_npc_unsafe
/* C5CE44 80242704 8C84008C */   lw       $a0, 0x8c($a0)
/* C5CE48 80242708 3C038024 */  lui       $v1, %hi(D_80246794)
/* C5CE4C 8024270C 8C636794 */  lw        $v1, %lo(D_80246794)($v1)
/* C5CE50 80242710 AC430028 */  sw        $v1, 0x28($v0)
/* C5CE54 80242714 8FBF0010 */  lw        $ra, 0x10($sp)
/* C5CE58 80242718 24020002 */  addiu     $v0, $zero, 2
/* C5CE5C 8024271C 03E00008 */  jr        $ra
/* C5CE60 80242720 27BD0018 */   addiu    $sp, $sp, 0x18
/* C5CE64 80242724 00000000 */  nop       
/* C5CE68 80242728 00000000 */  nop       
/* C5CE6C 8024272C 00000000 */  nop       
