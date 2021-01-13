.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802411D0_C3BBE0
/* C3BBE0 802411D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* C3BBE4 802411D4 AFB20038 */  sw        $s2, 0x38($sp)
/* C3BBE8 802411D8 0080902D */  daddu     $s2, $a0, $zero
/* C3BBEC 802411DC AFBF0048 */  sw        $ra, 0x48($sp)
/* C3BBF0 802411E0 AFB50044 */  sw        $s5, 0x44($sp)
/* C3BBF4 802411E4 AFB40040 */  sw        $s4, 0x40($sp)
/* C3BBF8 802411E8 AFB3003C */  sw        $s3, 0x3c($sp)
/* C3BBFC 802411EC AFB10034 */  sw        $s1, 0x34($sp)
/* C3BC00 802411F0 AFB00030 */  sw        $s0, 0x30($sp)
/* C3BC04 802411F4 8E510148 */  lw        $s1, 0x148($s2)
/* C3BC08 802411F8 86240008 */  lh        $a0, 8($s1)
/* C3BC0C 802411FC 0C00EABB */  jal       get_npc_unsafe
/* C3BC10 80241200 00A0802D */   daddu    $s0, $a1, $zero
/* C3BC14 80241204 8E43000C */  lw        $v1, 0xc($s2)
/* C3BC18 80241208 0240202D */  daddu     $a0, $s2, $zero
/* C3BC1C 8024120C 8C650000 */  lw        $a1, ($v1)
/* C3BC20 80241210 0C0B1EAF */  jal       get_variable
/* C3BC24 80241214 0040A82D */   daddu    $s5, $v0, $zero
/* C3BC28 80241218 AFA00010 */  sw        $zero, 0x10($sp)
/* C3BC2C 8024121C 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3BC30 80241220 8C630030 */  lw        $v1, 0x30($v1)
/* C3BC34 80241224 AFA30014 */  sw        $v1, 0x14($sp)
/* C3BC38 80241228 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3BC3C 8024122C 8C63001C */  lw        $v1, 0x1c($v1)
/* C3BC40 80241230 AFA30018 */  sw        $v1, 0x18($sp)
/* C3BC44 80241234 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3BC48 80241238 8C630024 */  lw        $v1, 0x24($v1)
/* C3BC4C 8024123C AFA3001C */  sw        $v1, 0x1c($sp)
/* C3BC50 80241240 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3BC54 80241244 8C630028 */  lw        $v1, 0x28($v1)
/* C3BC58 80241248 27B40010 */  addiu     $s4, $sp, 0x10
/* C3BC5C 8024124C AFA30020 */  sw        $v1, 0x20($sp)
/* C3BC60 80241250 8E2300D0 */  lw        $v1, 0xd0($s1)
/* C3BC64 80241254 3C014282 */  lui       $at, 0x4282
/* C3BC68 80241258 44810000 */  mtc1      $at, $f0
/* C3BC6C 8024125C 8C63002C */  lw        $v1, 0x2c($v1)
/* C3BC70 80241260 0040982D */  daddu     $s3, $v0, $zero
/* C3BC74 80241264 E7A00028 */  swc1      $f0, 0x28($sp)
/* C3BC78 80241268 A7A0002C */  sh        $zero, 0x2c($sp)
/* C3BC7C 8024126C 16000005 */  bnez      $s0, .L80241284
/* C3BC80 80241270 AFA30024 */   sw       $v1, 0x24($sp)
/* C3BC84 80241274 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3BC88 80241278 30420004 */  andi      $v0, $v0, 4
/* C3BC8C 8024127C 10400020 */  beqz      $v0, .L80241300
/* C3BC90 80241280 00000000 */   nop
.L80241284:
/* C3BC94 80241284 2404F7FF */  addiu     $a0, $zero, -0x801
/* C3BC98 80241288 AE400070 */  sw        $zero, 0x70($s2)
/* C3BC9C 8024128C A6A0008E */  sh        $zero, 0x8e($s5)
/* C3BCA0 80241290 8E2200CC */  lw        $v0, 0xcc($s1)
/* C3BCA4 80241294 8EA30000 */  lw        $v1, ($s5)
/* C3BCA8 80241298 8C420000 */  lw        $v0, ($v0)
/* C3BCAC 8024129C 00641824 */  and       $v1, $v1, $a0
/* C3BCB0 802412A0 AEA30000 */  sw        $v1, ($s5)
/* C3BCB4 802412A4 AEA20028 */  sw        $v0, 0x28($s5)
/* C3BCB8 802412A8 8E2200D0 */  lw        $v0, 0xd0($s1)
/* C3BCBC 802412AC 8C420034 */  lw        $v0, 0x34($v0)
/* C3BCC0 802412B0 54400005 */  bnel      $v0, $zero, .L802412C8
/* C3BCC4 802412B4 2402FDFF */   addiu    $v0, $zero, -0x201
/* C3BCC8 802412B8 34620200 */  ori       $v0, $v1, 0x200
/* C3BCCC 802412BC 2403FFF7 */  addiu     $v1, $zero, -9
/* C3BCD0 802412C0 080904B4 */  j         .L802412D0
/* C3BCD4 802412C4 00431024 */   and      $v0, $v0, $v1
.L802412C8:
/* C3BCD8 802412C8 00621024 */  and       $v0, $v1, $v0
/* C3BCDC 802412CC 34420008 */  ori       $v0, $v0, 8
.L802412D0:
/* C3BCE0 802412D0 AEA20000 */  sw        $v0, ($s5)
/* C3BCE4 802412D4 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3BCE8 802412D8 30420004 */  andi      $v0, $v0, 4
/* C3BCEC 802412DC 10400007 */  beqz      $v0, .L802412FC
/* C3BCF0 802412E0 24020063 */   addiu    $v0, $zero, 0x63
/* C3BCF4 802412E4 AE420070 */  sw        $v0, 0x70($s2)
/* C3BCF8 802412E8 AE400074 */  sw        $zero, 0x74($s2)
/* C3BCFC 802412EC 8E2200B0 */  lw        $v0, 0xb0($s1)
/* C3BD00 802412F0 2403FFFB */  addiu     $v1, $zero, -5
/* C3BD04 802412F4 00431024 */  and       $v0, $v0, $v1
/* C3BD08 802412F8 AE2200B0 */  sw        $v0, 0xb0($s1)
.L802412FC:
/* C3BD0C 802412FC AE20006C */  sw        $zero, 0x6c($s1)
.L80241300:
/* C3BD10 80241300 8E420070 */  lw        $v0, 0x70($s2)
/* C3BD14 80241304 2842001E */  slti      $v0, $v0, 0x1e
/* C3BD18 80241308 10400009 */  beqz      $v0, .L80241330
/* C3BD1C 8024130C 00000000 */   nop
/* C3BD20 80241310 8E22006C */  lw        $v0, 0x6c($s1)
/* C3BD24 80241314 14400006 */  bnez      $v0, .L80241330
/* C3BD28 80241318 00000000 */   nop
/* C3BD2C 8024131C 0C09009A */  jal       func_80240268_C3AC78
/* C3BD30 80241320 0240202D */   daddu    $a0, $s2, $zero
/* C3BD34 80241324 10400002 */  beqz      $v0, .L80241330
/* C3BD38 80241328 2402001E */   addiu    $v0, $zero, 0x1e
/* C3BD3C 8024132C AE420070 */  sw        $v0, 0x70($s2)
.L80241330:
/* C3BD40 80241330 8E430070 */  lw        $v1, 0x70($s2)
/* C3BD44 80241334 2C620064 */  sltiu     $v0, $v1, 0x64
/* C3BD48 80241338 10400048 */  beqz      $v0, .L8024145C
/* C3BD4C 8024133C 00031080 */   sll      $v0, $v1, 2
/* C3BD50 80241340 3C018024 */  lui       $at, %hi(jtbl_802424E0_C3CEF0)
/* C3BD54 80241344 00220821 */  addu      $at, $at, $v0
/* C3BD58 80241348 8C2224E0 */  lw        $v0, %lo(jtbl_802424E0_C3CEF0)($at)
/* C3BD5C 8024134C 00400008 */  jr        $v0
/* C3BD60 80241350 00000000 */   nop
glabel L80241354_C3BD64
/* C3BD64 80241354 0240202D */  daddu     $a0, $s2, $zero
/* C3BD68 80241358 0260282D */  daddu     $a1, $s3, $zero
/* C3BD6C 8024135C 0C012568 */  jal       func_800495A0
/* C3BD70 80241360 0280302D */   daddu    $a2, $s4, $zero
glabel L80241364_C3BD74
/* C3BD74 80241364 0240202D */  daddu     $a0, $s2, $zero
/* C3BD78 80241368 0260282D */  daddu     $a1, $s3, $zero
/* C3BD7C 8024136C 0C0125AE */  jal       func_800496B8
/* C3BD80 80241370 0280302D */   daddu    $a2, $s4, $zero
/* C3BD84 80241374 08090517 */  j         .L8024145C
/* C3BD88 80241378 00000000 */   nop
glabel L8024137C_C3BD8C
/* C3BD8C 8024137C 0240202D */  daddu     $a0, $s2, $zero
/* C3BD90 80241380 0260282D */  daddu     $a1, $s3, $zero
/* C3BD94 80241384 0C0126D1 */  jal       base_UnkNpcAIFunc1
/* C3BD98 80241388 0280302D */   daddu    $a2, $s4, $zero
glabel L8024138C_C3BD9C
/* C3BD9C 8024138C 0240202D */  daddu     $a0, $s2, $zero
/* C3BDA0 80241390 0260282D */  daddu     $a1, $s3, $zero
/* C3BDA4 80241394 0C012701 */  jal       func_80049C04
/* C3BDA8 80241398 0280302D */   daddu    $a2, $s4, $zero
/* C3BDAC 8024139C 08090517 */  j         .L8024145C
/* C3BDB0 802413A0 00000000 */   nop
glabel L802413A4_C3BDB4
/* C3BDB4 802413A4 0240202D */  daddu     $a0, $s2, $zero
/* C3BDB8 802413A8 0260282D */  daddu     $a1, $s3, $zero
/* C3BDBC 802413AC 0C01278F */  jal       func_80049E3C
/* C3BDC0 802413B0 0280302D */   daddu    $a2, $s4, $zero
glabel L802413B4_C3BDC4
/* C3BDC4 802413B4 0240202D */  daddu     $a0, $s2, $zero
/* C3BDC8 802413B8 0260282D */  daddu     $a1, $s3, $zero
/* C3BDCC 802413BC 0C0127B3 */  jal       func_80049ECC
/* C3BDD0 802413C0 0280302D */   daddu    $a2, $s4, $zero
/* C3BDD4 802413C4 08090517 */  j         .L8024145C
/* C3BDD8 802413C8 00000000 */   nop
glabel L802413CC_C3BDDC
/* C3BDDC 802413CC 0240202D */  daddu     $a0, $s2, $zero
/* C3BDE0 802413D0 0260282D */  daddu     $a1, $s3, $zero
/* C3BDE4 802413D4 0C0127DF */  jal       func_80049F7C
/* C3BDE8 802413D8 0280302D */   daddu    $a2, $s4, $zero
glabel L802413DC_C3BDEC
/* C3BDEC 802413DC 0240202D */  daddu     $a0, $s2, $zero
/* C3BDF0 802413E0 0260282D */  daddu     $a1, $s3, $zero
/* C3BDF4 802413E4 0C012849 */  jal       func_8004A124
/* C3BDF8 802413E8 0280302D */   daddu    $a2, $s4, $zero
/* C3BDFC 802413EC 08090517 */  j         .L8024145C
/* C3BE00 802413F0 00000000 */   nop
glabel L802413F4_C3BE04
/* C3BE04 802413F4 0240202D */  daddu     $a0, $s2, $zero
/* C3BE08 802413F8 0260282D */  daddu     $a1, $s3, $zero
/* C3BE0C 802413FC 0C0128FA */  jal       func_8004A3E8
/* C3BE10 80241400 0280302D */   daddu    $a2, $s4, $zero
/* C3BE14 80241404 08090517 */  j         .L8024145C
/* C3BE18 80241408 00000000 */   nop
glabel L8024140C_C3BE1C
/* C3BE1C 8024140C 0C090018 */  jal       dgb_05_UnkNpcAIFunc6
/* C3BE20 80241410 0240202D */   daddu    $a0, $s2, $zero
glabel L80241414_C3BE24
/* C3BE24 80241414 0C090033 */  jal       dgb_05_UnkNpcAIFunc7
/* C3BE28 80241418 0240202D */   daddu    $a0, $s2, $zero
/* C3BE2C 8024141C 8E430070 */  lw        $v1, 0x70($s2)
/* C3BE30 80241420 24020020 */  addiu     $v0, $zero, 0x20
/* C3BE34 80241424 1462000D */  bne       $v1, $v0, .L8024145C
/* C3BE38 80241428 00000000 */   nop
glabel L8024142C_C3BE3C
/* C3BE3C 8024142C 0C09004F */  jal       dgb_05_UnkNpcAIFunc8
/* C3BE40 80241430 0240202D */   daddu    $a0, $s2, $zero
/* C3BE44 80241434 8E430070 */  lw        $v1, 0x70($s2)
/* C3BE48 80241438 24020021 */  addiu     $v0, $zero, 0x21
/* C3BE4C 8024143C 14620007 */  bne       $v1, $v0, .L8024145C
/* C3BE50 80241440 00000000 */   nop
glabel L80241444_C3BE54
/* C3BE54 80241444 0C090085 */  jal       dgb_05_UnkNpcAIFunc5
/* C3BE58 80241448 0240202D */   daddu    $a0, $s2, $zero
/* C3BE5C 8024144C 08090517 */  j         .L8024145C
/* C3BE60 80241450 00000000 */   nop
glabel L80241454_C3BE64
/* C3BE64 80241454 0C0129CF */  jal       func_8004A73C
/* C3BE68 80241458 0240202D */   daddu    $a0, $s2, $zero
.L8024145C:
glabel L8024145C_C3BE6C
/* C3BE6C 8024145C 8FBF0048 */  lw        $ra, 0x48($sp)
/* C3BE70 80241460 8FB50044 */  lw        $s5, 0x44($sp)
/* C3BE74 80241464 8FB40040 */  lw        $s4, 0x40($sp)
/* C3BE78 80241468 8FB3003C */  lw        $s3, 0x3c($sp)
/* C3BE7C 8024146C 8FB20038 */  lw        $s2, 0x38($sp)
/* C3BE80 80241470 8FB10034 */  lw        $s1, 0x34($sp)
/* C3BE84 80241474 8FB00030 */  lw        $s0, 0x30($sp)
/* C3BE88 80241478 0000102D */  daddu     $v0, $zero, $zero
/* C3BE8C 8024147C 03E00008 */  jr        $ra
/* C3BE90 80241480 27BD0050 */   addiu    $sp, $sp, 0x50
/* C3BE94 80241484 00000000 */  nop
/* C3BE98 80241488 00000000 */  nop
/* C3BE9C 8024148C 00000000 */  nop
