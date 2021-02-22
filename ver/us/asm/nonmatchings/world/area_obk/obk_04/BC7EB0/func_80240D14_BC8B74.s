.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240D14_BC8B74
/* BC8B74 80240D14 27BDFC98 */  addiu     $sp, $sp, -0x368
/* BC8B78 80240D18 AFB20358 */  sw        $s2, 0x358($sp)
/* BC8B7C 80240D1C 3C128011 */  lui       $s2, %hi(gPlayerStatus)
/* BC8B80 80240D20 2652EFC8 */  addiu     $s2, $s2, %lo(gPlayerStatus)
/* BC8B84 80240D24 AFBF035C */  sw        $ra, 0x35c($sp)
/* BC8B88 80240D28 AFB10354 */  sw        $s1, 0x354($sp)
/* BC8B8C 80240D2C AFB00350 */  sw        $s0, 0x350($sp)
/* BC8B90 80240D30 F7B40360 */  sdc1      $f20, 0x360($sp)
/* BC8B94 80240D34 C64C0028 */  lwc1      $f12, 0x28($s2)
/* BC8B98 80240D38 4480A000 */  mtc1      $zero, $f20
/* BC8B9C 80240D3C C64E0030 */  lwc1      $f14, 0x30($s2)
/* BC8BA0 80240D40 4406A000 */  mfc1      $a2, $f20
/* BC8BA4 80240D44 4407A000 */  mfc1      $a3, $f20
/* BC8BA8 80240D48 0C00A7B5 */  jal       dist2D
/* BC8BAC 80240D4C 0080802D */   daddu    $s0, $a0, $zero
/* BC8BB0 80240D50 24020001 */  addiu     $v0, $zero, 1
/* BC8BB4 80240D54 46000106 */  mov.s     $f4, $f0
/* BC8BB8 80240D58 3C0142B4 */  lui       $at, 0x42b4
/* BC8BBC 80240D5C 44811000 */  mtc1      $at, $f2
/* BC8BC0 80240D60 00000000 */  nop
/* BC8BC4 80240D64 4604103C */  c.lt.s    $f2, $f4
/* BC8BC8 80240D68 00000000 */  nop
/* BC8BCC 80240D6C 45010002 */  bc1t      .L80240D78
/* BC8BD0 80240D70 0240882D */   daddu    $s1, $s2, $zero
/* BC8BD4 80240D74 0000102D */  daddu     $v0, $zero, $zero
.L80240D78:
/* BC8BD8 80240D78 3C014316 */  lui       $at, 0x4316
/* BC8BDC 80240D7C 44810000 */  mtc1      $at, $f0
/* BC8BE0 80240D80 00000000 */  nop
/* BC8BE4 80240D84 4600203C */  c.lt.s    $f4, $f0
/* BC8BE8 80240D88 00000000 */  nop
/* BC8BEC 80240D8C 45010002 */  bc1t      .L80240D98
/* BC8BF0 80240D90 24030001 */   addiu    $v1, $zero, 1
/* BC8BF4 80240D94 0000182D */  daddu     $v1, $zero, $zero
.L80240D98:
/* BC8BF8 80240D98 00431025 */  or        $v0, $v0, $v1
/* BC8BFC 80240D9C 1040001C */  beqz      $v0, .L80240E10
/* BC8C00 80240DA0 00000000 */   nop
/* BC8C04 80240DA4 C64C0028 */  lwc1      $f12, 0x28($s2)
/* BC8C08 80240DA8 C64E0030 */  lwc1      $f14, 0x30($s2)
/* BC8C0C 80240DAC 4406A000 */  mfc1      $a2, $f20
/* BC8C10 80240DB0 4407A000 */  mfc1      $a3, $f20
/* BC8C14 80240DB4 0C00A720 */  jal       atan2
/* BC8C18 80240DB8 00000000 */   nop
/* BC8C1C 80240DBC 3C014334 */  lui       $at, 0x4334
/* BC8C20 80240DC0 44811000 */  mtc1      $at, $f2
/* BC8C24 80240DC4 00000000 */  nop
/* BC8C28 80240DC8 46020000 */  add.s     $f0, $f0, $f2
/* BC8C2C 80240DCC 3C0542A0 */  lui       $a1, 0x42a0
/* BC8C30 80240DD0 44060000 */  mfc1      $a2, $f0
/* BC8C34 80240DD4 27A40010 */  addiu     $a0, $sp, 0x10
/* BC8C38 80240DD8 E7B40048 */  swc1      $f20, 0x48($sp)
/* BC8C3C 80240DDC E7B4004C */  swc1      $f20, 0x4c($sp)
/* BC8C40 80240DE0 0C00EA95 */  jal       npc_move_heading
/* BC8C44 80240DE4 E7B40050 */   swc1     $f20, 0x50($sp)
/* BC8C48 80240DE8 C7A00048 */  lwc1      $f0, 0x48($sp)
/* BC8C4C 80240DEC 4600018D */  trunc.w.s $f6, $f0
/* BC8C50 80240DF0 E6060084 */  swc1      $f6, 0x84($s0)
/* BC8C54 80240DF4 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* BC8C58 80240DF8 4600018D */  trunc.w.s $f6, $f0
/* BC8C5C 80240DFC E6060088 */  swc1      $f6, 0x88($s0)
/* BC8C60 80240E00 C7A00050 */  lwc1      $f0, 0x50($sp)
/* BC8C64 80240E04 24020001 */  addiu     $v0, $zero, 1
/* BC8C68 80240E08 0809038C */  j         .L80240E30
/* BC8C6C 80240E0C AE020090 */   sw       $v0, 0x90($s0)
.L80240E10:
/* BC8C70 80240E10 C6200028 */  lwc1      $f0, 0x28($s1)
/* BC8C74 80240E14 4600018D */  trunc.w.s $f6, $f0
/* BC8C78 80240E18 E6060084 */  swc1      $f6, 0x84($s0)
/* BC8C7C 80240E1C C620002C */  lwc1      $f0, 0x2c($s1)
/* BC8C80 80240E20 4600018D */  trunc.w.s $f6, $f0
/* BC8C84 80240E24 E6060088 */  swc1      $f6, 0x88($s0)
/* BC8C88 80240E28 C6200030 */  lwc1      $f0, 0x30($s1)
/* BC8C8C 80240E2C AE000090 */  sw        $zero, 0x90($s0)
.L80240E30:
/* BC8C90 80240E30 4600018D */  trunc.w.s $f6, $f0
/* BC8C94 80240E34 E606008C */  swc1      $f6, 0x8c($s0)
/* BC8C98 80240E38 8FBF035C */  lw        $ra, 0x35c($sp)
/* BC8C9C 80240E3C 8FB20358 */  lw        $s2, 0x358($sp)
/* BC8CA0 80240E40 8FB10354 */  lw        $s1, 0x354($sp)
/* BC8CA4 80240E44 8FB00350 */  lw        $s0, 0x350($sp)
/* BC8CA8 80240E48 D7B40360 */  ldc1      $f20, 0x360($sp)
/* BC8CAC 80240E4C 24020002 */  addiu     $v0, $zero, 2
/* BC8CB0 80240E50 03E00008 */  jr        $ra
/* BC8CB4 80240E54 27BD0368 */   addiu    $sp, $sp, 0x368
