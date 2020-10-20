.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802404F8_BA4C78
/* BA4C78 802404F8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* BA4C7C 802404FC AFB10014 */  sw        $s1, 0x14($sp)
/* BA4C80 80240500 0080882D */  daddu     $s1, $a0, $zero
/* BA4C84 80240504 AFBF0018 */  sw        $ra, 0x18($sp)
/* BA4C88 80240508 AFB00010 */  sw        $s0, 0x10($sp)
/* BA4C8C 8024050C 8E30000C */  lw        $s0, 0xc($s1)
/* BA4C90 80240510 8E050000 */  lw        $a1, ($s0)
/* BA4C94 80240514 0C0B1EAF */  jal       get_variable
/* BA4C98 80240518 26100004 */   addiu    $s0, $s0, 4
/* BA4C9C 8024051C 44826000 */  mtc1      $v0, $f12
/* BA4CA0 80240520 00000000 */  nop       
/* BA4CA4 80240524 0C00A8BB */  jal       sin_deg
/* BA4CA8 80240528 46806320 */   cvt.s.w  $f12, $f12
/* BA4CAC 8024052C 3C014120 */  lui       $at, 0x4120
/* BA4CB0 80240530 44811000 */  mtc1      $at, $f2
/* BA4CB4 80240534 00000000 */  nop       
/* BA4CB8 80240538 46020002 */  mul.s     $f0, $f0, $f2
/* BA4CBC 8024053C 00000000 */  nop       
/* BA4CC0 80240540 8E050000 */  lw        $a1, ($s0)
/* BA4CC4 80240544 4600010D */  trunc.w.s $f4, $f0
/* BA4CC8 80240548 44062000 */  mfc1      $a2, $f4
/* BA4CCC 8024054C 0C0B2026 */  jal       set_variable
/* BA4CD0 80240550 0220202D */   daddu    $a0, $s1, $zero
/* BA4CD4 80240554 8FBF0018 */  lw        $ra, 0x18($sp)
/* BA4CD8 80240558 8FB10014 */  lw        $s1, 0x14($sp)
/* BA4CDC 8024055C 8FB00010 */  lw        $s0, 0x10($sp)
/* BA4CE0 80240560 24020002 */  addiu     $v0, $zero, 2
/* BA4CE4 80240564 03E00008 */  jr        $ra
/* BA4CE8 80240568 27BD0020 */   addiu    $sp, $sp, 0x20
/* BA4CEC 8024056C 00000000 */  nop       
