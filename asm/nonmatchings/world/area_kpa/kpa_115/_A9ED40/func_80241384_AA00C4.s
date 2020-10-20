.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241384_AA00C4
/* AA00C4 80241384 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* AA00C8 80241388 3C05FE36 */  lui       $a1, 0xfe36
/* AA00CC 8024138C AFBF0010 */  sw        $ra, 0x10($sp)
/* AA00D0 80241390 8C820148 */  lw        $v0, 0x148($a0)
/* AA00D4 80241394 3C06800B */  lui       $a2, 0x800b
/* AA00D8 80241398 8CC60F9C */  lw        $a2, 0xf9c($a2)
/* AA00DC 8024139C 34A53C80 */  ori       $a1, $a1, 0x3c80
/* AA00E0 802413A0 00C23026 */  xor       $a2, $a2, $v0
/* AA00E4 802413A4 0C0B2026 */  jal       set_variable
/* AA00E8 802413A8 2CC60001 */   sltiu    $a2, $a2, 1
/* AA00EC 802413AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* AA00F0 802413B0 24020002 */  addiu     $v0, $zero, 2
/* AA00F4 802413B4 03E00008 */  jr        $ra
/* AA00F8 802413B8 27BD0018 */   addiu    $sp, $sp, 0x18
/* AA00FC 802413BC 00000000 */  nop       
