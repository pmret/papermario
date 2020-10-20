.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802413CC_A6545C
/* A6545C 802413CC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A65460 802413D0 3C05FE36 */  lui       $a1, 0xfe36
/* A65464 802413D4 AFBF0010 */  sw        $ra, 0x10($sp)
/* A65468 802413D8 8C820148 */  lw        $v0, 0x148($a0)
/* A6546C 802413DC 3C06800B */  lui       $a2, 0x800b
/* A65470 802413E0 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* A65474 802413E4 34A53C80 */  ori       $a1, $a1, 0x3c80
/* A65478 802413E8 00C23026 */  xor       $a2, $a2, $v0
/* A6547C 802413EC 0C0B2026 */  jal       set_variable
/* A65480 802413F0 2CC60001 */   sltiu    $a2, $a2, 1
/* A65484 802413F4 8FBF0010 */  lw        $ra, 0x10($sp)
/* A65488 802413F8 24020002 */  addiu     $v0, $zero, 2
/* A6548C 802413FC 03E00008 */  jr        $ra
/* A65490 80241400 27BD0018 */   addiu    $sp, $sp, 0x18
