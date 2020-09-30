.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80120DE4
/* B74E4 80120DE4 3C038015 */  lui       $v1, 0x8015
/* B74E8 80120DE8 8C634370 */  lw        $v1, 0x4370($v1)
/* B74EC 80120DEC 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B74F0 80120DF0 AFB20018 */  sw        $s2, 0x18($sp)
/* B74F4 80120DF4 0080902D */  daddu     $s2, $a0, $zero
/* B74F8 80120DF8 AFB10014 */  sw        $s1, 0x14($sp)
/* B74FC 80120DFC 0000882D */  daddu     $s1, $zero, $zero
/* B7500 80120E00 AFBF001C */  sw        $ra, 0x1c($sp)
/* B7504 80120E04 AFB00010 */  sw        $s0, 0x10($sp)
.L80120E08:
/* B7508 80120E08 8C620000 */  lw        $v0, ($v1)
/* B750C 80120E0C 10400006 */  beqz      $v0, .L80120E28
/* B7510 80120E10 2A220100 */   slti     $v0, $s1, 0x100
/* B7514 80120E14 26310001 */  addiu     $s1, $s1, 1
/* B7518 80120E18 2A220100 */  slti      $v0, $s1, 0x100
/* B751C 80120E1C 1440FFFA */  bnez      $v0, .L80120E08
/* B7520 80120E20 24630004 */   addiu    $v1, $v1, 4
/* B7524 80120E24 2A220100 */  slti      $v0, $s1, 0x100
.L80120E28:
/* B7528 80120E28 14400003 */  bnez      $v0, .L80120E38
/* B752C 80120E2C 00000000 */   nop      
.L80120E30:
/* B7530 80120E30 0804838C */  j         .L80120E30
/* B7534 80120E34 00000000 */   nop      
.L80120E38:
/* B7538 80120E38 0C00AB39 */  jal       heap_malloc
/* B753C 80120E3C 24040068 */   addiu    $a0, $zero, 0x68
/* B7540 80120E40 00112080 */  sll       $a0, $s1, 2
/* B7544 80120E44 3C038015 */  lui       $v1, 0x8015
/* B7548 80120E48 8C634370 */  lw        $v1, 0x4370($v1)
/* B754C 80120E4C 3C058015 */  lui       $a1, 0x8015
/* B7550 80120E50 24A51318 */  addiu     $a1, $a1, 0x1318
/* B7554 80120E54 00832021 */  addu      $a0, $a0, $v1
/* B7558 80120E58 8CA30000 */  lw        $v1, ($a1)
/* B755C 80120E5C 0040802D */  daddu     $s0, $v0, $zero
/* B7560 80120E60 AC900000 */  sw        $s0, ($a0)
/* B7564 80120E64 24630001 */  addiu     $v1, $v1, 1
/* B7568 80120E68 16000003 */  bnez      $s0, .L80120E78
/* B756C 80120E6C ACA30000 */   sw       $v1, ($a1)
.L80120E70:
/* B7570 80120E70 0804839C */  j         .L80120E70
/* B7574 80120E74 00000000 */   nop      
.L80120E78:
/* B7578 80120E78 0C00AB39 */  jal       heap_malloc
/* B757C 80120E7C 24040010 */   addiu    $a0, $zero, 0x10
/* B7580 80120E80 14400003 */  bnez      $v0, .L80120E90
/* B7584 80120E84 AE020014 */   sw       $v0, 0x14($s0)
.L80120E88:
/* B7588 80120E88 080483A2 */  j         .L80120E88
/* B758C 80120E8C 00000000 */   nop      
.L80120E90:
/* B7590 80120E90 3C013F80 */  lui       $at, 0x3f80
/* B7594 80120E94 44810000 */  mtc1      $at, $f0
/* B7598 80120E98 24020417 */  addiu     $v0, $zero, 0x417
/* B759C 80120E9C AE020000 */  sw        $v0, ($s0)
/* B75A0 80120EA0 24020001 */  addiu     $v0, $zero, 1
/* B75A4 80120EA4 A2020004 */  sb        $v0, 4($s0)
/* B75A8 80120EA8 AE120010 */  sw        $s2, 0x10($s0)
/* B75AC 80120EAC E6000008 */  swc1      $f0, 8($s0)
/* B75B0 80120EB0 16400004 */  bnez      $s2, .L80120EC4
/* B75B4 80120EB4 E600000C */   swc1     $f0, 0xc($s0)
/* B75B8 80120EB8 3C028015 */  lui       $v0, 0x8015
/* B75BC 80120EBC 2442C260 */  addiu     $v0, $v0, -0x3da0
/* B75C0 80120EC0 AE020010 */  sw        $v0, 0x10($s0)
.L80120EC4:
/* B75C4 80120EC4 8E020010 */  lw        $v0, 0x10($s0)
/* B75C8 80120EC8 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* B75CC 80120ECC 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* B75D0 80120ED0 AE00005C */  sw        $zero, 0x5c($s0)
/* B75D4 80120ED4 AE000060 */  sw        $zero, 0x60($s0)
/* B75D8 80120ED8 AE020058 */  sw        $v0, 0x58($s0)
/* B75DC 80120EDC 80620070 */  lb        $v0, 0x70($v1)
/* B75E0 80120EE0 54400001 */  bnel      $v0, $zero, .L80120EE8
/* B75E4 80120EE4 36310800 */   ori      $s1, $s1, 0x800
.L80120EE8:
/* B75E8 80120EE8 0220102D */  daddu     $v0, $s1, $zero
/* B75EC 80120EEC 8FBF001C */  lw        $ra, 0x1c($sp)
/* B75F0 80120EF0 8FB20018 */  lw        $s2, 0x18($sp)
/* B75F4 80120EF4 8FB10014 */  lw        $s1, 0x14($sp)
/* B75F8 80120EF8 8FB00010 */  lw        $s0, 0x10($sp)
/* B75FC 80120EFC 03E00008 */  jr        $ra
/* B7600 80120F00 27BD0020 */   addiu    $sp, $sp, 0x20
