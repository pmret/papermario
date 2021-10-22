.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel fx_44_update
/* 35EAD4 E00581B4 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 35EAD8 E00581B8 AFB3001C */  sw        $s3, 0x1c($sp)
/* 35EADC E00581BC 0080982D */  daddu     $s3, $a0, $zero
/* 35EAE0 E00581C0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 35EAE4 E00581C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 35EAE8 E00581C8 AFB10014 */  sw        $s1, 0x14($sp)
/* 35EAEC E00581CC AFB00010 */  sw        $s0, 0x10($sp)
/* 35EAF0 E00581D0 F7B60030 */  sdc1      $f22, 0x30($sp)
/* 35EAF4 E00581D4 F7B40028 */  sdc1      $f20, 0x28($sp)
/* 35EAF8 E00581D8 8E65000C */  lw        $a1, 0xc($s3)
/* 35EAFC E00581DC 8CA2002C */  lw        $v0, 0x2c($a1)
/* 35EB00 E00581E0 8CB20000 */  lw        $s2, ($a1)
/* 35EB04 E00581E4 2442FFFB */  addiu     $v0, $v0, -5
/* 35EB08 E00581E8 2C42000A */  sltiu     $v0, $v0, 0xa
/* 35EB0C E00581EC 10400007 */  beqz      $v0, .LE005820C
/* 35EB10 E00581F0 3C020004 */   lui      $v0, 4
/* 35EB14 E00581F4 16400006 */  bnez      $s2, .LE0058210
/* 35EB18 E00581F8 3442F1A0 */   ori      $v0, $v0, 0xf1a0
/* 35EB1C E00581FC 3C028011 */  lui       $v0, %hi(gPlayerActionState)
/* 35EB20 E0058200 8042F07C */  lb        $v0, %lo(gPlayerActionState)($v0)
/* 35EB24 E0058204 10400099 */  beqz      $v0, .LE005846C
/* 35EB28 E0058208 3C020004 */   lui      $v0, 4
.LE005820C:
/* 35EB2C E005820C 3442F1A0 */  ori       $v0, $v0, 0xf1a0
.LE0058210:
/* 35EB30 E0058210 8CA30028 */  lw        $v1, 0x28($a1)
/* 35EB34 E0058214 8CA4002C */  lw        $a0, 0x2c($a1)
/* 35EB38 E0058218 2463FFFF */  addiu     $v1, $v1, -1
/* 35EB3C E005821C 24840001 */  addiu     $a0, $a0, 1
/* 35EB40 E0058220 0044102A */  slt       $v0, $v0, $a0
/* 35EB44 E0058224 ACA30028 */  sw        $v1, 0x28($a1)
/* 35EB48 E0058228 10400003 */  beqz      $v0, .LE0058238
/* 35EB4C E005822C ACA4002C */   sw       $a0, 0x2c($a1)
/* 35EB50 E0058230 24020100 */  addiu     $v0, $zero, 0x100
/* 35EB54 E0058234 ACA2002C */  sw        $v0, 0x2c($a1)
.LE0058238:
/* 35EB58 E0058238 8CA40028 */  lw        $a0, 0x28($a1)
/* 35EB5C E005823C 04810005 */  bgez      $a0, .LE0058254
/* 35EB60 E0058240 00000000 */   nop
/* 35EB64 E0058244 0C080128 */  jal       shim_remove_effect
/* 35EB68 E0058248 0260202D */   daddu    $a0, $s3, $zero
/* 35EB6C E005824C 0801611B */  j         .LE005846C
/* 35EB70 E0058250 00000000 */   nop
.LE0058254:
/* 35EB74 E0058254 8CA2002C */  lw        $v0, 0x2c($a1)
/* 35EB78 E0058258 2842000A */  slti      $v0, $v0, 0xa
/* 35EB7C E005825C 10400010 */  beqz      $v0, .LE00582A0
/* 35EB80 E0058260 240200FF */   addiu    $v0, $zero, 0xff
/* 35EB84 E0058264 8CA30024 */  lw        $v1, 0x24($a1)
/* 35EB88 E0058268 3C01E006 */  lui       $at, %hi(D_E0058780)
/* 35EB8C E005826C D4208780 */  ldc1      $f0, %lo(D_E0058780)($at)
/* 35EB90 E0058270 00431023 */  subu      $v0, $v0, $v1
/* 35EB94 E0058274 44821000 */  mtc1      $v0, $f2
/* 35EB98 E0058278 00000000 */  nop
/* 35EB9C E005827C 468010A1 */  cvt.d.w   $f2, $f2
/* 35EBA0 E0058280 46201082 */  mul.d     $f2, $f2, $f0
/* 35EBA4 E0058284 00000000 */  nop
/* 35EBA8 E0058288 44830000 */  mtc1      $v1, $f0
/* 35EBAC E005828C 00000000 */  nop
/* 35EBB0 E0058290 46800021 */  cvt.d.w   $f0, $f0
/* 35EBB4 E0058294 46220000 */  add.d     $f0, $f0, $f2
/* 35EBB8 E0058298 4620020D */  trunc.w.d $f8, $f0
/* 35EBBC E005829C E4A80024 */  swc1      $f8, 0x24($a1)
.LE00582A0:
/* 35EBC0 E00582A0 2882000A */  slti      $v0, $a0, 0xa
/* 35EBC4 E00582A4 10400009 */  beqz      $v0, .LE00582CC
/* 35EBC8 E00582A8 00000000 */   nop
/* 35EBCC E00582AC 3C01E006 */  lui       $at, %hi(D_E0058788)
/* 35EBD0 E00582B0 D4228788 */  ldc1      $f2, %lo(D_E0058788)($at)
/* 35EBD4 E00582B4 C4A00024 */  lwc1      $f0, 0x24($a1)
/* 35EBD8 E00582B8 46800021 */  cvt.d.w   $f0, $f0
/* 35EBDC E00582BC 46220002 */  mul.d     $f0, $f0, $f2
/* 35EBE0 E00582C0 00000000 */  nop
/* 35EBE4 E00582C4 4620020D */  trunc.w.d $f8, $f0
/* 35EBE8 E00582C8 E4A80024 */  swc1      $f8, 0x24($a1)
.LE00582CC:
/* 35EBEC E00582CC 8E620008 */  lw        $v0, 8($s3)
/* 35EBF0 E00582D0 24110001 */  addiu     $s1, $zero, 1
/* 35EBF4 E00582D4 0222102A */  slt       $v0, $s1, $v0
/* 35EBF8 E00582D8 10400064 */  beqz      $v0, .LE005846C
/* 35EBFC E00582DC 24A50034 */   addiu    $a1, $a1, 0x34
/* 35EC00 E00582E0 24B00008 */  addiu     $s0, $a1, 8
/* 35EC04 E00582E4 3C01BD4C */  lui       $at, 0xbd4c
/* 35EC08 E00582E8 3421CCCD */  ori       $at, $at, 0xcccd
/* 35EC0C E00582EC 4481B000 */  mtc1      $at, $f22
/* 35EC10 E00582F0 3C014120 */  lui       $at, 0x4120
/* 35EC14 E00582F4 4481A000 */  mtc1      $at, $f20
.LE00582F8:
/* 35EC18 E00582F8 C60C0010 */  lwc1      $f12, 0x10($s0)
/* 35EC1C E00582FC 0C080140 */  jal       shim_sin_deg
/* 35EC20 E0058300 460C6300 */   add.s    $f12, $f12, $f12
/* 35EC24 E0058304 3C01E006 */  lui       $at, %hi(D_E0058790)
/* 35EC28 E0058308 D4228790 */  ldc1      $f2, %lo(D_E0058790)($at)
/* 35EC2C E005830C 46000021 */  cvt.d.s   $f0, $f0
/* 35EC30 E0058310 46220002 */  mul.d     $f0, $f0, $f2
/* 35EC34 E0058314 00000000 */  nop
/* 35EC38 E0058318 C602000C */  lwc1      $f2, 0xc($s0)
/* 35EC3C E005831C 46161080 */  add.s     $f2, $f2, $f22
/* 35EC40 E0058320 C6040008 */  lwc1      $f4, 8($s0)
/* 35EC44 E0058324 46200020 */  cvt.s.d   $f0, $f0
/* 35EC48 E0058328 46002000 */  add.s     $f0, $f4, $f0
/* 35EC4C E005832C E602000C */  swc1      $f2, 0xc($s0)
/* 35EC50 E0058330 16400019 */  bnez      $s2, .LE0058398
/* 35EC54 E0058334 E6000008 */   swc1     $f0, 8($s0)
/* 35EC58 E0058338 3C01E006 */  lui       $at, %hi(D_E0058798)
/* 35EC5C E005833C D4228798 */  ldc1      $f2, %lo(D_E0058798)($at)
/* 35EC60 E0058340 46000021 */  cvt.d.s   $f0, $f0
/* 35EC64 E0058344 46220002 */  mul.d     $f0, $f0, $f2
/* 35EC68 E0058348 00000000 */  nop
/* 35EC6C E005834C C60C0010 */  lwc1      $f12, 0x10($s0)
/* 35EC70 E0058350 46200020 */  cvt.s.d   $f0, $f0
/* 35EC74 E0058354 0C080140 */  jal       shim_sin_deg
/* 35EC78 E0058358 E6000008 */   swc1     $f0, 8($s0)
/* 35EC7C E005835C 3C01E006 */  lui       $at, %hi(D_E00587A0)
/* 35EC80 E0058360 D42287A0 */  ldc1      $f2, %lo(D_E00587A0)($at)
/* 35EC84 E0058364 46000021 */  cvt.d.s   $f0, $f0
/* 35EC88 E0058368 46220002 */  mul.d     $f0, $f0, $f2
/* 35EC8C E005836C 00000000 */  nop
/* 35EC90 E0058370 3C01E006 */  lui       $at, %hi(D_E00587A8)
/* 35EC94 E0058374 D42487A8 */  ldc1      $f4, %lo(D_E00587A8)($at)
/* 35EC98 E0058378 C602000C */  lwc1      $f2, 0xc($s0)
/* 35EC9C E005837C 46240000 */  add.d     $f0, $f0, $f4
/* 35ECA0 E0058380 460010A1 */  cvt.d.s   $f2, $f2
/* 35ECA4 E0058384 46201082 */  mul.d     $f2, $f2, $f0
/* 35ECA8 E0058388 00000000 */  nop
/* 35ECAC E005838C 462010A0 */  cvt.s.d   $f2, $f2
/* 35ECB0 E0058390 080160F1 */  j         .LE00583C4
/* 35ECB4 E0058394 E602000C */   swc1     $f2, 0xc($s0)
.LE0058398:
/* 35ECB8 E0058398 C6000008 */  lwc1      $f0, 8($s0)
/* 35ECBC E005839C 3C01E006 */  lui       $at, %hi(D_E00587B0)
/* 35ECC0 E00583A0 D42287B0 */  ldc1      $f2, %lo(D_E00587B0)($at)
/* 35ECC4 E00583A4 46000021 */  cvt.d.s   $f0, $f0
/* 35ECC8 E00583A8 46220002 */  mul.d     $f0, $f0, $f2
/* 35ECCC E00583AC 00000000 */  nop
/* 35ECD0 E00583B0 C602000C */  lwc1      $f2, 0xc($s0)
/* 35ECD4 E00583B4 46161080 */  add.s     $f2, $f2, $f22
/* 35ECD8 E00583B8 E602000C */  swc1      $f2, 0xc($s0)
/* 35ECDC E00583BC 46200020 */  cvt.s.d   $f0, $f0
/* 35ECE0 E00583C0 E6000008 */  swc1      $f0, 8($s0)
.LE00583C4:
/* 35ECE4 E00583C4 0C080138 */  jal       shim_rand_int
/* 35ECE8 E00583C8 24040032 */   addiu    $a0, $zero, 0x32
/* 35ECEC E00583CC 3C0141C8 */  lui       $at, 0x41c8
/* 35ECF0 E00583D0 44811000 */  mtc1      $at, $f2
/* 35ECF4 E00583D4 44820000 */  mtc1      $v0, $f0
/* 35ECF8 E00583D8 00000000 */  nop
/* 35ECFC E00583DC 46800020 */  cvt.s.w   $f0, $f0
/* 35ED00 E00583E0 46020001 */  sub.s     $f0, $f0, $f2
/* 35ED04 E00583E4 C60C0014 */  lwc1      $f12, 0x14($s0)
/* 35ED08 E00583E8 46006300 */  add.s     $f12, $f12, $f0
/* 35ED0C E00583EC 0C080140 */  jal       shim_sin_deg
/* 35ED10 E00583F0 E60C0014 */   swc1     $f12, 0x14($s0)
/* 35ED14 E00583F4 46140002 */  mul.s     $f0, $f0, $f20
/* 35ED18 E00583F8 00000000 */  nop
/* 35ED1C E00583FC C6020014 */  lwc1      $f2, 0x14($s0)
/* 35ED20 E0058400 3C013F00 */  lui       $at, 0x3f00
/* 35ED24 E0058404 44816000 */  mtc1      $at, $f12
/* 35ED28 E0058408 00000000 */  nop
/* 35ED2C E005840C 460C1302 */  mul.s     $f12, $f2, $f12
/* 35ED30 E0058410 00000000 */  nop
/* 35ED34 E0058414 C6020010 */  lwc1      $f2, 0x10($s0)
/* 35ED38 E0058418 46001080 */  add.s     $f2, $f2, $f0
/* 35ED3C E005841C 0C080144 */  jal       shim_cos_deg
/* 35ED40 E0058420 E6020010 */   swc1     $f2, 0x10($s0)
/* 35ED44 E0058424 46140002 */  mul.s     $f0, $f0, $f20
/* 35ED48 E0058428 00000000 */  nop
/* 35ED4C E005842C C606FFFC */  lwc1      $f6, -4($s0)
/* 35ED50 E0058430 C6020008 */  lwc1      $f2, 8($s0)
/* 35ED54 E0058434 C6040000 */  lwc1      $f4, ($s0)
/* 35ED58 E0058438 46023180 */  add.s     $f6, $f6, $f2
/* 35ED5C E005843C C602000C */  lwc1      $f2, 0xc($s0)
/* 35ED60 E0058440 46022100 */  add.s     $f4, $f4, $f2
/* 35ED64 E0058444 C6020018 */  lwc1      $f2, 0x18($s0)
/* 35ED68 E0058448 26310001 */  addiu     $s1, $s1, 1
/* 35ED6C E005844C 46001080 */  add.s     $f2, $f2, $f0
/* 35ED70 E0058450 E606FFFC */  swc1      $f6, -4($s0)
/* 35ED74 E0058454 E6040000 */  swc1      $f4, ($s0)
/* 35ED78 E0058458 E6020018 */  swc1      $f2, 0x18($s0)
/* 35ED7C E005845C 8E620008 */  lw        $v0, 8($s3)
/* 35ED80 E0058460 0222102A */  slt       $v0, $s1, $v0
/* 35ED84 E0058464 1440FFA4 */  bnez      $v0, .LE00582F8
/* 35ED88 E0058468 26100034 */   addiu    $s0, $s0, 0x34
.LE005846C:
/* 35ED8C E005846C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 35ED90 E0058470 8FB3001C */  lw        $s3, 0x1c($sp)
/* 35ED94 E0058474 8FB20018 */  lw        $s2, 0x18($sp)
/* 35ED98 E0058478 8FB10014 */  lw        $s1, 0x14($sp)
/* 35ED9C E005847C 8FB00010 */  lw        $s0, 0x10($sp)
/* 35EDA0 E0058480 D7B60030 */  ldc1      $f22, 0x30($sp)
/* 35EDA4 E0058484 D7B40028 */  ldc1      $f20, 0x28($sp)
/* 35EDA8 E0058488 03E00008 */  jr        $ra
/* 35EDAC E005848C 27BD0038 */   addiu    $sp, $sp, 0x38
