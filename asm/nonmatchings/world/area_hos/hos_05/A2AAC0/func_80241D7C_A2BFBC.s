.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241D7C_A2BFBC
/* A2BFBC 80241D7C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A2BFC0 80241D80 AFB00010 */  sw        $s0, 0x10($sp)
/* A2BFC4 80241D84 00A0802D */  daddu     $s0, $a1, $zero
/* A2BFC8 80241D88 AFBF0014 */  sw        $ra, 0x14($sp)
/* A2BFCC 80241D8C 0C0B36B0 */  jal       resolve_npc
/* A2BFD0 80241D90 24050009 */   addiu    $a1, $zero, 9
/* A2BFD4 80241D94 1200000E */  beqz      $s0, .L80241DD0
/* A2BFD8 80241D98 0040282D */   daddu    $a1, $v0, $zero
/* A2BFDC 80241D9C 3C01C311 */  lui       $at, 0xc311
/* A2BFE0 80241DA0 44810000 */  mtc1      $at, $f0
/* A2BFE4 80241DA4 3C0142E4 */  lui       $at, 0x42e4
/* A2BFE8 80241DA8 44811000 */  mtc1      $at, $f2
/* A2BFEC 80241DAC E4A00038 */  swc1      $f0, 0x38($a1)
/* A2BFF0 80241DB0 3C014387 */  lui       $at, 0x4387
/* A2BFF4 80241DB4 44810000 */  mtc1      $at, $f0
/* A2BFF8 80241DB8 E4A20040 */  swc1      $f2, 0x40($a1)
/* A2BFFC 80241DBC C4A20038 */  lwc1      $f2, 0x38($a1)
/* A2C000 80241DC0 C4A40040 */  lwc1      $f4, 0x40($a1)
/* A2C004 80241DC4 E4A0000C */  swc1      $f0, 0xc($a1)
/* A2C008 80241DC8 E4A2006C */  swc1      $f2, 0x6c($a1)
/* A2C00C 80241DCC E4A40074 */  swc1      $f4, 0x74($a1)
.L80241DD0:
/* A2C010 80241DD0 3C048025 */  lui       $a0, 0x8025
/* A2C014 80241DD4 24849984 */  addiu     $a0, $a0, -0x667c
/* A2C018 80241DD8 8C830000 */  lw        $v1, ($a0)
/* A2C01C 80241DDC 2402001E */  addiu     $v0, $zero, 0x1e
/* A2C020 80241DE0 14620005 */  bne       $v1, $v0, .L80241DF8
/* A2C024 80241DE4 00000000 */   nop      
/* A2C028 80241DE8 3C0142B4 */  lui       $at, 0x42b4
/* A2C02C 80241DEC 44810000 */  mtc1      $at, $f0
/* A2C030 80241DF0 00000000 */  nop       
/* A2C034 80241DF4 E4A0000C */  swc1      $f0, 0xc($a1)
.L80241DF8:
/* A2C038 80241DF8 8C860000 */  lw        $a2, ($a0)
/* A2C03C 80241DFC 28C20028 */  slti      $v0, $a2, 0x28
/* A2C040 80241E00 10400037 */  beqz      $v0, .L80241EE0
/* A2C044 80241E04 00061880 */   sll      $v1, $a2, 2
/* A2C048 80241E08 3C028025 */  lui       $v0, 0x8025
/* A2C04C 80241E0C 244299A8 */  addiu     $v0, $v0, -0x6658
/* A2C050 80241E10 00621821 */  addu      $v1, $v1, $v0
/* A2C054 80241E14 84620000 */  lh        $v0, ($v1)
/* A2C058 80241E18 3C0491A2 */  lui       $a0, 0x91a2
/* A2C05C 80241E1C 2442FF6F */  addiu     $v0, $v0, -0x91
/* A2C060 80241E20 44820000 */  mtc1      $v0, $f0
/* A2C064 80241E24 00000000 */  nop       
/* A2C068 80241E28 46800020 */  cvt.s.w   $f0, $f0
/* A2C06C 80241E2C E4A00038 */  swc1      $f0, 0x38($a1)
/* A2C070 80241E30 84620002 */  lh        $v0, 2($v1)
/* A2C074 80241E34 3484B3C5 */  ori       $a0, $a0, 0xb3c5
/* A2C078 80241E38 2442FF79 */  addiu     $v0, $v0, -0x87
/* A2C07C 80241E3C 00021840 */  sll       $v1, $v0, 1
/* A2C080 80241E40 00621821 */  addu      $v1, $v1, $v0
/* A2C084 80241E44 000318C0 */  sll       $v1, $v1, 3
/* A2C088 80241E48 00621821 */  addu      $v1, $v1, $v0
/* A2C08C 80241E4C 000318C0 */  sll       $v1, $v1, 3
/* A2C090 80241E50 00640018 */  mult      $v1, $a0
/* A2C094 80241E54 00003810 */  mfhi      $a3
/* A2C098 80241E58 00E31021 */  addu      $v0, $a3, $v1
/* A2C09C 80241E5C 000211C3 */  sra       $v0, $v0, 7
/* A2C0A0 80241E60 00031FC3 */  sra       $v1, $v1, 0x1f
/* A2C0A4 80241E64 00431023 */  subu      $v0, $v0, $v1
/* A2C0A8 80241E68 24420093 */  addiu     $v0, $v0, 0x93
/* A2C0AC 80241E6C 44820000 */  mtc1      $v0, $f0
/* A2C0B0 80241E70 00000000 */  nop       
/* A2C0B4 80241E74 46800020 */  cvt.s.w   $f0, $f0
/* A2C0B8 80241E78 28C20014 */  slti      $v0, $a2, 0x14
/* A2C0BC 80241E7C 1040000F */  beqz      $v0, .L80241EBC
/* A2C0C0 80241E80 E4A0003C */   swc1     $f0, 0x3c($a1)
/* A2C0C4 80241E84 3C0141F0 */  lui       $at, 0x41f0
/* A2C0C8 80241E88 44810000 */  mtc1      $at, $f0
/* A2C0CC 80241E8C 44861000 */  mtc1      $a2, $f2
/* A2C0D0 80241E90 00000000 */  nop       
/* A2C0D4 80241E94 468010A0 */  cvt.s.w   $f2, $f2
/* A2C0D8 80241E98 46001082 */  mul.s     $f2, $f2, $f0
/* A2C0DC 80241E9C 00000000 */  nop       
/* A2C0E0 80241EA0 3C0141A0 */  lui       $at, 0x41a0
/* A2C0E4 80241EA4 44812000 */  mtc1      $at, $f4
/* A2C0E8 80241EA8 3C0142E4 */  lui       $at, 0x42e4
/* A2C0EC 80241EAC 44810000 */  mtc1      $at, $f0
/* A2C0F0 80241EB0 46041083 */  div.s     $f2, $f2, $f4
/* A2C0F4 80241EB4 080907B2 */  j         .L80241EC8
/* A2C0F8 80241EB8 46020001 */   sub.s    $f0, $f0, $f2
.L80241EBC:
/* A2C0FC 80241EBC 3C0142A8 */  lui       $at, 0x42a8
/* A2C100 80241EC0 44810000 */  mtc1      $at, $f0
/* A2C104 80241EC4 00000000 */  nop       
.L80241EC8:
/* A2C108 80241EC8 E4A00040 */  swc1      $f0, 0x40($a1)
/* A2C10C 80241ECC C4A00038 */  lwc1      $f0, 0x38($a1)
/* A2C110 80241ED0 C4A20040 */  lwc1      $f2, 0x40($a1)
/* A2C114 80241ED4 E4A0006C */  swc1      $f0, 0x6c($a1)
/* A2C118 80241ED8 080907C8 */  j         .L80241F20
/* A2C11C 80241EDC E4A20074 */   swc1     $f2, 0x74($a1)
.L80241EE0:
/* A2C120 80241EE0 24C2FFD8 */  addiu     $v0, $a2, -0x28
/* A2C124 80241EE4 3042001E */  andi      $v0, $v0, 0x1e
/* A2C128 80241EE8 3C018025 */  lui       $at, 0x8025
/* A2C12C 80241EEC 00220821 */  addu      $at, $at, $v0
/* A2C130 80241EF0 84229988 */  lh        $v0, -0x6678($at)
/* A2C134 80241EF4 3C013DCC */  lui       $at, 0x3dcc
/* A2C138 80241EF8 3421CCCD */  ori       $at, $at, 0xcccd
/* A2C13C 80241EFC 44810000 */  mtc1      $at, $f0
/* A2C140 80241F00 44821000 */  mtc1      $v0, $f2
/* A2C144 80241F04 00000000 */  nop       
/* A2C148 80241F08 468010A0 */  cvt.s.w   $f2, $f2
/* A2C14C 80241F0C 46001082 */  mul.s     $f2, $f2, $f0
/* A2C150 80241F10 00000000 */  nop       
/* A2C154 80241F14 C4A0003C */  lwc1      $f0, 0x3c($a1)
/* A2C158 80241F18 46020000 */  add.s     $f0, $f0, $f2
/* A2C15C 80241F1C E4A0003C */  swc1      $f0, 0x3c($a1)
.L80241F20:
/* A2C160 80241F20 3C048025 */  lui       $a0, 0x8025
/* A2C164 80241F24 24849984 */  addiu     $a0, $a0, -0x667c
/* A2C168 80241F28 8C830000 */  lw        $v1, ($a0)
/* A2C16C 80241F2C C4A0003C */  lwc1      $f0, 0x3c($a1)
/* A2C170 80241F30 24630001 */  addiu     $v1, $v1, 1
/* A2C174 80241F34 286207D0 */  slti      $v0, $v1, 0x7d0
/* A2C178 80241F38 E4A00070 */  swc1      $f0, 0x70($a1)
/* A2C17C 80241F3C AC830000 */  sw        $v1, ($a0)
/* A2C180 80241F40 8FBF0014 */  lw        $ra, 0x14($sp)
/* A2C184 80241F44 8FB00010 */  lw        $s0, 0x10($sp)
/* A2C188 80241F48 38420001 */  xori      $v0, $v0, 1
/* A2C18C 80241F4C 03E00008 */  jr        $ra
/* A2C190 80241F50 27BD0018 */   addiu    $sp, $sp, 0x18
