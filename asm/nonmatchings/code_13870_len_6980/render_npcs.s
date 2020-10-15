.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel render_npcs
/* 15BF0 8003A7F0 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 15BF4 8003A7F4 F7BA0080 */  sdc1      $f26, 0x80($sp)
/* 15BF8 8003A7F8 3C01459C */  lui       $at, 0x459c
/* 15BFC 8003A7FC 34214000 */  ori       $at, $at, 0x4000
/* 15C00 8003A800 4481D000 */  mtc1      $at, $f26
/* 15C04 8003A804 F7B80078 */  sdc1      $f24, 0x78($sp)
/* 15C08 8003A808 4480C000 */  mtc1      $zero, $f24
/* 15C0C 8003A80C AFB10054 */  sw        $s1, 0x54($sp)
/* 15C10 8003A810 27B10028 */  addiu     $s1, $sp, 0x28
/* 15C14 8003A814 AFB20058 */  sw        $s2, 0x58($sp)
/* 15C18 8003A818 0000902D */  daddu     $s2, $zero, $zero
/* 15C1C 8003A81C AFB3005C */  sw        $s3, 0x5c($sp)
/* 15C20 8003A820 241300FF */  addiu     $s3, $zero, 0xff
/* 15C24 8003A824 F7B60070 */  sdc1      $f22, 0x70($sp)
/* 15C28 8003A828 3C01461C */  lui       $at, 0x461c
/* 15C2C 8003A82C 34214000 */  ori       $at, $at, 0x4000
/* 15C30 8003A830 4481B000 */  mtc1      $at, $f22
/* 15C34 8003A834 3C03800A */  lui       $v1, 0x800a
/* 15C38 8003A838 8463A634 */  lh        $v1, -0x59cc($v1)
/* 15C3C 8003A83C 3C04800B */  lui       $a0, %hi(gCameras)
/* 15C40 8003A840 24841D80 */  addiu     $a0, $a0, %lo(gCameras)
/* 15C44 8003A844 AFBF0064 */  sw        $ra, 0x64($sp)
/* 15C48 8003A848 AFB40060 */  sw        $s4, 0x60($sp)
/* 15C4C 8003A84C AFB00050 */  sw        $s0, 0x50($sp)
/* 15C50 8003A850 F7B40068 */  sdc1      $f20, 0x68($sp)
/* 15C54 8003A854 00031080 */  sll       $v0, $v1, 2
/* 15C58 8003A858 00431021 */  addu      $v0, $v0, $v1
/* 15C5C 8003A85C 00021080 */  sll       $v0, $v0, 2
/* 15C60 8003A860 00431023 */  subu      $v0, $v0, $v1
/* 15C64 8003A864 000218C0 */  sll       $v1, $v0, 3
/* 15C68 8003A868 00431021 */  addu      $v0, $v0, $v1
/* 15C6C 8003A86C 000210C0 */  sll       $v0, $v0, 3
/* 15C70 8003A870 0044A021 */  addu      $s4, $v0, $a0
.L8003A874:
/* 15C74 8003A874 3C03800A */  lui       $v1, %hi(gCurrentNpcListPtr)
/* 15C78 8003A878 8C630B90 */  lw        $v1, %lo(gCurrentNpcListPtr)($v1)
/* 15C7C 8003A87C 00121080 */  sll       $v0, $s2, 2
/* 15C80 8003A880 00431021 */  addu      $v0, $v0, $v1
/* 15C84 8003A884 8C500000 */  lw        $s0, ($v0)
/* 15C88 8003A888 52000063 */  beql      $s0, $zero, .L8003AA18
/* 15C8C 8003A88C 26520001 */   addiu    $s2, $s2, 1
/* 15C90 8003A890 8E030000 */  lw        $v1, ($s0)
/* 15C94 8003A894 50600060 */  beql      $v1, $zero, .L8003AA18
/* 15C98 8003A898 26520001 */   addiu    $s2, $s2, 1
/* 15C9C 8003A89C 3C028100 */  lui       $v0, 0x8100
/* 15CA0 8003A8A0 34420006 */  ori       $v0, $v0, 6
/* 15CA4 8003A8A4 00621024 */  and       $v0, $v1, $v0
/* 15CA8 8003A8A8 5440005B */  bnel      $v0, $zero, .L8003AA18
/* 15CAC 8003A8AC 26520001 */   addiu    $s2, $s2, 1
/* 15CB0 8003A8B0 3C013F80 */  lui       $at, 0x3f80
/* 15CB4 8003A8B4 44810000 */  mtc1      $at, $f0
/* 15CB8 8003A8B8 27A20038 */  addiu     $v0, $sp, 0x38
/* 15CBC 8003A8BC AFA20014 */  sw        $v0, 0x14($sp)
/* 15CC0 8003A8C0 27A2003C */  addiu     $v0, $sp, 0x3c
/* 15CC4 8003A8C4 AFA20018 */  sw        $v0, 0x18($sp)
/* 15CC8 8003A8C8 27A20040 */  addiu     $v0, $sp, 0x40
/* 15CCC 8003A8CC AFA2001C */  sw        $v0, 0x1c($sp)
/* 15CD0 8003A8D0 27A20044 */  addiu     $v0, $sp, 0x44
/* 15CD4 8003A8D4 AFA20020 */  sw        $v0, 0x20($sp)
/* 15CD8 8003A8D8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 15CDC 8003A8DC 8E050038 */  lw        $a1, 0x38($s0)
/* 15CE0 8003A8E0 8E06003C */  lw        $a2, 0x3c($s0)
/* 15CE4 8003A8E4 8E070040 */  lw        $a3, 0x40($s0)
/* 15CE8 8003A8E8 0C00A588 */  jal       transform_point
/* 15CEC 8003A8EC 268400D4 */   addiu    $a0, $s4, 0xd4
/* 15CF0 8003A8F0 C7A40044 */  lwc1      $f4, 0x44($sp)
/* 15CF4 8003A8F4 3C01800A */  lui       $at, 0x800a
/* 15CF8 8003A8F8 D42084B0 */  ldc1      $f0, -0x7b50($at)
/* 15CFC 8003A8FC 460020A1 */  cvt.d.s   $f2, $f4
/* 15D00 8003A900 4620103C */  c.lt.d    $f2, $f0
/* 15D04 8003A904 00000000 */  nop       
/* 15D08 8003A908 45000007 */  bc1f      .L8003A928
/* 15D0C 8003A90C 00000000 */   nop      
/* 15D10 8003A910 3C01800A */  lui       $at, 0x800a
/* 15D14 8003A914 D42084B8 */  ldc1      $f0, -0x7b48($at)
/* 15D18 8003A918 4622003C */  c.lt.d    $f0, $f2
/* 15D1C 8003A91C 00000000 */  nop       
/* 15D20 8003A920 4503003D */  bc1tl     .L8003AA18
/* 15D24 8003A924 26520001 */   addiu    $s2, $s2, 1
.L8003A928:
/* 15D28 8003A928 C7A00040 */  lwc1      $f0, 0x40($sp)
/* 15D2C 8003A92C 461A0002 */  mul.s     $f0, $f0, $f26
/* 15D30 8003A930 00000000 */  nop       
/* 15D34 8003A934 46040003 */  div.s     $f0, $f0, $f4
/* 15D38 8003A938 461A0500 */  add.s     $f20, $f0, $f26
/* 15D3C 8003A93C 4618A03C */  c.lt.s    $f20, $f24
/* 15D40 8003A940 00000000 */  nop       
/* 15D44 8003A944 45000003 */  bc1f      .L8003A954
/* 15D48 8003A948 00000000 */   nop      
/* 15D4C 8003A94C 0800EA59 */  j         .L8003A964
/* 15D50 8003A950 4600C506 */   mov.s    $f20, $f24
.L8003A954:
/* 15D54 8003A954 4614B03C */  c.lt.s    $f22, $f20
/* 15D58 8003A958 00000000 */  nop       
/* 15D5C 8003A95C 45030001 */  bc1tl     .L8003A964
/* 15D60 8003A960 4600B506 */   mov.s    $f20, $f22
.L8003A964:
/* 15D64 8003A964 4600A007 */  neg.s     $f0, $f20
/* 15D68 8003A968 4600018D */  trunc.w.s $f6, $f0
/* 15D6C 8003A96C E6260004 */  swc1      $f6, 4($s1)
/* 15D70 8003A970 3C028004 */  lui       $v0, %hi(appendGfx_npc)
/* 15D74 8003A974 24429FD0 */  addiu     $v0, $v0, %lo(appendGfx_npc)
/* 15D78 8003A978 AE300008 */  sw        $s0, 8($s1)
/* 15D7C 8003A97C AE22000C */  sw        $v0, 0xc($s1)
/* 15D80 8003A980 820200AA */  lb        $v0, 0xaa($s0)
/* 15D84 8003A984 AE220000 */  sw        $v0, ($s1)
/* 15D88 8003A988 8E020000 */  lw        $v0, ($s0)
/* 15D8C 8003A98C 3C030080 */  lui       $v1, 0x80
/* 15D90 8003A990 00431024 */  and       $v0, $v0, $v1
/* 15D94 8003A994 10400009 */  beqz      $v0, .L8003A9BC
/* 15D98 8003A998 27A40048 */   addiu    $a0, $sp, 0x48
/* 15D9C 8003A99C 27A50049 */  addiu     $a1, $sp, 0x49
/* 15DA0 8003A9A0 27A6004A */  addiu     $a2, $sp, 0x4a
/* 15DA4 8003A9A4 0C046FA0 */  jal       get_background_color_blend
/* 15DA8 8003A9A8 27A7004B */   addiu    $a3, $sp, 0x4b
/* 15DAC 8003A9AC 93A2004B */  lbu       $v0, 0x4b($sp)
/* 15DB0 8003A9B0 02621023 */  subu      $v0, $s3, $v0
/* 15DB4 8003A9B4 0800EA70 */  j         .L8003A9C0
/* 15DB8 8003A9B8 A20200AD */   sb       $v0, 0xad($s0)
.L8003A9BC:
/* 15DBC 8003A9BC A21300AD */  sb        $s3, 0xad($s0)
.L8003A9C0:
/* 15DC0 8003A9C0 920200AD */  lbu       $v0, 0xad($s0)
/* 15DC4 8003A9C4 10400003 */  beqz      $v0, .L8003A9D4
/* 15DC8 8003A9C8 00000000 */   nop      
/* 15DCC 8003A9CC 0C047644 */  jal       queue_render_task
/* 15DD0 8003A9D0 0220202D */   daddu    $a0, $s1, $zero
.L8003A9D4:
/* 15DD4 8003A9D4 8E020000 */  lw        $v0, ($s0)
/* 15DD8 8003A9D8 3C030010 */  lui       $v1, 0x10
/* 15DDC 8003A9DC 00431024 */  and       $v0, $v0, $v1
/* 15DE0 8003A9E0 5040000D */  beql      $v0, $zero, .L8003AA18
/* 15DE4 8003A9E4 26520001 */   addiu    $s2, $s2, 1
/* 15DE8 8003A9E8 4600A007 */  neg.s     $f0, $f20
/* 15DEC 8003A9EC 4600018D */  trunc.w.s $f6, $f0
/* 15DF0 8003A9F0 E6260004 */  swc1      $f6, 4($s1)
/* 15DF4 8003A9F4 0220202D */  daddu     $a0, $s1, $zero
/* 15DF8 8003A9F8 3C028004 */  lui       $v0, %hi(appedGfx_npc_blur)
/* 15DFC 8003A9FC 2442AE38 */  addiu     $v0, $v0, %lo(appedGfx_npc_blur)
/* 15E00 8003AA00 AE22000C */  sw        $v0, 0xc($s1)
/* 15E04 8003AA04 24020011 */  addiu     $v0, $zero, 0x11
/* 15E08 8003AA08 AE300008 */  sw        $s0, 8($s1)
/* 15E0C 8003AA0C 0C047644 */  jal       queue_render_task
/* 15E10 8003AA10 AE220000 */   sw       $v0, ($s1)
/* 15E14 8003AA14 26520001 */  addiu     $s2, $s2, 1
.L8003AA18:
/* 15E18 8003AA18 2A420040 */  slti      $v0, $s2, 0x40
/* 15E1C 8003AA1C 1440FF95 */  bnez      $v0, .L8003A874
/* 15E20 8003AA20 00000000 */   nop      
/* 15E24 8003AA24 8FBF0064 */  lw        $ra, 0x64($sp)
/* 15E28 8003AA28 8FB40060 */  lw        $s4, 0x60($sp)
/* 15E2C 8003AA2C 8FB3005C */  lw        $s3, 0x5c($sp)
/* 15E30 8003AA30 8FB20058 */  lw        $s2, 0x58($sp)
/* 15E34 8003AA34 8FB10054 */  lw        $s1, 0x54($sp)
/* 15E38 8003AA38 8FB00050 */  lw        $s0, 0x50($sp)
/* 15E3C 8003AA3C D7BA0080 */  ldc1      $f26, 0x80($sp)
/* 15E40 8003AA40 D7B80078 */  ldc1      $f24, 0x78($sp)
/* 15E44 8003AA44 D7B60070 */  ldc1      $f22, 0x70($sp)
/* 15E48 8003AA48 D7B40068 */  ldc1      $f20, 0x68($sp)
/* 15E4C 8003AA4C 03E00008 */  jr        $ra
/* 15E50 8003AA50 27BD0088 */   addiu    $sp, $sp, 0x88
