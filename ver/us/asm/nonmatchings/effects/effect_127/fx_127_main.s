.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_127_main
/* 404220 E011A000 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 404224 E011A004 AFB1002C */  sw        $s1, 0x2c($sp)
/* 404228 E011A008 0080882D */  daddu     $s1, $a0, $zero
/* 40422C E011A00C 27A40010 */  addiu     $a0, $sp, 0x10
/* 404230 E011A010 AFB20030 */  sw        $s2, 0x30($sp)
/* 404234 E011A014 8FB2004C */  lw        $s2, 0x4c($sp)
/* 404238 E011A018 3C02E012 */  lui       $v0, %hi(func_E011A0FC)
/* 40423C E011A01C 2442A0FC */  addiu     $v0, $v0, %lo(func_E011A0FC)
/* 404240 E011A020 AFA20018 */  sw        $v0, 0x18($sp)
/* 404244 E011A024 3C02E012 */  lui       $v0, %hi(func_E011A104)
/* 404248 E011A028 2442A104 */  addiu     $v0, $v0, %lo(func_E011A104)
/* 40424C E011A02C AFA2001C */  sw        $v0, 0x1c($sp)
/* 404250 E011A030 3C02E012 */  lui       $v0, %hi(func_E011A398)
/* 404254 E011A034 2442A398 */  addiu     $v0, $v0, %lo(func_E011A398)
/* 404258 E011A038 AFA20020 */  sw        $v0, 0x20($sp)
/* 40425C E011A03C 3C02E012 */  lui       $v0, %hi(func_E011A3A0)
/* 404260 E011A040 2442A3A0 */  addiu     $v0, $v0, %lo(func_E011A3A0)
/* 404264 E011A044 AFA20024 */  sw        $v0, 0x24($sp)
/* 404268 E011A048 2402007F */  addiu     $v0, $zero, 0x7f
/* 40426C E011A04C AFBF0034 */  sw        $ra, 0x34($sp)
/* 404270 E011A050 AFB00028 */  sw        $s0, 0x28($sp)
/* 404274 E011A054 AFA00010 */  sw        $zero, 0x10($sp)
/* 404278 E011A058 0C080124 */  jal       func_E0200490
/* 40427C E011A05C AFA20014 */   sw       $v0, 0x14($sp)
/* 404280 E011A060 2404002C */  addiu     $a0, $zero, 0x2c
/* 404284 E011A064 24030001 */  addiu     $v1, $zero, 1
/* 404288 E011A068 0040802D */  daddu     $s0, $v0, $zero
/* 40428C E011A06C 0C08012C */  jal       func_E02004B0
/* 404290 E011A070 AE030008 */   sw       $v1, 8($s0)
/* 404294 E011A074 0040282D */  daddu     $a1, $v0, $zero
/* 404298 E011A078 14A00003 */  bnez      $a1, .LE011A088
/* 40429C E011A07C AE02000C */   sw       $v0, 0xc($s0)
.LE011A080:
/* 4042A0 E011A080 08046820 */  j         .LE011A080
/* 4042A4 E011A084 00000000 */   nop
.LE011A088:
/* 4042A8 E011A088 A4B10000 */  sh        $s1, ($a1)
/* 4042AC E011A08C 1E400004 */  bgtz      $s2, .LE011A0A0
/* 4042B0 E011A090 ACA00008 */   sw       $zero, 8($a1)
/* 4042B4 E011A094 240203E8 */  addiu     $v0, $zero, 0x3e8
/* 4042B8 E011A098 08046829 */  j         .LE011A0A4
/* 4042BC E011A09C ACA20004 */   sw       $v0, 4($a1)
.LE011A0A0:
/* 4042C0 E011A0A0 ACB20004 */  sw        $s2, 4($a1)
.LE011A0A4:
/* 4042C4 E011A0A4 0000202D */  daddu     $a0, $zero, $zero
/* 4042C8 E011A0A8 00A0182D */  daddu     $v1, $a1, $zero
.LE011A0AC:
/* 4042CC E011A0AC A460000C */  sh        $zero, 0xc($v1)
/* 4042D0 E011A0B0 A460000E */  sh        $zero, 0xe($v1)
/* 4042D4 E011A0B4 A4600010 */  sh        $zero, 0x10($v1)
/* 4042D8 E011A0B8 A4600012 */  sh        $zero, 0x12($v1)
/* 4042DC E011A0BC A4600014 */  sh        $zero, 0x14($v1)
/* 4042E0 E011A0C0 24840001 */  addiu     $a0, $a0, 1
/* 4042E4 E011A0C4 28820003 */  slti      $v0, $a0, 3
/* 4042E8 E011A0C8 1440FFF8 */  bnez      $v0, .LE011A0AC
/* 4042EC E011A0CC 2463000A */   addiu    $v1, $v1, 0xa
/* 4042F0 E011A0D0 24020001 */  addiu     $v0, $zero, 1
/* 4042F4 E011A0D4 16220002 */  bne       $s1, $v0, .LE011A0E0
/* 4042F8 E011A0D8 A4A00002 */   sh       $zero, 2($a1)
/* 4042FC E011A0DC A4B10002 */  sh        $s1, 2($a1)
.LE011A0E0:
/* 404300 E011A0E0 0200102D */  daddu     $v0, $s0, $zero
/* 404304 E011A0E4 8FBF0034 */  lw        $ra, 0x34($sp)
/* 404308 E011A0E8 8FB20030 */  lw        $s2, 0x30($sp)
/* 40430C E011A0EC 8FB1002C */  lw        $s1, 0x2c($sp)
/* 404310 E011A0F0 8FB00028 */  lw        $s0, 0x28($sp)
/* 404314 E011A0F4 03E00008 */  jr        $ra
/* 404318 E011A0F8 27BD0038 */   addiu    $sp, $sp, 0x38
