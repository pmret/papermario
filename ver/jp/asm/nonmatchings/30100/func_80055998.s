.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055998
/* 30D98 80055998 3C07800A */  lui       $a3, %hi(D_8009A5A0)
/* 30D9C 8005599C 8CE7A5A0 */  lw        $a3, %lo(D_8009A5A0)($a3)
/* 30DA0 800559A0 8CE3005C */  lw        $v1, 0x5c($a3)
/* 30DA4 800559A4 8C620008 */  lw        $v0, 8($v1)
/* 30DA8 800559A8 14820005 */  bne       $a0, $v0, .L800559C0
/* 30DAC 800559AC 0000402D */   daddu    $t0, $zero, $zero
/* 30DB0 800559B0 3C02800A */  lui       $v0, %hi(D_8009A644)
/* 30DB4 800559B4 8C42A644 */  lw        $v0, %lo(D_8009A644)($v0)
/* 30DB8 800559B8 08015677 */  j         .L800559DC
/* 30DBC 800559BC ACC20000 */   sw       $v0, ($a2)
.L800559C0:
/* 30DC0 800559C0 8CE30060 */  lw        $v1, 0x60($a3)
/* 30DC4 800559C4 8C620008 */  lw        $v0, 8($v1)
/* 30DC8 800559C8 54820005 */  bnel      $a0, $v0, .L800559E0
/* 30DCC 800559CC 24080001 */   addiu    $t0, $zero, 1
/* 30DD0 800559D0 3C02800A */  lui       $v0, %hi(D_8009A5DC)
/* 30DD4 800559D4 8C42A5DC */  lw        $v0, %lo(D_8009A5DC)($v0)
/* 30DD8 800559D8 ACC20000 */  sw        $v0, ($a2)
.L800559DC:
/* 30DDC 800559DC ACA30000 */  sw        $v1, ($a1)
.L800559E0:
/* 30DE0 800559E0 03E00008 */  jr        $ra
/* 30DE4 800559E4 0100102D */   daddu    $v0, $t0, $zero
