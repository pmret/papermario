.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802425D8_B371A8
/* B371A8 802425D8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B371AC 802425DC AFBF0010 */  sw        $ra, 0x10($sp)
/* B371B0 802425E0 8C82000C */  lw        $v0, 0xc($a0)
/* B371B4 802425E4 0C0B1EAF */  jal       get_variable
/* B371B8 802425E8 8C450000 */   lw       $a1, ($v0)
/* B371BC 802425EC 3C038025 */  lui       $v1, 0x8025
/* B371C0 802425F0 8C63FEF8 */  lw        $v1, -0x108($v1)
/* B371C4 802425F4 8C63000C */  lw        $v1, 0xc($v1)
/* B371C8 802425F8 AC620034 */  sw        $v0, 0x34($v1)
/* B371CC 802425FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* B371D0 80242600 24020002 */  addiu     $v0, $zero, 2
/* B371D4 80242604 03E00008 */  jr        $ra
/* B371D8 80242608 27BD0018 */   addiu    $sp, $sp, 0x18
