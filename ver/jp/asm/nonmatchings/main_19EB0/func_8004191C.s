.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004191C
/* 1CD1C 8004191C 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* 1CD20 80041920 3C05800B */  lui       $a1, %hi(D_800B0EF0)
/* 1CD24 80041924 24A50EF0 */  addiu     $a1, $a1, %lo(D_800B0EF0)
/* 1CD28 80041928 AFBF0054 */  sw        $ra, 0x54($sp)
/* 1CD2C 8004192C AFB00050 */  sw        $s0, 0x50($sp)
/* 1CD30 80041930 8CA20094 */  lw        $v0, 0x94($a1)
/* 1CD34 80041934 14400005 */  bnez      $v0, .L8004194C
/* 1CD38 80041938 2402FF38 */   addiu    $v0, $zero, -0xc8
/* 1CD3C 8004193C 3C01800A */  lui       $at, %hi(D_8009A648)
/* 1CD40 80041940 A422A648 */  sh        $v0, %lo(D_8009A648)($at)
/* 1CD44 80041944 080106F0 */  j         .L80041BC0
/* 1CD48 80041948 00000000 */   nop
.L8004194C:
/* 1CD4C 8004194C 3C02800A */  lui       $v0, %hi(D_8009A648)
/* 1CD50 80041950 2442A648 */  addiu     $v0, $v0, %lo(D_8009A648)
/* 1CD54 80041954 94430000 */  lhu       $v1, ($v0)
/* 1CD58 80041958 24630028 */  addiu     $v1, $v1, 0x28
/* 1CD5C 8004195C 00032400 */  sll       $a0, $v1, 0x10
/* 1CD60 80041960 00048403 */  sra       $s0, $a0, 0x10
/* 1CD64 80041964 1A000005 */  blez      $s0, .L8004197C
/* 1CD68 80041968 A4430000 */   sh       $v1, ($v0)
/* 1CD6C 8004196C 2A020640 */  slti      $v0, $s0, 0x640
/* 1CD70 80041970 10400002 */  beqz      $v0, .L8004197C
/* 1CD74 80041974 2610F9C0 */   addiu    $s0, $s0, -0x640
/* 1CD78 80041978 0000802D */  daddu     $s0, $zero, $zero
.L8004197C:
/* 1CD7C 8004197C 80A30004 */  lb        $v1, 4($a1)
/* 1CD80 80041980 24020001 */  addiu     $v0, $zero, 1
/* 1CD84 80041984 10620005 */  beq       $v1, $v0, .L8004199C
/* 1CD88 80041988 24020002 */   addiu    $v0, $zero, 2
/* 1CD8C 8004198C 1062005D */  beq       $v1, $v0, .L80041B04
/* 1CD90 80041990 00000000 */   nop
/* 1CD94 80041994 080106F0 */  j         .L80041BC0
/* 1CD98 80041998 00000000 */   nop
.L8004199C:
/* 1CD9C 8004199C 80A30005 */  lb        $v1, 5($a1)
/* 1CDA0 800419A0 24020004 */  addiu     $v0, $zero, 4
/* 1CDA4 800419A4 1062000C */  beq       $v1, $v0, .L800419D8
/* 1CDA8 800419A8 28620005 */   slti     $v0, $v1, 5
/* 1CDAC 800419AC 10400005 */  beqz      $v0, .L800419C4
/* 1CDB0 800419B0 24020002 */   addiu    $v0, $zero, 2
/* 1CDB4 800419B4 10620009 */  beq       $v1, $v0, .L800419DC
/* 1CDB8 800419B8 3C040020 */   lui      $a0, 0x20
/* 1CDBC 800419BC 080106F0 */  j         .L80041BC0
/* 1CDC0 800419C0 00000000 */   nop
.L800419C4:
/* 1CDC4 800419C4 24020006 */  addiu     $v0, $zero, 6
/* 1CDC8 800419C8 10620029 */  beq       $v1, $v0, .L80041A70
/* 1CDCC 800419CC 3C040020 */   lui      $a0, 0x20
/* 1CDD0 800419D0 080106F0 */  j         .L80041BC0
/* 1CDD4 800419D4 00000000 */   nop
.L800419D8:
/* 1CDD8 800419D8 3C040020 */  lui       $a0, 0x20
.L800419DC:
/* 1CDDC 800419DC 348400C4 */  ori       $a0, $a0, 0xc4
/* 1CDE0 800419E0 0C04ADB5 */  jal       func_8012B6D4
/* 1CDE4 800419E4 0000282D */   daddu    $a1, $zero, $zero
/* 1CDE8 800419E8 24480018 */  addiu     $t0, $v0, 0x18
/* 1CDEC 800419EC 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1CDF0 800419F0 000817C2 */  srl       $v0, $t0, 0x1f
/* 1CDF4 800419F4 01021021 */  addu      $v0, $t0, $v0
/* 1CDF8 800419F8 00021043 */  sra       $v0, $v0, 1
/* 1CDFC 800419FC 00628023 */  subu      $s0, $v1, $v0
/* 1CE00 80041A00 0000202D */  daddu     $a0, $zero, $zero
/* 1CE04 80041A04 24050014 */  addiu     $a1, $zero, 0x14
/* 1CE08 80041A08 0200302D */  daddu     $a2, $s0, $zero
/* 1CE0C 80041A0C 24070045 */  addiu     $a3, $zero, 0x45
/* 1CE10 80041A10 2402001C */  addiu     $v0, $zero, 0x1c
/* 1CE14 80041A14 AFA20018 */  sw        $v0, 0x18($sp)
/* 1CE18 80041A18 240200FF */  addiu     $v0, $zero, 0xff
/* 1CE1C 80041A1C AFA2001C */  sw        $v0, 0x1c($sp)
/* 1CE20 80041A20 24020140 */  addiu     $v0, $zero, 0x140
/* 1CE24 80041A24 AFA20044 */  sw        $v0, 0x44($sp)
/* 1CE28 80041A28 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1CE2C 80041A2C AFA00010 */  sw        $zero, 0x10($sp)
/* 1CE30 80041A30 AFA80014 */  sw        $t0, 0x14($sp)
/* 1CE34 80041A34 AFA00020 */  sw        $zero, 0x20($sp)
/* 1CE38 80041A38 AFA00024 */  sw        $zero, 0x24($sp)
/* 1CE3C 80041A3C AFA00028 */  sw        $zero, 0x28($sp)
/* 1CE40 80041A40 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1CE44 80041A44 AFA00030 */  sw        $zero, 0x30($sp)
/* 1CE48 80041A48 AFA00034 */  sw        $zero, 0x34($sp)
/* 1CE4C 80041A4C AFA00038 */  sw        $zero, 0x38($sp)
/* 1CE50 80041A50 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1CE54 80041A54 AFA00040 */  sw        $zero, 0x40($sp)
/* 1CE58 80041A58 AFA20048 */  sw        $v0, 0x48($sp)
/* 1CE5C 80041A5C 0C03D51C */  jal       func_800F5470
/* 1CE60 80041A60 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1CE64 80041A64 3C040020 */  lui       $a0, 0x20
/* 1CE68 80041A68 080106E9 */  j         .L80041BA4
/* 1CE6C 80041A6C 348400C4 */   ori      $a0, $a0, 0xc4
.L80041A70:
/* 1CE70 80041A70 348400C5 */  ori       $a0, $a0, 0xc5
/* 1CE74 80041A74 0C04ADB5 */  jal       func_8012B6D4
/* 1CE78 80041A78 0000282D */   daddu    $a1, $zero, $zero
/* 1CE7C 80041A7C 24480018 */  addiu     $t0, $v0, 0x18
/* 1CE80 80041A80 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1CE84 80041A84 000817C2 */  srl       $v0, $t0, 0x1f
/* 1CE88 80041A88 01021021 */  addu      $v0, $t0, $v0
/* 1CE8C 80041A8C 00021043 */  sra       $v0, $v0, 1
/* 1CE90 80041A90 00628023 */  subu      $s0, $v1, $v0
/* 1CE94 80041A94 0000202D */  daddu     $a0, $zero, $zero
/* 1CE98 80041A98 24050014 */  addiu     $a1, $zero, 0x14
/* 1CE9C 80041A9C 0200302D */  daddu     $a2, $s0, $zero
/* 1CEA0 80041AA0 24070045 */  addiu     $a3, $zero, 0x45
/* 1CEA4 80041AA4 2402001C */  addiu     $v0, $zero, 0x1c
/* 1CEA8 80041AA8 AFA20018 */  sw        $v0, 0x18($sp)
/* 1CEAC 80041AAC 240200FF */  addiu     $v0, $zero, 0xff
/* 1CEB0 80041AB0 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1CEB4 80041AB4 24020140 */  addiu     $v0, $zero, 0x140
/* 1CEB8 80041AB8 AFA20044 */  sw        $v0, 0x44($sp)
/* 1CEBC 80041ABC 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1CEC0 80041AC0 AFA00010 */  sw        $zero, 0x10($sp)
/* 1CEC4 80041AC4 AFA80014 */  sw        $t0, 0x14($sp)
/* 1CEC8 80041AC8 AFA00020 */  sw        $zero, 0x20($sp)
/* 1CECC 80041ACC AFA00024 */  sw        $zero, 0x24($sp)
/* 1CED0 80041AD0 AFA00028 */  sw        $zero, 0x28($sp)
/* 1CED4 80041AD4 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1CED8 80041AD8 AFA00030 */  sw        $zero, 0x30($sp)
/* 1CEDC 80041ADC AFA00034 */  sw        $zero, 0x34($sp)
/* 1CEE0 80041AE0 AFA00038 */  sw        $zero, 0x38($sp)
/* 1CEE4 80041AE4 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1CEE8 80041AE8 AFA00040 */  sw        $zero, 0x40($sp)
/* 1CEEC 80041AEC AFA20048 */  sw        $v0, 0x48($sp)
/* 1CEF0 80041AF0 0C03D51C */  jal       func_800F5470
/* 1CEF4 80041AF4 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1CEF8 80041AF8 3C040020 */  lui       $a0, 0x20
/* 1CEFC 80041AFC 080106E9 */  j         .L80041BA4
/* 1CF00 80041B00 348400C5 */   ori      $a0, $a0, 0xc5
.L80041B04:
/* 1CF04 80041B04 0C03A73A */  jal       func_800E9CE8
/* 1CF08 80041B08 24040011 */   addiu    $a0, $zero, 0x11
/* 1CF0C 80041B0C 1440002C */  bnez      $v0, .L80041BC0
/* 1CF10 80041B10 3C040020 */   lui      $a0, 0x20
/* 1CF14 80041B14 348400C6 */  ori       $a0, $a0, 0xc6
/* 1CF18 80041B18 0C04ADB5 */  jal       func_8012B6D4
/* 1CF1C 80041B1C 0000282D */   daddu    $a1, $zero, $zero
/* 1CF20 80041B20 24480018 */  addiu     $t0, $v0, 0x18
/* 1CF24 80041B24 260300A0 */  addiu     $v1, $s0, 0xa0
/* 1CF28 80041B28 000817C2 */  srl       $v0, $t0, 0x1f
/* 1CF2C 80041B2C 01021021 */  addu      $v0, $t0, $v0
/* 1CF30 80041B30 00021043 */  sra       $v0, $v0, 1
/* 1CF34 80041B34 00628023 */  subu      $s0, $v1, $v0
/* 1CF38 80041B38 0000202D */  daddu     $a0, $zero, $zero
/* 1CF3C 80041B3C 24050004 */  addiu     $a1, $zero, 4
/* 1CF40 80041B40 0200302D */  daddu     $a2, $s0, $zero
/* 1CF44 80041B44 24070045 */  addiu     $a3, $zero, 0x45
/* 1CF48 80041B48 2402001C */  addiu     $v0, $zero, 0x1c
/* 1CF4C 80041B4C AFA20018 */  sw        $v0, 0x18($sp)
/* 1CF50 80041B50 240200FF */  addiu     $v0, $zero, 0xff
/* 1CF54 80041B54 AFA2001C */  sw        $v0, 0x1c($sp)
/* 1CF58 80041B58 24020140 */  addiu     $v0, $zero, 0x140
/* 1CF5C 80041B5C AFA20044 */  sw        $v0, 0x44($sp)
/* 1CF60 80041B60 240200F0 */  addiu     $v0, $zero, 0xf0
/* 1CF64 80041B64 AFA00010 */  sw        $zero, 0x10($sp)
/* 1CF68 80041B68 AFA80014 */  sw        $t0, 0x14($sp)
/* 1CF6C 80041B6C AFA00020 */  sw        $zero, 0x20($sp)
/* 1CF70 80041B70 AFA00024 */  sw        $zero, 0x24($sp)
/* 1CF74 80041B74 AFA00028 */  sw        $zero, 0x28($sp)
/* 1CF78 80041B78 AFA0002C */  sw        $zero, 0x2c($sp)
/* 1CF7C 80041B7C AFA00030 */  sw        $zero, 0x30($sp)
/* 1CF80 80041B80 AFA00034 */  sw        $zero, 0x34($sp)
/* 1CF84 80041B84 AFA00038 */  sw        $zero, 0x38($sp)
/* 1CF88 80041B88 AFA0003C */  sw        $zero, 0x3c($sp)
/* 1CF8C 80041B8C AFA00040 */  sw        $zero, 0x40($sp)
/* 1CF90 80041B90 AFA20048 */  sw        $v0, 0x48($sp)
/* 1CF94 80041B94 0C03D51C */  jal       func_800F5470
/* 1CF98 80041B98 AFA0004C */   sw       $zero, 0x4c($sp)
/* 1CF9C 80041B9C 3C040020 */  lui       $a0, 0x20
/* 1CFA0 80041BA0 348400C6 */  ori       $a0, $a0, 0xc6
.L80041BA4:
/* 1CFA4 80041BA4 2605000B */  addiu     $a1, $s0, 0xb
/* 1CFA8 80041BA8 2406004B */  addiu     $a2, $zero, 0x4b
/* 1CFAC 80041BAC 240700FF */  addiu     $a3, $zero, 0xff
/* 1CFB0 80041BB0 2402000A */  addiu     $v0, $zero, 0xa
/* 1CFB4 80041BB4 AFA20010 */  sw        $v0, 0x10($sp)
/* 1CFB8 80041BB8 0C04ADC4 */  jal       func_8012B710
/* 1CFBC 80041BBC AFA00014 */   sw       $zero, 0x14($sp)
.L80041BC0:
/* 1CFC0 80041BC0 8FBF0054 */  lw        $ra, 0x54($sp)
/* 1CFC4 80041BC4 8FB00050 */  lw        $s0, 0x50($sp)
/* 1CFC8 80041BC8 03E00008 */  jr        $ra
/* 1CFCC 80041BCC 27BD0058 */   addiu    $sp, $sp, 0x58
