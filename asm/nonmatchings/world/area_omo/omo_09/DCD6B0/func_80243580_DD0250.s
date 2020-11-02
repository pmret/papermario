.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243580_DD0250
/* DD0250 80243580 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* DD0254 80243584 3C05FE36 */  lui       $a1, 0xfe36
/* DD0258 80243588 AFBF0010 */  sw        $ra, 0x10($sp)
/* DD025C 8024358C 8C820148 */  lw        $v0, 0x148($a0)
/* DD0260 80243590 3C06800B */  lui       $a2, %hi(gCurrentEncounter+0x8C)
/* DD0264 80243594 8CC60F9C */  lw        $a2, %lo(gCurrentEncounter+0x8C)($a2)
/* DD0268 80243598 34A53C80 */  ori       $a1, $a1, 0x3c80
/* DD026C 8024359C 00C23026 */  xor       $a2, $a2, $v0
/* DD0270 802435A0 0C0B2026 */  jal       set_variable
/* DD0274 802435A4 2CC60001 */   sltiu    $a2, $a2, 1
/* DD0278 802435A8 8FBF0010 */  lw        $ra, 0x10($sp)
/* DD027C 802435AC 24020002 */  addiu     $v0, $zero, 2
/* DD0280 802435B0 03E00008 */  jr        $ra
/* DD0284 802435B4 27BD0018 */   addiu    $sp, $sp, 0x18
