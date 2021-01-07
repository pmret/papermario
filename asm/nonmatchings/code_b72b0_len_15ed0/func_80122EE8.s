.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122EE8
/* B95E8 80122EE8 2402F7FF */  addiu     $v0, $zero, -0x801
/* B95EC 80122EEC 00822024 */  and       $a0, $a0, $v0
/* B95F0 80122EF0 3C028015 */  lui       $v0, %hi(D_80154370)
/* B95F4 80122EF4 8C424370 */  lw        $v0, %lo(D_80154370)($v0)
/* B95F8 80122EF8 00042080 */  sll       $a0, $a0, 2
/* B95FC 80122EFC 00822021 */  addu      $a0, $a0, $v0
/* B9600 80122F00 8C840000 */  lw        $a0, ($a0)
/* B9604 80122F04 10800005 */  beqz      $a0, .L80122F1C
/* B9608 80122F08 00000000 */   nop      
/* B960C 80122F0C 8C820000 */  lw        $v0, ($a0)
/* B9610 80122F10 10400002 */  beqz      $v0, .L80122F1C
/* B9614 80122F14 00451025 */   or       $v0, $v0, $a1
/* B9618 80122F18 AC820000 */  sw        $v0, ($a0)
.L80122F1C:
/* B961C 80122F1C 03E00008 */  jr        $ra
/* B9620 80122F20 00000000 */   nop      
