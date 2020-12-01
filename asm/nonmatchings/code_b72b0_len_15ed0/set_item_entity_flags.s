.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_item_entity_flags
/* CA848 80134148 3C028015 */  lui       $v0, %hi(D_801565A0)
/* CA84C 8013414C 8C4265A0 */  lw        $v0, %lo(D_801565A0)($v0)
/* CA850 80134150 00042080 */  sll       $a0, $a0, 2
/* CA854 80134154 00822021 */  addu      $a0, $a0, $v0
/* CA858 80134158 8C830000 */  lw        $v1, ($a0)
/* CA85C 8013415C 8C620000 */  lw        $v0, ($v1)
/* CA860 80134160 00451025 */  or        $v0, $v0, $a1
/* CA864 80134164 AC620000 */  sw        $v0, ($v1)
/* CA868 80134168 3C030020 */  lui       $v1, 0x20
/* CA86C 8013416C 00431024 */  and       $v0, $v0, $v1
/* CA870 80134170 10400003 */  beqz      $v0, .L80134180
/* CA874 80134174 24020001 */   addiu    $v0, $zero, 1
/* CA878 80134178 3C018015 */  lui       $at, %hi(D_801565A8)
/* CA87C 8013417C A42265A8 */  sh        $v0, %lo(D_801565A8)($at)
.L80134180:
/* CA880 80134180 03E00008 */  jr        $ra
/* CA884 80134184 00000000 */   nop      
