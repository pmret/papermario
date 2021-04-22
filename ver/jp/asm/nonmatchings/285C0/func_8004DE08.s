.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004DE08
/* 29208 8004DE08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 2920C 8004DE0C AFB20018 */  sw        $s2, 0x18($sp)
/* 29210 8004DE10 0080902D */  daddu     $s2, $a0, $zero
/* 29214 8004DE14 AFB00010 */  sw        $s0, 0x10($sp)
/* 29218 8004DE18 00A0802D */  daddu     $s0, $a1, $zero
/* 2921C 8004DE1C AFB10014 */  sw        $s1, 0x14($sp)
/* 29220 8004DE20 00C0882D */  daddu     $s1, $a2, $zero
/* 29224 8004DE24 3C050002 */  lui       $a1, 2
/* 29228 8004DE28 34A5625A */  ori       $a1, $a1, 0x625a
/* 2922C 8004DE2C 24060030 */  addiu     $a2, $zero, 0x30
/* 29230 8004DE30 AFBF001C */  sw        $ra, 0x1c($sp)
/* 29234 8004DE34 0C01394C */  jal       func_8004E530
/* 29238 8004DE38 AE470000 */   sw       $a3, ($s2)
/* 2923C 8004DE3C 0000282D */  daddu     $a1, $zero, $zero
/* 29240 8004DE40 2404007F */  addiu     $a0, $zero, 0x7f
/* 29244 8004DE44 3C013F80 */  lui       $at, 0x3f80
/* 29248 8004DE48 44810000 */  mtc1      $at, $f0
/* 2924C 8004DE4C 34028000 */  ori       $v0, $zero, 0x8000
/* 29250 8004DE50 AE420048 */  sw        $v0, 0x48($s2)
/* 29254 8004DE54 24023CF0 */  addiu     $v0, $zero, 0x3cf0
/* 29258 8004DE58 AE4200B0 */  sw        $v0, 0xb0($s2)
/* 2925C 8004DE5C 3C027F00 */  lui       $v0, 0x7f00
/* 29260 8004DE60 AE4200C0 */  sw        $v0, 0xc0($s2)
/* 29264 8004DE64 24020001 */  addiu     $v0, $zero, 1
/* 29268 8004DE68 A242022B */  sb        $v0, 0x22b($s2)
/* 2926C 8004DE6C 24020002 */  addiu     $v0, $zero, 2
/* 29270 8004DE70 AE400014 */  sw        $zero, 0x14($s2)
/* 29274 8004DE74 AE400018 */  sw        $zero, 0x18($s2)
/* 29278 8004DE78 AE40001C */  sw        $zero, 0x1c($s2)
/* 2927C 8004DE7C AE400020 */  sw        $zero, 0x20($s2)
/* 29280 8004DE80 A6400058 */  sh        $zero, 0x58($s2)
/* 29284 8004DE84 A640005A */  sh        $zero, 0x5a($s2)
/* 29288 8004DE88 AE400068 */  sw        $zero, 0x68($s2)
/* 2928C 8004DE8C AE40006C */  sw        $zero, 0x6c($s2)
/* 29290 8004DE90 AE400070 */  sw        $zero, 0x70($s2)
/* 29294 8004DE94 AE4000BC */  sw        $zero, 0xbc($s2)
/* 29298 8004DE98 AE4000B8 */  sw        $zero, 0xb8($s2)
/* 2929C 8004DE9C AE4000B4 */  sw        $zero, 0xb4($s2)
/* 292A0 8004DEA0 AE4000CC */  sw        $zero, 0xcc($s2)
/* 292A4 8004DEA4 AE4000C8 */  sw        $zero, 0xc8($s2)
/* 292A8 8004DEA8 AE4000C4 */  sw        $zero, 0xc4($s2)
/* 292AC 8004DEAC A640020C */  sh        $zero, 0x20c($s2)
/* 292B0 8004DEB0 A640020E */  sh        $zero, 0x20e($s2)
/* 292B4 8004DEB4 A2400220 */  sb        $zero, 0x220($s2)
/* 292B8 8004DEB8 AE400204 */  sw        $zero, 0x204($s2)
/* 292BC 8004DEBC A2400232 */  sb        $zero, 0x232($s2)
/* 292C0 8004DEC0 A2400221 */  sb        $zero, 0x221($s2)
/* 292C4 8004DEC4 A2500234 */  sb        $s0, 0x234($s2)
/* 292C8 8004DEC8 A2510235 */  sb        $s1, 0x235($s2)
/* 292CC 8004DECC AE400168 */  sw        $zero, 0x168($s2)
/* 292D0 8004DED0 A2400222 */  sb        $zero, 0x222($s2)
/* 292D4 8004DED4 A2400223 */  sb        $zero, 0x223($s2)
/* 292D8 8004DED8 A240022A */  sb        $zero, 0x22a($s2)
/* 292DC 8004DEDC A240022C */  sb        $zero, 0x22c($s2)
/* 292E0 8004DEE0 E64000D0 */  swc1      $f0, 0xd0($s2)
/* 292E4 8004DEE4 A240022D */  sb        $zero, 0x22d($s2)
/* 292E8 8004DEE8 A242022F */  sb        $v0, 0x22f($s2)
/* 292EC 8004DEEC 24020003 */  addiu     $v0, $zero, 3
/* 292F0 8004DEF0 A2420230 */  sb        $v0, 0x230($s2)
/* 292F4 8004DEF4 24020004 */  addiu     $v0, $zero, 4
/* 292F8 8004DEF8 A240022E */  sb        $zero, 0x22e($s2)
/* 292FC 8004DEFC A2420231 */  sb        $v0, 0x231($s2)
/* 29300 8004DF00 00051400 */  sll       $v0, $a1, 0x10
.L8004DF04:
/* 29304 8004DF04 00021C03 */  sra       $v1, $v0, 0x10
/* 29308 8004DF08 00031040 */  sll       $v0, $v1, 1
/* 2930C 8004DF0C 00431021 */  addu      $v0, $v0, $v1
/* 29310 8004DF10 00021140 */  sll       $v0, $v0, 5
/* 29314 8004DF14 2442025C */  addiu     $v0, $v0, 0x25c
/* 29318 8004DF18 02421021 */  addu      $v0, $s2, $v0
/* 2931C 8004DF1C AC400018 */  sw        $zero, 0x18($v0)
/* 29320 8004DF20 AC400028 */  sw        $zero, 0x28($v0)
/* 29324 8004DF24 A4400046 */  sh        $zero, 0x46($v0)
/* 29328 8004DF28 A0400048 */  sb        $zero, 0x48($v0)
/* 2932C 8004DF2C A040004A */  sb        $zero, 0x4a($v0)
/* 29330 8004DF30 A040004B */  sb        $zero, 0x4b($v0)
/* 29334 8004DF34 A4400044 */  sh        $zero, 0x44($v0)
/* 29338 8004DF38 A0400058 */  sb        $zero, 0x58($v0)
/* 2933C 8004DF3C A0440049 */  sb        $a0, 0x49($v0)
/* 29340 8004DF40 A040004C */  sb        $zero, 0x4c($v0)
/* 29344 8004DF44 28620008 */  slti      $v0, $v1, 8
/* 29348 8004DF48 10400005 */  beqz      $v0, .L8004DF60
/* 2934C 8004DF4C 24A20001 */   addiu    $v0, $a1, 1
/* 29350 8004DF50 00031080 */  sll       $v0, $v1, 2
/* 29354 8004DF54 02421021 */  addu      $v0, $s2, $v0
/* 29358 8004DF58 AC400238 */  sw        $zero, 0x238($v0)
/* 2935C 8004DF5C 24A20001 */  addiu     $v0, $a1, 1
.L8004DF60:
/* 29360 8004DF60 0040282D */  daddu     $a1, $v0, $zero
/* 29364 8004DF64 00021400 */  sll       $v0, $v0, 0x10
/* 29368 8004DF68 00021403 */  sra       $v0, $v0, 0x10
/* 2936C 8004DF6C 28420010 */  slti      $v0, $v0, 0x10
/* 29370 8004DF70 1440FFE4 */  bnez      $v0, .L8004DF04
/* 29374 8004DF74 00051400 */   sll      $v0, $a1, 0x10
/* 29378 8004DF78 0000282D */  daddu     $a1, $zero, $zero
.L8004DF7C:
/* 2937C 8004DF7C 00051400 */  sll       $v0, $a1, 0x10
/* 29380 8004DF80 24A40001 */  addiu     $a0, $a1, 1
/* 29384 8004DF84 0080282D */  daddu     $a1, $a0, $zero
/* 29388 8004DF88 00021403 */  sra       $v0, $v0, 0x10
/* 2938C 8004DF8C 00021840 */  sll       $v1, $v0, 1
/* 29390 8004DF90 00621821 */  addu      $v1, $v1, $v0
/* 29394 8004DF94 000318C0 */  sll       $v1, $v1, 3
/* 29398 8004DF98 2463085C */  addiu     $v1, $v1, 0x85c
/* 2939C 8004DF9C 02431821 */  addu      $v1, $s2, $v1
/* 293A0 8004DFA0 00042400 */  sll       $a0, $a0, 0x10
/* 293A4 8004DFA4 00042403 */  sra       $a0, $a0, 0x10
/* 293A8 8004DFA8 28840018 */  slti      $a0, $a0, 0x18
/* 293AC 8004DFAC A4600008 */  sh        $zero, 8($v1)
/* 293B0 8004DFB0 A460000A */  sh        $zero, 0xa($v1)
/* 293B4 8004DFB4 AC60000C */  sw        $zero, 0xc($v1)
/* 293B8 8004DFB8 A4600014 */  sh        $zero, 0x14($v1)
/* 293BC 8004DFBC A0600016 */  sb        $zero, 0x16($v1)
/* 293C0 8004DFC0 1480FFEE */  bnez      $a0, .L8004DF7C
/* 293C4 8004DFC4 A0600017 */   sb       $zero, 0x17($v1)
/* 293C8 8004DFC8 2644002C */  addiu     $a0, $s2, 0x2c
/* 293CC 8004DFCC 0C014DE7 */  jal       func_8005379C
/* 293D0 8004DFD0 24057FFF */   addiu    $a1, $zero, 0x7fff
/* 293D4 8004DFD4 0C015370 */  jal       func_80054DC0
/* 293D8 8004DFD8 0240202D */   daddu    $a0, $s2, $zero
/* 293DC 8004DFDC 8FBF001C */  lw        $ra, 0x1c($sp)
/* 293E0 8004DFE0 8FB20018 */  lw        $s2, 0x18($sp)
/* 293E4 8004DFE4 8FB10014 */  lw        $s1, 0x14($sp)
/* 293E8 8004DFE8 8FB00010 */  lw        $s0, 0x10($sp)
/* 293EC 8004DFEC 03E00008 */  jr        $ra
/* 293F0 8004DFF0 27BD0020 */   addiu    $sp, $sp, 0x20
