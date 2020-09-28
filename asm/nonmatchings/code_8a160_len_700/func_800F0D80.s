.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800F0D80
/* 8A230 800F0D80 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 8A234 800F0D84 F7B60040 */  sdc1      $f22, 0x40($sp)
/* 8A238 800F0D88 3C018011 */  lui       $at, 0x8011
/* 8A23C 800F0D8C D436C310 */  ldc1      $f22, -0x3cf0($at)
/* 8A240 800F0D90 F7B40038 */  sdc1      $f20, 0x38($sp)
/* 8A244 800F0D94 3C018011 */  lui       $at, 0x8011
/* 8A248 800F0D98 D434C318 */  ldc1      $f20, -0x3ce8($at)
/* 8A24C 800F0D9C AFB40020 */  sw        $s4, 0x20($sp)
/* 8A250 800F0DA0 0000A02D */  daddu     $s4, $zero, $zero
/* 8A254 800F0DA4 AFBE0030 */  sw        $fp, 0x30($sp)
/* 8A258 800F0DA8 3C1E8011 */  lui       $fp, 0x8011
/* 8A25C 800F0DAC 27DE9820 */  addiu     $fp, $fp, -0x67e0
/* 8A260 800F0DB0 AFB60028 */  sw        $s6, 0x28($sp)
/* 8A264 800F0DB4 2416007F */  addiu     $s6, $zero, 0x7f
/* 8A268 800F0DB8 AFB7002C */  sw        $s7, 0x2c($sp)
/* 8A26C 800F0DBC 3C178011 */  lui       $s7, 0x8011
/* 8A270 800F0DC0 26F79800 */  addiu     $s7, $s7, -0x6800
/* 8A274 800F0DC4 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8A278 800F0DC8 0280982D */  daddu     $s3, $s4, $zero
/* 8A27C 800F0DCC AFBF0034 */  sw        $ra, 0x34($sp)
/* 8A280 800F0DD0 AFB50024 */  sw        $s5, 0x24($sp)
/* 8A284 800F0DD4 AFB20018 */  sw        $s2, 0x18($sp)
/* 8A288 800F0DD8 AFB10014 */  sw        $s1, 0x14($sp)
/* 8A28C 800F0DDC AFB00010 */  sw        $s0, 0x10($sp)
/* 8A290 800F0DE0 F7BA0050 */  sdc1      $f26, 0x50($sp)
/* 8A294 800F0DE4 F7B80048 */  sdc1      $f24, 0x48($sp)
.L800F0DE8:
/* 8A298 800F0DE8 3C058011 */  lui       $a1, %hi(D_8010D000)
/* 8A29C 800F0DEC 24A5D000 */  addiu     $a1, $a1, %lo(D_8010D000)
/* 8A2A0 800F0DF0 02651821 */  addu      $v1, $s3, $a1
/* 8A2A4 800F0DF4 90620000 */  lbu       $v0, ($v1)
/* 8A2A8 800F0DF8 5040007A */  beql      $v0, $zero, .L800F0FE4
/* 8A2AC 800F0DFC 26940001 */   addiu    $s4, $s4, 1
/* 8A2B0 800F0E00 90620001 */  lbu       $v0, 1($v1)
/* 8A2B4 800F0E04 2442FFFF */  addiu     $v0, $v0, -1
/* 8A2B8 800F0E08 A0620001 */  sb        $v0, 1($v1)
/* 8A2BC 800F0E0C 90620002 */  lbu       $v0, 2($v1)
/* 8A2C0 800F0E10 80640001 */  lb        $a0, 1($v1)
/* 8A2C4 800F0E14 24420001 */  addiu     $v0, $v0, 1
/* 8A2C8 800F0E18 04810003 */  bgez      $a0, .L800F0E28
/* 8A2CC 800F0E1C A0620002 */   sb       $v0, 2($v1)
/* 8A2D0 800F0E20 0803C3F8 */  j         .L800F0FE0
/* 8A2D4 800F0E24 A0600000 */   sb       $zero, ($v1)
.L800F0E28:
/* 8A2D8 800F0E28 0080A82D */  daddu     $s5, $a0, $zero
/* 8A2DC 800F0E2C 24120001 */  addiu     $s2, $zero, 1
/* 8A2E0 800F0E30 24700034 */  addiu     $s0, $v1, 0x34
/* 8A2E4 800F0E34 0000882D */  daddu     $s1, $zero, $zero
/* 8A2E8 800F0E38 C47A0008 */  lwc1      $f26, 8($v1)
/* 8A2EC 800F0E3C C478000C */  lwc1      $f24, 0xc($v1)
.L800F0E40:
/* 8A2F0 800F0E40 9202FFEF */  lbu       $v0, -0x11($s0)
/* 8A2F4 800F0E44 24420001 */  addiu     $v0, $v0, 1
/* 8A2F8 800F0E48 A202FFEF */  sb        $v0, -0x11($s0)
/* 8A2FC 800F0E4C 00021600 */  sll       $v0, $v0, 0x18
/* 8A300 800F0E50 00021603 */  sra       $v0, $v0, 0x18
/* 8A304 800F0E54 2842001E */  slti      $v0, $v0, 0x1e
/* 8A308 800F0E58 14400006 */  bnez      $v0, .L800F0E74
/* 8A30C 800F0E5C 2AA2001E */   slti     $v0, $s5, 0x1e
/* 8A310 800F0E60 10400003 */  beqz      $v0, .L800F0E70
/* 8A314 800F0E64 2402FFE1 */   addiu    $v0, $zero, -0x1f
/* 8A318 800F0E68 0803C39D */  j         .L800F0E74
/* 8A31C 800F0E6C A202FFEF */   sb       $v0, -0x11($s0)
.L800F0E70:
/* 8A320 800F0E70 A200FFEF */  sb        $zero, -0x11($s0)
.L800F0E74:
/* 8A324 800F0E74 8202FFEF */  lb        $v0, -0x11($s0)
/* 8A328 800F0E78 04420055 */  bltzl     $v0, .L800F0FD0
/* 8A32C 800F0E7C 26310002 */   addiu    $s1, $s1, 2
/* 8A330 800F0E80 14400031 */  bnez      $v0, .L800F0F48
/* 8A334 800F0E84 023E1821 */   addu     $v1, $s1, $fp
/* 8A338 800F0E88 80620000 */  lb        $v0, ($v1)
/* 8A33C 800F0E8C 44821000 */  mtc1      $v0, $f2
/* 8A340 800F0E90 00000000 */  nop       
/* 8A344 800F0E94 468010A0 */  cvt.s.w   $f2, $f2
/* 8A348 800F0E98 460010A1 */  cvt.d.s   $f2, $f2
/* 8A34C 800F0E9C 46361082 */  mul.d     $f2, $f2, $f22
/* 8A350 800F0EA0 00000000 */  nop       
/* 8A354 800F0EA4 80620001 */  lb        $v0, 1($v1)
/* 8A358 800F0EA8 44820000 */  mtc1      $v0, $f0
/* 8A35C 800F0EAC 00000000 */  nop       
/* 8A360 800F0EB0 46800020 */  cvt.s.w   $f0, $f0
/* 8A364 800F0EB4 46000007 */  neg.s     $f0, $f0
/* 8A368 800F0EB8 46000021 */  cvt.d.s   $f0, $f0
/* 8A36C 800F0EBC 46360002 */  mul.d     $f0, $f0, $f22
/* 8A370 800F0EC0 00000000 */  nop       
/* 8A374 800F0EC4 3C013F80 */  lui       $at, 0x3f80
/* 8A378 800F0EC8 44812000 */  mtc1      $at, $f4
/* 8A37C 800F0ECC 2404007F */  addiu     $a0, $zero, 0x7f
/* 8A380 800F0ED0 E61AFFF0 */  swc1      $f26, -0x10($s0)
/* 8A384 800F0ED4 E618FFF4 */  swc1      $f24, -0xc($s0)
/* 8A388 800F0ED8 E6040000 */  swc1      $f4, ($s0)
/* 8A38C 800F0EDC 462010A0 */  cvt.s.d   $f2, $f2
/* 8A390 800F0EE0 E602FFF8 */  swc1      $f2, -8($s0)
/* 8A394 800F0EE4 46200020 */  cvt.s.d   $f0, $f0
/* 8A398 800F0EE8 0C00A67F */  jal       rand_int
/* 8A39C 800F0EEC E600FFFC */   swc1     $f0, -4($s0)
/* 8A3A0 800F0EF0 A202FFEB */  sb        $v0, -0x15($s0)
/* 8A3A4 800F0EF4 304400FF */  andi      $a0, $v0, 0xff
/* 8A3A8 800F0EF8 0C00A67F */  jal       rand_int
/* 8A3AC 800F0EFC 02C42023 */   subu     $a0, $s6, $a0
/* 8A3B0 800F0F00 A202FFEC */  sb        $v0, -0x14($s0)
/* 8A3B4 800F0F04 304400FF */  andi      $a0, $v0, 0xff
/* 8A3B8 800F0F08 9202FFEB */  lbu       $v0, -0x15($s0)
/* 8A3BC 800F0F0C 02C42023 */  subu      $a0, $s6, $a0
/* 8A3C0 800F0F10 0C00A67F */  jal       rand_int
/* 8A3C4 800F0F14 00822023 */   subu     $a0, $a0, $v0
/* 8A3C8 800F0F18 9203FFEB */  lbu       $v1, -0x15($s0)
/* 8A3CC 800F0F1C A202FFED */  sb        $v0, -0x13($s0)
/* 8A3D0 800F0F20 240200FF */  addiu     $v0, $zero, 0xff
/* 8A3D4 800F0F24 A202FFEE */  sb        $v0, -0x12($s0)
/* 8A3D8 800F0F28 9202FFEC */  lbu       $v0, -0x14($s0)
/* 8A3DC 800F0F2C 24630080 */  addiu     $v1, $v1, 0x80
/* 8A3E0 800F0F30 A203FFEB */  sb        $v1, -0x15($s0)
/* 8A3E4 800F0F34 9203FFED */  lbu       $v1, -0x13($s0)
/* 8A3E8 800F0F38 24420080 */  addiu     $v0, $v0, 0x80
/* 8A3EC 800F0F3C A202FFEC */  sb        $v0, -0x14($s0)
/* 8A3F0 800F0F40 24630080 */  addiu     $v1, $v1, 0x80
/* 8A3F4 800F0F44 A203FFED */  sb        $v1, -0x13($s0)
.L800F0F48:
/* 8A3F8 800F0F48 C600FFF8 */  lwc1      $f0, -8($s0)
/* 8A3FC 800F0F4C 46000021 */  cvt.d.s   $f0, $f0
/* 8A400 800F0F50 46340002 */  mul.d     $f0, $f0, $f20
/* 8A404 800F0F54 00000000 */  nop       
/* 8A408 800F0F58 C602FFFC */  lwc1      $f2, -4($s0)
/* 8A40C 800F0F5C 460010A1 */  cvt.d.s   $f2, $f2
/* 8A410 800F0F60 46341082 */  mul.d     $f2, $f2, $f20
/* 8A414 800F0F64 00000000 */  nop       
/* 8A418 800F0F68 C608FFF0 */  lwc1      $f8, -0x10($s0)
/* 8A41C 800F0F6C C604FFF8 */  lwc1      $f4, -8($s0)
/* 8A420 800F0F70 C606FFF4 */  lwc1      $f6, -0xc($s0)
/* 8A424 800F0F74 46044200 */  add.s     $f8, $f8, $f4
/* 8A428 800F0F78 C604FFFC */  lwc1      $f4, -4($s0)
/* 8A42C 800F0F7C 8202FFEF */  lb        $v0, -0x11($s0)
/* 8A430 800F0F80 46043180 */  add.s     $f6, $f6, $f4
/* 8A434 800F0F84 00571021 */  addu      $v0, $v0, $s7
/* 8A438 800F0F88 E608FFF0 */  swc1      $f8, -0x10($s0)
/* 8A43C 800F0F8C E606FFF4 */  swc1      $f6, -0xc($s0)
/* 8A440 800F0F90 46200020 */  cvt.s.d   $f0, $f0
/* 8A444 800F0F94 462010A0 */  cvt.s.d   $f2, $f2
/* 8A448 800F0F98 E600FFF8 */  swc1      $f0, -8($s0)
/* 8A44C 800F0F9C E602FFFC */  swc1      $f2, -4($s0)
/* 8A450 800F0FA0 90420000 */  lbu       $v0, ($v0)
/* 8A454 800F0FA4 3C018011 */  lui       $at, 0x8011
/* 8A458 800F0FA8 D422C320 */  ldc1      $f2, -0x3ce0($at)
/* 8A45C 800F0FAC 44820000 */  mtc1      $v0, $f0
/* 8A460 800F0FB0 00000000 */  nop       
/* 8A464 800F0FB4 46800020 */  cvt.s.w   $f0, $f0
/* 8A468 800F0FB8 46000021 */  cvt.d.s   $f0, $f0
/* 8A46C 800F0FBC 46220002 */  mul.d     $f0, $f0, $f2
/* 8A470 800F0FC0 00000000 */  nop       
/* 8A474 800F0FC4 46200020 */  cvt.s.d   $f0, $f0
/* 8A478 800F0FC8 E6000000 */  swc1      $f0, ($s0)
/* 8A47C 800F0FCC 26310002 */  addiu     $s1, $s1, 2
.L800F0FD0:
/* 8A480 800F0FD0 26520001 */  addiu     $s2, $s2, 1
/* 8A484 800F0FD4 2A420039 */  slti      $v0, $s2, 0x39
/* 8A488 800F0FD8 1440FF99 */  bnez      $v0, .L800F0E40
/* 8A48C 800F0FDC 2610001C */   addiu    $s0, $s0, 0x1c
.L800F0FE0:
/* 8A490 800F0FE0 26940001 */  addiu     $s4, $s4, 1
.L800F0FE4:
/* 8A494 800F0FE4 1A80FF80 */  blez      $s4, .L800F0DE8
/* 8A498 800F0FE8 2673063C */   addiu    $s3, $s3, 0x63c
/* 8A49C 800F0FEC 8FBF0034 */  lw        $ra, 0x34($sp)
/* 8A4A0 800F0FF0 8FBE0030 */  lw        $fp, 0x30($sp)
/* 8A4A4 800F0FF4 8FB7002C */  lw        $s7, 0x2c($sp)
/* 8A4A8 800F0FF8 8FB60028 */  lw        $s6, 0x28($sp)
/* 8A4AC 800F0FFC 8FB50024 */  lw        $s5, 0x24($sp)
/* 8A4B0 800F1000 8FB40020 */  lw        $s4, 0x20($sp)
/* 8A4B4 800F1004 8FB3001C */  lw        $s3, 0x1c($sp)
/* 8A4B8 800F1008 8FB20018 */  lw        $s2, 0x18($sp)
/* 8A4BC 800F100C 8FB10014 */  lw        $s1, 0x14($sp)
/* 8A4C0 800F1010 8FB00010 */  lw        $s0, 0x10($sp)
/* 8A4C4 800F1014 D7BA0050 */  ldc1      $f26, 0x50($sp)
/* 8A4C8 800F1018 D7B80048 */  ldc1      $f24, 0x48($sp)
/* 8A4CC 800F101C D7B60040 */  ldc1      $f22, 0x40($sp)
/* 8A4D0 800F1020 D7B40038 */  ldc1      $f20, 0x38($sp)
/* 8A4D4 800F1024 03E00008 */  jr        $ra
/* 8A4D8 800F1028 27BD0058 */   addiu    $sp, $sp, 0x58
