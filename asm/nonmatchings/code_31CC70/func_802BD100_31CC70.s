.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BD100_31CC70
/* 31CC70 802BD100 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 31CC74 802BD104 AFBF0024 */  sw        $ra, 0x24($sp)
/* 31CC78 802BD108 AFB00020 */  sw        $s0, 0x20($sp)
/* 31CC7C 802BD10C 8C820000 */  lw        $v0, ($a0)
/* 31CC80 802BD110 30420002 */  andi      $v0, $v0, 2
/* 31CC84 802BD114 14400016 */  bnez      $v0, .L802BD170
/* 31CC88 802BD118 00000000 */   nop      
/* 31CC8C 802BD11C 3C10802C */  lui       $s0, 0x802c
/* 31CC90 802BD120 2610E310 */  addiu     $s0, $s0, -0x1cf0
/* 31CC94 802BD124 8E020000 */  lw        $v0, ($s0)
/* 31CC98 802BD128 14400011 */  bnez      $v0, .L802BD170
/* 31CC9C 802BD12C 24020005 */   addiu    $v0, $zero, 5
/* 31CCA0 802BD130 C484003C */  lwc1      $f4, 0x3c($a0)
/* 31CCA4 802BD134 3C014150 */  lui       $at, 0x4150
/* 31CCA8 802BD138 44811000 */  mtc1      $at, $f2
/* 31CCAC 802BD13C 3C013F66 */  lui       $at, 0x3f66
/* 31CCB0 802BD140 34216666 */  ori       $at, $at, 0x6666
/* 31CCB4 802BD144 44810000 */  mtc1      $at, $f0
/* 31CCB8 802BD148 AFA20014 */  sw        $v0, 0x14($sp)
/* 31CCBC 802BD14C AFA00018 */  sw        $zero, 0x18($sp)
/* 31CCC0 802BD150 46022100 */  add.s     $f4, $f4, $f2
/* 31CCC4 802BD154 E7A00010 */  swc1      $f0, 0x10($sp)
/* 31CCC8 802BD158 8C850038 */  lw        $a1, 0x38($a0)
/* 31CCCC 802BD15C 8C870040 */  lw        $a3, 0x40($a0)
/* 31CCD0 802BD160 44062000 */  mfc1      $a2, $f4
/* 31CCD4 802BD164 0C01C8EC */  jal       func_800723B0
/* 31CCD8 802BD168 0000202D */   daddu    $a0, $zero, $zero
/* 31CCDC 802BD16C AE020000 */  sw        $v0, ($s0)
.L802BD170:
/* 31CCE0 802BD170 8FBF0024 */  lw        $ra, 0x24($sp)
/* 31CCE4 802BD174 8FB00020 */  lw        $s0, 0x20($sp)
/* 31CCE8 802BD178 03E00008 */  jr        $ra
/* 31CCEC 802BD17C 27BD0028 */   addiu    $sp, $sp, 0x28
