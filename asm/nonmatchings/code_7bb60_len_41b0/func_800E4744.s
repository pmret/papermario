.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800E4744
/* 7DBF4 800E4744 27BDFF88 */  addiu     $sp, $sp, -0x78
/* 7DBF8 800E4748 AFB00048 */  sw        $s0, 0x48($sp)
/* 7DBFC 800E474C 3C108011 */  lui       $s0, 0x8011
/* 7DC00 800E4750 2610EFC8 */  addiu     $s0, $s0, -0x1038
/* 7DC04 800E4754 0200202D */  daddu     $a0, $s0, $zero
/* 7DC08 800E4758 27A50028 */  addiu     $a1, $sp, 0x28
/* 7DC0C 800E475C 27A6002C */  addiu     $a2, $sp, 0x2c
/* 7DC10 800E4760 AFBF005C */  sw        $ra, 0x5c($sp)
/* 7DC14 800E4764 AFB40058 */  sw        $s4, 0x58($sp)
/* 7DC18 800E4768 AFB30054 */  sw        $s3, 0x54($sp)
/* 7DC1C 800E476C AFB20050 */  sw        $s2, 0x50($sp)
/* 7DC20 800E4770 AFB1004C */  sw        $s1, 0x4c($sp)
/* 7DC24 800E4774 F7B80070 */  sdc1      $f24, 0x70($sp)
/* 7DC28 800E4778 F7B60068 */  sdc1      $f22, 0x68($sp)
/* 7DC2C 800E477C F7B40060 */  sdc1      $f20, 0x60($sp)
/* 7DC30 800E4780 860200B0 */  lh        $v0, 0xb0($s0)
/* 7DC34 800E4784 3C013F00 */  lui       $at, 0x3f00
/* 7DC38 800E4788 4481A000 */  mtc1      $at, $f20
/* 7DC3C 800E478C C6000028 */  lwc1      $f0, 0x28($s0)
/* 7DC40 800E4790 44822000 */  mtc1      $v0, $f4
/* 7DC44 800E4794 00000000 */  nop       
/* 7DC48 800E4798 46802120 */  cvt.s.w   $f4, $f4
/* 7DC4C 800E479C 46142582 */  mul.s     $f22, $f4, $f20
/* 7DC50 800E47A0 00000000 */  nop       
/* 7DC54 800E47A4 27A70030 */  addiu     $a3, $sp, 0x30
/* 7DC58 800E47A8 E7A00028 */  swc1      $f0, 0x28($sp)
/* 7DC5C 800E47AC C600002C */  lwc1      $f0, 0x2c($s0)
/* 7DC60 800E47B0 C6020030 */  lwc1      $f2, 0x30($s0)
/* 7DC64 800E47B4 46160000 */  add.s     $f0, $f0, $f22
/* 7DC68 800E47B8 27A20034 */  addiu     $v0, $sp, 0x34
/* 7DC6C 800E47BC E7A40034 */  swc1      $f4, 0x34($sp)
/* 7DC70 800E47C0 E7A0002C */  swc1      $f0, 0x2c($sp)
/* 7DC74 800E47C4 3C0140E0 */  lui       $at, 0x40e0
/* 7DC78 800E47C8 44810000 */  mtc1      $at, $f0
/* 7DC7C 800E47CC 46042100 */  add.s     $f4, $f4, $f4
/* 7DC80 800E47D0 E7A20030 */  swc1      $f2, 0x30($sp)
/* 7DC84 800E47D4 AFA20010 */  sw        $v0, 0x10($sp)
/* 7DC88 800E47D8 27A20038 */  addiu     $v0, $sp, 0x38
/* 7DC8C 800E47DC AFA20014 */  sw        $v0, 0x14($sp)
/* 7DC90 800E47E0 27A2003C */  addiu     $v0, $sp, 0x3c
/* 7DC94 800E47E4 AFA20018 */  sw        $v0, 0x18($sp)
/* 7DC98 800E47E8 27A20040 */  addiu     $v0, $sp, 0x40
/* 7DC9C 800E47EC AFA2001C */  sw        $v0, 0x1c($sp)
/* 7DCA0 800E47F0 27A20044 */  addiu     $v0, $sp, 0x44
/* 7DCA4 800E47F4 AFA20020 */  sw        $v0, 0x20($sp)
/* 7DCA8 800E47F8 0C03791B */  jal       func_800DE46C
/* 7DCAC 800E47FC 46002603 */   div.s    $f24, $f4, $f0
/* 7DCB0 800E4800 0C00A794 */  jal       get_player_normal_pitch
/* 7DCB4 800E4804 0040882D */   daddu    $s1, $v0, $zero
/* 7DCB8 800E4808 4614C502 */  mul.s     $f20, $f24, $f20
/* 7DCBC 800E480C 00000000 */  nop       
/* 7DCC0 800E4810 3C138011 */  lui       $s3, 0x8011
/* 7DCC4 800E4814 2673EBB0 */  addiu     $s3, $s3, -0x1450
/* 7DCC8 800E4818 C7A20034 */  lwc1      $f2, 0x34($sp)
/* 7DCCC 800E481C 4614B500 */  add.s     $f20, $f22, $f20
/* 7DCD0 800E4820 3C148016 */  lui       $s4, 0x8016
/* 7DCD4 800E4824 2694A550 */  addiu     $s4, $s4, -0x5ab0
/* 7DCD8 800E4828 4602A03C */  c.lt.s    $f20, $f2
/* 7DCDC 800E482C 00000000 */  nop       
/* 7DCE0 800E4830 45000002 */  bc1f      .L800E483C
/* 7DCE4 800E4834 E6000068 */   swc1     $f0, 0x68($s0)
/* 7DCE8 800E4838 2411FFFF */  addiu     $s1, $zero, -1
.L800E483C:
/* 7DCEC 800E483C 860200C0 */  lh        $v0, 0xc0($s0)
/* 7DCF0 800E4840 50400001 */  beql      $v0, $zero, .L800E4848
/* 7DCF4 800E4844 A6910002 */   sh       $s1, 2($s4)
.L800E4848:
/* 7DCF8 800E4848 06200005 */  bltz      $s1, .L800E4860
/* 7DCFC 800E484C 00000000 */   nop      
/* 7DD00 800E4850 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 7DD04 800E4854 C7A20044 */  lwc1      $f2, 0x44($sp)
/* 7DD08 800E4858 E6000034 */  swc1      $f0, 0x34($s0)
/* 7DD0C 800E485C E6020038 */  swc1      $f2, 0x38($s0)
.L800E4860:
/* 7DD10 800E4860 0C038082 */  jal       func_800E0208
/* 7DD14 800E4864 00000000 */   nop      
/* 7DD18 800E4868 14400090 */  bnez      $v0, .L800E4AAC
/* 7DD1C 800E486C 00000000 */   nop      
/* 7DD20 800E4870 8E030000 */  lw        $v1, ($s0)
/* 7DD24 800E4874 3062000E */  andi      $v0, $v1, 0xe
/* 7DD28 800E4878 1440008C */  bnez      $v0, .L800E4AAC
/* 7DD2C 800E487C 24120011 */   addiu    $s2, $zero, 0x11
/* 7DD30 800E4880 820200B4 */  lb        $v0, 0xb4($s0)
/* 7DD34 800E4884 10520089 */  beq       $v0, $s2, .L800E4AAC
/* 7DD38 800E4888 30620010 */   andi     $v0, $v1, 0x10
/* 7DD3C 800E488C 1040000C */  beqz      $v0, .L800E48C0
/* 7DD40 800E4890 00000000 */   nop      
/* 7DD44 800E4894 0C03954C */  jal       func_800E5530
/* 7DD48 800E4898 00000000 */   nop      
/* 7DD4C 800E489C 0C039178 */  jal       func_800E45E0
/* 7DD50 800E48A0 00000000 */   nop      
/* 7DD54 800E48A4 10400006 */  beqz      $v0, .L800E48C0
/* 7DD58 800E48A8 00000000 */   nop      
/* 7DD5C 800E48AC 0C039769 */  jal       set_action_state
/* 7DD60 800E48B0 0240202D */   daddu    $a0, $s2, $zero
/* 7DD64 800E48B4 820200B4 */  lb        $v0, 0xb4($s0)
/* 7DD68 800E48B8 1052007C */  beq       $v0, $s2, .L800E4AAC
/* 7DD6C 800E48BC 00000000 */   nop      
.L800E48C0:
/* 7DD70 800E48C0 0620005D */  bltz      $s1, .L800E4A38
/* 7DD74 800E48C4 00000000 */   nop      
/* 7DD78 800E48C8 0C016F6A */  jal       get_collider_type_by_id
/* 7DD7C 800E48CC 0220202D */   daddu    $a0, $s1, $zero
/* 7DD80 800E48D0 304400FF */  andi      $a0, $v0, 0xff
/* 7DD84 800E48D4 24020002 */  addiu     $v0, $zero, 2
/* 7DD88 800E48D8 10820005 */  beq       $a0, $v0, .L800E48F0
/* 7DD8C 800E48DC 24020003 */   addiu    $v0, $zero, 3
/* 7DD90 800E48E0 10820011 */  beq       $a0, $v0, .L800E4928
/* 7DD94 800E48E4 0000282D */   daddu    $a1, $zero, $zero
/* 7DD98 800E48E8 0803925F */  j         .L800E497C
/* 7DD9C 800E48EC 00000000 */   nop      
.L800E48F0:
/* 7DDA0 800E48F0 82620000 */  lb        $v0, ($s3)
/* 7DDA4 800E48F4 10400004 */  beqz      $v0, .L800E4908
/* 7DDA8 800E48F8 24020009 */   addiu    $v0, $zero, 9
/* 7DDAC 800E48FC 82630003 */  lb        $v1, 3($s3)
/* 7DDB0 800E4900 1062006A */  beq       $v1, $v0, .L800E4AAC
/* 7DDB4 800E4904 00000000 */   nop      
.L800E4908:
/* 7DDB8 800E4908 86020010 */  lh        $v0, 0x10($s0)
/* 7DDBC 800E490C 14400017 */  bnez      $v0, .L800E496C
/* 7DDC0 800E4910 24020017 */   addiu    $v0, $zero, 0x17
/* 7DDC4 800E4914 820300B4 */  lb        $v1, 0xb4($s0)
/* 7DDC8 800E4918 10620064 */  beq       $v1, $v0, .L800E4AAC
/* 7DDCC 800E491C 00000000 */   nop      
/* 7DDD0 800E4920 08039257 */  j         .L800E495C
/* 7DDD4 800E4924 A20400BF */   sb       $a0, 0xbf($s0)
.L800E4928:
/* 7DDD8 800E4928 82620000 */  lb        $v0, ($s3)
/* 7DDDC 800E492C 10400004 */  beqz      $v0, .L800E4940
/* 7DDE0 800E4930 24020009 */   addiu    $v0, $zero, 9
/* 7DDE4 800E4934 82630003 */  lb        $v1, 3($s3)
/* 7DDE8 800E4938 1062005C */  beq       $v1, $v0, .L800E4AAC
/* 7DDEC 800E493C 00000000 */   nop      
.L800E4940:
/* 7DDF0 800E4940 86020010 */  lh        $v0, 0x10($s0)
/* 7DDF4 800E4944 14400009 */  bnez      $v0, .L800E496C
/* 7DDF8 800E4948 24020017 */   addiu    $v0, $zero, 0x17
/* 7DDFC 800E494C 820300B4 */  lb        $v1, 0xb4($s0)
/* 7DE00 800E4950 10620056 */  beq       $v1, $v0, .L800E4AAC
/* 7DE04 800E4954 24020001 */   addiu    $v0, $zero, 1
/* 7DE08 800E4958 A20200BF */  sb        $v0, 0xbf($s0)
.L800E495C:
/* 7DE0C 800E495C 0C039769 */  jal       set_action_state
/* 7DE10 800E4960 24040017 */   addiu    $a0, $zero, 0x17
/* 7DE14 800E4964 080392AB */  j         .L800E4AAC
/* 7DE18 800E4968 00000000 */   nop      
.L800E496C:
/* 7DE1C 800E496C 0C039769 */  jal       set_action_state
/* 7DE20 800E4970 24040016 */   addiu    $a0, $zero, 0x16
/* 7DE24 800E4974 080392AB */  j         .L800E4AAC
/* 7DE28 800E4978 00000000 */   nop      
.L800E497C:
/* 7DE2C 800E497C 96840002 */  lhu       $a0, 2($s4)
/* 7DE30 800E4980 30824000 */  andi      $v0, $a0, 0x4000
/* 7DE34 800E4984 10400006 */  beqz      $v0, .L800E49A0
/* 7DE38 800E4988 00000000 */   nop      
/* 7DE3C 800E498C 00042400 */  sll       $a0, $a0, 0x10
/* 7DE40 800E4990 0C0441A9 */  jal       get_entity_type
/* 7DE44 800E4994 00042403 */   sra      $a0, $a0, 0x10
/* 7DE48 800E4998 38420030 */  xori      $v0, $v0, 0x30
/* 7DE4C 800E499C 2C450001 */  sltiu     $a1, $v0, 1
.L800E49A0:
/* 7DE50 800E49A0 820300B4 */  lb        $v1, 0xb4($s0)
/* 7DE54 800E49A4 24020022 */  addiu     $v0, $zero, 0x22
/* 7DE58 800E49A8 10620040 */  beq       $v1, $v0, .L800E4AAC
/* 7DE5C 800E49AC 00000000 */   nop      
/* 7DE60 800E49B0 14A0003E */  bnez      $a1, .L800E4AAC
/* 7DE64 800E49B4 00000000 */   nop      
/* 7DE68 800E49B8 8E020004 */  lw        $v0, 4($s0)
/* 7DE6C 800E49BC 30421000 */  andi      $v0, $v0, 0x1000
/* 7DE70 800E49C0 14400017 */  bnez      $v0, .L800E4A20
/* 7DE74 800E49C4 00000000 */   nop      
/* 7DE78 800E49C8 C7A4002C */  lwc1      $f4, 0x2c($sp)
/* 7DE7C 800E49CC C600002C */  lwc1      $f0, 0x2c($s0)
/* 7DE80 800E49D0 46002001 */  sub.s     $f0, $f4, $f0
/* 7DE84 800E49D4 3C0140C0 */  lui       $at, 0x40c0
/* 7DE88 800E49D8 44811000 */  mtc1      $at, $f2
/* 7DE8C 800E49DC 00000000 */  nop       
/* 7DE90 800E49E0 4602003C */  c.lt.s    $f0, $f2
/* 7DE94 800E49E4 00000000 */  nop       
/* 7DE98 800E49E8 45000003 */  bc1f      .L800E49F8
/* 7DE9C 800E49EC 00000000 */   nop      
/* 7DEA0 800E49F0 0803928A */  j         .L800E4A28
/* 7DEA4 800E49F4 E604002C */   swc1     $f4, 0x2c($s0)
.L800E49F8:
/* 7DEA8 800E49F8 0C039769 */  jal       set_action_state
/* 7DEAC 800E49FC 24040022 */   addiu    $a0, $zero, 0x22
/* 7DEB0 800E4A00 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 7DEB4 800E4A04 C6020080 */  lwc1      $f2, 0x80($s0)
/* 7DEB8 800E4A08 3C018011 */  lui       $at, 0x8011
/* 7DEBC 800E4A0C E420C928 */  swc1      $f0, -0x36d8($at)
/* 7DEC0 800E4A10 3C018011 */  lui       $at, 0x8011
/* 7DEC4 800E4A14 E422C984 */  swc1      $f2, -0x367c($at)
/* 7DEC8 800E4A18 0803928A */  j         .L800E4A28
/* 7DECC 800E4A1C 00000000 */   nop      
.L800E4A20:
/* 7DED0 800E4A20 C7A0002C */  lwc1      $f0, 0x2c($sp)
/* 7DED4 800E4A24 E600002C */  swc1      $f0, 0x2c($s0)
.L800E4A28:
/* 7DED8 800E4A28 0C039538 */  jal       save_ground_pos
/* 7DEDC 800E4A2C 00000000 */   nop      
/* 7DEE0 800E4A30 080392AB */  j         .L800E4AAC
/* 7DEE4 800E4A34 00000000 */   nop      
.L800E4A38:
/* 7DEE8 800E4A38 8E020000 */  lw        $v0, ($s0)
/* 7DEEC 800E4A3C 30420008 */  andi      $v0, $v0, 8
/* 7DEF0 800E4A40 1440001A */  bnez      $v0, .L800E4AAC
/* 7DEF4 800E4A44 2402001D */   addiu    $v0, $zero, 0x1d
/* 7DEF8 800E4A48 820300B4 */  lb        $v1, 0xb4($s0)
/* 7DEFC 800E4A4C 10620017 */  beq       $v1, $v0, .L800E4AAC
/* 7DF00 800E4A50 00000000 */   nop      
/* 7DF04 800E4A54 4618B080 */  add.s     $f2, $f22, $f24
/* 7DF08 800E4A58 C7A00034 */  lwc1      $f0, 0x34($sp)
/* 7DF0C 800E4A5C 4602003E */  c.le.s    $f0, $f2
/* 7DF10 800E4A60 00000000 */  nop       
/* 7DF14 800E4A64 4500000D */  bc1f      .L800E4A9C
/* 7DF18 800E4A68 24040008 */   addiu    $a0, $zero, 8
/* 7DF1C 800E4A6C C7A00040 */  lwc1      $f0, 0x40($sp)
/* 7DF20 800E4A70 44801000 */  mtc1      $zero, $f2
/* 7DF24 800E4A74 00000000 */  nop       
/* 7DF28 800E4A78 46020032 */  c.eq.s    $f0, $f2
/* 7DF2C 800E4A7C 00000000 */  nop       
/* 7DF30 800E4A80 45000006 */  bc1f      .L800E4A9C
/* 7DF34 800E4A84 00000000 */   nop      
/* 7DF38 800E4A88 C7A00044 */  lwc1      $f0, 0x44($sp)
/* 7DF3C 800E4A8C 46020032 */  c.eq.s    $f0, $f2
/* 7DF40 800E4A90 00000000 */  nop       
/* 7DF44 800E4A94 45030001 */  bc1tl     .L800E4A9C
/* 7DF48 800E4A98 24040009 */   addiu    $a0, $zero, 9
.L800E4A9C:
/* 7DF4C 800E4A9C 0C039769 */  jal       set_action_state
/* 7DF50 800E4AA0 00000000 */   nop      
/* 7DF54 800E4AA4 0C038C1B */  jal       gravity_use_fall_parms
/* 7DF58 800E4AA8 00000000 */   nop      
.L800E4AAC:
/* 7DF5C 800E4AAC 8FBF005C */  lw        $ra, 0x5c($sp)
/* 7DF60 800E4AB0 8FB40058 */  lw        $s4, 0x58($sp)
/* 7DF64 800E4AB4 8FB30054 */  lw        $s3, 0x54($sp)
/* 7DF68 800E4AB8 8FB20050 */  lw        $s2, 0x50($sp)
/* 7DF6C 800E4ABC 8FB1004C */  lw        $s1, 0x4c($sp)
/* 7DF70 800E4AC0 8FB00048 */  lw        $s0, 0x48($sp)
/* 7DF74 800E4AC4 D7B80070 */  ldc1      $f24, 0x70($sp)
/* 7DF78 800E4AC8 D7B60068 */  ldc1      $f22, 0x68($sp)
/* 7DF7C 800E4ACC D7B40060 */  ldc1      $f20, 0x60($sp)
/* 7DF80 800E4AD0 03E00008 */  jr        $ra
/* 7DF84 800E4AD4 27BD0078 */   addiu    $sp, $sp, 0x78
