.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241B94
/* C8F744 80241B94 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* C8F748 80241B98 AFBF0010 */  sw        $ra, 0x10($sp)
/* C8F74C 80241B9C 0C00EABB */  jal       get_npc_unsafe
/* C8F750 80241BA0 8C84008C */   lw       $a0, 0x8c($a0)
/* C8F754 80241BA4 3C038025 */  lui       $v1, 0x8025
/* C8F758 80241BA8 8C63854C */  lw        $v1, -0x7ab4($v1)
/* C8F75C 80241BAC AC430028 */  sw        $v1, 0x28($v0)
/* C8F760 80241BB0 8FBF0010 */  lw        $ra, 0x10($sp)
/* C8F764 80241BB4 24020002 */  addiu     $v0, $zero, 2
/* C8F768 80241BB8 03E00008 */  jr        $ra
/* C8F76C 80241BBC 27BD0018 */   addiu    $sp, $sp, 0x18
