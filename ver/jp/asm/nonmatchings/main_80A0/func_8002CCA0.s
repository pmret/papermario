.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002CCA0
/* 80A0 8002CCA0 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* 80A4 8002CCA4 3C04800E */  lui       $a0, %hi(D_800DAC70)
/* 80A8 8002CCA8 2484AC70 */  addiu     $a0, $a0, %lo(D_800DAC70)
/* 80AC 8002CCAC 3C05800A */  lui       $a1, %hi(D_8009E6B0)
/* 80B0 8002CCB0 24A5E6B0 */  addiu     $a1, $a1, %lo(D_8009E6B0)
/* 80B4 8002CCB4 24060008 */  addiu     $a2, $zero, 8
/* 80B8 8002CCB8 AFBF0028 */  sw        $ra, 0x28($sp)
/* 80BC 8002CCBC AFB30024 */  sw        $s3, 0x24($sp)
/* 80C0 8002CCC0 AFB20020 */  sw        $s2, 0x20($sp)
/* 80C4 8002CCC4 AFB1001C */  sw        $s1, 0x1c($sp)
/* 80C8 8002CCC8 0C019554 */  jal       func_80065550
/* 80CC 8002CCCC AFB00018 */   sw       $s0, 0x18($sp)
/* 80D0 8002CCD0 24130004 */  addiu     $s3, $zero, 4
/* 80D4 8002CCD4 24120008 */  addiu     $s2, $zero, 8
/* 80D8 8002CCD8 3C11800A */  lui       $s1, %hi(D_8009A5D8)
/* 80DC 8002CCDC 2631A5D8 */  addiu     $s1, $s1, %lo(D_8009A5D8)
/* 80E0 8002CCE0 3C10800A */  lui       $s0, %hi(D_8009A5F8)
/* 80E4 8002CCE4 2610A5F8 */  addiu     $s0, $s0, %lo(D_8009A5F8)
.L8002CCE8:
/* 80E8 8002CCE8 3C04800E */  lui       $a0, %hi(D_800DAC70)
/* 80EC 8002CCEC 2484AC70 */  addiu     $a0, $a0, %lo(D_800DAC70)
/* 80F0 8002CCF0 27A50010 */  addiu     $a1, $sp, 0x10
/* 80F4 8002CCF4 0C0195B0 */  jal       func_800656C0
/* 80F8 8002CCF8 24060001 */   addiu    $a2, $zero, 1
/* 80FC 8002CCFC 8FA40010 */  lw        $a0, 0x10($sp)
/* 8100 8002CD00 8C820054 */  lw        $v0, 0x54($a0)
/* 8104 8002CD04 84420000 */  lh        $v0, ($v0)
/* 8108 8002CD08 10530005 */  beq       $v0, $s3, .L8002CD20
/* 810C 8002CD0C 00000000 */   nop
/* 8110 8002CD10 10520012 */  beq       $v0, $s2, .L8002CD5C
/* 8114 8002CD14 00000000 */   nop
/* 8118 8002CD18 0800B33A */  j         .L8002CCE8
/* 811C 8002CD1C 00000000 */   nop
.L8002CD20:
/* 8120 8002CD20 3C028007 */  lui       $v0, %hi(D_800773D4)
/* 8124 8002CD24 8C4273D4 */  lw        $v0, %lo(D_800773D4)($v0)
/* 8128 8002CD28 10400003 */  beqz      $v0, .L8002CD38
/* 812C 8002CD2C 00000000 */   nop
/* 8130 8002CD30 0040F809 */  jalr      $v0
/* 8134 8002CD34 00000000 */   nop
.L8002CD38:
/* 8138 8002CD38 8E220000 */  lw        $v0, ($s1)
/* 813C 8002CD3C 30420080 */  andi      $v0, $v0, 0x80
/* 8140 8002CD40 1040000C */  beqz      $v0, .L8002CD74
/* 8144 8002CD44 00000000 */   nop
/* 8148 8002CD48 0C019CD4 */  jal       func_80067350
/* 814C 8002CD4C 0000202D */   daddu    $a0, $zero, $zero
/* 8150 8002CD50 24020001 */  addiu     $v0, $zero, 1
/* 8154 8002CD54 0800B35D */  j         .L8002CD74
/* 8158 8002CD58 AE220000 */   sw       $v0, ($s1)
.L8002CD5C:
/* 815C 8002CD5C 3C028007 */  lui       $v0, %hi(D_800773D8)
/* 8160 8002CD60 8C4273D8 */  lw        $v0, %lo(D_800773D8)($v0)
/* 8164 8002CD64 10400003 */  beqz      $v0, .L8002CD74
/* 8168 8002CD68 00000000 */   nop
/* 816C 8002CD6C 0040F809 */  jalr      $v0
/* 8170 8002CD70 00000000 */   nop
.L8002CD74:
/* 8174 8002CD74 0C018244 */  jal       func_80060910
/* 8178 8002CD78 24040001 */   addiu    $a0, $zero, 1
/* 817C 8002CD7C 8E030000 */  lw        $v1, ($s0)
/* 8180 8002CD80 0040202D */  daddu     $a0, $v0, $zero
/* 8184 8002CD84 2463FFFF */  addiu     $v1, $v1, -1
/* 8188 8002CD88 0C018244 */  jal       func_80060910
/* 818C 8002CD8C AE030000 */   sw       $v1, ($s0)
/* 8190 8002CD90 0800B33A */  j         .L8002CCE8
/* 8194 8002CD94 00000000 */   nop
/* 8198 8002CD98 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 819C 8002CD9C 24020008 */  addiu     $v0, $zero, 8
/* 81A0 8002CDA0 3C01800A */  lui       $at, %hi(D_8009C4F4)
/* 81A4 8002CDA4 A422C4F4 */  sh        $v0, %lo(D_8009C4F4)($at)
/* 81A8 8002CDA8 24020004 */  addiu     $v0, $zero, 4
/* 81AC 8002CDAC 3C01800A */  lui       $at, %hi(D_8009C4F6)
/* 81B0 8002CDB0 A422C4F6 */  sh        $v0, %lo(D_8009C4F6)($at)
/* 81B4 8002CDB4 3C02800A */  lui       $v0, %hi(D_8009A5F8)
/* 81B8 8002CDB8 2442A5F8 */  addiu     $v0, $v0, %lo(D_8009A5F8)
/* 81BC 8002CDBC AFBF0038 */  sw        $ra, 0x38($sp)
/* 81C0 8002CDC0 AFB70034 */  sw        $s7, 0x34($sp)
/* 81C4 8002CDC4 AFB60030 */  sw        $s6, 0x30($sp)
/* 81C8 8002CDC8 AFB5002C */  sw        $s5, 0x2c($sp)
/* 81CC 8002CDCC AFB40028 */  sw        $s4, 0x28($sp)
/* 81D0 8002CDD0 AFB30024 */  sw        $s3, 0x24($sp)
/* 81D4 8002CDD4 AFB20020 */  sw        $s2, 0x20($sp)
/* 81D8 8002CDD8 AFB1001C */  sw        $s1, 0x1c($sp)
/* 81DC 8002CDDC AFB00018 */  sw        $s0, 0x18($sp)
/* 81E0 8002CDE0 AC400000 */  sw        $zero, ($v0)
/* 81E4 8002CDE4 0C017C2C */  jal       func_8005F0B0
/* 81E8 8002CDE8 0000902D */   daddu    $s2, $zero, $zero
/* 81EC 8002CDEC 3C10800A */  lui       $s0, %hi(D_8009C4F8)
/* 81F0 8002CDF0 2610C4F8 */  addiu     $s0, $s0, %lo(D_8009C4F8)
/* 81F4 8002CDF4 0200202D */  daddu     $a0, $s0, $zero
/* 81F8 8002CDF8 24050005 */  addiu     $a1, $zero, 5
/* 81FC 8002CDFC 3C068003 */  lui       $a2, %hi(func_8002CCA0)
/* 8200 8002CE00 24C6CCA0 */  addiu     $a2, $a2, %lo(func_8002CCA0)
/* 8204 8002CE04 3C02800A */  lui       $v0, %hi(D_8009E6B0)
/* 8208 8002CE08 2442E6B0 */  addiu     $v0, $v0, %lo(D_8009E6B0)
/* 820C 8002CE0C AFA20010 */  sw        $v0, 0x10($sp)
/* 8210 8002CE10 2402003C */  addiu     $v0, $zero, 0x3c
/* 8214 8002CE14 0000382D */  daddu     $a3, $zero, $zero
/* 8218 8002CE18 0C01978C */  jal       func_80065E30
/* 821C 8002CE1C AFA20014 */   sw       $v0, 0x14($sp)
/* 8220 8002CE20 0C0197FC */  jal       func_80065FF0
/* 8224 8002CE24 0200202D */   daddu    $a0, $s0, $zero
/* 8228 8002CE28 3C17800E */  lui       $s7, %hi(D_800DAC70)
/* 822C 8002CE2C 26F7AC70 */  addiu     $s7, $s7, %lo(D_800DAC70)
/* 8230 8002CE30 24160001 */  addiu     $s6, $zero, 1
/* 8234 8002CE34 3C13800E */  lui       $s3, %hi(D_800D9760)
/* 8238 8002CE38 26739760 */  addiu     $s3, $s3, %lo(D_800D9760)
/* 823C 8002CE3C 24150100 */  addiu     $s5, $zero, 0x100
/* 8240 8002CE40 24141000 */  addiu     $s4, $zero, 0x1000
/* 8244 8002CE44 3C02800E */  lui       $v0, %hi(D_800D9258)
/* 8248 8002CE48 24429258 */  addiu     $v0, $v0, %lo(D_800D9258)
/* 824C 8002CE4C 0040802D */  daddu     $s0, $v0, $zero
/* 8250 8002CE50 26110058 */  addiu     $s1, $s0, 0x58
.L8002CE54:
/* 8254 8002CE54 3C04B000 */  lui       $a0, 0xb000
/* 8258 8002CE58 34840B70 */  ori       $a0, $a0, 0xb70
/* 825C 8002CE5C 3C05B000 */  lui       $a1, 0xb000
/* 8260 8002CE60 34A50C70 */  ori       $a1, $a1, 0xc70
/* 8264 8002CE64 0260302D */  daddu     $a2, $s3, $zero
/* 8268 8002CE68 AE110000 */  sw        $s1, ($s0)
/* 826C 8002CE6C AE170050 */  sw        $s7, 0x50($s0)
/* 8270 8002CE70 AE160010 */  sw        $s6, 0x10($s0)
/* 8274 8002CE74 0C00A5BF */  jal       func_800296FC
/* 8278 8002CE78 AE000014 */   sw       $zero, 0x14($s0)
/* 827C 8002CE7C 24020800 */  addiu     $v0, $zero, 0x800
/* 8280 8002CE80 AE02002C */  sw        $v0, 0x2c($s0)
/* 8284 8002CE84 3C02800E */  lui       $v0, %hi(D_800DA020)
/* 8288 8002CE88 2442A020 */  addiu     $v0, $v0, %lo(D_800DA020)
/* 828C 8002CE8C AE020030 */  sw        $v0, 0x30($s0)
/* 8290 8002CE90 24020400 */  addiu     $v0, $zero, 0x400
/* 8294 8002CE94 AE020034 */  sw        $v0, 0x34($s0)
/* 8298 8002CE98 3C02800C */  lui       $v0, %hi(D_800B91B0)
/* 829C 8002CE9C 244291B0 */  addiu     $v0, $v0, %lo(D_800B91B0)
/* 82A0 8002CEA0 AE020038 */  sw        $v0, 0x38($s0)
/* 82A4 8002CEA4 3C02800E */  lui       $v0, %hi(D_800D91B0)
/* 82A8 8002CEA8 244291B0 */  addiu     $v0, $v0, %lo(D_800D91B0)
/* 82AC 8002CEAC AE02003C */  sw        $v0, 0x3c($s0)
/* 82B0 8002CEB0 3C02800C */  lui       $v0, %hi(D_800B8570)
/* 82B4 8002CEB4 24428570 */  addiu     $v0, $v0, %lo(D_800B8570)
/* 82B8 8002CEB8 AE020048 */  sw        $v0, 0x48($s0)
/* 82BC 8002CEBC 24020C10 */  addiu     $v0, $zero, 0xc10
/* 82C0 8002CEC0 AE130018 */  sw        $s3, 0x18($s0)
/* 82C4 8002CEC4 AE15001C */  sw        $s5, 0x1c($s0)
/* 82C8 8002CEC8 AE140024 */  sw        $s4, 0x24($s0)
/* 82CC 8002CECC AE02004C */  sw        $v0, 0x4c($s0)
/* 82D0 8002CED0 26100058 */  addiu     $s0, $s0, 0x58
/* 82D4 8002CED4 26520001 */  addiu     $s2, $s2, 1
/* 82D8 8002CED8 2E42000A */  sltiu     $v0, $s2, 0xa
/* 82DC 8002CEDC 1440FFDD */  bnez      $v0, .L8002CE54
/* 82E0 8002CEE0 26310058 */   addiu    $s1, $s1, 0x58
/* 82E4 8002CEE4 3C02800E */  lui       $v0, %hi(D_800D9258)
/* 82E8 8002CEE8 24429258 */  addiu     $v0, $v0, %lo(D_800D9258)
/* 82EC 8002CEEC AC420318 */  sw        $v0, 0x318($v0)
/* 82F0 8002CEF0 8FBF0038 */  lw        $ra, 0x38($sp)
/* 82F4 8002CEF4 8FB70034 */  lw        $s7, 0x34($sp)
/* 82F8 8002CEF8 8FB60030 */  lw        $s6, 0x30($sp)
/* 82FC 8002CEFC 8FB5002C */  lw        $s5, 0x2c($sp)
/* 8300 8002CF00 8FB40028 */  lw        $s4, 0x28($sp)
/* 8304 8002CF04 8FB30024 */  lw        $s3, 0x24($sp)
/* 8308 8002CF08 8FB20020 */  lw        $s2, 0x20($sp)
/* 830C 8002CF0C 8FB1001C */  lw        $s1, 0x1c($sp)
/* 8310 8002CF10 8FB00018 */  lw        $s0, 0x18($sp)
/* 8314 8002CF14 3C01800A */  lui       $at, %hi(D_8009C4F0)
/* 8318 8002CF18 AC22C4F0 */  sw        $v0, %lo(D_8009C4F0)($at)
/* 831C 8002CF1C 03E00008 */  jr        $ra
/* 8320 8002CF20 27BD0040 */   addiu    $sp, $sp, 0x40
