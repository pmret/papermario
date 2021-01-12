.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218B80_63DD60
/* 63DD60 80218B80 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 63DD64 80218B84 AFB60038 */  sw        $s6, 0x38($sp)
/* 63DD68 80218B88 0080B02D */  daddu     $s6, $a0, $zero
/* 63DD6C 80218B8C 27A50010 */  addiu     $a1, $sp, 0x10
/* 63DD70 80218B90 27A60014 */  addiu     $a2, $sp, 0x14
/* 63DD74 80218B94 27A70018 */  addiu     $a3, $sp, 0x18
/* 63DD78 80218B98 AFBF003C */  sw        $ra, 0x3c($sp)
/* 63DD7C 80218B9C AFB50034 */  sw        $s5, 0x34($sp)
/* 63DD80 80218BA0 AFB40030 */  sw        $s4, 0x30($sp)
/* 63DD84 80218BA4 AFB3002C */  sw        $s3, 0x2c($sp)
/* 63DD88 80218BA8 AFB20028 */  sw        $s2, 0x28($sp)
/* 63DD8C 80218BAC AFB10024 */  sw        $s1, 0x24($sp)
/* 63DD90 80218BB0 0C0470AC */  jal       func_8011C2B0
/* 63DD94 80218BB4 AFB00020 */   sw       $s0, 0x20($sp)
/* 63DD98 80218BB8 8FA20018 */  lw        $v0, 0x18($sp)
/* 63DD9C 80218BBC 18400052 */  blez      $v0, .L80218D08
/* 63DDA0 80218BC0 0000802D */   daddu    $s0, $zero, $zero
/* 63DDA4 80218BC4 3C038022 */  lui       $v1, %hi(D_80221DF0)
/* 63DDA8 80218BC8 24631DF0 */  addiu     $v1, $v1, %lo(D_80221DF0)
/* 63DDAC 80218BCC 00161040 */  sll       $v0, $s6, 1
/* 63DDB0 80218BD0 0043A021 */  addu      $s4, $v0, $v1
/* 63DDB4 80218BD4 3C135555 */  lui       $s3, 0x5555
/* 63DDB8 80218BD8 36735556 */  ori       $s3, $s3, 0x5556
/* 63DDBC 80218BDC 34158000 */  ori       $s5, $zero, 0x8000
/* 63DDC0 80218BE0 02130018 */  mult      $s0, $s3
.L80218BE4:
/* 63DDC4 80218BE4 001097C3 */  sra       $s2, $s0, 0x1f
/* 63DDC8 80218BE8 00001810 */  mfhi      $v1
/* 63DDCC 80218BEC 00721823 */  subu      $v1, $v1, $s2
/* 63DDD0 80218BF0 00031040 */  sll       $v0, $v1, 1
/* 63DDD4 80218BF4 00431021 */  addu      $v0, $v0, $v1
/* 63DDD8 80218BF8 02021023 */  subu      $v0, $s0, $v0
/* 63DDDC 80218BFC 96830000 */  lhu       $v1, ($s4)
/* 63DDE0 80218C00 24420001 */  addiu     $v0, $v0, 1
/* 63DDE4 80218C04 00620018 */  mult      $v1, $v0
/* 63DDE8 80218C08 00101100 */  sll       $v0, $s0, 4
/* 63DDEC 80218C0C 00001812 */  mflo      $v1
/* 63DDF0 80218C10 00702021 */  addu      $a0, $v1, $s0
/* 63DDF4 80218C14 8FA30014 */  lw        $v1, 0x14($sp)
/* 63DDF8 80218C18 3084FFFF */  andi      $a0, $a0, 0xffff
/* 63DDFC 80218C1C 0C01917C */  jal       sins
/* 63DE00 80218C20 00628821 */   addu     $s1, $v1, $v0
/* 63DE04 80218C24 00021400 */  sll       $v0, $v0, 0x10
/* 63DE08 80218C28 00021403 */  sra       $v0, $v0, 0x10
/* 63DE0C 80218C2C 00551021 */  addu      $v0, $v0, $s5
/* 63DE10 80218C30 00021FC2 */  srl       $v1, $v0, 0x1f
/* 63DE14 80218C34 00431021 */  addu      $v0, $v0, $v1
/* 63DE18 80218C38 000213C0 */  sll       $v0, $v0, 0xf
/* 63DE1C 80218C3C 00021403 */  sra       $v0, $v0, 0x10
/* 63DE20 80218C40 00021880 */  sll       $v1, $v0, 2
/* 63DE24 80218C44 00621821 */  addu      $v1, $v1, $v0
/* 63DE28 80218C48 00031140 */  sll       $v0, $v1, 5
/* 63DE2C 80218C4C 00431823 */  subu      $v1, $v0, $v1
/* 63DE30 80218C50 04610002 */  bgez      $v1, .L80218C5C
/* 63DE34 80218C54 0060102D */   daddu    $v0, $v1, $zero
/* 63DE38 80218C58 24627FFF */  addiu     $v0, $v1, 0x7fff
.L80218C5C:
/* 63DE3C 80218C5C 000223C3 */  sra       $a0, $v0, 0xf
/* 63DE40 80218C60 24820064 */  addiu     $v0, $a0, 0x64
/* 63DE44 80218C64 A222000E */  sb        $v0, 0xe($s1)
/* 63DE48 80218C68 24820032 */  addiu     $v0, $a0, 0x32
/* 63DE4C 80218C6C 02121823 */  subu      $v1, $s0, $s2
/* 63DE50 80218C70 00032843 */  sra       $a1, $v1, 1
/* 63DE54 80218C74 00B30018 */  mult      $a1, $s3
/* 63DE58 80218C78 A222000D */  sb        $v0, 0xd($s1)
/* 63DE5C 80218C7C 96840000 */  lhu       $a0, ($s4)
/* 63DE60 80218C80 00031FC3 */  sra       $v1, $v1, 0x1f
/* 63DE64 80218C84 000433C2 */  srl       $a2, $a0, 0xf
/* 63DE68 80218C88 00004810 */  mfhi      $t1
/* 63DE6C 80218C8C 01231823 */  subu      $v1, $t1, $v1
/* 63DE70 80218C90 00031040 */  sll       $v0, $v1, 1
/* 63DE74 80218C94 00431021 */  addu      $v0, $v0, $v1
/* 63DE78 80218C98 00A22823 */  subu      $a1, $a1, $v0
/* 63DE7C 80218C9C 24A50001 */  addiu     $a1, $a1, 1
/* 63DE80 80218CA0 00052BC0 */  sll       $a1, $a1, 0xf
/* 63DE84 80218CA4 00C50018 */  mult      $a2, $a1
/* 63DE88 80218CA8 00042382 */  srl       $a0, $a0, 0xe
/* 63DE8C 80218CAC 000423C0 */  sll       $a0, $a0, 0xf
/* 63DE90 80218CB0 00001812 */  mflo      $v1
/* 63DE94 80218CB4 00642021 */  addu      $a0, $v1, $a0
/* 63DE98 80218CB8 00902021 */  addu      $a0, $a0, $s0
/* 63DE9C 80218CBC 0C01917C */  jal       sins
/* 63DEA0 80218CC0 3084FFFF */   andi     $a0, $a0, 0xffff
/* 63DEA4 80218CC4 00021400 */  sll       $v0, $v0, 0x10
/* 63DEA8 80218CC8 00021403 */  sra       $v0, $v0, 0x10
/* 63DEAC 80218CCC 9223000C */  lbu       $v1, 0xc($s1)
/* 63DEB0 80218CD0 00551021 */  addu      $v0, $v0, $s5
/* 63DEB4 80218CD4 00620018 */  mult      $v1, $v0
/* 63DEB8 80218CD8 00001812 */  mflo      $v1
/* 63DEBC 80218CDC 04610004 */  bgez      $v1, .L80218CF0
/* 63DEC0 80218CE0 00031403 */   sra      $v0, $v1, 0x10
/* 63DEC4 80218CE4 3402FFFF */  ori       $v0, $zero, 0xffff
/* 63DEC8 80218CE8 00621821 */  addu      $v1, $v1, $v0
/* 63DECC 80218CEC 00031403 */  sra       $v0, $v1, 0x10
.L80218CF0:
/* 63DED0 80218CF0 A222000C */  sb        $v0, 0xc($s1)
/* 63DED4 80218CF4 8FA20018 */  lw        $v0, 0x18($sp)
/* 63DED8 80218CF8 26100001 */  addiu     $s0, $s0, 1
/* 63DEDC 80218CFC 0202102A */  slt       $v0, $s0, $v0
/* 63DEE0 80218D00 1440FFB8 */  bnez      $v0, .L80218BE4
/* 63DEE4 80218D04 02130018 */   mult     $s0, $s3
.L80218D08:
/* 63DEE8 80218D08 3C03800A */  lui       $v1, %hi(gMasterGfxPos)
/* 63DEEC 80218D0C 2463A66C */  addiu     $v1, $v1, %lo(gMasterGfxPos)
/* 63DEF0 80218D10 8C620000 */  lw        $v0, ($v1)
/* 63DEF4 80218D14 02C0202D */  daddu     $a0, $s6, $zero
/* 63DEF8 80218D18 0040802D */  daddu     $s0, $v0, $zero
/* 63DEFC 80218D1C 24420008 */  addiu     $v0, $v0, 8
/* 63DF00 80218D20 AC620000 */  sw        $v0, ($v1)
/* 63DF04 80218D24 3C02DE00 */  lui       $v0, 0xde00
/* 63DF08 80218D28 0C0470BB */  jal       func_8011C2EC
/* 63DF0C 80218D2C AE020000 */   sw       $v0, ($s0)
/* 63DF10 80218D30 AE020004 */  sw        $v0, 4($s0)
/* 63DF14 80218D34 3C028022 */  lui       $v0, %hi(D_80221DF0)
/* 63DF18 80218D38 24421DF0 */  addiu     $v0, $v0, %lo(D_80221DF0)
/* 63DF1C 80218D3C 00161840 */  sll       $v1, $s6, 1
/* 63DF20 80218D40 00621821 */  addu      $v1, $v1, $v0
/* 63DF24 80218D44 94620000 */  lhu       $v0, ($v1)
/* 63DF28 80218D48 24420253 */  addiu     $v0, $v0, 0x253
/* 63DF2C 80218D4C A4620000 */  sh        $v0, ($v1)
/* 63DF30 80218D50 8FBF003C */  lw        $ra, 0x3c($sp)
/* 63DF34 80218D54 8FB60038 */  lw        $s6, 0x38($sp)
/* 63DF38 80218D58 8FB50034 */  lw        $s5, 0x34($sp)
/* 63DF3C 80218D5C 8FB40030 */  lw        $s4, 0x30($sp)
/* 63DF40 80218D60 8FB3002C */  lw        $s3, 0x2c($sp)
/* 63DF44 80218D64 8FB20028 */  lw        $s2, 0x28($sp)
/* 63DF48 80218D68 8FB10024 */  lw        $s1, 0x24($sp)
/* 63DF4C 80218D6C 8FB00020 */  lw        $s0, 0x20($sp)
/* 63DF50 80218D70 03E00008 */  jr        $ra
/* 63DF54 80218D74 27BD0040 */   addiu    $sp, $sp, 0x40
