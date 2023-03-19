.set noat      /* allow manual use of $at */
.set noreorder /* don't insert nops after branches */

glabel func_E02000AC
/* 34E93C E02000AC 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* 34E940 E02000B0 3C068080 */  lui       $a2, (0x808080FF >> 16)
/* 34E944 E02000B4 34C680FF */  ori       $a2, $a2, (0x808080FF & 0xFFFF)
/* 34E948 E02000B8 AFB50034 */  sw        $s5, 0x34($sp)
/* 34E94C E02000BC 0000A82D */  daddu     $s5, $zero, $zero
/* 34E950 E02000C0 3C028009 */  lui       $v0, %hi(gMainGfxPos)
/* 34E954 E02000C4 24426A44 */  addiu     $v0, $v0, %lo(gMainGfxPos)
/* 34E958 E02000C8 0040502D */  daddu     $t2, $v0, $zero
/* 34E95C E02000CC 3C0EF510 */  lui       $t6, (0xF5102800 >> 16)
/* 34E960 E02000D0 35CE2800 */  ori       $t6, $t6, (0xF5102800 & 0xFFFF)
/* 34E964 E02000D4 AFBE0040 */  sw        $fp, 0x40($sp)
/* 34E968 E02000D8 3C1E0701 */  lui       $fp, (0x7018070 >> 16)
/* 34E96C E02000DC 37DE8070 */  ori       $fp, $fp, (0x7018070 & 0xFFFF)
/* 34E970 E02000E0 AFB7003C */  sw        $s7, 0x3C($sp)
/* 34E974 E02000E4 3C17E700 */  lui       $s7, (0xE7000000 >> 16)
/* 34E978 E02000E8 00041080 */  sll       $v0, $a0, 2
/* 34E97C E02000EC 30420FFF */  andi      $v0, $v0, 0xFFF
/* 34E980 E02000F0 AFB3002C */  sw        $s3, 0x2C($sp)
/* 34E984 E02000F4 00029B00 */  sll       $s3, $v0, 12
/* 34E988 E02000F8 2482004F */  addiu     $v0, $a0, 0x4F
/* 34E98C E02000FC 00021080 */  sll       $v0, $v0, 2
/* 34E990 E0200100 30420FFF */  andi      $v0, $v0, 0xFFF
/* 34E994 E0200104 00021300 */  sll       $v0, $v0, 12
/* 34E998 E0200108 AFAE0000 */  sw        $t6, 0x0($sp)
/* 34E99C E020010C 3C0EFD10 */  lui       $t6, (0xFD10013F >> 16)
/* 34E9A0 E0200110 35CE013F */  ori       $t6, $t6, (0xFD10013F & 0xFFFF)
/* 34E9A4 E0200114 AFB60038 */  sw        $s6, 0x38($sp)
/* 34E9A8 E0200118 24960050 */  addiu     $s6, $a0, 0x50
/* 34E9AC E020011C AFAE0008 */  sw        $t6, 0x8($sp)
/* 34E9B0 E0200120 240E00A0 */  addiu     $t6, $zero, 0xA0
/* 34E9B4 E0200124 00042540 */  sll       $a0, $a0, 21
/* 34E9B8 E0200128 AFB20028 */  sw        $s2, 0x28($sp)
/* 34E9BC E020012C 24120014 */  addiu     $s2, $zero, 0x14
/* 34E9C0 E0200130 AFB10024 */  sw        $s1, 0x24($sp)
/* 34E9C4 E0200134 02A0882D */  daddu     $s1, $s5, $zero
/* 34E9C8 E0200138 AFB40030 */  sw        $s4, 0x30($sp)
/* 34E9CC E020013C AFB00020 */  sw        $s0, 0x20($sp)
/* 34E9D0 E0200140 AFA20004 */  sw        $v0, 0x4($sp)
/* 34E9D4 E0200144 AFAE000C */  sw        $t6, 0xC($sp)
/* 34E9D8 E0200148 AFA40010 */  sw        $a0, 0x10($sp)
/* 34E9DC E020014C 8D420000 */  lw        $v0, 0x0($t2)
/* 34E9E0 E0200150 00A0582D */  daddu     $t3, $a1, $zero
/* 34E9E4 E0200154 0040182D */  daddu     $v1, $v0, $zero
/* 34E9E8 E0200158 24420008 */  addiu     $v0, $v0, 0x8
/* 34E9EC E020015C AD420000 */  sw        $v0, 0x0($t2)
/* 34E9F0 E0200160 3C02FA00 */  lui       $v0, (0xFA000000 >> 16)
/* 34E9F4 E0200164 AC620000 */  sw        $v0, 0x0($v1)
/* 34E9F8 E0200168 AC660004 */  sw        $a2, 0x4($v1)
.LPAL_E020016C:
/* 34E9FC E020016C 3C07FD10 */  lui       $a3, (0xFD10004F >> 16)
/* 34EA00 E0200170 34E7004F */  ori       $a3, $a3, (0xFD10004F & 0xFFFF)
/* 34EA04 E0200174 3C080713 */  lui       $t0, (0x713C000 >> 16)
/* 34EA08 E0200178 3508C000 */  ori       $t0, $t0, (0x713C000 & 0xFFFF)
/* 34EA0C E020017C 3C090001 */  lui       $t1, (0x18070 >> 16)
/* 34EA10 E0200180 35298070 */  ori       $t1, $t1, (0x18070 & 0xFFFF)
/* 34EA14 E0200184 3C03F510 */  lui       $v1, (0xF5100100 >> 16)
/* 34EA18 E0200188 34630100 */  ori       $v1, $v1, (0xF5100100 & 0xFFFF)
/* 34EA1C E020018C 000B3080 */  sll       $a2, $t3, 2
/* 34EA20 E0200190 30C60FFF */  andi      $a2, $a2, 0xFFF
/* 34EA24 E0200194 25650005 */  addiu     $a1, $t3, 0x5
/* 34EA28 E0200198 00052880 */  sll       $a1, $a1, 2
/* 34EA2C E020019C 30A50FFF */  andi      $a1, $a1, 0xFFF
/* 34EA30 E02001A0 8FAE000C */  lw        $t6, 0xC($sp)
/* 34EA34 E02001A4 02667825 */  or        $t7, $s3, $a2
/* 34EA38 E02001A8 000E1180 */  sll       $v0, $t6, 6
/* 34EA3C E02001AC 00436825 */  or        $t5, $v0, $v1
/* 34EA40 E02001B0 3C0EF400 */  lui       $t6, (0xF4000000 >> 16)
/* 34EA44 E02001B4 00CE1025 */  or        $v0, $a2, $t6
/* 34EA48 E02001B8 0262A025 */  or        $s4, $s3, $v0
/* 34EA4C E02001BC 26C3FFFF */  addiu     $v1, $s6, -0x1
/* 34EA50 E02001C0 00031880 */  sll       $v1, $v1, 2
/* 34EA54 E02001C4 30630FFF */  andi      $v1, $v1, 0xFFF
/* 34EA58 E02001C8 00031B00 */  sll       $v1, $v1, 12
/* 34EA5C E02001CC 3C020700 */  lui       $v0, (0x7000000 >> 16)
/* 34EA60 E02001D0 00A21025 */  or        $v0, $a1, $v0
/* 34EA64 E02001D4 00628025 */  or        $s0, $v1, $v0
/* 34EA68 E02001D8 00161080 */  sll       $v0, $s6, 2
/* 34EA6C E02001DC 30420FFF */  andi      $v0, $v0, 0xFFF
/* 34EA70 E02001E0 0002CB00 */  sll       $t9, $v0, 12
/* 34EA74 E02001E4 25620006 */  addiu     $v0, $t3, 0x6
/* 34EA78 E02001E8 00021080 */  sll       $v0, $v0, 2
/* 34EA7C E02001EC 30580FFF */  andi      $t8, $v0, 0xFFF
/* 34EA80 E02001F0 8D430000 */  lw        $v1, 0x0($t2)
/* 34EA84 E02001F4 3C0E8009 */  lui       $t6, %hi(nuGfxCfb_ptr)
/* 34EA88 E02001F8 8DCE6A24 */  lw        $t6, %lo(nuGfxCfb_ptr)($t6)
/* 34EA8C E02001FC 0060102D */  daddu     $v0, $v1, $zero
/* 34EA90 E0200200 01C0202D */  daddu     $a0, $t6, $zero
/* 34EA94 E0200204 24630008 */  addiu     $v1, $v1, 0x8
/* 34EA98 E0200208 AFAE0018 */  sw        $t6, 0x18($sp)
/* 34EA9C E020020C AD430000 */  sw        $v1, 0x0($t2)
/* 34EAA0 E0200210 AC470000 */  sw        $a3, 0x0($v0)
/* 34EAA4 E0200214 AC440004 */  sw        $a0, 0x4($v0)
/* 34EAA8 E0200218 24620008 */  addiu     $v0, $v1, 0x8
/* 34EAAC E020021C AD420000 */  sw        $v0, 0x0($t2)
/* 34EAB0 E0200220 8FAE0000 */  lw        $t6, 0x0($sp)
/* 34EAB4 E0200224 24620010 */  addiu     $v0, $v1, 0x10
/* 34EAB8 E0200228 AC7E0004 */  sw        $fp, 0x4($v1)
/* 34EABC E020022C AC6E0000 */  sw        $t6, 0x0($v1)
/* 34EAC0 E0200230 3C0EE600 */  lui       $t6, (0xE6000000 >> 16)
/* 34EAC4 E0200234 AD420000 */  sw        $v0, 0x0($t2)
/* 34EAC8 E0200238 24620018 */  addiu     $v0, $v1, 0x18
/* 34EACC E020023C AC6E0008 */  sw        $t6, 0x8($v1)
/* 34EAD0 E0200240 AC60000C */  sw        $zero, 0xC($v1)
/* 34EAD4 E0200244 AD420000 */  sw        $v0, 0x0($t2)
/* 34EAD8 E0200248 32220FFF */  andi      $v0, $s1, 0xFFF
/* 34EADC E020024C 3C0EF400 */  lui       $t6, (0xF4000000 >> 16)
/* 34EAE0 E0200250 004E1025 */  or        $v0, $v0, $t6
/* 34EAE4 E0200254 AC620010 */  sw        $v0, 0x10($v1)
/* 34EAE8 E0200258 32420FFF */  andi      $v0, $s2, 0xFFF
/* 34EAEC E020025C 00481025 */  or        $v0, $v0, $t0
/* 34EAF0 E0200260 AC620014 */  sw        $v0, 0x14($v1)
/* 34EAF4 E0200264 24620020 */  addiu     $v0, $v1, 0x20
/* 34EAF8 E0200268 AD420000 */  sw        $v0, 0x0($t2)
/* 34EAFC E020026C 24620028 */  addiu     $v0, $v1, 0x28
/* 34EB00 E0200270 AC770018 */  sw        $s7, 0x18($v1)
/* 34EB04 E0200274 AC60001C */  sw        $zero, 0x1C($v1)
/* 34EB08 E0200278 AD420000 */  sw        $v0, 0x0($t2)
/* 34EB0C E020027C 8FAE0000 */  lw        $t6, 0x0($sp)
/* 34EB10 E0200280 24620030 */  addiu     $v0, $v1, 0x30
/* 34EB14 E0200284 AC690024 */  sw        $t1, 0x24($v1)
/* 34EB18 E0200288 AC6E0020 */  sw        $t6, 0x20($v1)
/* 34EB1C E020028C AD420000 */  sw        $v0, 0x0($t2)
/* 34EB20 E0200290 3C02F200 */  lui       $v0, (0xF2000000 >> 16)
/* 34EB24 E0200294 00C23025 */  or        $a2, $a2, $v0
/* 34EB28 E0200298 02663025 */  or        $a2, $s3, $a2
/* 34EB2C E020029C AC660028 */  sw        $a2, 0x28($v1)
/* 34EB30 E02002A0 8FAE0004 */  lw        $t6, 0x4($sp)
/* 34EB34 E02002A4 0000602D */  daddu     $t4, $zero, $zero
/* 34EB38 E02002A8 01C51025 */  or        $v0, $t6, $a1
/* 34EB3C E02002AC AC62002C */  sw        $v0, 0x2C($v1)
/* 34EB40 E02002B0 24620038 */  addiu     $v0, $v1, 0x38
/* 34EB44 E02002B4 AD420000 */  sw        $v0, 0x0($t2)
/* 34EB48 E02002B8 3C020100 */  lui       $v0, (0x1000000 >> 16)
/* 34EB4C E02002BC 00A22825 */  or        $a1, $a1, $v0
/* 34EB50 E02002C0 01C52825 */  or        $a1, $t6, $a1
/* 34EB54 E02002C4 AC660030 */  sw        $a2, 0x30($v1)
/* 34EB58 E02002C8 AC650034 */  sw        $a1, 0x34($v1)
.LPAL_E02002CC:
/* 34EB5C E02002CC 3C040101 */  lui       $a0, (0x1018070 >> 16)
/* 34EB60 E02002D0 34848070 */  ori       $a0, $a0, (0x1018070 & 0xFFFF)
/* 34EB64 E02002D4 8D430000 */  lw        $v1, 0x0($t2)
/* 34EB68 E02002D8 3C050400 */  lui       $a1, (0x4000400 >> 16)
/* 34EB6C E02002DC 0060102D */  daddu     $v0, $v1, $zero
/* 34EB70 E02002E0 24630008 */  addiu     $v1, $v1, 0x8
/* 34EB74 E02002E4 AD430000 */  sw        $v1, 0x0($t2)
/* 34EB78 E02002E8 8FAE0008 */  lw        $t6, 0x8($sp)
/* 34EB7C E02002EC 34A50400 */  ori       $a1, $a1, (0x4000400 & 0xFFFF)
/* 34EB80 E02002F0 AC4E0000 */  sw        $t6, 0x0($v0)
/* 34EB84 E02002F4 8FAE0018 */  lw        $t6, 0x18($sp)
/* 34EB88 E02002F8 258C0001 */  addiu     $t4, $t4, 0x1
/* 34EB8C E02002FC AC4E0004 */  sw        $t6, 0x4($v0)
/* 34EB90 E0200300 24620008 */  addiu     $v0, $v1, 0x8
/* 34EB94 E0200304 AD420000 */  sw        $v0, 0x0($t2)
/* 34EB98 E0200308 24620010 */  addiu     $v0, $v1, 0x10
/* 34EB9C E020030C 3C0EE600 */  lui       $t6, (0xE6000000 >> 16)
/* 34EBA0 E0200310 AC6D0000 */  sw        $t5, 0x0($v1)
/* 34EBA4 E0200314 AC7E0004 */  sw        $fp, 0x4($v1)
/* 34EBA8 E0200318 AD420000 */  sw        $v0, 0x0($t2)
/* 34EBAC E020031C 24620018 */  addiu     $v0, $v1, 0x18
/* 34EBB0 E0200320 AC6E0008 */  sw        $t6, 0x8($v1)
/* 34EBB4 E0200324 AC60000C */  sw        $zero, 0xC($v1)
/* 34EBB8 E0200328 AD420000 */  sw        $v0, 0x0($t2)
/* 34EBBC E020032C 24620020 */  addiu     $v0, $v1, 0x20
/* 34EBC0 E0200330 AC740010 */  sw        $s4, 0x10($v1)
/* 34EBC4 E0200334 AC700014 */  sw        $s0, 0x14($v1)
/* 34EBC8 E0200338 AD420000 */  sw        $v0, 0x0($t2)
/* 34EBCC E020033C 24620028 */  addiu     $v0, $v1, 0x28
/* 34EBD0 E0200340 AC770018 */  sw        $s7, 0x18($v1)
/* 34EBD4 E0200344 AC60001C */  sw        $zero, 0x1C($v1)
/* 34EBD8 E0200348 AD420000 */  sw        $v0, 0x0($t2)
/* 34EBDC E020034C 24620030 */  addiu     $v0, $v1, 0x30
/* 34EBE0 E0200350 AC6D0020 */  sw        $t5, 0x20($v1)
/* 34EBE4 E0200354 AC640024 */  sw        $a0, 0x24($v1)
/* 34EBE8 E0200358 AD420000 */  sw        $v0, 0x0($t2)
/* 34EBEC E020035C 3C02E400 */  lui       $v0, (0xE4000000 >> 16)
/* 34EBF0 E0200360 03021025 */  or        $v0, $t8, $v0
/* 34EBF4 E0200364 03221025 */  or        $v0, $t9, $v0
/* 34EBF8 E0200368 AC620028 */  sw        $v0, 0x28($v1)
/* 34EBFC E020036C 24620038 */  addiu     $v0, $v1, 0x38
/* 34EC00 E0200370 AC6F002C */  sw        $t7, 0x2C($v1)
/* 34EC04 E0200374 AD420000 */  sw        $v0, 0x0($t2)
/* 34EC08 E0200378 3C02E100 */  lui       $v0, (0xE1000000 >> 16)
/* 34EC0C E020037C AC620030 */  sw        $v0, 0x30($v1)
/* 34EC10 E0200380 000B1140 */  sll       $v0, $t3, 5
/* 34EC14 E0200384 8FAE0010 */  lw        $t6, 0x10($sp)
/* 34EC18 E0200388 3042FFFF */  andi      $v0, $v0, 0xFFFF
/* 34EC1C E020038C 01C21025 */  or        $v0, $t6, $v0
/* 34EC20 E0200390 AC620034 */  sw        $v0, 0x34($v1)
/* 34EC24 E0200394 24620040 */  addiu     $v0, $v1, 0x40
/* 34EC28 E0200398 AD420000 */  sw        $v0, 0x0($t2)
/* 34EC2C E020039C 3C02F100 */  lui       $v0, (0xF1000000 >> 16)
/* 34EC30 E02003A0 AC620038 */  sw        $v0, 0x38($v1)
/* 34EC34 E02003A4 1980FFC9 */  blez      $t4, .LPAL_E02002CC
/* 34EC38 E02003A8 AC65003C */   sw       $a1, 0x3C($v1)
/* 34EC3C E02003AC 26520018 */  addiu     $s2, $s2, 0x18
/* 34EC40 E02003B0 26310018 */  addiu     $s1, $s1, 0x18
/* 34EC44 E02003B4 256B0006 */  addiu     $t3, $t3, 0x6
/* 34EC48 E02003B8 8D420000 */  lw        $v0, 0x0($t2)
/* 34EC4C E02003BC 26B50001 */  addiu     $s5, $s5, 0x1
/* 34EC50 E02003C0 0040182D */  daddu     $v1, $v0, $zero
/* 34EC54 E02003C4 24420008 */  addiu     $v0, $v0, 0x8
/* 34EC58 E02003C8 AD420000 */  sw        $v0, 0x0($t2)
/* 34EC5C E02003CC 2AA2000A */  slti      $v0, $s5, 0xA
/* 34EC60 E02003D0 AC770000 */  sw        $s7, 0x0($v1)
/* 34EC64 E02003D4 1440FF65 */  bnez      $v0, .LPAL_E020016C
/* 34EC68 E02003D8 AC600004 */   sw       $zero, 0x4($v1)
/* 34EC6C E02003DC 8FBE0040 */  lw        $fp, 0x40($sp)
/* 34EC70 E02003E0 8FB7003C */  lw        $s7, 0x3C($sp)
/* 34EC74 E02003E4 8FB60038 */  lw        $s6, 0x38($sp)
/* 34EC78 E02003E8 8FB50034 */  lw        $s5, 0x34($sp)
/* 34EC7C E02003EC 8FB40030 */  lw        $s4, 0x30($sp)
/* 34EC80 E02003F0 8FB3002C */  lw        $s3, 0x2C($sp)
/* 34EC84 E02003F4 8FB20028 */  lw        $s2, 0x28($sp)
/* 34EC88 E02003F8 8FB10024 */  lw        $s1, 0x24($sp)
/* 34EC8C E02003FC 8FB00020 */  lw        $s0, 0x20($sp)
/* 34EC90 E0200400 03E00008 */  jr        $ra
/* 34EC94 E0200404 27BD0048 */   addiu    $sp, $sp, 0x48
/* 34EC98 E0200408 00000000 */  nop
/* 34EC9C E020040C 00000000 */  nop
