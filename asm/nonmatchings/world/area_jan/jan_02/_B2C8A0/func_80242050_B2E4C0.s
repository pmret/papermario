.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242050_B2E4C0
/* B2E4C0 80242050 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B2E4C4 80242054 AFBF0010 */  sw        $ra, 0x10($sp)
/* B2E4C8 80242058 8C82000C */  lw        $v0, 0xc($a0)
/* B2E4CC 8024205C 0C0B1EAF */  jal       get_variable
/* B2E4D0 80242060 8C450000 */   lw       $a1, ($v0)
/* B2E4D4 80242064 3C038025 */  lui       $v1, 0x8025
/* B2E4D8 80242068 8C638940 */  lw        $v1, -0x76c0($v1)
/* B2E4DC 8024206C 8C63000C */  lw        $v1, 0xc($v1)
/* B2E4E0 80242070 AC620034 */  sw        $v0, 0x34($v1)
/* B2E4E4 80242074 8FBF0010 */  lw        $ra, 0x10($sp)
/* B2E4E8 80242078 24020002 */  addiu     $v0, $zero, 2
/* B2E4EC 8024207C 03E00008 */  jr        $ra
/* B2E4F0 80242080 27BD0018 */   addiu    $sp, $sp, 0x18
