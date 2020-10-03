.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055CE8
/* 310E8 80055CE8 3C07800A */  lui       $a3, 0x800a
/* 310EC 80055CEC 8CE7A5C0 */  lw        $a3, -0x5a40($a3)
/* 310F0 80055CF0 8CE3005C */  lw        $v1, 0x5c($a3)
/* 310F4 80055CF4 8C620008 */  lw        $v0, 8($v1)
/* 310F8 80055CF8 14820005 */  bne       $a0, $v0, .L80055D10
/* 310FC 80055CFC 0000402D */   daddu    $t0, $zero, $zero
/* 31100 80055D00 3C02800A */  lui       $v0, 0x800a
/* 31104 80055D04 8C42A664 */  lw        $v0, -0x599c($v0)
/* 31108 80055D08 0801574B */  j         .L80055D2C
/* 3110C 80055D0C ACC20000 */   sw       $v0, ($a2)
.L80055D10:
/* 31110 80055D10 8CE30060 */  lw        $v1, 0x60($a3)
/* 31114 80055D14 8C620008 */  lw        $v0, 8($v1)
/* 31118 80055D18 54820005 */  bnel      $a0, $v0, .L80055D30
/* 3111C 80055D1C 24080001 */   addiu    $t0, $zero, 1
/* 31120 80055D20 3C02800A */  lui       $v0, 0x800a
/* 31124 80055D24 8C42A5FC */  lw        $v0, -0x5a04($v0)
/* 31128 80055D28 ACC20000 */  sw        $v0, ($a2)
.L80055D2C:
/* 3112C 80055D2C ACA30000 */  sw        $v1, ($a1)
.L80055D30:
/* 31130 80055D30 03E00008 */  jr        $ra
/* 31134 80055D34 0100102D */   daddu    $v0, $t0, $zero
