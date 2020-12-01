.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802AACD8
/* 41FA68 802AACD8 27BDFF58 */  addiu     $sp, $sp, -0xa8
/* 41FA6C 802AACDC 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 41FA70 802AACE0 8C42C070 */  lw        $v0, %lo(gBattleStatus)($v0)
/* 41FA74 802AACE4 3C030008 */  lui       $v1, 8
/* 41FA78 802AACE8 AFBF008C */  sw        $ra, 0x8c($sp)
/* 41FA7C 802AACEC AFBE0088 */  sw        $fp, 0x88($sp)
/* 41FA80 802AACF0 AFB70084 */  sw        $s7, 0x84($sp)
/* 41FA84 802AACF4 AFB60080 */  sw        $s6, 0x80($sp)
/* 41FA88 802AACF8 AFB5007C */  sw        $s5, 0x7c($sp)
/* 41FA8C 802AACFC AFB40078 */  sw        $s4, 0x78($sp)
/* 41FA90 802AAD00 AFB30074 */  sw        $s3, 0x74($sp)
/* 41FA94 802AAD04 AFB20070 */  sw        $s2, 0x70($sp)
/* 41FA98 802AAD08 AFB1006C */  sw        $s1, 0x6c($sp)
/* 41FA9C 802AAD0C AFB00068 */  sw        $s0, 0x68($sp)
/* 41FAA0 802AAD10 F7B800A0 */  sdc1      $f24, 0xa0($sp)
/* 41FAA4 802AAD14 F7B60098 */  sdc1      $f22, 0x98($sp)
/* 41FAA8 802AAD18 F7B40090 */  sdc1      $f20, 0x90($sp)
/* 41FAAC 802AAD1C 00431024 */  and       $v0, $v0, $v1
/* 41FAB0 802AAD20 14400005 */  bnez      $v0, .L802AAD38
/* 41FAB4 802AAD24 00000000 */   nop      
/* 41FAB8 802AAD28 3C16800E */  lui       $s6, %hi(gBattleStatus+0xD8)
/* 41FABC 802AAD2C 8ED6C148 */  lw        $s6, %lo(gBattleStatus+0xD8)($s6)
/* 41FAC0 802AAD30 080AAB50 */  j         .L802AAD40
/* 41FAC4 802AAD34 00000000 */   nop      
.L802AAD38:
/* 41FAC8 802AAD38 3C16800E */  lui       $s6, %hi(gBattleStatus+0xDC)
/* 41FACC 802AAD3C 8ED6C14C */  lw        $s6, %lo(gBattleStatus+0xDC)($s6)
.L802AAD40:
/* 41FAD0 802AAD40 82C9040C */  lb        $t1, 0x40c($s6)
/* 41FAD4 802AAD44 AFA9005C */  sw        $t1, 0x5c($sp)
/* 41FAD8 802AAD48 82C90425 */  lb        $t1, 0x425($s6)
/* 41FADC 802AAD4C 26D1022C */  addiu     $s1, $s6, 0x22c
/* 41FAE0 802AAD50 AFA90060 */  sw        $t1, 0x60($sp)
/* 41FAE4 802AAD54 8FA9005C */  lw        $t1, 0x5c($sp)
/* 41FAE8 802AAD58 11200166 */  beqz      $t1, .L802AB2F4
/* 41FAEC 802AAD5C 26D7040D */   addiu    $s7, $s6, 0x40d
/* 41FAF0 802AAD60 3C02800E */  lui       $v0, %hi(gBattleStatus+0x184)
/* 41FAF4 802AAD64 8C42C1F4 */  lw        $v0, %lo(gBattleStatus+0x184)($v0)
/* 41FAF8 802AAD68 30420001 */  andi      $v0, $v0, 1
/* 41FAFC 802AAD6C 10400045 */  beqz      $v0, .L802AAE84
/* 41FB00 802AAD70 00000000 */   nop      
/* 41FB04 802AAD74 8FA90060 */  lw        $t1, 0x60($sp)
/* 41FB08 802AAD78 02E91021 */  addu      $v0, $s7, $t1
/* 41FB0C 802AAD7C 80430000 */  lb        $v1, ($v0)
/* 41FB10 802AAD80 00031080 */  sll       $v0, $v1, 2
/* 41FB14 802AAD84 00431021 */  addu      $v0, $v0, $v1
/* 41FB18 802AAD88 00021080 */  sll       $v0, $v0, 2
/* 41FB1C 802AAD8C 2442022C */  addiu     $v0, $v0, 0x22c
/* 41FB20 802AAD90 02C28821 */  addu      $s1, $s6, $v0
/* 41FB24 802AAD94 0C09A75B */  jal       get_actor
/* 41FB28 802AAD98 86240000 */   lh       $a0, ($s1)
/* 41FB2C 802AAD9C 3C10802B */  lui       $s0, 0x802b
/* 41FB30 802AADA0 8E10CC70 */  lw        $s0, -0x3390($s0)
/* 41FB34 802AADA4 86230004 */  lh        $v1, 4($s1)
/* 41FB38 802AADA8 86240006 */  lh        $a0, 6($s1)
/* 41FB3C 802AADAC 8C420000 */  lw        $v0, ($v0)
/* 41FB40 802AADB0 4483B000 */  mtc1      $v1, $f22
/* 41FB44 802AADB4 00000000 */  nop       
/* 41FB48 802AADB8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 41FB4C 802AADBC 4484C000 */  mtc1      $a0, $f24
/* 41FB50 802AADC0 00000000 */  nop       
/* 41FB54 802AADC4 4680C620 */  cvt.s.w   $f24, $f24
/* 41FB58 802AADC8 86230008 */  lh        $v1, 8($s1)
/* 41FB5C 802AADCC 30420800 */  andi      $v0, $v0, 0x800
/* 41FB60 802AADD0 4483A000 */  mtc1      $v1, $f20
/* 41FB64 802AADD4 00000000 */  nop       
/* 41FB68 802AADD8 4680A520 */  cvt.s.w   $f20, $f20
/* 41FB6C 802AADDC 10400008 */  beqz      $v0, .L802AAE00
/* 41FB70 802AADE0 24140010 */   addiu    $s4, $zero, 0x10
/* 41FB74 802AADE4 24130002 */  addiu     $s3, $zero, 2
/* 41FB78 802AADE8 0C05122C */  jal       get_menu_icon_script
/* 41FB7C 802AADEC 0200202D */   daddu    $a0, $s0, $zero
/* 41FB80 802AADF0 3C058008 */  lui       $a1, 0x8008
/* 41FB84 802AADF4 24A50208 */  addiu     $a1, $a1, 0x208
/* 41FB88 802AADF8 080AAB86 */  j         .L802AAE18
/* 41FB8C 802AADFC 00000000 */   nop      
.L802AAE00:
/* 41FB90 802AAE00 24140005 */  addiu     $s4, $zero, 5
/* 41FB94 802AAE04 2413FFF5 */  addiu     $s3, $zero, -0xb
/* 41FB98 802AAE08 0C05122C */  jal       get_menu_icon_script
/* 41FB9C 802AAE0C 0200202D */   daddu    $a0, $s0, $zero
/* 41FBA0 802AAE10 3C058008 */  lui       $a1, 0x8008
/* 41FBA4 802AAE14 24A5FF20 */  addiu     $a1, $a1, -0xe0
.L802AAE18:
/* 41FBA8 802AAE18 50450004 */  beql      $v0, $a1, .L802AAE2C
/* 41FBAC 802AAE1C 24040001 */   addiu    $a0, $zero, 1
/* 41FBB0 802AAE20 0C0511FF */  jal       set_menu_icon_script
/* 41FBB4 802AAE24 0200202D */   daddu    $a0, $s0, $zero
/* 41FBB8 802AAE28 24040001 */  addiu     $a0, $zero, 1
.L802AAE2C:
/* 41FBBC 802AAE2C 4405B000 */  mfc1      $a1, $f22
/* 41FBC0 802AAE30 4406C000 */  mfc1      $a2, $f24
/* 41FBC4 802AAE34 4407A000 */  mfc1      $a3, $f20
/* 41FBC8 802AAE38 27A20050 */  addiu     $v0, $sp, 0x50
/* 41FBCC 802AAE3C AFA20010 */  sw        $v0, 0x10($sp)
/* 41FBD0 802AAE40 27A20054 */  addiu     $v0, $sp, 0x54
/* 41FBD4 802AAE44 AFA20014 */  sw        $v0, 0x14($sp)
/* 41FBD8 802AAE48 27A20058 */  addiu     $v0, $sp, 0x58
/* 41FBDC 802AAE4C 0C00B94E */  jal       get_screen_coords
/* 41FBE0 802AAE50 AFA20018 */   sw       $v0, 0x18($sp)
/* 41FBE4 802AAE54 0200202D */  daddu     $a0, $s0, $zero
/* 41FBE8 802AAE58 8FA50050 */  lw        $a1, 0x50($sp)
/* 41FBEC 802AAE5C 8FA60054 */  lw        $a2, 0x54($sp)
/* 41FBF0 802AAE60 00B42821 */  addu      $a1, $a1, $s4
/* 41FBF4 802AAE64 0C051261 */  jal       set_icon_render_pos
/* 41FBF8 802AAE68 00D33021 */   addu     $a2, $a2, $s3
/* 41FBFC 802AAE6C 3C05802B */  lui       $a1, 0x802b
/* 41FC00 802AAE70 8CA5CC64 */  lw        $a1, -0x339c($a1)
/* 41FC04 802AAE74 0C0513AC */  jal       icon_set_opacity
/* 41FC08 802AAE78 0200202D */   daddu    $a0, $s0, $zero
/* 41FC0C 802AAE7C 080AABED */  j         .L802AAFB4
/* 41FC10 802AAE80 00000000 */   nop      
.L802AAE84:
/* 41FC14 802AAE84 1920004B */  blez      $t1, .L802AAFB4
/* 41FC18 802AAE88 0000902D */   daddu    $s2, $zero, $zero
/* 41FC1C 802AAE8C 3C1E8008 */  lui       $fp, 0x8008
/* 41FC20 802AAE90 27DEFF20 */  addiu     $fp, $fp, -0xe0
/* 41FC24 802AAE94 3C15802B */  lui       $s5, 0x802b
/* 41FC28 802AAE98 26B5CC70 */  addiu     $s5, $s5, -0x3390
.L802AAE9C:
/* 41FC2C 802AAE9C 02F21021 */  addu      $v0, $s7, $s2
/* 41FC30 802AAEA0 80430000 */  lb        $v1, ($v0)
/* 41FC34 802AAEA4 00031080 */  sll       $v0, $v1, 2
/* 41FC38 802AAEA8 00431021 */  addu      $v0, $v0, $v1
/* 41FC3C 802AAEAC 00021080 */  sll       $v0, $v0, 2
/* 41FC40 802AAEB0 2442022C */  addiu     $v0, $v0, 0x22c
/* 41FC44 802AAEB4 02C28821 */  addu      $s1, $s6, $v0
/* 41FC48 802AAEB8 0C09A75B */  jal       get_actor
/* 41FC4C 802AAEBC 86240000 */   lh       $a0, ($s1)
/* 41FC50 802AAEC0 8EB00000 */  lw        $s0, ($s5)
/* 41FC54 802AAEC4 86230004 */  lh        $v1, 4($s1)
/* 41FC58 802AAEC8 86240006 */  lh        $a0, 6($s1)
/* 41FC5C 802AAECC 8C420000 */  lw        $v0, ($v0)
/* 41FC60 802AAED0 4483B000 */  mtc1      $v1, $f22
/* 41FC64 802AAED4 00000000 */  nop       
/* 41FC68 802AAED8 4680B5A0 */  cvt.s.w   $f22, $f22
/* 41FC6C 802AAEDC 4484C000 */  mtc1      $a0, $f24
/* 41FC70 802AAEE0 00000000 */  nop       
/* 41FC74 802AAEE4 4680C620 */  cvt.s.w   $f24, $f24
/* 41FC78 802AAEE8 86230008 */  lh        $v1, 8($s1)
/* 41FC7C 802AAEEC 30420800 */  andi      $v0, $v0, 0x800
/* 41FC80 802AAEF0 4483A000 */  mtc1      $v1, $f20
/* 41FC84 802AAEF4 00000000 */  nop       
/* 41FC88 802AAEF8 4680A520 */  cvt.s.w   $f20, $f20
/* 41FC8C 802AAEFC 1040000A */  beqz      $v0, .L802AAF28
/* 41FC90 802AAF00 24140010 */   addiu    $s4, $zero, 0x10
/* 41FC94 802AAF04 24130002 */  addiu     $s3, $zero, 2
/* 41FC98 802AAF08 0C05122C */  jal       get_menu_icon_script
/* 41FC9C 802AAF0C 0200202D */   daddu    $a0, $s0, $zero
/* 41FCA0 802AAF10 3C098008 */  lui       $t1, 0x8008
/* 41FCA4 802AAF14 25290208 */  addiu     $t1, $t1, 0x208
/* 41FCA8 802AAF18 1049000C */  beq       $v0, $t1, .L802AAF4C
/* 41FCAC 802AAF1C 0120282D */   daddu    $a1, $t1, $zero
/* 41FCB0 802AAF20 080AABD1 */  j         .L802AAF44
/* 41FCB4 802AAF24 0200202D */   daddu    $a0, $s0, $zero
.L802AAF28:
/* 41FCB8 802AAF28 24140005 */  addiu     $s4, $zero, 5
/* 41FCBC 802AAF2C 2413FFF5 */  addiu     $s3, $zero, -0xb
/* 41FCC0 802AAF30 0C05122C */  jal       get_menu_icon_script
/* 41FCC4 802AAF34 0200202D */   daddu    $a0, $s0, $zero
/* 41FCC8 802AAF38 105E0004 */  beq       $v0, $fp, .L802AAF4C
/* 41FCCC 802AAF3C 03C0282D */   daddu    $a1, $fp, $zero
/* 41FCD0 802AAF40 0200202D */  daddu     $a0, $s0, $zero
.L802AAF44:
/* 41FCD4 802AAF44 0C0511FF */  jal       set_menu_icon_script
/* 41FCD8 802AAF48 00000000 */   nop      
.L802AAF4C:
/* 41FCDC 802AAF4C 24040001 */  addiu     $a0, $zero, 1
/* 41FCE0 802AAF50 02449021 */  addu      $s2, $s2, $a0
/* 41FCE4 802AAF54 4405B000 */  mfc1      $a1, $f22
/* 41FCE8 802AAF58 4406C000 */  mfc1      $a2, $f24
/* 41FCEC 802AAF5C 4407A000 */  mfc1      $a3, $f20
/* 41FCF0 802AAF60 27A20050 */  addiu     $v0, $sp, 0x50
/* 41FCF4 802AAF64 AFA20010 */  sw        $v0, 0x10($sp)
/* 41FCF8 802AAF68 27A20054 */  addiu     $v0, $sp, 0x54
/* 41FCFC 802AAF6C AFA20014 */  sw        $v0, 0x14($sp)
/* 41FD00 802AAF70 27A20058 */  addiu     $v0, $sp, 0x58
/* 41FD04 802AAF74 0C00B94E */  jal       get_screen_coords
/* 41FD08 802AAF78 AFA20018 */   sw       $v0, 0x18($sp)
/* 41FD0C 802AAF7C 0200202D */  daddu     $a0, $s0, $zero
/* 41FD10 802AAF80 8FA50050 */  lw        $a1, 0x50($sp)
/* 41FD14 802AAF84 8FA60054 */  lw        $a2, 0x54($sp)
/* 41FD18 802AAF88 00B42821 */  addu      $a1, $a1, $s4
/* 41FD1C 802AAF8C 0C051261 */  jal       set_icon_render_pos
/* 41FD20 802AAF90 00D33021 */   addu     $a2, $a2, $s3
/* 41FD24 802AAF94 3C05802B */  lui       $a1, 0x802b
/* 41FD28 802AAF98 8CA5CC64 */  lw        $a1, -0x339c($a1)
/* 41FD2C 802AAF9C 0C0513AC */  jal       icon_set_opacity
/* 41FD30 802AAFA0 0200202D */   daddu    $a0, $s0, $zero
/* 41FD34 802AAFA4 8FA9005C */  lw        $t1, 0x5c($sp)
/* 41FD38 802AAFA8 0249102A */  slt       $v0, $s2, $t1
/* 41FD3C 802AAFAC 1440FFBB */  bnez      $v0, .L802AAE9C
/* 41FD40 802AAFB0 26B50004 */   addiu    $s5, $s5, 4
.L802AAFB4:
/* 41FD44 802AAFB4 3C028011 */  lui       $v0, %hi(gPlayerData)
/* 41FD48 802AAFB8 2442F290 */  addiu     $v0, $v0, %lo(gPlayerData)
/* 41FD4C 802AAFBC 80520012 */  lb        $s2, 0x12($v0)
/* 41FD50 802AAFC0 24020034 */  addiu     $v0, $zero, 0x34
/* 41FD54 802AAFC4 AFA20050 */  sw        $v0, 0x50($sp)
/* 41FD58 802AAFC8 3C02800E */  lui       $v0, %hi(gBattleStatus+0x4)
/* 41FD5C 802AAFCC 8C42C074 */  lw        $v0, %lo(gBattleStatus+0x4)($v0)
/* 41FD60 802AAFD0 24030040 */  addiu     $v1, $zero, 0x40
/* 41FD64 802AAFD4 00431024 */  and       $v0, $v0, $v1
/* 41FD68 802AAFD8 10400002 */  beqz      $v0, .L802AAFE4
/* 41FD6C 802AAFDC AFA30054 */   sw       $v1, 0x54($sp)
/* 41FD70 802AAFE0 2412000B */  addiu     $s2, $zero, 0xb
.L802AAFE4:
/* 41FD74 802AAFE4 3C02800E */  lui       $v0, %hi(gBattleStatus+0x184)
/* 41FD78 802AAFE8 8C42C1F4 */  lw        $v0, %lo(gBattleStatus+0x184)($v0)
/* 41FD7C 802AAFEC 30420001 */  andi      $v0, $v0, 1
/* 41FD80 802AAFF0 14400004 */  bnez      $v0, .L802AB004
/* 41FD84 802AAFF4 24020001 */   addiu    $v0, $zero, 1
/* 41FD88 802AAFF8 8FA9005C */  lw        $t1, 0x5c($sp)
/* 41FD8C 802AAFFC 15220026 */  bne       $t1, $v0, .L802AB098
/* 41FD90 802AB000 00000000 */   nop      
.L802AB004:
/* 41FD94 802AB004 86230000 */  lh        $v1, ($s1)
/* 41FD98 802AB008 14600004 */  bnez      $v1, .L802AB01C
/* 41FD9C 802AB00C 24020100 */   addiu    $v0, $zero, 0x100
/* 41FDA0 802AB010 3C04001D */  lui       $a0, 0x1d
/* 41FDA4 802AB014 080AAC3C */  j         .L802AB0F0
/* 41FDA8 802AB018 348400C4 */   ori      $a0, $a0, 0xc4
.L802AB01C:
/* 41FDAC 802AB01C 14620005 */  bne       $v1, $v0, .L802AB034
/* 41FDB0 802AB020 00121080 */   sll      $v0, $s2, 2
/* 41FDB4 802AB024 3C04802B */  lui       $a0, 0x802b
/* 41FDB8 802AB028 00822021 */  addu      $a0, $a0, $v0
/* 41FDBC 802AB02C 080AAC3C */  j         .L802AB0F0
/* 41FDC0 802AB030 8C84B738 */   lw       $a0, -0x48c8($a0)
.L802AB034:
/* 41FDC4 802AB034 8FA90060 */  lw        $t1, 0x60($sp)
/* 41FDC8 802AB038 02E91021 */  addu      $v0, $s7, $t1
/* 41FDCC 802AB03C 80430000 */  lb        $v1, ($v0)
/* 41FDD0 802AB040 00031080 */  sll       $v0, $v1, 2
/* 41FDD4 802AB044 00431021 */  addu      $v0, $v0, $v1
/* 41FDD8 802AB048 00021080 */  sll       $v0, $v0, 2
/* 41FDDC 802AB04C 2442022C */  addiu     $v0, $v0, 0x22c
/* 41FDE0 802AB050 02C28821 */  addu      $s1, $s6, $v0
/* 41FDE4 802AB054 0C09A75B */  jal       get_actor
/* 41FDE8 802AB058 86240000 */   lh       $a0, ($s1)
/* 41FDEC 802AB05C 0040802D */  daddu     $s0, $v0, $zero
/* 41FDF0 802AB060 86250002 */  lh        $a1, 2($s1)
/* 41FDF4 802AB064 0C099117 */  jal       get_actor_part
/* 41FDF8 802AB068 0200202D */   daddu    $a0, $s0, $zero
/* 41FDFC 802AB06C 8C420008 */  lw        $v0, 8($v0)
/* 41FE00 802AB070 8C440020 */  lw        $a0, 0x20($v0)
/* 41FE04 802AB074 1480001E */  bnez      $a0, .L802AB0F0
/* 41FE08 802AB078 00000000 */   nop      
/* 41FE0C 802AB07C 92020136 */  lbu       $v0, 0x136($s0)
/* 41FE10 802AB080 00021080 */  sll       $v0, $v0, 2
/* 41FE14 802AB084 3C048028 */  lui       $a0, 0x8028
/* 41FE18 802AB088 00822021 */  addu      $a0, $a0, $v0
/* 41FE1C 802AB08C 8C841104 */  lw        $a0, 0x1104($a0)
/* 41FE20 802AB090 080AAC3C */  j         .L802AB0F0
/* 41FE24 802AB094 00000000 */   nop      
.L802AB098:
/* 41FE28 802AB098 8FA90060 */  lw        $t1, 0x60($sp)
/* 41FE2C 802AB09C 02E91021 */  addu      $v0, $s7, $t1
/* 41FE30 802AB0A0 80430000 */  lb        $v1, ($v0)
/* 41FE34 802AB0A4 00031080 */  sll       $v0, $v1, 2
/* 41FE38 802AB0A8 00431021 */  addu      $v0, $v0, $v1
/* 41FE3C 802AB0AC 00021080 */  sll       $v0, $v0, 2
/* 41FE40 802AB0B0 2442022C */  addiu     $v0, $v0, 0x22c
/* 41FE44 802AB0B4 02C28821 */  addu      $s1, $s6, $v0
/* 41FE48 802AB0B8 86230000 */  lh        $v1, ($s1)
/* 41FE4C 802AB0BC 14600004 */  bnez      $v1, .L802AB0D0
/* 41FE50 802AB0C0 24020100 */   addiu    $v0, $zero, 0x100
/* 41FE54 802AB0C4 3C04001D */  lui       $a0, 0x1d
/* 41FE58 802AB0C8 080AAC3C */  j         .L802AB0F0
/* 41FE5C 802AB0CC 348400C4 */   ori      $a0, $a0, 0xc4
.L802AB0D0:
/* 41FE60 802AB0D0 14620006 */  bne       $v1, $v0, .L802AB0EC
/* 41FE64 802AB0D4 3C04001D */   lui      $a0, 0x1d
/* 41FE68 802AB0D8 00121080 */  sll       $v0, $s2, 2
/* 41FE6C 802AB0DC 3C04802B */  lui       $a0, 0x802b
/* 41FE70 802AB0E0 00822021 */  addu      $a0, $a0, $v0
/* 41FE74 802AB0E4 080AAC3C */  j         .L802AB0F0
/* 41FE78 802AB0E8 8C84B738 */   lw       $a0, -0x48c8($a0)
.L802AB0EC:
/* 41FE7C 802AB0EC 348400C5 */  ori       $a0, $a0, 0xc5
.L802AB0F0:
/* 41FE80 802AB0F0 0C04991D */  jal       get_string_width
/* 41FE84 802AB0F4 0000282D */   daddu    $a1, $zero, $zero
/* 41FE88 802AB0F8 2442000A */  addiu     $v0, $v0, 0xa
/* 41FE8C 802AB0FC 0000202D */  daddu     $a0, $zero, $zero
/* 41FE90 802AB100 8FA30050 */  lw        $v1, 0x50($sp)
/* 41FE94 802AB104 8FA70054 */  lw        $a3, 0x54($sp)
/* 41FE98 802AB108 24050004 */  addiu     $a1, $zero, 4
/* 41FE9C 802AB10C AFA20014 */  sw        $v0, 0x14($sp)
/* 41FEA0 802AB110 24020014 */  addiu     $v0, $zero, 0x14
/* 41FEA4 802AB114 AFA20018 */  sw        $v0, 0x18($sp)
/* 41FEA8 802AB118 240200FF */  addiu     $v0, $zero, 0xff
/* 41FEAC 802AB11C AFA2001C */  sw        $v0, 0x1c($sp)
/* 41FEB0 802AB120 24020140 */  addiu     $v0, $zero, 0x140
/* 41FEB4 802AB124 3C10802B */  lui       $s0, 0x802b
/* 41FEB8 802AB128 2610CC68 */  addiu     $s0, $s0, -0x3398
/* 41FEBC 802AB12C AFA00010 */  sw        $zero, 0x10($sp)
/* 41FEC0 802AB130 AFA00020 */  sw        $zero, 0x20($sp)
/* 41FEC4 802AB134 AFA00024 */  sw        $zero, 0x24($sp)
/* 41FEC8 802AB138 AFA00028 */  sw        $zero, 0x28($sp)
/* 41FECC 802AB13C AFA0002C */  sw        $zero, 0x2c($sp)
/* 41FED0 802AB140 AFA00030 */  sw        $zero, 0x30($sp)
/* 41FED4 802AB144 AFA00034 */  sw        $zero, 0x34($sp)
/* 41FED8 802AB148 AFA00038 */  sw        $zero, 0x38($sp)
/* 41FEDC 802AB14C AFA0003C */  sw        $zero, 0x3c($sp)
/* 41FEE0 802AB150 AFA00040 */  sw        $zero, 0x40($sp)
/* 41FEE4 802AB154 AFA20044 */  sw        $v0, 0x44($sp)
/* 41FEE8 802AB158 8E060000 */  lw        $a2, ($s0)
/* 41FEEC 802AB15C 240200F0 */  addiu     $v0, $zero, 0xf0
/* 41FEF0 802AB160 AFA20048 */  sw        $v0, 0x48($sp)
/* 41FEF4 802AB164 AFA0004C */  sw        $zero, 0x4c($sp)
/* 41FEF8 802AB168 0C03D4B8 */  jal       draw_box
/* 41FEFC 802AB16C 00663021 */   addu     $a2, $v1, $a2
/* 41FF00 802AB170 8FA20050 */  lw        $v0, 0x50($sp)
/* 41FF04 802AB174 8FA30054 */  lw        $v1, 0x54($sp)
/* 41FF08 802AB178 24480004 */  addiu     $t0, $v0, 4
/* 41FF0C 802AB17C 3C02800E */  lui       $v0, %hi(gBattleStatus+0x184)
/* 41FF10 802AB180 8C42C1F4 */  lw        $v0, %lo(gBattleStatus+0x184)($v0)
/* 41FF14 802AB184 24660002 */  addiu     $a2, $v1, 2
/* 41FF18 802AB188 AFA80050 */  sw        $t0, 0x50($sp)
/* 41FF1C 802AB18C 30420001 */  andi      $v0, $v0, 1
/* 41FF20 802AB190 14400005 */  bnez      $v0, .L802AB1A8
/* 41FF24 802AB194 AFA60054 */   sw       $a2, 0x54($sp)
/* 41FF28 802AB198 8FA9005C */  lw        $t1, 0x5c($sp)
/* 41FF2C 802AB19C 24020001 */  addiu     $v0, $zero, 1
/* 41FF30 802AB1A0 15220032 */  bne       $t1, $v0, .L802AB26C
/* 41FF34 802AB1A4 00000000 */   nop      
.L802AB1A8:
/* 41FF38 802AB1A8 86230000 */  lh        $v1, ($s1)
/* 41FF3C 802AB1AC 14600004 */  bnez      $v1, .L802AB1C0
/* 41FF40 802AB1B0 24020100 */   addiu    $v0, $zero, 0x100
/* 41FF44 802AB1B4 3C04001D */  lui       $a0, 0x1d
/* 41FF48 802AB1B8 080AACB5 */  j         .L802AB2D4
/* 41FF4C 802AB1BC 348400C4 */   ori      $a0, $a0, 0xc4
.L802AB1C0:
/* 41FF50 802AB1C0 1462000A */  bne       $v1, $v0, .L802AB1EC
/* 41FF54 802AB1C4 24020036 */   addiu    $v0, $zero, 0x36
/* 41FF58 802AB1C8 AFA20010 */  sw        $v0, 0x10($sp)
/* 41FF5C 802AB1CC 00121080 */  sll       $v0, $s2, 2
/* 41FF60 802AB1D0 AFA00014 */  sw        $zero, 0x14($sp)
/* 41FF64 802AB1D4 8E050000 */  lw        $a1, ($s0)
/* 41FF68 802AB1D8 3C04802B */  lui       $a0, 0x802b
/* 41FF6C 802AB1DC 00822021 */  addu      $a0, $a0, $v0
/* 41FF70 802AB1E0 8C84B738 */  lw        $a0, -0x48c8($a0)
/* 41FF74 802AB1E4 080AACBA */  j         .L802AB2E8
/* 41FF78 802AB1E8 240700FF */   addiu    $a3, $zero, 0xff
.L802AB1EC:
/* 41FF7C 802AB1EC 8FA90060 */  lw        $t1, 0x60($sp)
/* 41FF80 802AB1F0 02E91021 */  addu      $v0, $s7, $t1
/* 41FF84 802AB1F4 80430000 */  lb        $v1, ($v0)
/* 41FF88 802AB1F8 00031080 */  sll       $v0, $v1, 2
/* 41FF8C 802AB1FC 00431021 */  addu      $v0, $v0, $v1
/* 41FF90 802AB200 00021080 */  sll       $v0, $v0, 2
/* 41FF94 802AB204 2442022C */  addiu     $v0, $v0, 0x22c
/* 41FF98 802AB208 02C28821 */  addu      $s1, $s6, $v0
/* 41FF9C 802AB20C 0C09A75B */  jal       get_actor
/* 41FFA0 802AB210 86240000 */   lh       $a0, ($s1)
/* 41FFA4 802AB214 0040802D */  daddu     $s0, $v0, $zero
/* 41FFA8 802AB218 86250002 */  lh        $a1, 2($s1)
/* 41FFAC 802AB21C 0C099117 */  jal       get_actor_part
/* 41FFB0 802AB220 0200202D */   daddu    $a0, $s0, $zero
/* 41FFB4 802AB224 8C420008 */  lw        $v0, 8($v0)
/* 41FFB8 802AB228 8C440020 */  lw        $a0, 0x20($v0)
/* 41FFBC 802AB22C 14800006 */  bnez      $a0, .L802AB248
/* 41FFC0 802AB230 240700FF */   addiu    $a3, $zero, 0xff
/* 41FFC4 802AB234 92020136 */  lbu       $v0, 0x136($s0)
/* 41FFC8 802AB238 00021080 */  sll       $v0, $v0, 2
/* 41FFCC 802AB23C 3C048028 */  lui       $a0, 0x8028
/* 41FFD0 802AB240 00822021 */  addu      $a0, $a0, $v0
/* 41FFD4 802AB244 8C841104 */  lw        $a0, 0x1104($a0)
.L802AB248:
/* 41FFD8 802AB248 8FA30050 */  lw        $v1, 0x50($sp)
/* 41FFDC 802AB24C 3C05802B */  lui       $a1, 0x802b
/* 41FFE0 802AB250 8CA5CC68 */  lw        $a1, -0x3398($a1)
/* 41FFE4 802AB254 8FA60054 */  lw        $a2, 0x54($sp)
/* 41FFE8 802AB258 24020036 */  addiu     $v0, $zero, 0x36
/* 41FFEC 802AB25C AFA20010 */  sw        $v0, 0x10($sp)
/* 41FFF0 802AB260 AFA00014 */  sw        $zero, 0x14($sp)
/* 41FFF4 802AB264 080AACBB */  j         .L802AB2EC
/* 41FFF8 802AB268 00652821 */   addu     $a1, $v1, $a1
.L802AB26C:
/* 41FFFC 802AB26C 8FA90060 */  lw        $t1, 0x60($sp)
/* 420000 802AB270 02E91021 */  addu      $v0, $s7, $t1
/* 420004 802AB274 80430000 */  lb        $v1, ($v0)
/* 420008 802AB278 00031080 */  sll       $v0, $v1, 2
/* 42000C 802AB27C 00431021 */  addu      $v0, $v0, $v1
/* 420010 802AB280 00021080 */  sll       $v0, $v0, 2
/* 420014 802AB284 00568821 */  addu      $s1, $v0, $s6
/* 420018 802AB288 8623022C */  lh        $v1, 0x22c($s1)
/* 42001C 802AB28C 14600004 */  bnez      $v1, .L802AB2A0
/* 420020 802AB290 24020100 */   addiu    $v0, $zero, 0x100
/* 420024 802AB294 3C04001D */  lui       $a0, 0x1d
/* 420028 802AB298 080AACB5 */  j         .L802AB2D4
/* 42002C 802AB29C 348400C4 */   ori      $a0, $a0, 0xc4
.L802AB2A0:
/* 420030 802AB2A0 1462000B */  bne       $v1, $v0, .L802AB2D0
/* 420034 802AB2A4 3C04001D */   lui      $a0, 0x1d
/* 420038 802AB2A8 24020036 */  addiu     $v0, $zero, 0x36
/* 42003C 802AB2AC AFA20010 */  sw        $v0, 0x10($sp)
/* 420040 802AB2B0 00121080 */  sll       $v0, $s2, 2
/* 420044 802AB2B4 AFA00014 */  sw        $zero, 0x14($sp)
/* 420048 802AB2B8 8E050000 */  lw        $a1, ($s0)
/* 42004C 802AB2BC 3C04802B */  lui       $a0, 0x802b
/* 420050 802AB2C0 00822021 */  addu      $a0, $a0, $v0
/* 420054 802AB2C4 8C84B738 */  lw        $a0, -0x48c8($a0)
/* 420058 802AB2C8 080AACBA */  j         .L802AB2E8
/* 42005C 802AB2CC 240700FF */   addiu    $a3, $zero, 0xff
.L802AB2D0:
/* 420060 802AB2D0 348400C5 */  ori       $a0, $a0, 0xc5
.L802AB2D4:
/* 420064 802AB2D4 240700FF */  addiu     $a3, $zero, 0xff
/* 420068 802AB2D8 8E050000 */  lw        $a1, ($s0)
/* 42006C 802AB2DC 24020036 */  addiu     $v0, $zero, 0x36
/* 420070 802AB2E0 AFA20010 */  sw        $v0, 0x10($sp)
/* 420074 802AB2E4 AFA00014 */  sw        $zero, 0x14($sp)
.L802AB2E8:
/* 420078 802AB2E8 01052821 */  addu      $a1, $t0, $a1
.L802AB2EC:
/* 42007C 802AB2EC 0C04993B */  jal       draw_string
/* 420080 802AB2F0 00000000 */   nop      
.L802AB2F4:
/* 420084 802AB2F4 8FBF008C */  lw        $ra, 0x8c($sp)
/* 420088 802AB2F8 8FBE0088 */  lw        $fp, 0x88($sp)
/* 42008C 802AB2FC 8FB70084 */  lw        $s7, 0x84($sp)
/* 420090 802AB300 8FB60080 */  lw        $s6, 0x80($sp)
/* 420094 802AB304 8FB5007C */  lw        $s5, 0x7c($sp)
/* 420098 802AB308 8FB40078 */  lw        $s4, 0x78($sp)
/* 42009C 802AB30C 8FB30074 */  lw        $s3, 0x74($sp)
/* 4200A0 802AB310 8FB20070 */  lw        $s2, 0x70($sp)
/* 4200A4 802AB314 8FB1006C */  lw        $s1, 0x6c($sp)
/* 4200A8 802AB318 8FB00068 */  lw        $s0, 0x68($sp)
/* 4200AC 802AB31C D7B800A0 */  ldc1      $f24, 0xa0($sp)
/* 4200B0 802AB320 D7B60098 */  ldc1      $f22, 0x98($sp)
/* 4200B4 802AB324 D7B40090 */  ldc1      $f20, 0x90($sp)
/* 4200B8 802AB328 03E00008 */  jr        $ra
/* 4200BC 802AB32C 27BD00A8 */   addiu    $sp, $sp, 0xa8
