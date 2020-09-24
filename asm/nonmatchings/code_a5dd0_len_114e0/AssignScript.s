.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel AssignScript
/* A86B0 80111FB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A86B4 80111FB4 24020001 */  addiu     $v0, $zero, 1
/* A86B8 80111FB8 AFBF0014 */  sw        $ra, 0x14($sp)
/* A86BC 80111FBC AFB00010 */  sw        $s0, 0x10($sp)
/* A86C0 80111FC0 14A20009 */  bne       $a1, $v0, .L80111FE8
/* A86C4 80111FC4 8C83000C */   lw       $v1, 0xc($a0)
/* A86C8 80111FC8 0C0B1EAF */  jal       get_variable
/* A86CC 80111FCC 8C650000 */   lw       $a1, ($v1)
/* A86D0 80111FD0 3C048015 */  lui       $a0, 0x8015
/* A86D4 80111FD4 8C8412EC */  lw        $a0, 0x12ec($a0)
/* A86D8 80111FD8 0C04417A */  jal       get_entity_by_index
/* A86DC 80111FDC 0040802D */   daddu    $s0, $v0, $zero
/* A86E0 80111FE0 AC500028 */  sw        $s0, 0x28($v0)
/* A86E4 80111FE4 24020002 */  addiu     $v0, $zero, 2
.L80111FE8:
/* A86E8 80111FE8 8FBF0014 */  lw        $ra, 0x14($sp)
/* A86EC 80111FEC 8FB00010 */  lw        $s0, 0x10($sp)
/* A86F0 80111FF0 03E00008 */  jr        $ra
/* A86F4 80111FF4 27BD0018 */   addiu    $sp, $sp, 0x18
