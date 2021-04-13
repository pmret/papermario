.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80061CEC
/* 3D0EC 80061CEC 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 3D0F0 80061CF0 00805821 */  addu      $t3, $a0, $zero
/* 3D0F4 80061CF4 00A04821 */  addu      $t1, $a1, $zero
/* 3D0F8 80061CF8 00005021 */  addu      $t2, $zero, $zero
/* 3D0FC 80061CFC 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 3D100 80061D00 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 3D104 80061D04 3C08800B */  lui       $t0, %hi(D_800B0EB0)
/* 3D108 80061D08 25080EB0 */  addiu     $t0, $t0, %lo(D_800B0EB0)
/* 3D10C 80061D0C 18400021 */  blez      $v0, .L80061D94
/* 3D110 80061D10 00003821 */   addu     $a3, $zero, $zero
/* 3D114 80061D14 240C0001 */  addiu     $t4, $zero, 1
/* 3D118 80061D18 24A60002 */  addiu     $a2, $a1, 2
.L80061D1C:
/* 3D11C 80061D1C 89020000 */  lwl       $v0, ($t0)
/* 3D120 80061D20 99020003 */  lwr       $v0, 3($t0)
/* 3D124 80061D24 89030004 */  lwl       $v1, 4($t0)
/* 3D128 80061D28 99030007 */  lwr       $v1, 7($t0)
/* 3D12C 80061D2C ABA20000 */  swl       $v0, ($sp)
/* 3D130 80061D30 BBA20003 */  swr       $v0, 3($sp)
/* 3D134 80061D34 ABA30004 */  swl       $v1, 4($sp)
/* 3D138 80061D38 BBA30007 */  swr       $v1, 7($sp)
/* 3D13C 80061D3C 93A20002 */  lbu       $v0, 2($sp)
/* 3D140 80061D40 304200C0 */  andi      $v0, $v0, 0xc0
/* 3D144 80061D44 00021102 */  srl       $v0, $v0, 4
/* 3D148 80061D48 1440000A */  bnez      $v0, .L80061D74
/* 3D14C 80061D4C A0C20001 */   sb       $v0, 1($a2)
/* 3D150 80061D50 93A20005 */  lbu       $v0, 5($sp)
/* 3D154 80061D54 93A30004 */  lbu       $v1, 4($sp)
/* 3D158 80061D58 00021200 */  sll       $v0, $v0, 8
/* 3D15C 80061D5C 00621825 */  or        $v1, $v1, $v0
/* 3D160 80061D60 A5230000 */  sh        $v1, ($t1)
/* 3D164 80061D64 93A30006 */  lbu       $v1, 6($sp)
/* 3D168 80061D68 00EC1004 */  sllv      $v0, $t4, $a3
/* 3D16C 80061D6C 01425025 */  or        $t2, $t2, $v0
/* 3D170 80061D70 A0C30000 */  sb        $v1, ($a2)
.L80061D74:
/* 3D174 80061D74 24E70001 */  addiu     $a3, $a3, 1
/* 3D178 80061D78 25080008 */  addiu     $t0, $t0, 8
/* 3D17C 80061D7C 3C02800A */  lui       $v0, %hi(D_8009A5E6)
/* 3D180 80061D80 9042A5E6 */  lbu       $v0, %lo(D_8009A5E6)($v0)
/* 3D184 80061D84 24C60004 */  addiu     $a2, $a2, 4
/* 3D188 80061D88 00E2102A */  slt       $v0, $a3, $v0
/* 3D18C 80061D8C 1440FFE3 */  bnez      $v0, .L80061D1C
/* 3D190 80061D90 25290004 */   addiu    $t1, $t1, 4
.L80061D94:
/* 3D194 80061D94 A16A0000 */  sb        $t2, ($t3)
/* 3D198 80061D98 03E00008 */  jr        $ra
/* 3D19C 80061D9C 27BD0010 */   addiu    $sp, $sp, 0x10
