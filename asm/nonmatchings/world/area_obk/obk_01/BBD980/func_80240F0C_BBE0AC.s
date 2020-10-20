.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240F0C_BBE0AC
/* BBE0AC 80240F0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* BBE0B0 80240F10 AFBF0010 */  sw        $ra, 0x10($sp)
/* BBE0B4 80240F14 0C00EABB */  jal       get_npc_unsafe
/* BBE0B8 80240F18 8C84008C */   lw       $a0, 0x8c($a0)
/* BBE0BC 80240F1C 3C038024 */  lui       $v1, 0x8024
/* BBE0C0 80240F20 8C635AB4 */  lw        $v1, 0x5ab4($v1)
/* BBE0C4 80240F24 AC430028 */  sw        $v1, 0x28($v0)
/* BBE0C8 80240F28 8FBF0010 */  lw        $ra, 0x10($sp)
/* BBE0CC 80240F2C 24020002 */  addiu     $v0, $zero, 2
/* BBE0D0 80240F30 03E00008 */  jr        $ra
/* BBE0D4 80240F34 27BD0018 */   addiu    $sp, $sp, 0x18
