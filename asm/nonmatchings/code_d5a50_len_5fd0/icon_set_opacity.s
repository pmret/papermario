.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel icon_set_opacity
/* DB5B0 80144EB0 2402F7FF */  addiu     $v0, $zero, -0x801
/* DB5B4 80144EB4 00822024 */  and       $a0, $a0, $v0
/* DB5B8 80144EB8 3C028015 */  lui       $v0, 0x8015
/* DB5BC 80144EBC 8C427960 */  lw        $v0, 0x7960($v0)
/* DB5C0 80144EC0 00042080 */  sll       $a0, $a0, 2
/* DB5C4 80144EC4 00822021 */  addu      $a0, $a0, $v0
/* DB5C8 80144EC8 8C840000 */  lw        $a0, ($a0)
/* DB5CC 80144ECC 8C820000 */  lw        $v0, ($a0)
/* DB5D0 80144ED0 A085004A */  sb        $a1, 0x4a($a0)
/* DB5D4 80144ED4 34420020 */  ori       $v0, $v0, 0x20
/* DB5D8 80144ED8 AC820000 */  sw        $v0, ($a0)
/* DB5DC 80144EDC 240200FF */  addiu     $v0, $zero, 0xff
/* DB5E0 80144EE0 14A20004 */  bne       $a1, $v0, .L80144EF4
/* DB5E4 80144EE4 2403FFDF */   addiu    $v1, $zero, -0x21
/* DB5E8 80144EE8 8C820000 */  lw        $v0, ($a0)
/* DB5EC 80144EEC 00431024 */  and       $v0, $v0, $v1
/* DB5F0 80144EF0 AC820000 */  sw        $v0, ($a0)
.L80144EF4:
/* DB5F4 80144EF4 03E00008 */  jr        $ra
/* DB5F8 80144EF8 00000000 */   nop      
