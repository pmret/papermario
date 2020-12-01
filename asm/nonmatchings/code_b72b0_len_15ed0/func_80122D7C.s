.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80122D7C
/* B947C 80122D7C 2402F7FF */  addiu     $v0, $zero, -0x801
/* B9480 80122D80 00822024 */  and       $a0, $a0, $v0
/* B9484 80122D84 3C028015 */  lui       $v0, %hi(D_80154370)
/* B9488 80122D88 8C424370 */  lw        $v0, %lo(D_80154370)($v0)
/* B948C 80122D8C 00042080 */  sll       $a0, $a0, 2
/* B9490 80122D90 00822021 */  addu      $a0, $a0, $v0
/* B9494 80122D94 8C840000 */  lw        $a0, ($a0)
/* B9498 80122D98 1080000E */  beqz      $a0, .L80122DD4
/* B949C 80122D9C 00000000 */   nop      
/* B94A0 80122DA0 8C820000 */  lw        $v0, ($a0)
/* B94A4 80122DA4 1040000B */  beqz      $v0, .L80122DD4
/* B94A8 80122DA8 00000000 */   nop      
/* B94AC 80122DAC 14A00003 */  bnez      $a1, .L80122DBC
/* B94B0 80122DB0 00000000 */   nop      
/* B94B4 80122DB4 3C058015 */  lui       $a1, %hi(D_8014C260)
/* B94B8 80122DB8 24A5C260 */  addiu     $a1, $a1, %lo(D_8014C260)
.L80122DBC:
/* B94BC 80122DBC 3C013F80 */  lui       $at, 0x3f80
/* B94C0 80122DC0 44810000 */  mtc1      $at, $f0
/* B94C4 80122DC4 AC850010 */  sw        $a1, 0x10($a0)
/* B94C8 80122DC8 AC850058 */  sw        $a1, 0x58($a0)
/* B94CC 80122DCC E4800008 */  swc1      $f0, 8($a0)
/* B94D0 80122DD0 E480000C */  swc1      $f0, 0xc($a0)
.L80122DD4:
/* B94D4 80122DD4 03E00008 */  jr        $ra
/* B94D8 80122DD8 00000000 */   nop      
