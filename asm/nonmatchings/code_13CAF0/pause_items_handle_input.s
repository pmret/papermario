.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel pause_items_handle_input
/* 13DB18 8024A7D8 3C038027 */  lui       $v1, %hi(gItemMenuCurrentPage)
/* 13DB1C 8024A7DC 8C6304C8 */  lw        $v1, %lo(gItemMenuCurrentPage)($v1)
/* 13DB20 8024A7E0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 13DB24 8024A7E4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 13DB28 8024A7E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 13DB2C 8024A7EC 00031040 */  sll       $v0, $v1, 1
/* 13DB30 8024A7F0 00431021 */  addu      $v0, $v0, $v1
/* 13DB34 8024A7F4 00021080 */  sll       $v0, $v0, 2
/* 13DB38 8024A7F8 3C038027 */  lui       $v1, 0x8027
/* 13DB3C 8024A7FC 00621821 */  addu      $v1, $v1, $v0
/* 13DB40 8024A800 906304D2 */  lbu       $v1, 0x4d2($v1)
/* 13DB44 8024A804 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13DB48 8024A808 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 13DB4C 8024A80C 3C098027 */  lui       $t1, %hi(gItemMenuSelectedIndex)
/* 13DB50 8024A810 8D2905C0 */  lw        $t1, %lo(gItemMenuSelectedIndex)($t1)
/* 13DB54 8024A814 30428000 */  andi      $v0, $v0, 0x8000
/* 13DB58 8024A818 14600002 */  bnez      $v1, .L8024A824
/* 13DB5C 8024A81C 0123001A */   div      $zero, $t1, $v1
/* 13DB60 8024A820 0007000D */  break     7
.L8024A824:
/* 13DB64 8024A824 2401FFFF */   addiu    $at, $zero, -1
/* 13DB68 8024A828 14610004 */  bne       $v1, $at, .L8024A83C
/* 13DB6C 8024A82C 3C018000 */   lui      $at, 0x8000
/* 13DB70 8024A830 15210002 */  bne       $t1, $at, .L8024A83C
/* 13DB74 8024A834 00000000 */   nop      
/* 13DB78 8024A838 0006000D */  break     6
.L8024A83C:
/* 13DB7C 8024A83C 00002812 */   mflo     $a1
/* 13DB80 8024A840 00004010 */  mfhi      $t0
/* 13DB84 8024A844 10400015 */  beqz      $v0, .L8024A89C
/* 13DB88 8024A848 00000000 */   nop      
/* 13DB8C 8024A84C 3C048027 */  lui       $a0, %hi(gItemMenuLevel)
/* 13DB90 8024A850 248405E0 */  addiu     $a0, $a0, %lo(gItemMenuLevel)
/* 13DB94 8024A854 8C820000 */  lw        $v0, ($a0)
/* 13DB98 8024A858 14400010 */  bnez      $v0, .L8024A89C
/* 13DB9C 8024A85C 00091040 */   sll      $v0, $t1, 1
/* 13DBA0 8024A860 3C038027 */  lui       $v1, %hi(gItemMenuItemIDs)
/* 13DBA4 8024A864 00621821 */  addu      $v1, $v1, $v0
/* 13DBA8 8024A868 84630400 */  lh        $v1, %lo(gItemMenuItemIDs)($v1)
/* 13DBAC 8024A86C 24027FFE */  addiu     $v0, $zero, 0x7ffe
/* 13DBB0 8024A870 14620005 */  bne       $v1, $v0, .L8024A888
/* 13DBB4 8024A874 24020001 */   addiu    $v0, $zero, 1
/* 13DBB8 8024A878 0C05272D */  jal       play_sound
/* 13DBBC 8024A87C 2404021D */   addiu    $a0, $zero, 0x21d
/* 13DBC0 8024A880 08092B11 */  j         .L8024AC44
/* 13DBC4 8024A884 00000000 */   nop      
.L8024A888:
/* 13DBC8 8024A888 AC820000 */  sw        $v0, ($a0)
/* 13DBCC 8024A88C 0C05272D */  jal       play_sound
/* 13DBD0 8024A890 240400C9 */   addiu    $a0, $zero, 0xc9
/* 13DBD4 8024A894 08092B11 */  j         .L8024AC44
/* 13DBD8 8024A898 00000000 */   nop      
.L8024A89C:
/* 13DBDC 8024A89C 3C028027 */  lui       $v0, %hi(gItemMenuNumItems)
/* 13DBE0 8024A8A0 844205CC */  lh        $v0, %lo(gItemMenuNumItems)($v0)
/* 13DBE4 8024A8A4 104000B1 */  beqz      $v0, .L8024AB6C
/* 13DBE8 8024A8A8 00000000 */   nop      
/* 13DBEC 8024A8AC 3C028027 */  lui       $v0, %hi(gItemMenuLevel)
/* 13DBF0 8024A8B0 8C4205E0 */  lw        $v0, %lo(gItemMenuLevel)($v0)
/* 13DBF4 8024A8B4 14400015 */  bnez      $v0, .L8024A90C
/* 13DBF8 8024A8B8 3C020001 */   lui      $v0, 1
/* 13DBFC 8024A8BC 3C108027 */  lui       $s0, %hi(gItemMenuCurrentTab)
/* 13DC00 8024A8C0 261005E4 */  addiu     $s0, $s0, %lo(gItemMenuCurrentTab)
/* 13DC04 8024A8C4 3C028027 */  lui       $v0, %hi(gPauseMenuHeldButtons)
/* 13DC08 8024A8C8 8C4200C0 */  lw        $v0, %lo(gPauseMenuHeldButtons)($v0)
/* 13DC0C 8024A8CC 3C030003 */  lui       $v1, 3
/* 13DC10 8024A8D0 00431024 */  and       $v0, $v0, $v1
/* 13DC14 8024A8D4 8E030000 */  lw        $v1, ($s0)
/* 13DC18 8024A8D8 10400002 */  beqz      $v0, .L8024A8E4
/* 13DC1C 8024A8DC 38620001 */   xori     $v0, $v1, 1
/* 13DC20 8024A8E0 AE020000 */  sw        $v0, ($s0)
.L8024A8E4:
/* 13DC24 8024A8E4 8E020000 */  lw        $v0, ($s0)
/* 13DC28 8024A8E8 106200A0 */  beq       $v1, $v0, .L8024AB6C
/* 13DC2C 8024A8EC 00000000 */   nop      
/* 13DC30 8024A8F0 0C05272D */  jal       play_sound
/* 13DC34 8024A8F4 240400C8 */   addiu    $a0, $zero, 0xc8
/* 13DC38 8024A8F8 8E040000 */  lw        $a0, ($s0)
/* 13DC3C 8024A8FC 0C092937 */  jal       pause_items_load_items
/* 13DC40 8024A900 00000000 */   nop      
/* 13DC44 8024A904 08092ADB */  j         .L8024AB6C
/* 13DC48 8024A908 00000000 */   nop      
.L8024A90C:
/* 13DC4C 8024A90C 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13DC50 8024A910 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13DC54 8024A914 34422000 */  ori       $v0, $v0, 0x2000
/* 13DC58 8024A918 00621024 */  and       $v0, $v1, $v0
/* 13DC5C 8024A91C 10400022 */  beqz      $v0, .L8024A9A8
/* 13DC60 8024A920 3C020001 */   lui      $v0, 1
/* 13DC64 8024A924 00621024 */  and       $v0, $v1, $v0
/* 13DC68 8024A928 10400011 */  beqz      $v0, .L8024A970
/* 13DC6C 8024A92C 24A5FFFF */   addiu    $a1, $a1, -1
/* 13DC70 8024A930 04A20001 */  bltzl     $a1, .L8024A938
/* 13DC74 8024A934 0000282D */   daddu    $a1, $zero, $zero
.L8024A938:
/* 13DC78 8024A938 3C048027 */  lui       $a0, %hi(gItemMenuCurrentPage)
/* 13DC7C 8024A93C 248404C8 */  addiu     $a0, $a0, %lo(gItemMenuCurrentPage)
/* 13DC80 8024A940 8C830000 */  lw        $v1, ($a0)
/* 13DC84 8024A944 00031040 */  sll       $v0, $v1, 1
/* 13DC88 8024A948 00431021 */  addu      $v0, $v0, $v1
/* 13DC8C 8024A94C 00021080 */  sll       $v0, $v0, 2
/* 13DC90 8024A950 3C018027 */  lui       $at, 0x8027
/* 13DC94 8024A954 00220821 */  addu      $at, $at, $v0
/* 13DC98 8024A958 902204D1 */  lbu       $v0, 0x4d1($at)
/* 13DC9C 8024A95C 00A2102A */  slt       $v0, $a1, $v0
/* 13DCA0 8024A960 10400011 */  beqz      $v0, .L8024A9A8
/* 13DCA4 8024A964 2462FFFF */   addiu    $v0, $v1, -1
/* 13DCA8 8024A968 08092A6A */  j         .L8024A9A8
/* 13DCAC 8024A96C AC820000 */   sw       $v0, ($a0)
.L8024A970:
/* 13DCB0 8024A970 3C038027 */  lui       $v1, %hi(gItemMenuCurrentPage)
/* 13DCB4 8024A974 246304C8 */  addiu     $v1, $v1, %lo(gItemMenuCurrentPage)
/* 13DCB8 8024A978 8C620000 */  lw        $v0, ($v1)
/* 13DCBC 8024A97C 2442FFFF */  addiu     $v0, $v0, -1
/* 13DCC0 8024A980 04410002 */  bgez      $v0, .L8024A98C
/* 13DCC4 8024A984 AC620000 */   sw       $v0, ($v1)
/* 13DCC8 8024A988 AC600000 */  sw        $zero, ($v1)
.L8024A98C:
/* 13DCCC 8024A98C 8C630000 */  lw        $v1, ($v1)
/* 13DCD0 8024A990 00031040 */  sll       $v0, $v1, 1
/* 13DCD4 8024A994 00431021 */  addu      $v0, $v0, $v1
/* 13DCD8 8024A998 00021080 */  sll       $v0, $v0, 2
/* 13DCDC 8024A99C 3C058027 */  lui       $a1, 0x8027
/* 13DCE0 8024A9A0 00A22821 */  addu      $a1, $a1, $v0
/* 13DCE4 8024A9A4 90A504D1 */  lbu       $a1, 0x4d1($a1)
.L8024A9A8:
/* 13DCE8 8024A9A8 3C020002 */  lui       $v0, 2
/* 13DCEC 8024A9AC 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13DCF0 8024A9B0 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13DCF4 8024A9B4 34420010 */  ori       $v0, $v0, 0x10
/* 13DCF8 8024A9B8 00621024 */  and       $v0, $v1, $v0
/* 13DCFC 8024A9BC 10400030 */  beqz      $v0, .L8024AA80
/* 13DD00 8024A9C0 3C020002 */   lui      $v0, 2
/* 13DD04 8024A9C4 00621024 */  and       $v0, $v1, $v0
/* 13DD08 8024A9C8 1040001C */  beqz      $v0, .L8024AA3C
/* 13DD0C 8024A9CC 00000000 */   nop      
/* 13DD10 8024A9D0 3C068027 */  lui       $a2, %hi(gItemMenuCurrentPage)
/* 13DD14 8024A9D4 24C604C8 */  addiu     $a2, $a2, %lo(gItemMenuCurrentPage)
/* 13DD18 8024A9D8 8CC40000 */  lw        $a0, ($a2)
/* 13DD1C 8024A9DC 3C078027 */  lui       $a3, %hi(gItemMenuPages)
/* 13DD20 8024A9E0 24E704D0 */  addiu     $a3, $a3, %lo(gItemMenuPages)
/* 13DD24 8024A9E4 00041040 */  sll       $v0, $a0, 1
/* 13DD28 8024A9E8 00441021 */  addu      $v0, $v0, $a0
/* 13DD2C 8024A9EC 00021080 */  sll       $v0, $v0, 2
/* 13DD30 8024A9F0 00471021 */  addu      $v0, $v0, $a3
/* 13DD34 8024A9F4 90430001 */  lbu       $v1, 1($v0)
/* 13DD38 8024A9F8 90420003 */  lbu       $v0, 3($v0)
/* 13DD3C 8024A9FC 24A50001 */  addiu     $a1, $a1, 1
/* 13DD40 8024AA00 00621821 */  addu      $v1, $v1, $v0
/* 13DD44 8024AA04 00A3182A */  slt       $v1, $a1, $v1
/* 13DD48 8024AA08 1460001D */  bnez      $v1, .L8024AA80
/* 13DD4C 8024AA0C 24820001 */   addiu    $v0, $a0, 1
/* 13DD50 8024AA10 00021840 */  sll       $v1, $v0, 1
/* 13DD54 8024AA14 00621821 */  addu      $v1, $v1, $v0
/* 13DD58 8024AA18 00031880 */  sll       $v1, $v1, 2
/* 13DD5C 8024AA1C 00671821 */  addu      $v1, $v1, $a3
/* 13DD60 8024AA20 ACC20000 */  sw        $v0, ($a2)
/* 13DD64 8024AA24 90620000 */  lbu       $v0, ($v1)
/* 13DD68 8024AA28 14400015 */  bnez      $v0, .L8024AA80
/* 13DD6C 8024AA2C 00000000 */   nop      
/* 13DD70 8024AA30 ACC40000 */  sw        $a0, ($a2)
/* 13DD74 8024AA34 08092AA0 */  j         .L8024AA80
/* 13DD78 8024AA38 24A5FFFF */   addiu    $a1, $a1, -1
.L8024AA3C:
/* 13DD7C 8024AA3C 3C068027 */  lui       $a2, %hi(gItemMenuCurrentPage)
/* 13DD80 8024AA40 24C604C8 */  addiu     $a2, $a2, %lo(gItemMenuCurrentPage)
/* 13DD84 8024AA44 8CC70000 */  lw        $a3, ($a2)
/* 13DD88 8024AA48 3C048027 */  lui       $a0, %hi(gItemMenuPages)
/* 13DD8C 8024AA4C 248404D0 */  addiu     $a0, $a0, %lo(gItemMenuPages)
/* 13DD90 8024AA50 24E30001 */  addiu     $v1, $a3, 1
/* 13DD94 8024AA54 00031040 */  sll       $v0, $v1, 1
/* 13DD98 8024AA58 00431021 */  addu      $v0, $v0, $v1
/* 13DD9C 8024AA5C 00021080 */  sll       $v0, $v0, 2
/* 13DDA0 8024AA60 ACC30000 */  sw        $v1, ($a2)
/* 13DDA4 8024AA64 00441821 */  addu      $v1, $v0, $a0
/* 13DDA8 8024AA68 90620000 */  lbu       $v0, ($v1)
/* 13DDAC 8024AA6C 14400003 */  bnez      $v0, .L8024AA7C
/* 13DDB0 8024AA70 00000000 */   nop      
/* 13DDB4 8024AA74 08092AA0 */  j         .L8024AA80
/* 13DDB8 8024AA78 ACC70000 */   sw       $a3, ($a2)
.L8024AA7C:
/* 13DDBC 8024AA7C 90650001 */  lbu       $a1, 1($v1)
.L8024AA80:
/* 13DDC0 8024AA80 3C038027 */  lui       $v1, %hi(gItemMenuCurrentPage)
/* 13DDC4 8024AA84 8C6304C8 */  lw        $v1, %lo(gItemMenuCurrentPage)($v1)
/* 13DDC8 8024AA88 00031040 */  sll       $v0, $v1, 1
/* 13DDCC 8024AA8C 00431021 */  addu      $v0, $v0, $v1
/* 13DDD0 8024AA90 00021080 */  sll       $v0, $v0, 2
/* 13DDD4 8024AA94 3C048027 */  lui       $a0, 0x8027
/* 13DDD8 8024AA98 00822021 */  addu      $a0, $a0, $v0
/* 13DDDC 8024AA9C 908404D2 */  lbu       $a0, 0x4d2($a0)
/* 13DDE0 8024AAA0 00A40018 */  mult      $a1, $a0
/* 13DDE4 8024AAA4 00005012 */  mflo      $t2
/* 13DDE8 8024AAA8 000A1040 */  sll       $v0, $t2, 1
/* 13DDEC 8024AAAC 3C038027 */  lui       $v1, %hi(gItemMenuItemIDs)
/* 13DDF0 8024AAB0 00621821 */  addu      $v1, $v1, $v0
/* 13DDF4 8024AAB4 84630400 */  lh        $v1, %lo(gItemMenuItemIDs)($v1)
/* 13DDF8 8024AAB8 24027FFE */  addiu     $v0, $zero, 0x7ffe
/* 13DDFC 8024AABC 10620012 */  beq       $v1, $v0, .L8024AB08
/* 13DE00 8024AAC0 3C020004 */   lui      $v0, 4
/* 13DE04 8024AAC4 3C038027 */  lui       $v1, %hi(gPauseMenuHeldButtons)
/* 13DE08 8024AAC8 8C6300C0 */  lw        $v1, %lo(gPauseMenuHeldButtons)($v1)
/* 13DE0C 8024AACC 00621024 */  and       $v0, $v1, $v0
/* 13DE10 8024AAD0 10400006 */  beqz      $v0, .L8024AAEC
/* 13DE14 8024AAD4 3C020008 */   lui      $v0, 8
/* 13DE18 8024AAD8 2508FFFF */  addiu     $t0, $t0, -1
/* 13DE1C 8024AADC 0502000B */  bltzl     $t0, .L8024AB0C
/* 13DE20 8024AAE0 2488FFFF */   addiu    $t0, $a0, -1
/* 13DE24 8024AAE4 08092AC3 */  j         .L8024AB0C
/* 13DE28 8024AAE8 00000000 */   nop      
.L8024AAEC:
/* 13DE2C 8024AAEC 00621024 */  and       $v0, $v1, $v0
/* 13DE30 8024AAF0 10400006 */  beqz      $v0, .L8024AB0C
/* 13DE34 8024AAF4 00000000 */   nop      
/* 13DE38 8024AAF8 25080001 */  addiu     $t0, $t0, 1
/* 13DE3C 8024AAFC 0104102A */  slt       $v0, $t0, $a0
/* 13DE40 8024AB00 14400002 */  bnez      $v0, .L8024AB0C
/* 13DE44 8024AB04 00000000 */   nop      
.L8024AB08:
/* 13DE48 8024AB08 0000402D */  daddu     $t0, $zero, $zero
.L8024AB0C:
/* 13DE4C 8024AB0C 3C038027 */  lui       $v1, %hi(gItemMenuCurrentPage)
/* 13DE50 8024AB10 8C6304C8 */  lw        $v1, %lo(gItemMenuCurrentPage)($v1)
/* 13DE54 8024AB14 00031040 */  sll       $v0, $v1, 1
/* 13DE58 8024AB18 00431021 */  addu      $v0, $v0, $v1
/* 13DE5C 8024AB1C 00021080 */  sll       $v0, $v0, 2
/* 13DE60 8024AB20 3C018027 */  lui       $at, 0x8027
/* 13DE64 8024AB24 00220821 */  addu      $at, $at, $v0
/* 13DE68 8024AB28 902204D2 */  lbu       $v0, 0x4d2($at)
/* 13DE6C 8024AB2C 00A20018 */  mult      $a1, $v0
/* 13DE70 8024AB30 3C108027 */  lui       $s0, %hi(gItemMenuSelectedIndex)
/* 13DE74 8024AB34 261005C0 */  addiu     $s0, $s0, %lo(gItemMenuSelectedIndex)
/* 13DE78 8024AB38 00005012 */  mflo      $t2
/* 13DE7C 8024AB3C 010A1021 */  addu      $v0, $t0, $t2
/* 13DE80 8024AB40 10490003 */  beq       $v0, $t1, .L8024AB50
/* 13DE84 8024AB44 AE020000 */   sw       $v0, ($s0)
/* 13DE88 8024AB48 0C05272D */  jal       play_sound
/* 13DE8C 8024AB4C 240400C7 */   addiu    $a0, $zero, 0xc7
.L8024AB50:
/* 13DE90 8024AB50 8E020000 */  lw        $v0, ($s0)
/* 13DE94 8024AB54 00021040 */  sll       $v0, $v0, 1
/* 13DE98 8024AB58 3C018027 */  lui       $at, %hi(gItemMenuItemIDs)
/* 13DE9C 8024AB5C 00220821 */  addu      $at, $at, $v0
/* 13DEA0 8024AB60 84220400 */  lh        $v0, %lo(gItemMenuItemIDs)($at)
/* 13DEA4 8024AB64 3C018027 */  lui       $at, %hi(gItemMenuSelectedItemID)
/* 13DEA8 8024AB68 AC2205C8 */  sw        $v0, %lo(gItemMenuSelectedItemID)($at)
.L8024AB6C:
/* 13DEAC 8024AB6C 3C028027 */  lui       $v0, %hi(gItemMenuLevel)
/* 13DEB0 8024AB70 8C4205E0 */  lw        $v0, %lo(gItemMenuLevel)($v0)
/* 13DEB4 8024AB74 24030001 */  addiu     $v1, $zero, 1
/* 13DEB8 8024AB78 14430014 */  bne       $v0, $v1, .L8024ABCC
/* 13DEBC 8024AB7C 00000000 */   nop      
/* 13DEC0 8024AB80 3C038027 */  lui       $v1, %hi(gItemMenuSelectedItemID)
/* 13DEC4 8024AB84 8C6305C8 */  lw        $v1, %lo(gItemMenuSelectedItemID)($v1)
/* 13DEC8 8024AB88 24628002 */  addiu     $v0, $v1, -0x7ffe
/* 13DECC 8024AB8C 2C420002 */  sltiu     $v0, $v0, 2
/* 13DED0 8024AB90 1440000A */  bnez      $v0, .L8024ABBC
/* 13DED4 8024AB94 00000000 */   nop      
/* 13DED8 8024AB98 10600008 */  beqz      $v1, .L8024ABBC
/* 13DEDC 8024AB9C 00031140 */   sll      $v0, $v1, 5
/* 13DEE0 8024ABA0 3C018008 */  lui       $at, %hi(gItemTable+0x10)
/* 13DEE4 8024ABA4 00220821 */  addu      $at, $at, $v0
/* 13DEE8 8024ABA8 8C2278F0 */  lw        $v0, %lo(gItemTable+0x10)($at)
/* 13DEEC 8024ABAC 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13DEF0 8024ABB0 AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
/* 13DEF4 8024ABB4 08092AFE */  j         .L8024ABF8
/* 13DEF8 8024ABB8 00000000 */   nop      
.L8024ABBC:
/* 13DEFC 8024ABBC 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13DF00 8024ABC0 AC2000C8 */  sw        $zero, %lo(gPauseMenuCurrentDescString)($at)
/* 13DF04 8024ABC4 08092AFC */  j         .L8024ABF0
/* 13DF08 8024ABC8 00000000 */   nop      
.L8024ABCC:
/* 13DF0C 8024ABCC 3C028027 */  lui       $v0, %hi(gItemMenuCurrentTab)
/* 13DF10 8024ABD0 8C4205E4 */  lw        $v0, %lo(gItemMenuCurrentTab)($v0)
/* 13DF14 8024ABD4 14430002 */  bne       $v0, $v1, .L8024ABE0
/* 13DF18 8024ABD8 24040052 */   addiu    $a0, $zero, 0x52
/* 13DF1C 8024ABDC 24040051 */  addiu     $a0, $zero, 0x51
.L8024ABE0:
/* 13DF20 8024ABE0 0C093BA0 */  jal       pause_get_menu_string
/* 13DF24 8024ABE4 00000000 */   nop      
/* 13DF28 8024ABE8 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescString)
/* 13DF2C 8024ABEC AC2200C8 */  sw        $v0, %lo(gPauseMenuCurrentDescString)($at)
.L8024ABF0:
/* 13DF30 8024ABF0 3C018027 */  lui       $at, %hi(gPauseMenuCurrentDescIconScript)
/* 13DF34 8024ABF4 AC2000CC */  sw        $zero, %lo(gPauseMenuCurrentDescIconScript)($at)
.L8024ABF8:
/* 13DF38 8024ABF8 3C028027 */  lui       $v0, %hi(gPauseMenuPressedButtons)
/* 13DF3C 8024ABFC 8C4200C4 */  lw        $v0, %lo(gPauseMenuPressedButtons)($v0)
/* 13DF40 8024AC00 30424000 */  andi      $v0, $v0, 0x4000
/* 13DF44 8024AC04 1040000F */  beqz      $v0, .L8024AC44
/* 13DF48 8024AC08 00000000 */   nop      
/* 13DF4C 8024AC0C 3C108027 */  lui       $s0, %hi(gItemMenuLevel)
/* 13DF50 8024AC10 261005E0 */  addiu     $s0, $s0, %lo(gItemMenuLevel)
/* 13DF54 8024AC14 8E020000 */  lw        $v0, ($s0)
/* 13DF58 8024AC18 14400007 */  bnez      $v0, .L8024AC38
/* 13DF5C 8024AC1C 00000000 */   nop      
/* 13DF60 8024AC20 0C05272D */  jal       play_sound
/* 13DF64 8024AC24 240400CA */   addiu    $a0, $zero, 0xca
/* 13DF68 8024AC28 3C018027 */  lui       $at, %hi(gPauseMenuCurrentTab)
/* 13DF6C 8024AC2C A02000D4 */  sb        $zero, %lo(gPauseMenuCurrentTab)($at)
/* 13DF70 8024AC30 08092B11 */  j         .L8024AC44
/* 13DF74 8024AC34 00000000 */   nop      
.L8024AC38:
/* 13DF78 8024AC38 0C05272D */  jal       play_sound
/* 13DF7C 8024AC3C 240400CA */   addiu    $a0, $zero, 0xca
/* 13DF80 8024AC40 AE000000 */  sw        $zero, ($s0)
.L8024AC44:
/* 13DF84 8024AC44 8FBF0014 */  lw        $ra, 0x14($sp)
/* 13DF88 8024AC48 8FB00010 */  lw        $s0, 0x10($sp)
/* 13DF8C 8024AC4C 03E00008 */  jr        $ra
/* 13DF90 8024AC50 27BD0018 */   addiu    $sp, $sp, 0x18
