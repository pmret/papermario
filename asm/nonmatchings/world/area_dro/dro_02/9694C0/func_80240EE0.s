.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240EE0
/* 96A0A0 80240EE0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96A0A4 80240EE4 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A0A8 80240EE8 0080882D */  daddu     $s1, $a0, $zero
/* 96A0AC 80240EEC AFBF0018 */  sw        $ra, 0x18($sp)
/* 96A0B0 80240EF0 AFB00010 */  sw        $s0, 0x10($sp)
/* 96A0B4 80240EF4 8E30000C */  lw        $s0, 0xc($s1)
/* 96A0B8 80240EF8 8E050000 */  lw        $a1, ($s0)
/* 96A0BC 80240EFC 0C0B1EAF */  jal       get_variable
/* 96A0C0 80240F00 26100004 */   addiu    $s0, $s0, 4
/* 96A0C4 80240F04 00021880 */  sll       $v1, $v0, 2
/* 96A0C8 80240F08 00621821 */  addu      $v1, $v1, $v0
/* 96A0CC 80240F0C 00031880 */  sll       $v1, $v1, 2
/* 96A0D0 80240F10 00621823 */  subu      $v1, $v1, $v0
/* 96A0D4 80240F14 000310C0 */  sll       $v0, $v1, 3
/* 96A0D8 80240F18 00621821 */  addu      $v1, $v1, $v0
/* 96A0DC 80240F1C 000318C0 */  sll       $v1, $v1, 3
/* 96A0E0 80240F20 3C01800B */  lui       $at, 0x800b
/* 96A0E4 80240F24 00230821 */  addu      $at, $at, $v1
/* 96A0E8 80240F28 C4221D98 */  lwc1      $f2, 0x1d98($at)
/* 96A0EC 80240F2C 3C014480 */  lui       $at, 0x4480
/* 96A0F0 80240F30 44810000 */  mtc1      $at, $f0
/* 96A0F4 80240F34 00000000 */  nop       
/* 96A0F8 80240F38 46001082 */  mul.s     $f2, $f2, $f0
/* 96A0FC 80240F3C 00000000 */  nop       
/* 96A100 80240F40 3C01CD5B */  lui       $at, 0xcd5b
/* 96A104 80240F44 34215858 */  ori       $at, $at, 0x5858
/* 96A108 80240F48 44810000 */  mtc1      $at, $f0
/* 96A10C 80240F4C 00000000 */  nop       
/* 96A110 80240F50 46001080 */  add.s     $f2, $f2, $f0
/* 96A114 80240F54 8E050000 */  lw        $a1, ($s0)
/* 96A118 80240F58 4600110D */  trunc.w.s $f4, $f2
/* 96A11C 80240F5C 44062000 */  mfc1      $a2, $f4
/* 96A120 80240F60 0C0B2026 */  jal       set_variable
/* 96A124 80240F64 0220202D */   daddu    $a0, $s1, $zero
/* 96A128 80240F68 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96A12C 80240F6C 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A130 80240F70 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A134 80240F74 24020002 */  addiu     $v0, $zero, 2
/* 96A138 80240F78 03E00008 */  jr        $ra
/* 96A13C 80240F7C 27BD0020 */   addiu    $sp, $sp, 0x20
