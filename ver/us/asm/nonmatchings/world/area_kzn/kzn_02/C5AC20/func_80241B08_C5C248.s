.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80246558_C60C98
.double 0.06

.section .text

glabel func_80241B08_C5C248
/* C5C248 80241B08 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* C5C24C 80241B0C AFB3004C */  sw        $s3, 0x4c($sp)
/* C5C250 80241B10 0080982D */  daddu     $s3, $a0, $zero
/* C5C254 80241B14 AFBF0050 */  sw        $ra, 0x50($sp)
/* C5C258 80241B18 AFB20048 */  sw        $s2, 0x48($sp)
/* C5C25C 80241B1C AFB10044 */  sw        $s1, 0x44($sp)
/* C5C260 80241B20 AFB00040 */  sw        $s0, 0x40($sp)
/* C5C264 80241B24 8E720148 */  lw        $s2, 0x148($s3)
/* C5C268 80241B28 00A0882D */  daddu     $s1, $a1, $zero
/* C5C26C 80241B2C 86440008 */  lh        $a0, 8($s2)
/* C5C270 80241B30 0C00EABB */  jal       get_npc_unsafe
/* C5C274 80241B34 00C0802D */   daddu    $s0, $a2, $zero
/* C5C278 80241B38 0200202D */  daddu     $a0, $s0, $zero
/* C5C27C 80241B3C 0240282D */  daddu     $a1, $s2, $zero
/* C5C280 80241B40 24030001 */  addiu     $v1, $zero, 1
/* C5C284 80241B44 AFA30010 */  sw        $v1, 0x10($sp)
/* C5C288 80241B48 8E260024 */  lw        $a2, 0x24($s1)
/* C5C28C 80241B4C 8E270028 */  lw        $a3, 0x28($s1)
/* C5C290 80241B50 0C01242D */  jal       func_800490B4
/* C5C294 80241B54 0040802D */   daddu    $s0, $v0, $zero
/* C5C298 80241B58 14400020 */  bnez      $v0, .L80241BDC
/* C5C29C 80241B5C 24040002 */   addiu    $a0, $zero, 2
/* C5C2A0 80241B60 0200282D */  daddu     $a1, $s0, $zero
/* C5C2A4 80241B64 0000302D */  daddu     $a2, $zero, $zero
/* C5C2A8 80241B68 860300A8 */  lh        $v1, 0xa8($s0)
/* C5C2AC 80241B6C 3C013F80 */  lui       $at, 0x3f80
/* C5C2B0 80241B70 44810000 */  mtc1      $at, $f0
/* C5C2B4 80241B74 3C014000 */  lui       $at, 0x4000
/* C5C2B8 80241B78 44811000 */  mtc1      $at, $f2
/* C5C2BC 80241B7C 3C01C1A0 */  lui       $at, 0xc1a0
/* C5C2C0 80241B80 44812000 */  mtc1      $at, $f4
/* C5C2C4 80241B84 2402000F */  addiu     $v0, $zero, 0xf
/* C5C2C8 80241B88 AFA2001C */  sw        $v0, 0x1c($sp)
/* C5C2CC 80241B8C 44834000 */  mtc1      $v1, $f8
/* C5C2D0 80241B90 00000000 */  nop
/* C5C2D4 80241B94 46804220 */  cvt.s.w   $f8, $f8
/* C5C2D8 80241B98 44074000 */  mfc1      $a3, $f8
/* C5C2DC 80241B9C 27A20028 */  addiu     $v0, $sp, 0x28
/* C5C2E0 80241BA0 AFA20020 */  sw        $v0, 0x20($sp)
/* C5C2E4 80241BA4 E7A00010 */  swc1      $f0, 0x10($sp)
/* C5C2E8 80241BA8 E7A20014 */  swc1      $f2, 0x14($sp)
/* C5C2EC 80241BAC 0C01BFA4 */  jal       fx_emote
/* C5C2F0 80241BB0 E7A40018 */   swc1     $f4, 0x18($sp)
/* C5C2F4 80241BB4 8E4200CC */  lw        $v0, 0xcc($s2)
/* C5C2F8 80241BB8 8C430000 */  lw        $v1, ($v0)
/* C5C2FC 80241BBC 2402001E */  addiu     $v0, $zero, 0x1e
/* C5C300 80241BC0 A602008E */  sh        $v0, 0x8e($s0)
/* C5C304 80241BC4 24020014 */  addiu     $v0, $zero, 0x14
/* C5C308 80241BC8 AE030028 */  sw        $v1, 0x28($s0)
/* C5C30C 80241BCC AE620070 */  sw        $v0, 0x70($s3)
/* C5C310 80241BD0 2402001E */  addiu     $v0, $zero, 0x1e
/* C5C314 80241BD4 0809075B */  j         .L80241D6C
/* C5C318 80241BD8 AE420090 */   sw       $v0, 0x90($s2)
.L80241BDC:
/* C5C31C 80241BDC 8E050018 */  lw        $a1, 0x18($s0)
/* C5C320 80241BE0 8E06000C */  lw        $a2, 0xc($s0)
/* C5C324 80241BE4 0C00EA95 */  jal       npc_move_heading
/* C5C328 80241BE8 0200202D */   daddu    $a0, $s0, $zero
/* C5C32C 80241BEC 8E020000 */  lw        $v0, ($s0)
/* C5C330 80241BF0 30420008 */  andi      $v0, $v0, 8
/* C5C334 80241BF4 14400028 */  bnez      $v0, .L80241C98
/* C5C338 80241BF8 0000882D */   daddu    $s1, $zero, $zero
/* C5C33C 80241BFC 27A5002C */  addiu     $a1, $sp, 0x2c
/* C5C340 80241C00 27A60030 */  addiu     $a2, $sp, 0x30
/* C5C344 80241C04 860200A8 */  lh        $v0, 0xa8($s0)
/* C5C348 80241C08 C6000038 */  lwc1      $f0, 0x38($s0)
/* C5C34C 80241C0C 44821000 */  mtc1      $v0, $f2
/* C5C350 80241C10 00000000 */  nop
/* C5C354 80241C14 468010A0 */  cvt.s.w   $f2, $f2
/* C5C358 80241C18 E7A0002C */  swc1      $f0, 0x2c($sp)
/* C5C35C 80241C1C 860200A8 */  lh        $v0, 0xa8($s0)
/* C5C360 80241C20 C604003C */  lwc1      $f4, 0x3c($s0)
/* C5C364 80241C24 C6060040 */  lwc1      $f6, 0x40($s0)
/* C5C368 80241C28 44820000 */  mtc1      $v0, $f0
/* C5C36C 80241C2C 00000000 */  nop
/* C5C370 80241C30 46800021 */  cvt.d.w   $f0, $f0
/* C5C374 80241C34 46022100 */  add.s     $f4, $f4, $f2
/* C5C378 80241C38 3C014008 */  lui       $at, 0x4008
/* C5C37C 80241C3C 44811800 */  mtc1      $at, $f3
/* C5C380 80241C40 44801000 */  mtc1      $zero, $f2
/* C5C384 80241C44 27A20038 */  addiu     $v0, $sp, 0x38
/* C5C388 80241C48 46220000 */  add.d     $f0, $f0, $f2
/* C5C38C 80241C4C E7A60034 */  swc1      $f6, 0x34($sp)
/* C5C390 80241C50 E7A40030 */  swc1      $f4, 0x30($sp)
/* C5C394 80241C54 46200020 */  cvt.s.d   $f0, $f0
/* C5C398 80241C58 E7A00038 */  swc1      $f0, 0x38($sp)
/* C5C39C 80241C5C AFA20010 */  sw        $v0, 0x10($sp)
/* C5C3A0 80241C60 8E040080 */  lw        $a0, 0x80($s0)
/* C5C3A4 80241C64 0C0372DF */  jal       npc_raycast_down_sides
/* C5C3A8 80241C68 27A70034 */   addiu    $a3, $sp, 0x34
/* C5C3AC 80241C6C 1040000A */  beqz      $v0, .L80241C98
/* C5C3B0 80241C70 00000000 */   nop
/* C5C3B4 80241C74 860200A8 */  lh        $v0, 0xa8($s0)
/* C5C3B8 80241C78 C7A20038 */  lwc1      $f2, 0x38($sp)
/* C5C3BC 80241C7C 44820000 */  mtc1      $v0, $f0
/* C5C3C0 80241C80 00000000 */  nop
/* C5C3C4 80241C84 46800020 */  cvt.s.w   $f0, $f0
/* C5C3C8 80241C88 4600103C */  c.lt.s    $f2, $f0
/* C5C3CC 80241C8C 00000000 */  nop
/* C5C3D0 80241C90 45030001 */  bc1tl     .L80241C98
/* C5C3D4 80241C94 24110001 */   addiu    $s1, $zero, 1
.L80241C98:
/* C5C3D8 80241C98 12200008 */  beqz      $s1, .L80241CBC
/* C5C3DC 80241C9C 00000000 */   nop
/* C5C3E0 80241CA0 C7A00030 */  lwc1      $f0, 0x30($sp)
/* C5C3E4 80241CA4 3C013FF0 */  lui       $at, 0x3ff0
/* C5C3E8 80241CA8 44811800 */  mtc1      $at, $f3
/* C5C3EC 80241CAC 44801000 */  mtc1      $zero, $f2
/* C5C3F0 80241CB0 46000021 */  cvt.d.s   $f0, $f0
/* C5C3F4 80241CB4 08090751 */  j         .L80241D44
/* C5C3F8 80241CB8 46220000 */   add.d    $f0, $f0, $f2
.L80241CBC:
/* C5C3FC 80241CBC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* C5C400 80241CC0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* C5C404 80241CC4 3C014018 */  lui       $at, 0x4018
/* C5C408 80241CC8 44811800 */  mtc1      $at, $f3
/* C5C40C 80241CCC 44801000 */  mtc1      $zero, $f2
/* C5C410 80241CD0 C440002C */  lwc1      $f0, 0x2c($v0)
/* C5C414 80241CD4 C604003C */  lwc1      $f4, 0x3c($s0)
/* C5C418 80241CD8 46000021 */  cvt.d.s   $f0, $f0
/* C5C41C 80241CDC 46220000 */  add.d     $f0, $f0, $f2
/* C5C420 80241CE0 46002121 */  cvt.d.s   $f4, $f4
/* C5C424 80241CE4 46202001 */  sub.d     $f0, $f4, $f0
/* C5C428 80241CE8 462001A0 */  cvt.s.d   $f6, $f0
/* C5C42C 80241CEC 44800000 */  mtc1      $zero, $f0
/* C5C430 80241CF0 44800800 */  mtc1      $zero, $f1
/* C5C434 80241CF4 460030A1 */  cvt.d.s   $f2, $f6
/* C5C438 80241CF8 4620103C */  c.lt.d    $f2, $f0
/* C5C43C 80241CFC 00000000 */  nop
/* C5C440 80241D00 45010009 */  bc1t      .L80241D28
/* C5C444 80241D04 00000000 */   nop
/* C5C448 80241D08 3C014010 */  lui       $at, 0x4010
/* C5C44C 80241D0C 44810800 */  mtc1      $at, $f1
/* C5C450 80241D10 44800000 */  mtc1      $zero, $f0
/* C5C454 80241D14 00000000 */  nop
/* C5C458 80241D18 4622003C */  c.lt.d    $f0, $f2
/* C5C45C 80241D1C 00000000 */  nop
/* C5C460 80241D20 4500000A */  bc1f      .L80241D4C
/* C5C464 80241D24 00000000 */   nop
.L80241D28:
/* C5C468 80241D28 3C018024 */  lui       $at, %hi(D_80246558_C60C98)
/* C5C46C 80241D2C D4226558 */  ldc1      $f2, %lo(D_80246558_C60C98)($at)
/* C5C470 80241D30 46003187 */  neg.s     $f6, $f6
/* C5C474 80241D34 46003021 */  cvt.d.s   $f0, $f6
/* C5C478 80241D38 46220002 */  mul.d     $f0, $f0, $f2
/* C5C47C 80241D3C 00000000 */  nop
/* C5C480 80241D40 46202000 */  add.d     $f0, $f4, $f0
.L80241D44:
/* C5C484 80241D44 46200020 */  cvt.s.d   $f0, $f0
/* C5C488 80241D48 E600003C */  swc1      $f0, 0x3c($s0)
.L80241D4C:
/* C5C48C 80241D4C 8602008E */  lh        $v0, 0x8e($s0)
/* C5C490 80241D50 9603008E */  lhu       $v1, 0x8e($s0)
/* C5C494 80241D54 18400003 */  blez      $v0, .L80241D64
/* C5C498 80241D58 2462FFFF */   addiu    $v0, $v1, -1
/* C5C49C 80241D5C 0809075B */  j         .L80241D6C
/* C5C4A0 80241D60 A602008E */   sh       $v0, 0x8e($s0)
.L80241D64:
/* C5C4A4 80241D64 2402000C */  addiu     $v0, $zero, 0xc
/* C5C4A8 80241D68 AE620070 */  sw        $v0, 0x70($s3)
.L80241D6C:
/* C5C4AC 80241D6C 8FBF0050 */  lw        $ra, 0x50($sp)
/* C5C4B0 80241D70 8FB3004C */  lw        $s3, 0x4c($sp)
/* C5C4B4 80241D74 8FB20048 */  lw        $s2, 0x48($sp)
/* C5C4B8 80241D78 8FB10044 */  lw        $s1, 0x44($sp)
/* C5C4BC 80241D7C 8FB00040 */  lw        $s0, 0x40($sp)
/* C5C4C0 80241D80 03E00008 */  jr        $ra
/* C5C4C4 80241D84 27BD0058 */   addiu    $sp, $sp, 0x58
