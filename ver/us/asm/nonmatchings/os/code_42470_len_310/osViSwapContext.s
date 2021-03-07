.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel D_80099D70
.double 4294967296.0, 0.0

.section .text

glabel osViSwapContext
/* 42470 80067070 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 42474 80067074 AFB00010 */  sw        $s0, 0x10($sp)
/* 42478 80067078 3C108009 */  lui       $s0, %hi(D_800959D4)
/* 4247C 8006707C 8E1059D4 */  lw        $s0, %lo(D_800959D4)($s0)
/* 42480 80067080 3C02A440 */  lui       $v0, 0xa440
/* 42484 80067084 34420010 */  ori       $v0, $v0, 0x10
/* 42488 80067088 AFBF0024 */  sw        $ra, 0x24($sp)
/* 4248C 8006708C AFB40020 */  sw        $s4, 0x20($sp)
/* 42490 80067090 AFB3001C */  sw        $s3, 0x1c($sp)
/* 42494 80067094 AFB20018 */  sw        $s2, 0x18($sp)
/* 42498 80067098 AFB10014 */  sw        $s1, 0x14($sp)
/* 4249C 8006709C 8C420000 */  lw        $v0, ($v0)
/* 424A0 800670A0 8E040004 */  lw        $a0, 4($s0)
/* 424A4 800670A4 8E120008 */  lw        $s2, 8($s0)
/* 424A8 800670A8 0C0187A4 */  jal       osVirtualToPhysical
/* 424AC 800670AC 30510001 */   andi     $s1, $v0, 1
/* 424B0 800670B0 00111880 */  sll       $v1, $s1, 2
/* 424B4 800670B4 00711821 */  addu      $v1, $v1, $s1
/* 424B8 800670B8 00031880 */  sll       $v1, $v1, 2
/* 424BC 800670BC 02431821 */  addu      $v1, $s2, $v1
/* 424C0 800670C0 8C640028 */  lw        $a0, 0x28($v1)
/* 424C4 800670C4 96030000 */  lhu       $v1, ($s0)
/* 424C8 800670C8 30630002 */  andi      $v1, $v1, 2
/* 424CC 800670CC 10600008 */  beqz      $v1, .L800670F0
/* 424D0 800670D0 00443021 */   addu     $a2, $v0, $a0
/* 424D4 800670D4 8E420020 */  lw        $v0, 0x20($s2)
/* 424D8 800670D8 8E030020 */  lw        $v1, 0x20($s0)
/* 424DC 800670DC 2404F000 */  addiu     $a0, $zero, -0x1000
/* 424E0 800670E0 00441024 */  and       $v0, $v0, $a0
/* 424E4 800670E4 00621825 */  or        $v1, $v1, $v0
/* 424E8 800670E8 08019C3E */  j         .L800670F8
/* 424EC 800670EC AE030020 */   sw       $v1, 0x20($s0)
.L800670F0:
/* 424F0 800670F0 8E420020 */  lw        $v0, 0x20($s2)
/* 424F4 800670F4 AE020020 */  sw        $v0, 0x20($s0)
.L800670F8:
/* 424F8 800670F8 96020000 */  lhu       $v0, ($s0)
/* 424FC 800670FC 30420004 */  andi      $v0, $v0, 4
/* 42500 80067100 1040002B */  beqz      $v0, .L800671B0
/* 42504 80067104 00111080 */   sll      $v0, $s1, 2
/* 42508 80067108 00511021 */  addu      $v0, $v0, $s1
/* 4250C 8006710C 00021080 */  sll       $v0, $v0, 2
/* 42510 80067110 02421021 */  addu      $v0, $s2, $v0
/* 42514 80067114 8C42002C */  lw        $v0, 0x2c($v0)
/* 42518 80067118 30420FFF */  andi      $v0, $v0, 0xfff
/* 4251C 8006711C 44822000 */  mtc1      $v0, $f4
/* 42520 80067120 00000000 */  nop
/* 42524 80067124 04410004 */  bgez      $v0, .L80067138
/* 42528 80067128 46802121 */   cvt.d.w  $f4, $f4
/* 4252C 8006712C 3C01800A */  lui       $at, %hi(D_80099D70)
/* 42530 80067130 D4209D70 */  ldc1      $f0, %lo(D_80099D70)($at)
/* 42534 80067134 46202100 */  add.d     $f4, $f4, $f0
.L80067138:
/* 42538 80067138 C6020024 */  lwc1      $f2, 0x24($s0)
/* 4253C 8006713C 46202020 */  cvt.s.d   $f0, $f4
/* 42540 80067140 46001082 */  mul.s     $f2, $f2, $f0
/* 42544 80067144 3C014F00 */  lui       $at, 0x4f00
/* 42548 80067148 44810000 */  mtc1      $at, $f0
/* 4254C 8006714C 00000000 */  nop
/* 42550 80067150 4602003E */  c.le.s    $f0, $f2
/* 42554 80067154 00000000 */  nop
/* 42558 80067158 00000000 */  nop
/* 4255C 8006715C 45030006 */  bc1tl     .L80067178
/* 42560 80067160 46001001 */   sub.s    $f0, $f2, $f0
/* 42564 80067164 4600100D */  trunc.w.s $f0, $f2
/* 42568 80067168 44040000 */  mfc1      $a0, $f0
/* 4256C 8006716C 00000000 */  nop
/* 42570 80067170 08019C63 */  j         .L8006718C
/* 42574 80067174 00111080 */   sll      $v0, $s1, 2
.L80067178:
/* 42578 80067178 4600008D */  trunc.w.s $f2, $f0
/* 4257C 8006717C 44041000 */  mfc1      $a0, $f2
/* 42580 80067180 3C028000 */  lui       $v0, 0x8000
/* 42584 80067184 00822025 */  or        $a0, $a0, $v0
/* 42588 80067188 00111080 */  sll       $v0, $s1, 2
.L8006718C:
/* 4258C 8006718C 00511021 */  addu      $v0, $v0, $s1
/* 42590 80067190 00021080 */  sll       $v0, $v0, 2
/* 42594 80067194 02421021 */  addu      $v0, $s2, $v0
/* 42598 80067198 AE04002C */  sw        $a0, 0x2c($s0)
/* 4259C 8006719C 8C42002C */  lw        $v0, 0x2c($v0)
/* 425A0 800671A0 2403F000 */  addiu     $v1, $zero, -0x1000
/* 425A4 800671A4 00431024 */  and       $v0, $v0, $v1
/* 425A8 800671A8 08019C70 */  j         .L800671C0
/* 425AC 800671AC 00821025 */   or       $v0, $a0, $v0
.L800671B0:
/* 425B0 800671B0 00511021 */  addu      $v0, $v0, $s1
/* 425B4 800671B4 00021080 */  sll       $v0, $v0, 2
/* 425B8 800671B8 02421021 */  addu      $v0, $s2, $v0
/* 425BC 800671BC 8C42002C */  lw        $v0, 0x2c($v0)
.L800671C0:
/* 425C0 800671C0 AE02002C */  sw        $v0, 0x2c($s0)
/* 425C4 800671C4 8E53001C */  lw        $s3, 0x1c($s2)
/* 425C8 800671C8 00111080 */  sll       $v0, $s1, 2
/* 425CC 800671CC 00511021 */  addu      $v0, $v0, $s1
/* 425D0 800671D0 00021080 */  sll       $v0, $v0, 2
/* 425D4 800671D4 02428821 */  addu      $s1, $s2, $v0
/* 425D8 800671D8 96040000 */  lhu       $a0, ($s0)
/* 425DC 800671DC 3C058009 */  lui       $a1, %hi(D_8009469C)
/* 425E0 800671E0 8CA5469C */  lw        $a1, %lo(D_8009469C)($a1)
/* 425E4 800671E4 8E230030 */  lw        $v1, 0x30($s1)
/* 425E8 800671E8 30820020 */  andi      $v0, $a0, 0x20
/* 425EC 800671EC 2C420001 */  sltiu     $v0, $v0, 1
/* 425F0 800671F0 00021023 */  negu      $v0, $v0
/* 425F4 800671F4 02629824 */  and       $s3, $s3, $v0
/* 425F8 800671F8 00051400 */  sll       $v0, $a1, 0x10
/* 425FC 800671FC 00621823 */  subu      $v1, $v1, $v0
/* 42600 80067200 30840040 */  andi      $a0, $a0, 0x40
/* 42604 80067204 10800005 */  beqz      $a0, .L8006721C
/* 42608 80067208 0065A021 */   addu     $s4, $v1, $a1
/* 4260C 8006720C 8E040004 */  lw        $a0, 4($s0)
/* 42610 80067210 0C0187A4 */  jal       osVirtualToPhysical
/* 42614 80067214 AE00002C */   sw       $zero, 0x2c($s0)
/* 42618 80067218 00403021 */  addu      $a2, $v0, $zero
.L8006721C:
/* 4261C 8006721C 96020000 */  lhu       $v0, ($s0)
/* 42620 80067220 30420080 */  andi      $v0, $v0, 0x80
/* 42624 80067224 10400008 */  beqz      $v0, .L80067248
/* 42628 80067228 3C0303FF */   lui      $v1, 0x3ff
/* 4262C 8006722C 96020028 */  lhu       $v0, 0x28($s0)
/* 42630 80067230 8E040004 */  lw        $a0, 4($s0)
/* 42634 80067234 00021400 */  sll       $v0, $v0, 0x10
/* 42638 80067238 00431024 */  and       $v0, $v0, $v1
/* 4263C 8006723C 0C0187A4 */  jal       osVirtualToPhysical
/* 42640 80067240 AE02002C */   sw       $v0, 0x2c($s0)
/* 42644 80067244 00403021 */  addu      $a2, $v0, $zero
.L80067248:
/* 42648 80067248 3C02A440 */  lui       $v0, 0xa440
/* 4264C 8006724C 34420004 */  ori       $v0, $v0, 4
/* 42650 80067250 3C03A440 */  lui       $v1, 0xa440
/* 42654 80067254 34630008 */  ori       $v1, $v1, 8
/* 42658 80067258 3C04A440 */  lui       $a0, 0xa440
/* 4265C 8006725C 34840014 */  ori       $a0, $a0, 0x14
/* 42660 80067260 AC460000 */  sw        $a2, ($v0)
/* 42664 80067264 8E420008 */  lw        $v0, 8($s2)
/* 42668 80067268 3C05A440 */  lui       $a1, 0xa440
/* 4266C 8006726C 34A50018 */  ori       $a1, $a1, 0x18
/* 42670 80067270 AC620000 */  sw        $v0, ($v1)
/* 42674 80067274 8E42000C */  lw        $v0, 0xc($s2)
/* 42678 80067278 3C06A440 */  lui       $a2, 0xa440
/* 4267C 8006727C 34C60020 */  ori       $a2, $a2, 0x20
/* 42680 80067280 AC820000 */  sw        $v0, ($a0)
/* 42684 80067284 8E420010 */  lw        $v0, 0x10($s2)
/* 42688 80067288 3C03A440 */  lui       $v1, 0xa440
/* 4268C 8006728C 3463001C */  ori       $v1, $v1, 0x1c
/* 42690 80067290 ACA20000 */  sw        $v0, ($a1)
/* 42694 80067294 8E420014 */  lw        $v0, 0x14($s2)
/* 42698 80067298 3C04A440 */  lui       $a0, 0xa440
/* 4269C 8006729C 34840024 */  ori       $a0, $a0, 0x24
/* 426A0 800672A0 AC620000 */  sw        $v0, ($v1)
/* 426A4 800672A4 8E420018 */  lw        $v0, 0x18($s2)
/* 426A8 800672A8 3C03A440 */  lui       $v1, 0xa440
/* 426AC 800672AC 34630028 */  ori       $v1, $v1, 0x28
/* 426B0 800672B0 ACC20000 */  sw        $v0, ($a2)
/* 426B4 800672B4 AC930000 */  sw        $s3, ($a0)
/* 426B8 800672B8 AC740000 */  sw        $s4, ($v1)
/* 426BC 800672BC 8E230034 */  lw        $v1, 0x34($s1)
/* 426C0 800672C0 3C02A440 */  lui       $v0, 0xa440
/* 426C4 800672C4 3442002C */  ori       $v0, $v0, 0x2c
/* 426C8 800672C8 AC430000 */  sw        $v1, ($v0)
/* 426CC 800672CC 8E230038 */  lw        $v1, 0x38($s1)
/* 426D0 800672D0 3C02A440 */  lui       $v0, 0xa440
/* 426D4 800672D4 3442000C */  ori       $v0, $v0, 0xc
/* 426D8 800672D8 AC430000 */  sw        $v1, ($v0)
/* 426DC 800672DC 8E030020 */  lw        $v1, 0x20($s0)
/* 426E0 800672E0 3C02A440 */  lui       $v0, 0xa440
/* 426E4 800672E4 34420030 */  ori       $v0, $v0, 0x30
/* 426E8 800672E8 AC430000 */  sw        $v1, ($v0)
/* 426EC 800672EC 8E03002C */  lw        $v1, 0x2c($s0)
/* 426F0 800672F0 3C02A440 */  lui       $v0, 0xa440
/* 426F4 800672F4 34420034 */  ori       $v0, $v0, 0x34
/* 426F8 800672F8 AC430000 */  sw        $v1, ($v0)
/* 426FC 800672FC 8E03000C */  lw        $v1, 0xc($s0)
/* 42700 80067300 3C028009 */  lui       $v0, %hi(D_800959D0)
/* 42704 80067304 8C4259D0 */  lw        $v0, %lo(D_800959D0)($v0)
/* 42708 80067308 02003021 */  addu      $a2, $s0, $zero
/* 4270C 8006730C 24C80030 */  addiu     $t0, $a2, 0x30
/* 42710 80067310 3C018009 */  lui       $at, %hi(D_800959D0)
/* 42714 80067314 AC2659D0 */  sw        $a2, %lo(D_800959D0)($at)
/* 42718 80067318 00403821 */  addu      $a3, $v0, $zero
/* 4271C 8006731C 3C02A440 */  lui       $v0, 0xa440
/* 42720 80067320 3C018009 */  lui       $at, %hi(D_800959D4)
/* 42724 80067324 AC2759D4 */  sw        $a3, %lo(D_800959D4)($at)
/* 42728 80067328 AC430000 */  sw        $v1, ($v0)
.L8006732C:
/* 4272C 8006732C 8CC20000 */  lw        $v0, ($a2)
/* 42730 80067330 8CC30004 */  lw        $v1, 4($a2)
/* 42734 80067334 8CC40008 */  lw        $a0, 8($a2)
/* 42738 80067338 8CC5000C */  lw        $a1, 0xc($a2)
/* 4273C 8006733C ACE20000 */  sw        $v0, ($a3)
/* 42740 80067340 ACE30004 */  sw        $v1, 4($a3)
/* 42744 80067344 ACE40008 */  sw        $a0, 8($a3)
/* 42748 80067348 ACE5000C */  sw        $a1, 0xc($a3)
/* 4274C 8006734C 24C60010 */  addiu     $a2, $a2, 0x10
/* 42750 80067350 14C8FFF6 */  bne       $a2, $t0, .L8006732C
/* 42754 80067354 24E70010 */   addiu    $a3, $a3, 0x10
/* 42758 80067358 8FBF0024 */  lw        $ra, 0x24($sp)
/* 4275C 8006735C 8FB40020 */  lw        $s4, 0x20($sp)
/* 42760 80067360 8FB3001C */  lw        $s3, 0x1c($sp)
/* 42764 80067364 8FB20018 */  lw        $s2, 0x18($sp)
/* 42768 80067368 8FB10014 */  lw        $s1, 0x14($sp)
/* 4276C 8006736C 8FB00010 */  lw        $s0, 0x10($sp)
/* 42770 80067370 03E00008 */  jr        $ra
/* 42774 80067374 27BD0028 */   addiu    $sp, $sp, 0x28
/* 42778 80067378 00000000 */  nop
/* 4277C 8006737C 00000000 */  nop
