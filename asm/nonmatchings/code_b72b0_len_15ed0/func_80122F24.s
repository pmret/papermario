.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122F24
/* B9624 80122F24 2402F7FF */  addiu     $v0, $zero, -0x801
/* B9628 80122F28 00822024 */  and       $a0, $a0, $v0
/* B962C 80122F2C 3C028015 */  lui       $v0, 0x8015
/* B9630 80122F30 8C424370 */  lw        $v0, 0x4370($v0)
/* B9634 80122F34 00042080 */  sll       $a0, $a0, 2
/* B9638 80122F38 00822021 */  addu      $a0, $a0, $v0
/* B963C 80122F3C 8C840000 */  lw        $a0, ($a0)
/* B9640 80122F40 10800006 */  beqz      $a0, .L80122F5C
/* B9644 80122F44 00000000 */   nop      
/* B9648 80122F48 8C830000 */  lw        $v1, ($a0)
/* B964C 80122F4C 10600003 */  beqz      $v1, .L80122F5C
/* B9650 80122F50 00051027 */   nor      $v0, $zero, $a1
/* B9654 80122F54 00621024 */  and       $v0, $v1, $v0
/* B9658 80122F58 AC820000 */  sw        $v0, ($a0)
.L80122F5C:
/* B965C 80122F5C 03E00008 */  jr        $ra
/* B9660 80122F60 00000000 */   nop      
