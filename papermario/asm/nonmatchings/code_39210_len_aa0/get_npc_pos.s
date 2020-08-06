.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_npc_pos
/* 039210 8005DE10 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 039214 8005DE14 AFB00010 */  sw    $s0, 0x10($sp)
/* 039218 8005DE18 00A0802D */  daddu $s0, $a1, $zero
/* 03921C 8005DE1C AFB10014 */  sw    $s1, 0x14($sp)
/* 039220 8005DE20 00C0882D */  daddu $s1, $a2, $zero
/* 039224 8005DE24 AFB20018 */  sw    $s2, 0x18($sp)
/* 039228 8005DE28 00E0902D */  daddu $s2, $a3, $zero
/* 03922C 8005DE2C 3C038011 */  lui   $v1, 0x8011
/* 039230 8005DE30 2463EFC8 */  addiu $v1, $v1, -0x1038
/* 039234 8005DE34 AFB3001C */  sw    $s3, 0x1c($sp)
/* 039238 8005DE38 8FB30038 */  lw    $s3, 0x38($sp)
/* 03923C 8005DE3C 2402FFFF */  addiu $v0, $zero, -1
/* 039240 8005DE40 AFBF0020 */  sw    $ra, 0x20($sp)
/* 039244 8005DE44 AE000000 */  sw    $zero, ($s0)
/* 039248 8005DE48 AE200000 */  sw    $zero, ($s1)
/* 03924C 8005DE4C AE400000 */  sw    $zero, ($s2)
/* 039250 8005DE50 1482000A */  bne   $a0, $v0, .L8005DE7C
/* 039254 8005DE54 AE600000 */   sw    $zero, ($s3)
/* 039258 8005DE58 C4600028 */  lwc1  $f0, 0x28($v1)
/* 03925C 8005DE5C E6000000 */  swc1  $f0, ($s0)
/* 039260 8005DE60 C460002C */  lwc1  $f0, 0x2c($v1)
/* 039264 8005DE64 E6200000 */  swc1  $f0, ($s1)
/* 039268 8005DE68 C4600030 */  lwc1  $f0, 0x30($v1)
/* 03926C 8005DE6C E6400000 */  swc1  $f0, ($s2)
/* 039270 8005DE70 8C620000 */  lw    $v0, ($v1)
/* 039274 8005DE74 080177A9 */  j     .L8005DEA4
/* 039278 8005DE78 30420006 */   andi  $v0, $v0, 6

.L8005DE7C:
/* 03927C 8005DE7C 0C00EABB */  jal   get_npc_unsafe
/* 039280 8005DE80 00000000 */   nop   
/* 039284 8005DE84 C4400038 */  lwc1  $f0, 0x38($v0)
/* 039288 8005DE88 E6000000 */  swc1  $f0, ($s0)
/* 03928C 8005DE8C C440003C */  lwc1  $f0, 0x3c($v0)
/* 039290 8005DE90 E6200000 */  swc1  $f0, ($s1)
/* 039294 8005DE94 C4400040 */  lwc1  $f0, 0x40($v0)
/* 039298 8005DE98 E6400000 */  swc1  $f0, ($s2)
/* 03929C 8005DE9C 8C420000 */  lw    $v0, ($v0)
/* 0392A0 8005DEA0 30420800 */  andi  $v0, $v0, 0x800
.L8005DEA4:
/* 0392A4 8005DEA4 10400002 */  beqz  $v0, .L8005DEB0
/* 0392A8 8005DEA8 24020001 */   addiu $v0, $zero, 1
/* 0392AC 8005DEAC AE620000 */  sw    $v0, ($s3)
.L8005DEB0:
/* 0392B0 8005DEB0 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0392B4 8005DEB4 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0392B8 8005DEB8 8FB20018 */  lw    $s2, 0x18($sp)
/* 0392BC 8005DEBC 8FB10014 */  lw    $s1, 0x14($sp)
/* 0392C0 8005DEC0 8FB00010 */  lw    $s0, 0x10($sp)
/* 0392C4 8005DEC4 03E00008 */  jr    $ra
/* 0392C8 8005DEC8 27BD0028 */   addiu $sp, $sp, 0x28

/* 0392CC 8005DECC 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0392D0 8005DED0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0392D4 8005DED4 0080882D */  daddu $s1, $a0, $zero
/* 0392D8 8005DED8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0392DC 8005DEDC 00A0902D */  daddu $s2, $a1, $zero
/* 0392E0 8005DEE0 AFB3001C */  sw    $s3, 0x1c($sp)
/* 0392E4 8005DEE4 00C0982D */  daddu $s3, $a2, $zero
/* 0392E8 8005DEE8 F7B40028 */  sdc1  $f20, 0x28($sp)
/* 0392EC 8005DEEC 4487A000 */  mtc1  $a3, $f20
/* 0392F0 8005DEF0 240402A4 */  addiu $a0, $zero, 0x2a4
/* 0392F4 8005DEF4 AFBF0020 */  sw    $ra, 0x20($sp)
/* 0392F8 8005DEF8 0C00AB39 */  jal   heap_malloc
/* 0392FC 8005DEFC AFB00010 */   sw    $s0, 0x10($sp)
/* 039300 8005DF00 0040202D */  daddu $a0, $v0, $zero
/* 039304 8005DF04 3C108011 */  lui   $s0, 0x8011
/* 039308 8005DF08 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 03930C 8005DF0C 14800003 */  bnez  $a0, .L8005DF1C
/* 039310 8005DF10 AE240020 */   sw    $a0, 0x20($s1)
.L8005DF14:
/* 039314 8005DF14 080177C5 */  j     .L8005DF14
/* 039318 8005DF18 00000000 */   nop   

.L8005DF1C:
/* 03931C 8005DF1C 0000282D */  daddu $a1, $zero, $zero
/* 039320 8005DF20 0080182D */  daddu $v1, $a0, $zero
.L8005DF24:
/* 039324 8005DF24 C6000028 */  lwc1  $f0, 0x28($s0)
/* 039328 8005DF28 E4600004 */  swc1  $f0, 4($v1)
/* 03932C 8005DF2C C600002C */  lwc1  $f0, 0x2c($s0)
/* 039330 8005DF30 24A50001 */  addiu $a1, $a1, 1
/* 039334 8005DF34 E4600008 */  swc1  $f0, 8($v1)
/* 039338 8005DF38 C6000030 */  lwc1  $f0, 0x30($s0)
/* 03933C 8005DF3C 28A20028 */  slti  $v0, $a1, 0x28
/* 039340 8005DF40 A0600000 */  sb    $zero, ($v1)
/* 039344 8005DF44 E460000C */  swc1  $f0, 0xc($v1)
/* 039348 8005DF48 1440FFF6 */  bnez  $v0, .L8005DF24
/* 03934C 8005DF4C 24630010 */   addiu $v1, $v1, 0x10
/* 039350 8005DF50 AC800280 */  sw    $zero, 0x280($a0)
/* 039354 8005DF54 AC800284 */  sw    $zero, 0x284($a0)
/* 039358 8005DF58 AC800288 */  sw    $zero, 0x288($a0)
/* 03935C 8005DF5C AC92028C */  sw    $s2, 0x28c($a0)
/* 039360 8005DF60 AC930290 */  sw    $s3, 0x290($a0)
/* 039364 8005DF64 E4940294 */  swc1  $f20, 0x294($a0)
/* 039368 8005DF68 C7A00040 */  lwc1  $f0, 0x40($sp)
/* 03936C 8005DF6C 0260102D */  daddu $v0, $s3, $zero
/* 039370 8005DF70 E4800298 */  swc1  $f0, 0x298($a0)
/* 039374 8005DF74 C7A00044 */  lwc1  $f0, 0x44($sp)
/* 039378 8005DF78 46800020 */  cvt.s.w $f0, $f0
/* 03937C 8005DF7C E480029C */  swc1  $f0, 0x29c($a0)
/* 039380 8005DF80 C7A00048 */  lwc1  $f0, 0x48($sp)
/* 039384 8005DF84 46800020 */  cvt.s.w $f0, $f0
/* 039388 8005DF88 E48002A0 */  swc1  $f0, 0x2a0($a0)
/* 03938C 8005DF8C 8C440010 */  lw    $a0, 0x10($v0)
/* 039390 8005DF90 8E220000 */  lw    $v0, ($s1)
/* 039394 8005DF94 2403FEFF */  addiu $v1, $zero, -0x101
/* 039398 8005DF98 AE20001C */  sw    $zero, 0x1c($s1)
/* 03939C 8005DF9C 34420200 */  ori   $v0, $v0, 0x200
/* 0393A0 8005DFA0 00431024 */  and   $v0, $v0, $v1
/* 0393A4 8005DFA4 AE220000 */  sw    $v0, ($s1)
/* 0393A8 8005DFA8 3C020001 */  lui   $v0, 1
/* 0393AC 8005DFAC AE220080 */  sw    $v0, 0x80($s1)
/* 0393B0 8005DFB0 AE240028 */  sw    $a0, 0x28($s1)
/* 0393B4 8005DFB4 8FBF0020 */  lw    $ra, 0x20($sp)
/* 0393B8 8005DFB8 8FB3001C */  lw    $s3, 0x1c($sp)
/* 0393BC 8005DFBC 8FB20018 */  lw    $s2, 0x18($sp)
/* 0393C0 8005DFC0 8FB10014 */  lw    $s1, 0x14($sp)
/* 0393C4 8005DFC4 8FB00010 */  lw    $s0, 0x10($sp)
/* 0393C8 8005DFC8 D7B40028 */  ldc1  $f20, 0x28($sp)
/* 0393CC 8005DFCC 03E00008 */  jr    $ra
/* 0393D0 8005DFD0 27BD0030 */   addiu $sp, $sp, 0x30

/* 0393D4 8005DFD4 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 0393D8 8005DFD8 AFB20030 */  sw    $s2, 0x30($sp)
/* 0393DC 8005DFDC 0080902D */  daddu $s2, $a0, $zero
/* 0393E0 8005DFE0 27A6001C */  addiu $a2, $sp, 0x1c
/* 0393E4 8005DFE4 27A70020 */  addiu $a3, $sp, 0x20
/* 0393E8 8005DFE8 AFBF0038 */  sw    $ra, 0x38($sp)
/* 0393EC 8005DFEC AFB30034 */  sw    $s3, 0x34($sp)
/* 0393F0 8005DFF0 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0393F4 8005DFF4 AFB00028 */  sw    $s0, 0x28($sp)
/* 0393F8 8005DFF8 8E510020 */  lw    $s1, 0x20($s2)
/* 0393FC 8005DFFC 27A20024 */  addiu $v0, $sp, 0x24
/* 039400 8005E000 AFA20010 */  sw    $v0, 0x10($sp)
/* 039404 8005E004 8E24028C */  lw    $a0, 0x28c($s1)
/* 039408 8005E008 0C017784 */  jal   get_npc_pos
/* 03940C 8005E00C 27A50018 */   addiu $a1, $sp, 0x18
/* 039410 8005E010 8E220280 */  lw    $v0, 0x280($s1)
/* 039414 8005E014 00021100 */  sll   $v0, $v0, 4
/* 039418 8005E018 02228021 */  addu  $s0, $s1, $v0
/* 03941C 8005E01C 8FA20024 */  lw    $v0, 0x24($sp)
/* 039420 8005E020 82030000 */  lb    $v1, ($s0)
/* 039424 8005E024 10600003 */  beqz  $v1, .L8005E034
/* 039428 8005E028 0002982B */   sltu  $s3, $zero, $v0
/* 03942C 8005E02C 16600038 */  bnez  $s3, .L8005E110
/* 039430 8005E030 00000000 */   nop   
.L8005E034:
/* 039434 8005E034 1660000E */  bnez  $s3, .L8005E070
/* 039438 8005E038 00000000 */   nop   
/* 03943C 8005E03C 8FA60018 */  lw    $a2, 0x18($sp)
/* 039440 8005E040 8FA70020 */  lw    $a3, 0x20($sp)
/* 039444 8005E044 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039448 8005E048 0C00A7B5 */  jal   dist2D
/* 03944C 8005E04C C64E0040 */   lwc1  $f14, 0x40($s2)
/* 039450 8005E050 C622029C */  lwc1  $f2, 0x29c($s1)
/* 039454 8005E054 4602003E */  c.le.s $f0, $f2
/* 039458 8005E058 00000000 */  nop   
/* 03945C 8005E05C 45000004 */  bc1f  .L8005E070
/* 039460 8005E060 00000000 */   nop   
/* 039464 8005E064 82020000 */  lb    $v0, ($s0)
/* 039468 8005E068 10400029 */  beqz  $v0, .L8005E110
/* 03946C 8005E06C 00000000 */   nop   
.L8005E070:
/* 039470 8005E070 8E220280 */  lw    $v0, 0x280($s1)
/* 039474 8005E074 C7A00018 */  lwc1  $f0, 0x18($sp)
/* 039478 8005E078 00021100 */  sll   $v0, $v0, 4
/* 03947C 8005E07C 02228021 */  addu  $s0, $s1, $v0
/* 039480 8005E080 C6020004 */  lwc1  $f2, 4($s0)
/* 039484 8005E084 46001032 */  c.eq.s $f2, $f0
/* 039488 8005E088 00000000 */  nop   
/* 03948C 8005E08C 4500000D */  bc1f  .L8005E0C4
/* 039490 8005E090 00000000 */   nop   
/* 039494 8005E094 C6020008 */  lwc1  $f2, 8($s0)
/* 039498 8005E098 C7A0001C */  lwc1  $f0, 0x1c($sp)
/* 03949C 8005E09C 46001032 */  c.eq.s $f2, $f0
/* 0394A0 8005E0A0 00000000 */  nop   
/* 0394A4 8005E0A4 45000007 */  bc1f  .L8005E0C4
/* 0394A8 8005E0A8 00000000 */   nop   
/* 0394AC 8005E0AC C602000C */  lwc1  $f2, 0xc($s0)
/* 0394B0 8005E0B0 C7A00020 */  lwc1  $f0, 0x20($sp)
/* 0394B4 8005E0B4 46001032 */  c.eq.s $f2, $f0
/* 0394B8 8005E0B8 00000000 */  nop   
/* 0394BC 8005E0BC 45010014 */  bc1t  .L8005E110
/* 0394C0 8005E0C0 00000000 */   nop   
.L8005E0C4:
/* 0394C4 8005E0C4 8E220280 */  lw    $v0, 0x280($s1)
/* 0394C8 8005E0C8 8E230284 */  lw    $v1, 0x284($s1)
/* 0394CC 8005E0CC 24420001 */  addiu $v0, $v0, 1
/* 0394D0 8005E0D0 1062000F */  beq   $v1, $v0, .L8005E110
/* 0394D4 8005E0D4 00000000 */   nop   
/* 0394D8 8005E0D8 AE220280 */  sw    $v0, 0x280($s1)
/* 0394DC 8005E0DC 28420028 */  slti  $v0, $v0, 0x28
/* 0394E0 8005E0E0 50400001 */  beql  $v0, $zero, .L8005E0E8
/* 0394E4 8005E0E4 AE200280 */   sw    $zero, 0x280($s1)
.L8005E0E8:
/* 0394E8 8005E0E8 8E220280 */  lw    $v0, 0x280($s1)
/* 0394EC 8005E0EC C7A00018 */  lwc1  $f0, 0x18($sp)
/* 0394F0 8005E0F0 C7A2001C */  lwc1  $f2, 0x1c($sp)
/* 0394F4 8005E0F4 C7A40020 */  lwc1  $f4, 0x20($sp)
/* 0394F8 8005E0F8 00021100 */  sll   $v0, $v0, 4
/* 0394FC 8005E0FC 02228021 */  addu  $s0, $s1, $v0
/* 039500 8005E100 E6000004 */  swc1  $f0, 4($s0)
/* 039504 8005E104 E6020008 */  swc1  $f2, 8($s0)
/* 039508 8005E108 E604000C */  swc1  $f4, 0xc($s0)
/* 03950C 8005E10C A2130000 */  sb    $s3, ($s0)
.L8005E110:
/* 039510 8005E110 8FBF0038 */  lw    $ra, 0x38($sp)
/* 039514 8005E114 8FB30034 */  lw    $s3, 0x34($sp)
/* 039518 8005E118 8FB20030 */  lw    $s2, 0x30($sp)
/* 03951C 8005E11C 8FB1002C */  lw    $s1, 0x2c($sp)
/* 039520 8005E120 8FB00028 */  lw    $s0, 0x28($sp)
/* 039524 8005E124 03E00008 */  jr    $ra
/* 039528 8005E128 27BD0040 */   addiu $sp, $sp, 0x40

/* 03952C 8005E12C 27BDFF98 */  addiu $sp, $sp, -0x68
/* 039530 8005E130 AFB20040 */  sw    $s2, 0x40($sp)
/* 039534 8005E134 0080902D */  daddu $s2, $a0, $zero
/* 039538 8005E138 27A50018 */  addiu $a1, $sp, 0x18
/* 03953C 8005E13C 27A6001C */  addiu $a2, $sp, 0x1c
/* 039540 8005E140 AFBF0044 */  sw    $ra, 0x44($sp)
/* 039544 8005E144 AFB1003C */  sw    $s1, 0x3c($sp)
/* 039548 8005E148 AFB00038 */  sw    $s0, 0x38($sp)
/* 03954C 8005E14C F7BA0060 */  sdc1  $f26, 0x60($sp)
/* 039550 8005E150 F7B80058 */  sdc1  $f24, 0x58($sp)
/* 039554 8005E154 F7B60050 */  sdc1  $f22, 0x50($sp)
/* 039558 8005E158 F7B40048 */  sdc1  $f20, 0x48($sp)
/* 03955C 8005E15C 8E510020 */  lw    $s1, 0x20($s2)
/* 039560 8005E160 27A20024 */  addiu $v0, $sp, 0x24
/* 039564 8005E164 AFA20010 */  sw    $v0, 0x10($sp)
/* 039568 8005E168 8E24028C */  lw    $a0, 0x28c($s1)
/* 03956C 8005E16C 0C017784 */  jal   get_npc_pos
/* 039570 8005E170 27A70020 */   addiu $a3, $sp, 0x20
/* 039574 8005E174 8E230288 */  lw    $v1, 0x288($s1)
/* 039578 8005E178 24020001 */  addiu $v0, $zero, 1
/* 03957C 8005E17C 106200A4 */  beq   $v1, $v0, .L8005E410
/* 039580 8005E180 28620002 */   slti  $v0, $v1, 2
/* 039584 8005E184 50400005 */  beql  $v0, $zero, .L8005E19C
/* 039588 8005E188 24020002 */   addiu $v0, $zero, 2
/* 03958C 8005E18C 10600015 */  beqz  $v1, .L8005E1E4
/* 039590 8005E190 00000000 */   nop   
/* 039594 8005E194 08017A20 */  j     .L8005E880
/* 039598 8005E198 00000000 */   nop   

.L8005E19C:
/* 03959C 8005E19C 10620104 */  beq   $v1, $v0, .L8005E5B0
/* 0395A0 8005E1A0 2402000A */   addiu $v0, $zero, 0xa
/* 0395A4 8005E1A4 1062014C */  beq   $v1, $v0, .L8005E6D8
/* 0395A8 8005E1A8 00000000 */   nop   
/* 0395AC 8005E1AC 08017A20 */  j     .L8005E880
/* 0395B0 8005E1B0 00000000 */   nop   

.L8005E1B4:
/* 0395B4 8005E1B4 8E220290 */  lw    $v0, 0x290($s1)
/* 0395B8 8005E1B8 C658000C */  lwc1  $f24, 0xc($s2)
/* 0395BC 8005E1BC 8C420010 */  lw    $v0, 0x10($v0)
/* 0395C0 8005E1C0 080178ED */  j     .L8005E3B4
/* 0395C4 8005E1C4 AE420028 */   sw    $v0, 0x28($s2)

.L8005E1C8:
/* 0395C8 8005E1C8 AE400018 */  sw    $zero, 0x18($s2)
/* 0395CC 8005E1CC 8E220290 */  lw    $v0, 0x290($s1)
/* 0395D0 8005E1D0 C658000C */  lwc1  $f24, 0xc($s2)
/* 0395D4 8005E1D4 8C420010 */  lw    $v0, 0x10($v0)
/* 0395D8 8005E1D8 AE420028 */  sw    $v0, 0x28($s2)
/* 0395DC 8005E1DC 080178EC */  j     .L8005E3B0
/* 0395E0 8005E1E0 2402000A */   addiu $v0, $zero, 0xa

.L8005E1E4:
/* 0395E4 8005E1E4 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 0395E8 8005E1E8 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 0395EC 8005E1EC 8FA60018 */  lw    $a2, 0x18($sp)
/* 0395F0 8005E1F0 8E220284 */  lw    $v0, 0x284($s1)
/* 0395F4 8005E1F4 8FA70020 */  lw    $a3, 0x20($sp)
/* 0395F8 8005E1F8 C642003C */  lwc1  $f2, 0x3c($s2)
/* 0395FC 8005E1FC C6260294 */  lwc1  $f6, 0x294($s1)
/* 039600 8005E200 00021100 */  sll   $v0, $v0, 4
/* 039604 8005E204 02228021 */  addu  $s0, $s1, $v0
/* 039608 8005E208 46006006 */  mov.s $f0, $f12
/* 03960C 8005E20C C6160004 */  lwc1  $f22, 4($s0)
/* 039610 8005E210 C614000C */  lwc1  $f20, 0xc($s0)
/* 039614 8005E214 46007106 */  mov.s $f4, $f14
/* 039618 8005E218 E7A00028 */  swc1  $f0, 0x28($sp)
/* 03961C 8005E21C E7A2002C */  swc1  $f2, 0x2c($sp)
/* 039620 8005E220 E7A40030 */  swc1  $f4, 0x30($sp)
/* 039624 8005E224 0C00A7B5 */  jal   dist2D
/* 039628 8005E228 E6460018 */   swc1  $f6, 0x18($s2)
/* 03962C 8005E22C C62202A0 */  lwc1  $f2, 0x2a0($s1)
/* 039630 8005E230 4600103E */  c.le.s $f2, $f0
/* 039634 8005E234 00000000 */  nop   
/* 039638 8005E238 45000003 */  bc1f  .L8005E248
/* 03963C 8005E23C E7A00034 */   swc1  $f0, 0x34($sp)
/* 039640 8005E240 C6200298 */  lwc1  $f0, 0x298($s1)
/* 039644 8005E244 E6400018 */  swc1  $f0, 0x18($s2)
.L8005E248:
/* 039648 8005E248 8E220290 */  lw    $v0, 0x290($s1)
/* 03964C 8005E24C 8C430014 */  lw    $v1, 0x14($v0)
/* 039650 8005E250 8E420000 */  lw    $v0, ($s2)
/* 039654 8005E254 30421000 */  andi  $v0, $v0, 0x1000
/* 039658 8005E258 14400004 */  bnez  $v0, .L8005E26C
/* 03965C 8005E25C AE430028 */   sw    $v1, 0x28($s2)
/* 039660 8005E260 8E220290 */  lw    $v0, 0x290($s1)
/* 039664 8005E264 8C420008 */  lw    $v0, 8($v0)
/* 039668 8005E268 AE420028 */  sw    $v0, 0x28($s2)
.L8005E26C:
/* 03966C 8005E26C C7AC0028 */  lwc1  $f12, 0x28($sp)
/* 039670 8005E270 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 039674 8005E274 4406B000 */  mfc1  $a2, $f22
/* 039678 8005E278 4407A000 */  mfc1  $a3, $f20
/* 03967C 8005E27C 0C00A7B5 */  jal   dist2D
/* 039680 8005E280 00000000 */   nop   
/* 039684 8005E284 C7AC0028 */  lwc1  $f12, 0x28($sp)
/* 039688 8005E288 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 03968C 8005E28C 4406B000 */  mfc1  $a2, $f22
/* 039690 8005E290 4407A000 */  mfc1  $a3, $f20
/* 039694 8005E294 0C00A720 */  jal   atan2
/* 039698 8005E298 E7A00034 */   swc1  $f0, 0x34($sp)
/* 03969C 8005E29C C6440018 */  lwc1  $f4, 0x18($s2)
/* 0396A0 8005E2A0 C7A20034 */  lwc1  $f2, 0x34($sp)
/* 0396A4 8005E2A4 4602203C */  c.lt.s $f4, $f2
/* 0396A8 8005E2A8 00000000 */  nop   
/* 0396AC 8005E2AC 45000020 */  bc1f  .L8005E330
/* 0396B0 8005E2B0 46000606 */   mov.s $f24, $f0
/* 0396B4 8005E2B4 C7AC0028 */  lwc1  $f12, 0x28($sp)
/* 0396B8 8005E2B8 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 0396BC 8005E2BC 8FA60018 */  lw    $a2, 0x18($sp)
/* 0396C0 8005E2C0 0C00A7B5 */  jal   dist2D
/* 0396C4 8005E2C4 8FA70020 */   lw    $a3, 0x20($sp)
/* 0396C8 8005E2C8 E7A00034 */  swc1  $f0, 0x34($sp)
/* 0396CC 8005E2CC C62202A0 */  lwc1  $f2, 0x2a0($s1)
/* 0396D0 8005E2D0 4600103C */  c.lt.s $f2, $f0
/* 0396D4 8005E2D4 00000000 */  nop   
/* 0396D8 8005E2D8 45010036 */  bc1t  .L8005E3B4
/* 0396DC 8005E2DC 00000000 */   nop   
/* 0396E0 8005E2E0 C622029C */  lwc1  $f2, 0x29c($s1)
/* 0396E4 8005E2E4 4600103C */  c.lt.s $f2, $f0
/* 0396E8 8005E2E8 00000000 */  nop   
/* 0396EC 8005E2EC 45000010 */  bc1f  .L8005E330
/* 0396F0 8005E2F0 00000000 */   nop   
/* 0396F4 8005E2F4 46020001 */  sub.s $f0, $f0, $f2
/* 0396F8 8005E2F8 E6400018 */  swc1  $f0, 0x18($s2)
/* 0396FC 8005E2FC C6220294 */  lwc1  $f2, 0x294($s1)
/* 039700 8005E300 4600103C */  c.lt.s $f2, $f0
/* 039704 8005E304 00000000 */  nop   
/* 039708 8005E308 4503002A */  bc1tl .L8005E3B4
/* 03970C 8005E30C E6420018 */   swc1  $f2, 0x18($s2)
/* 039710 8005E310 3C013FF0 */  lui   $at, 0x3ff0
/* 039714 8005E314 44811800 */  mtc1  $at, $f3
/* 039718 8005E318 44801000 */  mtc1  $zero, $f2
/* 03971C 8005E31C 46000021 */  cvt.d.s $f0, $f0
/* 039720 8005E320 46220000 */  add.d $f0, $f0, $f2
/* 039724 8005E324 46200020 */  cvt.s.d $f0, $f0
/* 039728 8005E328 080178ED */  j     .L8005E3B4
/* 03972C 8005E32C E6400018 */   swc1  $f0, 0x18($s2)

.L8005E330:
/* 039730 8005E330 8E230284 */  lw    $v1, 0x284($s1)
/* 039734 8005E334 8E220280 */  lw    $v0, 0x280($s1)
/* 039738 8005E338 5062FF9E */  beql  $v1, $v0, .L8005E1B4
/* 03973C 8005E33C AE400018 */   sw    $zero, 0x18($s2)
/* 039740 8005E340 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039744 8005E344 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039748 8005E348 8FA60018 */  lw    $a2, 0x18($sp)
/* 03974C 8005E34C 0C00A7B5 */  jal   dist2D
/* 039750 8005E350 8FA70020 */   lw    $a3, 0x20($sp)
/* 039754 8005E354 C622029C */  lwc1  $f2, 0x29c($s1)
/* 039758 8005E358 4602003E */  c.le.s $f0, $f2
/* 03975C 8005E35C 00000000 */  nop   
/* 039760 8005E360 4501FF99 */  bc1t  .L8005E1C8
/* 039764 8005E364 E7A00034 */   swc1  $f0, 0x34($sp)
/* 039768 8005E368 8E220284 */  lw    $v0, 0x284($s1)
/* 03976C 8005E36C 24420001 */  addiu $v0, $v0, 1
/* 039770 8005E370 AE220284 */  sw    $v0, 0x284($s1)
/* 039774 8005E374 28420028 */  slti  $v0, $v0, 0x28
/* 039778 8005E378 50400001 */  beql  $v0, $zero, .L8005E380
/* 03977C 8005E37C AE200284 */   sw    $zero, 0x284($s1)
.L8005E380:
/* 039780 8005E380 8E220284 */  lw    $v0, 0x284($s1)
/* 039784 8005E384 00021100 */  sll   $v0, $v0, 4
/* 039788 8005E388 02228021 */  addu  $s0, $s1, $v0
/* 03978C 8005E38C C6160004 */  lwc1  $f22, 4($s0)
/* 039790 8005E390 8E420000 */  lw    $v0, ($s2)
/* 039794 8005E394 C614000C */  lwc1  $f20, 0xc($s0)
/* 039798 8005E398 30421000 */  andi  $v0, $v0, 0x1000
/* 03979C 8005E39C 1040FFB3 */  beqz  $v0, .L8005E26C
/* 0397A0 8005E3A0 00000000 */   nop   
/* 0397A4 8005E3A4 82020000 */  lb    $v0, ($s0)
/* 0397A8 8005E3A8 1040FFB0 */  beqz  $v0, .L8005E26C
/* 0397AC 8005E3AC 24020001 */   addiu $v0, $zero, 1
.L8005E3B0:
/* 0397B0 8005E3B0 AE220288 */  sw    $v0, 0x288($s1)
.L8005E3B4:
/* 0397B4 8005E3B4 8E420000 */  lw    $v0, ($s2)
/* 0397B8 8005E3B8 30421000 */  andi  $v0, $v0, 0x1000
/* 0397BC 8005E3BC 14400008 */  bnez  $v0, .L8005E3E0
/* 0397C0 8005E3C0 00000000 */   nop   
/* 0397C4 8005E3C4 C6400018 */  lwc1  $f0, 0x18($s2)
/* 0397C8 8005E3C8 3C013F00 */  lui   $at, 0x3f00
/* 0397CC 8005E3CC 44811000 */  mtc1  $at, $f2
/* 0397D0 8005E3D0 00000000 */  nop   
/* 0397D4 8005E3D4 46020002 */  mul.s $f0, $f0, $f2
/* 0397D8 8005E3D8 00000000 */  nop   
/* 0397DC 8005E3DC E6400018 */  swc1  $f0, 0x18($s2)
.L8005E3E0:
/* 0397E0 8005E3E0 8E450018 */  lw    $a1, 0x18($s2)
/* 0397E4 8005E3E4 4406C000 */  mfc1  $a2, $f24
/* 0397E8 8005E3E8 0240202D */  daddu $a0, $s2, $zero
/* 0397EC 8005E3EC 0C00EA95 */  jal   npc_move_heading
/* 0397F0 8005E3F0 AE46000C */   sw    $a2, 0xc($s2)
/* 0397F4 8005E3F4 8E420000 */  lw    $v0, ($s2)
/* 0397F8 8005E3F8 24035000 */  addiu $v1, $zero, 0x5000
/* 0397FC 8005E3FC 30425000 */  andi  $v0, $v0, 0x5000
/* 039800 8005E400 1443011F */  bne   $v0, $v1, .L8005E880
/* 039804 8005E404 24020001 */   addiu $v0, $zero, 1
/* 039808 8005E408 08017A20 */  j     .L8005E880
/* 03980C 8005E40C AE220288 */   sw    $v0, 0x288($s1)

.L8005E410:
/* 039810 8005E410 8E230284 */  lw    $v1, 0x284($s1)
/* 039814 8005E414 8E220280 */  lw    $v0, 0x280($s1)
/* 039818 8005E418 10620119 */  beq   $v1, $v0, .L8005E880
/* 03981C 8005E41C 24620001 */   addiu $v0, $v1, 1
/* 039820 8005E420 AE220284 */  sw    $v0, 0x284($s1)
/* 039824 8005E424 28420028 */  slti  $v0, $v0, 0x28
/* 039828 8005E428 50400001 */  beql  $v0, $zero, .L8005E430
/* 03982C 8005E42C AE200284 */   sw    $zero, 0x284($s1)
.L8005E430:
/* 039830 8005E430 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039834 8005E434 8E220284 */  lw    $v0, 0x284($s1)
/* 039838 8005E438 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 03983C 8005E43C 3C014000 */  lui   $at, 0x4000
/* 039840 8005E440 44810000 */  mtc1  $at, $f0
/* 039844 8005E444 00021100 */  sll   $v0, $v0, 4
/* 039848 8005E448 02228021 */  addu  $s0, $s1, $v0
/* 03984C 8005E44C C6160004 */  lwc1  $f22, 4($s0)
/* 039850 8005E450 C614000C */  lwc1  $f20, 0xc($s0)
/* 039854 8005E454 C6020008 */  lwc1  $f2, 8($s0)
/* 039858 8005E458 A640008E */  sh    $zero, 0x8e($s2)
/* 03985C 8005E45C E6400014 */  swc1  $f0, 0x14($s2)
/* 039860 8005E460 E6560060 */  swc1  $f22, 0x60($s2)
/* 039864 8005E464 E6540068 */  swc1  $f20, 0x68($s2)
/* 039868 8005E468 E6420064 */  swc1  $f2, 0x64($s2)
/* 03986C 8005E46C C6200298 */  lwc1  $f0, 0x298($s1)
/* 039870 8005E470 4406B000 */  mfc1  $a2, $f22
/* 039874 8005E474 4407A000 */  mfc1  $a3, $f20
/* 039878 8005E478 0C00A7B5 */  jal   dist2D
/* 03987C 8005E47C E6400018 */   swc1  $f0, 0x18($s2)
/* 039880 8005E480 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039884 8005E484 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039888 8005E488 8E460060 */  lw    $a2, 0x60($s2)
/* 03988C 8005E48C 8E470068 */  lw    $a3, 0x68($s2)
/* 039890 8005E490 0C00A720 */  jal   atan2
/* 039894 8005E494 E6400010 */   swc1  $f0, 0x10($s2)
/* 039898 8005E498 C6480010 */  lwc1  $f8, 0x10($s2)
/* 03989C 8005E49C C6440064 */  lwc1  $f4, 0x64($s2)
/* 0398A0 8005E4A0 C642003C */  lwc1  $f2, 0x3c($s2)
/* 0398A4 8005E4A4 E640000C */  swc1  $f0, 0xc($s2)
/* 0398A8 8005E4A8 46022101 */  sub.s $f4, $f4, $f2
/* 0398AC 8005E4AC 46004186 */  mov.s $f6, $f8
/* 0398B0 8005E4B0 E7A80034 */  swc1  $f8, 0x34($sp)
/* 0398B4 8005E4B4 4604303C */  c.lt.s $f6, $f4
/* 0398B8 8005E4B8 00000000 */  nop   
/* 0398BC 8005E4BC 45000002 */  bc1f  .L8005E4C8
/* 0398C0 8005E4C0 E7A4002C */   swc1  $f4, 0x2c($sp)
/* 0398C4 8005E4C4 E7A40034 */  swc1  $f4, 0x34($sp)
.L8005E4C8:
/* 0398C8 8005E4C8 C620029C */  lwc1  $f0, 0x29c($s1)
/* 0398CC 8005E4CC C7A20034 */  lwc1  $f2, 0x34($sp)
/* 0398D0 8005E4D0 4600103C */  c.lt.s $f2, $f0
/* 0398D4 8005E4D4 00000000 */  nop   
/* 0398D8 8005E4D8 4500000A */  bc1f  .L8005E504
/* 0398DC 8005E4DC 00000000 */   nop   
/* 0398E0 8005E4E0 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 0398E4 8005E4E4 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 0398E8 8005E4E8 8FA60018 */  lw    $a2, 0x18($sp)
/* 0398EC 8005E4EC 8FA70020 */  lw    $a3, 0x20($sp)
/* 0398F0 8005E4F0 8E420000 */  lw    $v0, ($s2)
/* 0398F4 8005E4F4 AE40001C */  sw    $zero, 0x1c($s2)
/* 0398F8 8005E4F8 34420200 */  ori   $v0, $v0, 0x200
/* 0398FC 8005E4FC 080179B1 */  j     .L8005E6C4
/* 039900 8005E500 AE420000 */   sw    $v0, ($s2)

.L8005E504:
/* 039904 8005E504 C6400018 */  lwc1  $f0, 0x18($s2)
/* 039908 8005E508 46001003 */  div.s $f0, $f2, $f0
/* 03990C 8005E50C 4600028D */  trunc.w.s $f10, $f0
/* 039910 8005E510 44025000 */  mfc1  $v0, $f10
/* 039914 8005E514 00000000 */  nop   
/* 039918 8005E518 A642008E */  sh    $v0, 0x8e($s2)
/* 03991C 8005E51C 00021400 */  sll   $v0, $v0, 0x10
/* 039920 8005E520 00021403 */  sra   $v0, $v0, 0x10
/* 039924 8005E524 2842000A */  slti  $v0, $v0, 0xa
/* 039928 8005E528 10400002 */  beqz  $v0, .L8005E534
/* 03992C 8005E52C 2402000A */   addiu $v0, $zero, 0xa
/* 039930 8005E530 A642008E */  sh    $v0, 0x8e($s2)
.L8005E534:
/* 039934 8005E534 8642008E */  lh    $v0, 0x8e($s2)
/* 039938 8005E538 C6420014 */  lwc1  $f2, 0x14($s2)
/* 03993C 8005E53C 44823000 */  mtc1  $v0, $f6
/* 039940 8005E540 00000000 */  nop   
/* 039944 8005E544 468031A0 */  cvt.s.w $f6, $f6
/* 039948 8005E548 46061082 */  mul.s $f2, $f2, $f6
/* 03994C 8005E54C 00000000 */  nop   
/* 039950 8005E550 46061082 */  mul.s $f2, $f2, $f6
/* 039954 8005E554 00000000 */  nop   
/* 039958 8005E558 3C013F00 */  lui   $at, 0x3f00
/* 03995C 8005E55C 44810000 */  mtc1  $at, $f0
/* 039960 8005E560 00000000 */  nop   
/* 039964 8005E564 46001082 */  mul.s $f2, $f2, $f0
/* 039968 8005E568 00000000 */  nop   
/* 03996C 8005E56C 2404FDFF */  addiu $a0, $zero, -0x201
/* 039970 8005E570 C7A4002C */  lwc1  $f4, 0x2c($sp)
/* 039974 8005E574 46003206 */  mov.s $f8, $f6
/* 039978 8005E578 C6400010 */  lwc1  $f0, 0x10($s2)
/* 03997C 8005E57C 46022100 */  add.s $f4, $f4, $f2
/* 039980 8005E580 46080003 */  div.s $f0, $f0, $f8
/* 039984 8005E584 E6400018 */  swc1  $f0, 0x18($s2)
/* 039988 8005E588 46062103 */  div.s $f4, $f4, $f6
/* 03998C 8005E58C E644001C */  swc1  $f4, 0x1c($s2)
/* 039990 8005E590 8E230290 */  lw    $v1, 0x290($s1)
/* 039994 8005E594 8E420000 */  lw    $v0, ($s2)
/* 039998 8005E598 8C630004 */  lw    $v1, 4($v1)
/* 03999C 8005E59C 00441024 */  and   $v0, $v0, $a0
/* 0399A0 8005E5A0 AE420000 */  sw    $v0, ($s2)
/* 0399A4 8005E5A4 24020002 */  addiu $v0, $zero, 2
/* 0399A8 8005E5A8 08017A1F */  j     .L8005E87C
/* 0399AC 8005E5AC AE430028 */   sw    $v1, 0x28($s2)

.L8005E5B0:
/* 0399B0 8005E5B0 C640001C */  lwc1  $f0, 0x1c($s2)
/* 0399B4 8005E5B4 C6420014 */  lwc1  $f2, 0x14($s2)
/* 0399B8 8005E5B8 46020001 */  sub.s $f0, $f0, $f2
/* 0399BC 8005E5BC C642003C */  lwc1  $f2, 0x3c($s2)
/* 0399C0 8005E5C0 46001080 */  add.s $f2, $f2, $f0
/* 0399C4 8005E5C4 4480B000 */  mtc1  $zero, $f22
/* 0399C8 8005E5C8 00000000 */  nop   
/* 0399CC 8005E5CC 4616003E */  c.le.s $f0, $f22
/* 0399D0 8005E5D0 E640001C */  swc1  $f0, 0x1c($s2)
/* 0399D4 8005E5D4 45000004 */  bc1f  .L8005E5E8
/* 0399D8 8005E5D8 E642003C */   swc1  $f2, 0x3c($s2)
/* 0399DC 8005E5DC 8E220290 */  lw    $v0, 0x290($s1)
/* 0399E0 8005E5E0 8C420008 */  lw    $v0, 8($v0)
/* 0399E4 8005E5E4 AE420028 */  sw    $v0, 0x28($s2)
.L8005E5E8:
/* 0399E8 8005E5E8 8E450018 */  lw    $a1, 0x18($s2)
/* 0399EC 8005E5EC 8E46000C */  lw    $a2, 0xc($s2)
/* 0399F0 8005E5F0 0C00EA95 */  jal   npc_move_heading
/* 0399F4 8005E5F4 0240202D */   daddu $a0, $s2, $zero
/* 0399F8 8005E5F8 C640001C */  lwc1  $f0, 0x1c($s2)
/* 0399FC 8005E5FC 4616003E */  c.le.s $f0, $f22
/* 039A00 8005E600 00000000 */  nop   
/* 039A04 8005E604 4500009E */  bc1f  .L8005E880
/* 039A08 8005E608 27A50028 */   addiu $a1, $sp, 0x28
/* 039A0C 8005E60C 46000005 */  abs.s $f0, $f0
/* 039A10 8005E610 46000021 */  cvt.d.s $f0, $f0
/* 039A14 8005E614 27A6002C */  addiu $a2, $sp, 0x2c
/* 039A18 8005E618 27A20034 */  addiu $v0, $sp, 0x34
/* 039A1C 8005E61C 3C014020 */  lui   $at, 0x4020
/* 039A20 8005E620 4481A800 */  mtc1  $at, $f21
/* 039A24 8005E624 4480A000 */  mtc1  $zero, $f20
/* 039A28 8005E628 C6420038 */  lwc1  $f2, 0x38($s2)
/* 039A2C 8005E62C 46340000 */  add.d $f0, $f0, $f20
/* 039A30 8005E630 E7A20028 */  swc1  $f2, 0x28($sp)
/* 039A34 8005E634 C642003C */  lwc1  $f2, 0x3c($s2)
/* 039A38 8005E638 C6440040 */  lwc1  $f4, 0x40($s2)
/* 039A3C 8005E63C 46200020 */  cvt.s.d $f0, $f0
/* 039A40 8005E640 46001080 */  add.s $f2, $f2, $f0
/* 039A44 8005E644 E7A40030 */  swc1  $f4, 0x30($sp)
/* 039A48 8005E648 E7A00034 */  swc1  $f0, 0x34($sp)
/* 039A4C 8005E64C E7A2002C */  swc1  $f2, 0x2c($sp)
/* 039A50 8005E650 AFA20010 */  sw    $v0, 0x10($sp)
/* 039A54 8005E654 8E440080 */  lw    $a0, 0x80($s2)
/* 039A58 8005E658 0C0372DF */  jal   func_800DCB7C
/* 039A5C 8005E65C 27A70030 */   addiu $a3, $sp, 0x30
/* 039A60 8005E660 10400087 */  beqz  $v0, .L8005E880
/* 039A64 8005E664 00000000 */   nop   
/* 039A68 8005E668 C640001C */  lwc1  $f0, 0x1c($s2)
/* 039A6C 8005E66C C7A20034 */  lwc1  $f2, 0x34($sp)
/* 039A70 8005E670 46000005 */  abs.s $f0, $f0
/* 039A74 8005E674 46000021 */  cvt.d.s $f0, $f0
/* 039A78 8005E678 46340000 */  add.d $f0, $f0, $f20
/* 039A7C 8005E67C 460010A1 */  cvt.d.s $f2, $f2
/* 039A80 8005E680 4620103E */  c.le.d $f2, $f0
/* 039A84 8005E684 00000000 */  nop   
/* 039A88 8005E688 4500007D */  bc1f  .L8005E880
/* 039A8C 8005E68C 00000000 */   nop   
/* 039A90 8005E690 C7AC0028 */  lwc1  $f12, 0x28($sp)
/* 039A94 8005E694 C7AE0030 */  lwc1  $f14, 0x30($sp)
/* 039A98 8005E698 8FA60018 */  lw    $a2, 0x18($sp)
/* 039A9C 8005E69C 8E220290 */  lw    $v0, 0x290($s1)
/* 039AA0 8005E6A0 8FA70020 */  lw    $a3, 0x20($sp)
/* 039AA4 8005E6A4 C7A0002C */  lwc1  $f0, 0x2c($sp)
/* 039AA8 8005E6A8 8C43000C */  lw    $v1, 0xc($v0)
/* 039AAC 8005E6AC 8E420000 */  lw    $v0, ($s2)
/* 039AB0 8005E6B0 E656001C */  swc1  $f22, 0x1c($s2)
/* 039AB4 8005E6B4 E640003C */  swc1  $f0, 0x3c($s2)
/* 039AB8 8005E6B8 34420200 */  ori   $v0, $v0, 0x200
/* 039ABC 8005E6BC AE420000 */  sw    $v0, ($s2)
/* 039AC0 8005E6C0 AE430028 */  sw    $v1, 0x28($s2)
.L8005E6C4:
/* 039AC4 8005E6C4 0C00A720 */  jal   atan2
/* 039AC8 8005E6C8 00000000 */   nop   
/* 039ACC 8005E6CC E640000C */  swc1  $f0, 0xc($s2)
/* 039AD0 8005E6D0 08017A20 */  j     .L8005E880
/* 039AD4 8005E6D4 AE200288 */   sw    $zero, 0x288($s1)

.L8005E6D8:
/* 039AD8 8005E6D8 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039ADC 8005E6DC C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039AE0 8005E6E0 8FA60018 */  lw    $a2, 0x18($sp)
/* 039AE4 8005E6E4 8E220284 */  lw    $v0, 0x284($s1)
/* 039AE8 8005E6E8 8FA70020 */  lw    $a3, 0x20($sp)
/* 039AEC 8005E6EC C642003C */  lwc1  $f2, 0x3c($s2)
/* 039AF0 8005E6F0 00021100 */  sll   $v0, $v0, 4
/* 039AF4 8005E6F4 02228021 */  addu  $s0, $s1, $v0
/* 039AF8 8005E6F8 46006006 */  mov.s $f0, $f12
/* 039AFC 8005E6FC C6160004 */  lwc1  $f22, 4($s0)
/* 039B00 8005E700 C614000C */  lwc1  $f20, 0xc($s0)
/* 039B04 8005E704 46007106 */  mov.s $f4, $f14
/* 039B08 8005E708 E7A00028 */  swc1  $f0, 0x28($sp)
/* 039B0C 8005E70C E7A2002C */  swc1  $f2, 0x2c($sp)
/* 039B10 8005E710 0C00A7B5 */  jal   dist2D
/* 039B14 8005E714 E7A40030 */   swc1  $f4, 0x30($sp)
/* 039B18 8005E718 C622029C */  lwc1  $f2, 0x29c($s1)
/* 039B1C 8005E71C 4602003E */  c.le.s $f0, $f2
/* 039B20 8005E720 00000000 */  nop   
/* 039B24 8005E724 45010056 */  bc1t  .L8005E880
/* 039B28 8005E728 E7A00034 */   swc1  $f0, 0x34($sp)
/* 039B2C 8005E72C 3C0142B4 */  lui   $at, 0x42b4
/* 039B30 8005E730 4481D000 */  mtc1  $at, $f26
.L8005E734:
/* 039B34 8005E734 82020000 */  lb    $v0, ($s0)
/* 039B38 8005E738 14400028 */  bnez  $v0, .L8005E7DC
/* 039B3C 8005E73C 00000000 */   nop   
/* 039B40 8005E740 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039B44 8005E744 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039B48 8005E748 4406B000 */  mfc1  $a2, $f22
/* 039B4C 8005E74C 4407A000 */  mfc1  $a3, $f20
/* 039B50 8005E750 0C00A720 */  jal   atan2
/* 039B54 8005E754 00000000 */   nop   
/* 039B58 8005E758 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039B5C 8005E75C C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039B60 8005E760 8FA60018 */  lw    $a2, 0x18($sp)
/* 039B64 8005E764 8FA70020 */  lw    $a3, 0x20($sp)
/* 039B68 8005E768 0C00A720 */  jal   atan2
/* 039B6C 8005E76C 46000606 */   mov.s $f24, $f0
/* 039B70 8005E770 4600C306 */  mov.s $f12, $f24
/* 039B74 8005E774 0C00A70A */  jal   get_clamped_angle_diff
/* 039B78 8005E778 46000386 */   mov.s $f14, $f0
/* 039B7C 8005E77C 46000005 */  abs.s $f0, $f0
/* 039B80 8005E780 461A003C */  c.lt.s $f0, $f26
/* 039B84 8005E784 00000000 */  nop   
/* 039B88 8005E788 4501000F */  bc1t  .L8005E7C8
/* 039B8C 8005E78C 00000000 */   nop   
/* 039B90 8005E790 8E230284 */  lw    $v1, 0x284($s1)
/* 039B94 8005E794 8E220280 */  lw    $v0, 0x280($s1)
/* 039B98 8005E798 1062000B */  beq   $v1, $v0, .L8005E7C8
/* 039B9C 8005E79C 24620001 */   addiu $v0, $v1, 1
/* 039BA0 8005E7A0 AE220284 */  sw    $v0, 0x284($s1)
/* 039BA4 8005E7A4 28420028 */  slti  $v0, $v0, 0x28
/* 039BA8 8005E7A8 50400001 */  beql  $v0, $zero, .L8005E7B0
/* 039BAC 8005E7AC AE200284 */   sw    $zero, 0x284($s1)
.L8005E7B0:
/* 039BB0 8005E7B0 8E220284 */  lw    $v0, 0x284($s1)
/* 039BB4 8005E7B4 00021100 */  sll   $v0, $v0, 4
/* 039BB8 8005E7B8 02228021 */  addu  $s0, $s1, $v0
/* 039BBC 8005E7BC C6160004 */  lwc1  $f22, 4($s0)
/* 039BC0 8005E7C0 080179CD */  j     .L8005E734
/* 039BC4 8005E7C4 C614000C */   lwc1  $f20, 0xc($s0)

.L8005E7C8:
/* 039BC8 8005E7C8 82020000 */  lb    $v0, ($s0)
/* 039BCC 8005E7CC 14400003 */  bnez  $v0, .L8005E7DC
/* 039BD0 8005E7D0 00000000 */   nop   
/* 039BD4 8005E7D4 08017A20 */  j     .L8005E880
/* 039BD8 8005E7D8 AE200288 */   sw    $zero, 0x288($s1)

.L8005E7DC:
/* 039BDC 8005E7DC 3C0142B4 */  lui   $at, 0x42b4
/* 039BE0 8005E7E0 4481D000 */  mtc1  $at, $f26
.L8005E7E4:
/* 039BE4 8005E7E4 82020000 */  lb    $v0, ($s0)
/* 039BE8 8005E7E8 10400024 */  beqz  $v0, .L8005E87C
/* 039BEC 8005E7EC 24020001 */   addiu $v0, $zero, 1
/* 039BF0 8005E7F0 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039BF4 8005E7F4 C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039BF8 8005E7F8 4406B000 */  mfc1  $a2, $f22
/* 039BFC 8005E7FC 4407A000 */  mfc1  $a3, $f20
/* 039C00 8005E800 0C00A720 */  jal   atan2
/* 039C04 8005E804 00000000 */   nop   
/* 039C08 8005E808 C64C0038 */  lwc1  $f12, 0x38($s2)
/* 039C0C 8005E80C C64E0040 */  lwc1  $f14, 0x40($s2)
/* 039C10 8005E810 8FA60018 */  lw    $a2, 0x18($sp)
/* 039C14 8005E814 8FA70020 */  lw    $a3, 0x20($sp)
/* 039C18 8005E818 0C00A720 */  jal   atan2
/* 039C1C 8005E81C 46000606 */   mov.s $f24, $f0
/* 039C20 8005E820 4600C306 */  mov.s $f12, $f24
/* 039C24 8005E824 0C00A70A */  jal   get_clamped_angle_diff
/* 039C28 8005E828 46000386 */   mov.s $f14, $f0
/* 039C2C 8005E82C 46000005 */  abs.s $f0, $f0
/* 039C30 8005E830 461A003C */  c.lt.s $f0, $f26
/* 039C34 8005E834 00000000 */  nop   
/* 039C38 8005E838 45010010 */  bc1t  .L8005E87C
/* 039C3C 8005E83C 24020001 */   addiu $v0, $zero, 1
/* 039C40 8005E840 8E230284 */  lw    $v1, 0x284($s1)
/* 039C44 8005E844 8E220280 */  lw    $v0, 0x280($s1)
/* 039C48 8005E848 1062000B */  beq   $v1, $v0, .L8005E878
/* 039C4C 8005E84C 24620001 */   addiu $v0, $v1, 1
/* 039C50 8005E850 AE220284 */  sw    $v0, 0x284($s1)
/* 039C54 8005E854 28420028 */  slti  $v0, $v0, 0x28
/* 039C58 8005E858 50400001 */  beql  $v0, $zero, .L8005E860
/* 039C5C 8005E85C AE200284 */   sw    $zero, 0x284($s1)
.L8005E860:
/* 039C60 8005E860 8E220284 */  lw    $v0, 0x284($s1)
/* 039C64 8005E864 00021100 */  sll   $v0, $v0, 4
/* 039C68 8005E868 02228021 */  addu  $s0, $s1, $v0
/* 039C6C 8005E86C C6160004 */  lwc1  $f22, 4($s0)
/* 039C70 8005E870 080179F9 */  j     .L8005E7E4
/* 039C74 8005E874 C614000C */   lwc1  $f20, 0xc($s0)

.L8005E878:
/* 039C78 8005E878 24020001 */  addiu $v0, $zero, 1
.L8005E87C:
/* 039C7C 8005E87C AE220288 */  sw    $v0, 0x288($s1)
.L8005E880:
/* 039C80 8005E880 8FBF0044 */  lw    $ra, 0x44($sp)
/* 039C84 8005E884 8FB20040 */  lw    $s2, 0x40($sp)
/* 039C88 8005E888 8FB1003C */  lw    $s1, 0x3c($sp)
/* 039C8C 8005E88C 8FB00038 */  lw    $s0, 0x38($sp)
/* 039C90 8005E890 D7BA0060 */  ldc1  $f26, 0x60($sp)
/* 039C94 8005E894 D7B80058 */  ldc1  $f24, 0x58($sp)
/* 039C98 8005E898 D7B60050 */  ldc1  $f22, 0x50($sp)
/* 039C9C 8005E89C D7B40048 */  ldc1  $f20, 0x48($sp)
/* 039CA0 8005E8A0 03E00008 */  jr    $ra
/* 039CA4 8005E8A4 27BD0068 */   addiu $sp, $sp, 0x68

/* 039CA8 8005E8A8 00000000 */  nop   
/* 039CAC 8005E8AC 00000000 */  nop   


