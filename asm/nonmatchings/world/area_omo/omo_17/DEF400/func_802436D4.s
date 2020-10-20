.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802436D4
/* DF2574 802436D4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DF2578 802436D8 3C05FE36 */  lui       $a1, 0xfe36
/* DF257C 802436DC AFBF0010 */  sw        $ra, 0x10($sp)
/* DF2580 802436E0 8C820148 */  lw        $v0, 0x148($a0)
/* DF2584 802436E4 3C06800B */  lui       $a2, 0x800b
/* DF2588 802436E8 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* DF258C 802436EC 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DF2590 802436F0 00C23026 */  xor       $a2, $a2, $v0
/* DF2594 802436F4 0C0B2026 */  jal       set_variable
/* DF2598 802436F8 2CC60001 */   sltiu    $a2, $a2, 1
/* DF259C 802436FC 8FBF0010 */  lw        $ra, 0x10($sp)
/* DF25A0 80243700 24020002 */  addiu     $v0, $zero, 2
/* DF25A4 80243704 03E00008 */  jr        $ra
/* DF25A8 80243708 27BD0018 */   addiu    $sp, $sp, 0x18
/* DF25AC 8024370C 00000000 */  nop       
