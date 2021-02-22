.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F70_C49B50
/* C49B50 80242F70 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C49B54 80242F74 AFB20048 */  sw        $s2, 0x48($sp)
/* C49B58 80242F78 0080902D */  daddu     $s2, $a0, $zero
/* C49B5C 80242F7C AFBF004C */  sw        $ra, 0x4c($sp)
/* C49B60 80242F80 AFB10044 */  sw        $s1, 0x44($sp)
/* C49B64 80242F84 AFB00040 */  sw        $s0, 0x40($sp)
/* C49B68 80242F88 F7B40050 */  sdc1      $f20, 0x50($sp)
/* C49B6C 80242F8C 8E500148 */  lw        $s0, 0x148($s2)
/* C49B70 80242F90 0C00EABB */  jal       get_npc_unsafe
/* C49B74 80242F94 86040008 */   lh       $a0, 8($s0)
/* C49B78 80242F98 27A50028 */  addiu     $a1, $sp, 0x28
/* C49B7C 80242F9C 0040882D */  daddu     $s1, $v0, $zero
/* C49B80 80242FA0 27A6002C */  addiu     $a2, $sp, 0x2c
/* C49B84 80242FA4 27A70030 */  addiu     $a3, $sp, 0x30
/* C49B88 80242FA8 C620003C */  lwc1      $f0, 0x3c($s1)
/* C49B8C 80242FAC 3C014004 */  lui       $at, 0x4004
/* C49B90 80242FB0 44811800 */  mtc1      $at, $f3
/* C49B94 80242FB4 44801000 */  mtc1      $zero, $f2
/* C49B98 80242FB8 C6260038 */  lwc1      $f6, 0x38($s1)
/* C49B9C 80242FBC 46000021 */  cvt.d.s   $f0, $f0
/* C49BA0 80242FC0 46220000 */  add.d     $f0, $f0, $f2
/* C49BA4 80242FC4 3C01447A */  lui       $at, 0x447a
/* C49BA8 80242FC8 44812000 */  mtc1      $at, $f4
/* C49BAC 80242FCC C6020078 */  lwc1      $f2, 0x78($s0)
/* C49BB0 80242FD0 468010A0 */  cvt.s.w   $f2, $f2
/* C49BB4 80242FD4 46200020 */  cvt.s.d   $f0, $f0
/* C49BB8 80242FD8 E620003C */  swc1      $f0, 0x3c($s1)
/* C49BBC 80242FDC 46000206 */  mov.s     $f8, $f0
/* C49BC0 80242FE0 C6200040 */  lwc1      $f0, 0x40($s1)
/* C49BC4 80242FE4 27A20034 */  addiu     $v0, $sp, 0x34
/* C49BC8 80242FE8 E7A00030 */  swc1      $f0, 0x30($sp)
/* C49BCC 80242FEC 3C014059 */  lui       $at, 0x4059
/* C49BD0 80242FF0 44810800 */  mtc1      $at, $f1
/* C49BD4 80242FF4 44800000 */  mtc1      $zero, $f0
/* C49BD8 80242FF8 460010A1 */  cvt.d.s   $f2, $f2
/* C49BDC 80242FFC E7A60028 */  swc1      $f6, 0x28($sp)
/* C49BE0 80243000 E7A40034 */  swc1      $f4, 0x34($sp)
/* C49BE4 80243004 E7A8002C */  swc1      $f8, 0x2c($sp)
/* C49BE8 80243008 AFA20010 */  sw        $v0, 0x10($sp)
/* C49BEC 8024300C 8E240080 */  lw        $a0, 0x80($s1)
/* C49BF0 80243010 46201083 */  div.d     $f2, $f2, $f0
/* C49BF4 80243014 0C0372DF */  jal       func_800DCB7C
/* C49BF8 80243018 46201520 */   cvt.s.d  $f20, $f2
/* C49BFC 8024301C C7A0002C */  lwc1      $f0, 0x2c($sp)
/* C49C00 80243020 46140000 */  add.s     $f0, $f0, $f20
/* C49C04 80243024 C622003C */  lwc1      $f2, 0x3c($s1)
/* C49C08 80243028 4600103C */  c.lt.s    $f2, $f0
/* C49C0C 8024302C 00000000 */  nop
/* C49C10 80243030 45010028 */  bc1t      .L802430D4
/* C49C14 80243034 00000000 */   nop
/* C49C18 80243038 8E0200D0 */  lw        $v0, 0xd0($s0)
/* C49C1C 8024303C C62C0038 */  lwc1      $f12, 0x38($s1)
/* C49C20 80243040 C62E0040 */  lwc1      $f14, 0x40($s1)
/* C49C24 80243044 C44A0000 */  lwc1      $f10, ($v0)
/* C49C28 80243048 468052A0 */  cvt.s.w   $f10, $f10
/* C49C2C 8024304C 44065000 */  mfc1      $a2, $f10
/* C49C30 80243050 C44A0008 */  lwc1      $f10, 8($v0)
/* C49C34 80243054 468052A0 */  cvt.s.w   $f10, $f10
/* C49C38 80243058 44075000 */  mfc1      $a3, $f10
/* C49C3C 8024305C 0C00A720 */  jal       atan2
/* C49C40 80243060 2410000A */   addiu    $s0, $zero, 0xa
/* C49C44 80243064 24040002 */  addiu     $a0, $zero, 2
/* C49C48 80243068 0220282D */  daddu     $a1, $s1, $zero
/* C49C4C 8024306C 0000302D */  daddu     $a2, $zero, $zero
/* C49C50 80243070 C7A2002C */  lwc1      $f2, 0x2c($sp)
/* C49C54 80243074 862200A8 */  lh        $v0, 0xa8($s1)
/* C49C58 80243078 E620000C */  swc1      $f0, 0xc($s1)
/* C49C5C 8024307C 3C013F80 */  lui       $at, 0x3f80
/* C49C60 80243080 44810000 */  mtc1      $at, $f0
/* C49C64 80243084 3C014000 */  lui       $at, 0x4000
/* C49C68 80243088 44812000 */  mtc1      $at, $f4
/* C49C6C 8024308C 3C01C1A0 */  lui       $at, 0xc1a0
/* C49C70 80243090 44813000 */  mtc1      $at, $f6
/* C49C74 80243094 44825000 */  mtc1      $v0, $f10
/* C49C78 80243098 00000000 */  nop
/* C49C7C 8024309C 468052A0 */  cvt.s.w   $f10, $f10
/* C49C80 802430A0 46141080 */  add.s     $f2, $f2, $f20
/* C49C84 802430A4 44075000 */  mfc1      $a3, $f10
/* C49C88 802430A8 27A20038 */  addiu     $v0, $sp, 0x38
/* C49C8C 802430AC E622003C */  swc1      $f2, 0x3c($s1)
/* C49C90 802430B0 E7A00010 */  swc1      $f0, 0x10($sp)
/* C49C94 802430B4 E7A40014 */  swc1      $f4, 0x14($sp)
/* C49C98 802430B8 E7A60018 */  swc1      $f6, 0x18($sp)
/* C49C9C 802430BC AFB0001C */  sw        $s0, 0x1c($sp)
/* C49CA0 802430C0 0C01BFA4 */  jal       fx_emote
/* C49CA4 802430C4 AFA20020 */   sw       $v0, 0x20($sp)
/* C49CA8 802430C8 24020012 */  addiu     $v0, $zero, 0x12
/* C49CAC 802430CC A630008E */  sh        $s0, 0x8e($s1)
/* C49CB0 802430D0 AE420070 */  sw        $v0, 0x70($s2)
.L802430D4:
/* C49CB4 802430D4 8FBF004C */  lw        $ra, 0x4c($sp)
/* C49CB8 802430D8 8FB20048 */  lw        $s2, 0x48($sp)
/* C49CBC 802430DC 8FB10044 */  lw        $s1, 0x44($sp)
/* C49CC0 802430E0 8FB00040 */  lw        $s0, 0x40($sp)
/* C49CC4 802430E4 D7B40050 */  ldc1      $f20, 0x50($sp)
/* C49CC8 802430E8 03E00008 */  jr        $ra
/* C49CCC 802430EC 27BD0058 */   addiu    $sp, $sp, 0x58
