.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240010_8FEE90
/* 8FEE90 80240010 27BDFFF0 */  addiu     $sp, $sp, -0x10
/* 8FEE94 80240014 0000482D */  daddu     $t1, $zero, $zero
/* 8FEE98 80240018 3C02800A */  lui       $v0, %hi(D_8009A66C)
/* 8FEE9C 8024001C 2442A66C */  addiu     $v0, $v0, %lo(D_8009A66C)
/* 8FEEA0 80240020 0040402D */  daddu     $t0, $v0, $zero
/* 8FEEA4 80240024 3C0EFD18 */  lui       $t6, 0xfd18
/* 8FEEA8 80240028 35CE00C7 */  ori       $t6, $t6, 0xc7
/* 8FEEAC 8024002C AFB3000C */  sw        $s3, 0xc($sp)
/* 8FEEB0 80240030 3C138024 */  lui       $s3, %hi(D_802407F4)
/* 8FEEB4 80240034 267307F4 */  addiu     $s3, $s3, %lo(D_802407F4)
/* 8FEEB8 80240038 3C0BF518 */  lui       $t3, 0xf518
/* 8FEEBC 8024003C 356B6400 */  ori       $t3, $t3, 0x6400
/* 8FEEC0 80240040 AFB20008 */  sw        $s2, 8($sp)
/* 8FEEC4 80240044 3C120700 */  lui       $s2, 0x700
/* 8FEEC8 80240048 AFB10004 */  sw        $s1, 4($sp)
/* 8FEECC 8024004C 3C11E600 */  lui       $s1, 0xe600
/* 8FEED0 80240050 AFB00000 */  sw        $s0, ($sp)
/* 8FEED4 80240054 3C10F400 */  lui       $s0, 0xf400
/* 8FEED8 80240058 3C0D0731 */  lui       $t5, 0x731
/* 8FEEDC 8024005C 35ADC004 */  ori       $t5, $t5, 0xc004
/* 8FEEE0 80240060 3C19E700 */  lui       $t9, 0xe700
/* 8FEEE4 80240064 3C18F200 */  lui       $t8, 0xf200
/* 8FEEE8 80240068 3C0C0031 */  lui       $t4, 0x31
/* 8FEEEC 8024006C 358CC004 */  ori       $t4, $t4, 0xc004
/* 8FEEF0 80240070 3C0F8024 */  lui       $t7, %hi(D_80240334)
/* 8FEEF4 80240074 25EF0334 */  addiu     $t7, $t7, %lo(D_80240334)
/* 8FEEF8 80240078 0120502D */  daddu     $t2, $t1, $zero
/* 8FEEFC 8024007C 8D030000 */  lw        $v1, ($t0)
/* 8FEF00 80240080 3C02DE00 */  lui       $v0, %hi(D_DE000338)
/* 8FEF04 80240084 0060202D */  daddu     $a0, $v1, $zero
/* 8FEF08 80240088 24630008 */  addiu     $v1, $v1, 8
/* 8FEF0C 8024008C AD030000 */  sw        $v1, ($t0)
/* 8FEF10 80240090 AC820000 */  sw        $v0, ($a0)
/* 8FEF14 80240094 3C028024 */  lui       $v0, %hi(D_80240338)
/* 8FEF18 80240098 24420338 */  addiu     $v0, $v0, %lo(D_DE000338)
/* 8FEF1C 8024009C AC820004 */  sw        $v0, 4($a0)
/* 8FEF20 802400A0 24620008 */  addiu     $v0, $v1, 8
/* 8FEF24 802400A4 AD020000 */  sw        $v0, ($t0)
/* 8FEF28 802400A8 3C048024 */  lui       $a0, %hi(D_80240333)
/* 8FEF2C 802400AC 90840333 */  lbu       $a0, %lo(D_80240333)($a0)
/* 8FEF30 802400B0 3C02FA00 */  lui       $v0, 0xfa00
/* 8FEF34 802400B4 AC620000 */  sw        $v0, ($v1)
/* 8FEF38 802400B8 24620010 */  addiu     $v0, $v1, 0x10
/* 8FEF3C 802400BC AC640004 */  sw        $a0, 4($v1)
/* 8FEF40 802400C0 AD020000 */  sw        $v0, ($t0)
/* 8FEF44 802400C4 0320102D */  daddu     $v0, $t9, $zero
/* 8FEF48 802400C8 AC620008 */  sw        $v0, 8($v1)
/* 8FEF4C 802400CC AC60000C */  sw        $zero, 0xc($v1)
.L802400D0:
/* 8FEF50 802400D0 3C070400 */  lui       $a3, 0x400
/* 8FEF54 802400D4 34E70400 */  ori       $a3, $a3, 0x400
/* 8FEF58 802400D8 00092840 */  sll       $a1, $t1, 1
/* 8FEF5C 802400DC 25290001 */  addiu     $t1, $t1, 1
/* 8FEF60 802400E0 8D040000 */  lw        $a0, ($t0)
/* 8FEF64 802400E4 8E620000 */  lw        $v0, ($s3)
/* 8FEF68 802400E8 0080182D */  daddu     $v1, $a0, $zero
/* 8FEF6C 802400EC 24840008 */  addiu     $a0, $a0, 8
/* 8FEF70 802400F0 004A1021 */  addu      $v0, $v0, $t2
/* 8FEF74 802400F4 254A0640 */  addiu     $t2, $t2, 0x640
/* 8FEF78 802400F8 AD040000 */  sw        $a0, ($t0)
/* 8FEF7C 802400FC AC620004 */  sw        $v0, 4($v1)
/* 8FEF80 80240100 24820008 */  addiu     $v0, $a0, 8
/* 8FEF84 80240104 AC6E0000 */  sw        $t6, ($v1)
/* 8FEF88 80240108 AD020000 */  sw        $v0, ($t0)
/* 8FEF8C 8024010C 24820010 */  addiu     $v0, $a0, 0x10
/* 8FEF90 80240110 AC8B0000 */  sw        $t3, ($a0)
/* 8FEF94 80240114 AC920004 */  sw        $s2, 4($a0)
/* 8FEF98 80240118 AD020000 */  sw        $v0, ($t0)
/* 8FEF9C 8024011C 24820018 */  addiu     $v0, $a0, 0x18
/* 8FEFA0 80240120 AC910008 */  sw        $s1, 8($a0)
/* 8FEFA4 80240124 AC80000C */  sw        $zero, 0xc($a0)
/* 8FEFA8 80240128 AD020000 */  sw        $v0, ($t0)
/* 8FEFAC 8024012C 24820020 */  addiu     $v0, $a0, 0x20
/* 8FEFB0 80240130 AC900010 */  sw        $s0, 0x10($a0)
/* 8FEFB4 80240134 AC8D0014 */  sw        $t5, 0x14($a0)
/* 8FEFB8 80240138 AD020000 */  sw        $v0, ($t0)
/* 8FEFBC 8024013C 24820028 */  addiu     $v0, $a0, 0x28
/* 8FEFC0 80240140 AC990018 */  sw        $t9, 0x18($a0)
/* 8FEFC4 80240144 AC80001C */  sw        $zero, 0x1c($a0)
/* 8FEFC8 80240148 AD020000 */  sw        $v0, ($t0)
/* 8FEFCC 8024014C 24820030 */  addiu     $v0, $a0, 0x30
/* 8FEFD0 80240150 AC8B0020 */  sw        $t3, 0x20($a0)
/* 8FEFD4 80240154 AC800024 */  sw        $zero, 0x24($a0)
/* 8FEFD8 80240158 AD020000 */  sw        $v0, ($t0)
/* 8FEFDC 8024015C 24820038 */  addiu     $v0, $a0, 0x38
/* 8FEFE0 80240160 AC980028 */  sw        $t8, 0x28($a0)
/* 8FEFE4 80240164 AC8C002C */  sw        $t4, 0x2c($a0)
/* 8FEFE8 80240168 8DE60000 */  lw        $a2, ($t7)
/* 8FEFEC 8024016C 3C03E441 */  lui       $v1, 0xe441
/* 8FEFF0 80240170 AD020000 */  sw        $v0, ($t0)
/* 8FEFF4 80240174 24C20002 */  addiu     $v0, $a2, 2
/* 8FEFF8 80240178 00A21021 */  addu      $v0, $a1, $v0
/* 8FEFFC 8024017C 00021080 */  sll       $v0, $v0, 2
/* 8FF000 80240180 30420FFF */  andi      $v0, $v0, 0xfff
/* 8FF004 80240184 00431025 */  or        $v0, $v0, $v1
/* 8FF008 80240188 00A62821 */  addu      $a1, $a1, $a2
/* 8FF00C 8024018C 00052880 */  sll       $a1, $a1, 2
/* 8FF010 80240190 30A50FFF */  andi      $a1, $a1, 0xfff
/* 8FF014 80240194 AC820030 */  sw        $v0, 0x30($a0)
/* 8FF018 80240198 3C02000F */  lui       $v0, 0xf
/* 8FF01C 8024019C 00A22825 */  or        $a1, $a1, $v0
/* 8FF020 802401A0 24820040 */  addiu     $v0, $a0, 0x40
/* 8FF024 802401A4 AC850034 */  sw        $a1, 0x34($a0)
/* 8FF028 802401A8 AD020000 */  sw        $v0, ($t0)
/* 8FF02C 802401AC 3C02E100 */  lui       $v0, 0xe100
/* 8FF030 802401B0 AC820038 */  sw        $v0, 0x38($a0)
/* 8FF034 802401B4 24820048 */  addiu     $v0, $a0, 0x48
/* 8FF038 802401B8 AC80003C */  sw        $zero, 0x3c($a0)
/* 8FF03C 802401BC AD020000 */  sw        $v0, ($t0)
/* 8FF040 802401C0 3C02F100 */  lui       $v0, 0xf100
/* 8FF044 802401C4 AC820040 */  sw        $v0, 0x40($a0)
/* 8FF048 802401C8 29220038 */  slti      $v0, $t1, 0x38
/* 8FF04C 802401CC 1440FFC0 */  bnez      $v0, .L802400D0
/* 8FF050 802401D0 AC870044 */   sw       $a3, 0x44($a0)
/* 8FF054 802401D4 3C03800A */  lui       $v1, %hi(D_8009A66C)
/* 8FF058 802401D8 2463A66C */  addiu     $v1, $v1, %lo(D_8009A66C)
/* 8FF05C 802401DC 8C620000 */  lw        $v0, ($v1)
/* 8FF060 802401E0 0040202D */  daddu     $a0, $v0, $zero
/* 8FF064 802401E4 24420008 */  addiu     $v0, $v0, 8
/* 8FF068 802401E8 AC620000 */  sw        $v0, ($v1)
/* 8FF06C 802401EC 3C02E700 */  lui       $v0, 0xe700
/* 8FF070 802401F0 AC820000 */  sw        $v0, ($a0)
/* 8FF074 802401F4 AC800004 */  sw        $zero, 4($a0)
/* 8FF078 802401F8 8FB3000C */  lw        $s3, 0xc($sp)
/* 8FF07C 802401FC 8FB20008 */  lw        $s2, 8($sp)
/* 8FF080 80240200 8FB10004 */  lw        $s1, 4($sp)
/* 8FF084 80240204 8FB00000 */  lw        $s0, ($sp)
/* 8FF088 80240208 03E00008 */  jr        $ra
/* 8FF08C 8024020C 27BD0010 */   addiu    $sp, $sp, 0x10
